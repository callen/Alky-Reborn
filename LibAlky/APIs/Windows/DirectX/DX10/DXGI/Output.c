/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/DX10/DXGI/DXGI.h>
#include <APIs/Windows/DirectX/DX10/DXGI/DXGI_Classes.h>

#define NUMODULE_NAME "DXGI10"

WINAPI ULONG IDXGIOutput_Release(
	/* IDXGIOutput */ void * this_
) {
	NuWarn("IDXGIOutput::Release not yet implemented");
	
	return S_OK;
}

WINAPI HRESULT IDXGIOutput_GetDesc(
	/* IDXGIOutput */ void * this_, 
	DXGI_OUTPUT_DESC *pDesc
) {
	NuWarn("IDXGIOutput::GetDesc not yet implemented");
	
	memset(pDesc, 0, sizeof(DXGI_OUTPUT_DESC));
	wcscpy(pDesc->DeviceName, L"Alky D3D10 Device");
	pDesc->DesktopCoordinates.left = 0;
	pDesc->DesktopCoordinates.right = 640;
	pDesc->DesktopCoordinates.top = 0;
	pDesc->DesktopCoordinates.bottom = 480;
	
	return S_OK;
}

WINAPI HRESULT IDXGIOutput_GetDisplayModeList(
	/* IDXGIOutput */ void * this_, 
	DXGI_FORMAT EnumFormat, 
	UINT Flags, 
	UINT *pNumModes, 
	DXGI_MODE_DESC *pDesc
) {
	NuWarn("IDXGIOutput::GetDisplayModeList not yet implemented");
	
	if(pDesc != NULL) {
		pDesc->Width = 640;
		pDesc->Height = 480;
		pDesc->RefreshRate.Numerator = 60;
		pDesc->RefreshRate.Denominator = 1;
		pDesc->Format = DXGI_FORMAT_R8G8B8A8_UNORM; // EnumFormat;
	}
	
	*pNumModes = 1;
	
	return S_OK;
}
