# Copyright 2006 Falling Leaf Systems, LLC.
# Refer to LICENSE in the root directory.

import os

loweralpha = 'abcdefghijklmnopqrstuvwxyz'

class LinuxLinker:
	def __init__(self, source, dest, linkwrapper, converted):
		self.source      = source
		self.dest        = dest
		self.linkwrapper = linkwrapper
		self.converted   = converted
	
	def createLinkerscript(self):
		ldscript = os.popen('ld -zcombreloc --verbose', 'r').read()
		
		ldscript = ldscript.split('==================================================')[1]
		ldscript = ldscript[:ldscript.rfind('}')] # Chop off last curly brace
		
		phdrs = []
		phdrs.append('headers PT_PHDR PHDRS;')
		phdrs.append('interp PT_INTERP;')
		phdrs.append('text PT_LOAD FILEHDR PHDRS;')
		phdrs.append('data PT_LOAD;')
		phdrs.append('dynamic PT_DYNAMIC;')
		
		seg_map = dict(
			interp=('.interp',),
			text=(
				'.interp', '.note.ABI-tag', '.hash', '.dynsym',
				'.dynstr', '.gnu.version', '.gnu.version_r',
				'.rel.got', '.rel.bss', '.rel.plt', '.init',
				'.plt', '.text', '.fini', '.rodata'
			),
			data=('.dynamic', '.got', '.got.plt', '.data', '.bss'),
			dynamic=('.dynamic',),
		)
		
		prev = ldscript.find('SECTIONS')
		while True:
			curly = ldscript.find('}', prev)
			
			if curly < 0:
				break
			
			lcurly = ldscript.rfind('{', 0, curly)
			colon = ldscript.rfind(':', 0, curly)
			dot = ldscript.rfind('.', 0, lcurly)
			slash = ldscript.rfind('/', 0, lcurly)
			semi = ldscript.rfind(';', 0, curly)
			
			curly += 1
			prev = curly
			
			if slash > dot:
				continue
			
			while True:
				newdot = ldscript.rfind('.', 0, dot)
				cut = ldscript[newdot+1:dot].lower()
				
				right = True
				
				for char in cut:
					if char in loweralpha:
						continue
					else:
						right = False
						break
				
				if not right:
					break
				
				dot = newdot
			
			if not (curly > lcurly > colon > dot > semi):
				continue
			
			segname = ldscript[dot:colon].strip().split(' ', 1)[0]
			
			segstr = ''
			
			for seg in seg_map:
				seglist = seg_map[seg]
				if segname in seglist:
					segstr += ' :%s' % seg
			
			if segstr:
				ldscript = ldscript[:curly] + segstr + ldscript[curly:]
			
			prev += 6
		
		segs = []
		
		i = 0
		for section in self.dest.sections:
			phdrs.append('alky%i PT_LOAD;' % i)
			segs.append('  %s 0x%08x : { *(%s) } :alky%i' % (section.name, section.addr, section.name, i))
			i += 1
		
		ldscript += '\n'.join(segs)
		ldscript += '\n}\n'
		
		ldscript = list(ldscript.split('SECTIONS', 1))
		
		ldscript[0] += '\nPHDRS {\n  %s\n}\n' % '\n  '.join(phdrs)
		
		ldscript = 'SECTIONS'.join(ldscript)
		
		return ldscript
	
	def output(self, filename):
		file('/tmp/linkerscript.ld', 'w').write(self.createLinkerscript())
		
		ld = []
		ld.append('ld')
		ld.append('-o ' + filename)
		# Define linker, output type and that we want the header frame
		ld.append('-eh-frame-hdr -m elf_i386 -dynamic-linker /lib/ld-linux.so.2')
		
		# Basic stdlib stuff
		ld.append('/usr/lib/crt1.o')
		ld.append('/usr/lib/crti.o')
		
		# Ask gcc where gcc.a is located, and get the dirname from that
		ld.append('-L`dirname \`gcc -print-libgcc-file-name\``')
		ld.append('-L/usr/lib')
		
		# Use our linkerscript
		ld.append('-T /tmp/linkerscript.ld')
		
		ld.append('-lgcc --as-needed -lgcc_s --no-as-needed -lc -lgcc')
		ld.append('--as-needed -lgcc_s --no-as-needed  ')
		ld.append('/usr/lib/crtn.o -ldl')
		ld.append('--export-dynamic')
		
		ld.append(self.converted)
		ld.append(self.linkwrapper)
		
		print ' '.join(ld)
		
		if os.system(' '.join(ld)) != 0:
		    return False
		
		return True

	"""
	def output_gcc(self, filename):
		file('/tmp/linkerscript.ld', 'w').write(self.createLinkerscript())
		
		ld = []
		ld.append('gcc')
		
		ld.append('-o ' + filename)
		ld.append(self.linkwrapper)
		ld.append(self.converted)

		#for section in self.dest.sections:
		#	ld.append('-Wl,--section-start=%s=0x%08X' % (section.name, section.addr))
		
		ld.append('-ldl')
		ld.append('-Xlinker -T/tmp/linkerscript.ld')
		# ld.append('-e _start')

		print ' '.join(ld)

		if os.system(' '.join(ld)) != 0:
		    return False
		
		return True
	"""
