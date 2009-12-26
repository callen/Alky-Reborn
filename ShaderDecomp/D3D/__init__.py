#!/usr/bin/env python
# encoding: utf-8
"""
__init__.py

Created by  on 2006-12-26.
Copyright (c) 2006 Falling Leaf Systems, LLC All rights reserved.
"""

from source import Source

import disasm
# import decomp

class D3D(Source):
    def __init__(self, data):
        self.asm = disasm.disasm(data)
    
    def getAFT(self):
        return decomp.decomp(self.asm)
