# Copyright 2006 Falling Leaf Systems, LLC.
# Refer to LICENSE in the root directory.

#!/usr/bin/env python

import pefile

import struct, sys

def main(args):
    filename = args[0]
    addr = eval(args[1])

    pe = pefile.PE(filename)

    for section in pe.sections:
        secaddr = section.VirtualAddress + pe.OPTIONAL_HEADER.ImageBase

        if addr >= secaddr and addr < secaddr + section.Misc_VirtualSize:
            mc = section.data[addr - secaddr - 4:addr - secaddr]
            addr = struct.unpack('<L', mc)[0]

            for imp in pe.DIRECTORY_ENTRY_IMPORT:
                dll, imps = imp.dll, imp.imports
                for temp in imps:
                    if temp.address == addr:
                        print temp.name
                        sys.exit()

            if addr < 0x2fff:
                print '%04x' % addr
                sys.exit()

    print 'No result'

if __name__=='__main__':
    main(sys.argv[1:])
