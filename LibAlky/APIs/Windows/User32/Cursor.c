/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/User32/User32.h>

#define NUMODULE_NAME "User32"

WINAPI HCURSOR LoadCursorA(
    HINSTANCE hInstance,
    LPCSTR lpCursorName
) {
	NuWarn("LoadCursorA not yet implemented");
	
	return None;
}

WINAPI HCURSOR SetCursor(
    HCURSOR hCursor
) {
	NuWarn("SetCursor not yet implemented");
	
	return hCursor;
}

WINAPI int ShowCursor_(
    BOOL bShow
) {
	NuWarn("ShowCursor not yet implemented");
	
	return 42;
}