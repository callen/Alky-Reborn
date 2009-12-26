/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <Nucleus/Nucleus.h>
#include <Nucleus/Memory/Memory.h>

#define NUMODULE_NAME "NuMemory"

NuContext_Singleton(NuMemory_GetContext, NuMemory, NUMODULE_NAME);

void *NuMemory_Alloc(size_t bytes) {
	void *ptr;
	
	// NuLog("Allocating %p (%i) bytes of memory", bytes, bytes);
	
	ptr = malloc(bytes);
	
	memset(ptr, 0, bytes);
	
	return ptr;
}

void *NuMemory_Realloc(void *addr, size_t bytes) {
	return realloc(addr, bytes);
}

void  NuMemory_Free(void *addr) {
	free(addr);
}
