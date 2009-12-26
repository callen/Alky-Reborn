/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/Version/Version.h>

#define NUMODULE_NAME "Version"

WINAPI DWORD GetFileVersionInfoSizeA(
    LPCSTR lptstrFilename,
    LPDWORD lpdwHandle
) {
	NuWarn("GetFileVersionInfoSizeA not yet implemented");
	
	NuLog("Filename: %s", lptstrFilename);
	
	*lpdwHandle = 0;
	
	return 4;
}

WINAPI BOOL GetFileVersionInfoA(
    LPCSTR lptstrFilename,
    DWORD dwHandle,
    DWORD dwLen,
    LPVOID lpData
) {
	NuWarn("GetFileVersionInfoA not yet implemented");
	
	NuLog("Filename: %s", lptstrFilename);
	
	memset(lpData, 0xFF, dwLen);
	
	return True;
}

WINAPI BOOL VerQueryValueA(
    const LPVOID pBlock,
    LPSTR lpSubBlock,
    LPVOID *lplpBuffer,
    PUINT puLen
) {
	int i;
	
	VS_FixedFileInfo *fixedFileInfo;
	
	NuWarn("VerQueryValueA not yet implemented");
	
	NuLog("Requested SubBlock: %s puLen: %i", lpSubBlock, *puLen);
	
	fixedFileInfo = NuMemory_Alloc(sizeof(VS_FixedFileInfo));
	
	memset(fixedFileInfo, 0x7F, sizeof(VS_FixedFileInfo));
	
	fixedFileInfo->dwSignature = 0xFEEF04BD;
	fixedFileInfo->dwFileFlagsMask = 0;
	fixedFileInfo->dwFileFlags = 0;
	fixedFileInfo->dwFileType = VFT_VXD;
	fixedFileInfo->dwFileSubtype = VFT2_DRV_SOUND;
	
	*lplpBuffer = fixedFileInfo;
	
	*puLen = sizeof(VS_FixedFileInfo);
	
	return True;
}
