/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/OLEAUT32/OLEAUT32.h>

#define NUMODULE_NAME "OLEAUT32"

WINAPI LPCSTR *SysAllocStringLen(LPCSTR *str, UINT len) {
	LPCSTR *ret;
	
	NuWarn("SysAllocStringLen not yet implemented");
	
	ret = NuMemory_Alloc(len + 1);

	if(str) {
		memcpy(ret, str, len);
		ret[len] = 0;
	} else {
		memset(ret, 0, len + 1);
	}
	
	return ret;
}

WINAPI VOID SysFreeString(
  LPCSTR *bstr
) {
	NuWarn("SysFreeString not yet implemented");
	
	NuMemory_Free(bstr);
}