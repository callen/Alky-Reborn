#!/bin/bash

grep -v extrn $1 | sed 's/gl[A-Z]/&^%/; s/.* ; \([ \*a-zA-Z0-9_]*[a-zA-Z0-9_][\(].*[\)]\)[^\)]*/\1;/; s/.*Imports from \(.*\)/!\1/; s/__stdcall/WINAPI/; s/  / /;' | grep -v '.idata' > ida.txt
python idaparse.py ida.txt $2