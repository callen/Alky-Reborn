/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/User32/User32.h>

#define NUMODULE_NAME "User32"

WINAPI HDC GetDC(
  HWND hWnd
) {
	NuWarn("GetDC not yet implemented");
	
	return hWnd;
}

WINAPI int ReleaseDC(
  HWND hWnd,
  HDC hDC
) {
	NuWarn("ReleaseDC not yet implemented");

	return True;
}

WINAPI BOOL EnumDisplaySettingsA(
  LPCSTR lpszDeviceName,
  DWORD iModeNum,
  LPDEVMODE lpDevMode
) {
	NuWarn("EnumDisplaySettingsA not yet implemented");
	
	NuAssert(lpDevMode != None);
	
	if(iModeNum > 10)
		return False;
	
	lpDevMode->dmBitsPerPel = 32;
	lpDevMode->dmPelsWidth = 1024;
	lpDevMode->dmPelsHeight = 768;
	lpDevMode->dmDisplayFlags = 0;
	lpDevMode->dmDisplayFrequency = 60;
	
	return True;
}

WINAPI LONG ChangeDisplaySettingsA(
  LPDEVMODE lpDevMode,
  DWORD dwflags
) {
	NuWarn("ChangeDisplaySettingsA not yet implemented");
	
	return DISP_CHANGE_SUCCESSFUL;
}
