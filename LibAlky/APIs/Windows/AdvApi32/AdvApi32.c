/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/AdvApi32/AdvApi32.h>

#define NUMODULE_NAME "AdvApi32"

WINAPI BOOL GetUserNameA(
  LPSTR lpBuffer,
  LPDWORD lpnSize
) {
	NuWarn("GetUserNameA not yet implemented");
	
	snprintf(lpBuffer, *lpnSize, "daeken");
	
	*lpnSize = strlen(lpBuffer) + 1;
	
	return True;
}
