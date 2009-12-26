/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/D3D/D3D.h>
#include <APIs/Windows/DirectX/D3D/D3D_Classes.h>

#define NUMODULE_NAME "D3D"

WINAPI HRESULT IDirect3DSurface9_Init(
	void *this_,
	UINT Width,
	UINT Height,
	D3DFORMAT Format
) {
	CSTRUCT(IDirect3DSurface9) *_Surface;
	int i;
	
	NuLog("IDirect3DSurface9::Init(%p)", this_);
	
	_Surface = GET_CLASS_STRUCT(IDirect3DSurface9, this_);
	
	_Surface->Width = Width;
	_Surface->Height = Height;
	_Surface->Format = Format;
	
	_Surface->pBits = NuMemory_Alloc(Width * Height * 4);
	
	glGenTextures(1, &_Surface->glTexture);
	
	return S_OK;
}

WINAPI HRESULT IDirect3DSurface9_Release(
    void *this_
) {
	NuWarn("IDirect3DSurface9::Release not yet implemented");
	
	return S_OK;
}

WINAPI HRESULT IDirect3DSurface9_GetDesc(
    void *this_,
    D3DSURFACE_DESC *pDesc
) {
	CSTRUCT(IDirect3DSurface9) *_Context;
	
	NuWarn("IDirect3DSurface9::GetDesc not yet implemented");
	
	_Context = GET_CLASS_STRUCT(IDirect3DSurface9, this_);

	pDesc->Format = _Context->Format;
	
	pDesc->Width = _Context->Width;
	pDesc->Height = _Context->Height;
	
	return S_OK;
}

WINAPI HRESULT IDirect3DSurface9_LockRect(
    void *this_,
    D3DLOCKED_RECT *pLockedRect,
    CONST RECT *pRect,
    DWORD Flags
) {
	CSTRUCT(IDirect3DSurface9) *_Surface;
	
	INT Pitch;
	
	NuLog("IDirect3DSurface9::LockRect");
	
	_Surface = GET_CLASS_STRUCT(IDirect3DSurface9, this_);
	
	if(pRect != None) {
		NuError("Non-NULL pRects are not supported");
	}
	
	switch(_Surface->Format) {
		case D3DFMT_DXT1:
		case D3DFMT_DXT2:
		case D3DFMT_DXT3:
		case D3DFMT_DXT4:
		case D3DFMT_DXT5:
			Pitch = _Surface->Width >> 2;
			break;
		default:
			Pitch = _Surface->Width << 2;
			break;
	}
	
	pLockedRect->Pitch = Pitch;
	pLockedRect->pBits = _Surface->pBits;
	
	return S_OK;
}

WINAPI HRESULT IDirect3DSurface9_UnlockRect(
    void *this_
) {
	CSTRUCT(IDirect3DSurface9) *_Surface;
	
	NuLog("IDirect3DSurface9::UnlockRect");
	
	_Surface = GET_CLASS_STRUCT(IDirect3DSurface9, this_);
	
	glBindTexture(GL_TEXTURE_2D, _Surface->glTexture);
	
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	
	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		GL_RGBA,
		_Surface->Width,
		_Surface->Height,
		0,
		GL_RGBA,
		GL_UNSIGNED_BYTE,
		_Surface->pBits
	);
	
	return S_OK;
}
