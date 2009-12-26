# Copyright 2006 Falling Leaf Systems, LLC.
# Refer to LICENSE in the root directory.

import sys

sys.path.append('Formats')

import Formats

class OrdMapper:
	def __init__(self):
		self.formats = []
		
		for format in Formats.__formats__:
			self.formats.append(format.__fileformat_desc__)
	
	def generateMap(self, filename):
		in_file = self.read(filename)
		
		if not in_file:
			return 0
		
		for exp in in_file.symbols:
			print exp, in_file.symbols[exp]
		
		return 0
	
	def read(self, filename):
		fp = file(filename, 'rb')
		
		for format in self.formats:
			fp.seek(0)
				
			try:
				signature = format['signature']
			except AttributeError:
				continue
			
			match = fp.read(len(signature))
			
			fp.seek(0)
			if match == signature:
				format_obj = format['fileformat_class']()
				format_obj.read(fp)
				fp.close()
				return format_obj
		
		return None

if __name__=='__main__':
	sys.exit(OrdMapper().generateMap(sys.argv[1]))
