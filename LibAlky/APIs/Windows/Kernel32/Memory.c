/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/Kernel32/Kernel32.h>

#include <Nucleus/Nucleus.h>

#define NUMODULE_NAME "Kernel32"

WINAPI BOOL IsBadReadPtr(
  const VOID* lp,
  UINT_PTR ucb
) {
	NuWarn("IsBadReadPtr not yet implemented");

	return False;
}

WINAPI BOOL IsBadWritePtr(
  const VOID* lp,
  UINT_PTR ucb
) {
	NuWarn("IsBadWritePtr not yet implemented");
	
	return False;
}

WINAPI HANDLE GetProcessHeap(void) {
	static void *heap = None;
	
	if(heap != None)
		return heap;

	heap = NuMemory_HeapCreate(0xFFFFF, 0xFFFFF, 0);
	return heap;
}

WINAPI HANDLE HeapCreate(
  DWORD flOptions,
  SIZE_T dwInitialSize,
  SIZE_T dwMaximumSize
) {
	return NuMemory_HeapCreate(dwInitialSize, dwMaximumSize, 0);
}

WINAPI LPVOID HeapAlloc(
  HANDLE hHeap,
  DWORD dwFlags,
  SIZE_T dwBytes
) {
	return NuMemory_HeapAlloc(hHeap, dwBytes, 0);
}

WINAPI LPVOID HeapReAlloc(
  HANDLE hHeap,
  DWORD dwFlags,
  LPVOID lpMem,
  SIZE_T dwBytes
) {
	return NuMemory_HeapRealloc(hHeap, lpMem, dwBytes, 0);
}

WINAPI BOOL HeapFree(
  HANDLE hHeap,
  DWORD dwFlags,
  LPVOID lpMem
) {
	return NuMemory_HeapFree(hHeap, lpMem, 0);
}

WINAPI SIZE_T HeapSize(
  HANDLE hHeap,
  DWORD dwFlags,
  LPCVOID lpMem
) {
	return NuMemory_HeapSize(hHeap, lpMem, 0);
}

WINAPI BOOL HeapValidate(
  HANDLE hHeap,
  DWORD dwFlags,
  LPCVOID lpMem
) {
	NuWarn("HeapValidate not yet implemented");
	
	return True;
}

WINAPI LPVOID VirtualAlloc(
  LPVOID lpAddress,
  SIZE_T dwSize,
  DWORD flAllocationType,
  DWORD flProtect
) {
	NuWarn("VirtualAlloc does not allocate at requested addresses!");
	
	return NuMemory_Alloc(dwSize);
}

WINAPI HLOCAL LocalAlloc(
  UINT uFlags,
  SIZE_T uBytes
) {
	return NuMemory_Alloc(uBytes);
}

WINAPI LOCAL LocalReAlloc(
  HLOCAL hMem,
  SIZE_T uBytes,
  UINT uFlags
) {
	return NuMemory_Realloc(hMem, uBytes);
}

WINAPI HLOCAL LocalFree(
  HLOCAL hMem
) {
	NuMemory_Free(hMem);
	
	return None;
}

WINAPI HLOCAL GlobalAlloc(
  UINT uFlags,
  SIZE_T uBytes
) {
	return NuMemory_Alloc(uBytes);
}

WINAPI HLOCAL GlobalReAlloc(
  HLOCAL hMem,
  SIZE_T uBytes,
  UINT uFlags
) {
	return NuMemory_Realloc(hMem, uBytes);
}

WINAPI HLOCAL GlobalFree(
  HLOCAL hMem
) {
	NuMemory_Free(hMem);
	
	return None;
}

WINAPI LPVOID GlobalLock(
  HGLOBAL hMem
) {
	NuWarn("GlobalLock not yet implemented");
	
	return hMem;
}

WINAPI LPVOID GlobalUnlock(
  HGLOBAL hMem
) {
	NuWarn("GlobalUnlock not yet implemented");
	
	return hMem;
}

WINAPI PVOID EncodePointer(
  PVOID Ptr
) {
	return (PVOID) ((unsigned int) Ptr ^ 0xDEADBEEF);
}

WINAPI PVOID DecodePointer(
  PVOID Ptr
) {
	return (PVOID) ((unsigned int) Ptr ^ 0xDEADBEEF);
}

WINAPI void GlobalMemoryStatus(
  LPMEMORYSTATUS lpBuffer
) {
	lpBuffer->dwMemoryLoad = 0;
	lpBuffer->dwTotalPhys = lpBuffer->dwAvailPhys = 512*1024*1024; // 512MB
	lpBuffer->dwTotalPageFile = lpBuffer->dwAvailPageFile = 512*1024*1024; // 512MB
	lpBuffer->dwTotalVirtual = lpBuffer->dwAvailVirtual = 512*1024*1024; // 512MB
}

WINAPI BOOL GlobalMemoryStatusEx(
  LPMEMORYSTATUSEX lpBuffer
) {
	NuWarn("GlobalMemoryStatusEx not yet implemented");
	
	GlobalMemoryStatus((LPMEMORYSTATUS) lpBuffer);
	lpBuffer->ullAvailExtendedVirtual = 512*1024*1024; // 512MB
	
	return True;
}

WINAPI BOOL VirtualLock(
  LPVOID lpAddress,
  SIZE_T dwSize
) {
	NuWarn("VirtualLock not yet implemented");
	
	return True;
}

WINAPI BOOL VirtualUnlock(
  LPVOID lpAddress,
  SIZE_T dwSize
) {
	NuWarn("VirtualUnlock not yet implemented");
	
	return True;
}

WINAPI SIZE_T VirtualQuery(
  LPCVOID lpAddress,
  PMEMORY_BASIC_INFORMATION lpBuffer,
  SIZE_T dwLength
) {
	NuWarn("VirtualQuery not yet implemented");
	
	return sizeof(MEMORY_BASIC_INFORMATION);
}
