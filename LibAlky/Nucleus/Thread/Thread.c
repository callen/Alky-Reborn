/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <Nucleus/Nucleus.h>
#include <Nucleus/Process/Process.h>
#include <pthread.h>

#define NUMODULE_NAME "NuThread"

bool NuThread_Setup() {
	NuLog("Initialize");
	
	return True;
}

bool NuThread_Teardown() {
	NuLog("Teardown");
	
	return True;
}

inline void *NuThread_Start(void *start_proc, void *start_param) {
	pthread_t thread;
	
	NuLog("Starting thread at %p with parameter %p", start_proc, start_param);
	
	if(pthread_create(&thread, None, start_proc, start_param) == 0)
		return (void *) thread;
	
	return None;
}