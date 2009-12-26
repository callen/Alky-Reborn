/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __NUCLEUS_CONTEXT_CONTEXT_H__
#define __NUCLEUS_CONTEXT_CONTEXT_H__

#include <Nucleus/Nucleus.h>

struct NuContext_s {
	int   context_count;
	char *keys[256];
	void *contexts[256];
} typedef NuContext;

bool NuContext_Setup();
bool NuContext_Teardown();

int   NuContext_GetContextID(char *key);
void *NuContext_GetContext(int id);
bool  NuContext_SetContext(int id, void *context);

#define NuContext_Singleton(name, class, key) \
inline class *name() { \
	static class *_Context = None; \
	static int    _ContextID = None; \
	\
	if(_Context != None) \
		return _Context; \
	\
	_ContextID = NuContext_GetContextID(key); \
	_Context = NuContext_GetContext(_ContextID); \
	\
	if(_Context != None) \
		return _Context; \
	\
	_Context = (class *) NuMemory_Alloc(sizeof(class)); \
	\
	memset(_Context, 0, sizeof(class)); \
	\
	NuContext_SetContext(_ContextID, _Context); \
	\
	return _Context; \
}

#define NuContext_SingletonDecl(name, class) \
class *name();


#endif
