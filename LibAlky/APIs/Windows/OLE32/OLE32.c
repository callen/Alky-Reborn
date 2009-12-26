/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/OLE32/OLE32.h>
#include <APIs/Windows/COM/COM.h>

#define NUMODULE_NAME "OLE32"

WINAPI HRESULT CoInitialize(
  LPVOID pvReserved
) {
	NuLog("CoInitialize does nothing");
	
	return True;
}

WINAPI void CoUninitialize() {
	NuLog("CoUninitialize does nothing");
}

WINAPI BOOL CoCreateInstance(
	REFCLSID rclsid,
	LPUNKNOWN pUnkOuter,
	DWORD dwClsContext,
	REFIID riid,
	LPVOID *ppv
) {
	void **foo;
	
	NuWarn("CoCreateInstance not yet implemented");
	
	NuLog(
		"CLSID Requested: {%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}",
		rclsid->Data1,
		rclsid->Data2,
		rclsid->Data3,
		rclsid->Data4[0],
		rclsid->Data4[1],
		
		rclsid->Data4[2],
		rclsid->Data4[3],
		rclsid->Data4[4],
		rclsid->Data4[5],
		rclsid->Data4[6],
		rclsid->Data4[7]
	);
	
	if(ppv)
		*ppv = None;
	
	return 1;
}
