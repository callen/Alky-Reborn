#!/usr/bin/env python
# encoding: utf-8
"""
disasm.py

Created by	on 2006-12-26.
Copyright (c) 2006 Falling Leaf Systems, LLC All rights reserved.
"""

import struct
import shader_inst

PIXEL = 1
VERTEX = 0

COMP_X = 0x0
COMP_Y = 0x1
COMP_Z = 0x2
COMP_W = 0x3

def swizzleComp(comp):
	if comp == COMP_X:
		return 'x'
	elif comp == COMP_Y:
		return 'y'
	elif comp == COMP_Z:
		return 'z'
	elif comp == COMP_W:
		return 'w'

class SourceToken(object):
	def __init__(self, token):
		self.register_number =  token & 0x3FF
		token >>= 10
		self.register_type   = (token & 0x03) << 3
		token >>= 2
		self.relative        = token & 0x01
		token >>= 1
		
		token >>= 2
		
		swizzle              = token & 0xFF
		token >>= 8
		
		self.swizzle = (
			 swizzle       & 0x2,
			(swizzle >> 2) & 0x2,
			(swizzle >> 4) & 0x2,
			(swizzle >> 6) & 0x2,
		)
		
		self.modifier        = token & 0xF
		token >>= 4
		
		self.register_type  |= token & 0x07
		token >>= 3
		
		token >>= 1
		
	def __repr__(self):
		if self.register_type == 0:
			str = 'r'
		elif self.register_type == 1:
			str = 'v'
		else:
			str = 'o'
		
		str += '%i.' % self.register_number
		
		swiz  = swizzleComp(self.swizzle[0])
		swiz += swizzleComp(self.swizzle[1])
		swiz += swizzleComp(self.swizzle[2])
		swiz += swizzleComp(self.swizzle[3])
		
		if swiz != 'xyzw':
			str += swiz
		
		return str

class DestToken(object):
	def __init__(self, token):
		self.register_number =  token & 0x3FF
		token >>= 10
		self.register_type   = (token & 0x03) << 3
		token >>= 2
		self.relative        = token & 0x01
		token >>= 1
		
		token >>= 2
		
		self.write_mask      = token & 0x0F
		token >>= 4
		
		self.modifier        = token & 0x0F
		token >>= 4
		
		self.shift_scale     = token & 0x0F
		token >>= 4
		
		self.register_type  |= token & 0x07
		token >>= 3
		
		token >>= 1
	
	def __repr__(self):
		str = 'r%i' % self.register_number
		
		if self.write_mask:
			str += '.'
			
			if self.write_mask & 1:
				str += 'x'
			if self.write_mask & 2:
				str += 'y'
			if self.write_mask & 4:
				str += 'z'
			if self.write_mask & 8:
				str += 'w'
		
		return str

class disasm:
	def __init__(self, data):
		self.opcode_handlers = {}
		
		for inst in shader_inst.instructions:
			self.opcode_handlers[inst[0]] = inst
		
		self.disasm(data)
	
	def __getattr__(self, name):
		try:
			object.getattr(self, name)
		except:
			return None
	
	def disasm(self, data):
		dwords = list(struct.unpack('<' + ('L' * (len(data) >> 2)), data))
		
		version = dwords[0]
		
		minor = version & 0xFF
		major = (version & 0xFF00) >> 8
		self.version = (major, minor)
		
		if (version & 0xFFFF0000) == 0xFFFF0000:
			self.type = PIXEL
		else:
			self.type = VERTEX
		
		offset = 1
		count = len(dwords)
		
		while offset < count:
			token = dwords[offset]
			
			token_type = dwords[offset] & 0x0000FFFF
			
			
			if token_type in self.opcode_handlers:
				inst = self.opcode_handlers[token_type]
				if inst:
					offset, success = self.handleToken(inst, token, dwords, offset)
					
					if success:
						continue
					else:
						offset -= 1
			
			offset += 1
	
	def handleToken(self, inst, token, dwords, offset):
		args = []
		varargs = False
		
		for arg in inst:
			arg_token = dwords[offset]
			
			if arg == shader_inst.SOURCE:
				args.append(SourceToken(arg_token))
			elif arg == shader_inst.DEST:
				args.append(DestToken(arg_token))
			elif arg == shader_inst.LABEL:
				pass
			elif arg == shader_inst.VARARGS:
				varargs = True
				break
			else:
				args.append(arg_token)
			
			offset += 1
		
		func = eval('self.%s' % shader_inst.string_map[token & 0x0000FFFF])
		
		if not func:
			print shader_inst.string_map[token & 0x0000FFFF], args
			return offset, False
		
		if varargs:
			args += [dwords, offset]
			return func(*args), True
		else:
			func(*args)
		
		return offset, True
	
	def ADD(self, inst, dest, left, right):
		print '%r = %r + %r' % (dest, left, right)
	
	def SUB(self, inst, dest, left, right):
		print '%r = %r - %r' % (dest, left, right)
	
	def MUL(self, inst, dest, left, right):
		print '%r = %r * %r' % (dest, left, right)
	
	def DIV(self, inst, dest, left, right):
		print '%r = %r / %r' % (dest, left, right)
	
	def DP3(self, inst, dest, left, right):
		print '%r = dot(%r, %r)' % (dest, left, right)
		
	def DP4(self, inst, dest, left, right):
		print '%r = dot(%r, %r)' % (dest, left, right)
	
	def MIN(self, inst, dest, a, b):
		print '%r = min(%r, %r)' % (dest, a, b)
	
	def MAX(self, inst, dest, a, b):
		print '%r = max(%r, %r)' % (dest, a, b)
	
	def MAD(self, inst, dest, a, b, c):
		print '%r = (%r * %r) + %r' % (dest, a, b, c)
	
	def MOV(self, inst, dest, src):
		print '%r = %r' % (dest, src)
	
	def RCP(self, inst, dest, src):
		print '%r = 1.0f / %r' % (dest, src)
	
	def RSQ(self, inst, dest, src):
		print '%r = 1.0f / sqrt(%r)' % (dest, src)
	
	def COMMENT(self, inst, dwords, offset):
		print 'Comment Token'
		
		len = inst >> 16
		
		comment = dwords[offset:offset+len]
		comment = struct.pack('<' + ('L' * len), *comment)
		print comment
		
		return offset + len
	
	def END(self, inst):
		print 'End Token'
