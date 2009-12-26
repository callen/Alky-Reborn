#!/usr/bin/env python
# encoding: utf-8
"""
setup.py

Created by Cody Brocious on 2006-12-21.
Copyright (c) 2006 Falling Leaf Systems. All rights reserved.
"""

from distutils.core import setup
import py2app

setup(
	app = ['Convert.py'],
	options = dict(
		py2app=dict(
			argv_emulation=True
		)
	)
)
