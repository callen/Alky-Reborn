# Copyright 2006 Falling Leaf Systems, LLC.
# Refer to LICENSE in the root directory.

import struct
from fileformat import *

CPU_TYPE_X86 = 7
CPU_SUBTYPE_LITTLE_ENDIAN = 0

MH_EXECUTE = 2
MH_DYLIB   = 6

class MachO(FileFormat):
	capabilities = (FILEFORMAT_WRITE, )
	
	def write(self, fp):
		"""
		Write file to given file pointer
   
		@param	fp:		File pointer to output file
		@type	fp:		C{file}
		"""
	
		cputype = CPU_TYPE_X86
		cpusubtype = CPU_SUBTYPE_LITTLE_ENDIAN
		
		filetype = MH_EXECUTE
		
		flags = 0x20000
		
		self.used_segments = []

		ncmds = len(self.sections)
		if len(self.symbols):
			ncmds += 1
		cmds = self.commands()
		sizeofcmds = len(cmds)
		reserved = 0

		fp.write(struct.pack('<LLL', 0xfeedfaceL, cputype, cpusubtype))
		fp.write(struct.pack('<LLLL', filetype, ncmds, sizeofcmds, flags))
		fp.write(cmds)
		
		fileoff = 7*4 # Size of the Mach-O header we use
		
		for sec in self.sections:
			fileoff += 56 + 68
		if len(self.symbols):
			fileoff += 24
		
		for section in self.sections:
			fp.write(section.data)
		
		if len(self.symbols):
			strtab = '\0'
			
			for sym in self.symbols:
				temp = self.symbols[sym]
				
				sect = 0
				for section in self.sections:
					if temp[1] >= section.addr and temp[1] < section.addr + section.size:
						break
					
					sect += 1
				
				fp.write(struct.pack(
					'<LBBHL', len(strtab),
					0x01|0xe, # N_PEXT|N_SECT
					sect,
					0x10, # REFERENCED_DYNAMICALLY
					temp[1]
				))
				strtab += '_' + sym + '\0'
			fp.write(strtab)
		
	def commands(self):
		data = ''
		fileoff = 7*4 # Size of the Mach-O header we use
		
		for sec in self.sections:
			fileoff += 56 + 68
		
		if len(self.symbols):
			fileoff += 24 # 80 + 
		
		for sec in self.sections:
			data += self.writeSegment(sec, fileoff)
			fileoff += len(sec.data)
		
		if len(self.symbols):
			temp, offset = self.writeSymtab(fileoff)
			data += temp
			fileoff += offset
			# data += self.writeDySymtab(fileoff)
		
		return data
	
	def writeSymtab(self, fileoff):
		cmd, cmdsize = 0x2, 24
		
		symoff = fileoff
		nsyms = len(self.symbols)
		
		stroff = symoff + (len(self.symbols) * 12)
		strsize = 1
		
		for sym in self.symbols:
			strsize += len(sym) + 2
		
		offset  = len(self.symbols) * 12
		offset += strsize
		
		return struct.pack(
			'<LLLLLL',
			cmd, cmdsize,
			symoff, nsyms,
			stroff, strsize
		), offset
	
	def writeDySymtab(self, fileoff):
		cmd, cmdsize = 0xb, 80
		
		ilocalsym = 0
		nlocalsym = 0
		
		iextdefsym = 1
		nextdefsym = len(self.symbols)
		
		iundefsym = 0
		nundefsym = 0
		
		tocoff = fileoff
		ntoc = len(self.symbols)
		
		modtaboff = 0
		nmodtab = 0
		
		extrefsymoff = fileoff
		nextrefsyms = len(self.symbols)
		
		indirectsymoff = 0
		nindirectsyms = 0
		
		extreloff = 0
		nextrel = 0
		
		locreloff = 0
		nlocrel = 0
		
		return struct.pack(
			'<LLLLLLLLLLLLLLLLLLLL',
			cmd, cmdsize,
			ilocalsym, nlocalsym,
			iextdefsym, nextdefsym,
			iundefsym, nundefsym,
			tocoff, ntoc,
			modtaboff, nmodtab,
			extrefsymoff, nextrefsyms,
			indirectsymoff, nindirectsyms,
			extreloff, nextrel,
			locreloff, nlocrel
		)
		
	def writeSegment(self, sec, fileoff):
		cmd, cmdsize = 0x1, 56 + 68
		
		segname = sec.name
		
		if segname[0] == '.':
			segname = segname[1:]
		elif segname[0] == '_':
			segname = segname[1:]
			if segname[0] == '_':
				segname = segname[1:]
		
		segname = segname.upper()
		segname = segname.replace('ALKY', '')
		
		segname = 'ALKY%s' % segname
		
		while segname in self.used_segments:
			segname += '_'
		
		self.used_segments.append(segname)
		
		data = struct.pack(
			'<LL16sLLLLLLLL', cmd, cmdsize,
			segname, sec.addr, sec.size,
			fileoff, len(sec.data), 7,
			sec.prot, 1, 0x4 # SG_NORELOC
		)
		
		data += self.writeSection(segname, sec, fileoff)
		
		sec.name = segname
		
		return data
	
	def writeSection(self, segname, sec, fileoff):
		align = 0
		reloff = nreloc = 0
		reserved1 = reserved2 = 0
		
		flags = 0x04000400L
		
		secname = sec.name
		
		if secname[0] == '.':
			secname = secname[1:]
		elif secname[0] == '_':
			secname = secname[1:]
			if secname[0] == '_':
				secname = secname[1:]
		
		secname = secname.lower()
		secname = secname.replace('alky', '')
		
		secname = '__%s' % secname
		
		return struct.pack(
			'<16s16sLLLLLLLLL', secname, segname,
			sec.addr, sec.size, fileoff, align,
			reloff, nreloc, flags, reserved1,
			reserved2
		)
