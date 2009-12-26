# Copyright 2006 Falling Leaf Systems, LLC.
# Refer to LICENSE in the root directory.

from elf import ELF

__fileformat_desc__ = dict(
	name = 'ELF',
	fileformat_class = ELF,
	signature = '\x7ELF'
)