import funcDB, sys

if __name__=='__main__':
	fdb = funcDB.FuncDB()
	
	fdb.getFuncs(sys.argv[1])
