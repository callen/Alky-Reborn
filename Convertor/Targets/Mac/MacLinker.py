# Copyright 2006 Falling Leaf Systems, LLC.
# Refer to LICENSE in the root directory.

import os

class MacLinker:
	def __init__(self, source, dest, linkwrapper, converted):
		self.source      = source
		self.dest        = dest
		self.linkwrapper = linkwrapper
		self.converted   = converted
	
	def output(self, filename):
		ld = []
		ld.append('ld -e start')
		
		for section in self.dest.sections:
			ld.append('-segaddr %s 0x%08X' % (section.name, section.addr))
		
		ld.append('-o ' + filename)
		ld.append('-execute /tmp/SDLMain.o')
		# ld.append('-execute ' + self.linkwrapper)
		ld.append(self.linkwrapper)
		ld.append('/Developer/SDKs/MacOSX10.4u.sdk/usr/lib/libSystem.dylib')
		ld.append('/Developer/SDKs/MacOSX10.4u.sdk/usr/lib/crt1.o')
		ld.append('/usr/lib/gcc/i686-apple-darwin8/4.0.1/libgcc.a')
		ld.append('-framework Cocoa')
		ld.append('-F.')
		ld.append('-framework SDL')
		ld.append(self.converted)
		
		ld = ' '.join(ld)
		
		print ld
		
		if os.system(ld) != 0:
		    return False
		
		return True