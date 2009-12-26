/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/D3D/D3D.h>
#include <APIs/Windows/DirectX/D3D/D3D_Classes.h>

#define NUMODULE_NAME "D3D"

WINAPI HRESULT IDirect3DCubeTexture9_Init(
    void *this_,
    UINT EdgeLength,
    UINT Levels,
    D3DFORMAT Format
) {
	CSTRUCT(IDirect3DCubeTexture9) *_Texture;
	int thisEdge;
	
	int i, j, surface = 0;
	
	NuLog("IDirect3DCubeTexture9::Init");
	
	_Texture = GET_CLASS_STRUCT(IDirect3DCubeTexture9, this_);
	
	if(Levels == 0) {
		thisEdge = EdgeLength;
		
		while(thisEdge > 1) {
			Levels++;
			thisEdge >>= 1;
		}
	}
	
	_Texture->Resource.Type = D3DRTYPE_CUBETEXTURE;
	
	_Texture->EdgeLength = EdgeLength;
	_Texture->Levels = Levels;
	_Texture->Format = Format;
	
	thisEdge = EdgeLength;
	
	NuLog("Creating cube texture of %i levels: %i", Levels, EdgeLength);
	
	_Texture->surfaces = NuMemory_Alloc(sizeof(void *) * Levels * 6);
	
	for(i = 0; i < Levels; ++i) {
		for(j = 0; j < 6; ++j) {
			INIT_CLASS(IDirect3DSurface9, _Texture->surfaces[surface]);
			
			IDirect3DSurface9_Init(
				_Texture->surfaces[surface],
				thisEdge,
				thisEdge,
				Format
			);
			
			surface++;
		}
		
		thisEdge >>= 1;
	}
}

WINAPI HRESULT IDirect3DCubeTexture9_Release(
    void *this_
) {
	NuWarn("IDirect3DCubeTexture9::Release not yet implemented");
	
	return S_OK;
}

WINAPI HRESULT IDirect3DCubeTexture9_GetCubeMapSurface(
    void *this_,
    D3DCUBEMAP_FACES FaceType,
    UINT Level,
    void **ppCubeMapSurface
) {
	CSTRUCT(IDirect3DCubeTexture9) *_Texture;
	
	NuLog("IDirect3DCubeTexture9::GetCubeMapSurface");
	
	_Texture = GET_CLASS_STRUCT(IDirect3DCubeTexture9, this_);
	
	Level = (Level << 2) + (Level << 1); // Level * 6
	
	*ppCubeMapSurface = _Texture->surfaces[Level + FaceType];
	
	return S_OK;
}
