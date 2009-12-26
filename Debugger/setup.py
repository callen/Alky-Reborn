# Copyright 2006 Falling Leaf Systems, LLC.
# Refer to LICENSE in the root directory.

from distutils.core import setup, Extension
import glob

setup(
	name='Alky Debugger',
	version='0.1',
	description='Alky debugging API',
	author='Cody Brocious',
	author_email='cody.brocious@gmail.com',
	url='http://www.alkyproject.com/',
	packages=['alkydebug', 'alkydebug/process', 'alkydebug/debug'],
	ext_modules=[
		Extension(
			'alkydebug_c',
			list(glob.glob('c/*.c')),
		)
	]
)