/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/WinMM/WinMM.h>

#define NUMODULE_NAME "WinMM"

WINAPI DWORD timeGetTime(VOID) {
	return NuGUI_GetTicks() * 50;
}

WINAPI MMRESULT timeBeginPeriod(
  UINT uPeriod
) {
	NuWarn("timeBeginPeriod not yet implemented");
	
	return TIMERR_NOERROR;
}

WINAPI MMRESULT timeEndPeriod(
  UINT uPeriod
) {
	NuWarn("timeEndPeriod not yet implemented");
	
	return TIMERR_NOERROR;
}

WINAPI MMRESULT timeGetDevCaps(
  LPTIMECAPS ptc,
  UINT cbtc
) {
	NuWarn("timeGetDevCaps not yet implemented");
	
	ptc->wPeriodMin = 1000;
	ptc->wPeriodMax = 1000;
	
	return TIMERR_NOERROR;
}
