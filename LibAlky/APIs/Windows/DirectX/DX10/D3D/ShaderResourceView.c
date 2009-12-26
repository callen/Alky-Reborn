/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/DX10/D3D/D3D.h>
#include <APIs/Windows/DirectX/DX10/D3D/D3D_Classes.h>

#define NUMODULE_NAME "D3D10"

WINAPI /* ID3D10ShaderResourceView */ void *D3D10_CreateShaderResourceView() {
	void *ret;
	CSTRUCT(ID3D10ShaderResourceView) *Resource;
	
	INIT_CLASS(ID3D10ShaderResourceView, ret);
	Resource = GET_CLASS_STRUCT(ID3D10ShaderResourceView, ret);
	
	Resource->texture2D = None;
	
	return ret;
}

WINAPI /* ID3D10ShaderResourceView */ void *D3D10_CreateShaderResourceViewFromDDS(
	DDS *dds
) {
	void *ret;
	CSTRUCT(ID3D10ShaderResourceView) *Resource;
	
	NuLog("D3D10_CreateShaderResourceViewFromDDS");
	
	INIT_CLASS(ID3D10ShaderResourceView, ret);
	Resource = GET_CLASS_STRUCT(ID3D10ShaderResourceView, ret);
	
	Resource->texture2D = D3D10_CreateTexture2DFromDDS(dds);
	
	return ret;
}

WINAPI HRESULT ID3D10ShaderResourceView_QueryInterface(
	/* ID3D10ShaderResourceView */ void * this_, 
	REFIID riid, 
	void **ppvObject
) {
	NuWarn("ID3D10ShaderResourceView::QueryInterface not yet implemented");
	
	*ppvObject = this_;
	
	return S_OK;
}
