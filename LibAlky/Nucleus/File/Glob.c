/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <Nucleus/Nucleus.h>
#include <Nucleus/File/File.h>

#define NUMODULE_NAME "NuFile"

inline NuGlob *NuGlob_Glob(char *glob_string) {
	NuGlob *ret;
	glob_t glob_obj;
	
	if(glob(glob_string, 0, None, &glob_obj) != 0)
		return None;
	
	ret = NuMemory_Alloc(sizeof(NuGlob));
	
	memcpy(&ret->glob_obj, &glob_obj, sizeof(glob_t));
	
	ret->glob_string = strdup(glob_string);
	ret->glob_iter = 0;
	
	return ret;
}

inline char *NuGlob_Next(NuGlob *glob) {
	if(glob->glob_iter == glob->glob_obj.gl_pathc)
		return None;
	return glob->glob_obj.gl_pathv[glob->glob_iter++];
}

inline bool NuGlob_Free(NuGlob *glob) {
	NuMemory_Free(glob->glob_string);
	NuMemory_Free(glob);
	
	return True;
}
