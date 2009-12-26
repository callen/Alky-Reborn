/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <Nucleus/Nucleus.h>
#include <Nucleus/Process/Process.h>
#include <pthread.h>

#define NUMODULE_NAME "NuMutex"

inline NuMutex *NuMutex_Create() {
	pthread_mutex_t *mutex;
	
	mutex = NuMemory_Alloc(sizeof(pthread_mutex_t));
	
	if(pthread_mutex_init(mutex, None) == 0)
		return mutex;
	
	NuMemory_Free(mutex);
	
	return False;
}

inline bool NuMutex_Lock(NuMutex *mutex) {
	if(pthread_mutex_lock(mutex) == 0)
		return True;
	else
		return False;
}

inline bool NuMutex_Unlock(NuMutex *mutex) {
	if(pthread_mutex_unlock(mutex) == 0)
		return True;
	else
		return False;
}

inline bool NuMutex_Destroy(NuMutex *mutex) {
	bool ret;
	
	if(pthread_mutex_destroy(mutex) == 0)
		ret = True;
	else
		ret = False;
	
	NuMemory_Free(mutex);
	
	return ret;
}
