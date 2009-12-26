/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <Python.h>

int single_stepping = 0;

PyObject *
Alky_TraceByCommandLine(PyObject *self, PyObject *args);

PyObject *
Alky_SingleStep(PyObject *self, PyObject *args);

PyObject *
Alky_Continue(PyObject *self, PyObject *args);

PyObject *
Alky_Resume(PyObject *self, PyObject *args);

PyObject *
Alky_Suspend(PyObject *self, PyObject *args);

PyObject *
Alky_Detach(PyObject *self, PyObject *args);

PyObject *
Alky_GetRegisters(PyObject *self, PyObject *args);

PyObject *
Alky_PeekMemory(PyObject *self, PyObject *args);

PyObject *
Alky_PokeMemory(PyObject *self, PyObject *args);

static PyMethodDef AlkyDebugMethods[] = {
	{"traceByCommandLine", Alky_TraceByCommandLine, METH_VARARGS,
	 "Creates trace from command line"},
	{"singleStep", Alky_SingleStep, METH_VARARGS,
	 "Single steps through an application"},
	{"cont", Alky_Continue, METH_VARARGS,
	 "Continues an application"},
	{"resume", Alky_Resume, METH_VARARGS,
	 "Resumes an application"},
	{"suspend", Alky_Suspend, METH_VARARGS,
	 "Suspends an application"},
	{"detach", Alky_Detach, METH_VARARGS,
	 "Detaches from an application"},
	{"getRegisters", Alky_GetRegisters, METH_VARARGS,
	 "Gets registers from an application"},
	{"peekMemory", Alky_PeekMemory, METH_VARARGS,
	 "Peeks at the memory of an application"},
	{"pokeMemory", Alky_PokeMemory, METH_VARARGS,
	 "Pokes at the memory of an application"},
	{NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC initalkydebug_c(void) {
	(void) Py_InitModule("alkydebug_c", AlkyDebugMethods);
}
