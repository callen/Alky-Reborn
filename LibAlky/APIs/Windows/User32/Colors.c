/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/User32/User32.h>

#define NUMODULE_NAME "User32"

WINAPI DWORD GetSysColor(
  int nIndex
) {
	NuWarn("GetSysColor not yet implemented");
	
	return 0xFFFFFF;
}

WINAPI HBRUSH GetSysColorBrush(
  int nIndex
) {
	NuWarn("GetSysColorBrush not yet implemented");
	
	return None;
}
