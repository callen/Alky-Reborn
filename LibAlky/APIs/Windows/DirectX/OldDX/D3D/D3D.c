/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#define DEFINE_CLASSES
#include <APIs/Windows/DirectX/D3D/D3D.h>
#include <APIs/Windows/DirectX/D3D/D3D_Classes.h>

#define NUMODULE_NAME "D3D"

VTABLE_SETUP_FUNC(
	VTABLE_SETUP(IDirect3D9)
	VTABLE_SETUP(IDirect3DDevice9)
	VTABLE_SETUP(IDirect3DResource9)
	VTABLE_SETUP(IDirect3DSurface9)
	VTABLE_SETUP(IDirect3DCubeTexture9)
	VTABLE_SETUP(IDirect3DTexture9)
	VTABLE_SETUP(IDirect3DVertexBuffer9)
);


WINAPI void *Direct3DCreate9(
    UINT SDKVersion
) {
	void *ret;
	
	INIT_CLASS(IDirect3D9, ret);
	
	return ret;
}

WINAPI HRESULT IDirect3D9_Release(
    void *this_
) {
	return S_OK;
}

WINAPI UINT IDirect3D9_GetAdapterCount(
    void *this_
) {
	NuWarn("IDirect3D9::GetAdapterCount not yet implemented");
	
	return 1;
}

WINAPI HRESULT IDirect3D9_GetAdapterIdentifier(
    void *this_,
    UINT Adapter,
    DWORD Flags,
    D3DADAPTER_IDENTIFIER9 *pIdentifier
) {
	NuWarn("IDirect3D9::GetAdapterIdentifier not yet implemented");
	
	strcpy(pIdentifier->Driver, "Alky D3D->OGL Layer");
	strcpy(pIdentifier->Description, "Alky D3D Rocks");
	strcpy(pIdentifier->DeviceName, "Alky D3D Device");
	
	pIdentifier->WHQLLevel = 0xFFFFFFFF;
	
	return S_OK;
}

WINAPI UINT IDirect3D9_GetAdapterModeCount(
    void *this_,
    UINT Adapter,
    D3DFORMAT Format
) {
	NuWarn("IDirect3D9::GetAdapterModeCount not yet implemented");
	
	return 1;
}

WINAPI HRESULT IDirect3D9_EnumAdapterModes(
    void *this_,
    UINT Adapter,
    D3DFORMAT Format,
    UINT Mode,
    D3DDISPLAYMODE *pMode
) {
	NuWarn("IDirect3D9::EnumAdapterModes not yet implemented");
	
	pMode->Width = 1024;
	pMode->Height = 768;
	pMode->RefreshRate = 60;
	pMode->Format = D3DFMT_X8R8G8B8;
	
	return S_OK;
}

WINAPI HRESULT IDirect3D9_GetAdapterDisplayMode(
    void *this_,
    UINT Adapter,
    D3DDISPLAYMODE *pMode
) {
	NuWarn("IDirect3D9::GetAdapterDisplayMode not yet implemented");
	
	pMode->Width = 1024;
	pMode->Height = 768;
	pMode->RefreshRate = 60;
	pMode->Format = D3DFMT_X8R8G8B8;
	
	return S_OK;
}

WINAPI HRESULT IDirect3D9_CheckDeviceType(
    void *this_,
    UINT Adapter,
    D3DDEVTYPE DevType,
    D3DFORMAT AdapterFormat,
    D3DFORMAT BackBufferFormat,
    BOOL bWindowed
) {
	NuWarn("IDirect3D9::CheckDeviceType not yet implemented");
	
	return S_OK;
}

WINAPI HRESULT IDirect3D9_CheckDeviceFormat(
    void *this_,
    UINT Adapter,
    D3DDEVTYPE DeviceType,
    D3DFORMAT AdapterFormat,
    DWORD Usage,
    D3DRESOURCETYPE RType,
    D3DFORMAT CheckFormat
) {
	NuWarn("IDirect3D9::CheckDeviceFormat not yet implemented");
	
	return S_OK;
}

WINAPI HRESULT IDirect3D9_CheckDeviceMultiSampleType(
    void *this_,
    UINT Adapter,
    D3DDEVTYPE DeviceType,
    D3DFORMAT SurfaceFormat,
    BOOL Windowed,
    D3DMULTISAMPLE_TYPE MultiSampleType,
    DWORD* pQualityLevels
) {
	NuWarn("IDirect3D9::CheckDeviceMultiSampleType not yet implemented");
	
	*pQualityLevels = 0x10;
	
	return S_OK;
}

WINAPI HRESULT IDirect3D9_CheckDepthStencilMatch(
    void *this_,
    UINT Adapter,
    D3DDEVTYPE DeviceType,
    D3DFORMAT AdapterFormat,
    D3DFORMAT RenderTargetFormat,
    D3DFORMAT DepthStencilFormat
) {
	NuWarn("IDirect3D9::CheckDepthStencilMatch not yet implemented");
	
	return S_OK;
}

WINAPI HRESULT IDirect3D9_GetDeviceCaps(
    void *this_,
    UINT Adapter,
    D3DDEVTYPE DeviceType,
    D3DCAPS9 *pCaps
) {
	NuWarn("IDirect3D9::GetDeviceCaps not yet implemented");
	
	memset(pCaps, 0x7F, sizeof(D3DCAPS9));
	
	pCaps->DeviceType = D3DDEVTYPE_HAL;
	pCaps->AdapterOrdinal = 0;
	
	pCaps->CursorCaps = D3DCURSORCAPS_COLOR;
	
	pCaps->PresentationIntervals = D3DPRESENT_INTERVAL_DEFAULT;
	
	pCaps->DevCaps =
		D3DDEVCAPS_EXECUTEVIDEOMEMORY | 
		D3DDEVCAPS_TLVERTEXVIDEOMEMORY |
		D3DDEVCAPS_TEXTUREVIDEOMEMORY |
		D3DDEVCAPS_DRAWPRIMTLVERTEX |
		D3DDEVCAPS_CANRENDERAFTERFLIP |
		D3DDEVCAPS_DRAWPRIMITIVES2 |
		D3DDEVCAPS_SEPARATETEXTUREMEMORIES |
		D3DDEVCAPS_DRAWPRIMITIVES2EX |
		D3DDEVCAPS_HWTRANSFORMANDLIGHT |
		D3DDEVCAPS_CANBLTSYSTONONLOCAL |
		D3DDEVCAPS_HWRASTERIZATION |
		D3DDEVCAPS_PUREDEVICE |
		D3DDEVCAPS_RTPATCHES |
		D3DDEVCAPS_RTPATCHHANDLEZERO |
		D3DDEVCAPS_NPATCHES;
	
	pCaps->Caps2 =
		D3DCAPS2_CANAUTOGENMIPMAP |
		D3DCAPS2_CANCALIBRATEGAMMA |
		D3DCAPS2_CANMANAGERESOURCE |
		D3DCAPS2_DYNAMICTEXTURES |
		D3DCAPS2_FULLSCREENGAMMA;
	
	pCaps->Caps3 =
		D3DCAPS3_ALPHA_FULLSCREEN_FLIP_OR_DISCARD |
		D3DCAPS3_COPY_TO_VIDMEM |
		D3DCAPS3_COPY_TO_SYSTEMMEM |
		D3DCAPS3_LINEAR_TO_SRGB_PRESENTATION;
	
	pCaps->PrimitiveMiscCaps =
		D3DPMISCCAPS_MASKZ |
		D3DPMISCCAPS_CULLCW |
		D3DPMISCCAPS_CULLCCW |
		D3DPMISCCAPS_COLORWRITEENABLE |
		D3DPMISCCAPS_CLIPPLANESCALEDPOINTS |
		D3DPMISCCAPS_CLIPTLVERTS |
		D3DPMISCCAPS_TSSARGTEMP |
		D3DPMISCCAPS_NULLREFERENCE |
		D3DPMISCCAPS_INDEPENDENTWRITEMASKS |
		D3DPMISCCAPS_PERSTAGECONSTANT |
		D3DPMISCCAPS_FOGANDSPECULARALPHA |
		D3DPMISCCAPS_SEPARATEALPHABLEND |
		D3DPMISCCAPS_MRTINDEPENDENTBITDEPTHS |
		D3DPMISCCAPS_MRTPOSTPIXELSHADERBLENDING |
		D3DPMISCCAPS_FOGVERTEXCLAMPED;
	
	pCaps->DevCaps2 =
		D3DDEVCAPS2_STREAMOFFSET |
		D3DDEVCAPS2_ADAPTIVETESSRTPATCH |
		D3DDEVCAPS2_ADAPTIVETESSNPATCH |
		D3DDEVCAPS2_CAN_STRETCHRECT_FROM_TEXTURES |
		D3DDEVCAPS2_PRESAMPLEDDMAPNPATCH |
		D3DDEVCAPS2_VERTEXELEMENTSCANSHARESTREAMOFFSET;
	
	pCaps->RasterCaps =
		D3DPRASTERCAPS_DITHER |
		D3DPRASTERCAPS_ZTEST |
		D3DPRASTERCAPS_FOGVERTEX |
		D3DPRASTERCAPS_FOGTABLE |
		D3DPRASTERCAPS_MIPMAPLODBIAS |
		D3DPRASTERCAPS_ZBUFFERLESSHSR |
		D3DPRASTERCAPS_FOGRANGE |
		D3DPRASTERCAPS_ANISOTROPY |
		D3DPRASTERCAPS_WBUFFER |
		D3DPRASTERCAPS_WFOG |
		D3DPRASTERCAPS_ZFOG |
		D3DPRASTERCAPS_COLORPERSPECTIVE |
		D3DPRASTERCAPS_SCISSORTEST |
		D3DPRASTERCAPS_SLOPESCALEDEPTHBIAS |
		D3DPRASTERCAPS_DEPTHBIAS |
		D3DPRASTERCAPS_MULTISAMPLE_TOGGLE;
	
	pCaps->ZCmpCaps = pCaps->AlphaCmpCaps =
		D3DPCMPCAPS_NEVER |
		D3DPCMPCAPS_LESS |
		D3DPCMPCAPS_EQUAL |
		D3DPCMPCAPS_LESSEQUAL |
		D3DPCMPCAPS_GREATER |
		D3DPCMPCAPS_NOTEQUAL |
		D3DPCMPCAPS_GREATEREQUAL |
		D3DPCMPCAPS_ALWAYS;
	
	pCaps->SrcBlendCaps =
	pCaps->DestBlendCaps =
		D3DPBLENDCAPS_ZERO |
		D3DPBLENDCAPS_ONE |
		D3DPBLENDCAPS_DESTALPHA |
		D3DPBLENDCAPS_INVDESTALPHA |
		D3DPBLENDCAPS_SRCALPHA |
		D3DPBLENDCAPS_INVSRCALPHA |
		D3DPBLENDCAPS_DESTCOLOR |
		D3DPBLENDCAPS_INVDESTCOLOR |
		D3DPBLENDCAPS_SRCCOLOR |
		D3DPBLENDCAPS_INVSRCCOLOR |
		D3DPBLENDCAPS_BLENDFACTOR;
	
	pCaps->ShadeCaps =
		D3DPSHADECAPS_COLORGOURAUDRGB |
		D3DPSHADECAPS_SPECULARGOURAUDRGB |
		D3DPSHADECAPS_ALPHAGOURAUDBLEND |
		D3DPSHADECAPS_FOGGOURAUD;
	
	pCaps->TextureCaps =
		D3DPTEXTURECAPS_POW2 |
		D3DPTEXTURECAPS_ALPHA |
		D3DPTEXTURECAPS_TEXREPEATNOTSCALEDBYSIZE |
		D3DPTEXTURECAPS_ALPHAPALETTE |
		D3DPTEXTURECAPS_NONPOW2CONDITIONAL |
		D3DPTEXTURECAPS_PROJECTED |
		D3DPTEXTURECAPS_CUBEMAP |
		D3DPTEXTURECAPS_VOLUMEMAP |
		D3DPTEXTURECAPS_MIPMAP |
		D3DPTEXTURECAPS_MIPVOLUMEMAP |
		D3DPTEXTURECAPS_MIPCUBEMAP |
		D3DPTEXTURECAPS_CUBEMAP_POW2 |
		D3DPTEXTURECAPS_VOLUMEMAP_POW2;
	
	pCaps->TextureFilterCaps =
	pCaps->CubeTextureFilterCaps =
	pCaps->VolumeTextureFilterCaps =
	pCaps->StretchRectFilterCaps =
	pCaps->VertexTextureFilterCaps =
		D3DPTFILTERCAPS_MINFPOINT |
		D3DPTFILTERCAPS_MINFLINEAR |
		D3DPTFILTERCAPS_MINFANISOTROPIC |
		D3DPTFILTERCAPS_MINFPYRAMIDALQUAD |
		D3DPTFILTERCAPS_MIPFPOINT |
		D3DPTFILTERCAPS_MIPFLINEAR |
		D3DPTFILTERCAPS_MAGFPOINT |
		D3DPTFILTERCAPS_MAGFLINEAR |
		D3DPTFILTERCAPS_MAGFANISOTROPIC |
		D3DPTFILTERCAPS_MAGFPYRAMIDALQUAD |
		D3DPTFILTERCAPS_MAGFGAUSSIANQUAD;
	
	pCaps->TextureAddressCaps =
	pCaps->VolumeTextureAddressCaps =
		D3DPTADDRESSCAPS_WRAP |
		D3DPTADDRESSCAPS_MIRROR |
		D3DPTADDRESSCAPS_CLAMP |
		D3DPTADDRESSCAPS_BORDER |
		D3DPTADDRESSCAPS_INDEPENDENTUV |
		D3DPTADDRESSCAPS_MIRRORONCE;
	
	pCaps->LineCaps =
		D3DLINECAPS_TEXTURE |
		D3DLINECAPS_ZTEST |
		D3DLINECAPS_BLEND |
		D3DLINECAPS_ALPHACMP |
		D3DLINECAPS_FOG |
		D3DLINECAPS_ANTIALIAS;
	
	pCaps->MaxTextureWidth = 65536;
	pCaps->MaxTextureHeight = 65536;
	
	pCaps->MaxVolumeExtent = 0xFFFFFFFF;
	
	pCaps->MaxTextureRepeat = 0xFFFFFFFF;
	pCaps->MaxTextureAspectRatio = 0xFFFFFFFF;
	
	pCaps->MaxAnisotropy = 0xFFFFFFFF;
	
	pCaps->MaxVertexW = 10000000000.0f;
	
	pCaps->GuardBandLeft = -10000000.0f;
	pCaps->GuardBandTop = -10000000.0f;
	pCaps->GuardBandRight = 10000000.0f;
	pCaps->GuardBandBottom = 10000000.0f;
	pCaps->ExtentsAdjust = 0.0f;
	
	pCaps->StencilCaps =
		D3DSTENCILCAPS_KEEP |
		D3DSTENCILCAPS_ZERO |
		D3DSTENCILCAPS_REPLACE |
		D3DSTENCILCAPS_INCRSAT |
		D3DSTENCILCAPS_DECRSAT |
		D3DSTENCILCAPS_INVERT |
		D3DSTENCILCAPS_INCR |
		D3DSTENCILCAPS_DECR;
	
	pCaps->VertexProcessingCaps =
		D3DVTXPCAPS_DIRECTIONALLIGHTS |
		D3DVTXPCAPS_LOCALVIEWER |
		D3DVTXPCAPS_MATERIALSOURCE7 |
		D3DVTXPCAPS_POSITIONALLIGHTS |
		D3DVTXPCAPS_TEXGEN |
		D3DVTXPCAPS_TEXGEN_SPHEREMAP |
		D3DVTXPCAPS_TWEENING;
	
	pCaps->FVFCaps = D3DFVFCAPS_PSIZE | 8;
	
	pCaps->TextureOpCaps = 0xFFFFFFFF;
	
	pCaps->MaxTextureBlendStages = 0x10;
	pCaps->MaxSimultaneousTextures = 0xFFFFFFFF;
	pCaps->MaxActiveLights = 0xFFFFFFFF;
	pCaps->MaxUserClipPlanes = 0xFFFFFFFF;
	pCaps->MaxVertexBlendMatrices = 0xFFFFFFFF;
	pCaps->MaxVertexBlendMatrixIndex = 0xFFFFFFFF;
	
	pCaps->MaxPointSize = 100000000.0f;
	
	pCaps->MaxPrimitiveCount = 0xFFFFFFFF;
	pCaps->MaxVertexIndex = 0xFFFFFFFF;
	pCaps->MaxStreams = 0xFFFFFFFF;
	pCaps->MaxStreamStride = 0xFFFFFFFF;
	pCaps->VertexShaderVersion = 0xFFFFFFFF;
	pCaps->MaxVertexShaderConst = 0xFFFFFFFF;
	
	pCaps->PixelShader1xMaxValue = 100000000.0f;
	pCaps->MaxNpatchTessellationLevel = 100000000.0f;
	
	pCaps->MasterAdapterOrdinal = 0;
	pCaps->AdapterOrdinalInGroup = 0;
	pCaps->NumberOfAdaptersInGroup = 1;
	
	pCaps->DeclTypes =
		D3DDTCAPS_UBYTE4 |
		D3DDTCAPS_UBYTE4N |
		D3DDTCAPS_SHORT2N |
		D3DDTCAPS_SHORT4N |
		D3DDTCAPS_USHORT2N |
		D3DDTCAPS_USHORT4N |
		D3DDTCAPS_UDEC3 |
		D3DDTCAPS_DEC3N |
		D3DDTCAPS_FLOAT16_2 |
		D3DDTCAPS_FLOAT16_4;
	
	pCaps->VS20Caps.Caps = 1;
	pCaps->VS20Caps.DynamicFlowControlDepth = 24;
	pCaps->VS20Caps.NumTemps = 0xFFFFFFFF;
	pCaps->PS20Caps.StaticFlowControlDepth = 0xFFFFFFFF;
	
	pCaps->PS20Caps.Caps = 1;
	pCaps->PS20Caps.DynamicFlowControlDepth = 24;
	pCaps->PS20Caps.NumTemps = 0xFFFFFFFF;
	pCaps->PS20Caps.StaticFlowControlDepth = 0xFFFFFFFF;
	pCaps->PS20Caps.NumInstructionSlots = 0xFFFFFFFF;
	
	pCaps->MaxVShaderInstructionsExecuted = 0xFFFFFFFF;
	pCaps->MaxPShaderInstructionsExecuted = 0xFFFFFFFF;
	
	pCaps->MaxVertexShader30InstructionSlots = 0xFFFFFFFF;
	pCaps->MaxPixelShader30InstructionSlots = 0xFFFFFFFF;
	
	return S_OK;
}

WINAPI HRESULT IDirect3D9_CreateDevice(
    void *this_,
    UINT Adapter,
    D3DDEVTYPE DeviceType,
    HWND hFocusWindow,
    DWORD BehaviorFlags,
    D3DPRESENT_PARAMETERS *pPresentationParameters,
    void** ppReturnedDeviceInterface
) {
	NuLog("IDirect3D9::CreateDevice");
	
	INIT_CLASS(IDirect3DDevice9, *ppReturnedDeviceInterface);
	
	if(pPresentationParameters->BackBufferFormat == 0) {
		pPresentationParameters->BackBufferFormat = D3DFMT_X8R8G8B8;
	}
	
	if(pPresentationParameters->BackBufferWidth == 0) {
		pPresentationParameters->BackBufferWidth = 1024;
		pPresentationParameters->BackBufferHeight = 768;
		pPresentationParameters->BackBufferCount = 1;
	}
	
	return S_OK;
}
