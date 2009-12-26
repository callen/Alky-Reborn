/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __APIS_WINDOWS_VERSION_VERSION_H__
#define __APIS_WINDOWS_VERSION_VERSION_H__

#include <APIs/Windows/Windows.h>

typedef struct VS_FIXEDFILEINFO_s {
  DWORD dwSignature; 
  DWORD dwStrucVersion; 
  DWORD dwFileVersionMS; 
  DWORD dwFileVersionLS; 
  DWORD dwProductVersionMS; 
  DWORD dwProductVersionLS; 
  DWORD dwFileFlagsMask; 
  DWORD dwFileFlags; 
  DWORD dwFileOS; 
  DWORD dwFileType; 
  DWORD dwFileSubtype; 
  DWORD dwFileDateMS; 
  DWORD dwFileDateLS; 
} VS_FixedFileInfo;

WINAPI DWORD GetFileVersionInfoSizeA(
    LPCSTR lptstrFilename,
    LPDWORD lpdwHandle
);

WINAPI BOOL GetFileVersionInfoA(
    LPCSTR lptstrFilename,
    DWORD dwHandle,
    DWORD dwLen,
    LPVOID lpData
);

WINAPI BOOL VerQueryValueA(
    const LPVOID pBlock,
    LPSTR lpSubBlock,
    LPVOID *lplpBuffer,
    PUINT puLen
);

#define VFT_VXD                 0x00000005L
#define VFT2_DRV_SOUND          0x00000009L

#endif
