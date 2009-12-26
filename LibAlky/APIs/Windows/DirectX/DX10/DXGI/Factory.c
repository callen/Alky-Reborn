/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/DX10/DXGI/DXGI.h>
#include <APIs/Windows/DirectX/DX10/DXGI/DXGI_Classes.h>

#define NUMODULE_NAME "DXGI10"

WINAPI HRESULT CreateDXGIFactory(
  REFIID riid,
  void **ppFactory /* IDGXIFactory */
) {
	SETUP_VTABLE(DXGI10);
	
	NuLog("CreateDXGIFactory");
	
	if(ppFactory != NULL)
		INIT_CLASS(IDXGIFactory, *ppFactory);
	
	return S_OK;
}

WINAPI HRESULT IDXGIFactory_EnumAdapters(
	/* IDXGIFactory */ void * this_, 
	UINT Adapter, 
	/* IDXGIAdapter */ void **ppAdapter
) {
	NuLog("IDXGIFactory::EnumAdapters");
	
	if(Adapter > 0)
		return DXGI_ERROR_NOT_FOUND;
	
	if(ppAdapter != NULL)
		INIT_CLASS(IDXGIAdapter, *ppAdapter);
	
	return S_OK;
}

WINAPI HRESULT IDXGIFactory_MakeWindowAssociation(
	/* IDXGIFactory */ void * this_, 
	HWND WindowHandle, 
	UINT Flags
) {
	NuWarn("IDXGIFactory::MakeWindowAssociation not yet implemented");
	
	return S_OK;
}

WINAPI HRESULT IDXGIFactory_CreateSwapChain(
	/* IDXGIFactory */ void * this_, 
	/* IUnknown */ void *pDevice, 
	DXGI_SWAP_CHAIN_DESC *pDesc, 
	/* IDXGISwapChain */ void **ppSwapChain
) {
	NuLog("IDXGIFactory::CreateSwapChain");
	
	return DXGI_CreateSwapChain(pDevice, pDesc, ppSwapChain);
}
