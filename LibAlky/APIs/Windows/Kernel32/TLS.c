/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/Kernel32/Kernel32.h>

#include <Nucleus/Nucleus.h>

#define NUMODULE_NAME "Kernel32"

WINAPI DWORD TlsAlloc(void) {
	NuLog("TlsAlloc");
	return NuMemory_TLSAlloc();
}

WINAPI LPVOID TlsGetValue(DWORD dwTlsIndex) {
	void *val = NuMemory_TLSGet(dwTlsIndex);
	
	return val;
}

WINAPI BOOL TlsSetValue(DWORD dwTlsIndex, LPVOID value) {
	return NuMemory_TLSSet(dwTlsIndex, value);
}

WINAPI BOOL TlsFree(DWORD dwTlsIndex) {
	NuWarn("TlsFree not yet implemented");

	return True;
}

WINAPI DWORD FlsAlloc(void *callback) {
	NuWarn("FLS subsystem currently tied to TLS");
	
	return NuMemory_TLSAlloc();
}

WINAPI LPVOID FlsGetValue(DWORD dwTlsIndex) {
	void *val = NuMemory_TLSGet(dwTlsIndex);
	
	return val;
}

WINAPI BOOL FlsSetValue(DWORD dwTlsIndex, LPVOID value) {
	return NuMemory_TLSSet(dwTlsIndex, value);
}

WINAPI BOOL FlsFree(DWORD dwTlsIndex) {
	NuWarn("FlsFree not yet implemented");
	
	return True;
}