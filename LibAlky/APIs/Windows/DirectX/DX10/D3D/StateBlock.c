/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/DX10/D3D/D3D.h>
#include <APIs/Windows/DirectX/DX10/D3D/D3D_Classes.h>

#define NUMODULE_NAME "D3D10"

WINAPI HRESULT D3D10CreateStateBlock(
  /* ID3D10Device */ void *pDevice,
  D3D10_STATE_BLOCK_MASK *pStateBlockMask,
  /* ID3D10StateBlock */ void **ppStateBlock
) {
	if(ppStateBlock) {
		SETUP_VTABLE(D3D10);
		INIT_CLASS(ID3D10StateBlock, *ppStateBlock);
	}
	
	return S_OK;
}

WINAPI HRESULT ID3D10StateBlock_QueryInterface(
	/* ID3D10StateBlock */ void *this, 
	REFIID iid, 
	LPVOID **ppvObject
) {
	NuWarn("ID3D10StateBlock::QueryInterface not yet implemented");
	
	*ppvObject = this;
	
	return S_OK;
}

WINAPI HRESULT ID3D10StateBlock_Capture(/* ID3D10StateBlock */ void *this) {
	NuWarn("ID3D10StateBlock::Capture not yet implemented");
	
	return S_OK;
}

WINAPI HRESULT ID3D10StateBlock_Apply(/* ID3D10StateBlock */ void *this) {
	NuWarn("ID3D10StateBlock::Apply not yet implemented");
	
	return S_OK;
}
