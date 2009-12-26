/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <Nucleus/Nucleus.h>
#include <Nucleus/GUI/GUI.h>

#include <string.h>

#define NUMODULE_NAME "NuGUI"

NuContext_Singleton(NuGUI_GetContext, NuGUI, NUMODULE_NAME);

bool NuGUI_Setup() {
	NuGUI *_Context;
	
	NuLog("Setup");
	
	_Context = NuGUI_GetContext();
	
	memset(_Context->wndclasses, 0, 256 * sizeof(NuGUI_WindowClass *));
	_Context->wndclassCount = 0;
	
	memset(_Context->windows, 0, 256 * sizeof(NuGUI_Window *));
	_Context->windowCount = 0;
	
	_Context->eventMutex = SDL_CreateMutex();
	_Context->events = None;
	_Context->lastEvent = None;
	
	_Context->callChain = None;
	_Context->lastCall = None;
	
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		NuError("Could not initialize SDL video");
}

bool NuGUI_Teardown() {
	NuGUI *_Context;

	NuLog("Teardown");
	
	_Context = NuGUI_GetContext();
	
	if(_Context != None) {
		// NuMemory_Free(_Context);
		_Context = None;
	}
}
