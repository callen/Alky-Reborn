/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/Kernel32/Kernel32.h>

#define NUMODULE_NAME "Kernel32"

WINAPI HANDLE CreateWaitableTimerA(
  LPSECURITY_ATTRIBUTES lpTimerAttributes,
  BOOL bManualReset,
  LPCSTR lpTimerName
) {
	NuWarn("CreateWaitableTimerA not yet implemented");
	
	return NuEvent_CreateTimer(0);
}

WINAPI BOOL SetWaitableTimer(
  HANDLE hTimer,
  const LARGE_INTEGER* pDueTime,
  LONG lPeriod,
  PTIMERAPCROUTINE pfnCompletionRoutine,
  LPVOID lpArgToCompletionRoutine,
  BOOL fResume
) {
	NuWarn("SetWaitableTimer not yet implemented");
	
	return True;
}