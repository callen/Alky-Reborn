/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __APIS_WINDOWS_WINMM_WINMM_H__
#define __APIS_WINDOWS_WINMM_WINMM_H__

#include <APIs/Windows/Windows.h>

typedef struct {
    UINT wPeriodMin;
    UINT wPeriodMax;
} TIMECAPS,
*LPTIMECAPS;

WINAPI DWORD timeGetTime(VOID);

WINAPI MMRESULT timeBeginPeriod(
  UINT uPeriod  
);

WINAPI MMRESULT timeEndPeriod(
  UINT uPeriod  
);

WINAPI MMRESULT timeGetDevCaps(
  LPTIMECAPS ptc,
  UINT cbtc
);

#define TIMERR_NOERROR 0

#endif
