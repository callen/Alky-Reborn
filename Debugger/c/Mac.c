/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifdef __APPLE__

#include <Python.h>

#include <signal.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <sys/wait.h>

#include <mach/mach_types.h>
#include <mach/i386/thread_status.h>

#include <Carbon/Carbon.h>

extern int single_stepping;

PyObject *
Alky_TraceByCommandLine(PyObject *self, PyObject *args) {
	const char *app;	
	int pid;
	
	if(!PyArg_ParseTuple(args, "s", &app))
		return NULL;
	
	switch(pid = fork()) {
		case -1:
			return Py_False;
		case 0:
			ptrace(PT_TRACE_ME, 0, 0, 0);
			
			execl(app, NULL);
			
			exit(0);
			
			break;
		default:
			return Py_BuildValue("l", pid);
	}
	
	return Py_True;
}

PyObject *
Alky_SingleStep(PyObject *self, PyObject *args) {
	int pid, waiter = 0;
	
	if(!PyArg_ParseTuple(args, "l", &pid))
		return NULL;
	
	single_stepping = 1;
	
	//while((waiter & 0xFF00) != (SIGTRAP << 8))
	waitpid(pid, &waiter, 0);
	
	if(ptrace(PT_STEP, pid, 1, 0) != 0)
		return Py_False;
	
	return Py_True;
}

PyObject *Alky_Continue(PyObject *self, PyObject *args) {
	int pid, waiter = 0;
	
	if(!PyArg_ParseTuple(args, "l", &pid))
		return NULL;
	
	//while((waiter & 0xFF00) != (SIGTRAP << 8))
	waitpid(pid, &waiter, 0);
	
	if(ptrace(PT_CONTINUE, pid, 1, 0) != 0)
		return Py_False;
	
	return Py_True;
}

PyObject *
Alky_GetRegisters(PyObject *self, PyObject *args) {
	pid_t pid;
	task_t port;
	
	thread_act_port_array_t thread_list;
	mach_msg_type_number_t thread_count;
	
	i386_thread_state_t x86_state;
	mach_msg_type_number_t sc = i386_THREAD_STATE_COUNT;
	long thread;
	
	if(!PyArg_ParseTuple(args, "l", &pid))
		return NULL;
	
	if(task_for_pid(mach_task_self(), pid, &port))
		return NULL;
	
	if(!single_stepping && task_suspend(port))
		return NULL;
	
	if(task_threads(port, &thread_list, &thread_count))
		return NULL;
		
	memset(&x86_state, 0, sizeof(i386_thread_state_t));
	
	thread = 0;
	if(thread_get_state(
		thread_list[thread],
		i386_THREAD_STATE,
		(thread_state_t) &x86_state,
		&sc
	)) {
		if(!single_stepping)
			task_resume(port);
		return Py_False;
	}
	
	if(!single_stepping && task_resume(port))
		return NULL;

	return Py_BuildValue(
		"{s:I,s:I,s:I,s:I,s:I,s:I,s:I,s:I,s:I,s:I,s:I,s:I,s:I,s:I,s:I,s:I}",
		"eax", x86_state.__eax,
		"ebx", x86_state.__ebx,
		"ecx", x86_state.__ecx,
		"edx", x86_state.__edx,
		"edi", x86_state.__edi,
		"esi", x86_state.__esi,
		"ebp", x86_state.__ebp,
		"esp", x86_state.__esp,

		"ss", x86_state.__ss,
		"eflags", x86_state.__eflags,
		"eip", x86_state.__eip,

		"cs", x86_state.__cs,
		"ds", x86_state.__ds,
		"es", x86_state.__es,
		"fs", x86_state.__fs,
		"gs", x86_state.__gs
	);
}

PyObject *Alky_Resume(PyObject *self, PyObject *args) {
	pid_t pid;
	task_t port;
	
	if(!PyArg_ParseTuple(args, "l", &pid))
		return NULL;
	
	if(task_for_pid(mach_task_self(), pid, &port))
		return NULL;
	
	if(task_resume(port))
		return NULL;
	
	return Py_True;
}

PyObject *Alky_Suspend(PyObject *self, PyObject *args) {
	pid_t pid;
	task_t port;
	
	if(!PyArg_ParseTuple(args, "l", &pid))
		return NULL;
	
	if(task_for_pid(mach_task_self(), pid, &port))
		return NULL;
	
	if(task_suspend(port))
		return NULL;
	
	return Py_True;
}

PyObject *Alky_Detach(PyObject *self, PyObject *args) {
	int pid, waiter = 0;
	
	if(!PyArg_ParseTuple(args, "l", &pid))
		return NULL;
	
	//while((waiter & 0xFF00) != (SIGTRAP << 8))
	waitpid(pid, &waiter, 0);
	
	if(ptrace(PT_DETACH, pid, 0, 0) != 0)
		return Py_False;
	
	waitpid(pid, &waiter, 0);
	
	return Py_True;
}

PyObject *
Alky_PeekMemory(PyObject *self, PyObject *args) {
	pid_t pid;
	task_t port;
	void *addr;
	int count;
	int out_count;
	
	void *data;
	
	PyObject *out;
	
	if(!PyArg_ParseTuple(args, "lIl", &pid, &addr, &count))
		return NULL;
	
	if(task_for_pid(mach_task_self(), pid, &port))
		return Py_False;
	
	if(!single_stepping && task_suspend(port))
		return Py_False;
	
	if(vm_read(port, addr, count, &data, &out_count))
		return Py_False;
	
	if(!single_stepping && task_resume(port))
		return Py_False;
	
	out = Py_BuildValue("s#", data, out_count);
	
	vm_deallocate(mach_task_self(), data, out_count);
	
	return out;
}

PyObject *
Alky_PokeMemory(PyObject *self, PyObject *args) {
	pid_t pid;
	task_t port;
	void *addr;
	int count;	
	void *data;
	//void *vm_data = NULL;
	
	if(!PyArg_ParseTuple(args, "lIs#", &pid, &addr, &data, &count))
		return NULL;
	
	if(task_for_pid(mach_task_self(), pid, &port))
		return Py_False;
	
	if(!single_stepping && task_suspend(port))
		return Py_False;
	
	if(vm_write(port, addr, data, count))
		return Py_False;
	
	return Py_True;
}

#endif