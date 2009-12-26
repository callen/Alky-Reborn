/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/D3DX/D3DX.h>
#include <APIs/Windows/DirectX/D3DX/D3DX_Classes.h>

#define NUMODULE_NAME "D3DX"

WINAPI HRESULT ID3DXBuffer_Init(
	void *this_,
	DWORD bytes,
	void *buffer
) {
	CSTRUCT(ID3DXBuffer) *_Buffer;
	
	_Buffer = GET_CLASS_STRUCT(ID3DXBuffer, this_);
	
	_Buffer->length = bytes;
	
	if(bytes != 0) {
		_Buffer->buffer = NuMemory_Alloc(bytes);
		
		if(buffer != None)
			memcpy(_Buffer->buffer, buffer, bytes);
	}
	else
		_Buffer->buffer = None;
	
	return S_OK;
}

WINAPI HRESULT ID3DXBuffer_Release(
	void *this_
) {
	NuWarn("ID3DXBuffer::Release not yet implemented");
	
	return S_OK;
}

WINAPI LPVOID ID3DXBuffer_GetBufferPointer(
	void *this_
) {
	CSTRUCT(ID3DXBuffer) *_Buffer;
	
	_Buffer = GET_CLASS_STRUCT(ID3DXBuffer, this_);
	
	return _Buffer->buffer;
}

WINAPI LPVOID ID3DXBuffer_GetBufferSize(
	void *this_
) {
	CSTRUCT(ID3DXBuffer) *_Buffer;
	
	_Buffer = GET_CLASS_STRUCT(ID3DXBuffer, this_);
	
	return _Buffer->length;
}
