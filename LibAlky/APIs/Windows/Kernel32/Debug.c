/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/Kernel32/Kernel32.h>

#define NUMODULE_NAME "Kernel32"

WINAPI void OutputDebugStringA(
  LPCSTR lpOutputString
) {
	NuWarn("%s", lpOutputString);
}

WINAPI BOOL IsDebuggerPresent() {
	return False;
}
