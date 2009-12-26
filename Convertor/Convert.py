#!/usr/bin/env python
# encoding: utf-8
"""
Convert.py

Created by Cody Brocious on 2006-12-20.
Copyright (c) 2006 __MyCompanyName__. All rights reserved.
"""

import sys
import os
import posixpath

import convertor

def main(args):
	app_path = os.getcwd().split('/')
	app_path = '/'.join(app_path[:-3])
	app = app_path + '/Prey.app'
	
	cli = ['-s', app_path + '/base/gamex86.dll', app_path + '/prey.exe', 'out_temp']
	
	conv = convertor.Convertor()
	conv.convertCLI(cli)
	
	os.mkdir(app)
	os.mkdir(app + '/Contents')
	os.mkdir(app + '/Contents/MacOS')
	
	fp = file(app + '/Contents/MacOS/temp', 'wb')
	fp.write(file('out_temp', 'rb').read())
	fp.close()
	os.system('chmod +x %s/Contents/MacOS/temp' % app)
	
	fp = file(app + '/Contents/Info.plist', 'wb')
	fp.write(file('Info.plist.template', 'rb').read())
	fp.close()
	
	os.system('cp -R Nucleus %s/Nucleus' % app_path)
	os.system('cp -R Build %s/Build' % app_path)
	
	os.mkdir(app_path + '/My Games')
	os.mkdir(app_path + '/My Games/PREY')
	
	os.system('ln -s %r %r' % (app_path + '/base', app_path + '/My Games/Prey/base'))
	
	os.mkdir(app + '/Contents/Frameworks')
	
	os.system('cp -R SDL.framework %r' % (app + '/Contents/Frameworks/SDL.framework'))

if __name__ == '__main__':
    main(sys.argv[1:])

