/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <Nucleus/Nucleus.h>
#include <Nucleus/GUI/GUI.h>

#include <string.h>

#define NUMODULE_NAME "NuGUI"

NuGUI_Window *NuGUI_OpenWindow(
	NuGUI_WindowClass *wndclass,
	int width, int height
) {
	SDL_Surface* drawContext;
	Uint32 flags;
	NuGUI *_Context;
	NuGUI_Window *window;

	NuLog("Creating window");
	
	window = (NuGUI_Window *) NuMemory_Alloc(sizeof(NuGUI_Window));
	
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	
	window->wndclass = wndclass;
	
	_Context = NuGUI_GetContext();

	window->id = _Context->windowCount;
	
	window->width = width;
	window->height = height;
	
	flags = SDL_OPENGL; // | SDL_FULLSCREEN
	
	if(width != 0 && height != 0)
		window->drawContext = SDL_SetVideoMode(width, height, 0, flags);
	else
		window->drawContext = None;
	
	_Context->windows[_Context->windowCount++] = window;
	
	return window;
}

bool NuGUI_CloseWindow(NuGUI_Window *window) {
	NuWarn("CloseWindow not yet implemented");
	return False;
}

NuGUI_Window *NuGUI_WindowById(int id) {
	NuGUI *_Context = NuGUI_GetContext();
	
	if(id >= _Context->windowCount) {
		NuWarn("Requesting out of bounds window -- but passing back the last one");
		id = _Context->windowCount - 1;
	}
	
	return _Context->windows[id];
}

bool NuGUI_SwapBuffers(NuGUI_Window *window) {
	SDL_GL_SwapBuffers();
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	return True;
}
