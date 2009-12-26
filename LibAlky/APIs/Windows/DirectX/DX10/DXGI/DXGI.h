/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __API_WINDOWS_DIRECTX_DXTEN_DXGI_DXGI_H__
#define __API_WINDOWS_DIRECTX_DXTEN_DXGI_DXGI_H__

#ifndef __API_WINDOWS_DIRECTX_DXTEN_DTHREED_DTHREED_H__
#define __API_WINDOWS_DIRECTX_DXTEN_DTHREED_DTHREED_H__
#define CHEAP_HACK
#endif

#include <APIs/Windows/DirectX/DX10/DXGI/DXGI_Types.h>
#include <APIs/Windows/Windows.h>
#include <APIs/Windows/COM/COM.h>

/* IDXGIAdapter Methods */
WINAPI HRESULT IDXGIAdapter_QueryInterface(/* IDXGIAdapter */ void * this_, REFIID riid, void **ppvObject);
WINAPI ULONG IDXGIAdapter_AddRef(/* IDXGIAdapter */ void * this_);
WINAPI ULONG IDXGIAdapter_Release(/* IDXGIAdapter */ void * this_);
WINAPI HRESULT IDXGIAdapter_SetPrivateData(/* IDXGIAdapter */ void * this_, REFGUID Name, UINT DataSize, const void *pData);
WINAPI HRESULT IDXGIAdapter_SetPrivateDataInterface(/* IDXGIAdapter */ void * this_, REFGUID Name, const /* IUnknown */ void *pUnknown);
WINAPI HRESULT IDXGIAdapter_GetPrivateData(/* IDXGIAdapter */ void * this_, REFGUID Name, UINT *pDataSize, void *pData);
WINAPI HRESULT IDXGIAdapter_GetParent(/* IDXGIAdapter */ void * this_, REFIID riid, void **ppParent);
WINAPI HRESULT IDXGIAdapter_EnumOutputs(/* IDXGIAdapter */ void * this_, UINT Output, /* IDXGIOutput */ void **ppOutput);
WINAPI HRESULT IDXGIAdapter_GetDesc(/* IDXGIAdapter */ void * this_, DXGI_ADAPTER_DESC *pDesc);
WINAPI HRESULT IDXGIAdapter_CheckInterfaceSupport(/* IDXGIAdapter */ void * this_, REFGUID InterfaceName, LARGE_INTEGER *pUMDVersion);

/* IDXGIFactory Methods */

WINAPI HRESULT CreateDXGIFactory(
  REFIID riid,
  void **ppFactory /* IDGXIFactory */
);

WINAPI HRESULT IDXGIFactory_QueryInterface(/* IDXGIFactory */ void * this_, REFIID riid, void **ppvObject);
WINAPI ULONG IDXGIFactory_AddRef(/* IDXGIFactory */ void * this_);
WINAPI ULONG IDXGIFactory_Release(/* IDXGIFactory */ void * this_);
WINAPI HRESULT IDXGIFactory_SetPrivateData(/* IDXGIFactory */ void * this_, REFGUID Name, UINT DataSize, const void *pData);
WINAPI HRESULT IDXGIFactory_SetPrivateDataInterface(/* IDXGIFactory */ void * this_, REFGUID Name, const /* IUnknown */ void *pUnknown);
WINAPI HRESULT IDXGIFactory_GetPrivateData(/* IDXGIFactory */ void * this_, REFGUID Name, UINT *pDataSize, void *pData);
WINAPI HRESULT IDXGIFactory_GetParent(/* IDXGIFactory */ void * this_, REFIID riid, void **ppParent);
WINAPI HRESULT IDXGIFactory_EnumAdapters(/* IDXGIFactory */ void * this_, UINT Adapter, /* IDXGIAdapter */ void **ppAdapter);
WINAPI HRESULT IDXGIFactory_MakeWindowAssociation(/* IDXGIFactory */ void * this_, HWND WindowHandle, UINT Flags);
WINAPI HRESULT IDXGIFactory_GetWindowAssociation(/* IDXGIFactory */ void * this_, HWND *pWindowHandle);
WINAPI HRESULT IDXGIFactory_CreateSwapChain(/* IDXGIFactory */ void * this_, /* IUnknown */ void *pDevice, DXGI_SWAP_CHAIN_DESC *pDesc, /* IDXGISwapChain */ void **ppSwapChain);
WINAPI HRESULT IDXGIFactory_CreateSoftwareAdapter(/* IDXGIFactory */ void * this_, HMODULE Module, /* IDXGIAdapter */ void **ppAdapter);

/*IDXGIOutput Methods */
WINAPI HRESULT IDXGIOutput_QueryInterface(/* IDXGIOutput */ void * this_, REFIID riid, void **ppvObject);
WINAPI ULONG IDXGIOutput_AddRef(/* IDXGIOutput */ void * this_);
WINAPI ULONG IDXGIOutput_Release(/* IDXGIOutput */ void * this_);
WINAPI HRESULT IDXGIOutput_SetPrivateData(/* IDXGIOutput */ void * this_, REFGUID Name, UINT DataSize, const void *pData);
WINAPI HRESULT IDXGIOutput_SetPrivateDataInterface(/* IDXGIOutput */ void * this_, REFGUID Name, const /* IUnknown */ void *pUnknown);
WINAPI HRESULT IDXGIOutput_GetPrivateData(/* IDXGIOutput */ void * this_, REFGUID Name, UINT *pDataSize, void *pData);
WINAPI HRESULT IDXGIOutput_GetParent(/* IDXGIOutput */ void * this_, REFIID riid, void **ppParent);
WINAPI HRESULT IDXGIOutput_GetDesc(/* IDXGIOutput */ void * this_, DXGI_OUTPUT_DESC *pDesc);
WINAPI HRESULT IDXGIOutput_GetDisplayModeList(/* IDXGIOutput */ void * this_, DXGI_FORMAT EnumFormat, UINT Flags, UINT *pNumModes, DXGI_MODE_DESC *pDesc);
WINAPI HRESULT IDXGIOutput_FindClosestMatchingMode(/* IDXGIOutput */ void * this_, const DXGI_MODE_DESC *pModeToMatch, DXGI_MODE_DESC *pClosestMatch, /* IUnknown */ void *pConcernedDevice);
WINAPI HRESULT IDXGIOutput_WaitForVBlank(/* IDXGIOutput */ void * this_);
WINAPI HRESULT IDXGIOutput_TakeOwnership(/* IDXGIOutput */ void * this_, /* IUnknown */ void *pDevice, BOOL Exclusive);
WINAPI void IDXGIOutput_ReleaseOwnership(/* IDXGIOutput */ void * this_);
WINAPI HRESULT IDXGIOutput_GetGammaControlCapabilities(/* IDXGIOutput */ void * this_, DXGI_GAMMA_CONTROL_CAPABILITIES *pGammaCaps);
WINAPI HRESULT IDXGIOutput_SetGammaControl(/* IDXGIOutput */ void * this_, const DXGI_GAMMA_CONTROL *pArray);
WINAPI HRESULT IDXGIOutput_GetGammaControl(/* IDXGIOutput */ void * this_, DXGI_GAMMA_CONTROL *pArray);
WINAPI HRESULT IDXGIOutput_SetDisplaySurface(/* IDXGIOutput */ void * this_, /* IDXGISurface */ void *pScanoutSurface);
WINAPI HRESULT IDXGIOutput_GetDisplaySurfaceData(/* IDXGIOutput */ void * this_, /* IDXGISurface */ void *pDestination);
WINAPI HRESULT IDXGIOutput_GetFrameStatistics(/* IDXGIOutput */ void * this_, DXGI_FRAME_STATISTICS *pStats);

/* IDXGISwapChain Methods */

WINAPI HRESULT DXGI_CreateSwapChain(
	void *pDevice, /* ID3D10Device */
	DXGI_SWAP_CHAIN_DESC *pDesc,
	void **ppSwapChain /* IDXGISwapChain */
);

WINAPI HRESULT IDXGISwapChain_QueryInterface(/* IDXGISwapChain */ void * this_, REFIID riid, void **ppvObject);
WINAPI ULONG IDXGISwapChain_AddRef(/* IDXGISwapChain */ void * this_);
WINAPI ULONG IDXGISwapChain_Release(/* IDXGISwapChain */ void * this_);
WINAPI HRESULT IDXGISwapChain_SetPrivateData(/* IDXGISwapChain */ void * this_, REFGUID Name, UINT DataSize, const void *pData);
WINAPI HRESULT IDXGISwapChain_SetPrivateDataInterface(/* IDXGISwapChain */ void * this_, REFGUID Name, const /* IUnknown */ void *pUnknown);
WINAPI HRESULT IDXGISwapChain_GetPrivateData(/* IDXGISwapChain */ void * this_, REFGUID Name, UINT *pDataSize, void *pData);
WINAPI HRESULT IDXGISwapChain_GetParent(/* IDXGISwapChain */ void * this_, REFIID riid, void **ppParent);
WINAPI HRESULT IDXGISwapChain_GetDevice(/* IDXGISwapChain */ void * this_, REFIID riid, void **ppDevice);
WINAPI HRESULT IDXGISwapChain_Present(/* IDXGISwapChain */ void * this_, UINT SyncInterval, UINT Flags);
WINAPI HRESULT IDXGISwapChain_GetBuffer(/* IDXGISwapChain */ void * this_, UINT Buffer, REFIID riid, void **ppSurface);
WINAPI HRESULT IDXGISwapChain_SetFullscreenState(/* IDXGISwapChain */ void * this_, BOOL Fullscreen, /* IDXGIOutput */ void *pTarget);
WINAPI HRESULT IDXGISwapChain_GetFullscreenState(/* IDXGISwapChain */ void * this_, BOOL *pFullscreen, /* IDXGIOutput */ void **ppTarget);
WINAPI HRESULT IDXGISwapChain_GetDesc(/* IDXGISwapChain */ void * this_, DXGI_SWAP_CHAIN_DESC *pDesc);
WINAPI HRESULT IDXGISwapChain_ResizeBuffers(/* IDXGISwapChain */ void * this_, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags);
WINAPI HRESULT IDXGISwapChain_ResizeTarget(/* IDXGISwapChain */ void * this_, const DXGI_MODE_DESC *pNewTargetParameters);
WINAPI HRESULT IDXGISwapChain_GetContainingOutput(/* IDXGISwapChain */ void * this_, /* IDXGIOutput */ void **ppOutput);
WINAPI HRESULT IDXGISwapChain_GetFrameStatistics(/* IDXGISwapChain */ void * this_, DXGI_FRAME_STATISTICS *pStats);
WINAPI HRESULT IDXGISwapChain_GetLastPresentCount(/* IDXGISwapChain */ void * this_, UINT *pLastPresentCount);

#define DXGI_USAGE_SHADER_INPUT             ( 1L << (0 + 4) )
#define DXGI_USAGE_RENDER_TARGET_OUTPUT     ( 1L << (1 + 4) )
#define DXGI_USAGE_BACK_BUFFER              ( 1L << (2 + 4) )
#define DXGI_USAGE_SHARED                   ( 1L << (3 + 4) )
#define DXGI_USAGE_READ_ONLY                ( 1L << (4 + 4) )

#define _FACDXGI    0x87a
#define MAKE_DXGI_HRESULT( code )    MAKE_HRESULT( 1, _FACDXGI, code )
#define MAKE_DXGI_STATUS( code )    MAKE_HRESULT( 0, _FACDXGI, code )
#define DXGI_STATUS_OCCLUDED                MAKE_DXGI_STATUS(1 )
#define DXGI_STATUS_CLIPPED                 MAKE_DXGI_STATUS(2 )
#define DXGI_STATUS_NO_REDIRECTION          MAKE_DXGI_STATUS(4 )
#define DXGI_STATUS_NO_DESKTOP_ACCESS       MAKE_DXGI_STATUS(5 )
#define DXGI_STATUS_GRAPHICS_VIDPN_SOURCE_IN_USE       MAKE_DXGI_STATUS(6 )
#define DXGI_STATUS_MODE_CHANGED            MAKE_DXGI_STATUS(7 )
#define DXGI_ERROR_INVALID_CALL    MAKE_DXGI_HRESULT( 1 )
#define DXGI_ERROR_NOT_FOUND    MAKE_DXGI_HRESULT( 2 )
#define DXGI_ERROR_MORE_DATA    MAKE_DXGI_HRESULT( 3 )
#define DXGI_ERROR_UNSUPPORTED    MAKE_DXGI_HRESULT( 4 )
#define DXGI_ERROR_DEVICE_REMOVED    MAKE_DXGI_HRESULT( 5 )
#define DXGI_ERROR_DEVICE_HUNG    MAKE_DXGI_HRESULT( 6 )
#define DXGI_ERROR_DEVICE_RESET    MAKE_DXGI_HRESULT( 7 )
#define DXGI_ERROR_WAS_STILL_DRAWING    MAKE_DXGI_HRESULT( 10 )
#define DXGI_ERROR_FRAME_STATISTICS_DISJOINT MAKE_DXGI_HRESULT( 11 )
#define DXGI_ERROR_DRIVER_INTERNAL_ERROR    MAKE_DXGI_HRESULT( 32 )
#define DXGI_ERROR_NONEXCLUSIVE    MAKE_DXGI_HRESULT( 33 )

#ifdef CHEAP_HACK
#undef __API_WINDOWS_DIRECTX_DXTEN_DTHREED_DTHREED_H__
#undef CHEAP_HACK
#endif

#endif
