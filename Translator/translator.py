# Copyright 2006 Falling Leaf Systems, LLC.
# Refer to LICENSE in the root directory.

import sys
sys.path.append('../Convertor')

import Formats

class Translator:
	def __init__(self, args):
		self.formats = []
		self.targets = []
		
		for format in Formats.__formats__:
			self.formats.append(format.__fileformat_desc__)
		
		input = self.read(args[0])
		
		print input
	
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
	Translator(sys.argv[1:])

