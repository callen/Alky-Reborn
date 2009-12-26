/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/Kernel32/Kernel32.h>

#define NUMODULE_NAME "Kernel32"

NuContext_Singleton(Kernel32_GetContext, Kernel32, NUMODULE_NAME);

WINAPI void ExitProcess(
    int exit_code
) {
	NuError("ExitProcess called");
}
