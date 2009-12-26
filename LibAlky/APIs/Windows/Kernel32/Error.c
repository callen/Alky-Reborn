/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/Kernel32/Kernel32.h>

#include <Nucleus/Nucleus.h>

#define NUMODULE_NAME "Kernel32"

WINAPI DWORD GetLastError(void) {
	Kernel32 *_Context = Kernel32_GetContext();
	
	return _Context->lastError;
}

WINAPI void SetLastError(DWORD error) {
	Kernel32 *_Context = Kernel32_GetContext();
	
	_Context->lastError = error;
}

DWORD Kernel32_GetLastError(void) {
	Kernel32 *_Context = Kernel32_GetContext();
	
	return _Context->lastError;
}

void Kernel32_SetLastError(DWORD error) {
	Kernel32 *_Context = Kernel32_GetContext();
	
	_Context->lastError = error;
}

WINAPI UINT SetErrorMode(
  UINT uMode
) {
	NuWarn("SetErrorMode not yet implemented");
	
	return uMode;
}
