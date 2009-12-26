# Copyright 2006 Falling Leaf Systems, LLC.
# Refer to LICENSE in the root directory.

import pefile
from fileformat import *

import ordinals

class PE(FileFormat):
	capabilities = (FILEFORMAT_READ, )
	
	def read(self, fp):
		"""
		Read file from given file pointer
	   
		@param	fp:		File pointer to input file
		@type	fp:		C{file}
	   
		@return:	This L{FileFormat} object after reading from the file
		@rtype:		L{FileFormat}
		"""
		
		pe = pefile.PE(data=fp.read())
		
		self.image_base = pe.OPTIONAL_HEADER.ImageBase
		self.entry_point = pe.OPTIONAL_HEADER.ImageBase + pe.OPTIONAL_HEADER.AddressOfEntryPoint
		
		fp.seek(0)
		
		sec = Section(
			name='.alkyimage',
			addr = pe.OPTIONAL_HEADER.ImageBase,
			data = fp.read(0x1000),
			size = 0x1000,
			prot = SECTION_ALL
		)
		
		self.addSection(sec)
		
		for section in pe.sections:
			name = section.Name
			addr = section.VirtualAddress + self.image_base
			data = section.data
			size = section.Misc_VirtualSize
			align = pe.OPTIONAL_HEADER.FileAlignment
			
			print name, `data[:6]`
			
			sec = Section(
				name=name, addr=addr, data=data,
				size=size, prot=SECTION_ALL
			)
			
			self.addSection(sec)
		
		"""
		for relocs in pe.DIRECTORY_ENTRY_BASERELOC:
			for reloc in relocs.entries:
				print '%08x' % reloc.rva
		"""
		
		for import_ in pe.DIRECTORY_ENTRY_IMPORT:
			dll, imports = import_.dll, import_.imports
			for imp in imports:
				if not imp.name:
					if dll.upper() in ordinals.ordinals:
						try:
							imp.name = ordinals.ordinals[dll.upper()][imp.ordinal]
						except:
							pass
				self.addImport(module=dll, ordinal=imp.ordinal, name=imp.name, addr=imp.address)
		
		if hasattr(pe, 'DIRECTORY_ENTRY_EXPORT'):
			for exp in pe.DIRECTORY_ENTRY_EXPORT.symbols:
				self.addSymbol(ordinal=exp.ordinal, name=exp.name, addr=exp.address + self.image_base)