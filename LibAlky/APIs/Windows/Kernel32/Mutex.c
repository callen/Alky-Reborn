/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/Kernel32/Kernel32.h>

#include <Nucleus/Nucleus.h>

#define NUMODULE_NAME "Kernel32"

WINAPI void InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection) {
	NuWarn("InitializeCriticalSection not yet implemented");
}

WINAPI void DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection) {
	NuWarn("DeleteCriticalSection not yet implemented");
}

WINAPI void TryEnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection) {
	// NuWarn("TryEnterCriticalSection not yet implemented");
}

WINAPI void EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection) {
	// NuWarn("EnterCriticalSection not yet implemented");
}

WINAPI void LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection) {
	// NuWarn("LeaveCriticalSection not yet implemented");
}

WINAPI LONG InterlockedDecrement(LONG volatile* Addend) {
	*Addend--;
	
	return *Addend;
}

WINAPI LONG InterlockedIncrement(LONG volatile* Addend) {
	*Addend++;
	
	return *Addend;
}

WINAPI LONG InterlockedExchange(LPLONG Target, LONG Value) {
	LONG old = *Target;
	
	NuWarn("InterlockedExchange not yet implemented");
	
	*Target = Value;
	
	return old;
}

WINAPI HANDLE CreateMutexA(
  LPSECURITY_ATTRIBUTES lpMutexAttributes,
  BOOL bInitialOwner,
  LPCSTR lpName
) {
	NuWarn("CreateMutexA not yet implemented");
	
	return None;
}

WINAPI HANDLE CreateSemaphoreA(
  LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
  LONG lInitialCount,
  LONG lMaximumCount,
  LPCSTR lpName
) {
	NuWarn("CreateSemaphoreA not yet implemented");
	
	return None;
}

WINAPI BOOL ReleaseSemaphore(
	HANDLE hSemaphore,
	LONG lReleaseCount,
	LPLONG lpPreviousCount
) {
	// NuWarn("ReleaseSemaphore not yet implemented");
	
	return True;
}
