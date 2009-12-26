/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/DX10/D3DX/D3DX.h>
#include <APIs/Windows/DirectX/DX10/D3DX/D3DX_Classes.h>

#define NUMODULE_NAME "D3DX10"


WINAPI HRESULT D3DX10CreateEffectFromFileA(
	LPCSTR pFileName, 
	CONST D3D10_SHADER_MACRO *pDefines, 
 	/* ID3D10Include */ void *pInclude,
	LPCSTR pProfile, 
	UINT HLSLFlags, 
	UINT FXFlags, 
	/* ID3D10Device */ void *pDevice,
	/* ID3D10EffectPool */ void *pEffectPool,
	/* ID3DX10ThreadPump */ void *pPump,
	/* ID3D10Effect */ void **ppEffect,
	/* ID3D10Blob */ void **ppErrors,
	HRESULT* pHResult
) {
	NuWarn("D3DX10CreateEffectFromFileA not yet implemented");
	
	NuLog("Filename: %s", pFileName);
	
	if(ppEffect) {
		*ppEffect = D3D10_CreateEffect(pDevice);
	}
	
	return S_OK;
}

WINAPI HRESULT D3DX10CreateEffectFromFileW(
	LPWSTR pFileName, 
	CONST D3D10_SHADER_MACRO *pDefines, 
 	/* ID3D10Include */ void *pInclude,
	LPCSTR pProfile, 
	UINT HLSLFlags, 
	UINT FXFlags, 
	/* ID3D10Device */ void *pDevice,
	/* ID3D10EffectPool */ void *pEffectPool,
	/* ID3DX10ThreadPump */ void *pPump,
	/* ID3D10Effect */ void **ppEffect,
	/* ID3D10Blob */ void **ppErrors,
	HRESULT* pHResult
) {
	NuWarn("D3DX10CreateEffectFromFileW not yet implemented");
	
	if(ppEffect) {
		*ppEffect = D3D10_CreateEffect(pDevice);
	}
	
	return S_OK;
}

WINAPI HRESULT D3DX10CreateEffectFromMemory(
	LPCVOID pData, 
	SIZE_T DataLength, 
	LPCSTR pSrcFileName, 
	CONST D3D10_SHADER_MACRO *pDefines, 
	/* ID3D10Include */ void *pInclude,
	LPCSTR pProfile, 
	UINT HLSLFlags, 
	UINT FXFlags, 
	/* ID3D10Device */ void *pDevice,
	/* ID3D10EffectPool */ void *pEffectPool,
	/* ID3DX10ThreadPump */ void *pPump,
	/* ID3D10Effect */ void **ppEffect,
	/* ID3D10Blob */ void **ppErrors,
	HRESULT* pHResult
) {
	NuWarn("D3DX10CreateEffectFromMemory not yet implemented");
	
	if(ppEffect) {
		*ppEffect = D3D10_CreateEffect(pDevice);
	}
	
	if(pHResult)
		*pHResult = S_OK;
	
	return S_OK;
}
