/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __NUCLEUS_THREAD_THREAD_H__
#define __NUCLEUS_THREAD_THREAD_H__

#ifndef WINDOWS
#include <pthread.h>

typedef pthread_mutex_t NuMutex;
#else
typedef void NuMutex;
#endif

bool               NuThread_Setup();
bool               NuThread_Teardown();

inline void       *NuThread_Start(void *start_proc, void *start_param);

inline NuMutex    *NuMutex_Create();
inline bool        NuMutex_Lock(NuMutex *mutex);
inline bool        NuMutex_Unlock(NuMutex *mutex);
inline bool        NuMutex_Destroy(NuMutex *mutex);

#endif
