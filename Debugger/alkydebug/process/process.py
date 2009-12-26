# Copyright 2006 Falling Leaf Systems, LLC.
# Refer to LICENSE in the root directory.

import alkydebug_c

class AlkyProcessException(Exception):
	pass

class Process:
	def __init__(self, pid=None, name=None, commandLine=None):
		if not pid and not name and not commandLine:
			raise AlkyProcessException('No name, PID, or command line passed to Process constructor')
		
		if pid or name:
			raise AlkyProcessException('Attaching to existing processes is not yet implemented')
			
		self.pid = pid
		self.name = name
		
		if commandLine and not (self.pid or self.name):
			self.start(commandLine)
	
	def start(self, commandLine):
		self.pid = alkydebug_c.traceByCommandLine(commandLine)
	
	def cont(self):
		return alkydebug_c.cont(self.pid)
	
	def resume(self):
		return alkydebug_c.resume(self.pid)
	
	def suspend(self):
		return alkydebug_c.suspend(self.pid)
	
	def detach(self):
		return alkydebug_c.detach(self.pid)
	
	def singleStep(self):
		return alkydebug_c.singleStep(self.pid)
	
	def getRegisters(self):
		return alkydebug_c.getRegisters(self.pid)
	
	def setRegisters(self, regs):
		return alkydebug_c.setRegisters(self.pid, regs)

	def peekMemory(self, addr, count):
		orig_addr = addr
		
		if addr & 0xFFF:
			orig_addr = addr
			addr &= ~0xFFF
		
		mem = alkydebug_c.peekMemory(self.pid, addr, count + (orig_addr - addr))
		
		if not mem:
			return False
		
		if orig_addr != None:
			return mem[orig_addr - addr:]
		else:
			return mem
	
	def pokeMemory(self, addr, val):
		count = len(val)
		orig_addr = None
		
		if addr & 0xFFF:
			orig_addr = addr
			addr &= ~0xFFF
			
			page_count = count + (orig_addr - addr)
			page_count >>= 12
			
			if page_count == 0:
				page_count = 1
			
			pages = self.peekMemory(addr, page_count << 12)
			
			pages = pages[:orig_addr - addr] + val + pages[count + (orig_addr - addr):]
		elif count < 0x1000 or count & 0xFFF:
			page_count = count
			page_count >>= 12
			
			if page_count == 0:
				page_count = 1
				
			pages = val + self.peekMemory(addr + count, (page_count << 12) - count)
		else:
			pages = val
		
		return alkydebug_c.pokeMemory(self.pid, addr, pages)