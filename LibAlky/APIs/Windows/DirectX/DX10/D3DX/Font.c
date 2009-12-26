/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/DX10/D3DX/D3DX.h>
#include <APIs/Windows/DirectX/DX10/D3DX/D3DX_Classes.h>

#define NUMODULE_NAME "D3DX10"

WINAPI HRESULT D3DX10CreateFontA(
  /* ID3D10Device */ void *pDevice,
  INT Height,
  UINT Width,
  UINT Weight,
  UINT MipLevels,
  BOOL Italic,
  UINT CharSet,
  UINT OutputPrecision,
  UINT Quality,
  UINT PitchAndFamily,
  LPCSTR pFaceName,
  /* ID3DX10FONT */ void **ppFont
) {
	NuWarn("D3DX10CreateFontA not yet implemented");
	
	if(ppFont != None) {
		SETUP_VTABLE(D3DX10);
		INIT_CLASS(ID3DX10Font, *ppFont);
	}
	
	return S_OK;
}

WINAPI HRESULT D3DX10CreateFontW(
  /* ID3D10Device */ void *pDevice,
  INT Height,
  UINT Width,
  UINT Weight,
  UINT MipLevels,
  BOOL Italic,
  UINT CharSet,
  UINT OutputPrecision,
  UINT Quality,
  UINT PitchAndFamily,
  LPCWSTR pFaceName,
  /* ID3DX10FONT */ void **ppFont
) {
	NuWarn("D3DX10CreateFontW not yet implemented");
	
	if(ppFont != None) {
		SETUP_VTABLE(D3DX10);
		INIT_CLASS(ID3DX10Font, *ppFont);
	}
	
	return S_OK;
}

WINAPI INT ID3DX10Font_DrawTextW(
	/* ID3DX10Font */ void *this, 
	/* ID3DX10SPRITE */ void *pSprite, 
	LPCWSTR pString, 
	INT Count, 
	LPRECT pRect, 
	UINT Format, 
	D3DXCOLOR Color
) {
	NuWarn("ID3DX10Font::DrawTextW not yet implemented");
	
	return 25;
}
