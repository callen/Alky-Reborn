# Copyright 2006 Falling Leaf Systems, LLC.
# Refer to LICENSE in the root directory.

from diSlib64 import *
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
		
		pe = PEFile(fp)
		
		self.image_base = pe.ImageBase
		self.entry_point = pe.ImageBase + pe.EntryPoint
		
		fp.seek(0)
		
		sec = Section(
			name='.alkyimage',
			addr = pe.ImageBase,
			data = fp.read(0x1000),
			size = 0x1000,
			prot = SECTION_ALL
		)
		
		self.addSection(sec)
		
		for section in pe.Sections:
			name = section.Name
			addr = section.VA + self.image_base
			data = section.Data
			size = section.Size
			align = 1
			
			print name, `data[:6]`
			
			sec = Section(
				name=name, addr=addr, data=data,
				size=size, prot=SECTION_ALL
			)
			
			self.addSection(sec)
		
		print 'shit'
		
		for import_ in pe.Imports:
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