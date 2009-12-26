import funcDB, sys

if __name__=='__main__':
	fdb = funcDB.FuncDB()
	
	for arg in sys.argv[1:]:
		print arg
		fdb.addFile(arg)
	
	fdb.write()
