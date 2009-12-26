/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/User32/User32.h>

#define NUMODULE_NAME "User32"

NuContext_Singleton(User32_GetContext, User32, NUMODULE_NAME);

WINAPI int MessageBoxA(
    void *hWnd,
    char *lpText,
    char *lpCaption,
    int uType
) {
	NuLog("Message box");
	NuLog("Text: `%s'", lpText);
	NuLog("Caption: `%s'", lpCaption);
	
	return IDNO;
}

WINAPI BOOL GetCursorPos(
    LPPOINT lpPoint
) {
	NuWarn("GetCursorPos not yet implemented");
	
	lpPoint->x = lpPoint->y = 0;
	
	return None;
}

WINAPI int GetSystemMetrics(
  int nIndex
) {
	NuWarn("GetSystemMetrics not yet implemented");
	
	return 0xDEADBEEF;
}

WINAPI BOOL GetUserObjectInformationA(
  HANDLE hObj,
  int nIndex,
  PVOID pvInfo,
  DWORD nLength,
  LPDWORD lpnLengthNeeded
) {
	NuWarn("GetUserObjectInformationA not yet implemented");
	
	return False;
}

WINAPI HWINSTA GetProcessWindowStation(void) {
	NuWarn("GetProcessWindowStation not yet implemented");
	
	return 0xDEADBEEF;
}

WINAPI UINT_PTR SetTimer(
    HWND hWnd,
    UINT_PTR nIDEvent,
    UINT uElapse,
    TIMERPROC lpTimerFunc
) {
	NuWarn("SetTimer not yet implemented");
	
	if(hWnd == None)
		return 0xDEADBEEF;
	else
		return True;
}

WINAPI UINT GetDoubleClickTime() {
	NuWarn("GetDoubleClickTime not yet implemented");
	
	return 250;
}
