# Copyright 2006 Falling Leaf Systems, LLC.
# Refer to LICENSE in the root directory.

import os

class MacDylibLinker:
	def __init__(self, source, dest, linkwrapper, converted):
		self.source      = source
		self.dest        = dest
		self.linkwrapper = linkwrapper
		self.converted   = converted
	
	def output(self, filename):
		ld = []
		ld.append('ld')
		
		for section in self.dest.sections:
			ld.append('-seg1addr %08X' % (section.addr - 0x1000))
			break
		
		ld.append('-o ' + filename)
		ld.append('-dylib')
		ld.append('-dynamic')
		ld.append(self.converted)
		ld.append(self.linkwrapper)
		ld.append('/Developer/SDKs/MacOSX10.4u.sdk/usr/lib/libSystem.dylib')
		
		if os.system(' '.join(ld)) != 0:
		    return False
		
		return True