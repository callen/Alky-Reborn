/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <Nucleus/Nucleus.h>
#include <Nucleus/Event/Event.h>

#define NUMODULE_NAME "NuEvent"

inline NuEvent_Object *NuEvent_Create(char *name) {
	NuEvent_Object *out;
	
	out = NuMemory_Alloc(sizeof(NuEvent_Object));
	memset(out, 0, sizeof(NuEvent_Object));
	
	out->name = strdup(name);
	
	return out;
}

inline bool NuEvent_Signal(NuEvent_Object *event) {
	event->isSignaled = True;
	
	return True;
}

inline bool NuEvent_Reset(NuEvent_Object *event) {
	event->isSignaled = False;
	
	return True;
}

inline bool NuEvent_Status(NuEvent_Object *event) {
	return event->isSignaled;
}