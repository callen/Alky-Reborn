/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/COM/COM.h>

#define NUMODULE_NAME "COM"

WINAPI HRESULT IUnknown_QueryInterface(
    void *this_
) {
	NuWarn("IUnknown::QueryInterface not yet implemented");
	
	return S_OK;
}
