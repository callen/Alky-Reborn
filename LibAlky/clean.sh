#!/bin/bash

scons -c
find . -iname ".sconsign" | xargs rm
find . -iname "*.pyc" | xargs rm
