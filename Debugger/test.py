# Copyright 2006 Falling Leaf Systems, LLC.
# Refer to LICENSE in the root directory.

import alkydebug
import time
import sys

def foo(debug):
	old = debug.process.peekMemory(0x006FBAA3L, 2)
	if old == '\xff\xd0':
		if not debug.process.pokeMemory(0x006FBAA3L, '\x90\x90'):
			print 'Failed poking?!'
			return
		if old == debug.process.peekMemory(0x006FBAA3L, 2):
			print 'Memory didn\'t write.'
			return
		print 'Success!'
	elif not old:
		print 'Could not read memory.'
		return
	else:
		print 'Memory not what was expected.'
		return

def main(args):
	process = alkydebug.Process(commandLine='./foo')
	debug = alkydebug.Debug(process)

	debug.start()
	
	foo(debug)
	
	debug.process.cont()

	if debug.process.detach():
		print 'Detached'
	else:
		print 'Could not detach'

main([])