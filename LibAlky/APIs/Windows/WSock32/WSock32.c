/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#define DEFINE_SOCK_WRAPPERS
#include <APIs/Windows/WSock32/WSock32.h>

#define NUMODULE_NAME "WSock32"

WINAPI int WSAStartup(
  WORD wVersionRequested,
  LPWSADATA lpWSAData
) {
	NuLog("WSAStartup");
	
	memset(lpWSAData, 0, sizeof(WSADATA));
	
	lpWSAData->wVersion = 2;
	lpWSAData->wHighVersion = 2;
	
	strcpy(lpWSAData->szDescription, "Alky Network Stack");
	strcpy(lpWSAData->szSystemStatus, "Alky Network Stack");
	
	return 0;
}

WINAPI int WSAGetLastError() {
	NuWarn("WSAGetLastError not yet implemented");
	
	return 0;
}

WINAPI int ioctlsocket(
  int s,
  long cmd,
  u_long* argp
) {
	NuWarn("ioctlsocket not yet implemented");
	
	return 1;
}
