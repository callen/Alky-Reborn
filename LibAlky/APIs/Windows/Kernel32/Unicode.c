/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/Kernel32/Kernel32.h>

#include <Nucleus/Nucleus.h>

#define NUMODULE_NAME "Kernel32"

inline int strlenw(LPCWSTR str) {
	int count = 0;
	
	while(*str) {
		++count;
		++str;
	}
	
	return count;
}

WINAPI int WideCharToMultiByte(
  UINT CodePage,
  DWORD dwFlags,
  LPCWSTR lpWideCharStr,
  int cchWideChar,
  LPSTR lpMultiByteStr,
  int cbMultiByte,
  LPCSTR lpDefaultChar,
  LPBOOL lpUsedDefaultChar
) {
	int i;
	
	NuWarn("WideCharToMultiByte not yet implemented");
	
	NuLog("%p %p", cchWideChar, cbMultiByte);
	
	if(cchWideChar == -1)
		cchWideChar = strlenw(lpWideCharStr) + 1;
	
	if(cbMultiByte == 0)
		return cchWideChar;
	
	if(cchWideChar > cbMultiByte)
		cchWideChar = cbMultiByte;
	
	for(i = 0; i < cchWideChar; ++i) {
		lpMultiByteStr[i] = lpWideCharStr[i];
	}
	
	return i;
}

WINAPI int MultiByteToWideChar(
	UINT CodePage,
	DWORD dwFlags,
	LPCSTR lpMultiByteStr,
	int cchMultiByte,
	LPWSTR lpWideCharStr,
	int cchWideChar
) {
	int i;
	
	NuWarn("MultiByteToWideChar not yet implemented");
	
	if(cchMultiByte == -1)
		cchMultiByte = strlen(lpMultiByteStr) + 1;
	
	if(cchWideChar == 0)
		return cchMultiByte;
	
	if(cchWideChar > cchMultiByte)
		cchWideChar = cchMultiByte;
	
	for(i = 0; i < cchMultiByte; ++i)
		lpWideCharStr[i] = lpMultiByteStr[i];
	
	return cchMultiByte;
}

WINAPI UINT GetOEMCP(void) {
	NuWarn("GetOEMCP not yet implemented");

	return 20127;
}

WINAPI UINT GetACP(void) {
	NuWarn("GetACP not yet implemented");

	return 20127;
}

WINAPI BOOL GetCPInfo(
  UINT CodePage,
  LPCPINFO lpCPInfo
) {
	NuWarn("GetCPInfo not yet implemented");

	lpCPInfo->MaxCharSize = 1;
	lpCPInfo->DefaultChar[0] = 'w';
	lpCPInfo->DefaultChar[1] = '\0';
	memset(lpCPInfo->LeadByte, 0, sizeof(MAX_LEADBYTES));
	lpCPInfo->LeadByte[0] = 'w';

	return True;
}

WINAPI BOOL GetStringTypeW(
	DWORD dwInfoType,
	LPCWSTR lpSrcStr,
	int cchSrc,
	LPWORD lpCharType
) {
	int i;
	
	NuWarn("GetStringTypeW not yet implemented");
	
	for(i = 0; i < min(cchSrc, 16); ++i)
		lpCharType[i] = 0x4;
	
	return True;
}

WINAPI int LCMapStringA(
	LCID Locale,
	DWORD dwMapFlags,
	LPCSTR lpSrcStr,
	int cchSrc,
	LPSTR lpDestStr,
	int cchDest
) {
	NuWarn("LCMapStringA not yet implemented");
	
	if(cchSrc == -1)
		cchSrc = strlen(lpSrcStr) + 1;
	
	if(cchDest == 0)
		return cchSrc;
	
	if(cchSrc > cchDest)
		cchSrc = cchDest;
	
	memcpy(lpDestStr, lpSrcStr, cchSrc);
	
	return cchSrc;
}

WINAPI int LCMapStringW(
	LCID Locale,
	DWORD dwMapFlags,
	LPCWSTR lpSrcStr,
	int cchSrc,
	LPWSTR lpDestStr,
	int cchDest
) {
	NuWarn("LCMapStringW not yet implemented");
	
	if(cchDest == 0)
		return cchSrc;
	
	if(cchSrc > cchDest)
		cchSrc = cchDest;
	
	memcpy(lpDestStr, lpSrcStr, (cchSrc) << 1);
	
	return cchSrc;
}

WINAPI int GetLocaleInfoA(
	LCID Locale,
	LCTYPE LCType,
	LPSTR lpLCData,
	int cchData
) {
	NuWarn("GetLocaleInfoA not yet implemented");
	
	if(cchData != 0)
		strcpy(lpLCData, "0");

	return 2;
}
