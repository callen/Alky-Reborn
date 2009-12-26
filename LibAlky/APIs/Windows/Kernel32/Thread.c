/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/Kernel32/Kernel32.h>

#include <stdio.h>

#define NUMODULE_NAME "Kernel32"

typedef struct thread_wrap_data_s {
	WINAPI void (*func)(void *user_data);
	void *user_data;
	NuMutex *mutex;
} thread_wrap_data;

void thread_wrapper(thread_wrap_data *thr) {
	WINAPI void (*func)(void *) = thr->func;
	void *user_data = thr->user_data;
	
	NuLog("Starting Windows thread at %p", func);
	
	WinCore_SetupFS();
	
	NuMutex_Unlock(thr->mutex);
	
#ifdef LINUX
	WinCore_ReplaceStackAndRun(func, user_data, True);
#else
	func(user_data);
#endif
}

WINAPI HANDLE CreateThread(
  LPSECURITY_ATTRIBUTES lpThreadAttributes,
  SIZE_T dwStackSize,
  LPTHREAD_START_ROUTINE lpStartAddress,
  LPVOID lpParameter,
  DWORD dwCreationFlags,
  LPDWORD lpThreadId
) {
	void *id;
	
	thread_wrap_data *thr;
	
	thr = NuMemory_Alloc(sizeof(thread_wrap_data));
	thr->func = lpStartAddress;
	thr->user_data = lpParameter;
	thr->mutex = NuMutex_Create();
	NuMutex_Lock(thr->mutex);
	
	NuLog("CreateThread %p (thread_wrapper:%p)", lpStartAddress, thread_wrapper);
	
	id = NuThread_Start(thread_wrapper, thr);
	
	NuMutex_Lock(thr->mutex);
	NuMutex_Unlock(thr->mutex);
	NuMutex_Destroy(thr->mutex);
	
	NuMemory_Free(thr);
	
	if(lpThreadId) {
	 	*lpThreadId = id;
	}
	
	return id;
}

WINAPI DWORD ResumeThread(HANDLE hThread) {
	NuWarn("ResumeThread not yet implemented");
	
	return 0;
}

WINAPI BOOL SetThreadPriority(
  HANDLE hThread,
  int nPriority
) {
	NuWarn("SetThreadPriority not yet implemented");
	
	return True;
}
