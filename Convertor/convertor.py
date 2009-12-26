# Copyright 2006 Falling Leaf Systems, LLC.
# Refer to LICENSE in the root directory.

import sys

import Formats, Targets

from optparse import OptionParser

class Convertor:
	def __init__(self):
		self.formats = []
		self.targets = []
		
		for format in Formats.__formats__:
			self.formats.append(format.__fileformat_desc__)
		
		for target in Targets.__targets__:
			self.targets.append(target.__target_desc__)
	
	def convertCLI(self, args):
		if 'darwin' in sys.platform:
			target = 'Mac'
		else:
			target = 'Linux'
		
		parser = OptionParser()
		parser.add_option(
			'-s', '--shared', dest='shared', action='append',
			help='Adds a shared object to combine into the output',
			metavar='foo.dll'
		)
		parser.add_option(
			'-t', '--target', dest='target', action='store',
			help='Specifies the target to use [%s]' % target,
			metavar='TARGET', default=target
		)
		
		(options, args) = parser.parse_args(args=args)
		
		if len(args) == 2:
			in_file, out_file = args
		else:
			parser.print_help()
			return 1
		
		if in_file[-4:] == '.dll':
			shared = True
		else:
			shared = False
		
		in_file = self.read(in_file)
		
		if options.shared == None:
			options.shared = []
		
		shared_entries = []
		
		for name in options.shared:
			try:
				dll = self.read(name)
				
				shared_entries.append((name, dll.image_base, dll.entry_point))
			
				for sec in dll.sections:
					while True:
						found = False
						for sectemp in in_file.sections:
							if sec == sectemp:
								continue
							if sec.name == sectemp.name:
								sec.name += '_'
								found = True
								break
						if not found:
							break
					in_file.sections.append(sec)
			
				for sym in dll.symbols:
					in_file.symbols[sym] = dll.symbols[sym]
			
				for imp in dll.imports:
					impdest = imp
					while impdest in in_file.imports:
						impdest += '_'
				
					in_file.imports[impdest] = dll.imports[imp]
			except Exception, e:
				print e
		
		for section in in_file.sections:
			if not len(section.name.strip()):
				name = 'emptyname'
				while True:
					found = False
					for sec in in_file.sections:
						if sec.name == name:
							found = True
							break
					if not found:
						break
					name += '_'
				section.name = name
			
			print '%s - %08x-%08x (%08x) %r' % (section.name, section.addr, section.addr + section.size, section.size, section.data[:6])
			section.data += '\0' * (section.size - len(section.data))
			
			if len(section.data) % 4 != 0:
				section.data += '\0' * (4 - (len(section.data) % 4))
		
		temp_file = '/tmp/' + out_file
		
		target = self.getTarget(options.target)
		
		if 'prewrite' in target:
			in_file = target['prewrite'](in_file)
		
		print '%08x' % in_file.entry_point
		
		dest = self.write(
			filename=temp_file,
			format=target['fileformat'],
			source=in_file,
			shared=shared
		)
		
		linkwrapper = self.linkwrapper(
			source=in_file,
			target=target,
			shared=shared_entries
		)
		
		self.linker(
			source=in_file,
			dest=dest,
			target=target,
			linkwrapper=linkwrapper,
			converted=temp_file,
			result=out_file
		)
		
		return 0
	
	def getTarget(self, name):
		for target in self.targets:
			if target['name'] == name:
				return target
		return None
	
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
	
	def write(self, filename, format, source, shared):
		fp = file(filename, 'wb')
		found = None
		
		for format_ in self.formats:
			if format == format_['name']:
				found = format_
				break
		
		if not found:
			return None
		
		format = found['fileformat_class']()
		format.copy(source)
		
		format.is_shared = shared
		
		format.write(fp)
		
		fp.close()
		
		return format
	
	def linkwrapper(self, source, target, shared):
		filename = '/tmp/linkwrapper'
		linkwrapper = target['linkwrapper'](source, shared)
		linkwrapper.output(filename)
		
		return filename
	
	def linker(self, source, dest, target, linkwrapper, converted, result):
		linker = target['linker']
		linker = linker(source, dest, linkwrapper, converted)
		linker.output(result)


if __name__=='__main__':
	sys.exit(Convertor().convertCLI(sys.argv[1:]))
