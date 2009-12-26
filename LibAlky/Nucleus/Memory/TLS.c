/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <Nucleus/Nucleus.h>
#include <Nucleus/Memory/Memory.h>

#define NUMODULE_NAME "NuMemory"

int NuMemory_TLSAlloc() {
	NuMemory *_Context = NuMemory_GetContext();
	
	NuLog("Allocating TLS spot %i", _Context->tlsCount);
	
	_Context->tls[_Context->tlsCount] = 0;
	
	return _Context->tlsCount++;
}

void *NuMemory_TLSGet(int id) {
	NuMemory *_Context = NuMemory_GetContext();
	
	// NuLog("Getting TLS spot %i", id);
	
	if(_Context->tlsCount <= id) {
		NuWarn("Out of bounds TLSGet!");
		return None;
	}
	
	return _Context->tls[id];
}

bool NuMemory_TLSSet(int id, void *value) {
	NuMemory *_Context = NuMemory_GetContext();
	
	// NuLog("Setting TLS spot %i", id);
	
	if(_Context->tlsCount <= id) {
		NuWarn("Out of bounds TLSSet!");
		return False;
	}
	
	_Context->tls[id] = value;
	
	return True;
}
