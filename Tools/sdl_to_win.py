sdl_pre = 'SDLK_'
win_pre = 'VK_'

map = \
'''
'''

direct = \
'''
UP
DOWN
LEFT
RIGHT
'''

for line in direct.split('\n'):
	map += '%s %s\n' % (line, line)

letters = [chr(char) for char in range(ord('a'), ord('z') + 1)]

for letter in letters:
	map += '%s %s\n' % (letter, letter.upper())

for line in map.split('\n'):
	line = line.strip()
	if line == '':
		continue
	sdl, win = line.split(' ')
	
	print 'case %s%s: return %s%s' % (sdl_pre, sdl, win_pre, win)