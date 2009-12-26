/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/DirectX/DX10/D3D/D3D.h>
#include <APIs/Windows/DirectX/DX10/D3D/D3D_Classes.h>

#define NUMODULE_NAME "D3D10"

static bool hack = False;

WINAPI HRESULT D3D10CreateDevice(
	void *pAdapter, /* IDXGIAdapter */
	D3D10_DRIVER_TYPE DriverType,
	HMODULE Software,
	UINT Flags,
	UINT SDKVersion,
	void **ppDevice /* ID3D10Device */
) {
	SETUP_VTABLE(D3D10);
	
	NuLog("D3D10CreateDevice");
	
	if(DriverType != D3D10_DRIVER_TYPE_HARDWARE)
		return -1;
	
	INIT_CLASS(ID3D10Device, *ppDevice);
	
	return S_OK;
}

WINAPI HRESULT D3D10CreateDeviceAndSwapChain(
	void *pAdapter, /* IDXGIAdapter */
	D3D10_DRIVER_TYPE DriverType,
	HMODULE Software,
	UINT Flags,
	UINT SDKVersion,
	DXGI_SWAP_CHAIN_DESC *pSwapChainDesc,
	void **ppSwapChain, /* IDXGISwapChain */
	void **ppDevice /* ID3D10Device */
) {
	CSTRUCT(ID3D10Device) *_Device;
	
	SETUP_VTABLE(D3D10);
	
	if(ppDevice != None) {
		INIT_CLASS(ID3D10Device, *ppDevice);

		if(pSwapChainDesc != None && ppSwapChain != None) {
			DXGI_CreateSwapChain(*ppDevice, pSwapChainDesc, ppSwapChain);
		}
		
		_Device = GET_CLASS_STRUCT(ID3D10Device, *ppDevice);
		_Device->device = NuRender_CreateDevice();
	}
	
	return S_OK;
}

WINAPI ULONG ID3D10Device_Release(/* ID3D10Device */ void * this_) {
	return 0;
}

WINAPI void ID3D10Device_Draw(
	/* ID3D10Device */ void * this_, 
	UINT VertexCount, 
	UINT StartVertexLocation
) {
	CSTRUCT(ID3D10Device) *_Device;
	CSTRUCT(ID3D10Buffer) *_Vertices;
	unsigned int i;
	
	unsigned char *vertices;
	
	NuWarn("ID3D10Device::Draw not yet implemented");
	
	_Device = GET_CLASS_STRUCT(ID3D10Device, this_);
	_Vertices = GET_CLASS_STRUCT(ID3D10Buffer, _Device->vertices);
	
	vertices = _Vertices->buffer + _Device->vertexWidth*StartVertexLocation;
	
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	
	switch(_Device->topology) {
		case D3D10_PRIMITIVE_TOPOLOGY_POINTLIST:
			glBegin(GL_POINTS);
			for(i = 0; i < VertexCount; ++i) {
				if(hack)
					glTexCoord2fv((float *) (vertices + (sizeof(float) * 3)));
				else
					glTexCoord2fv((float *) (vertices + (sizeof(float) * 6)));
				glVertex3fv((float *) vertices);
				
				vertices += _Device->vertexWidth;
			}
			glEnd();
			break;
		case D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST:
			glBegin(GL_TRIANGLES);
			for(i = 0; i < VertexCount; ++i) {
				if(hack)
					glTexCoord2fv((float *) (vertices + (sizeof(float) * 3)));
				else
					glTexCoord2fv((float *) (vertices + (sizeof(float) * 6)));
				glVertex3fv((float *) vertices);
				
				vertices += _Device->vertexWidth;
			}
			glEnd();
			break;
		default:
			NuError("Unsupported topology type: %i %08X", _Device->topology, _Device->topology);
	}
}

WINAPI void ID3D10Device_DrawIndexed(
	/* ID3D10Device */ void * this_, 
	UINT IndexCount, 
	UINT StartIndexLocation, 
	INT BaseVertexLocation
) {
	CSTRUCT(ID3D10Device) *_Device;
	CSTRUCT(ID3D10Buffer) *_Indices, *_Vertices;
	unsigned int i;
	
	unsigned short int *shortIndices = None;
	unsigned int *longIndices = None;
	unsigned int index, indexv[4];
	
	unsigned char *vertices;
	float *tempFloatPtr;
	
	NuWarn("ID3D10Device::DrawIndexed not yet implemented");
	
	_Device = GET_CLASS_STRUCT(ID3D10Device, this_);
	_Indices = GET_CLASS_STRUCT(ID3D10Buffer, _Device->indices);
	_Vertices = GET_CLASS_STRUCT(ID3D10Buffer, _Device->vertices);
	
	vertices = _Vertices->buffer + _Device->vertexWidth*BaseVertexLocation;
	
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	
	switch(_Device->indexFormat) {
		case DXGI_FORMAT_R32_UINT:
			longIndices = _Indices->buffer;
			break;
		case DXGI_FORMAT_R16_UINT:
			shortIndices = _Indices->buffer;
			break;
		default:
			NuError("Unsupported index format: %i %08X", _Device->indexFormat, _Device->indexFormat);
	}
	
	switch(_Device->topology) {
		case D3D10_PRIMITIVE_TOPOLOGY_POINTLIST:
			glBegin(GL_POINTS);
			for(i = StartIndexLocation; i < StartIndexLocation + IndexCount; ++i) {
				if(longIndices != None)
					index = *(longIndices++);
				else
					index = *(shortIndices++);
				
				if(hack)
					glTexCoord2fv((float *) (vertices + (_Device->vertexWidth * index) + (sizeof(float) * 3)));
				else
					glTexCoord2fv((float *) (vertices + (_Device->vertexWidth * index) + (sizeof(float) * 6)));
				glVertex3fv((float *) (vertices + (_Device->vertexWidth * index)));
			}
			glEnd();
			break;
		case D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST:
			glBegin(GL_TRIANGLES);
			for(i = StartIndexLocation; i < StartIndexLocation + IndexCount; ++i) {
				if(longIndices != None)
					index = *(longIndices++);
				else
					index = *(shortIndices++);
				
				if(hack)
					glTexCoord2fv((float *) (vertices + (_Device->vertexWidth * index) + (sizeof(float) * 3)));
				else
					glTexCoord2fv((float *) (vertices + (_Device->vertexWidth * index) + (sizeof(float) * 6)));
				glVertex3fv((float *) (vertices + (_Device->vertexWidth * index)));
			}
			glEnd();
			break;
		default:
			NuError("Unsupported topology type: %i %08X", _Device->topology, _Device->topology);
	}
	
	glEnd();
}

WINAPI void ID3D10Device_IASetInputLayout(
	/* ID3D10Device */ void * this_, 
	/* ID3D10InputLayout */ void *pInputLayout
) {
	NuWarn("ID3D10Device::IASetInputLayout not yet implemented");


	if((unsigned int) pInputLayout < 3)
		hack = True;
	else
		hack = False;
}

WINAPI void ID3D10Device_IASetVertexBuffers(
	/* ID3D10Device */ void * this_, 
	UINT StartSlot, 
	UINT NumBuffers, 
	/* ID3D10Buffer */ void *const *ppVertexBuffers, 
	const UINT *pStrides, 
	const UINT *pOffsets
) {
	CSTRUCT(ID3D10Device) *_Device;
	
	_Device = GET_CLASS_STRUCT(ID3D10Device, this_);
	_Device->vertexWidth = pStrides[0];
	_Device->vertices = ppVertexBuffers[0];
}

WINAPI void ID3D10Device_IASetIndexBuffer(
	/* ID3D10Device */ void * this_, 
	/* ID3D10Buffer */ void *pIndexBuffer, 
	DXGI_FORMAT Format, 
	UINT Offset
) {
	CSTRUCT(ID3D10Device) *_Device;
	
	_Device = GET_CLASS_STRUCT(ID3D10Device, this_);
	_Device->indexFormat = Format;
	_Device->indices = pIndexBuffer;
}

WINAPI void ID3D10Device_IASetPrimitiveTopology(
	/* ID3D10Device */ void * this_, 
	D3D10_PRIMITIVE_TOPOLOGY Topology
) {
	CSTRUCT(ID3D10Device) *_Device;
	
	_Device = GET_CLASS_STRUCT(ID3D10Device, this_);
	_Device->topology = Topology;
}

WINAPI void ID3D10Device_OMSetRenderTargets(
	/* ID3D10Device */ void * this_,
	UINT NumViews,
	/* ID3D10RenderTargetView */ void *const *ppRenderTargetViews,
	/* ID3D10DepthStencilView */ void *pDepthStencilView
) {
	NuWarn("ID3D10Device::OMSetRenderTargets not yet implemented");
}

WINAPI void ID3D10Device_SOSetTargets(
	/* ID3D10Device */ void * this_, 
	UINT NumBuffers, 
	/* ID3D10Buffer */ void *const *ppSOTargets, 
	const UINT *pOffsets
) {
	NuWarn("ID3D10Device::SOSetTargets not yet implemented");
}

WINAPI void ID3D10Device_RSSetViewports(
	/* ID3D10Device */ void * this_,
	UINT NumViewports,
	const D3D10_VIEWPORT *pViewports
) {
	if(NumViewports != 1)
		NuError("ID3D10Device::RSSetViewPorts only supports one viewport at a time");
	
	glViewport(
		pViewports[0].TopLeftX,
		pViewports[0].TopLeftY,
		pViewports[0].Width,
		pViewports[0].Height
	);
	
	glDepthRange(
		pViewports[0].MinDepth,
		pViewports[0].MaxDepth
	);
}

WINAPI void ID3D10Device_ClearRenderTargetView(
	/* ID3D10Device */ void * this_,
	/* ID3D10RenderTargetView */ void *pRenderTargetView,
	const FLOAT ColorRGBA[ 4 ]
) {
	CSTRUCT(ID3D10Device) *_Device = GET_CLASS_STRUCT(ID3D10Device, this_);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	NuRender_DeviceClear(_Device->device, (FLOAT *) ColorRGBA);
}

WINAPI void ID3D10Device_ClearDepthStencilView(
	/* ID3D10Device */ void * this_, 
	/* ID3D10DepthStencilView */ void *pDepthStencilView, 
	UINT ClearFlags, 
	FLOAT Depth, 
	UINT8 Stencil
) {
	NuWarn("ID3D10Device::ClearDepthStencilView not yet implemented");
}

WINAPI HRESULT ID3D10Device_CreateBuffer(
	/* ID3D10Device */ void * this_, 
	const D3D10_BUFFER_DESC *pDesc, 
	const D3D10_SUBRESOURCE_DATA *pInitialData, 
	/* ID3D10Buffer */ void **ppBuffer
) {
	CSTRUCT(ID3D10Buffer) *_Buffer;
	
	NuWarn("ID3D10Device::CreateBuffer builds buffers in system memory");
	
	if(ppBuffer) {
		INIT_CLASS(ID3D10Buffer, *ppBuffer);
		_Buffer = GET_CLASS_STRUCT(ID3D10Buffer, *ppBuffer);
		
		_Buffer->size = pDesc->ByteWidth;
		
		if(_Buffer->size > 0 && pInitialData != None) {
			_Buffer->buffer = (void *) malloc(_Buffer->size);
			memcpy(_Buffer->buffer, pInitialData->pSysMem, _Buffer->size);
		} else
			_Buffer->buffer = None;
	}
	
	return S_OK;
}

WINAPI HRESULT ID3D10Device_CreateTexture1D(
	/* ID3D10Device */ void * this_, 
	const D3D10_TEXTURE1D_DESC *pDesc, 
	const D3D10_SUBRESOURCE_DATA *pInitialData, 
	/* ID3D10Texture1D */ void **ppTexture1D
) {
	*ppTexture1D = D3D10_CreateTexture1D(pDesc, pInitialData);
	
	return S_OK;
}

WINAPI HRESULT ID3D10Device_CreateTexture2D(
	/* ID3D10Device */ void * this_,
	const D3D10_TEXTURE2D_DESC *pDesc,
	const D3D10_SUBRESOURCE_DATA *pInitialData,
	/* ID3D10Texture2D */ void **ppTexture2D
) {
	*ppTexture2D = D3D10_CreateTexture2D(pDesc, pInitialData);
	
	return S_OK;
}

WINAPI HRESULT ID3D10Device_CreateShaderResourceView(
	/* ID3D10Device */ void * this_, 
	/* ID3D10Resource */ void *pResource, 
	const D3D10_SHADER_RESOURCE_VIEW_DESC *pDesc, 
	/* ID3D10ShaderResourceView */ void **ppSRView
) {
	NuWarn("ID3D10Device::CreateShaderResourceView not yet implemented");
	
	if(ppSRView) {
		*ppSRView = D3D10_CreateShaderResourceView();
	}
	
	return S_OK;
}

WINAPI HRESULT ID3D10Device_CreateRenderTargetView(
	/* ID3D10Device */ void * this_,
	/* ID3D10Resource */ void *pResource,
	const D3D10_RENDER_TARGET_VIEW_DESC *pDesc,
	/* ID3D10RenderTargetView */ void **ppRTView
) {
	NuWarn("ID3D10Device::CreateRenderTargetView not yet implemented");
	
	return S_OK;
}

WINAPI HRESULT ID3D10Device_CreateDepthStencilView(
	/* ID3D10Device */ void * this_,
	/* ID3D10Resource */ void *pResource,
	const D3D10_DEPTH_STENCIL_VIEW_DESC *pDesc,
	/* ID3D10DepthStencilView */ void **ppDepthStencilView
) {
	NuWarn("ID3D10Device::CreateDepthStencilView not yet implemented");
	
	*ppDepthStencilView = (void *) 0xDEADBEEF;
	
	return S_OK;
}

WINAPI HRESULT ID3D10Device_CreateInputLayout(
	/* ID3D10Device */ void * this_, 
	const D3D10_INPUT_ELEMENT_DESC *pInputElementDescs, 
	UINT NumElements, 
	const void *pShaderBytecodeWithInputSignature, 
	SIZE_T BytecodeLength, 
	/* ID3D10InputLayout */ void **ppInputLayout
) {
	NuWarn("ID3D10Device::CreateInputLayout not yet implemented");
	
	if(ppInputLayout) *ppInputLayout = (void *) NumElements;
	
	return S_OK;
}

WINAPI HRESULT ID3D10Device_CreateDepthStencilState(
	/* ID3D10Device */ void * this_, 
	const D3D10_DEPTH_STENCIL_DESC *pDepthStencilDesc, 
	/* ID3D10DepthStencilState */ void **ppDepthStencilState
) {
	NuWarn("ID3D10Device::CreateDepthStencilState not yet implemented");
	
	if(ppDepthStencilState) *ppDepthStencilState = None;
	
	return S_OK;
}

WINAPI HRESULT ID3D10Device_CreateRasterizerState(
	/* ID3D10Device */ void * this_, 
	const D3D10_RASTERIZER_DESC *pRasterizerDesc, 
	/* ID3D10RasterizerState */ void **ppRasterizerState
) {
	NuWarn("ID3D10Device::CreateRasterizerState not yet implemented");
	
	if(ppRasterizerState) *ppRasterizerState = None;
	
	return S_OK;
}

WINAPI HRESULT ID3D10Device_CheckMultisampleQualityLevels(
	/* ID3D10Device */ void * this_, 
	DXGI_FORMAT Format, 
	UINT SampleCount, 
	UINT *pNumQualityLevels
) {
	NuWarn("ID3D10Device::CheckMultisampleQualityLevels not yet implemented");
	
	*pNumQualityLevels = (UINT) pow((float) 2, (float) SampleCount);
	
	return S_OK;
}
