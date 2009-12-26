/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
 */

#ifndef __APIS_WINDOWS_DTHREED_DTHREED_CLASSES_H__
#define __APIS_WINDOWS_DTHREED_DTHREED_CLASSES_H__

#include <APIs/Windows/Windows.h>
#include <APIs/Windows/COM/COM.h>

/*
  3.  STDMETHOD(RegisterSoftwareDevice)(THIS_ void* pInitializeFunction) PURE;
  4.  STDMETHOD_(UINT, GetAdapterCount)(THIS) PURE;
  5.  STDMETHOD(GetAdapterIdentifier)(THIS_ UINT Adapter,DWORD Flags,D3DADAPTER_IDENTIFIER9* pIdentifier) PURE;
  6.  STDMETHOD_(UINT, GetAdapterModeCount)(THIS_ UINT Adapter,D3DFORMAT Format) PURE;
  7.  STDMETHOD(EnumAdapterModes)(THIS_ UINT Adapter,D3DFORMAT Format,UINT Mode,D3DDISPLAYMODE* pMode) PURE;
  8.  STDMETHOD(GetAdapterDisplayMode)(THIS_ UINT Adapter,D3DDISPLAYMODE* pMode) PURE;
  9.  STDMETHOD(CheckDeviceType)(THIS_ UINT Adapter,D3DDEVTYPE DevType,D3DFORMAT AdapterFormat,D3DFORMAT BackBufferFormat,BOOL bWindowed) PURE;
 10.  STDMETHOD(CheckDeviceFormat)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT AdapterFormat,DWORD Usage,D3DRESOURCETYPE RType,D3DFORMAT CheckFormat) PURE;
 11.  STDMETHOD(CheckDeviceMultiSampleType)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT SurfaceFormat,BOOL Windowed,D3DMULTISAMPLE_TYPE MultiSampleType,DWORD* pQualityLevels) PURE;
 12.  STDMETHOD(CheckDepthStencilMatch)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT AdapterFormat,D3DFORMAT RenderTargetFormat,D3DFORMAT DepthStencilFormat) PURE;
 13.  STDMETHOD(CheckDeviceFormatConversion)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT SourceFormat,D3DFORMAT TargetFormat) PURE;
 14.  STDMETHOD(GetDeviceCaps)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,D3DCAPS9* pCaps) PURE;
 15.  STDMETHOD_(HMONITOR, GetAdapterMonitor)(THIS_ UINT Adapter) PURE;
 16.  STDMETHOD(CreateDevice)(THIS_ UINT Adapter,D3DDEVTYPE DeviceType,HWND hFocusWindow,DWORD BehaviorFlags,D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DDevice9** ppReturnedDeviceInterface) PURE;
*/

CLASS(
	IDirect3D9,
	STRUCT(
	),
	VTABLE(
		CSTUB(IDirect3D9_RegisterSoftwareDevice),
		CMEMBER(IDirect3D9_GetAdapterCount),
		CMEMBER(IDirect3D9_GetAdapterIdentifier),
		CMEMBER(IDirect3D9_GetAdapterModeCount),
		CMEMBER(IDirect3D9_EnumAdapterModes),
		CMEMBER(IDirect3D9_GetAdapterDisplayMode),
		CMEMBER(IDirect3D9_CheckDeviceType),
		CMEMBER(IDirect3D9_CheckDeviceFormat),
		CMEMBER(IDirect3D9_CheckDeviceMultiSampleType),
		CMEMBER(IDirect3D9_CheckDepthStencilMatch),
		CSTUB(IDirect3D9_CheckDeviceFormatConversion),
		CMEMBER(IDirect3D9_GetDeviceCaps),
		CSTUB(IDirect3D9_GetAdapterMonitor),
		CMEMBER(IDirect3D9_CreateDevice)
	)
);

/*
'	3.	STDMETHOD(TestCooperativeLevel)(THIS) PURE;
'	4.	STDMETHOD_(UINT, GetAvailableTextureMem)(THIS) PURE;
'	5.	STDMETHOD(EvictManagedResources)(THIS) PURE;
'	6.	STDMETHOD(GetDirect3D)(THIS_ IDirect3D9** ppD3D9) PURE;
'	7.	STDMETHOD(GetDeviceCaps)(THIS_ D3DCAPS9* pCaps) PURE;
'	8.	STDMETHOD(GetDisplayMode)(THIS_ UINT iSwapChain,D3DDISPLAYMODE* pMode) PURE;
'	9.	STDMETHOD(GetCreationParameters)(THIS_ D3DDEVICE_CREATION_PARAMETERS *pParameters) PURE;
'  10.	STDMETHOD(SetCursorProperties)(THIS_ UINT XHotSpot,UINT YHotSpot,IDirect3DSurface9* pCursorBitmap) PURE;
'  11.	STDMETHOD_(void, SetCursorPosition)(THIS_ int X,int Y,DWORD Flags) PURE;
'  12.	STDMETHOD_(BOOL, ShowCursor)(THIS_ BOOL bShow) PURE;
'  13.	STDMETHOD(CreateAdditionalSwapChain)(THIS_ D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DSwapChain9** pSwapChain) PURE;
'  14.	STDMETHOD(GetSwapChain)(THIS_ UINT iSwapChain,IDirect3DSwapChain9** pSwapChain) PURE;
'  15.	STDMETHOD_(UINT, GetNumberOfSwapChains)(THIS) PURE;
'  16.	STDMETHOD(Reset)(THIS_ D3DPRESENT_PARAMETERS* pPresentationParameters) PURE;
'  17.	STDMETHOD(Present)(THIS_ CONST RECT* pSourceRect,CONST RECT* pDestRect,HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion) PURE;
'  18.	STDMETHOD(GetBackBuffer)(THIS_ UINT iSwapChain,UINT iBackBuffer,D3DBACKBUFFER_TYPE Type,IDirect3DSurface9** ppBackBuffer) PURE;
'  19.	STDMETHOD(GetRasterStatus)(THIS_ UINT iSwapChain,D3DRASTER_STATUS* pRasterStatus) PURE;
'  20.	STDMETHOD(SetDialogBoxMode)(THIS_ BOOL bEnableDialogs) PURE;
'  21.	STDMETHOD_(void, SetGammaRamp)(THIS_ UINT iSwapChain,DWORD Flags,CONST D3DGAMMARAMP* pRamp) PURE;
'  22.	STDMETHOD_(void, GetGammaRamp)(THIS_ UINT iSwapChain,D3DGAMMARAMP* pRamp) PURE;
'  23.	STDMETHOD(CreateTexture)(THIS_ UINT Width,UINT Height,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DTexture9** ppTexture,HANDLE* pSharedHandle) PURE;
'  24.	STDMETHOD(CreateVolumeTexture)(THIS_ UINT Width,UINT Height,UINT Depth,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DVolumeTexture9** ppVolumeTexture,HANDLE* pSharedHandle) PURE;
'  25.	STDMETHOD(CreateCubeTexture)(THIS_ UINT EdgeLength,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DCubeTexture9** ppCubeTexture,HANDLE* pSharedHandle) PURE;
'  26.	STDMETHOD(CreateVertexBuffer)(THIS_ UINT Length,DWORD Usage,DWORD FVF,D3DPOOL Pool,IDirect3DVertexBuffer9** ppVertexBuffer,HANDLE* pSharedHandle) PURE;
'  27.	STDMETHOD(CreateIndexBuffer)(THIS_ UINT Length,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DIndexBuffer9** ppIndexBuffer,HANDLE* pSharedHandle) PURE;
'  28.	STDMETHOD(CreateRenderTarget)(THIS_ UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,DWORD MultisampleQuality,BOOL Lockable,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle) PURE;
'  29.	STDMETHOD(CreateDepthStencilSurface)(THIS_ UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,DWORD MultisampleQuality,BOOL Discard,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle) PURE;
'  30.	STDMETHOD(UpdateSurface)(THIS_ IDirect3DSurface9* pSourceSurface,CONST RECT* pSourceRect,IDirect3DSurface9* pDestinationSurface,CONST POINT* pDestPoint) PURE;
'  31.	STDMETHOD(UpdateTexture)(THIS_ IDirect3DBaseTexture9* pSourceTexture,IDirect3DBaseTexture9* pDestinationTexture) PURE;
'  32.	STDMETHOD(GetRenderTargetData)(THIS_ IDirect3DSurface9* pRenderTarget,IDirect3DSurface9* pDestSurface) PURE;
'  33.	STDMETHOD(GetFrontBufferData)(THIS_ UINT iSwapChain,IDirect3DSurface9* pDestSurface) PURE;
'  34.	STDMETHOD(StretchRect)(THIS_ IDirect3DSurface9* pSourceSurface,CONST RECT* pSourceRect,IDirect3DSurface9* pDestSurface,CONST RECT* pDestRect,D3DTEXTUREFILTERTYPE Filter) PURE;
'  35.	STDMETHOD(ColorFill)(THIS_ IDirect3DSurface9* pSurface,CONST RECT* pRect,D3DCOLOR color) PURE;
'  36.	STDMETHOD(CreateOffscreenPlainSurface)(THIS_ UINT Width,UINT Height,D3DFORMAT Format,D3DPOOL Pool,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle) PURE;
'  37.	STDMETHOD(SetRenderTarget)(THIS_ DWORD RenderTargetIndex,IDirect3DSurface9* pRenderTarget) PURE;
'  38.	STDMETHOD(GetRenderTarget)(THIS_ DWORD RenderTargetIndex,IDirect3DSurface9** ppRenderTarget) PURE;
'  39.	STDMETHOD(SetDepthStencilSurface)(THIS_ IDirect3DSurface9* pNewZStencil) PURE;
'  40.	STDMETHOD(GetDepthStencilSurface)(THIS_ IDirect3DSurface9** ppZStencilSurface) PURE;
'  41.	STDMETHOD(BeginScene)(THIS) PURE;
'  42.	STDMETHOD(EndScene)(THIS) PURE;
'  43.	STDMETHOD(Clear)(THIS_ DWORD Count,CONST D3DRECT* pRects,DWORD Flags,D3DCOLOR Color,float Z,DWORD Stencil) PURE;
'  44.	STDMETHOD(SetTransform)(THIS_ D3DTRANSFORMSTATETYPE State,CONST D3DMATRIX* pMatrix) PURE;
'  45.	STDMETHOD(GetTransform)(THIS_ D3DTRANSFORMSTATETYPE State,D3DMATRIX* pMatrix) PURE;
'  46.	STDMETHOD(MultiplyTransform)(THIS_ D3DTRANSFORMSTATETYPE,CONST D3DMATRIX*) PURE;
'  47.	STDMETHOD(SetViewport)(THIS_ CONST D3DVIEWPORT9* pViewport) PURE;
'  48.	STDMETHOD(GetViewport)(THIS_ D3DVIEWPORT9* pViewport) PURE;
'  49.	STDMETHOD(SetMaterial)(THIS_ CONST D3DMATERIAL9* pMaterial) PURE;
'  50.	STDMETHOD(GetMaterial)(THIS_ D3DMATERIAL9* pMaterial) PURE;
'  51.	STDMETHOD(SetLight)(THIS_ DWORD Index,CONST D3DLIGHT9*) PURE;
'  52.	STDMETHOD(GetLight)(THIS_ DWORD Index,D3DLIGHT9*) PURE;
'  53.	STDMETHOD(LightEnable)(THIS_ DWORD Index,BOOL Enable) PURE;
'  54.	STDMETHOD(GetLightEnable)(THIS_ DWORD Index,BOOL* pEnable) PURE;
'  55.	STDMETHOD(SetClipPlane)(THIS_ DWORD Index,CONST float* pPlane) PURE;
'  56.	STDMETHOD(GetClipPlane)(THIS_ DWORD Index,float* pPlane) PURE;
'  57.	STDMETHOD(SetRenderState)(THIS_ D3DRENDERSTATETYPE State,DWORD Value) PURE;
'  58.	STDMETHOD(GetRenderState)(THIS_ D3DRENDERSTATETYPE State,DWORD* pValue) PURE;
'  59.	STDMETHOD(CreateStateBlock)(THIS_ D3DSTATEBLOCKTYPE Type,IDirect3DStateBlock9** ppSB) PURE;
'  60.	STDMETHOD(BeginStateBlock)(THIS) PURE;
'  61.	STDMETHOD(EndStateBlock)(THIS_ IDirect3DStateBlock9** ppSB) PURE;
'  62.	STDMETHOD(SetClipStatus)(THIS_ CONST D3DCLIPSTATUS9* pClipStatus) PURE;
'  63.	STDMETHOD(GetClipStatus)(THIS_ D3DCLIPSTATUS9* pClipStatus) PURE;
'  64.	STDMETHOD(GetTexture)(THIS_ DWORD Stage,IDirect3DBaseTexture9** ppTexture) PURE;
'  65.	STDMETHOD(SetTexture)(THIS_ DWORD Stage,IDirect3DBaseTexture9* pTexture) PURE;
'  66.	STDMETHOD(GetTextureStageState)(THIS_ DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD* pValue) PURE;
'  67.	STDMETHOD(SetTextureStageState)(THIS_ DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD Value) PURE;
'  68.	STDMETHOD(GetSamplerState)(THIS_ DWORD Sampler,D3DSAMPLERSTATETYPE Type,DWORD* pValue) PURE;
'  69.	STDMETHOD(SetSamplerState)(THIS_ DWORD Sampler,D3DSAMPLERSTATETYPE Type,DWORD Value) PURE;
'  70.	STDMETHOD(ValidateDevice)(THIS_ DWORD* pNumPasses) PURE;
'  71.	STDMETHOD(SetPaletteEntries)(THIS_ UINT PaletteNumber,CONST PALETTEENTRY* pEntries) PURE;
'  72.	STDMETHOD(GetPaletteEntries)(THIS_ UINT PaletteNumber,PALETTEENTRY* pEntries) PURE;
'  73.	STDMETHOD(SetCurrentTexturePalette)(THIS_ UINT PaletteNumber) PURE;
'  74.	STDMETHOD(GetCurrentTexturePalette)(THIS_ UINT *PaletteNumber) PURE;
'  75.	STDMETHOD(SetScissorRect)(THIS_ CONST RECT* pRect) PURE;
'  76.	STDMETHOD(GetScissorRect)(THIS_ RECT* pRect) PURE;
'  77.	STDMETHOD(SetSoftwareVertexProcessing)(THIS_ BOOL bSoftware) PURE;
'  78.	STDMETHOD_(BOOL, GetSoftwareVertexProcessing)(THIS) PURE;
'  79.	STDMETHOD(SetNPatchMode)(THIS_ float nSegments) PURE;
'  80.	STDMETHOD_(float, GetNPatchMode)(THIS) PURE;
'  81.	STDMETHOD(DrawPrimitive)(THIS_ D3DPRIMITIVETYPE PrimitiveType,UINT StartVertex,UINT PrimitiveCount) PURE;
'  82.	STDMETHOD(DrawIndexedPrimitive)(THIS_ D3DPRIMITIVETYPE,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount) PURE;
'  83.	STDMETHOD(DrawPrimitiveUP)(THIS_ D3DPRIMITIVETYPE PrimitiveType,UINT PrimitiveCount,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride) PURE;
'  84.	STDMETHOD(DrawIndexedPrimitiveUP)(THIS_ D3DPRIMITIVETYPE PrimitiveType,UINT MinVertexIndex,UINT NumVertices,UINT PrimitiveCount,CONST void* pIndexData,D3DFORMAT IndexDataFormat,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride) PURE;
'  85.	STDMETHOD(ProcessVertices)(THIS_ UINT SrcStartIndex,UINT DestIndex,UINT VertexCount,IDirect3DVertexBuffer9* pDestBuffer,IDirect3DVertexDeclaration9* pVertexDecl,DWORD Flags) PURE;
'  86.	STDMETHOD(CreateVertexDeclaration)(THIS_ CONST D3DVERTEXELEMENT9* pVertexElements,IDirect3DVertexDeclaration9** ppDecl) PURE;
'  87.	STDMETHOD(SetVertexDeclaration)(THIS_ IDirect3DVertexDeclaration9* pDecl) PURE;
'  88.	STDMETHOD(GetVertexDeclaration)(THIS_ IDirect3DVertexDeclaration9** ppDecl) PURE;
'  89.	STDMETHOD(SetFVF)(THIS_ DWORD FVF) PURE;
'  90.	STDMETHOD(GetFVF)(THIS_ DWORD* pFVF) PURE;
'  91.	STDMETHOD(CreateVertexShader)(THIS_ CONST DWORD* pFunction,IDirect3DVertexShader9** ppShader) PURE;
'  92.	STDMETHOD(SetVertexShader)(THIS_ IDirect3DVertexShader9* pShader) PURE;
'  93.	STDMETHOD(GetVertexShader)(THIS_ IDirect3DVertexShader9** ppShader) PURE;
'  94.	STDMETHOD(SetVertexShaderConstantF)(THIS_ UINT StartRegister,CONST float* pConstantData,UINT Vector4fCount) PURE;
'  95.	STDMETHOD(GetVertexShaderConstantF)(THIS_ UINT StartRegister,float* pConstantData,UINT Vector4fCount) PURE;
'  96.	STDMETHOD(SetVertexShaderConstantI)(THIS_ UINT StartRegister,CONST int* pConstantData,UINT Vector4iCount) PURE;
'  97.	STDMETHOD(GetVertexShaderConstantI)(THIS_ UINT StartRegister,int* pConstantData,UINT Vector4iCount) PURE;
'  98.	STDMETHOD(SetVertexShaderConstantB)(THIS_ UINT StartRegister,CONST BOOL* pConstantData,UINT	 BoolCount) PURE;
'  99.	STDMETHOD(GetVertexShaderConstantB)(THIS_ UINT StartRegister,BOOL* pConstantData,UINT BoolCount) PURE;
' 100.	STDMETHOD(SetStreamSource)(THIS_ UINT StreamNumber,IDirect3DVertexBuffer9* pStreamData,UINT OffsetInBytes,UINT Stride) PURE;
' 101.	STDMETHOD(GetStreamSource)(THIS_ UINT StreamNumber,IDirect3DVertexBuffer9** ppStreamData,UINT* pOffsetInBytes,UINT* pStride) PURE;
' 102.	STDMETHOD(SetStreamSourceFreq)(THIS_ UINT StreamNumber,UINT Setting) PURE;
' 103.	STDMETHOD(GetStreamSourceFreq)(THIS_ UINT StreamNumber,UINT* pSetting) PURE;
' 104.	STDMETHOD(SetIndices)(THIS_ IDirect3DIndexBuffer9* pIndexData) PURE;
' 105.	STDMETHOD(GetIndices)(THIS_ IDirect3DIndexBuffer9** ppIndexData) PURE;
' 106.	STDMETHOD(CreatePixelShader)(THIS_ CONST DWORD* pFunction,IDirect3DPixelShader9** ppShader) PURE;
' 107.	STDMETHOD(SetPixelShader)(THIS_ IDirect3DPixelShader9* pShader) PURE;
' 108.	STDMETHOD(GetPixelShader)(THIS_ IDirect3DPixelShader9** ppShader) PURE;
' 109.	STDMETHOD(SetPixelShaderConstantF)(THIS_ UINT StartRegister,CONST float* pConstantData,UINT Vector4fCount) PURE;
' 110.	STDMETHOD(GetPixelShaderConstantF)(THIS_ UINT StartRegister,float* pConstantData,UINT Vector4fCount) PURE;
' 111.	STDMETHOD(SetPixelShaderConstantI)(THIS_ UINT StartRegister,CONST int* pConstantData,UINT Vector4iCount) PURE;
' 112.	STDMETHOD(GetPixelShaderConstantI)(THIS_ UINT StartRegister,int* pConstantData,UINT Vector4iCount) PURE;
' 113.	STDMETHOD(SetPixelShaderConstantB)(THIS_ UINT StartRegister,CONST BOOL* pConstantData,UINT	BoolCount) PURE;
' 114.	STDMETHOD(GetPixelShaderConstantB)(THIS_ UINT StartRegister,BOOL* pConstantData,UINT BoolCount) PURE;
' 115.	STDMETHOD(DrawRectPatch)(THIS_ UINT Handle,CONST float* pNumSegs,CONST D3DRECTPATCH_INFO* pRectPatchInfo) PURE;
' 116.	STDMETHOD(DrawTriPatch)(THIS_ UINT Handle,CONST float* pNumSegs,CONST D3DTRIPATCH_INFO* pTriPatchInfo) PURE;
' 117.	STDMETHOD(DeletePatch)(THIS_ UINT Handle) PURE;
' 118.	STDMETHOD(CreateQuery)(THIS_ D3DQUERYTYPE Type,IDirect3DQuery9** ppQuery) PURE;
*/

CLASS(
	IDirect3DDevice9,
	STRUCT(
		DWORD fvf;
		
		unsigned int currentStream;
		void *stream[0xFF];
	),
	VTABLE(
		CSTUB(IDirect3DDevice9_TestCooperativeLevel),
		CSTUB(IDirect3DDevice9_GetAvailableTextureMem),
		CSTUB(IDirect3DDevice9_EvictManagedResources),
		CSTUB(IDirect3DDevice9_GetDirect3D),
		CMEMBER(IDirect3DDevice9_GetDeviceCaps),
		CSTUB(IDirect3DDevice9_GetDisplayMode),
		CSTUB(IDirect3DDevice9_GetCreationParameters),
		CSTUB(IDirect3DDevice9_SetCursorProperties),
		CSTUB(IDirect3DDevice9_SetCursorPosition),
		CSTUB(IDirect3DDevice9_ShowCursor),
		CSTUB(IDirect3DDevice9_CreateAdditionalSwapChain),
		CSTUB(IDirect3DDevice9_GetSwapChain),
		CSTUB(IDirect3DDevice9_GetNumberOfSwapChains),
		CSTUB(IDirect3DDevice9_Reset),
		CMEMBER(IDirect3DDevice9_Present),
		CSTUB(IDirect3DDevice9_GetBackBuffer),
		CSTUB(IDirect3DDevice9_GetRasterStatus),
		CSTUB(IDirect3DDevice9_SetDialogBoxMode),
		CSTUB(IDirect3DDevice9_SetGammaRamp),
		CSTUB(IDirect3DDevice9_GetGammaRamp),
		CMEMBER(IDirect3DDevice9_CreateTexture),
		CSTUB(IDirect3DDevice9_CreateVolumeTexture),
		CMEMBER(IDirect3DDevice9_CreateCubeTexture),
		CMEMBER(IDirect3DDevice9_CreateVertexBuffer),
		CSTUB(IDirect3DDevice9_CreateIndexBuffer),
		CSTUB(IDirect3DDevice9_CreateRenderTarget),
		CSTUB(IDirect3DDevice9_CreateDepthStencilSurface),
		CSTUB(IDirect3DDevice9_UpdateSurface),
		CSTUB(IDirect3DDevice9_UpdateTexture),
		CSTUB(IDirect3DDevice9_GetRenderTargetData),
		CSTUB(IDirect3DDevice9_GetFrontBufferData),
		CSTUB(IDirect3DDevice9_StretchRect),
		CSTUB(IDirect3DDevice9_ColorFill),
		CSTUB(IDirect3DDevice9_CreateOffscreenPlainSurface),
		CSTUB(IDirect3DDevice9_SetRenderTarget),
		CMEMBER(IDirect3DDevice9_GetRenderTarget),
		CSTUB(IDirect3DDevice9_SetDepthStencilSurface),
		CMEMBER(IDirect3DDevice9_GetDepthStencilSurface),
		CMEMBER(IDirect3DDevice9_BeginScene),
		CMEMBER(IDirect3DDevice9_EndScene),
		CMEMBER(IDirect3DDevice9_Clear),
		CMEMBER(IDirect3DDevice9_SetTransform),
		CSTUB(IDirect3DDevice9_GetTransform),
		CSTUB(IDirect3DDevice9_MultiplyTransform),
		CMEMBER(IDirect3DDevice9_SetViewport),
		CSTUB(IDirect3DDevice9_GetViewport),
		CMEMBER(IDirect3DDevice9_SetMaterial),
		CSTUB(IDirect3DDevice9_GetMaterial),
		CMEMBER(IDirect3DDevice9_SetLight),
		CSTUB(IDirect3DDevice9_GetLight),
		CMEMBER(IDirect3DDevice9_LightEnable),
		CSTUB(IDirect3DDevice9_GetLightEnable),
		CSTUB(IDirect3DDevice9_SetClipPlane),
		CSTUB(IDirect3DDevice9_GetClipPlane),
		CMEMBER(IDirect3DDevice9_SetRenderState),
		CSTUB(IDirect3DDevice9_GetRenderState),
		CSTUB(IDirect3DDevice9_CreateStateBlock),
		CSTUB(IDirect3DDevice9_BeginStateBlock),
		CSTUB(IDirect3DDevice9_EndStateBlock),
		CSTUB(IDirect3DDevice9_SetClipStatus),
		CSTUB(IDirect3DDevice9_GetClipStatus),
		CSTUB(IDirect3DDevice9_GetTexture),
		CMEMBER(IDirect3DDevice9_SetTexture),
		CSTUB(IDirect3DDevice9_GetTextureStageState),
		CMEMBER(IDirect3DDevice9_SetTextureStageState),
		CSTUB(IDirect3DDevice9_GetSamplerState),
		CMEMBER(IDirect3DDevice9_SetSamplerState),
		CSTUB(IDirect3DDevice9_ValidateDevice),
		CSTUB(IDirect3DDevice9_SetPaletteEntries),
		CSTUB(IDirect3DDevice9_GetPaletteEntries),
		CSTUB(IDirect3DDevice9_SetCurrentTexturePalette),
		CSTUB(IDirect3DDevice9_GetCurrentTexturePalette),
		CSTUB(IDirect3DDevice9_SetScissorRect),
		CSTUB(IDirect3DDevice9_GetScissorRect),
		CSTUB(IDirect3DDevice9_SetSoftwareVertexProcessing),
		CSTUB(IDirect3DDevice9_GetSoftwareVertexProcessing),
		CSTUB(IDirect3DDevice9_SetNPatchMode),
		CSTUB(IDirect3DDevice9_GetNPatchMode),
		CMEMBER(IDirect3DDevice9_DrawPrimitive),
		CSTUB(IDirect3DDevice9_DrawIndexedPrimitive),
		CSTUB(IDirect3DDevice9_DrawPrimitiveUP),
		CSTUB(IDirect3DDevice9_DrawIndexedPrimitiveUP),
		CSTUB(IDirect3DDevice9_ProcessVertices),
		CSTUB(IDirect3DDevice9_CreateVertexDeclaration),
		CSTUB(IDirect3DDevice9_SetVertexDeclaration),
		CSTUB(IDirect3DDevice9_GetVertexDeclaration),
		CMEMBER(IDirect3DDevice9_SetFVF),
		CSTUB(IDirect3DDevice9_GetFVF),
		CMEMBER(IDirect3DDevice9_CreateVertexShader),
		CSTUB(IDirect3DDevice9_SetVertexShader),
		CSTUB(IDirect3DDevice9_GetVertexShader),
		CSTUB(IDirect3DDevice9_SetVertexShaderConstantF),
		CSTUB(IDirect3DDevice9_GetVertexShaderConstantF),
		CSTUB(IDirect3DDevice9_SetVertexShaderConstantI),
		CSTUB(IDirect3DDevice9_GetVertexShaderConstantI),
		CSTUB(IDirect3DDevice9_SetVertexShaderConstantB),
		CSTUB(IDirect3DDevice9_GetVertexShaderConstantB),
		CMEMBER(IDirect3DDevice9_SetStreamSource),
		CSTUB(IDirect3DDevice9_GetStreamSource),
		CSTUB(IDirect3DDevice9_SetStreamSourceFreq),
		CSTUB(IDirect3DDevice9_GetStreamSourceFreq),
		CSTUB(IDirect3DDevice9_SetIndices),
		CSTUB(IDirect3DDevice9_GetIndices),
		CMEMBER(IDirect3DDevice9_CreatePixelShader),
		CSTUB(IDirect3DDevice9_SetPixelShader),
		CSTUB(IDirect3DDevice9_GetPixelShader),
		CSTUB(IDirect3DDevice9_SetPixelShaderConstantF),
		CSTUB(IDirect3DDevice9_GetPixelShaderConstantF),
		CSTUB(IDirect3DDevice9_SetPixelShaderConstantI),
		CSTUB(IDirect3DDevice9_GetPixelShaderConstantI),
		CSTUB(IDirect3DDevice9_SetPixelShaderConstantB),
		CSTUB(IDirect3DDevice9_GetPixelShaderConstantB),
		CSTUB(IDirect3DDevice9_DrawRectPatch),
		CSTUB(IDirect3DDevice9_DrawTriPatch),
		CSTUB(IDirect3DDevice9_DeletePatch),
		CSTUB(IDirect3DDevice9_CreateQuery)
	)
);

CLASS(
	IDirect3DResource9,
	STRUCT(
		D3DRESOURCETYPE Type;
	),
	VTABLE(
		CSTUB(IDirect3DResource9_GetDevice),
		CSTUB(IDirect3DResource9_SetPrivateData),
		CSTUB(IDirect3DResource9_GetPrivateData),
		CSTUB(IDirect3DResource9_FreePrivateData),
		CSTUB(IDirect3DResource9_SetPriority),
		CSTUB(IDirect3DResource9_GetPriority),
		CSTUB(IDirect3DResource9_PreLoad),
		CMEMBER(IDirect3DResource9_GetType)
	)
);

/*
'  IDirect3DResource9 methods
'  3.  STDMETHOD(GetDevice)(THIS_ IDirect3DDevice9** ppDevice) PURE;
'  4.  STDMETHOD(SetPrivateData)(THIS_ REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags) PURE;
'  5.  STDMETHOD(GetPrivateData)(THIS_ REFGUID refguid,void* pData,DWORD* pSizeOfData) PURE;
'  6.  STDMETHOD(FreePrivateData)(THIS_ REFGUID refguid) PURE;
'  7.  STDMETHOD_(DWORD, SetPriority)(THIS_ DWORD PriorityNew) PURE;
'  8.  STDMETHOD_(DWORD, GetPriority)(THIS) PURE;
'  9.  STDMETHOD_(void, PreLoad)(THIS) PURE;
' 10.  STDMETHOD_(D3DRESOURCETYPE, GetType)(THIS) PURE;

' IDirect3DVertexBuffer9 methods
' 11.  STDMETHOD(Lock)(THIS_ UINT OffsetToLock,UINT SizeToLock,void** ppbData,DWORD Flags) PURE;
' 12.  STDMETHOD(Unlock)(THIS) PURE;
' 13.  STDMETHOD(GetDesc)(THIS_ D3DVERTEXBUFFER_DESC *pDesc) PURE;
*/

CLASS(
	IDirect3DVertexBuffer9,
	STRUCT(
		CSTRUCT(IDirect3DResource9) Resource;
		
		DWORD fvf;
		unsigned int length;
		unsigned int vertexCount;
		void *vertexBuffer;
	),
	VTABLE(
		CSTUB(IDirect3DVertexBuffer9_GetDevice),
		CSTUB(IDirect3DVertexBuffer9_SetPrivateData),
		CSTUB(IDirect3DVertexBuffer9_GetPrivateData),
		CSTUB(IDirect3DVertexBuffer9_FreePrivateData),
		CSTUB(IDirect3DVertexBuffer9_SetPriority),
		CSTUB(IDirect3DVertexBuffer9_GetPriority),
		CSTUB(IDirect3DVertexBuffer9_PreLoad),
		CSTUB(IDirect3DVertexBuffer9_GetType),
		
		CMEMBER(IDirect3DVertexBuffer9_Lock),
		CMEMBER(IDirect3DVertexBuffer9_Unlock),
		CSTUB(IDirect3DVertexBuffer9_GetDesc)
	)
);

/*
'  3.  STDMETHOD(GetDevice)(THIS_ IDirect3DDevice9** ppDevice) PURE;
'  4.  STDMETHOD(SetPrivateData)(THIS_ REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags) PURE;
'  5.  STDMETHOD(GetPrivateData)(THIS_ REFGUID refguid,void* pData,DWORD* pSizeOfData) PURE;
'  6.  STDMETHOD(FreePrivateData)(THIS_ REFGUID refguid) PURE;
'  7.  STDMETHOD_(DWORD, SetPriority)(THIS_ DWORD PriorityNew) PURE;
'  8.  STDMETHOD_(DWORD, GetPriority)(THIS) PURE;
'  9.  STDMETHOD_(void, PreLoad)(THIS) PURE;
' 10.  STDMETHOD_(D3DRESOURCETYPE, GetType)(THIS) PURE;

'	 *** IDirect3DSurface9 methods ***

' 11.  STDMETHOD(GetContainer)(THIS_ REFIID riid,void** ppContainer) PURE;
' 12.  STDMETHOD(GetDesc)(THIS_ D3DSURFACE_DESC *pDesc) PURE;
' 13.  STDMETHOD(LockRect)(THIS_ D3DLOCKED_RECT* pLockedRect,CONST RECT* pRect,DWORD Flags) PURE;
' 14.  STDMETHOD(UnlockRect)(THIS) PURE;
' 15.  STDMETHOD(GetDC)(THIS_ HDC *phdc) PURE;
' 16.  STDMETHOD(ReleaseDC)(THIS_ HDC hdc) PURE;
*/

CLASS(
	IDirect3DSurface9,
	STRUCT(
		CSTRUCT(IDirect3DResource9) Resource;
		
		UINT Width, Height;
		D3DFORMAT Format;
		
		void *pBits;
		
		GLuint glTexture;
	),
	VTABLE(
		CSTUB(IDirect3DSurface9_GetDevice),
		CSTUB(IDirect3DSurface9_SetPrivateData),
		CSTUB(IDirect3DSurface9_GetPrivateData),
		CSTUB(IDirect3DSurface9_FreePrivateData),
		CSTUB(IDirect3DSurface9_SetPriority),
		CSTUB(IDirect3DSurface9_GetPriority),
		CSTUB(IDirect3DSurface9_PreLoad),
		CSTUB(IDirect3DSurface9_GetType),
		
		CSTUB(IDirect3DSurface9_GetContainer),
		CMEMBER(IDirect3DSurface9_GetDesc),
		CMEMBER(IDirect3DSurface9_LockRect),
		CMEMBER(IDirect3DSurface9_UnlockRect),
		CSTUB(IDirect3DSurface9_GetDC),
		CSTUB(IDirect3DSurface9_ReleaseDC)
	)
);

/*
STDMETHOD_(DWORD, SetLOD)(THIS_ DWORD LODNew) PURE;
STDMETHOD_(DWORD, GetLOD)(THIS) PURE;
STDMETHOD_(DWORD, GetLevelCount)(THIS) PURE;
STDMETHOD(SetAutoGenFilterType)(THIS_ D3DTEXTUREFILTERTYPE FilterType) PURE;
STDMETHOD_(D3DTEXTUREFILTERTYPE, GetAutoGenFilterType)(THIS) PURE;
STDMETHOD_(void, GenerateMipSubLevels)(THIS) PURE;

STDMETHOD(GetLevelDesc)(THIS_ UINT Level,D3DSURFACE_DESC *pDesc) PURE;
STDMETHOD(GetSurfaceLevel)(THIS_ UINT Level,IDirect3DSurface9** ppSurfaceLevel) PURE;
STDMETHOD(LockRect)(THIS_ UINT Level,D3DLOCKED_RECT* pLockedRect,CONST RECT* pRect,DWORD Flags) PURE;
STDMETHOD(UnlockRect)(THIS_ UINT Level) PURE;
STDMETHOD(AddDirtyRect)(THIS_ CONST RECT* pDirtyRect) PURE;
*/

CLASS(
	IDirect3DTexture9,
	STRUCT(
		CSTRUCT(IDirect3DResource9) Resource;
		
		UINT Width, Height, Levels;
		D3DFORMAT Format;
		
		void ***surfaces;
	),
	VTABLE(
		CSTUB(IDirect3DTexture9_GetDevice),
		CSTUB(IDirect3DTexture9_SetPrivateData),
		CSTUB(IDirect3DTexture9_GetPrivateData),
		CSTUB(IDirect3DTexture9_FreePrivateData),
		CSTUB(IDirect3DTexture9_SetPriority),
		CSTUB(IDirect3DTexture9_GetPriority),
		CSTUB(IDirect3DTexture9_PreLoad),
		CMEMBER(IDirect3DTexture9_GetType),
		
		CSTUB(IDirect3DTexture9_SetLOD),
		CMEMBER(IDirect3DTexture9_GetLOD),
		CSTUB(IDirect3DTexture9_GetLevelCount),
		CSTUB(IDirect3DTexture9_SetAutoGenFilterType),
		CSTUB(IDirect3DTexture9_D3DTEXTUREFILTERTYPE),
		CSTUB(IDirect3DTexture9_GenerateMipSubLevels),
		
		CSTUB(IDirect3DTexture9_GetLevelDesc),
		CMEMBER(IDirect3DTexture9_GetSurfaceLevel),
		CSTUB(IDirect3DTexture9_LockRect),
		CSTUB(IDirect3DTexture9_UnlockRect),
		CSTUB(IDirect3DTexture9_AddDirtyRect)
	)
);

/*
STDMETHOD(GetLevelDesc)(THIS_ UINT Level,D3DSURFACE_DESC *pDesc) PURE;
STDMETHOD(GetCubeMapSurface)(THIS_ D3DCUBEMAP_FACES FaceType,UINT Level,IDirect3DSurface9** ppCubeMapSurface) PURE;
STDMETHOD(LockRect)(THIS_ D3DCUBEMAP_FACES FaceType,UINT Level,D3DLOCKED_RECT* pLockedRect,CONST RECT* pRect,DWORD Flags) PURE;
STDMETHOD(UnlockRect)(THIS_ D3DCUBEMAP_FACES FaceType,UINT Level) PURE;
STDMETHOD(AddDirtyRect)(THIS_ D3DCUBEMAP_FACES FaceType,CONST RECT* pDirtyRect) PURE;
*/

CLASS(
	IDirect3DCubeTexture9,
	STRUCT(
		CSTRUCT(IDirect3DResource9) Resource;
		
		UINT EdgeLength, Levels;
		D3DFORMAT Format;
		
		void ***surfaces;
	),
	VTABLE(
		CSTUB(IDirect3DCubeTexture9_GetDevice),
		CSTUB(IDirect3DCubeTexture9_SetPrivateData),
		CSTUB(IDirect3DCubeTexture9_GetPrivateData),
		CSTUB(IDirect3DCubeTexture9_FreePrivateData),
		CSTUB(IDirect3DCubeTexture9_SetPriority),
		CSTUB(IDirect3DCubeTexture9_GetPriority),
		CSTUB(IDirect3DCubeTexture9_PreLoad),
		CSTUB(IDirect3DCubeTexture9_GetType),
		
		CSTUB(IDirect3DCubeTexture9_SetLOD),
		CSTUB(IDirect3DCubeTexture9_GetLOD),
		CSTUB(IDirect3DCubeTexture9_GetLevelCount),
		CSTUB(IDirect3DCubeTexture9_SetAutoGenFilterType),
		CSTUB(IDirect3DCubeTexture9_D3DTEXTUREFILTERTYPE),
		CSTUB(IDirect3DCubeTexture9_GenerateMipSubLevels),
		
		CSTUB(IDirect3DCubeTexture9_GetLevelDesc),
		CMEMBER(IDirect3DCubeTexture9_GetCubeMapSurface),
		CSTUB(IDirect3DCubeTexture9_LockRect),
		CSTUB(IDirect3DCubeTexture9_UnlockRect),
		CSTUB(IDirect3DCubeTexture9_AddDirtyRect)
	)
);

#endif
