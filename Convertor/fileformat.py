# Copyright 2006 Falling Leaf Systems, LLC.
# Refer to LICENSE in the root directory.

FILEFORMAT_READ	  = 1
FILEFORMAT_WRITE  = 2

SECTION_READ  = 1
SECTION_WRITE = 2
SECTION_EXEC  = 4
SECTION_ALL   = SECTION_READ  | \
				SECTION_WRITE | \
				SECTION_EXEC

class FileFormatException(Exception):
	pass

class UnsupportedAction(FileFormatException):
	pass
   
class Section:
	def __init__(self, name, addr, data, size,
				 prot):
		"""
		Initializes a section object
	
		@param	name:	   Section name
		@type	name:	   C{string}
	
		@param	addr:	   Section address in memory
		@type	addr:	   C{int}
	
		@param	data:	   Section data
		@type	data:	   C{string}
	
		@param	size:	   Size of section in memory
		@type	size:	   C{int}
	
		@param	prot:	   Section protection flags
		@type	prot:	   C{int}
		"""
	
		self.name, self.addr, self.data, self.size, self.prot = \
			name, addr, data, size, prot
	
	def __str__(self):
		return self.name
	
	def __repr__(self):
		return 'Section(name=%s)' % `self.name`

class FileFormat:
	capabilities = ()
	def __init__(self, image_base=None, entry_point=None, is_shared=False):
		self.sections		= []
		self.symbols		= {}
		self.imports		= {}
		self.image_base		= image_base
		self.entry_point	= entry_point
		self.is_shared		= is_shared
	
	def copy(self, source):
		self.image_base  = source.image_base
		self.entry_point = source.entry_point
		self.is_shared   = source.is_shared
		
		for sec in source.sections:
			self.addSection(sec)
		
		for imp in source.imports:
			self.imports[imp] = source.imports[imp]
		
		for symname in source.symbols:
			self.symbols[symname] = source.symbols[symname]
		
		return self
	
	def addImport(self, module=None, ordinal=None, name=None, addr=None):
		if name == None:
			name = 'Unknown'
			while name in self.imports:
				name += '_'
		self.imports[name] = (ordinal, module, name, addr)
	
	def addSymbol(self, ordinal=None, name=None, addr=None):
		if name == None:
			name = 'Unknown'
			while name in self.symbols:
				name += '_'
		self.symbols[name] = (ordinal, addr)
	
	def addSection(self, section):
		self.sections.append(section)
		
	def write(self, fp):
		"""
		Write file to given file pointer
	   
		@param	fp:		File pointer to output file
		@type	fp:		C{file}
		"""
		raise UnsupportedAction('File writing is not yet supported in %s' %
				str(self.__class__)
		)
		
	def read(self, fp):
		"""
		Read file from given file pointer
	   
		@param	fp:		File pointer to input file
		@type	fp:		C{file}
	   
		@return:	This L{FileFormat} object after reading from the file
		@rtype:		L{FileFormat}
		"""
		raise UnsupportedAction('File reading is not yet supported in %s' %
				str(self.__class__)
		)
	   
