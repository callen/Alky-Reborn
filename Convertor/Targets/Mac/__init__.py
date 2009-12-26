# Copyright 2006 Falling Leaf Systems, LLC.
# Refer to LICENSE in the root directory.

from MacLinkWrapper import MacLinkWrapper
from MacLinker      import MacLinker

__target_desc__ = dict(
	name        = 'Mac',
	linkwrapper = MacLinkWrapper,
	linker      = MacLinker,
	fileformat  = 'MachO',
	sharedObject= False,
)