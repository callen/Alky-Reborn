/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/DX10/D3DX/D3DX.h>
#include <APIs/Windows/DirectX/DX10/D3DX/D3DX_Classes.h>

#define NUMODULE_NAME "D3DX10"

WINAPI HRESULT D3DX10CreateSprite(
  /* ID3D10Device */ void *pDevice,
  UINT cDeviceBufferSize,
  /* ID3DX10Sprite */ void **ppSprite
) {
	NuWarn("D3DX10CreateSprite not yet implemented");
	
	if(ppSprite) {
		SETUP_VTABLE(D3DX10);
		INIT_CLASS(ID3DX10Sprite, *ppSprite);
	}
	
	return S_OK;
}

WINAPI HRESULT ID3DX10Sprite_Begin(
	/* ID3DX10Sprite */ void *this, 
	UINT flags
) {
	NuWarn("ID3DX10Sprite::Begin not yet implemented");
	
	return S_OK;
}

WINAPI HRESULT ID3DX10Sprite_DrawSpritesBuffered(
	/* ID3DX10Sprite */ void *this, 
	D3DX10_SPRITE *pSprites, 
	UINT cSprites
) {
	NuWarn("ID3DX10Sprite::DrawSpritesBuffered not yet implemented");
	
	return S_OK;
}

WINAPI HRESULT ID3DX10Sprite_End(/* ID3DX10Sprite */ void *this) {
	NuWarn("ID3DX10Sprite::End not yet implemented");
	
	return S_OK;
}

WINAPI HRESULT ID3DX10Sprite_SetProjectionTransform(
	/* ID3DX10Sprite */ void *this, 
	D3DXMATRIX *pProjectionTransform
) {
	NuWarn("ID3DX10Sprite::SetProjectionTransform not yet implemented");
	
	return S_OK;
}

WINAPI HRESULT ID3DX10Sprite_GetDevice(
	/* ID3DX10Sprite */ void *this, 
	/* ID3D10Device */ void ** ppDevice
) {
	CSTRUCT(ID3DX10Sprite) *Sprite = GET_CLASS_STRUCT(ID3DX10Sprite, this);
	
	if(ppDevice != None)
		*ppDevice = Sprite->device;
	
	return S_OK;
}
