/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/GDI32/GDI32.h>

#define NUMODULE_NAME "GDI32"

WINAPI int SetDIBits(
  HDC hdc,
  HBITMAP hbmp,
  UINT uStartScan,
  UINT cScanLines,
  CONST VOID *lpvBits,
  CONST BITMAPINFO *lpbmi,
  UINT fuColorUse
) {
	unsigned char *temp = hbmp;
	
	NuLog("SetDIBits");
	
	temp += uStartScan * lpbmi->bmiHeader.biWidth * lpbmi->bmiHeader.biBitCount / 8;
	
	memcpy(temp, lpvBits, lpbmi->bmiHeader.biWidth * lpbmi->bmiHeader.biHeight * lpbmi->bmiHeader.biBitCount / 8);
	
	return cScanLines;
}

WINAPI HBITMAP CreateDIBSection(
  HDC hdc,
  CONST BITMAPINFO *pbmi,
  UINT iUsage,
  VOID **ppvBits,
  HANDLE hSection,
  DWORD dwOffset
) {
	int bytes, i;
	unsigned char *pixels;
	
	bytes = pbmi->bmiHeader.biWidth * pbmi->bmiHeader.biHeight * pbmi->bmiHeader.biBitCount / 8;
	
	pixels = (unsigned char *) NuMemory_Alloc(bytes);
	
	if(hSection != None)
		memcpy(pixels, (char *) hSection + dwOffset, bytes);
	
	*ppvBits = pixels;
	
	return (HBITMAP) pixels;
}
