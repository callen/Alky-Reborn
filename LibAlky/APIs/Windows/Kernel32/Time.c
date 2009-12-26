/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/Kernel32/Kernel32.h>

#define NUMODULE_NAME "Kernel32"

WINAPI DWORD GetTickCount(void) {
	NuWarn("GetTickCount not yet implemented");
	
	return NuGUI_GetTicks() / 1000;
}

WINAPI void GetSystemTimeAsFileTime(
  LPFILETIME lpSystemTimeAsFileTime
) {
	NuWarn("GetSystemTimeAsFile not yet implemented");
	
	memset(lpSystemTimeAsFileTime, 0xDE, sizeof(FILETIME));
}

WINAPI BOOL QueryPerformanceCounter(
    LARGE_INTEGER *lpPerformanceCount
) {
	// NuWarn("QueryPerformanceCounter not yet implemented");
	
	return True;
}

WINAPI BOOL QueryPerformanceFrequency(
    LARGE_INTEGER *lpFrequency
) {
	NuWarn("QueryPerformanceFrequency not yet implemented");
	
	return True;
}

WINAPI DWORD GetTimeZoneInformation(
  LPTIME_ZONE_INFORMATION lpTimeZoneInformation
) {
	NuWarn("GetTimeZoneInformation not yet implemented");
	
	memset(lpTimeZoneInformation, 0, sizeof(LPTIME_ZONE_INFORMATION));
	
	return 0;
}

WINAPI BOOL FileTimeToLocalFileTime(
  const FILETIME* lpFileTime,
  LPFILETIME lpLocalFileTime
) {
	NuWarn("FileTimeToLocalFileTime not yet implemented");
	
	memcpy(lpLocalFileTime, lpFileTime, sizeof(FILETIME));
	
	return True;
}

WINAPI BOOL FileTimeToSystemTime(
  const FILETIME* lpFileTime,
  LPSYSTEMTIME lpSystemTime
) {
	NuWarn("FileTimeToSystemTime not yet implemented");
	
	return False;
}
