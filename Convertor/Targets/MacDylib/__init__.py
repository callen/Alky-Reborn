# Copyright 2006 Falling Leaf Systems, LLC.
# Refer to LICENSE in the root directory.

from MacDylibLinkWrapper import MacDylibLinkWrapper
from MacDylibLinker      import MacDylibLinker

__target_desc__ = dict(
	name        = 'MacDylib',
	linkwrapper = MacDylibLinkWrapper,
	linker      = MacDylibLinker,
	fileformat  = 'MachO',
	sharedObject= True,
)