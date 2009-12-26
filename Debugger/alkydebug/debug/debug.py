# Copyright 2006 Falling Leaf Systems, LLC.
# Refer to LICENSE in the root directory.

import time

class AlkyDebugException(Exception):
	pass

class Debug:
	def __init__(self, process=None):
		self.process = process
	
	def getProcess(self):
		return self.process
	
	def setProcess(self, process):
		self.process = process
		
		return self
	
	def start(self):
		return self.process.singleStep()