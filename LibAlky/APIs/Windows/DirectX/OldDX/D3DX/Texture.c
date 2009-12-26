/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/D3DX/D3DX.h>

#define NUMODULE_NAME "D3DX"

bool LoadBMPTexture(
	void *pDevice,
	LPCSTR pSrcFile,
	void **ppTexture
) {
	NuFile *fp;
	
	BMPHeader header;
	BMPInfo info;
	
	void *pSurface;
	
	D3DLOCKED_RECT lockedRect;
	int i, j;
	
	unsigned char color[3];
	
	fp = NuFile_Open(pSrcFile, "rb");
	
	if(fp == None)
		return False;
	
	NuFile_Read(fp, &header, sizeof(BMPHeader));
	NuFile_Read(fp, &info,   sizeof(BMPInfo));
	
	IDirect3DDevice9_CreateTexture(
		pDevice,
		info.width,
		info.height,
		1,
		0,
		D3DFMT_X8R8G8B8,
		None,
		ppTexture,
		None
	);
	
	IDirect3DTexture9_GetSurfaceLevel(
		*ppTexture,
		0,
		&pSurface
	);
	
	IDirect3DSurface9_LockRect(
		pSurface,
		&lockedRect,
		None,
		0
	);
	
	for(i = 0; i < info.width; ++i) {
		for(j = 0; j < info.height; ++j) {
			NuFile_Read(fp, color, 3);
			lockedRect.pBits[0] = color[2];
			lockedRect.pBits[1] = color[1];
			lockedRect.pBits[2] = color[0];
			lockedRect.pBits[3] = 0xFF;
			
			lockedRect.pBits += 4;
		}
	}
	
	IDirect3DSurface9_UnlockRect(
		pSurface
	);
	
	NuFile_Close(fp);
	
	return True;
}

WINAPI HRESULT D3DXCreateTextureFromFileA(
	void *pDevice,
	LPCSTR pSrcFile,
	void **ppTexture
) {
	NuLog("D3DXCreateTextureFromFileA");
	
	if(strcmp(pSrcFile + strlen(pSrcFile) - 4, ".bmp") == 0) {
		if(LoadBMPTexture(pDevice, pSrcFile, ppTexture))
			return S_OK;
		else
			return -1;
	} else {
		NuError("Extension %s not yet supported", pSrcFile + strlen(pSrcFile) - 3);
	}
	
	return S_OK;
}
