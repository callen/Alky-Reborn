import sys, cPickle, os

class FuncDB(object):
	def __init__(self):
		try:
			self.db = cPickle.load(file('funcs.db', 'rb'))
		except:
			self.db = {}
		
		print 'Read %i entries from the function database' % len(self.db)
	
	def write(self):
		cPickle.dump(self.db, file('funcs.db', 'wb'))
	
	def addFile(self, fn):
		w, r = os.popen2('perl headerparse.pl')
		
		w.write(file(fn, 'rb').read())
		w.close()
		
		data = r.read()
		
		lines = data.split('\n')
		
		for i in range(0, len(lines), 3):
			try:
				name, ret, params = lines[i:i+3]
			except:
				continue
			
			self.db[name] = (fn, ret, params)
	
	def getFuncs(self, name):
		byFn = {}
		for func in self.db:
			if name in func or func in name:
				fn, ret, params = self.db[func]
				
				if not fn in byFn:
					byFn[fn] = []
				
				byFn[fn].append((func, ret, params))
		
		for name in byFn:
			print '%s:' % name
			for (func, ret, params) in byFn[name]:
				print '%s %s(%s);' % (ret, func, params)
			print
