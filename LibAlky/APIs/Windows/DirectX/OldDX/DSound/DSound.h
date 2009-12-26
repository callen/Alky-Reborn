/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __APIS_WINDOWS_DSOUND_DSOUND_H__
#define __APIS_WINDOWS_DSOUND_DSOUND_H__

#include <APIs/Windows/Windows.h>
#include <APIs/Windows/COM/COM.h>

typedef struct DSCAPS {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwMinSecondarySampleRate, dwMaxSecondarySampleRate;
    DWORD dwPrimaryBuffers;
    DWORD dwMaxHwMixingAllBuffers;
    DWORD dwMaxHwMixingStaticBuffers;
    DWORD dwMaxHwMixingStreamingBuffers;
    DWORD dwFreeHwMixingAllBuffers;
    DWORD dwFreeHwMixingStaticBuffers;
    DWORD dwFreeHwMixingStreamingBuffers;
    DWORD dwMaxHw3DAllBuffers;
    DWORD dwMaxHw3DStaticBuffers;
    DWORD dwMaxHw3DStreamingBuffers;
    DWORD dwFreeHw3DAllBuffers;
    DWORD dwFreeHw3DStaticBuffers;
    DWORD dwFreeHw3DStreamingBuffers;
    DWORD dwTotalHwMemBytes;
    DWORD dwFreeHwMemBytes;
    DWORD dwMaxContigFreeHwMemBytes;
    DWORD dwUnlockTransferRateHwBuffers;
    DWORD dwPlayCpuOverheadSwBuffers;
    DWORD dwReserved1;
    DWORD dwReserved2;
} DSCAPS,
*LPDSCAPS;

typedef struct WAVEFORMATEX {
    WORD wFormatTag;
    WORD nChannels;
    DWORD nSamplesPerSec;
    DWORD nAvgBytesPerSec;
    WORD nBlockAlign;
    WORD wBitsPerSample;
    WORD cbSize;
} WAVEFORMATEX,
*LPWAVEFORMATEX;

typedef struct DSBUFFERDESC {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwBufferBytes;
    DWORD dwReserved;
    LPWAVEFORMATEX lpwfxFormat;
    GUID guid3DAlgorithm;
} DSBUFFERDESC,
*LPCDSBUFFERDESC;

WINAPI HRESULT DirectSoundCreate(
  LPCGUID lpcGuidDevice,
  void **ppDS,
  LPUNKNOWN pUnkOuter
);

WINAPI HRESULT DirectSoundCreate8(
  LPCGUID lpcGuidDevice,
  void **ppDS,
  LPUNKNOWN pUnkOuter
);

WINAPI HRESULT IDirectSound8_Release(void *this_);

WINAPI HRESULT IDirectSound8_Compact(void *this_);

WINAPI HRESULT IDirectSound8_CreateSoundBuffer(
  void *this_,
  LPCDSBUFFERDESC pcDSBufferDesc,
  void **ppDSBuffer,
  LPUNKNOWN *pUnkOuter
);

WINAPI HRESULT IDirectSound8_GetCaps(
  void *this_,
  LPDSCAPS pDSCaps
);

WINAPI HRESULT IDirectSound8_Initialize(
  void *this_,
  LPCGUID pcGuidDevice
);

WINAPI HRESULT IDirectSoundBuffer8_Release(void *this_);

#endif
