/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __APIS_WINDOWS_OLE32_OLE32_H__
#define __APIS_WINDOWS_OLE32_OLE32_H__

#include <APIs/Windows/Windows.h>

enum RET {
	S_OK = 0,
	S_FALSE = 1
};

WINAPI HRESULT CoInitialize(
  LPVOID pvReserved
);

WINAPI void CoUninitialize();

WINAPI BOOL CoCreateInstance(
	REFCLSID rclsid,
	LPUNKNOWN pUnkOuter,
	DWORD dwClsContext,
	REFIID riid,
	LPVOID *ppv
);

#endif
