/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#define DEFINE_CLASSES
#include <APIs/Windows/DirectX/DSound/DSound.h>
#include <APIs/Windows/DirectX/DSound/DSound_Classes.h>

#define NUMODULE_NAME "DSound"

WINAPI HRESULT DirectSoundCreate(
  LPCGUID lpcGuidDevice,
  void **ppDS,
  LPUNKNOWN pUnkOuter
) {
	NuLog("DirectSoundCreate");
	
	return -1;
	
	if(pUnkOuter != None)
		ppDS = pUnkOuter;
	
	INIT_CLASS(IDirectSound8, *ppDS);
	
	return S_OK;
}

WINAPI HRESULT DirectSoundCreate8(
  LPCGUID lpcGuidDevice,
  void **ppDS,
  LPUNKNOWN pUnkOuter
) {
	return -1;
	
	return DirectSoundCreate(lpcGuidDevice, ppDS, pUnkOuter);
}

WINAPI HRESULT IDirectSound8_Release(void *this_) {
	NuWarn("IDirectSound8::Release not yet implemented");
	
	return S_OK;
}

WINAPI HRESULT IDirectSound8_Compact(void *this_) {
	NuLog("IDirectSound8::Compact");
	
	return S_OK;
}

WINAPI HRESULT IDirectSound8_CreateSoundBuffer(
  void *this_,
  LPCDSBUFFERDESC pcDSBufferDesc,
  void **ppDSBuffer,
  LPUNKNOWN *pUnkOuter
) {
	NuLog("IDirectSound8::CreateSoundBuffer");
	
	if(ppDSBuffer == None && pUnkOuter != None) {
		ppDSBuffer = pUnkOuter;
		pUnkOuter = None;
	}
	
	INIT_CLASS(IDirectSoundBuffer8, *ppDSBuffer);
	
	if(ppDSBuffer != None && pUnkOuter != None)
		*pUnkOuter = *ppDSBuffer;
	
	return S_OK;
}

WINAPI HRESULT IDirectSound8_GetCaps(
  void *this_,
  LPDSCAPS pDSCaps
) {
	NuLog("IDirectSound8::GetCaps");

	memset(pDSCaps, 0, sizeof(DSCAPS));
	pDSCaps->dwSize = sizeof(DSCAPS);
	
	pDSCaps->dwFlags = 0xFFFFFFFF;
	
	pDSCaps->dwMinSecondarySampleRate = 0;
	pDSCaps->dwMinSecondarySampleRate = 96000;
	
	pDSCaps->dwPrimaryBuffers = 1;
	
	pDSCaps->dwMaxHwMixingAllBuffers = 10;
	pDSCaps->dwMaxHwMixingStaticBuffers = 10;
	pDSCaps->dwMaxHwMixingStreamingBuffers = 10;
	
	pDSCaps->dwFreeHwMixingAllBuffers = 10;
	pDSCaps->dwFreeHwMixingStaticBuffers = 10;
	pDSCaps->dwFreeHwMixingStreamingBuffers = 10;
	
	pDSCaps->dwMaxHw3DAllBuffers = 10;
	pDSCaps->dwMaxHw3DStaticBuffers = 10;
	pDSCaps->dwMaxHw3DStreamingBuffers = 10;
	
	pDSCaps->dwTotalHwMemBytes = 1 * 1024 * 1024;
	pDSCaps->dwFreeHwMemBytes = 1 * 1024 * 1024;
	pDSCaps->dwMaxContigFreeHwMemBytes = 1 * 1024 * 1024;
	
	pDSCaps->dwUnlockTransferRateHwBuffers = 1024;
	
	pDSCaps->dwPlayCpuOverheadSwBuffers = 1;

	return S_OK;
}

WINAPI HRESULT IDirectSound8_Initialize(
  void *this_,
  LPCGUID pcGuidDevice
) {
	NuLog("IDirectSound8::Initialize");
	
	return S_OK;
}

WINAPI HRESULT IDirectSoundBuffer8_Release(void *this_) {
	NuWarn("IDirectSoundBuffer8::Release not yet implemented");
	
	return S_OK;
}
