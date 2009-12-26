# Copyright 2006 Falling Leaf Systems, LLC.
# Refer to LICENSE in the root directory.

from MacDriverLinkWrapper import MacDriverLinkWrapper
from MacDriverLinker      import MacDriverLinker

def MacDriverPrewrite(source):
	sections = []
	for sec in source.sections:
		if not '.alkyimage' in sec.name:
			sections.append(sec)
	
	source.sections = sections
	
	return source

__target_desc__ = dict(
	name        = 'MacDriver',
	linkwrapper = MacDriverLinkWrapper,
	linker      = MacDriverLinker,
	fileformat  = 'MachO',
	sharedObject= False,
	prewrite    = MacDriverPrewrite
)
