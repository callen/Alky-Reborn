/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <Nucleus/Nucleus.h>
#include <Nucleus/GUI/GUI.h>

#include <string.h>

#define NUMODULE_NAME "NuGUI"

void NuGUI_MouseReset() {
	SDL_ShowCursor(SDL_DISABLE);
	SDL_WarpMouse(128, 128);
}