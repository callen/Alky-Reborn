/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/User32/User32.h>

#define NUMODULE_NAME "User32"

WINAPI BOOL AdjustWindowRect( 
  LPRECT lpRect, 
  DWORD dwStyle, 
  BOOL bMenu 
) {
	NuWarn("AdjustWindowRect not yet implemented");

	return True;
}

WINAPI BOOL AdjustWindowRectEx( 
  LPRECT lpRect, 
  DWORD dwStyle, 
  BOOL bMenu, 
  DWORD dwExStyle 
) {
	NuWarn("AdjustWindowRectEx not yet implemented");
	
	return True;
}

WINAPI BOOL GetClientRect(
    HWND hWnd,
    LPRECT lpRect
) {
	NuGUI_Window *window = (NuGUI_Window *) hWnd;
	
	lpRect->left = 0;
	lpRect->right = window->width;
	
	lpRect->top = 0;
	lpRect->bottom = window->height;
	
	return True;
}

WINAPI HWND CreateWindowExA(
	DWORD dwExStyle, 
	LPCSTR lpClassName, 
	LPCSTR lpWindowName, 
	DWORD dwStyle, 
	int x, 
	int y, 
	int nWidth, 
	int nHeight, 
	HWND hWndParent, 
	HMENU hMenu, 
	HINSTANCE hInstance, 
	LPVOID lpParam 
) {
	NuGUI_WindowClass *wndclass;
	
	// Is it a string?
	if((DWORD) lpClassName & 0xFFFF0000) {
		wndclass = NuGUI_ClassByName(lpClassName);
	} else {
		wndclass = NuGUI_ClassById((int) lpClassName);
	}
	
	return NuGUI_OpenWindow(wndclass, nWidth, nHeight);
}

WINAPI BOOL DestroyWindow(
    HWND hWnd
) {
	NuWarn("DestroyWindow not yet implemented");
	
	return True;
}

WINAPI BOOL ShowWindow(
    HWND hWnd,
    int nCmdShow
) {
	NuWarn("ShowWindow not yet implemented");
	
	return True;
}

WINAPI BOOL UpdateWindow(
    HWND hWnd
) {
	NuWarn("UpdateWindow not yet implemented");
	
	return True;
}

WINAPI BOOL CloseWindow(
    HWND hWnd
) {
	NuWarn("CloseWindow not yet implemented");
	
	return True;
}

WINAPI BOOL SetForegroundWindow(
    HWND hWnd
) {
	NuWarn("SetForegroundWindow not yet implemented");
	
	return True;
}

WINAPI HWND GetFocus() {
	return NuGUI_WindowById(0);
}

WINAPI HWND SetFocus(
    HWND hWnd
) {
	NuWarn("SetFocus not yet implemented");
	
	return hWnd;
}

WINAPI HWND GetActiveWindow(VOID) {
	NuWarn("GetActiveWindow not yet implemented");
	
	return NuGUI_WindowById(0);
}

WINAPI HWND GetDesktopWindow(VOID) {
	NuWarn("GetDesktopWindow not yet implemented");
	
	return 0xDEADBEEF;
}

WINAPI HWND GetLastActivePopup(VOID) {
	NuWarn("GetLastActivePopup not yet implemented");
	
	return 0xDEADBEEF;
}

WINAPI LONG SetWindowLongA(
    HWND hWnd,
    int nIndex,
    LONG dwNewLong
) {
	NuWarn("SetWindowLong not yet implemented");
	
	return dwNewLong;
}

WINAPI BOOL SetWindowTextA(
    HWND hWnd,
    LPCSTR lpString
) {
	NuWarn("SetWindowTextA not yet implemented");
	
	NuLog("Window text: %s", lpString);
	
	return True;
}

WINAPI BOOL SetWindowPos(
    HWND hWnd,
    HWND hWndInsertAfter,
    int X,
    int Y,
    int cx,
    int cy,
    UINT uFlags
) {
	NuWarn("SetWindowPos not yet implemented");
	
	return True;
}

WINAPI HWND GetForegroundWindow(VOID) {
	NuWarn("GetForegroundWindow not yet implemented");
	
	return NuGUI_WindowById(0xFFFF);
}

WINAPI HWND FindWindowA(
	LPCSTR lpClassName,
	LPCSTR lpWindowName
) {
	NuWarn("FindWindowA not yet implemented");
	
	NuLog(
		"lpClassName=`%s' lpWindowName=`%s'",
		lpClassName,
		lpWindowName
	);
	
	return None;
}

WINAPI BOOL SwapMouseButton(
	BOOL fSwap
) {
	NuWarn("SwapMouseButton not yet implemented");
	
	return True;
}
