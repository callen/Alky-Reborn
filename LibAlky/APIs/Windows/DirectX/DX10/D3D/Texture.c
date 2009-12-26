/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/DX10/D3D/D3D.h>
#include <APIs/Windows/DirectX/DX10/D3D/D3D_Classes.h>

#define NUMODULE_NAME "D3D10"

WINAPI /* ID3D10Texture1D */ void *D3D10_CreateTexture1D(
	D3D10_TEXTURE1D_DESC *pDesc,
	D3D10_SUBRESOURCE_DATA *pInitialData
) {
	CSTRUCT(ID3D10Texture1D) *_Texture;
	void *ret;
	GLint type;

	NuLog("D3D10_CreateTexture1D");
	
	SETUP_VTABLE(D3D10);
	INIT_CLASS(ID3D10Texture1D, ret);
	_Texture = GET_CLASS_STRUCT(ID3D10Texture1D, ret);
	
	return ret;
}

WINAPI /* ID3D10Texture2D */ void *D3D10_CreateTexture2D(
	D3D10_TEXTURE2D_DESC *pDesc,
	D3D10_SUBRESOURCE_DATA *pInitialData
) {
	CSTRUCT(ID3D10Texture2D) *_Texture;
	void *ret;
	GLint type;

	static void (*pglCompressedTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data) = None;
	
	NuLog("D3D10_CreateTexture2D");
	
	SETUP_VTABLE(D3D10);
	INIT_CLASS(ID3D10Texture2D, ret);
	_Texture = GET_CLASS_STRUCT(ID3D10Texture2D, ret);
	
	memcpy(&_Texture->desc, pDesc, sizeof(D3D10_TEXTURE2D_DESC));
	
	if(pInitialData == None) {
		_Texture->bufferSize = 0;
		_Texture->buffer = None;
		
		_Texture->tex = 0xDEADBEEF;
	} else {
		_Texture->bufferSize = pDesc->Height * pInitialData->SysMemPitch;
		_Texture->buffer = None;
		
		switch(pDesc->Format) {
			case DXGI_FORMAT_BC1_UNORM:
				NuLog("DXT1");
				type = COMPRESSED_RGBA_S3TC_DXT1_EXT;
				break;
			case DXGI_FORMAT_BC3_UNORM:
				NuLog("DXT3");
				type = COMPRESSED_RGBA_S3TC_DXT3_EXT;
				break;
			case DXGI_FORMAT_BC5_UNORM:
				NuLog("DXT5");
				type = COMPRESSED_RGBA_S3TC_DXT5_EXT;
				break;
			case DXGI_FORMAT_R8G8B8A8_UINT:
				NuLog("RGBA");
				type = GL_RGBA;
				break;
			default:
				NuError("Texture format not supported: %i", pDesc->Format);
		}
		
		glGenTextures(1, &_Texture->tex);
		glBindTexture(GL_TEXTURE_2D, _Texture->tex);
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		
		if(type == GL_RGBA) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, pDesc->Width, pDesc->Height, 0, GL_BGRA, GL_UNSIGNED_BYTE, pInitialData->pSysMem);
		}
		else {
			if(pglCompressedTexImage2D == None) {
				pglCompressedTexImage2D = wglGetProcAddress("glCompressedTexImage2D");
				NuAssert(pglCompressedTexImage2D != None);
			}
			
			pglCompressedTexImage2D(GL_TEXTURE_2D, 0, type, pDesc->Width, pDesc->Height, 0, _Texture->bufferSize, pInitialData->pSysMem);
		}
	}
	
	return ret;
}

WINAPI /* ID3D10Texture2D */ void *D3D10_CreateTexture2DFromDDS(
	DDS *dds
) {
	D3D10_TEXTURE2D_DESC desc;
	D3D10_SUBRESOURCE_DATA data;
	
	NuLog("D3D10_CreateTexture2DFromDDS");
	
	desc.Width = dds->width;
	desc.Height = dds->height;
	desc.MipLevels = dds->mipmapCount;
	desc.ArraySize = dds->bufferCount;
	
	switch(dds->format) {
		case DXT1:
			NuLog("DXT1");
			desc.Format = DXGI_FORMAT_BC1_UNORM;
			break;
		case DXT2:
			NuLog("DXT2");
			desc.Format = DXGI_FORMAT_BC2_UNORM;
			break;
		case DXT3:
			NuLog("DXT3");
			desc.Format = DXGI_FORMAT_BC3_UNORM;
			break;
		case DXT4:
			NuLog("DXT4");
			desc.Format = DXGI_FORMAT_BC4_UNORM;
			break;
		case DXT5:
			NuLog("DXT5");
			desc.Format = DXGI_FORMAT_BC5_UNORM;
			break;
		case URGBA32:
			NuLog("URGBA32");
			desc.Format = DXGI_FORMAT_R8G8B8A8_UINT;
			break;
		default:
			NuError("Unsupported DDS type: %i", dds->format);
	}
	
	data.pSysMem = dds->buffers[0];
	data.SysMemPitch = dds->pitch;
	
	return D3D10_CreateTexture2D(&desc, &data);
}

WINAPI HRESULT ID3D10Texture2D_QueryInterface(
	/* ID3D10Texture2D */ void * this_, 
	REFIID riid, 
	void **ppvObject
) {
	NuWarn("ID3D10Texture2D::QueryInterface not yet implemented");
	
	*ppvObject = this_;
	
	return S_OK;
}

WINAPI ULONG ID3D10Texture2D_Release(/* ID3D10Texture2D */ void * this_) {
	return 0;
}

WINAPI void ID3D10Texture2D_GetDesc(
	/* ID3D10Texture2D */ void * this_, 
	D3D10_TEXTURE2D_DESC *pDesc
) {
	CSTRUCT(ID3D10Texture2D) *_Texture = GET_CLASS_STRUCT(ID3D10Texture2D, this_);
	
	memcpy(pDesc, &_Texture->desc, sizeof(D3D10_TEXTURE2D_DESC));
}
