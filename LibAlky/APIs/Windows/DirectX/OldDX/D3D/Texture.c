/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/D3D/D3D.h>
#include <APIs/Windows/DirectX/D3D/D3D_Classes.h>

#define NUMODULE_NAME "D3D"

WINAPI HRESULT IDirect3DTexture9_Init(
	void *this_,
	UINT Width,
	UINT Height,
	UINT Levels,
	D3DFORMAT Format
) {
	CSTRUCT(IDirect3DTexture9) *_Texture;
	UINT thisWidth, thisHeight;
	
	int i;
	
	NuLog("IDirect3DTexture9::Init(%p)", this_);
	
	_Texture = GET_CLASS_STRUCT(IDirect3DTexture9, this_);
	
	_Texture->Resource.Type = D3DRTYPE_TEXTURE;
	
	_Texture->Width = Width;
	_Texture->Height = Height;
	_Texture->Levels = Levels;
	_Texture->Format = Format;
	
	NuLog("Creating texture of %i levels: %ix%i", Levels, Width, Height);
	
	_Texture->surfaces = NuMemory_Alloc(sizeof(void *) * Levels);
	
	thisWidth = Width;
	thisHeight = Height;
	
	for(i = 0; i < Levels; ++i) {
		INIT_CLASS(IDirect3DSurface9, _Texture->surfaces[i]);
		
		IDirect3DSurface9_Init(
			_Texture->surfaces[i],
			thisWidth,
			thisHeight,
			Format
		);
		
		thisWidth >>= 1;
		thisHeight >>= 1;
	}
}

WINAPI HRESULT IDirect3DTexture9_Release(
    void *this_
) {
	NuWarn("IDirect3DTexture9::Release not yet implemented");
	
	return S_OK;
}

WINAPI DWORD IDirect3DTexture9_GetLOD(
    void *this_
) {
	NuWarn("IDirect3DTexture9::GetLOD not yet implemented");
	
	return 5;
}

WINAPI D3DRESOURCETYPE IDirect3DTexture9_GetType(
    void *this_
) {
	CSTRUCT(IDirect3DTexture9) *_Context;

	NuLog("IDirect3DTexture9::GetType");
	
	_Context = GET_CLASS_STRUCT(IDirect3DTexture9, this_);
	
	return _Context->Resource.Type;
}

WINAPI HRESULT IDirect3DTexture9_GetSurfaceLevel(
    void *this_,
    UINT Level,
    void **ppSurfaceLevel
) {
	CSTRUCT(IDirect3DTexture9) *_Context;
	
	NuLog("IDirect3DTexture9::GetSurfaceLevel");
	
	_Context = GET_CLASS_STRUCT(IDirect3DTexture9, this_);
	
	*ppSurfaceLevel = _Context->surfaces[Level];
	
	return S_OK;
}
