import sys

lines = [line.strip() for line in file(sys.argv[1]).readlines()]
matches = []
	
for left in file(sys.argv[2]).readlines():
	module, name = left.strip().split('::')
	
	for line in lines:
		if not line:
			continue
		if line[0] == '!':
			continue
		if name + '(' in line:
			matches.append(line)

for line in lines:
	if line and line[0] == '!' or line in matches:
		print line