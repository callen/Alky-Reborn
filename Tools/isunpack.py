#!/usr/bin/env python
# encoding: utf-8
"""
isunpack.py

Created by  on 2007-02-05.
Copyright (c) 2007 Falling Leaf Systems, LLC. All rights reserved.
"""

import sys
import os
import zipfile

header = '\x50\x4b\x03\x04'

def main((filename, directory)):
	fp = file(filename, 'rb')
	
	data = ''
	
	i = 0
	
	while True:
		data += fp.read(4096)
		
		if len(data) < 5:
			break
		
		if header in data:
			cur = fp.tell()
			
			data = data[data.find(header)]
			
			cabfp = file('zips/temp.zip.%04i' % i, 'wb')
			cabfp.write(data)
			
			print 'Dumping zip file to disk'
			
			seen_header = 0
			
			while True:
				data = fp.read(4096)
				
				if not data:
					break
				
				if header in data:
					seen_header += 1
					
					if seen_header == 3:
						break
				
				cabfp.write(data)
			
			cabfp.close()
			
			print 'Finished dumping'
			
			fp.seek(cur)
			
			"""
			try:
				zip = zipfile.ZipFile('zips/temp.zip.%i' % i)
				print zip.namelist()
			except:
				continue
			
			print 'Executing unzip'
			
			command = 'unzip -d "%s" %s' % (directory, 'temp.zip')
			
			os.system(command)
			
			print 'Finished executing unzip'
			"""
			
			i += 1
		
		data = data[-3:]

if __name__=='__main__':
    main(sys.argv[1:])

