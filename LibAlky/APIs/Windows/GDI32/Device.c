/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/GDI32/GDI32.h>

#define NUMODULE_NAME "GDI32"

WINAPI HDC CreateCompatibleDC(
  HDC hdc
) {
	NuWarn("CreateCompatibleDC not yet implemented");

	return 0xDEADBEEF;
}

WINAPI BOOL DeleteDC(
  HDC hdc
) {
	NuWarn("DeleteDC not yet implemented");

	return True;
}

WINAPI int GetDeviceCaps(
  HDC hdc,
  int nIndex
) {
	NuWarn("GetDeviceCaps not yet implemented");

	return 0;
}

WINAPI BOOL GetDeviceGammaRamp(
  HDC hDC,
  LPVOID lpRamp
) {
	NuWarn("GetDeviceGammaRamp not yet implemented");

	return False;
}

WINAPI BOOL SetDeviceGammaRamp(
  HDC hDC,
  LPVOID lpRamp
) {
	NuWarn("SetDeviceGammaRamp not yet implemented");

	return True;
}

WINAPI HDC CreateICA(
  LPCSTR lpszDriver,
  LPCSTR lpszDevice,
  LPCSTR lpszOutput,
  CONST DEVMODE *lpdvmInit
) {
	NuWarn("CreateIC not yet implemented");
	
	return 0xDEADBEEF;
}
