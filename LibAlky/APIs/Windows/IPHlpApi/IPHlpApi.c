/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/IPHlpApi/IPHlpApi.h>

#define NUMODULE_NAME "IPHlpApi"

WINAPI DWORD GetAdaptersInfo(
  PIP_ADAPTER_INFO pAdapterInfo,
  PULONG pOutBufLen
) {
	NuWarn("GetAdaptersInfo not yet implemented");
	
	*pOutBufLen = 0;
	
	if(!pAdapterInfo)
		return ERROR_SUCCESS;
	
	memset(pAdapterInfo, 0, sizeof(IP_ADAPTER_INFO));
	
	return ERROR_SUCCESS;
}