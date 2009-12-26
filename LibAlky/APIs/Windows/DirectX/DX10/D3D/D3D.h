/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __API_WINDOWS_DIRECTX_DXTEN_DTHREED_DTHREED_H__
#define __API_WINDOWS_DIRECTX_DXTEN_DTHREED_DTHREED_H__

#include <APIs/Windows/DirectX/DX10/D3DX/D3DX_Types.h>
#include <APIs/Windows/DirectX/DX10/D3D/D3D_Types.h>
#include <APIs/Windows/Windows.h>
#include <APIs/Windows/COM/COM.h>

VTABLE_SETUP_DECL(D3D10);

WINAPI HRESULT D3D10CreateDevice(
	void *pAdapter, /* IDXGIAdapter */
	D3D10_DRIVER_TYPE DriverType,
	HMODULE Software,
	UINT Flags,
	UINT SDKVersion,
	void **ppDevice /* ID3D10Device */
);

WINAPI HRESULT D3D10CreateDeviceAndSwapChain(
	void *pAdapter, /* IDXGIAdapter */
	D3D10_DRIVER_TYPE DriverType,
	HMODULE Software,
	UINT Flags,
	UINT SDKVersion,
	DXGI_SWAP_CHAIN_DESC *pSwapChainDesc,
	void **ppSwapChain, /* IDXGISwapChain */
	void **ppDevice /* ID3D10Device */
);

/* Buffer.c */

WINAPI HRESULT ID3D10Buffer_QueryInterface(/* ID3D10Buffer */ void * this_, REFIID riid, void **ppvObject);
WINAPI ULONG ID3D10Buffer_AddRef(/* ID3D10Buffer */ void * this_);
WINAPI ULONG ID3D10Buffer_Release(/* ID3D10Buffer */ void * this_);
WINAPI void ID3D10Buffer_GetDevice(/* ID3D10Buffer */ void * this_, /* ID3D10Device */ void **ppDevice);
WINAPI HRESULT ID3D10Buffer_GetPrivateData(/* ID3D10Buffer */ void * this_, REFGUID guid, UINT *pDataSize, void *pData);
WINAPI HRESULT ID3D10Buffer_SetPrivateData(/* ID3D10Buffer */ void * this_, REFGUID guid, UINT DataSize, const void *pData);
WINAPI HRESULT ID3D10Buffer_SetPrivateDataInterface(/* ID3D10Buffer */ void * this_, REFGUID guid, const /* IUnknown */ void *pData);
WINAPI void ID3D10Buffer_GetType(/* ID3D10Buffer */ void * this_, D3D10_RESOURCE_DIMENSION *rType);
WINAPI void ID3D10Buffer_SetEvictionPriority(/* ID3D10Buffer */ void * this_, UINT EvictionPriority);
WINAPI UINT ID3D10Buffer_GetEvictionPriority(/* ID3D10Buffer */ void * this_);
WINAPI HRESULT ID3D10Buffer_Map(/* ID3D10Buffer */ void * this_, D3D10_MAP MapType, UINT MapFlags, void **ppData);
WINAPI void ID3D10Buffer_Unmap(/* ID3D10Buffer */ void * this_);
WINAPI void ID3D10Buffer_GetDesc(/* ID3D10Buffer */ void * this_, D3D10_BUFFER_DESC *pDesc);

/* Device.c */

WINAPI HRESULT ID3D10Device_QueryInterface(/* ID3D10Device */ void * this_, REFIID riid, void **ppvObject);
WINAPI ULONG ID3D10Device_AddRef(/* ID3D10Device */ void * this_);
WINAPI ULONG ID3D10Device_Release(/* ID3D10Device */ void * this_);
WINAPI void ID3D10Device_VSSetConstantBuffers(/* ID3D10Device */ void * this_, UINT StartSlot, UINT NumBuffers, /* ID3D10Buffer */ void *const *ppConstantBuffers);
WINAPI void ID3D10Device_PSSetShaderResources(/* ID3D10Device */ void * this_, UINT StartSlot, UINT NumViews, /* ID3D10ShaderResourceView */ void *const *ppShaderResourceViews);
WINAPI void ID3D10Device_PSSetShader(/* ID3D10Device */ void * this_, /* ID3D10PixelShader */ void *pPixelShader);
WINAPI void ID3D10Device_PSSetSamplers(/* ID3D10Device */ void * this_, UINT StartSlot, UINT NumSamplers, /* ID3D10SamplerState */ void *const *ppSamplers);
WINAPI void ID3D10Device_VSSetShader(/* ID3D10Device */ void * this_, /* ID3D10VertexShader */ void *pVertexShader);
WINAPI void ID3D10Device_DrawIndexed(/* ID3D10Device */ void * this_, UINT IndexCount, UINT StartIndexLocation, INT BaseVertexLocation);
WINAPI void ID3D10Device_Draw(/* ID3D10Device */ void * this_, UINT VertexCount, UINT StartVertexLocation);
WINAPI void ID3D10Device_PSSetConstantBuffers(/* ID3D10Device */ void * this_, UINT StartSlot, UINT NumBuffers, /* ID3D10Buffer */ void *const *ppConstantBuffers);
WINAPI void ID3D10Device_IASetInputLayout(/* ID3D10Device */ void * this_, /* ID3D10InputLayout */ void *pInputLayout);
WINAPI void ID3D10Device_IASetVertexBuffers(/* ID3D10Device */ void * this_, UINT StartSlot, UINT NumBuffers, /* ID3D10Buffer */ void *const *ppVertexBuffers, const UINT *pStrides, const UINT *pOffsets);
WINAPI void ID3D10Device_IASetIndexBuffer(/* ID3D10Device */ void * this_, /* ID3D10Buffer */ void *pIndexBuffer, DXGI_FORMAT Format, UINT Offset);
WINAPI void ID3D10Device_DrawIndexedInstanced(/* ID3D10Device */ void * this_, UINT IndexCountPerInstance, UINT InstanceCount, UINT StartIndexLocation, INT BaseVertexLocation, UINT StartInstanceLocation);
WINAPI void ID3D10Device_DrawInstanced(/* ID3D10Device */ void * this_, UINT VertexCountPerInstance, UINT InstanceCount, UINT StartVertexLocation, UINT StartInstanceLocation);
WINAPI void ID3D10Device_GSSetConstantBuffers(/* ID3D10Device */ void * this_, UINT StartSlot, UINT NumBuffers, /* ID3D10Buffer */ void *const *ppConstantBuffers);
WINAPI void ID3D10Device_GSSetShader(/* ID3D10Device */ void * this_, /* ID3D10GeometryShader */ void *pShader);
WINAPI void ID3D10Device_IASetPrimitiveTopology(/* ID3D10Device */ void * this_, D3D10_PRIMITIVE_TOPOLOGY Topology);
WINAPI void ID3D10Device_VSSetShaderResources(/* ID3D10Device */ void * this_, UINT StartSlot, UINT NumViews, /* ID3D10ShaderResourceView */ void *const *ppShaderResourceViews);
WINAPI void ID3D10Device_VSSetSamplers(/* ID3D10Device */ void * this_, UINT StartSlot, UINT NumSamplers, /* ID3D10SamplerState */ void *const *ppSamplers);
WINAPI void ID3D10Device_SetPredication(/* ID3D10Device */ void * this_, /* ID3D10Predicate */ void *pPredicate, BOOL PredicateValue);
WINAPI void ID3D10Device_GSSetShaderResources(/* ID3D10Device */ void * this_, UINT StartSlot, UINT NumViews, /* ID3D10ShaderResourceView */ void *const *ppShaderResourceViews);
WINAPI void ID3D10Device_GSSetSamplers(/* ID3D10Device */ void * this_, UINT StartSlot, UINT NumSamplers, /* ID3D10SamplerState */ void *const *ppSamplers);
WINAPI void ID3D10Device_OMSetRenderTargets(/* ID3D10Device */ void * this_, UINT NumViews, /* ID3D10RenderTargetView */ void *const *ppRenderTargetViews, /* ID3D10DepthStencilView */ void *pDepthStencilView);
WINAPI void ID3D10Device_OMSetBlendState(/* ID3D10Device */ void * this_, /* ID3D10BlendState */ void *pBlendState, const FLOAT BlendFactor[ 4 ], UINT SampleMask);
WINAPI void ID3D10Device_OMSetDepthStencilState(/* ID3D10Device */ void * this_, /* ID3D10DepthStencilState */ void *pDepthStencilState, UINT StencilRef);
WINAPI void ID3D10Device_SOSetTargets(/* ID3D10Device */ void * this_, UINT NumBuffers, /* ID3D10Buffer */ void *const *ppSOTargets, const UINT *pOffsets);
WINAPI void ID3D10Device_DrawAuto(/* ID3D10Device */ void * this_);
WINAPI void ID3D10Device_RSSetState(/* ID3D10Device */ void * this_, /* ID3D10RasterizerState */ void *pRasterizerState);
WINAPI void ID3D10Device_RSSetViewports(/* ID3D10Device */ void * this_, UINT NumViewports, const D3D10_VIEWPORT *pViewports);
WINAPI void ID3D10Device_RSSetScissorRects(/* ID3D10Device */ void * this_, UINT NumRects, const D3D10_RECT *pRects);
WINAPI void ID3D10Device_CopySubresourceRegion(/* ID3D10Device */ void * this_, /* ID3D10Resource */ void *pDstResource, UINT DstSubresource, UINT DstX, UINT DstY, UINT DstZ, /* ID3D10Resource */ void *pSrcResource, UINT SrcSubresource, const D3D10_BOX *pSrcBox);
WINAPI void ID3D10Device_CopyResource(/* ID3D10Device */ void * this_, /* ID3D10Resource */ void *pDstResource, /* ID3D10Resource */ void *pSrcResource);
WINAPI void ID3D10Device_UpdateSubresource(/* ID3D10Device */ void * this_, /* ID3D10Resource */ void *pDstResource, UINT DstSubresource, const D3D10_BOX *pDstBox, const void *pSrcData, UINT SrcRowPitch, UINT SrcDepthPitch);
WINAPI void ID3D10Device_ClearRenderTargetView(/* ID3D10Device */ void * this_, /* ID3D10RenderTargetView */ void *pRenderTargetView, const FLOAT ColorRGBA[ 4 ]);
WINAPI void ID3D10Device_ClearDepthStencilView(/* ID3D10Device */ void * this_, /* ID3D10DepthStencilView */ void *pDepthStencilView, UINT ClearFlags, FLOAT Depth, UINT8 Stencil);
WINAPI void ID3D10Device_GenerateMips(/* ID3D10Device */ void * this_, /* ID3D10ShaderResourceView */ void *pShaderResourceView);
WINAPI void ID3D10Device_ResolveSubresource(/* ID3D10Device */ void * this_, /* ID3D10Resource */ void *pDstResource, UINT DstSubresource, /* ID3D10Resource */ void *pSrcResource, UINT SrcSubresource, DXGI_FORMAT Format);
WINAPI void ID3D10Device_VSGetConstantBuffers(/* ID3D10Device */ void * this_, UINT StartSlot, UINT NumBuffers, /* ID3D10Buffer */ void **ppConstantBuffers);
WINAPI void ID3D10Device_PSGetShaderResources(/* ID3D10Device */ void * this_, UINT StartSlot, UINT NumViews, /* ID3D10ShaderResourceView */ void **ppShaderResourceViews);
WINAPI void ID3D10Device_PSGetShader(/* ID3D10Device */ void * this_, /* ID3D10PixelShader */ void **ppPixelShader);
WINAPI void ID3D10Device_PSGetSamplers(/* ID3D10Device */ void * this_, UINT StartSlot, UINT NumSamplers, /* ID3D10SamplerState */ void **ppSamplers);
WINAPI void ID3D10Device_VSGetShader(/* ID3D10Device */ void * this_, /* ID3D10VertexShader */ void **ppVertexShader);
WINAPI void ID3D10Device_PSGetConstantBuffers(/* ID3D10Device */ void * this_, UINT StartSlot, UINT NumBuffers, /* ID3D10Buffer */ void **ppConstantBuffers);
WINAPI void ID3D10Device_IAGetInputLayout(/* ID3D10Device */ void * this_, /* ID3D10InputLayout */ void **ppInputLayout);
WINAPI void ID3D10Device_IAGetVertexBuffers(/* ID3D10Device */ void * this_, UINT StartSlot, UINT NumBuffers, /* ID3D10Buffer */ void **ppVertexBuffers, UINT *pStrides, UINT *pOffsets);
WINAPI void ID3D10Device_IAGetIndexBuffer(/* ID3D10Device */ void * this_, /* ID3D10Buffer */ void **pIndexBuffer, DXGI_FORMAT *Format, UINT *Offset);
WINAPI void ID3D10Device_GSGetConstantBuffers(/* ID3D10Device */ void * this_, UINT StartSlot, UINT NumBuffers, /* ID3D10Buffer */ void **ppConstantBuffers);
WINAPI void ID3D10Device_GSGetShader(/* ID3D10Device */ void * this_, /* ID3D10GeometryShader */ void **ppGeometryShader);
WINAPI void ID3D10Device_IAGetPrimitiveTopology(/* ID3D10Device */ void * this_, D3D10_PRIMITIVE_TOPOLOGY *pTopology);
WINAPI void ID3D10Device_VSGetShaderResources(/* ID3D10Device */ void * this_, UINT StartSlot, UINT NumViews, /* ID3D10ShaderResourceView */ void **ppShaderResourceViews);
WINAPI void ID3D10Device_VSGetSamplers(/* ID3D10Device */ void * this_, UINT StartSlot, UINT NumSamplers, /* ID3D10SamplerState */ void **ppSamplers);
WINAPI void ID3D10Device_GetPredication(/* ID3D10Device */ void * this_, /* ID3D10Predicate */ void **ppPredicate, BOOL *pPredicateValue);
WINAPI void ID3D10Device_GSGetShaderResources(/* ID3D10Device */ void * this_, UINT StartSlot, UINT NumViews, /* ID3D10ShaderResourceView */ void **ppShaderResourceViews);
WINAPI void ID3D10Device_GSGetSamplers(/* ID3D10Device */ void * this_, UINT StartSlot, UINT NumSamplers, /* ID3D10SamplerState */ void **ppSamplers);
WINAPI void ID3D10Device_OMGetRenderTargets(/* ID3D10Device */ void * this_, UINT NumViews, /* ID3D10RenderTargetView */ void **ppRenderTargetViews, /* ID3D10DepthStencilView */ void **ppDepthStencilView);
WINAPI void ID3D10Device_OMGetBlendState(/* ID3D10Device */ void * this_, /* ID3D10BlendState */ void **ppBlendState, FLOAT BlendFactor[ 4 ], UINT *pSampleMask);
WINAPI void ID3D10Device_OMGetDepthStencilState(/* ID3D10Device */ void * this_, /* ID3D10DepthStencilState */ void **ppDepthStencilState, UINT *pStencilRef);
WINAPI void ID3D10Device_SOGetTargets(/* ID3D10Device */ void * this_, UINT NumBuffers, /* ID3D10Buffer */ void **ppSOTargets, UINT *pOffsets);
WINAPI void ID3D10Device_RSGetState(/* ID3D10Device */ void * this_, /* ID3D10RasterizerState */ void **ppRasterizerState);
WINAPI void ID3D10Device_RSGetViewports(/* ID3D10Device */ void * this_, UINT *NumViewports, D3D10_VIEWPORT *pViewports);
WINAPI void ID3D10Device_RSGetScissorRects(/* ID3D10Device */ void * this_, UINT *NumRects, D3D10_RECT *pRects);
WINAPI HRESULT ID3D10Device_GetDeviceRemovedReason(/* ID3D10Device */ void * this_);
WINAPI HRESULT ID3D10Device_SetExceptionMode(/* ID3D10Device */ void * this_, UINT RaiseFlags);
WINAPI UINT ID3D10Device_GetExceptionMode(/* ID3D10Device */ void * this_);
WINAPI HRESULT ID3D10Device_GetPrivateData(/* ID3D10Device */ void * this_, REFGUID guid, UINT *pDataSize, void *pData);
WINAPI HRESULT ID3D10Device_SetPrivateData(/* ID3D10Device */ void * this_, REFGUID guid, UINT DataSize, const void *pData);
WINAPI HRESULT ID3D10Device_SetPrivateDataInterface(/* ID3D10Device */ void * this_, REFGUID guid, const /* IUnknown */ void *pData);
WINAPI void ID3D10Device_ClearState(/* ID3D10Device */ void * this_);
WINAPI void ID3D10Device_Flush(/* ID3D10Device */ void * this_);
WINAPI HRESULT ID3D10Device_CreateBuffer(/* ID3D10Device */ void * this_, const D3D10_BUFFER_DESC *pDesc, const D3D10_SUBRESOURCE_DATA *pInitialData, /* ID3D10Buffer */ void **ppBuffer);
WINAPI HRESULT ID3D10Device_CreateTexture1D(/* ID3D10Device */ void * this_, const D3D10_TEXTURE1D_DESC *pDesc, const D3D10_SUBRESOURCE_DATA *pInitialData, /* ID3D10Texture1D */ void **ppTexture1D);
WINAPI HRESULT ID3D10Device_CreateTexture2D(/* ID3D10Device */ void * this_, const D3D10_TEXTURE2D_DESC *pDesc, const D3D10_SUBRESOURCE_DATA *pInitialData, /* ID3D10Texture2D */ void **ppTexture2D);
WINAPI HRESULT ID3D10Device_CreateTexture3D(/* ID3D10Device */ void * this_, const D3D10_TEXTURE3D_DESC *pDesc, const D3D10_SUBRESOURCE_DATA *pInitialData, /* ID3D10Texture3D */ void **ppTexture3D);
WINAPI HRESULT ID3D10Device_CreateShaderResourceView(/* ID3D10Device */ void * this_, /* ID3D10Resource */ void *pResource, const D3D10_SHADER_RESOURCE_VIEW_DESC *pDesc, /* ID3D10ShaderResourceView */ void **ppSRView);
WINAPI HRESULT ID3D10Device_CreateRenderTargetView(/* ID3D10Device */ void * this_, /* ID3D10Resource */ void *pResource, const D3D10_RENDER_TARGET_VIEW_DESC *pDesc, /* ID3D10RenderTargetView */ void **ppRTView);
WINAPI HRESULT ID3D10Device_CreateDepthStencilView(/* ID3D10Device */ void * this_, /* ID3D10Resource */ void *pResource, const D3D10_DEPTH_STENCIL_VIEW_DESC *pDesc, /* ID3D10DepthStencilView */ void **ppDepthStencilView);
WINAPI HRESULT ID3D10Device_CreateInputLayout(/* ID3D10Device */ void * this_, const D3D10_INPUT_ELEMENT_DESC *pInputElementDescs, UINT NumElements, const void *pShaderBytecodeWithInputSignature, SIZE_T BytecodeLength, /* ID3D10InputLayout */ void **ppInputLayout);
WINAPI HRESULT ID3D10Device_CreateVertexShader(/* ID3D10Device */ void * this_, const void *pShaderBytecode, SIZE_T BytecodeLength, /* ID3D10VertexShader */ void **ppVertexShader);
WINAPI HRESULT ID3D10Device_CreateGeometryShader(/* ID3D10Device */ void * this_, const void *pShaderBytecode, SIZE_T BytecodeLength, /* ID3D10GeometryShader */ void **ppGeometryShader);
WINAPI HRESULT ID3D10Device_CreateGeometryShaderWithStreamOutput(/* ID3D10Device */ void * this_, const void *pShaderBytecode, SIZE_T BytecodeLength, const D3D10_SO_DECLARATION_ENTRY *pSODeclaration, UINT NumEntries, UINT OutputStreamStride, /* ID3D10GeometryShader */ void **ppGeometryShader);
WINAPI HRESULT ID3D10Device_CreatePixelShader(/* ID3D10Device */ void * this_, const void *pShaderBytecode, SIZE_T BytecodeLength, /* ID3D10PixelShader */ void **ppPixelShader);
WINAPI HRESULT ID3D10Device_CreateBlendState(/* ID3D10Device */ void * this_, const D3D10_BLEND_DESC *pBlendStateDesc, /* ID3D10BlendState */ void **ppBlendState);
WINAPI HRESULT ID3D10Device_CreateDepthStencilState(/* ID3D10Device */ void * this_, const D3D10_DEPTH_STENCIL_DESC *pDepthStencilDesc, /* ID3D10DepthStencilState */ void **ppDepthStencilState);
WINAPI HRESULT ID3D10Device_CreateRasterizerState(/* ID3D10Device */ void * this_, const D3D10_RASTERIZER_DESC *pRasterizerDesc, /* ID3D10RasterizerState */ void **ppRasterizerState);
WINAPI HRESULT ID3D10Device_CreateSamplerState(/* ID3D10Device */ void * this_, const D3D10_SAMPLER_DESC *pSamplerDesc, /* ID3D10SamplerState */ void **ppSamplerState);
WINAPI HRESULT ID3D10Device_CreateQuery(/* ID3D10Device */ void * this_, const D3D10_QUERY_DESC *pQueryDesc, /* ID3D10Query */ void **ppQuery);
WINAPI HRESULT ID3D10Device_CreatePredicate(/* ID3D10Device */ void * this_, const D3D10_QUERY_DESC *pPredicateDesc, /* ID3D10Predicate */ void **ppPredicate);
WINAPI HRESULT ID3D10Device_CreateCounter(/* ID3D10Device */ void * this_, const D3D10_COUNTER_DESC *pCounterDesc, /* ID3D10Counter */ void **ppCounter);
WINAPI HRESULT ID3D10Device_CheckFormatSupport(/* ID3D10Device */ void * this_, DXGI_FORMAT Format, UINT *pFormatSupport);
WINAPI HRESULT ID3D10Device_CheckMultisampleQualityLevels(/* ID3D10Device */ void * this_, DXGI_FORMAT Format, UINT SampleCount, UINT *pNumQualityLevels);
WINAPI void ID3D10Device_CheckCounterInfo(/* ID3D10Device */ void * this_, D3D10_COUNTER_INFO *pCounterInfo);
WINAPI HRESULT ID3D10Device_CheckCounter(/* ID3D10Device */ void * this_, const D3D10_COUNTER_DESC *pDesc, D3D10_COUNTER_TYPE *pType, UINT *pActiveCounters, LPSTR szName, UINT *pNameLength, LPSTR szUnits, UINT *pUnitsLength, LPSTR szDescription, UINT *pDescriptionLength);
WINAPI UINT ID3D10Device_GetCreationFlags(/* ID3D10Device */ void * this_);
WINAPI HRESULT ID3D10Device_OpenSharedResource(/* ID3D10Device */ void * this_, HANDLE hResource, REFIID ReturnedInterface, void **ppResource);
WINAPI void ID3D10Device_SetTextFilterSize(/* ID3D10Device */ void * this_, UINT Width, UINT Height);
WINAPI void ID3D10Device_GetTextFilterSize(/* ID3D10Device */ void * this_, UINT *pWidth, UINT *pHeight);

/* Effect.c */

WINAPI /* ID3D10Effect */ void *D3D10_CreateEffect(/* ID3D10Device */ void *device);

WINAPI void ID3D10Effect_QueryInterface(/* ID3D10Effect */ void *this, REFIID iid, LPVOID *ppv);
WINAPI ULONG ID3D10Effect_AddRef(/* ID3D10Effect */ void *this);
WINAPI ULONG ID3D10Effect_Release(/* ID3D10Effect */ void *this);
WINAPI BOOL ID3D10Effect_IsValid(/* ID3D10Effect */ void *this);
WINAPI BOOL ID3D10Effect_IsPool(/* ID3D10Effect */ void *this);
WINAPI void ID3D10Effect_GetDevice(/* ID3D10Effect */ void *this, /* ID3D10Device */ void ** ppDevice);
WINAPI void ID3D10Effect_GetDesc(/* ID3D10Effect */ void *this, D3D10_EFFECT_DESC *pDesc);
WINAPI /* ID3D10EffectConstantBuffer */ void *ID3D10Effect_GetConstantBufferByIndex(/* ID3D10Effect */ void *this, UINT Index);
WINAPI /* ID3D10EffectConstantBuffer */ void *ID3D10Effect_GetConstantBufferByName(/* ID3D10Effect */ void *this, LPCSTR Name);
WINAPI /* ID3D10EffectVariable */ void *ID3D10Effect_GetVariableByIndex(/* ID3D10Effect */ void *this, UINT Index);
WINAPI /* ID3D10EffectVariable */ void *ID3D10Effect_GetVariableByName(/* ID3D10Effect */ void *this, LPCSTR Name);
WINAPI /* ID3D10EffectVariable */ void *ID3D10Effect_GetVariableBySemantic(/* ID3D10Effect */ void *this, LPCSTR Semantic);
WINAPI /* ID3D10EffectTechnique */ void *ID3D10Effect_GetTechniqueByIndex(/* ID3D10Effect */ void *this, UINT Index);
WINAPI /* ID3D10EffectTechnique */ void *ID3D10Effect_GetTechniqueByName(/* ID3D10Effect */ void *this, LPCSTR Name);
WINAPI void ID3D10Effect_Optimize(/* ID3D10Effect */ void *this);
WINAPI BOOL ID3D10Effect_IsOptimized(/* ID3D10Effect */ void *this);

/* EffectPass.c */

WINAPI /* ID3D10EffectPass */ void *D3D10_CreateEffectPass(/* ID3D10EffectTechnique */ void *technique);

WINAPI BOOL ID3D10EffectPass_IsValid(/* ID3D10EffectPass */ void *this);
WINAPI void ID3D10EffectPass_GetDesc(/* ID3D10EffectPass */ void *this, D3D10_PASS_DESC *pDesc);
WINAPI void ID3D10EffectPass_GetVertexShaderDesc(/* ID3D10EffectPass */ void *this, D3D10_PASS_SHADER_DESC *pDesc);
WINAPI void ID3D10EffectPass_GetGeometryShaderDesc(/* ID3D10EffectPass */ void *this, D3D10_PASS_SHADER_DESC *pDesc);
WINAPI void ID3D10EffectPass_GetPixelShaderDesc(/* ID3D10EffectPass */ void *this, D3D10_PASS_SHADER_DESC *pDesc);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectPass_GetAnnotationByIndex(/* ID3D10EffectPass */ void *this, UINT Index);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectPass_GetAnnotationByName(/* ID3D10EffectPass */ void *this, LPCSTR Name);
WINAPI void ID3D10EffectPass_Apply(/* ID3D10EffectPass */ void *this, UINT Flags);
WINAPI void ID3D10EffectPass_ComputeStateBlockMask(/* ID3D10EffectPass */ void *this, D3D10_STATE_BLOCK_MASK *pStateBlockMask);

/* EffectTechnique.c */

WINAPI /* ID3D10EffectTechnique */ void *D3D10_CreateEffectTechnique(void *this);

WINAPI BOOL ID3D10EffectTechnique_IsValid(/* ID3D10EffectTechnique */ void *this);
WINAPI void ID3D10EffectTechnique_GetDesc(/* ID3D10EffectTechnique */ void *this, D3D10_TECHNIQUE_DESC *pDesc);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectTechnique_GetAnnotationByIndex(/* ID3D10EffectTechnique */ void *this, UINT Index);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectTechnique_GetAnnotationByName(/* ID3D10EffectTechnique */ void *this, LPCSTR Name);
WINAPI /* ID3D10EffectPass */ void *ID3D10EffectTechnique_GetPassByIndex(/* ID3D10EffectTechnique */ void *this, UINT Index);
WINAPI /* ID3D10EffectPass */ void *ID3D10EffectTechnique_GetPassByName(/* ID3D10EffectTechnique */ void *this, LPCSTR Name);
WINAPI void ID3D10EffectTechnique_ComputeStateBlockMask(/* ID3D10EffectTechnique */ void *this, D3D10_STATE_BLOCK_MASK *pStateBlockMask);

/* EffectVariable.c */

WINAPI /* ID3D10EffectVariable */ void *D3D10_CreateEffectVariable(/* ID3D10Effect */ void *Effect, LPCSTR Name);

WINAPI BOOL ID3D10EffectVariable_IsValid(/* ID3D10EffectVariable */ void *this);
WINAPI /* ID3D10EffectType */ void *ID3D10EffectVariable_GetType(/* ID3D10EffectVariable */ void *this);
WINAPI void ID3D10EffectVariable_GetDesc(/* ID3D10EffectVariable */ void *this, D3D10_EFFECT_VARIABLE_DESC *pDesc);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectVariable_GetAnnotationByIndex(/* ID3D10EffectVariable */ void *this, UINT Index);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectVariable_GetAnnotationByName(/* ID3D10EffectVariable */ void *this, LPCSTR Name);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectVariable_GetMemberByIndex(/* ID3D10EffectVariable */ void *this, UINT Index);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectVariable_GetMemberByName(/* ID3D10EffectVariable */ void *this, LPCSTR Name);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectVariable_GetMemberBySemantic(/* ID3D10EffectVariable */ void *this, LPCSTR Semantic);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectVariable_GetElement(/* ID3D10EffectVariable */ void *this, UINT Index);
WINAPI /* ID3D10EffectConstantBuffer */ void *ID3D10EffectVariable_GetParentConstantBuffer(/* ID3D10EffectVariable */ void *this);
WINAPI /* ID3D10EffectScalarVariable */ void *ID3D10EffectVariable_AsScalar(/* ID3D10EffectVariable */ void *this);
WINAPI /* ID3D10EffectVectorVariable */ void *ID3D10EffectVariable_AsVector(/* ID3D10EffectVariable */ void *this);
WINAPI /* ID3D10EffectMatrixVariable */ void *ID3D10EffectVariable_AsMatrix(/* ID3D10EffectVariable */ void *this);
WINAPI /* ID3D10EffectStringVariable */ void *ID3D10EffectVariable_AsString(/* ID3D10EffectVariable */ void *this);
WINAPI /* ID3D10EffectShaderResourceVariable */ void *ID3D10EffectVariable_AsShaderResource(/* ID3D10EffectVariable */ void *this);
WINAPI /* ID3D10EffectRenderTargetViewVariable */ void *ID3D10EffectVariable_AsRenderTargetView(/* ID3D10EffectVariable */ void *this);
WINAPI /* ID3D10EffectDepthStencilViewVariable */ void *ID3D10EffectVariable_AsDepthStencilView(/* ID3D10EffectVariable */ void *this);
WINAPI /* ID3D10EffectConstantBuffer */ void *ID3D10EffectVariable_AsConstantBuffer(/* ID3D10EffectVariable */ void *this);
WINAPI /* ID3D10EffectShaderVariable */ void *ID3D10EffectVariable_AsShader(/* ID3D10EffectVariable */ void *this);
WINAPI /* ID3D10EffectBlendVariable */ void *ID3D10EffectVariable_AsBlend(/* ID3D10EffectVariable */ void *this);
WINAPI /* ID3D10EffectDepthStencilVariable */ void *ID3D10EffectVariable_AsDepthStencil(/* ID3D10EffectVariable */ void *this);
WINAPI /* ID3D10EffectRasterizerVariable */ void *ID3D10EffectVariable_AsRasterizer(/* ID3D10EffectVariable */ void *this);
WINAPI /* ID3D10EffectSamplerVariable */ void *ID3D10EffectVariable_AsSampler(/* ID3D10EffectVariable */ void *this);
WINAPI void ID3D10EffectVariable_SetRawValue(/* ID3D10EffectVariable */ void *this, void *pData, UINT Offset, UINT Count);
WINAPI void ID3D10EffectVariable_GetRawValue(/* ID3D10EffectVariable */ void *this, void *pData, UINT Offset, UINT Count);

/* EffectMatrixVariable.c */

WINAPI BOOL ID3D10EffectMatrixVariable_IsValid(/* ID3D10EffectMatrixVariable */ void *this);
WINAPI /* ID3D10EffectType */ void *ID3D10EffectMatrixVariable_GetType(/* ID3D10EffectMatrixVariable */ void *this);
WINAPI void ID3D10EffectMatrixVariable_GetDesc(/* ID3D10EffectMatrixVariable */ void *this, D3D10_EFFECT_VARIABLE_DESC *pDesc);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectMatrixVariable_GetAnnotationByIndex(/* ID3D10EffectMatrixVariable */ void *this, UINT Index);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectMatrixVariable_GetAnnotationByName(/* ID3D10EffectMatrixVariable */ void *this, LPCSTR Name);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectMatrixVariable_GetMemberByIndex(/* ID3D10EffectMatrixVariable */ void *this, UINT Index);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectMatrixVariable_GetMemberByName(/* ID3D10EffectMatrixVariable */ void *this, LPCSTR Name);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectMatrixVariable_GetMemberBySemantic(/* ID3D10EffectMatrixVariable */ void *this, LPCSTR Semantic);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectMatrixVariable_GetElement(/* ID3D10EffectMatrixVariable */ void *this, UINT Index);
WINAPI /* ID3D10EffectConstantBuffer */ void *ID3D10EffectMatrixVariable_GetParentConstantBuffer(/* ID3D10EffectMatrixVariable */ void *this);
WINAPI /* ID3D10EffectScalarVariable */ void *ID3D10EffectMatrixVariable_AsScalar(/* ID3D10EffectMatrixVariable */ void *this);
WINAPI /* ID3D10EffectVectorVariable */ void *ID3D10EffectMatrixVariable_AsVector(/* ID3D10EffectMatrixVariable */ void *this);
WINAPI /* ID3D10EffectMatrixVariable */ void *ID3D10EffectMatrixVariable_AsMatrix(/* ID3D10EffectMatrixVariable */ void *this);
WINAPI /* ID3D10EffectStringVariable */ void *ID3D10EffectMatrixVariable_AsString(/* ID3D10EffectMatrixVariable */ void *this);
WINAPI /* ID3D10EffectShaderResourceVariable */ void *ID3D10EffectMatrixVariable_AsShaderResource(/* ID3D10EffectMatrixVariable */ void *this);
WINAPI /* ID3D10EffectRenderTargetViewVariable */ void *ID3D10EffectMatrixVariable_AsRenderTargetView(/* ID3D10EffectMatrixVariable */ void *this);
WINAPI /* ID3D10EffectDepthStencilViewVariable */ void *ID3D10EffectMatrixVariable_AsDepthStencilView(/* ID3D10EffectMatrixVariable */ void *this);
WINAPI /* ID3D10EffectConstantBuffer */ void *ID3D10EffectMatrixVariable_AsConstantBuffer(/* ID3D10EffectMatrixVariable */ void *this);
WINAPI /* ID3D10EffectShaderVariable */ void *ID3D10EffectMatrixVariable_AsShader(/* ID3D10EffectMatrixVariable */ void *this);
WINAPI /* ID3D10EffectBlendVariable */ void *ID3D10EffectMatrixVariable_AsBlend(/* ID3D10EffectMatrixVariable */ void *this);
WINAPI /* ID3D10EffectDepthStencilVariable */ void *ID3D10EffectMatrixVariable_AsDepthStencil(/* ID3D10EffectMatrixVariable */ void *this);
WINAPI /* ID3D10EffectRasterizerVariable */ void *ID3D10EffectMatrixVariable_AsRasterizer(/* ID3D10EffectMatrixVariable */ void *this);
WINAPI /* ID3D10EffectSamplerVariable */ void *ID3D10EffectMatrixVariable_AsSampler(/* ID3D10EffectMatrixVariable */ void *this);
WINAPI void ID3D10EffectMatrixVariable_SetRawValue(/* ID3D10EffectMatrixVariable */ void *this, void *pData, UINT ByteOffset, UINT ByteCount);
WINAPI void ID3D10EffectMatrixVariable_GetRawValue(/* ID3D10EffectMatrixVariable */ void *this, void *pData, UINT ByteOffset, UINT ByteCount);
WINAPI void ID3D10EffectMatrixVariable_SetMatrix(/* ID3D10EffectMatrixVariable */ void *this, float *pData);
WINAPI void ID3D10EffectMatrixVariable_GetMatrix(/* ID3D10EffectMatrixVariable */ void *this, float *pData);
WINAPI void ID3D10EffectMatrixVariable_SetMatrixArray(/* ID3D10EffectMatrixVariable */ void *this, float *pData, UINT Offset, UINT Count);
WINAPI void ID3D10EffectMatrixVariable_GetMatrixArray(/* ID3D10EffectMatrixVariable */ void *this, float *pData, UINT Offset, UINT Count);
WINAPI void ID3D10EffectMatrixVariable_SetMatrixTranspose(/* ID3D10EffectMatrixVariable */ void *this, float *pData);
WINAPI void ID3D10EffectMatrixVariable_GetMatrixTranspose(/* ID3D10EffectMatrixVariable */ void *this, float *pData);
WINAPI void ID3D10EffectMatrixVariable_SetMatrixTransposeArray(/* ID3D10EffectMatrixVariable */ void *this, float *pData, UINT Offset, UINT Count);
WINAPI void ID3D10EffectMatrixVariable_GetMatrixTransposeArray(/* ID3D10EffectMatrixVariable */ void *this, float *pData, UINT Offset, UINT Count);

/* EffectScalarVariable.c */

WINAPI BOOL ID3D10EffectScalarVariable_IsValid(/* ID3D10EffectScalarVariable */ void *this);
WINAPI /* ID3D10EffectType */ void *ID3D10EffectScalarVariable_GetType(/* ID3D10EffectScalarVariable */ void *this);
WINAPI void ID3D10EffectScalarVariable_GetDesc(/* ID3D10EffectScalarVariable */ void *this, D3D10_EFFECT_VARIABLE_DESC *pDesc);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectScalarVariable_GetAnnotationByIndex(/* ID3D10EffectScalarVariable */ void *this, UINT Index);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectScalarVariable_GetAnnotationByName(/* ID3D10EffectScalarVariable */ void *this, LPCSTR Name);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectScalarVariable_GetMemberByIndex(/* ID3D10EffectScalarVariable */ void *this, UINT Index);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectScalarVariable_GetMemberByName(/* ID3D10EffectScalarVariable */ void *this, LPCSTR Name);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectScalarVariable_GetMemberBySemantic(/* ID3D10EffectScalarVariable */ void *this, LPCSTR Semantic);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectScalarVariable_GetElement(/* ID3D10EffectScalarVariable */ void *this, UINT Index);
WINAPI /* ID3D10EffectConstantBuffer */ void *ID3D10EffectScalarVariable_GetParentConstantBuffer(/* ID3D10EffectScalarVariable */ void *this);
WINAPI /* ID3D10EffectScalarVariable */ void *ID3D10EffectScalarVariable_AsScalar(/* ID3D10EffectScalarVariable */ void *this);
WINAPI /* ID3D10EffectVectorVariable */ void *ID3D10EffectScalarVariable_AsVector(/* ID3D10EffectScalarVariable */ void *this);
WINAPI /* ID3D10EffectMatrixVariable */ void *ID3D10EffectScalarVariable_AsMatrix(/* ID3D10EffectScalarVariable */ void *this);
WINAPI /* ID3D10EffectStringVariable */ void *ID3D10EffectScalarVariable_AsString(/* ID3D10EffectScalarVariable */ void *this);
WINAPI /* ID3D10EffectShaderResourceVariable */ void *ID3D10EffectScalarVariable_AsShaderResource(/* ID3D10EffectScalarVariable */ void *this);
WINAPI /* ID3D10EffectRenderTargetViewVariable */ void *ID3D10EffectScalarVariable_AsRenderTargetView(/* ID3D10EffectScalarVariable */ void *this);
WINAPI /* ID3D10EffectDepthStencilViewVariable */ void *ID3D10EffectScalarVariable_AsDepthStencilView(/* ID3D10EffectScalarVariable */ void *this);
WINAPI /* ID3D10EffectConstantBuffer */ void *ID3D10EffectScalarVariable_AsConstantBuffer(/* ID3D10EffectScalarVariable */ void *this);
WINAPI /* ID3D10EffectShaderVariable */ void *ID3D10EffectScalarVariable_AsShader(/* ID3D10EffectScalarVariable */ void *this);
WINAPI /* ID3D10EffectBlendVariable */ void *ID3D10EffectScalarVariable_AsBlend(/* ID3D10EffectScalarVariable */ void *this);
WINAPI /* ID3D10EffectDepthStencilVariable */ void *ID3D10EffectScalarVariable_AsDepthStencil(/* ID3D10EffectScalarVariable */ void *this);
WINAPI /* ID3D10EffectRasterizerVariable */ void *ID3D10EffectScalarVariable_AsRasterizer(/* ID3D10EffectScalarVariable */ void *this);
WINAPI /* ID3D10EffectSamplerVariable */ void *ID3D10EffectScalarVariable_AsSampler(/* ID3D10EffectScalarVariable */ void *this);
WINAPI void ID3D10EffectScalarVariable_SetRawValue(/* ID3D10EffectScalarVariable */ void *this, void *pData, UINT ByteOffset, UINT ByteCount);
WINAPI void ID3D10EffectScalarVariable_GetRawValue(/* ID3D10EffectScalarVariable */ void *this, void *pData, UINT ByteOffset, UINT ByteCount);
WINAPI void ID3D10EffectScalarVariable_SetFloat(/* ID3D10EffectScalarVariable */ void *this, float Value);
WINAPI void ID3D10EffectScalarVariable_GetFloat(/* ID3D10EffectScalarVariable */ void *this, float *pValue);
WINAPI void ID3D10EffectScalarVariable_SetFloatArray(/* ID3D10EffectScalarVariable */ void *this, float *pData, UINT Offset, UINT Count);
WINAPI void ID3D10EffectScalarVariable_GetFloatArray(/* ID3D10EffectScalarVariable */ void *this, float *pData, UINT Offset, UINT Count);
WINAPI void ID3D10EffectScalarVariable_SetInt(/* ID3D10EffectScalarVariable */ void *this, int Value);
WINAPI void ID3D10EffectScalarVariable_GetInt(/* ID3D10EffectScalarVariable */ void *this, int *pValue);
WINAPI void ID3D10EffectScalarVariable_SetIntArray(/* ID3D10EffectScalarVariable */ void *this, int *pData, UINT Offset, UINT Count);
WINAPI void ID3D10EffectScalarVariable_GetIntArray(/* ID3D10EffectScalarVariable */ void *this, int *pData, UINT Offset, UINT Count);
WINAPI void ID3D10EffectScalarVariable_SetBool(/* ID3D10EffectScalarVariable */ void *this, BOOL Value);
WINAPI void ID3D10EffectScalarVariable_GetBool(/* ID3D10EffectScalarVariable */ void *this, BOOL *pValue);
WINAPI void ID3D10EffectScalarVariable_SetBoolArray(/* ID3D10EffectScalarVariable */ void *this, BOOL *pData, UINT Offset, UINT Count);
WINAPI void ID3D10EffectScalarVariable_GetBoolArray(/* ID3D10EffectScalarVariable */ void *this, BOOL *pData, UINT Offset, UINT Count);

/* EffectShaderResourceVariable.c */

WINAPI BOOL ID3D10EffectShaderResourceVariable_IsValid(/* ID3D10EffectShaderResourceVariable */ void *this);
WINAPI /* ID3D10EffectType */ void *ID3D10EffectShaderResourceVariable_GetType(/* ID3D10EffectShaderResourceVariable */ void *this);
WINAPI void ID3D10EffectShaderResourceVariable_GetDesc(/* ID3D10EffectShaderResourceVariable */ void *this, D3D10_EFFECT_VARIABLE_DESC *pDesc);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectShaderResourceVariable_GetAnnotationByIndex(/* ID3D10EffectShaderResourceVariable */ void *this, UINT Index);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectShaderResourceVariable_GetAnnotationByName(/* ID3D10EffectShaderResourceVariable */ void *this, LPCSTR Name);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectShaderResourceVariable_GetMemberByIndex(/* ID3D10EffectShaderResourceVariable */ void *this, UINT Index);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectShaderResourceVariable_GetMemberByName(/* ID3D10EffectShaderResourceVariable */ void *this, LPCSTR Name);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectShaderResourceVariable_GetMemberBySemantic(/* ID3D10EffectShaderResourceVariable */ void *this, LPCSTR Semantic);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectShaderResourceVariable_GetElement(/* ID3D10EffectShaderResourceVariable */ void *this, UINT Index);
WINAPI /* ID3D10EffectConstantBuffer */ void *ID3D10EffectShaderResourceVariable_GetParentConstantBuffer(/* ID3D10EffectShaderResourceVariable */ void *this);
WINAPI /* ID3D10EffectScalarVariable */ void *ID3D10EffectShaderResourceVariable_AsScalar(/* ID3D10EffectShaderResourceVariable */ void *this);
WINAPI /* ID3D10EffectVectorVariable */ void *ID3D10EffectShaderResourceVariable_AsVector(/* ID3D10EffectShaderResourceVariable */ void *this);
WINAPI /* ID3D10EffectMatrixVariable */ void *ID3D10EffectShaderResourceVariable_AsMatrix(/* ID3D10EffectShaderResourceVariable */ void *this);
WINAPI /* ID3D10EffectStringVariable */ void *ID3D10EffectShaderResourceVariable_AsString(/* ID3D10EffectShaderResourceVariable */ void *this);
WINAPI /* ID3D10EffectShaderResourceVariable */ void *ID3D10EffectShaderResourceVariable_AsShaderResource(/* ID3D10EffectShaderResourceVariable */ void *this);
WINAPI /* ID3D10EffectRenderTargetViewVariable */ void *ID3D10EffectShaderResourceVariable_AsRenderTargetView(/* ID3D10EffectShaderResourceVariable */ void *this);
WINAPI /* ID3D10EffectDepthStencilViewVariable */ void *ID3D10EffectShaderResourceVariable_AsDepthStencilView(/* ID3D10EffectShaderResourceVariable */ void *this);
WINAPI /* ID3D10EffectConstantBuffer */ void *ID3D10EffectShaderResourceVariable_AsConstantBuffer(/* ID3D10EffectShaderResourceVariable */ void *this);
WINAPI /* ID3D10EffectShaderVariable */ void *ID3D10EffectShaderResourceVariable_AsShader(/* ID3D10EffectShaderResourceVariable */ void *this);
WINAPI /* ID3D10EffectBlendVariable */ void *ID3D10EffectShaderResourceVariable_AsBlend(/* ID3D10EffectShaderResourceVariable */ void *this);
WINAPI /* ID3D10EffectDepthStencilVariable */ void *ID3D10EffectShaderResourceVariable_AsDepthStencil(/* ID3D10EffectShaderResourceVariable */ void *this);
WINAPI /* ID3D10EffectRasterizerVariable */ void *ID3D10EffectShaderResourceVariable_AsRasterizer(/* ID3D10EffectShaderResourceVariable */ void *this);
WINAPI /* ID3D10EffectSamplerVariable */ void *ID3D10EffectShaderResourceVariable_AsSampler(/* ID3D10EffectShaderResourceVariable */ void *this);
WINAPI void ID3D10EffectShaderResourceVariable_SetRawValue(/* ID3D10EffectShaderResourceVariable */ void *this, void *pData, UINT Offset, UINT Count);
WINAPI void ID3D10EffectShaderResourceVariable_GetRawValue(/* ID3D10EffectShaderResourceVariable */ void *this, void *pData, UINT Offset, UINT Count);
WINAPI void ID3D10EffectShaderResourceVariable_SetResource(/* ID3D10EffectShaderResourceVariable */ void *this, /* ID3D10ShaderResourceView */ void *pResource);
WINAPI void ID3D10EffectShaderResourceVariable_GetResource(/* ID3D10EffectShaderResourceVariable */ void *this, /* ID3D10ShaderResourceView */ void **ppResource);
WINAPI void ID3D10EffectShaderResourceVariable_SetResourceArray(/* ID3D10EffectShaderResourceVariable */ void *this, /* ID3D10ShaderResourceView */ void **ppResources, UINT Offset, UINT Count);
WINAPI void ID3D10EffectShaderResourceVariable_GetResourceArray(/* ID3D10EffectShaderResourceVariable */ void *this, /* ID3D10ShaderResourceView */ void **ppResources, UINT Offset, UINT Count);

/* EffectVectorVariable.c */

WINAPI BOOL ID3D10EffectVectorVariable_IsValid(/* ID3D10EffectVectorVariable */ void *this);
WINAPI /* ID3D10EffectType */ void *ID3D10EffectVectorVariable_GetType(/* ID3D10EffectVectorVariable */ void *this);
WINAPI void ID3D10EffectVectorVariable_GetDesc(/* ID3D10EffectVectorVariable */ void *this, D3D10_EFFECT_VARIABLE_DESC *pDesc);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectVectorVariable_GetAnnotationByIndex(/* ID3D10EffectVectorVariable */ void *this, UINT Index);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectVectorVariable_GetAnnotationByName(/* ID3D10EffectVectorVariable */ void *this, LPCSTR Name);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectVectorVariable_GetMemberByIndex(/* ID3D10EffectVectorVariable */ void *this, UINT Index);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectVectorVariable_GetMemberByName(/* ID3D10EffectVectorVariable */ void *this, LPCSTR Name);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectVectorVariable_GetMemberBySemantic(/* ID3D10EffectVectorVariable */ void *this, LPCSTR Semantic);
WINAPI /* ID3D10EffectVariable */ void *ID3D10EffectVectorVariable_GetElement(/* ID3D10EffectVectorVariable */ void *this, UINT Index);
WINAPI /* ID3D10EffectConstantBuffer */ void *ID3D10EffectVectorVariable_GetParentConstantBuffer(/* ID3D10EffectVectorVariable */ void *this);
WINAPI /* ID3D10EffectScalarVariable */ void *ID3D10EffectVectorVariable_AsScalar(/* ID3D10EffectVectorVariable */ void *this);
WINAPI /* ID3D10EffectVectorVariable */ void *ID3D10EffectVectorVariable_AsVector(/* ID3D10EffectVectorVariable */ void *this);
WINAPI /* ID3D10EffectMatrixVariable */ void *ID3D10EffectVectorVariable_AsMatrix(/* ID3D10EffectVectorVariable */ void *this);
WINAPI /* ID3D10EffectStringVariable */ void *ID3D10EffectVectorVariable_AsString(/* ID3D10EffectVectorVariable */ void *this);
WINAPI /* ID3D10EffectShaderResourceVariable */ void *ID3D10EffectVectorVariable_AsShaderResource(/* ID3D10EffectVectorVariable */ void *this);
WINAPI /* ID3D10EffectRenderTargetViewVariable */ void *ID3D10EffectVectorVariable_AsRenderTargetView(/* ID3D10EffectVectorVariable */ void *this);
WINAPI /* ID3D10EffectDepthStencilViewVariable */ void *ID3D10EffectVectorVariable_AsDepthStencilView(/* ID3D10EffectVectorVariable */ void *this);
WINAPI /* ID3D10EffectConstantBuffer */ void *ID3D10EffectVectorVariable_AsConstantBuffer(/* ID3D10EffectVectorVariable */ void *this);
WINAPI /* ID3D10EffectShaderVariable */ void *ID3D10EffectVectorVariable_AsShader(/* ID3D10EffectVectorVariable */ void *this);
WINAPI /* ID3D10EffectBlendVariable */ void *ID3D10EffectVectorVariable_AsBlend(/* ID3D10EffectVectorVariable */ void *this);
WINAPI /* ID3D10EffectDepthStencilVariable */ void *ID3D10EffectVectorVariable_AsDepthStencil(/* ID3D10EffectVectorVariable */ void *this);
WINAPI /* ID3D10EffectRasterizerVariable */ void *ID3D10EffectVectorVariable_AsRasterizer(/* ID3D10EffectVectorVariable */ void *this);
WINAPI /* ID3D10EffectSamplerVariable */ void *ID3D10EffectVectorVariable_AsSampler(/* ID3D10EffectVectorVariable */ void *this);
WINAPI void ID3D10EffectVectorVariable_SetRawValue(/* ID3D10EffectVectorVariable */ void *this, void *pData, UINT ByteOffset, UINT ByteCount);
WINAPI void ID3D10EffectVectorVariable_GetRawValue(/* ID3D10EffectVectorVariable */ void *this, void *pData, UINT ByteOffset, UINT ByteCount);
WINAPI void ID3D10EffectVectorVariable_SetBoolVector(/* ID3D10EffectVectorVariable */ void *this, BOOL *pData);
WINAPI void ID3D10EffectVectorVariable_SetIntVector(/* ID3D10EffectVectorVariable */ void *this, int *pData);
WINAPI void ID3D10EffectVectorVariable_SetFloatVector(/* ID3D10EffectVectorVariable */ void *this, float *pData);
WINAPI void ID3D10EffectVectorVariable_GetBoolVector(/* ID3D10EffectVectorVariable */ void *this, BOOL *pData);
WINAPI void ID3D10EffectVectorVariable_GetIntVector(/* ID3D10EffectVectorVariable */ void *this, int *pData);
WINAPI void ID3D10EffectVectorVariable_GetFloatVector(/* ID3D10EffectVectorVariable */ void *this, float *pData);
WINAPI void ID3D10EffectVectorVariable_SetBoolVectorArray(/* ID3D10EffectVectorVariable */ void *this, BOOL *pData, UINT Offset, UINT Count);
WINAPI void ID3D10EffectVectorVariable_SetIntVectorArray(/* ID3D10EffectVectorVariable */ void *this, int *pData, UINT Offset, UINT Count);
WINAPI void ID3D10EffectVectorVariable_SetFloatVectorArray(/* ID3D10EffectVectorVariable */ void *this, float *pData, UINT Offset, UINT Count);
WINAPI void ID3D10EffectVectorVariable_GetBoolVectorArray(/* ID3D10EffectVectorVariable */ void *this, BOOL *pData, UINT Offset, UINT Count);
WINAPI void ID3D10EffectVectorVariable_GetIntVectorArray(/* ID3D10EffectVectorVariable */ void *this, int *pData, UINT Offset, UINT Count);
WINAPI void ID3D10EffectVectorVariable_GetFloatVectorArray(/* ID3D10EffectVectorVariable */ void *this, float *pData, UINT Offset, UINT Count);

/* ShaderResourceView.c */

WINAPI /* ID3D10ShaderResourceView */ void *D3D10_CreateShaderResourceView();
WINAPI /* ID3D10ShaderResourceView */ void *D3D10_CreateShaderResourceViewFromDDS(DDS *dds);

WINAPI HRESULT ID3D10ShaderResourceView_QueryInterface(/* ID3D10ShaderResourceView */ void * this_, REFIID riid, void **ppvObject);
WINAPI ULONG ID3D10ShaderResourceView_AddRef(/* ID3D10ShaderResourceView */ void * this_);
WINAPI ULONG ID3D10ShaderResourceView_Release(/* ID3D10ShaderResourceView */ void * this_);
WINAPI void ID3D10ShaderResourceView_GetDevice(/* ID3D10ShaderResourceView */ void * this_, /* ID3D10Device */ void **ppDevice);
WINAPI HRESULT ID3D10ShaderResourceView_GetPrivateData(/* ID3D10ShaderResourceView */ void * this_, REFGUID guid, UINT *pDataSize, void *pData);
WINAPI HRESULT ID3D10ShaderResourceView_SetPrivateData(/* ID3D10ShaderResourceView */ void * this_, REFGUID guid, UINT DataSize, const void *pData);
WINAPI HRESULT ID3D10ShaderResourceView_SetPrivateDataInterface(/* ID3D10ShaderResourceView */ void * this_, REFGUID guid, const /* IUnknown */ void *pData);
WINAPI void ID3D10ShaderResourceView_GetResource(/* ID3D10ShaderResourceView */ void * this_, /* ID3D10Resource */ void **ppResource);
WINAPI void ID3D10ShaderResourceView_GetDesc(/* ID3D10ShaderResourceView */ void * this_, D3D10_SHADER_RESOURCE_VIEW_DESC *pDesc);

/* StateBlock.c */

WINAPI HRESULT D3D10CreateStateBlock(
  /* ID3D10Device */ void *pDevice,
  D3D10_STATE_BLOCK_MASK *pStateBlockMask,
  /* ID3D10StateBlock */ void **ppStateBlock
);

WINAPI HRESULT ID3D10StateBlock_QueryInterface(/* ID3D10StateBlock */ void *this, REFIID iid, LPVOID **ppvObject);
WINAPI ULONG ID3D10StateBlock_AddRef(/* ID3D10StateBlock */ void *this);
WINAPI ULONG ID3D10StateBlock_Release(/* ID3D10StateBlock */ void *this);
WINAPI HRESULT ID3D10StateBlock_Capture(/* ID3D10StateBlock */ void *this);
WINAPI HRESULT ID3D10StateBlock_Apply(/* ID3D10StateBlock */ void *this);
WINAPI void ID3D10StateBlock_ReleaseAllDeviceObjects(/* ID3D10StateBlock */ void *this);
WINAPI void ID3D10StateBlock_GetDevice(/* ID3D10StateBlock */ void *this, /* ID3D10Device */ void **ppDevice);

/* Texture.c */

WINAPI /* ID3D10Texture1D */ void *D3D10_CreateTexture1D(
	D3D10_TEXTURE1D_DESC *pDesc,
	D3D10_SUBRESOURCE_DATA *pInitialData
);

WINAPI HRESULT ID3D10Texture1D_QueryInterface(/* ID3D10Texture1D */ void * this_, REFIID riid, void **ppvObject);
WINAPI ULONG ID3D10Texture1D_AddRef(/* ID3D10Texture1D */ void * this_);
WINAPI ULONG ID3D10Texture1D_Release(/* ID3D10Texture1D */ void * this_);
WINAPI void ID3D10Texture1D_GetDevice(/* ID3D10Texture1D */ void * this_, /* ID3D10Device */ void **ppDevice);
WINAPI HRESULT ID3D10Texture1D_GetPrivateData(/* ID3D10Texture1D */ void * this_, REFGUID guid, UINT *pDataSize, void *pData);
WINAPI HRESULT ID3D10Texture1D_SetPrivateData(/* ID3D10Texture1D */ void * this_, REFGUID guid, UINT DataSize, const void *pData);
WINAPI HRESULT ID3D10Texture1D_SetPrivateDataInterface(/* ID3D10Texture1D */ void * this_, REFGUID guid, const /* IUnknown */ void *pData);
WINAPI void ID3D10Texture1D_GetType(/* ID3D10Texture1D */ void * this_, D3D10_RESOURCE_DIMENSION *rType);
WINAPI void ID3D10Texture1D_SetEvictionPriority(/* ID3D10Texture1D */ void * this_, UINT EvictionPriority);
WINAPI UINT ID3D10Texture1D_GetEvictionPriority(/* ID3D10Texture1D */ void * this_);
WINAPI HRESULT ID3D10Texture1D_Map(/* ID3D10Texture1D */ void * this_, UINT Subresource, D3D10_MAP MapType, UINT MapFlags, void **ppData);
WINAPI void ID3D10Texture1D_Unmap(/* ID3D10Texture1D */ void * this_, UINT Subresource);
WINAPI void ID3D10Texture1D_GetDesc(/* ID3D10Texture1D */ void * this_, D3D10_TEXTURE1D_DESC *pDesc);

WINAPI /* ID3D10Texture2D */ void *D3D10_CreateTexture2D(
	D3D10_TEXTURE2D_DESC *pDesc,
	D3D10_SUBRESOURCE_DATA *pInitialData
);

WINAPI /* ID3D10Texture2D */ void *D3D10_CreateTexture2DFromDDS(
	DDS *dds
);

WINAPI HRESULT ID3D10Texture2D_QueryInterface(/* ID3D10Texture2D */ void * this_, REFIID riid, void **ppvObject);
WINAPI ULONG ID3D10Texture2D_AddRef(/* ID3D10Texture2D */ void * this_);
WINAPI ULONG ID3D10Texture2D_Release(/* ID3D10Texture2D */ void * this_);
WINAPI void ID3D10Texture2D_GetDevice(/* ID3D10Texture2D */ void * this_, /* ID3D10Device */ void **ppDevice);
WINAPI HRESULT ID3D10Texture2D_GetPrivateData(/* ID3D10Texture2D */ void * this_, REFGUID guid, UINT *pDataSize, void *pData);
WINAPI HRESULT ID3D10Texture2D_SetPrivateData(/* ID3D10Texture2D */ void * this_, REFGUID guid, UINT DataSize, const void *pData);
WINAPI HRESULT ID3D10Texture2D_SetPrivateDataInterface(/* ID3D10Texture2D */ void * this_, REFGUID guid, const /* IUnknown */ void *pData);
WINAPI void ID3D10Texture2D_GetType(/* ID3D10Texture2D */ void * this_, D3D10_RESOURCE_DIMENSION *rType);
WINAPI void ID3D10Texture2D_SetEvictionPriority(/* ID3D10Texture2D */ void * this_, UINT EvictionPriority);
WINAPI UINT ID3D10Texture2D_GetEvictionPriority(/* ID3D10Texture2D */ void * this_);
WINAPI HRESULT ID3D10Texture2D_Map(/* ID3D10Texture2D */ void * this_, UINT Subresource, D3D10_MAP MapType, UINT MapFlags, D3D10_MAPPED_TEXTURE2D *pMappedTex2D);
WINAPI void ID3D10Texture2D_Unmap(/* ID3D10Texture2D */ void * this_, UINT Subresource);
WINAPI void ID3D10Texture2D_GetDesc(/* ID3D10Texture2D */ void * this_, D3D10_TEXTURE2D_DESC *pDesc);

#endif
