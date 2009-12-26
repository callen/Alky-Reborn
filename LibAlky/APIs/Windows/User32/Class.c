/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/User32/User32.h>
#include <string.h>

#define NUMODULE_NAME "User32"

WINAPI ATOM RegisterClassA(
    CONST WNDCLASSA *lpWndClass
) {
	NuGUI *_Context;
	NuGUI_WindowClass wndclass;

	wndclass.className = strdup(lpWndClass->lpszClassName);
	wndclass.callback = lpWndClass->lpfnWndProc;

	NuLog("RegisterClass(`%s')", lpWndClass->lpszClassName);
	
	NuGUI_RegisterClass(&wndclass);

	_Context = NuGUI_GetContext();

	return (ATOM) _Context->wndclassCount;
}

WINAPI ATOM RegisterClassExA(
    CONST WNDCLASSEXA *lpWndClass
) {
	NuGUI *_Context;
	NuGUI_WindowClass wndclass;
	
	wndclass.className = strdup(lpWndClass->lpszClassName);
	wndclass.callback = lpWndClass->lpfnWndProc;
	
	NuGUI_RegisterClass(&wndclass);
	
	_Context = NuGUI_GetContext();
	
	return (ATOM) _Context->wndclassCount;
}

WINAPI BOOL UnregisterClassA(
	LPCSTR lpClassName,
	HINSTANCE hInstance
) {
	NuWarn("UnregisterClassA not yet implemented");
	
	return True;
}

WINAPI DWORD GetClassLongA(
	HWND hWnd,
	int nIndex
) {
	NuWarn("GetClassLongA not yet implemented");
	
	return 0xFFFF;
}

WINAPI DWORD GetWindowLongA(
	HWND hWnd,
	int nIndex
) {
	NuWarn("GetWindowLongA not yet implemented");
	
	return 0xFFFF;
}
