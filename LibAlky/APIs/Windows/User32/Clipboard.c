/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/Kernel32/Kernel32.h>

#define NUMODULE_NAME "Kernel32"

WINAPI UINT RegisterClipboardFormatA(
    LPCSTR lpszFormat
) {
	NuWarn("RegisterClipboardFormatA not yet implemented");
	
	return 0xDEADBEEF;
}

WINAPI BOOL OpenClipboard(
    HWND hWndNewOwner
) {
	NuWarn("OpenClipboard not yet implemented");
	
	return True;
}

WINAPI BOOL CloseClipboard() {
	NuWarn("CloseClipboard not yet implemented");
	
	return True;
}

WINAPI BOOL EmptyClipboard() {
	NuWarn("EmptyClipboard not yet implemented");
	
	return True;
}

WINAPI HANDLE SetClipboardData(
    UINT uFormat,
    HANDLE hMem
) {
	NuWarn("SetClipboardData not yet implemented");
	
	return hMem;
}
