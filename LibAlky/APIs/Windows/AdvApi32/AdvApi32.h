/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __APIS_WINDOWS_ADVAPI32_ADVAPI32_H__
#define __APIS_WINDOWS_ADVAPI32_ADVAPI32_H__

#include <APIs/Windows/Windows.h>

WINAPI BOOL GetUserNameA(
  LPSTR lpBuffer,
  LPDWORD lpnSize
);

WINAPI LONG RegOpenKeyA(
  HKEY hKey,
  LPCSTR lpSubKey,
  PHKEY phkResult
);

WINAPI LONG RegOpenKeyExA(
  HKEY hKey,
  LPCSTR lpSubKey,
  DWORD ulOptions,
  REGSAM samDesired,
  PHKEY phkResult
);

WINAPI LONG RegQueryValueExA(
  HKEY hKey,
  LPCSTR lpValueName,
  LPDWORD lpReserved,
  LPDWORD lpType,
  LPBYTE lpData,
  LPDWORD lpcbData
);

WINAPI LONG RegCloseKey(
  HKEY hKey
);

#endif
