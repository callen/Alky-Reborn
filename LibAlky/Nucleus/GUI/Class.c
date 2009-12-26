/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <Nucleus/Nucleus.h>
#include <Nucleus/GUI/GUI.h>

#include <string.h>

#define NUMODULE_NAME "NuGUI"

NuGUI_WindowClass *NuGUI_RegisterClass(NuGUI_WindowClass *wndclass) {
	NuGUI_WindowClass *copy;
	NuGUI *_Context;
	
	NuLog("Registering window class");
	
	_Context = NuGUI_GetContext();
	
	copy = (NuGUI_WindowClass *) NuMemory_Alloc(sizeof(NuGUI_WindowClass));
	memcpy(copy, wndclass, sizeof(NuGUI_WindowClass));
	
	_Context->wndclasses[_Context->wndclassCount] = copy;
	
	_Context->wndclassCount++;
	
	return copy;
}

bool NuGUI_DeRegisterClass(NuGUI_WindowClass *wndclass) {
	NuLog("DeRegistering window class");
}

NuGUI_WindowClass *NuGUI_ClassById(int id) {
	NuGUI *_Context;
	NuGUI_WindowClass *wndclass;
	int i;
	
	_Context = NuGUI_GetContext();
	
	// Check for bounds.
	if(id > _Context->wndclassCount - 2)
		return None;
	
	return _Context->wndclasses[id];
}

NuGUI_WindowClass *NuGUI_ClassByName(char *name) {
	NuGUI *_Context;
	NuGUI_WindowClass *wndclass;
	int i;

	_Context = NuGUI_GetContext();
	
	for(i = 0, wndclass = _Context->wndclasses[i]; i < _Context->wndclassCount; ++i) {
		if(strcmp(wndclass->className, name) == 0)
			return wndclass;
	}
	
	return None;
}
