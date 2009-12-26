#!/usr/bin/env python
# encoding: utf-8
"""
LinuxConvert.py

Created by Cody Brocious on 2007-02-11.
Copyright (c) 2007 Falling Leaf Systems, LLC. All rights reserved.
"""

import sys, os, urllib2, zipfile

import convertor

def unpackAndInstall(zip):
	os.system('unzip %s -d /tmp/' % zip)
	
	os.system('wine /tmp/SetupPreyDemo.exe')
	os.unlink('/tmp/SetupPreyDemo.exe')

def findPreyDir():
	for root, dirs, files in os.walk(os.path.expanduser('~')):
		if 'prey.exe' in files and 'base' in dirs:
			return root

def unpackDll(dir):
	zip = zipfile.ZipFile('%s/base/demo00.pk4')
	fp = file('%s/base/gamex86.dll', 'wb')
	
	fp.write(zip.read('gamex86.dll'))
	
	fp.close()
	zip.close()

def convertBinary(dir):
	cli = ['-s', dir + '/base/gamex86.dll', dir + '/prey.exe', 'out_temp']
	
	conv = convertor.Convertor()
	conv.convertCLI(cli)
	
	dir = dir.replace('\\', '\\\\').replace('"', '\\"')
	
	os.system('mv "out_temp" "%s"' % dir)

def makeCopies(dir):
	curdir = sys.path[0].replace('\\', '\\\\').replace('"', '\\"')
	destdir = dir.replace('\\', '\\\\').replace('"', '\\"')
	
	os.system('cp -Rf "%s" "%s"' % (curdir, destdir))

def main(filename):
	if not yesNo('Would you like to download and install the Prey Demo from 3DRealms?'):
		return
	
	unpackAndInstall(filename)
	
	preydir = findPreyDir()
	
	unpackDLL(preydir)
	
	convertBinary(preydir)
	
	makeCopies(preydir)

if __name__=='__main__':
	sys.exit(main(*sys.argv[1:]))
