/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/D3D/D3D.h>
#include <APIs/Windows/DirectX/D3D/D3D_Classes.h>

#define NUMODULE_NAME "D3D"

WINAPI HRESULT IDirect3DVertexBuffer9_Release(
    void *this_
) {
	return S_OK;
}

WINAPI HRESULT IDirect3DVertexBuffer9_Lock(
	void *this_,
	UINT OffsetToLock,
	UINT SizeToLock,
	void** ppbData,
	DWORD Flags
) {
	CSTRUCT(IDirect3DVertexBuffer9) *_Context = GET_CLASS_STRUCT(IDirect3DVertexBuffer9, this_);
	
	NuWarn("IDirect3DVertexBuffer9::Lock not yet implemented");
	
	*ppbData = _Context->vertexBuffer;
	
	return S_OK;
}

WINAPI HRESULT IDirect3DVertexBuffer9_Unlock(
	void *this_
) {
	NuWarn("IDirect3DVertexBuffer9::Unlock not yet implemented");
	
	return S_OK;
}
