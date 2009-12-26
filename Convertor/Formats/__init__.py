# Copyright 2006 Falling Leaf Systems, LLC.
# Refer to LICENSE in the root directory.

import fileformat

import ELF, MachO, PE

__formats__ = (
	ELF,
	MachO,
	PE
)