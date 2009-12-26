#!/bin/bash

svn co http://www.alkyproject.com/svn/alky/ alky
cd alky/trunk/LibAlky/

# Comment this out and uncomment the next line
# if you have dual-processors/dual-core.
scons
# scons -j 2

cd ../Convertor/

ln -s ../LibAlky/Nucleus Nucleus
ln -s ../LibAlky/Build Build

curl -o Lesson5.exe http://alkyproject.com/cody/Lesson5.exe

python convertor.py Lesson5.exe Lesson5 Mac

./Lesson5