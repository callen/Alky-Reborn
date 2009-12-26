/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/User32/User32.h>

#define NUMODULE_NAME "User32"

WINAPI UINT MapVirtualKeyA(
  UINT uCode,
  UINT uMapType
) {
	NuWarn("MapVirtualKeyA not yet implemented");
	
	return uCode;
}

WINAPI int ToAscii(
    UINT uVirtKey,
    UINT uScanCode,
    PBYTE lpKeyState,
    LPWORD lpChar,
    UINT uFlags
) {
	NuWarn("ToAscii not yet implemented");
	
	lpChar[0] = 'w';
	lpChar[1] = '\0';
	
	return 1;
}

WINAPI SHORT GetKeyState(
    int nVirtKey
) {
	int sdl_key;
	
	NuWarn("GetKeyState not yet implemented");
	
	switch(nVirtKey) {
		case VK_UP:
			sdl_key = SDLK_UP;
			break;
		case VK_DOWN:
			sdl_key = SDLK_DOWN;
			break;
		case VK_LEFT:
			sdl_key = SDLK_LEFT;
			break;
		case VK_RIGHT:
			sdl_key = SDLK_RIGHT;
			break;
		default:
			return 0;
	}
	
	return NuGUI_KeyState(sdl_key) ? 0x80 : 0;
}
