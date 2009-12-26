/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <Nucleus/Nucleus.h>
#include <Nucleus/GUI/GUI.h>

#include <string.h>

#define NUMODULE_NAME "NuGUI"

int NuGUI_GetTicks() {
	return SDL_GetTicks();
}
