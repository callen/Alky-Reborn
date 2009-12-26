/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/AdvApi32/AdvApi32.h>

#define NUMODULE_NAME "AdvApi32"

WINAPI LONG RegOpenKeyA(
  HKEY hKey,
  LPCSTR lpSubKey,
  PHKEY phkResult
) {
	return RegOpenKeyExA(
		hKey,
		lpSubKey,
		0,
		NULL,
		phkResult
	);
}

WINAPI LONG RegOpenKeyExA(
  HKEY hKey,
  LPCSTR lpSubKey,
  DWORD ulOptions,
  REGSAM samDesired,
  PHKEY phkResult
) {
	NuWarn("RegOpenKeyExA not yet implemented");
	
	NuLog("Trying to open subkey %s", lpSubKey);
	
	*phkResult = 0xDEADBEEF;
	
	return ERROR_SUCCESS;
}

WINAPI LONG RegQueryValueExA(
  HKEY hKey,
  LPCSTR lpValueName,
  LPDWORD lpReserved,
  LPDWORD lpType,
  LPBYTE lpData,
  LPDWORD lpcbData
) {
	DWORD val;
	
	NuWarn("RegQueryValueExA not yet implemented");
	
	NuLog("Key: %s", lpValueName);
	
	if(lpValueName == None)
		return -1;
	
	val = 0x000004ca;
	
	memcpy(lpData, &val, 4);
	
	*lpcbData = 4;
	if(lpType)
		*lpType = 4; // REG_DWORD_LITTLE_ENDIAN
	
	return ERROR_SUCCESS;
}

WINAPI LONG RegCloseKey(
  HKEY hKey
) {
	NuWarn("RegCloseKey not yet implemented");
	
	return ERROR_SUCCESS;
}
