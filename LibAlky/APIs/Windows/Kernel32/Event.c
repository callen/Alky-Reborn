/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <APIs/Windows/Kernel32/Kernel32.h>

#include <Nucleus/Nucleus.h>

#define NUMODULE_NAME "Kernel32"

WINAPI HANDLE CreateEventA(
  LPSECURITY_ATTRIBUTES lpEventAttributes,
  BOOL bManualReset,
  BOOL bInitialState,
  LPCSTR lpName
) {
	NuWarn("CreateEventA not yet implemented");
	
	NuLog("Creating event: %s", lpName);
	
	return 0xDEADBEEF; // NuEvent_Create(lpName);
}

WINAPI DWORD WaitForSingleObject(
  HANDLE hHandle,
  DWORD dwMilliseconds
) {
	NuWarn("WaitForSingleObject not yet implemented");
	
	// usleep(250);
	
	// SDL_PumpEvents();	
	// NuGUI_PumpEvents();
	
	return WAIT_OBJECT_0;
}

WINAPI BOOL SetEvent(
  HANDLE hEvent
) {
	NuWarn("SetEvent not yet implemented");
	
	return True;
}

WINAPI BOOL ResetEvent(
  HANDLE hEvent
) {
	NuAssert(hEvent != None);
	
	return True; //NuEvent_Reset((NuEvent_Object *) hEvent);
}
