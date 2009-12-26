/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/User32/User32.h>

#define NUMODULE_NAME "User32"

WINAPI HHOOK SetWindowsHookExA(
    int idHook,
    HOOKPROC lpfn,
    HINSTANCE hMod,
    DWORD dwThreadId
) {
	User32 *_Context = User32_GetContext();
	
	NuWarn("SetWindowsHookExA not yet implemented");
	
	switch(idHook) {
		case WH_GETMESSAGE:
			_Context->msgHookProc = lpfn;
			break;
	}
	
	return 0xDEADBEEF;
}
