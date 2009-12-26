/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/D3DX/D3DX.h>
#include <APIs/Windows/DirectX/D3DX/D3DX_Classes.h>

#define NUMODULE_NAME "D3DX"

WINAPI HRESULT D3DXCompileShader(
	LPCSTR pSrcData,
	UINT srcDataLen,
	CONST D3DXMACRO *pDefines,
	LPD3DXINCLUDE pInclude,
	LPCSTR pFunctionName,
	LPCSTR pProfile,
	DWORD Flags,
	LPD3DXBUFFER *ppShader,
	LPD3DXBUFFER *ppErrorMsgs,
	LPD3DXCONSTANTTABLE *ppConstantTable
) {
	NuWarn("D3DXCompileShader not yet implemented");
	
	NuLog("%s %s", pFunctionName, pProfile);
	NuLog("%s", pSrcData);
	
	if(ppShader != None) {
		INIT_CLASS(ID3DXBuffer, *ppShader);
		ID3DXBuffer_Init(
			*ppShader,
			6,
			"test?"
		);
	}
	
	if(ppErrorMsgs != None) {
		INIT_CLASS(ID3DXBuffer, *ppErrorMsgs);
		ID3DXBuffer_Init(
			*ppErrorMsgs,
			13,
			"No errors..."
		);
	}
	
	if(ppConstantTable != None) {
		INIT_CLASS(ID3DXConstantTable, *ppConstantTable);
	}
	
	return S_OK;
}
