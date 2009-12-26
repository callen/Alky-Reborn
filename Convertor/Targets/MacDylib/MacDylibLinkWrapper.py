# Copyright 2006 Falling Leaf Systems, LLC.
# Refer to LICENSE in the root directory.

import os

class MacDylibLinkWrapper:
	def __init__(self, source):
		self.source      = source
		self.imports     = source.imports
		self.entry_point = source.entry_point
	
	def output(self, filename):
		linkwrapper = file('Targets/MacDylib/linkwrapper.c', 'r').read()
		linkwrapper = linkwrapper.replace('%IMPORT_PATH%', '/tmp/imports.h')
		linkwrapper = linkwrapper.replace('%ENTRY_POINT%', '0x%08x' % self.entry_point)
		
		fp = file('/tmp/linkwrapper.c', 'w')
		fp.write(linkwrapper)
		fp.close()
		
		fp = file('/tmp/imports.h', 'w')
		
		for imp in self.imports:
			imp = self.imports[imp]
			print >>fp, 'IMPORT("%s", "%s", 0x%08x);' % (imp[1].lower().replace('.dll', ''), imp[2], imp[3])
		
		fp.close()
		
		ret = os.system('gcc -c -dynamic -o %s %s -I../LibAlky -I/Library/Frameworks/SDL.framework/Headers/' % (filename, '/tmp/linkwrapper.c'))
		
		if ret != 0:
			return False
		
		return True