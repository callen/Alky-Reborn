/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <Nucleus/Nucleus.h>

#define NUMODULE_NAME "TestCore"

int main(int argc, char **argv) {
	NuCore_Setup();
	
	NuLog("Error: %s", NuCore_Error());
	NuCore_SetError("no real error");
	NuLog("Error part deux: %s", NuCore_Error());
	NuCore_SetError("yet again");
	NuLog("Error part three: %s", NuCore_Error());
	
	NuCore_Teardown();
}
