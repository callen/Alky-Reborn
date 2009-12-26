/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifdef HACK

#define ALKY_TRACEME PTRACE_TRACEME
#define ALKY_SINGLESTEP PTRACE_SINGLESTEP

static PyObject *
Alky_TraceByCommandLine(PyObject *self, PyObject *args) {
	const char *app;
	
	int pid;
	
	if(!PyArg_ParseTuple(args, "s", &app))
		return NULL;
	
	switch(pid = fork()) {
		case -1:
			return Py_False;
		case 0:
			ptrace(ALKY_TRACEME, 0, 0, 0);
			
			execl(app, NULL);
			
			exit(0);
			
			break;
		default:
			return Py_BuildValue("l", pid);
	}
	
	return Py_True;
}

static PyObject *
Alky_SingleStep(PyObject *self, PyObject *args) {
	int pid, waiter;
	
	if(!PyArg_ParseTuple(args, "l", &pid))
		return NULL;
	
	wait(&waiter);
	
	if(ptrace(ALKY_SINGLESTEP, pid, 0, 0) != 0)
		return Py_False;
	
	return Py_True;
}

static PyObject *
Alky_GetRegisters(PyObject *self, PyObject *args) {
	int pid;
	
	if(!PyArg_ParseTuple(args, "l", &pid))
		return NULL;
	
	return Py_False;
}

#endif