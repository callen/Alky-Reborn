/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
 */

#ifndef __API_WINDOWS_DIRECTX_DXTEN_DXGI_DXGI_CLASSES_H__
#define __API_WINDOWS_DIRECTX_DXTEN_DXGI_DXGI_CLASSES_H__

#include <APIs/Windows/Windows.h>
#include <APIs/Windows/COM/COM.h>

CLASS(
	IDXGIAdapter,
	STRUCT(),
	VTABLE(
		CSTUB(IDXGIAdapter_QueryInterface),
		CSTUB(IDXGIAdapter_AddRef),
		CSTUB(IDXGIAdapter_Release),
		CSTUB(IDXGIAdapter_SetPrivateData),
		CSTUB(IDXGIAdapter_SetPrivateDataInterface),
		CSTUB(IDXGIAdapter_GetPrivateData),
		CSTUB(IDXGIAdapter_GetParent),
		CMEMBER(IDXGIAdapter_EnumOutputs),
		CMEMBER(IDXGIAdapter_GetDesc),
		CSTUB(IDXGIAdapter_CheckInterfaceSupport)
	)
);

CLASS(
	IDXGIFactory,
	STRUCT(),
	VTABLE(
		CSTUB(IDXGIFactory_QueryInterface),
		CSTUB(IDXGIFactory_AddRef),
		CSTUB(IDXGIFactory_Release),
		CSTUB(IDXGIFactory_SetPrivateData),
		CSTUB(IDXGIFactory_SetPrivateDataInterface),
		CSTUB(IDXGIFactory_GetPrivateData),
		CSTUB(IDXGIFactory_GetParent),
		CMEMBER(IDXGIFactory_EnumAdapters),
		CMEMBER(IDXGIFactory_MakeWindowAssociation),
		CSTUB(IDXGIFactory_GetWindowAssociation),
		CMEMBER(IDXGIFactory_CreateSwapChain),
		CSTUB(IDXGIFactory_CreateSoftwareAdapter)
	)
);

CLASS(
	IDXGIOutput,
	STRUCT(),
	VTABLE(
		CSTUB(IDXGIOutput_QueryInterface),
		CSTUB(IDXGIOutput_AddRef),
		CMEMBER(IDXGIOutput_Release),
		CSTUB(IDXGIOutput_SetPrivateData),
		CSTUB(IDXGIOutput_SetPrivateDataInterface),
		CSTUB(IDXGIOutput_GetPrivateData),
		CSTUB(IDXGIOutput_GetParent),
		CMEMBER(IDXGIOutput_GetDesc),
		CMEMBER(IDXGIOutput_GetDisplayModeList),
		CSTUB(IDXGIOutput_FindClosestMatchingMode),
		CSTUB(IDXGIOutput_WaitForVBlank),
		CSTUB(IDXGIOutput_TakeOwnership),
		CSTUB(IDXGIOutput_ReleaseOwnership),
		CSTUB(IDXGIOutput_GetGammaControlCapabilities),
		CSTUB(IDXGIOutput_SetGammaControl),
		CSTUB(IDXGIOutput_GetGammaControl),
		CSTUB(IDXGIOutput_SetDisplaySurface),
		CSTUB(IDXGIOutput_GetDisplaySurfaceData),
		CSTUB(IDXGIOutput_GetFrameStatistics)
	)
);

CLASS(
	IDXGISwapChain,
	STRUCT(
		DXGI_SWAP_CHAIN_DESC desc;
		void *device;
		void *buffer;
		HWND window;
	),
	VTABLE(
		CSTUB(IDXGISwapChain_QueryInterface),
		CSTUB(IDXGISwapChain_AddRef),
		CMEMBER(IDXGISwapChain_Release),
		CSTUB(IDXGISwapChain_SetPrivateData),
		CSTUB(IDXGISwapChain_SetPrivateDataInterface),
		CSTUB(IDXGISwapChain_GetPrivateData),
		CSTUB(IDXGISwapChain_GetParent),
		CSTUB(IDXGISwapChain_GetDevice),
		CMEMBER(IDXGISwapChain_Present),
		CMEMBER(IDXGISwapChain_GetBuffer),
		CSTUB(IDXGISwapChain_SetFullscreenState),
		CSTUB(IDXGISwapChain_GetFullscreenState),
		CSTUB(IDXGISwapChain_GetDesc),
		CSTUB(IDXGISwapChain_ResizeBuffers),
		CSTUB(IDXGISwapChain_ResizeTarget),
		CSTUB(IDXGISwapChain_GetContainingOutput),
		CSTUB(IDXGISwapChain_GetFrameStatistics),
		CSTUB(IDXGISwapChain_GetLastPresentCount)
	)
);

#endif
