# Copyright 2006 Falling Leaf Systems, LLC.
# Refer to LICENSE in the root directory.

from LinuxLinkWrapper import LinuxLinkWrapper
from LinuxLinker      import LinuxLinker

__target_desc__ = dict(
	name        = 'Linux',
	linkwrapper = LinuxLinkWrapper,
	linker      = LinuxLinker,
	fileformat  = 'ELF',
	sharedObject= False,
)
