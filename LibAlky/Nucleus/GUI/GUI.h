/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __NUCLEUS_GUI_GUI_H__
#define __NUCLEUS_GUI_GUI_H__

#ifdef MAC
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <OpenGL/glext.h>
#include <SDL.h>
#include <SDL_opengl.h>
#elif defined(LINUX)
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>
#include <SDL/SDL.h>
#include <SDL/SDL_video.h>
#include <SDL/SDL_opengl.h>
#elif defined(WINDOWS)
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>
typedef void SDL_Event;
typedef void SDL_mutex;
typedef void SDL_Surface;
#endif

#include <Nucleus/Nucleus.h>

#define COMPRESSED_RGB_S3TC_DXT1_EXT 0x83F0
#define COMPRESSED_RGBA_S3TC_DXT1_EXT 0x83F1
#define COMPRESSED_RGBA_S3TC_DXT3_EXT 0x83F2
#define COMPRESSED_RGBA_S3TC_DXT5_EXT 0x83F3

struct NuGUI_s typedef NuGUI;
struct NuGUI_Window_s typedef NuGUI_Window;
struct NuGUI_WindowClass_s typedef NuGUI_WindowClass;
struct NuGUI_EventLink_s typedef NuGUI_EventLink;
struct NuGUI_EventCallChain_s typedef NuGUI_EventCallChain;

typedef SDL_Event NuGUI_Event;

struct NuGUI_s {
	int wndclassCount;
	NuGUI_WindowClass *wndclasses[256];
	
	int windowCount;
	NuGUI_Window *windows[256];
	
	unsigned char keyboard[512];

	SDL_mutex *eventMutex;
	NuGUI_EventLink *events;
	NuGUI_EventLink *lastEvent;
	
	NuGUI_EventCallChain *callChain;
	NuGUI_EventCallChain *lastCall;
};

typedef void (*NuGUI_EventCallback)(NuGUI_Event *event, void *user_desc);

struct NuGUI_EventCallChain_s {
	NuGUI_EventCallback callback;
	void *user_data;
	NuGUI_EventCallChain *next;
};

struct NuGUI_Window_s {
	int id;
	NuGUI_WindowClass *wndclass;
	
	unsigned short width, height;
	
	SDL_Surface *drawContext;
};

struct NuGUI_WindowClass_s {
	char *className;
	void *callback;
};

struct NuGUI_EventLink_s {
	NuGUI_Event *event;
	NuGUI_EventLink *prev, *next;
};

bool               NuGUI_Setup();
bool               NuGUI_Teardown();

NuGUI_WindowClass *NuGUI_RegisterClass(NuGUI_WindowClass *wndclass);
bool               NuGUI_DeRegisterClass(NuGUI_WindowClass *wndclass);

NuGUI_Window      *NuGUI_OpenWindow(NuGUI_WindowClass *wndclass, int width, int height);
bool               NuGUI_CloseWindow(NuGUI_Window *window);
NuGUI_Window      *NuGUI_WindowById(int id);

bool               NuGUI_SwapBuffers(NuGUI_Window *window);

int                NuGUI_GetEventCount(int type);
NuGUI_Event       *NuGUI_GetEvent(int type, bool pop);
NuGUI_Event       *NuGUI_EventsPresent(bool getEvent);
NuGUI_Event       *NuGUI_PopEvent();
NuGUI_Event       *NuGUI_WaitEvent();
bool               NuGUI_FreeEvent(NuGUI_Event *event);

bool               NuGUI_AddEventCallback(NuGUI_EventCallback callback, void *user_data);

bool               NuGUI_KeyState(int sdl_key);

void               NuGUI_MouseReset();

int                NuGUI_GetTicks();

NuContext_SingletonDecl(NuGUI_GetContext, NuGUI);

#endif
