/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/DX10/D3DX/D3DX.h>
#include <APIs/Windows/DirectX/DX10/D3DX/D3DX_Classes.h>

#define NUMODULE_NAME "D3DX10"

WINAPI HRESULT D3DX10CreateTextureFromFileA(
  /* ID3D10Device */ void *pDevice,
  LPSTR pSrcFile,
  D3DX10_IMAGE_LOAD_INFO *pLoadInfo,
  /* ID3DX10ThreadPump */ void *pPump,
  /* ID3D10Resource */ void **ppTexture,
  HRESULT*                    pHResult
) {
	NuWarn("D3DX10CreateTextureFromFileA not yet implemented");
	
	if(ppTexture) *ppTexture = None;
	
	return S_OK;
}

WINAPI HRESULT D3DX10CreateTextureFromFileW(
  /* ID3D10Device */ void *pDevice,
  LPWSTR pSrcFile,
  D3DX10_IMAGE_LOAD_INFO *pLoadInfo,
  /* ID3DX10ThreadPump */ void *pPump,
  /* ID3D10Resource */ void **ppTexture,
  HRESULT*                    pHResult
) {
	NuWarn("D3DX10CreateTextureFromFileW not yet implemented");
	
	if(ppTexture) *ppTexture = None;
	
	return S_OK;
}

WINAPI HRESULT D3DX10CreateTextureFromMemory(
  /* ID3D10Device */ void *pDevice,
  LPCVOID pSrcData,
  SIZE_T SrcDataSize,
  D3DX10_IMAGE_LOAD_INFO *pLoadInfo,
  /* ID3DX10ThreadPump */ void *pPump,
  /* ID3D10Resource */ void **ppTexture,
  HRESULT*                    pHResult
) {
	DDS *dds;
	
	NuLog("D3DX10CreateTextureFromMemory");
	
	if(ppTexture) {
		dds = DDS_Read(pSrcData, SrcDataSize);
		*ppTexture = D3D10_CreateTexture2DFromDDS(dds);
		DDS_Free(dds);
	}

	return S_OK;
}

WINAPI HRESULT D3DX10CreateTextureFromResourceW(
  /* ID3D10Device */ void *pDevice,
  HMODULE hSrcModule,
  LPCWSTR pSrcResource,
  D3DX10_IMAGE_LOAD_INFO *pLoadInfo,
  /* ID3DX10ThreadPump */ void *pPump,
  /* ID3D10Resource */ void **ppTexture,
  HRESULT*                    pHResult
) {
	NuWarn("D3DX10CreateTextureFromResourceW not yet implemented");

	if(ppTexture) *ppTexture = None;
	
	return S_OK;
}
