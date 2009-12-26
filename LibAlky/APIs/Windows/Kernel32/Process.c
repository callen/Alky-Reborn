/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/Kernel32/Kernel32.h>

#define NUMODULE_NAME "Kernel32"

WINAPI DWORD GetCurrentProcessId() {
	return NuProcess_ProcessID();
}

WINAPI DWORD GetCurrentThreadId() {
	return NuProcess_ProcessID();
}

WINAPI HANDLE GetCurrentThread(void) {
	NuWarn("GetCurrentThread not yet implemented");
	
	return 0xDEADBEEF;
}

WINAPI HANDLE GetCurrentProcess(void) {
	NuWarn("GetCurrentProcess not yet implemented");
	
	return 0xDEADBEEF;
}

WINAPI BOOL SetProcessWorkingSetSize(
  HANDLE hProcess,
  SIZE_T dwMinimumWorkingSetSize,
  SIZE_T dwMaximumWorkingSetSize
) {
	NuWarn("SetProcessWorkingSetSize not yet implemented");
	
	return True;
}

WINAPI BOOL GetProcessAffinityMask(
  HANDLE hProcess,
  PDWORD_PTR lpProcessAffinityMask,
  PDWORD_PTR lpSystemAffinityMask
) {
	NuWarn("GetProcessAffinityMask not yet implemented");

	*lpProcessAffinityMask = 1;
	*lpSystemAffinityMask = 1;
	
	return True;
}

WINAPI BOOL SetProcessAffinityMask(
  HANDLE hProcess,
  DWORD_PTR dwProcessAffinityMask
) {
	NuWarn("SetProcessAffinityMask not yet implemented");
	
	return True;
}
