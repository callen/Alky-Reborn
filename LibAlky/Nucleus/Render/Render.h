/*
 * Copyright 2007 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __NUCLEUS_RENDER_RENDER_H__
#define __NUCLEUS_RENDER_RENDER_H__

#include <Nucleus/Nucleus.h>
#include <Nucleus/GUI/GUI.h>

struct NuRender_Device_s {
	void *placeholder;
} typedef NuRender_Device;

inline NuRender_Device   *NuRender_CreateDevice();
inline bool               NuRender_FreeDevice(NuRender_Device *device);
inline bool               NuRender_DeviceClear(NuRender_Device *device, float color[4]);

#endif
