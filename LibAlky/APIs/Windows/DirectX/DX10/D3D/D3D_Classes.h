/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
 */

#ifndef __API_WINDOWS_DIRECTX_DXTEN_DTHREED_DTHREED_CLASSES_H__
#define __API_WINDOWS_DIRECTX_DXTEN_DTHREED_DTHREED_CLASSES_H__

#include <APIs/Windows/Windows.h>
#include <APIs/Windows/COM/COM.h>

CLASS(
	ID3D10Buffer,
	STRUCT(
		unsigned int size;
		void *buffer;
	),
	VTABLE(
		CSTUB(ID3D10Buffer_QueryInterface),
		CSTUB(ID3D10Buffer_AddRef),
		CSTUB(ID3D10Buffer_Release),
		CSTUB(ID3D10Buffer_GetDevice),
		CSTUB(ID3D10Buffer_GetPrivateData),
		CSTUB(ID3D10Buffer_SetPrivateData),
		CSTUB(ID3D10Buffer_SetPrivateDataInterface),
		CSTUB(ID3D10Buffer_GetType),
		CSTUB(ID3D10Buffer_SetEvictionPriority),
		CSTUB(ID3D10Buffer_GetEvictionPriority),
		CSTUB(ID3D10Buffer_Map),
		CSTUB(ID3D10Buffer_Unmap),
		CSTUB(ID3D10Buffer_GetDesc)
	)
);

CLASS(
	ID3D10Device,
	STRUCT(
		NuRender_Device *device;
		
		unsigned int vertexWidth;
		/* ID3D10Buffer */ void *vertices;
		DXGI_FORMAT indexFormat;
		/* ID3D10Buffer */ void *indices;
		
		D3D10_PRIMITIVE_TOPOLOGY topology;
	),
	VTABLE(
		CSTUB(ID3D10Device_QueryInterface),
		CSTUB(ID3D10Device_AddRef),
		CMEMBER(ID3D10Device_Release),
		CSTUB(ID3D10Device_VSSetConstantBuffers),
		CSTUB(ID3D10Device_PSSetShaderResources),
		CSTUB(ID3D10Device_PSSetShader),
		CSTUB(ID3D10Device_PSSetSamplers),
		CSTUB(ID3D10Device_VSSetShader),
		CMEMBER(ID3D10Device_DrawIndexed),
		CMEMBER(ID3D10Device_Draw),
		CSTUB(ID3D10Device_PSSetConstantBuffers),
		CMEMBER(ID3D10Device_IASetInputLayout),
		CMEMBER(ID3D10Device_IASetVertexBuffers),
		CMEMBER(ID3D10Device_IASetIndexBuffer),
		CSTUB(ID3D10Device_DrawIndexedInstanced),
		CSTUB(ID3D10Device_DrawInstanced),
		CSTUB(ID3D10Device_GSSetConstantBuffers),
		CSTUB(ID3D10Device_GSSetShader),
		CMEMBER(ID3D10Device_IASetPrimitiveTopology),
		CSTUB(ID3D10Device_VSSetShaderResources),
		CSTUB(ID3D10Device_VSSetSamplers),
		CSTUB(ID3D10Device_SetPredication),
		CSTUB(ID3D10Device_GSSetShaderResources),
		CSTUB(ID3D10Device_GSSetSamplers),
		CMEMBER(ID3D10Device_OMSetRenderTargets),
		CSTUB(ID3D10Device_OMSetBlendState),
		CSTUB(ID3D10Device_OMSetDepthStencilState),
		CMEMBER(ID3D10Device_SOSetTargets),
		CSTUB(ID3D10Device_DrawAuto),
		CSTUB(ID3D10Device_RSSetState),
		CMEMBER(ID3D10Device_RSSetViewports),
		CSTUB(ID3D10Device_RSSetScissorRects),
		CSTUB(ID3D10Device_CopySubresourceRegion),
		CSTUB(ID3D10Device_CopyResource),
		CSTUB(ID3D10Device_UpdateSubresource),
		CMEMBER(ID3D10Device_ClearRenderTargetView),
		CMEMBER(ID3D10Device_ClearDepthStencilView),
		CSTUB(ID3D10Device_GenerateMips),
		CSTUB(ID3D10Device_ResolveSubresource),
		CSTUB(ID3D10Device_VSGetConstantBuffers),
		CSTUB(ID3D10Device_PSGetShaderResources),
		CSTUB(ID3D10Device_PSGetShader),
		CSTUB(ID3D10Device_PSGetSamplers),
		CSTUB(ID3D10Device_VSGetShader),
		CSTUB(ID3D10Device_PSGetConstantBuffers),
		CSTUB(ID3D10Device_IAGetInputLayout),
		CSTUB(ID3D10Device_IAGetVertexBuffers),
		CSTUB(ID3D10Device_IAGetIndexBuffer),
		CSTUB(ID3D10Device_GSGetConstantBuffers),
		CSTUB(ID3D10Device_GSGetShader),
		CSTUB(ID3D10Device_IAGetPrimitiveTopology),
		CSTUB(ID3D10Device_VSGetShaderResources),
		CSTUB(ID3D10Device_VSGetSamplers),
		CSTUB(ID3D10Device_GetPredication),
		CSTUB(ID3D10Device_GSGetShaderResources),
		CSTUB(ID3D10Device_GSGetSamplers),
		CSTUB(ID3D10Device_OMGetRenderTargets),
		CSTUB(ID3D10Device_OMGetBlendState),
		CSTUB(ID3D10Device_OMGetDepthStencilState),
		CSTUB(ID3D10Device_SOGetTargets),
		CSTUB(ID3D10Device_RSGetState),
		CSTUB(ID3D10Device_RSGetViewports),
		CSTUB(ID3D10Device_RSGetScissorRects),
		CSTUB(ID3D10Device_GetDeviceRemovedReason),
		CSTUB(ID3D10Device_SetExceptionMode),
		CSTUB(ID3D10Device_GetExceptionMode),
		CSTUB(ID3D10Device_GetPrivateData),
		CSTUB(ID3D10Device_SetPrivateData),
		CSTUB(ID3D10Device_SetPrivateDataInterface),
		CSTUB(ID3D10Device_ClearState),
		CSTUB(ID3D10Device_Flush),
		CMEMBER(ID3D10Device_CreateBuffer),
		CMEMBER(ID3D10Device_CreateTexture1D),
		CMEMBER(ID3D10Device_CreateTexture2D),
		CSTUB(ID3D10Device_CreateTexture3D),
		CMEMBER(ID3D10Device_CreateShaderResourceView),
		CMEMBER(ID3D10Device_CreateRenderTargetView),
		CMEMBER(ID3D10Device_CreateDepthStencilView),
		CMEMBER(ID3D10Device_CreateInputLayout),
		CSTUB(ID3D10Device_CreateVertexShader),
		CSTUB(ID3D10Device_CreateGeometryShader),
		CSTUB(ID3D10Device_CreateGeometryShaderWithStreamOutput),
		CSTUB(ID3D10Device_CreatePixelShader),
		CSTUB(ID3D10Device_CreateBlendState),
		CMEMBER(ID3D10Device_CreateDepthStencilState),
		CMEMBER(ID3D10Device_CreateRasterizerState),
		CSTUB(ID3D10Device_CreateSamplerState),
		CSTUB(ID3D10Device_CreateQuery),
		CSTUB(ID3D10Device_CreatePredicate),
		CSTUB(ID3D10Device_CreateCounter),
		CSTUB(ID3D10Device_CheckFormatSupport),
		CMEMBER(ID3D10Device_CheckMultisampleQualityLevels),
		CSTUB(ID3D10Device_CheckCounterInfo),
		CSTUB(ID3D10Device_CheckCounter),
		CSTUB(ID3D10Device_GetCreationFlags),
		CSTUB(ID3D10Device_OpenSharedResource),
		CSTUB(ID3D10Device_SetTextFilterSize),
		CSTUB(ID3D10Device_GetTextFilterSize)
	)
);

CLASS(
	ID3D10Effect,
	STRUCT(),
	VTABLE(
		CSTUB(ID3D10Effect_QueryInterface),
		CSTUB(ID3D10Effect_AddRef),
		CMEMBER(ID3D10Effect_Release),
		CSTUB(ID3D10Effect_IsValid),
		CSTUB(ID3D10Effect_IsPool),
		CSTUB(ID3D10Effect_GetDevice),
		CSTUB(ID3D10Effect_GetDesc),
		CSTUB(ID3D10Effect_GetConstantBufferByIndex),
		CSTUB(ID3D10Effect_GetConstantBufferByName),
		CSTUB(ID3D10Effect_GetVariableByIndex),
		CMEMBER(ID3D10Effect_GetVariableByName),
		CSTUB(ID3D10Effect_GetVariableBySemantic),
		CSTUB(ID3D10Effect_GetTechniqueByIndex),
		CMEMBER(ID3D10Effect_GetTechniqueByName),
		CSTUB(ID3D10Effect_Optimize),
		CSTUB(ID3D10Effect_IsOptimized)
	)
);

CLASS(
	ID3D10EffectPass,
	STRUCT(),
	VTABLE(
		CSTUB(ID3D10EffectPass_IsValid),
		CMEMBER(ID3D10EffectPass_GetDesc),
		CSTUB(ID3D10EffectPass_GetVertexShaderDesc),
		CSTUB(ID3D10EffectPass_GetGeometryShaderDesc),
		CSTUB(ID3D10EffectPass_GetPixelShaderDesc),
		CSTUB(ID3D10EffectPass_GetAnnotationByIndex),
		CSTUB(ID3D10EffectPass_GetAnnotationByName),
		CMEMBER(ID3D10EffectPass_Apply),
		CSTUB(ID3D10EffectPass_ComputeStateBlockMask)
	)
);

CLASS(
	ID3D10EffectTechnique,
	STRUCT(),
	VTABLE(
		CSTUB(ID3D10EffectTechnique_IsValid),
		CMEMBER(ID3D10EffectTechnique_GetDesc),
		CSTUB(ID3D10EffectTechnique_GetAnnotationByIndex),
		CSTUB(ID3D10EffectTechnique_GetAnnotationByName),
		CMEMBER(ID3D10EffectTechnique_GetPassByIndex),
		CSTUB(ID3D10EffectTechnique_GetPassByName),
		CSTUB(ID3D10EffectTechnique_ComputeStateBlockMask)
	)
);

CLASS(
	ID3D10EffectVariable,
	STRUCT(
		/* ID3D10Effect */ void *Effect;
		LPSTR Name;
	),
	VTABLE(
		CSTUB(ID3D10EffectVariable_IsValid),
		CSTUB(ID3D10EffectVariable_GetType),
		CSTUB(ID3D10EffectVariable_GetDesc),
		CSTUB(ID3D10EffectVariable_GetAnnotationByIndex),
		CSTUB(ID3D10EffectVariable_GetAnnotationByName),
		CSTUB(ID3D10EffectVariable_GetMemberByIndex),
		CSTUB(ID3D10EffectVariable_GetMemberByName),
		CSTUB(ID3D10EffectVariable_GetMemberBySemantic),
		CSTUB(ID3D10EffectVariable_GetElement),
		CSTUB(ID3D10EffectVariable_GetParentConstantBuffer),
		CMEMBER(ID3D10EffectVariable_AsScalar),
		CMEMBER(ID3D10EffectVariable_AsVector),
		CMEMBER(ID3D10EffectVariable_AsMatrix),
		CSTUB(ID3D10EffectVariable_AsString),
		CMEMBER(ID3D10EffectVariable_AsShaderResource),
		CSTUB(ID3D10EffectVariable_AsRenderTargetView),
		CSTUB(ID3D10EffectVariable_AsDepthStencilView),
		CSTUB(ID3D10EffectVariable_AsConstantBuffer),
		CSTUB(ID3D10EffectVariable_AsShader),
		CSTUB(ID3D10EffectVariable_AsBlend),
		CSTUB(ID3D10EffectVariable_AsDepthStencil),
		CSTUB(ID3D10EffectVariable_AsRasterizer),
		CSTUB(ID3D10EffectVariable_AsSampler),
		CSTUB(ID3D10EffectVariable_SetRawValue),
		CSTUB(ID3D10EffectVariable_GetRawValue)
	)
);

CLASS(
	ID3D10EffectMatrixVariable,
	STRUCT(
		/* ID3D10Effect */ void *Effect;
		LPSTR Name;
		
		D3DXMATRIX Matrix;
	),
	VTABLE(
		CSTUB(ID3D10EffectMatrixVariable_IsValid),
		CSTUB(ID3D10EffectMatrixVariable_GetType),
		CSTUB(ID3D10EffectMatrixVariable_GetDesc),
		CSTUB(ID3D10EffectMatrixVariable_GetAnnotationByIndex),
		CSTUB(ID3D10EffectMatrixVariable_GetAnnotationByName),
		CSTUB(ID3D10EffectMatrixVariable_GetMemberByIndex),
		CSTUB(ID3D10EffectMatrixVariable_GetMemberByName),
		CSTUB(ID3D10EffectMatrixVariable_GetMemberBySemantic),
		CSTUB(ID3D10EffectMatrixVariable_GetElement),
		CSTUB(ID3D10EffectMatrixVariable_GetParentConstantBuffer),
		CSTUB(ID3D10EffectMatrixVariable_AsScalar),
		CSTUB(ID3D10EffectMatrixVariable_AsVector),
		CSTUB(ID3D10EffectMatrixVariable_AsMatrix),
		CSTUB(ID3D10EffectMatrixVariable_AsString),
		CSTUB(ID3D10EffectMatrixVariable_AsShaderResource),
		CSTUB(ID3D10EffectMatrixVariable_AsRenderTargetView),
		CSTUB(ID3D10EffectMatrixVariable_AsDepthStencilView),
		CSTUB(ID3D10EffectMatrixVariable_AsConstantBuffer),
		CSTUB(ID3D10EffectMatrixVariable_AsShader),
		CSTUB(ID3D10EffectMatrixVariable_AsBlend),
		CSTUB(ID3D10EffectMatrixVariable_AsDepthStencil),
		CSTUB(ID3D10EffectMatrixVariable_AsRasterizer),
		CSTUB(ID3D10EffectMatrixVariable_AsSampler),
		CSTUB(ID3D10EffectMatrixVariable_SetRawValue),
		CSTUB(ID3D10EffectMatrixVariable_GetRawValue),
		CMEMBER(ID3D10EffectMatrixVariable_SetMatrix),
		CSTUB(ID3D10EffectMatrixVariable_GetMatrix),
		CMEMBER(ID3D10EffectMatrixVariable_SetMatrixArray),
		CSTUB(ID3D10EffectMatrixVariable_GetMatrixArray),
		CSTUB(ID3D10EffectMatrixVariable_SetMatrixTranspose),
		CSTUB(ID3D10EffectMatrixVariable_GetMatrixTranspose),
		CSTUB(ID3D10EffectMatrixVariable_SetMatrixTransposeArray),
		CSTUB(ID3D10EffectMatrixVariable_GetMatrixTransposeArray)
	)
);

CLASS(
	ID3D10EffectScalarVariable,
	STRUCT(
		/* ID3D10Effect */ void *Effect;
		LPSTR Name;
		
		float Value;
	),
	VTABLE(
		CSTUB(ID3D10EffectScalarVariable_IsValid),
		CSTUB(ID3D10EffectScalarVariable_GetType),
		CSTUB(ID3D10EffectScalarVariable_GetDesc),
		CSTUB(ID3D10EffectScalarVariable_GetAnnotationByIndex),
		CSTUB(ID3D10EffectScalarVariable_GetAnnotationByName),
		CSTUB(ID3D10EffectScalarVariable_GetMemberByIndex),
		CSTUB(ID3D10EffectScalarVariable_GetMemberByName),
		CSTUB(ID3D10EffectScalarVariable_GetMemberBySemantic),
		CSTUB(ID3D10EffectScalarVariable_GetElement),
		CSTUB(ID3D10EffectScalarVariable_GetParentConstantBuffer),
		CSTUB(ID3D10EffectScalarVariable_AsScalar),
		CSTUB(ID3D10EffectScalarVariable_AsVector),
		CSTUB(ID3D10EffectScalarVariable_AsMatrix),
		CSTUB(ID3D10EffectScalarVariable_AsString),
		CSTUB(ID3D10EffectScalarVariable_AsShaderResource),
		CSTUB(ID3D10EffectScalarVariable_AsRenderTargetView),
		CSTUB(ID3D10EffectScalarVariable_AsDepthStencilView),
		CSTUB(ID3D10EffectScalarVariable_AsConstantBuffer),
		CSTUB(ID3D10EffectScalarVariable_AsShader),
		CSTUB(ID3D10EffectScalarVariable_AsBlend),
		CSTUB(ID3D10EffectScalarVariable_AsDepthStencil),
		CSTUB(ID3D10EffectScalarVariable_AsRasterizer),
		CSTUB(ID3D10EffectScalarVariable_AsSampler),
		CSTUB(ID3D10EffectScalarVariable_SetRawValue),
		CSTUB(ID3D10EffectScalarVariable_GetRawValue),
		CSTUB(ID3D10EffectScalarVariable_SetFloat),
		CSTUB(ID3D10EffectScalarVariable_GetFloat),
		CSTUB(ID3D10EffectScalarVariable_SetFloatArray),
		CSTUB(ID3D10EffectScalarVariable_GetFloatArray),
		CSTUB(ID3D10EffectScalarVariable_SetInt),
		CSTUB(ID3D10EffectScalarVariable_GetInt),
		CSTUB(ID3D10EffectScalarVariable_SetIntArray),
		CSTUB(ID3D10EffectScalarVariable_GetIntArray),
		CSTUB(ID3D10EffectScalarVariable_SetBool),
		CSTUB(ID3D10EffectScalarVariable_GetBool),
		CSTUB(ID3D10EffectScalarVariable_SetBoolArray),
		CSTUB(ID3D10EffectScalarVariable_GetBoolArray)
	)
);

CLASS(
	ID3D10EffectShaderResourceVariable,
	STRUCT(
		/* ID3D10Effect */ void *Effect;
		LPSTR Name;	
	),
	VTABLE(
		CSTUB(ID3D10EffectShaderResourceVariable_IsValid),
		CSTUB(ID3D10EffectShaderResourceVariable_GetType),
		CSTUB(ID3D10EffectShaderResourceVariable_GetDesc),
		CSTUB(ID3D10EffectShaderResourceVariable_GetAnnotationByIndex),
		CSTUB(ID3D10EffectShaderResourceVariable_GetAnnotationByName),
		CSTUB(ID3D10EffectShaderResourceVariable_GetMemberByIndex),
		CSTUB(ID3D10EffectShaderResourceVariable_GetMemberByName),
		CSTUB(ID3D10EffectShaderResourceVariable_GetMemberBySemantic),
		CSTUB(ID3D10EffectShaderResourceVariable_GetElement),
		CSTUB(ID3D10EffectShaderResourceVariable_GetParentConstantBuffer),
		CSTUB(ID3D10EffectShaderResourceVariable_AsScalar),
		CSTUB(ID3D10EffectShaderResourceVariable_AsVector),
		CSTUB(ID3D10EffectShaderResourceVariable_AsMatrix),
		CSTUB(ID3D10EffectShaderResourceVariable_AsString),
		CSTUB(ID3D10EffectShaderResourceVariable_AsShaderResource),
		CSTUB(ID3D10EffectShaderResourceVariable_AsRenderTargetView),
		CSTUB(ID3D10EffectShaderResourceVariable_AsDepthStencilView),
		CSTUB(ID3D10EffectShaderResourceVariable_AsConstantBuffer),
		CSTUB(ID3D10EffectShaderResourceVariable_AsShader),
		CSTUB(ID3D10EffectShaderResourceVariable_AsBlend),
		CSTUB(ID3D10EffectShaderResourceVariable_AsDepthStencil),
		CSTUB(ID3D10EffectShaderResourceVariable_AsRasterizer),
		CSTUB(ID3D10EffectShaderResourceVariable_AsSampler),
		CSTUB(ID3D10EffectShaderResourceVariable_SetRawValue),
		CSTUB(ID3D10EffectShaderResourceVariable_GetRawValue),
		CMEMBER(ID3D10EffectShaderResourceVariable_SetResource),
		CSTUB(ID3D10EffectShaderResourceVariable_GetResource),
		CSTUB(ID3D10EffectShaderResourceVariable_SetResourceArray),
		CSTUB(ID3D10EffectShaderResourceVariable_GetResourceArray)
	)
);

CLASS(
	ID3D10EffectVectorVariable,
	STRUCT(
		/* ID3D10Effect */ void *Effect;
		LPSTR Name;
		
		D3DXVECTOR4 Vector;
	),
	VTABLE(
		CSTUB(ID3D10EffectVectorVariable_IsValid),
		CSTUB(ID3D10EffectVectorVariable_GetType),
		CSTUB(ID3D10EffectVectorVariable_GetDesc),
		CSTUB(ID3D10EffectVectorVariable_GetAnnotationByIndex),
		CSTUB(ID3D10EffectVectorVariable_GetAnnotationByName),
		CSTUB(ID3D10EffectVectorVariable_GetMemberByIndex),
		CSTUB(ID3D10EffectVectorVariable_GetMemberByName),
		CSTUB(ID3D10EffectVectorVariable_GetMemberBySemantic),
		CSTUB(ID3D10EffectVectorVariable_GetElement),
		CSTUB(ID3D10EffectVectorVariable_GetParentConstantBuffer),
		CSTUB(ID3D10EffectVectorVariable_AsScalar),
		CSTUB(ID3D10EffectVectorVariable_AsVector),
		CSTUB(ID3D10EffectVectorVariable_AsMatrix),
		CSTUB(ID3D10EffectVectorVariable_AsString),
		CSTUB(ID3D10EffectVectorVariable_AsShaderResource),
		CSTUB(ID3D10EffectVectorVariable_AsRenderTargetView),
		CSTUB(ID3D10EffectVectorVariable_AsDepthStencilView),
		CSTUB(ID3D10EffectVectorVariable_AsConstantBuffer),
		CSTUB(ID3D10EffectVectorVariable_AsShader),
		CSTUB(ID3D10EffectVectorVariable_AsBlend),
		CSTUB(ID3D10EffectVectorVariable_AsDepthStencil),
		CSTUB(ID3D10EffectVectorVariable_AsRasterizer),
		CSTUB(ID3D10EffectVectorVariable_AsSampler),
		CSTUB(ID3D10EffectVectorVariable_SetRawValue),
		CSTUB(ID3D10EffectVectorVariable_GetRawValue),
		CSTUB(ID3D10EffectVectorVariable_SetBoolVector),
		CSTUB(ID3D10EffectVectorVariable_SetIntVector),
		CMEMBER(ID3D10EffectVectorVariable_SetFloatVector),
		CSTUB(ID3D10EffectVectorVariable_GetBoolVector),
		CSTUB(ID3D10EffectVectorVariable_GetIntVector),
		CSTUB(ID3D10EffectVectorVariable_GetFloatVector),
		CSTUB(ID3D10EffectVectorVariable_SetBoolVectorArray),
		CSTUB(ID3D10EffectVectorVariable_SetIntVectorArray),
		CMEMBER(ID3D10EffectVectorVariable_SetFloatVectorArray),
		CSTUB(ID3D10EffectVectorVariable_GetBoolVectorArray),
		CSTUB(ID3D10EffectVectorVariable_GetIntVectorArray),
		CSTUB(ID3D10EffectVectorVariable_GetFloatVectorArray)
	)
);

CLASS(
	ID3D10ShaderResourceView,
	STRUCT(
		/* ID3D10Texture2D */ void *texture2D;
	),
	VTABLE(
		CMEMBER(ID3D10ShaderResourceView_QueryInterface),
		CSTUB(ID3D10ShaderResourceView_AddRef),
		CSTUB(ID3D10ShaderResourceView_Release),
		CSTUB(ID3D10ShaderResourceView_GetDevice),
		CSTUB(ID3D10ShaderResourceView_GetPrivateData),
		CSTUB(ID3D10ShaderResourceView_SetPrivateData),
		CSTUB(ID3D10ShaderResourceView_SetPrivateDataInterface),
		CSTUB(ID3D10ShaderResourceView_GetResource),
		CSTUB(ID3D10ShaderResourceView_GetDesc)
	)
);

CLASS(
	ID3D10StateBlock,
	STRUCT(),
	VTABLE(
		CMEMBER(ID3D10StateBlock_QueryInterface),
		CSTUB(ID3D10StateBlock_AddRef),
		CSTUB(ID3D10StateBlock_Release),
		CMEMBER(ID3D10StateBlock_Capture),
		CMEMBER(ID3D10StateBlock_Apply),
		CSTUB(ID3D10StateBlock_ReleaseAllDeviceObjects),
		CSTUB(ID3D10StateBlock_GetDevice)
	)
);

CLASS(
	ID3D10Texture1D,
	STRUCT(
		D3D10_TEXTURE1D_DESC desc;
		
		unsigned int bufferSize;
		void *buffer;
		
		GLuint tex;
	),
	VTABLE(
		CSTUB(ID3D10Texture1D_QueryInterface),
		CSTUB(ID3D10Texture1D_AddRef),
		CSTUB(ID3D10Texture1D_Release),
		CSTUB(ID3D10Texture1D_GetDevice),
		CSTUB(ID3D10Texture1D_GetPrivateData),
		CSTUB(ID3D10Texture1D_SetPrivateData),
		CSTUB(ID3D10Texture1D_SetPrivateDataInterface),
		CSTUB(ID3D10Texture1D_GetType),
		CSTUB(ID3D10Texture1D_SetEvictionPriority),
		CSTUB(ID3D10Texture1D_GetEvictionPriority),
		CSTUB(ID3D10Texture1D_Map),
		CSTUB(ID3D10Texture1D_Unmap),
		CSTUB(ID3D10Texture1D_GetDesc)
	)
);

CLASS(
	ID3D10Texture2D,
	STRUCT(
		D3D10_TEXTURE2D_DESC desc;
		
		unsigned int bufferSize;
		void *buffer;
		
		GLuint tex;
	),
	VTABLE(
		CMEMBER(ID3D10Texture2D_QueryInterface),
		CSTUB(ID3D10Texture2D_AddRef),
		CMEMBER(ID3D10Texture2D_Release),
		CSTUB(ID3D10Texture2D_GetDevice),
		CSTUB(ID3D10Texture2D_GetPrivateData),
		CSTUB(ID3D10Texture2D_SetPrivateData),
		CSTUB(ID3D10Texture2D_SetPrivateDataInterface),
		CSTUB(ID3D10Texture2D_GetType),
		CSTUB(ID3D10Texture2D_SetEvictionPriority),
		CSTUB(ID3D10Texture2D_GetEvictionPriority),
		CSTUB(ID3D10Texture2D_Map),
		CSTUB(ID3D10Texture2D_Unmap),
		CMEMBER(ID3D10Texture2D_GetDesc)
	)
);

#endif
