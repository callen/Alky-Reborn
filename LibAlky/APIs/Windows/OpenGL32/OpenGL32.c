/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#define NUMODULE_NAME "OpenGL32"

#define DEFINE_OGL_WRAPPERS
#include <APIs/Windows/OpenGL32/OpenGL32.h>

void *ImportOverride(char *method) {
	char method_temp[256];
	void *method_ptr;
	void (*setPtr)(void *ptr);
	void *temp_ptr;
	
	snprintf(method_temp, 256, "%s_ptr", method);
	
	method_ptr = dlsym(RTLD_DEFAULT, method_temp);
	
	if(!method_ptr)
		goto fail;
	
	snprintf(method_temp, 256, "%s_setPtr", method);
	
	setPtr = dlsym(RTLD_DEFAULT, method_temp);
	
	if(!setPtr)
		goto fail;
	
	temp_ptr = dlsym(RTLD_DEFAULT, method);

	if(temp_ptr)
		goto end;
	
	snprintf(method_temp, 256, "%sARB_", method);
	temp_ptr = dlsym(RTLD_DEFAULT, method_temp);
	
	if(temp_ptr)
		goto end;
	
	snprintf(method_temp, 256, "%sEXT_", method);
	temp_ptr = dlsym(RTLD_DEFAULT, method_temp);
	
	if(temp_ptr)
		goto end;
	
	/*
	temp_ptr = SDL_GL_GetProcAddress(method);

	if(temp_ptr)
		goto end;
	
	snprintf(method_temp, 256, "%sARB", method);
	temp_ptr = SDL_GL_GetProcAddress(method_temp);

	if(temp_ptr)
		goto end;
	
	snprintf(method_temp, 256, "%sEXT", method);
	temp_ptr = SDL_GL_GetProcAddress(method_temp);
	
	if(temp_ptr)
		goto end;
	*/
	
fail:
	if(method[0] == 'w' || strcmp(method, "glGetString") == 0 || strcmp(method, "glProgramStringARB") == 0) // || strcmp(method, "glBindTexture")
		return None;
	else {
		NuCore_AddImportAddr(method, method);
		return NuCore_CreateUnsupportedWrapper(method);
	}
	
end:
	setPtr(temp_ptr);

	snprintf(method_temp, 256, "%s_", method);
	return dlsym(None, method_temp);
}

WINAPI HGLRC wglCreateContext(
  HDC  hdc
) {
	NuWarn("wglCreateContext not yet implemented");
	
	return True;
}

WINAPI BOOL wglMakeCurrent(
  HDC  hdc,
  HGLRC  hglrc
) {
	NuWarn("wglMakeCurrent not yet implemented");
	
	return True;
}

WINAPI PROC wglGetProcAddress(
  LPCSTR  lpszProc
) {
	return NuCore_Import("opengl32", lpszProc, None);
}

WINAPI BOOL wglDeleteContext(
  HGLRC  hglrc
) {
	NuWarn("wglDeleteContext not yet implemented");
	
	return True;
}

WINAPI char *wglGetExtensionsStringARB(HDC hdc) {
	NuWarn("wglGetExtensionsStringARB not yet implemented");
	
	return glGetString(GL_EXTENSIONS);
}

WINAPI BOOL wglSwapIntervalEXT(int interval) {
	NuWarn("wglSwapIntervalEXT not yet implemented");
	
	return True;
}

WINAPI BOOL wglGetPixelFormatAttribivARB(
  HDC hDC,
  int iPixelFormat,
  int iLayerPlane,
  UINT nAttributes,
  int *piAttributes,
  int *piValues
) {
	NuWarn("wglGetPixelFormatAttribivARB not yet implemented");
	
	return False;
}

WINAPI GLubyte *glGetString_(GLenum name) {
	GLubyte *ext, *exts = glGetString(name);
	GLubyte *ret;
	
	int i, j, extlen;
	bool end;
	
	if(name != GL_EXTENSIONS)
		return glGetString(name);
	
	if(name != GL_EXTENSIONS)
		return ret;
	
	exts = glGetString(GL_EXTENSIONS);
	NuWarn("Supported extensions: %s", exts);
	
	return exts;
	
	extlen = strlen(exts);
	ret = NuMemory_Alloc(extlen + 1);
	
	for(i = 0; i < extlen; ++i) {
		for(j = i; exts[j] != ' ' && exts[j] != '\0' && j < extlen; ++j)
			continue;
		
		if(exts[j] == ' ')
			exts[j] = '\0';
		
		ext = &exts[i];
		
		i = j;
		
		if(
			(ext[3] == 'N' && ext[4] == 'V') ||
			(ext[3] == 'A' && ext[4] == 'T' && ext[5] == 'I')
		)
			NuWarn("Skipping extension %s", ext);
		else {
			memcpy(&ret[strlen(ret)], ext, strlen(ext) + 1);
			
			ret[strlen(ret) + 1] = '\0';
			ret[strlen(ret)    ] = ' ' ;
		}
	}
	
	NuError("Patched extensions: %s", ret);
	
	return ret;
}

WINAPI void glTexImage2D_memcpy_(
	GLenum target,
	GLint level,
	GLenum internalformat,
	GLsizei width,
	GLsizei height,
	GLint border,
	GLenum format,
	GLenum type,
	const GLvoid *pixels
) {
	int size;
	void *pixel_copy;
	
	size = width * height;
	
	/*
		GL_ALPHA, GL_ALPHA4, GL_ALPHA8, GL_ALPHA12,
		GL_ALPHA16, GL_LUMINANCE, GL_LUMINANCE4,
		GL_LUMINANCE8, GL_LUMINANCE12,
		GL_LUMINANCE16, GL_LUMINANCE_ALPHA,
		GL_LUMINANCE4_ALPHA4,	GL_LUMINANCE6_ALPHA2,
		GL_LUMINANCE8_ALPHA8,	GL_LUMINANCE12_ALPHA4,
		GL_LUMINANCE12_ALPHA12,
		GL_LUMINANCE16_ALPHA16, GL_INTENSITY,
		GL_INTENSITY4, GL_INTENSITY8,
		GL_INTENSITY12, GL_INTENSITY16, GL_R3_G3_B2,
		GL_RGB, GL_RGB4, GL_RGB5, GL_RGB8, GL_RGB10,
		GL_RGB12, GL_RGB16, GL_RGBA, GL_RGBA2,
		GL_RGBA4, GL_RGB5_A1,	GL_RGBA8, GL_RGB10_A2,
		GL_RGBA12, or	GL_RGBA16.
	*/
	
	switch(format) {
		case GL_BGR:
		case GL_RGB:
			size = (size << 1) + size; // 3 items
			break;
		case GL_BGRA:
		case GL_RGBA:
			size <<= 2; // 4 items
			break;
		default:
			NuError("Other format: %i %p", format, format);
			break;
	}
	
	switch(type) {
		case GL_BYTE:
		case GL_UNSIGNED_BYTE:
			break;
		case GL_SHORT:
		case GL_UNSIGNED_SHORT:
			size <<= 1; // Multiply by 2
			break;
		case GL_INT:
		case GL_UNSIGNED_INT:
		case GL_FLOAT:
			size <<= 2; // Multiply by 4
			break;
		default:
			NuError("Other type: %i %p", type, type);
			break;
	}
	
	pixel_copy = NuMemory_Alloc(size);
	memcpy(pixel_copy, pixels, size);
	
	return glTexImage2D(target, level, internalformat, width, height, border, format, type, pixel_copy);
}

/*
OGL_WRAPPER(
	void,
	glProgramStringARB,
	(GLenum target, GLenum format, GLsizei len, const GLvoid *string),
	(target, format, len,  string));
*/

/*
WINAPI void glProgramStringARB_(GLenum target, GLenum format, GLsizei len, const GLvoid *string) {
	NuFile *temp;
	
	temp = NuFile_Open("shaders.txt", "a");
	
	NuFile_Write(temp, string, len);
	NuFile_Write(temp, "\n", 1);
	
	NuFile_Close(temp);
	
	glProgramStringARB(target, format, len, string);
}
*/
