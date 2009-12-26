#!/bin/bash

mkdir $3
mkdir $3/Contents
mkdir $3/Contents/MacOS
ln -s $1/$2 $3/Contents/MacOS/$2
curl http://alkyproject.com/cody/test.plist | sed "s/FOO/$2/;" > $3/Contents/Info.plist
