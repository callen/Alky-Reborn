/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/D3D/D3D.h>
#include <APIs/Windows/DirectX/D3D/D3D_Classes.h>

#define NUMODULE_NAME "D3D"

WINAPI HRESULT IDirect3DResource9_Release(
    void *this_
) {
	NuWarn("IDirect3DResource9::Release not yet implemented");
	
	return S_OK;
}

WINAPI D3DRESOURCETYPE IDirect3DResource9_GetType(
    void *this_
) {
	CSTRUCT(IDirect3DResource9) *_Context;
	
	NuLog("IDirect3DResource9::GetType");
	
	_Context = GET_CLASS_STRUCT(IDirect3DResource9, this_);
	
	return _Context->Type;
}
