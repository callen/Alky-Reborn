#!/usr/bin/env python
# encoding: utf-8
"""
main.py

Created by  on 2006-12-26.
Copyright (c) 2006 Falling Leaf Systems, LLC All rights reserved.
"""

from Sources.D3D import D3D
import sys

d3d = D3D(file(sys.argv[1], 'rb').read())
