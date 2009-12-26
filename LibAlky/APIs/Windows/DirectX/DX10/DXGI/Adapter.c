/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/DX10/DXGI/DXGI.h>
#include <APIs/Windows/DirectX/DX10/DXGI/DXGI_Classes.h>

#define NUMODULE_NAME "DXGI10"

WINAPI HRESULT IDXGIAdapter_GetDesc(
	/* IDXGIAdapter */ void * this_, 
	DXGI_ADAPTER_DESC *pDesc
) {
	NuWarn("IDXGIAdapter::GetDesc not yet implemented");
	
	wcscpy(pDesc->Description, L"Alky D3D10 Compatible Card");
	pDesc->DedicatedVideoMemory = 512*1024*1024;
	pDesc->DedicatedSystemMemory = 2*1024*1024*1024;
	pDesc->SharedSystemMemory = 512*1024*1024;
	
	return S_OK;
}

WINAPI HRESULT IDXGIAdapter_EnumOutputs(
	/* IDXGIAdapter */ void * this_, 
	UINT Output, 
	/* IDXGIOutput */ void **ppOutput
) {
	NuWarn("IDXGIAdapter::EnumOutputs not yet implemented");
	
	if(Output > 0)
		return DXGI_ERROR_NOT_FOUND;
	
	if(ppOutput != NULL)
		INIT_CLASS(IDXGIOutput, *ppOutput);
	
	return S_OK;
}
