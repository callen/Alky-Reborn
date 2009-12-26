/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#define NUMODULE_NAME "OpenAL32"

#define DEFINE_OAL_WRAPPERS
#include <APIs/Windows/OpenAL32/OpenAL32.h>

WINAPI_CDECL ALboolean alIsExtensionPresent_( const ALubyte* extname ) {
	ALboolean ret = alIsExtensionPresent(extname);
	
	if(strcmp(extname, "EAX5.0") == 0)
		ret = True;
	
	NuLog("alIsExtensionPresent(%s) == %s", extname, ret ? "True" : "False");
	
	return ret;
}
