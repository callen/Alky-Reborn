/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/Kernel32/Kernel32.h>

#define NUMODULE_NAME "Kernel32"

WINAPI DWORD GetVersion(void) {
	NuLog("GetVersion");
	
	// return 0x4000;
	return 0x80000004;
}

WINAPI BOOL GetVersionExA(
  LPOSVERSIONINFOEXA lpVersionInfo
) {
	NuLog("GetVersionExA");
	
	lpVersionInfo->dwMajorVersion = 5;
	lpVersionInfo->dwMinorVersion = 1;
	lpVersionInfo->dwBuildNumber = 0;
	lpVersionInfo->dwPlatformId = 2;
	memset(lpVersionInfo->szCSDVersion, 0, 128);
	strcpy((char *) lpVersionInfo->szCSDVersion, (char *) "Alky!");
	
	return True;
}

WINAPI VOID GetStartupInfoA(
  LPSTARTUPINFOA lpStartupInfo
) {
	NuLog("GetStartupInfoA");
	
	memset(lpStartupInfo, 0, sizeof(STARTUPINFOA));
	lpStartupInfo->cb = sizeof(STARTUPINFOA);
	
	lpStartupInfo->lpDesktop = "Desktop";
	lpStartupInfo->lpTitle = "Alky!";
	lpStartupInfo->dwX = 0;
	lpStartupInfo->dwY = 0;
	lpStartupInfo->dwXSize = 100;
	lpStartupInfo->dwYSize = 100;
	
	lpStartupInfo->dwXCountChars = 100;
	lpStartupInfo->dwYCountChars = 100;
	
	lpStartupInfo->dwFillAttribute = 0;
	
	lpStartupInfo->dwFlags = 0;
	
	lpStartupInfo->wShowWindow = 0;
	
	lpStartupInfo->hStdInput = 1;
	lpStartupInfo->hStdOutput = 1;
	lpStartupInfo->hStdError = 1;
}

WINAPI VOID GetStartupInfoW(
  LPSTARTUPINFOW lpStartupInfo
) {
	NuLog("GetStartupInfoW");
	
	memset(lpStartupInfo, 0, sizeof(STARTUPINFOA));
	lpStartupInfo->cb = sizeof(STARTUPINFOA);
	
	lpStartupInfo->lpDesktop = L"Desktop";
	lpStartupInfo->lpTitle = L"Alky!";
	lpStartupInfo->dwX = 0;
	lpStartupInfo->dwY = 0;
	lpStartupInfo->dwXSize = 100;
	lpStartupInfo->dwYSize = 100;
	
	lpStartupInfo->dwXCountChars = 100;
	lpStartupInfo->dwYCountChars = 100;
	
	lpStartupInfo->dwFillAttribute = 0;
	
	lpStartupInfo->dwFlags = 0;
	
	lpStartupInfo->wShowWindow = 0;
	
	lpStartupInfo->hStdInput = 1;
	lpStartupInfo->hStdOutput = 1;
	lpStartupInfo->hStdError = 1;
}
WINAPI void GetSystemInfo(
  LPSYSTEM_INFO lpSystemInfo
) {
	NuWarn("GetSystemInfo not yet implemented");
	
	memset(lpSystemInfo, 0, sizeof(SYSTEM_INFO));
}

WINAPI LPSTR GetCommandLineA(void) {
	NuWarn("GetCommandLineA not yet implemented");
	return "";
}

WINAPI LPWSTR GetCommandLineW(void) {
	NuWarn("GetCommandLineW not yet implemented");
	return L"";
}

WINAPI LPVOID GetEnvironmentStringsW(void) {
	NuWarn("GetEnvironmentStringsW not yet implemented");
	return None;
}

WINAPI LPVOID GetEnvironmentStrings(void) {
	NuWarn("GetEnvironmentStrings not yet implemented");
	return "\0\0";
}

WINAPI BOOL FreeEnvironmentStringsA(
  LPCH lpszEnvironmentBlock
) {
	NuWarn("FreeEnvironmentStringsA not yet implemented");
	
	return True;
}

WINAPI LPSTR lstrcpyA(
    LPSTR lpString1,
    LPSTR lpString2
) {
	strcpy(lpString1, lpString2);
	
	return lpString1;
}

WINAPI int MulDiv(
  int nNumber,
  int nNumerator,
  int nDenominator
) {
	long long int product;
	
	product = ((long long int) nNumber) * ((long long int) nNumerator);
	
	return (int) (product / nDenominator);
}

WINAPI VOID Sleep(
  DWORD dwMilliseconds
) {
	usleep(dwMilliseconds);
}

WINAPI BOOL IsProcessorFeaturePresent(
  DWORD ProcessorFeature
) {
	NuWarn("IsProcessorFeaturePresent not yet implemented");
	
	return True;
}
