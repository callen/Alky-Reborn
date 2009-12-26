/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __NUCLEUS_MEMORY_MEMORY_H__
#define __NUCLEUS_MEMORY_MEMORY_H__

struct NuMemory_Heap_s {
	size_t size;
	size_t max_size;
	size_t offset;
	char  *memory;
	char  *current;
} typedef NuMemory_Heap;

struct NuMemory_s {
	int tlsCount;
	void *tls[256];
} typedef NuMemory;

void *NuMemory_Alloc(size_t bytes);
void *NuMemory_Realloc(void *addr, size_t bytes);
void  NuMemory_Free(void *addr);

NuMemory_Heap *NuMemory_HeapCreate(size_t min_size, size_t max_size, int flags);
void          *NuMemory_HeapAlloc(NuMemory_Heap *heap, size_t bytes, int flags);
void          *NuMemory_HeapRealloc(NuMemory_Heap *heap, void *mem, size_t bytes, int flags);
bool           NuMemory_HeapFree(NuMemory_Heap *heap, void *addr, int flags);
bool           NuMemory_HeapDestroy(NuMemory_Heap *heap, int flags);
int            NuMemory_HeapSize(NuMemory_Heap *heap, void *addr, int flags);

int            NuMemory_TLSAlloc();
void          *NuMemory_TLSGet(int id);
bool           NuMemory_TLSSet(int id, void *value);

NuContext_SingletonDecl(NuMemory_GetContext, NuMemory);

#endif
