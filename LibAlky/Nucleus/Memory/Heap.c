/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <Nucleus/Nucleus.h>
#include <Nucleus/Memory/Memory.h>

#define NUMODULE_NAME "NuMemory"

#define FAKE_HEAP

NuMemory_Heap *NuMemory_HeapCreate(size_t min_size, size_t max_size, int flags) {
	NuMemory_Heap *heap;
	
#ifdef FAKE_HEAP
	return NuMemory_Alloc(1);
#else
	
	NuLog("Creating heap of %i-%i bytes", min_size, max_size);
	
	heap = (NuMemory_Heap *) NuMemory_Alloc(sizeof(NuMemory_Heap));
	
	heap->offset = 0;
	
	if(max_size == 0) {
		heap->size = min_size;
		heap->max_size = heap->size;
	}
	else
		heap->size = heap->max_size = max_size;
	
	heap->memory = heap->current = (char *) NuMemory_Alloc(heap->size);

	memset(heap->memory, 0, heap->size);
	
	return heap;
#endif
}

void *NuMemory_HeapAlloc(NuMemory_Heap *heap, size_t bytes, int flags) {
#ifdef FAKE_HEAP
	return NuMemory_Alloc(bytes);
#else
	
	void *ret = (void *) heap->current;
	
	if(heap->offset + bytes > heap->max_size) {
		// NuWarn("Allocating %i bytes off heap %p.  Heap full!", bytes, heap);
		ret = NuMemory_Alloc(bytes + 1);
		
		return ret;
	}
	
	heap->current += bytes;
	heap->offset  += bytes;
	
	return ret;
#endif
}

void *NuMemory_HeapRealloc(NuMemory_Heap *heap, void *mem, size_t bytes, int flags) {
#ifdef FAKE_HEAP
	NuError("Realloc not supported in heaps");
	return NuMemory_Realloc(mem, bytes);
#else
	NuError("Realloc not supported in heaps");
#endif
}

bool NuMemory_HeapFree(NuMemory_Heap *heap, void *addr, int flags) {
#ifdef FAKE_HEAP
	NuMemory_Free(addr);
	
	return True;
#else
	
	NuAssert(heap != None);
	
	if(addr < heap->memory || addr >= heap->current)
		NuMemory_Free(addr);
	
	return True;
#endif
}

bool NuMemory_HeapDestroy(NuMemory_Heap *heap, int flags) {
	NuLog("Destroying heap %p", heap);
	
	NuMemory_Free(heap);
	return True;
}

int NuMemory_HeapSize(NuMemory_Heap *heap, void *addr, int flags) {
	// NuWarn("HeapSize not yet implemented");
	
	NuAssert(heap != None);
	
	return 0xFFFFFFFF; // heap->size;
}
