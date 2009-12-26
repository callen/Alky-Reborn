/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <Nucleus/Nucleus.h>
#include <Nucleus/Process/Process.h>

#define NUMODULE_NAME "NuProcess"

inline int       NuProcess_ProcessID() {
	NuLog("ProcessID");
	
	return getpid();
}
