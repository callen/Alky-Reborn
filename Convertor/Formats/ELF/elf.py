# Copyright 2006 Falling Leaf Systems, LLC.
# Refer to LICENSE in the root directory.
				
import struct
from fileformat import *

PT_NULL = 0		
PT_LOAD = 1
PT_DYNAMIC = 2	
PT_INTERP = 3	
PT_NOTE = 4		
PT_SHLIB = 5	
PT_PHDR = 6		
PT_LOOS = 0x60000000
PT_HIOS = 0x6fffffff
PT_LOPROC = 0x70000000
PT_HIPROC = 0x7fffffff
PT_GNU_EH_FRAME = 0x6474e550 
				
ET_NONE = 0		
ET_REL = 1
ET_EXEC = 2		
ET_DYN = 3		
ET_CORE = 4
ET_LOPROC = 0xff00
ET_HIPROC = 0xffff
						
EM_NONE = 0
EM_M32 = 1		
EM_SPARC = 2			
EM_386 = 3				
EM_68K = 4		
EM_88K = 5
EM_486 = 6
EM_860 = 7		
				
class ELF(FileFormat):
		capabilities = (FILEFORMAT_WRITE, FILEFORMAT_READ)
				
		def read(self, fp):
				"""
				Read file from given file pointer
						
				@param	fp:				File pointer toinput file
				@type	fp:				C{file}

				@return:		   This L{FileFormat} object after reading from the file
				@rtype:			   L{FileFormat}
				"""
				
				assert(fp.read(4) == '\x7FELF')
				
				e_ident = fp.read(12)
				
				filetype, machine, version,\
				entry, phoff,shoff,\
				flags, ehsize, phentsize,\
				phnum, shentsize, shnum,\
				shstrndx                     = struct.unpack('<HHLLLLLHHHHHH', fp.read(36))
				
				self.entry_point = entry
				
				fp.seek(shoff+(shentsize*shstrndx)+16)
				strndxaddr = struct.unpack('<L', fp.read(4))[0]
				fp.seek(shoff+(shentsize*shstrndx)+20)
				strndxlen  = struct.unpack('<L', fp.read(4))[0]
								
				fp.seek(strndxaddr)
				self.strtab = fp.read(strndxlen)
				
				fp.seek(phoff)
				for i in range(phnum):
						self.readPhdr(fp)

				for i in range(shnum - 1):
						fp.seek(shoff+(shentsize*i))
						self.readShdr(fp)
				# assert(True != True)

		def write(self, fp):
				"""
				Write file to given file pointer

				@param	fp:				File pointer to output file
				@type	fp:				C{file}
				"""

				if self.is_shared:
						filetype = ET_DYN
				else:
						filetype = ET_REL # ET_EXEC

				machine = EM_386
				version = 1
				entry = self.entry_point
				flags = 0
				ehsize = 52 # sizeof(Elf32'Ehdr)
				phentsize = 32 # sizeof(Elf32.Phdr)
				phnum = len(self.sections)
				shentsize = 40 # sizeof(Elf32.Shdr)
				shnum = len(self.sections) + 2 + 1 # For symtab
				phoff = ehsize
				shoff = phoff + (phentsize * phnum)
				shstrndx = shnum - 1

				fp.write('\x7FELF')
				fp.write('\x01\x01\x01' + ('\x00' * 9)) # Rest of e'ident
				fp.write(
						struct.pack('<HHLLLLLHHHHHH',
								filetype, machine, version,
								entry, phoff, shoff,
								flags, ehsize, phentsize,
								phnum, shentsize, shnum,
								shstrndx
						)
				)

				shstr = '\0'
				fileoff = shoff + (shentsize * shnum)

				for sec in self.sections:
						fp.write(self.writePhdr(sec, fileoff=fileoff))
						fileoff += len(sec.data)

				fileoff = shoff + (shentsize * shnum)

				fp.write(
						struct.pack('<LLLLLLLLLL',
								0, 0, 0, 0, 0,
								0, 0, 0, 0, 0
						)
				)

				used_segments = []

				for sec in self.sections:
						fp.write(self.writeShdr(sec, fileoff=fileoff, nameoff=len(shstr)))
						fileoff += len(sec.data)

						name = sec.name.lower()
						name = name.replace('.', '')
						name = name.replace('alky', '')
						name = '.alky' + name
						while name in used_segments:
								name += '_'
						used_segments.append(name)
						sec.name = name

						shstr += '%s\0' % name

				temp = len(shstr)
				shstr += '.symtab\0'

				symtab = self.writeSymTab(nameoff=len(shstr))
				for sym in self.symbols:
						shstr += sym + '\0'

				link = shstrndx
				info = len(self.symbols) + 1

				fp.write(
						struct.pack('<LLLLLLLLLL',
								temp, 2, 0x7,
								0, fileoff, len(symtab),
								link, info, 0, 16
						)
				)

				fileoff += len(symtab)

				fp.write(
						struct.pack('<LLLLLLLLLL',
								0, 3, 0x7,
								0, fileoff, len(shstr),
								0, 0, 0, 0
						)
				)

				for sec in self.sections:
						fp.write(sec.data)

				fp.write(symtab)

				fp.write(shstr)

		def writePhdr(self, sec, fileoff):
				type = PT_LOAD
				return struct.pack('<LLLLLLLL',
						type, fileoff, sec.addr,
						0, len(sec.data), sec.size,
						0x7, 2
				)

		def readPhdr(self, fp):
				type, fileoff, addr,\
				unk, data_len, data_size,\
				prot, unk2				  = struct.unpack('<LLLLLLLL', fp.read(32))

				return True

		def writeShdr(self, sec, fileoff=0, nameoff=0):
				return struct.pack('<LLLLLLLLLL',
						nameoff, 1, 0x7,
						sec.addr, fileoff, len(sec.data),
						0, 0, 2, 0
				)

		def readShdr(self, fp):
				nameoff, unk, prot,\
				addr, fileoff, data_len,\
				unk2, unk3, unk4, unk5	 = struct.unpack('<LLLLLLLLLL', fp.read(40))

				if nameoff != 0:
						name = self.strtab[nameoff:].split('\0', 1)[0]
				else:
						name = None
				if not name:
						return False

				fp.seek(fileoff)

				data = fp.read(data_len)

				sec = Section(name, addr, data, data_len, prot)

				self.addSection(sec)

				return True

		def writeSymTab(self, nameoff):
				symtab = []

				symtab.append((0, 0, 0, 0, 0))

				for sym in self.symbols:
						ordinal, addr = self.symbols[sym]
						typ = (1 << 4) | 2

						i = -1
						for sec in self.sections:
								if addr >= sec.addr and addr < sec.addr + sec.size:
										section = i
										break
								i += 1

						if i == -1:
								i = 0xfffe

						symtab.append((nameoff, addr, 0, typ, section))
						nameoff += len(sym) + 1

				data = ''

				for sym in symtab:
						data += struct.pack('<LLLHH', *sym)

				return data