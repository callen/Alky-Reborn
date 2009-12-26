/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <Nucleus/Nucleus.h>
#include <Nucleus/Context/Context.h>
#include <string.h>

#define NUMODULE_NAME "NuContext"

NuContext *NuContext_Context = None; // Repetitititive

bool NuContext_Setup() {
	if(NuContext_Context != None)
		return True;
	
	NuLog("Setup");
	
	NuContext_Context = (NuContext *) malloc(sizeof(NuContext));
	memset(NuContext_Context->keys, 0, 256 * sizeof(char *));
	memset(NuContext_Context->contexts, 0, 256 * sizeof(void *));
	NuContext_Context->context_count = 0;
	
	return True;
}

bool NuContext_Teardown() {
	NuLog("Teardown");
}

int NuContext_GetContextID(char *key) {
	int i;
	
	NuContext_Setup();
	
	for(i = 0; i < NuContext_Context->context_count; ++i) {
		if(strcmp(NuContext_Context->keys[i], key) == 0)
			return i;
	}
	
	NuContext_Context->keys[NuContext_Context->context_count] = key;
	NuContext_Context->contexts[NuContext_Context->context_count] = None;
	
	return NuContext_Context->context_count++;
}

void *NuContext_GetContext(int id) {
	return NuContext_Context->contexts[id];
}

bool NuContext_SetContext(int id, void *context) {
	NuContext_Context->contexts[id] = context;
	
	return True;
}
