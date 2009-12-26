# Copyright 2006 Falling Leaf Systems, LLC.
# Refer to LICENSE in the root directory.

from SCons.Environment import Environment
import os, sys, glob

LINKFLAGS  = ['-L%s' % name_ for name_ in glob.glob(os.getcwd() + '/APIs/*/*/')]
LINKFLAGS += ['-L%s' % name_ for name_ in glob.glob(os.getcwd() + '/APIs/*/*/*/')]
LINKFLAGS += ['-L%s' % name_ for name_ in glob.glob(os.getcwd() + '/APIs/*/*/*/*/')]
LINKFLAGS += ['-L%s' % name_ for name_ in glob.glob(os.getcwd() + '/Nucleus/*/')]
LINKFLAGS = ' '.join(LINKFLAGS)

CCFLAGS = ['-I.', '-g', '-O2']
if 'darwin' in sys.platform:
	CCFLAGS.append('-mstackrealign')
	CCFLAGS.append(' -I/Library/Frameworks/SDL.framework/Headers/')
	MAC = True
	LINUX = False
	WIN = False
else:
	CCFLAGS.append('')
	LINUX = True
	MAC = False
	WIN = False
CCFLAGS.append(LINKFLAGS)
CCFLAGS = ' '.join(CCFLAGS)
env = Environment(CCFLAGS=CCFLAGS, LINKFLAGS=LINKFLAGS)

libs = {}
depends = {}

def AlkyLib(name, *args, **kwargs):
	# Reduce path to LibAlky
	# Eg. /foo/bar/LibAlky/baz
	# Becomes /foo/bar/LibAlky
	path = os.getcwd()
	path = path.replace('\\', '/')
	path = path.split('/')
	for i in range(len(path)):
		if path[i] == 'LibAlky':
			break
	path = path[:i + 1]
	path = '/'.join(path)
	
	print 'Library named', name
	
	if 'CCFLAGS' in kwargs:
		kwargs['CCFLAGS'] = CCFLAGS + ' ' + kwargs['CCFLAGS']
	else:
		kwargs['CCFLAGS'] = CCFLAGS

	if 'LINKFLAGS' in kwargs:
		kwargs['LINKFLAGS'] = LINKFLAGS + ' ' + kwargs['LINKFLAGS']
	else:
		kwargs['LINKFLAGS'] = LINKFLAGS

	if 'FRAMEWORKS' in kwargs:
		if MAC:
			kwargs['LINKFLAGS'] += ' ' + ' '.join(['-framework %s' % framework for framework in kwargs['FRAMEWORKS']])
		else:
			kwargs['LINKFLAGS'] += ' ' + ' '.join(['-l%s' % framework for framework in kwargs['FRAMEWORKS']])
		del kwargs['FRAMEWORKS']

	lib = env.SharedLibrary(name, *args, **kwargs)
	
	libs[name] = lib
	
	AlkyDepends(lib, name, kwargs)
	
	env.Install(path + '/Build', lib)
	
	lib = env.Library(name + '_static', *args, **kwargs)
	
	libs[name + '_static'] = lib
	
	AlkyDepends(lib, name + '_static', kwargs)

	env.Install(path + '/Build', lib)
	
def AlkyTest(name):
	env.SConscript(name + '/SConscript')

def AlkyDepends(lib, name, kwargs):
	if name in depends:
		for lib_ in depends[name]:
			env.Depends(lib_, [libs[name], ])
	
	if 'LIBS' in kwargs:
		for name_ in kwargs['LIBS']:
			if name_ in libs:
				print name, name_
				env.Depends(lib, [libs[name_], ])
			else:
				if not name_ in depends:
					depends[name_] = []
				depends[name_].append(lib)
