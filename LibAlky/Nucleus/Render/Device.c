/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <Nucleus/Nucleus.h>
#include <Nucleus/Render/Render.h>

#define NUMODULE_NAME "NuRender"

inline NuRender_Device *NuRender_CreateDevice() {
	return NuMemory_Alloc(sizeof(NuRender_Device));
}

inline bool NuRender_FreeDevice(NuRender_Device *device) {
	NuMemory_Free(device);
	
	return True;
}

inline bool NuRender_DeviceClear(NuRender_Device *device, float color[4]) {
	glClearColor(color[0], color[1], color[2], color[3]);
	glClear(GL_STENCIL_BUFFER_BIT|GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	return True;
}
