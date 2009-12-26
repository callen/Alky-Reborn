/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __APIS_WINDOWS_OPENGL32_OPENGL32_H__
#define __APIS_WINDOWS_OPENGL32_OPENGL32_H__

#include <APIs/Windows/Windows.h>

WINAPI HGLRC wglCreateContext(
  HDC  hdc
);

WINAPI BOOL wglMakeCurrent(
  HDC  hdc,
  HGLRC  hglrc
);

WINAPI PROC wglGetProcAddress(
  LPCSTR  lpszProc
);

WINAPI BOOL wglDeleteContext(
  HGLRC  hglrc
);

WINAPI char *wglGetExtensionsStringARB(HDC hdc);

WINAPI BOOL wglSwapIntervalEXT(int interval);

WINAPI BOOL wglGetPixelFormatAttribivARB(
  HDC hDC,
  int iPixelFormat,
  int iLayerPlane,
  UINT nAttributes,
  int *piAttributes,
  int *piValues
);

#ifdef DEFINE_OGL_WRAPPERS
#define OGL_WRAPPER(ret, name, args, argnames) \
ret (*name##_ptr) args = None; \
void name##_setPtr(void *ptr) { name##_ptr = ptr; } \
WINAPI ret name##_ args { /* NuWarn(#name); */ return name##_ptr argnames; } \
ret (*name##ARB_ptr) args = None; \
void name##ARB_setPtr(void *ptr) { name##ARB_ptr = ptr; } \
WINAPI ret name##ARB_ args { /* NuWarn(#name); */ return name##ARB_ptr argnames; }\
ret (*name##EXT_ptr) args = None; \
void name##EXT_setPtr(void *ptr) { name##EXT_ptr = ptr; } \
WINAPI ret name##EXT_ args { /* NuWarn(#name); */ return name##EXT_ptr argnames; }

#define OGL_WRAPPER_NULL(ret, name, args, argnames) \
ret (*name##_ptr) args = None; \
void name##_setPtr(void *ptr) { name##_ptr = ptr; } \
WINAPI ret name##_ args { NuWarn(#name); } \
ret (*name##ARB_ptr) args = None; \
void name##ARB_setPtr(void *ptr) { name##ARB_ptr = ptr; } \
WINAPI ret name##ARB_ args { NuWarn(#name); }

#define OGL_WRAPPER_DEBUG(ret, name, args, argnames) \
ret (*name##_ptr) args = None; \
void name##_setPtr(void *ptr) { name##_ptr = ptr; } \
WINAPI ret name##_ args { \
	static bool test = False; \
	static bool test2 = False; \
	\
	/* NuWarn(#name); */ \
	\
	if(texture == 0x28) { \
		if(test) \
			texture = 0x27; \
		test = True; \
	} \
	if(texture == 0x428) { \
		texture = 0x427; \
	} \
	\
	return name##_ptr argnames; \
} \
ret (*name##ARB_ptr) args = None; \
void name##ARB_setPtr(void *ptr) { name##ARB_ptr = ptr; } \
WINAPI ret name##ARB_ args { NuWarn(#name); return name##ARB_ptr argnames; }

#define OGL_WRAPPER_DEBUG2(ret, name, args, argnames) \
ret (*name##_ptr) args = None; \
void name##_setPtr(void *ptr) { name##_ptr = ptr; } \
WINAPI ret name##_ args { \
	if(*textures == 0x428) \
		return; \
	\
	name##_ptr argnames; \
} \
ret (*name##ARB_ptr) args = None; \
void name##ARB_setPtr(void *ptr) { name##ARB_ptr = ptr; } \
WINAPI ret name##ARB_ args { NuWarn(#name); return name##ARB_ptr argnames; }

/*
if(texture == 0x427) { \
	texture = 0x426; \
} \
\
else 
*/

#define OGL_WRAPPER_CDECL(ret, name, args, argnames) \
WINAPI_CDECL ret name##_ args { return name##_ptr argnames; }
#else
#define OGL_WRAPPER(ret, name, args, argnames) \
WINAPI ret name##_ args; \
WINAPI ret name##ARB_ args
#define OGL_WRAPPER_CDECL(ret, name, args, argnames) \
WINAPI_CDECL ret name##_ args
#define OGL_WRAPPER_DEBUG(ret, name, args, argnames) \
WINAPI ret name##_ args;
#define OGL_WRAPPER_DEBUG2(ret, name, args, argnames) \
WINAPI ret name##_ args;
#endif

#define OGL_WRAPPER_PROTO(ret, name, args, argnames) \
WINAPI ret name##_ args; \
WINAPI ret name##ARB_ args

OGL_WRAPPER(
	void,
	glAccum,
	(GLenum op, GLfloat value),
	(op, value));
OGL_WRAPPER(
	void,
	glAlphaFunc,
	(GLenum func, GLclampf ref),
	(func, ref));
OGL_WRAPPER(
	GLboolean,
	glAreTexturesResident,
	(GLsizei n, const GLuint *textures, GLboolean *residences),
	(n,  textures,  residences));
OGL_WRAPPER(
	void,
	glArrayElement,
	(GLint i),
	(i));
OGL_WRAPPER(
	void,
	glBegin,
	(GLenum mode),
	(mode));

#ifdef MAC
OGL_WRAPPER_DEBUG(
	void,
	glBindTexture,
	(GLenum target, GLuint texture),
	(target, texture));
#else
OGL_WRAPPER(
	void,
	glBindTexture,
	(GLenum target, GLuint texture),
	(target, texture));
#endif

OGL_WRAPPER(
	void,
	glBitmap,
	(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap),
	(width, height, xorig, yorig, xmove, ymove,  bitmap));
OGL_WRAPPER(
	void,
	glBlendColor,
	(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha),
	(red, green, blue, alpha));
OGL_WRAPPER(
	void,
	glBlendEquation,
	(GLenum mode),
	(mode));
OGL_WRAPPER(
	void,
	glBlendEquationSeparate,
	(GLenum modeRGB, GLenum modeAlpha),
	(modeRGB, modeAlpha));
OGL_WRAPPER(
	void,
	glBlendFunc,
	(GLenum sfactor, GLenum dfactor),
	(sfactor, dfactor));
OGL_WRAPPER(
	void,
	glCallList,
	(GLuint list),
	(list));
OGL_WRAPPER(
	void,
	glCallLists,
	(GLsizei n, GLenum type, const GLvoid *lists),
	(n, type,  lists));
OGL_WRAPPER(
	void,
	glClear,
	(GLbitfield mask),
	(mask));
OGL_WRAPPER(
	void,
	glClearAccum,
	(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha),
	(red, green, blue, alpha));
OGL_WRAPPER(
	void,
	glClearColor,
	(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha),
	(red, green, blue, alpha));
OGL_WRAPPER(
	void,
	glClearDepth,
	(GLclampd depth),
	(depth));
OGL_WRAPPER(
	void,
	glClearIndex,
	(GLfloat c),
	(c));
OGL_WRAPPER(
	void,
	glClearStencil,
	(GLint s),
	(s));
OGL_WRAPPER(
	void,
	glClipPlane,
	(GLenum plane, const GLdouble *equation),
	(plane,  equation));
OGL_WRAPPER(
	void,
	glColor3b,
	(GLbyte red, GLbyte green, GLbyte blue),
	(red, green, blue));
OGL_WRAPPER(
	void,
	glColor3bv,
	(const GLbyte *v),
	( v));
OGL_WRAPPER(
	void,
	glColor3d,
	(GLdouble red, GLdouble green, GLdouble blue),
	(red, green, blue));
OGL_WRAPPER(
	void,
	glColor3dv,
	(const GLdouble *v),
	( v));
OGL_WRAPPER(
	void,
	glColor3f,
	(GLfloat red, GLfloat green, GLfloat blue),
	(red, green, blue));
OGL_WRAPPER(
	void,
	glColor3fv,
	(const GLfloat *v),
	( v));
OGL_WRAPPER(
	void,
	glColor3i,
	(GLint red, GLint green, GLint blue),
	(red, green, blue));
OGL_WRAPPER(
	void,
	glColor3iv,
	(const GLint *v),
	( v));
OGL_WRAPPER(
	void,
	glColor3s,
	(GLshort red, GLshort green, GLshort blue),
	(red, green, blue));
OGL_WRAPPER(
	void,
	glColor3sv,
	(const GLshort *v),
	( v));
OGL_WRAPPER(
	void,
	glColor3ub,
	(GLubyte red, GLubyte green, GLubyte blue),
	(red, green, blue));
OGL_WRAPPER(
	void,
	glColor3ubv,
	(const GLubyte *v),
	( v));
OGL_WRAPPER(
	void,
	glColor3ui,
	(GLuint red, GLuint green, GLuint blue),
	(red, green, blue));
OGL_WRAPPER(
	void,
	glColor3uiv,
	(const GLuint *v),
	( v));
OGL_WRAPPER(
	void,
	glColor3us,
	(GLushort red, GLushort green, GLushort blue),
	(red, green, blue));
OGL_WRAPPER(
	void,
	glColor3usv,
	(const GLushort *v),
	( v));
OGL_WRAPPER(
	void,
	glColor4b,
	(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha),
	(red, green, blue, alpha));
OGL_WRAPPER(
	void,
	glColor4bv,
	(const GLbyte *v),
	( v));
OGL_WRAPPER(
	void,
	glColor4d,
	(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha),
	(red, green, blue, alpha));
OGL_WRAPPER(
	void,
	glColor4dv,
	(const GLdouble *v),
	( v));
OGL_WRAPPER(
	void,
	glColor4f,
	(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha),
	(red, green, blue, alpha));
OGL_WRAPPER(
	void,
	glColor4fv,
	(const GLfloat *v),
	( v));
OGL_WRAPPER(
	void,
	glColor4i,
	(GLint red, GLint green, GLint blue, GLint alpha),
	(red, green, blue, alpha));
OGL_WRAPPER(
	void,
	glColor4iv,
	(const GLint *v),
	( v));
OGL_WRAPPER(
	void,
	glColor4s,
	(GLshort red, GLshort green, GLshort blue, GLshort alpha),
	(red, green, blue, alpha));
OGL_WRAPPER(
	void,
	glColor4sv,
	(const GLshort *v),
	( v));
OGL_WRAPPER(
	void,
	glColor4ub,
	(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha),
	(red, green, blue, alpha));
OGL_WRAPPER(
	void,
	glColor4ubv,
	(const GLubyte *v),
	( v));
OGL_WRAPPER(
	void,
	glColor4ui,
	(GLuint red, GLuint green, GLuint blue, GLuint alpha),
	(red, green, blue, alpha));
OGL_WRAPPER(
	void,
	glColor4uiv,
	(const GLuint *v),
	( v));
OGL_WRAPPER(
	void,
	glColor4us,
	(GLushort red, GLushort green, GLushort blue, GLushort alpha),
	(red, green, blue, alpha));
OGL_WRAPPER(
	void,
	glColor4usv,
	(const GLushort *v),
	( v));
OGL_WRAPPER(
	void,
	glColorMask,
	(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha),
	(red, green, blue, alpha));
OGL_WRAPPER(
	void,
	glColorMaterial,
	(GLenum face, GLenum mode),
	(face, mode));
OGL_WRAPPER(
	void,
	glColorPointer,
	(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer),
	(size, type, stride,  pointer));
OGL_WRAPPER(
	void,
	glColorSubTable,
	(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data),
	(target, start, count, format, type,  data));
OGL_WRAPPER(
	void,
	glColorTable,
	(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table),
	(target, internalformat, width, format, type,  table));
OGL_WRAPPER(
	void,
	glColorTableParameterfv,
	(GLenum target, GLenum pname, const GLfloat *params),
	(target, pname,  params));
OGL_WRAPPER(
	void,
	glColorTableParameteriv,
	(GLenum target, GLenum pname, const GLint *params),
	(target, pname,  params));
OGL_WRAPPER(
	void,
	glConvolutionFilter1D,
	(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image),
	(target, internalformat, width, format, type,  image));
OGL_WRAPPER(
	void,
	glConvolutionFilter2D,
	(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image),
	(target, internalformat, width, height, format, type,  image));
OGL_WRAPPER(
	void,
	glConvolutionParameterf,
	(GLenum target, GLenum pname, GLfloat params),
	(target, pname, params));
OGL_WRAPPER(
	void,
	glConvolutionParameterfv,
	(GLenum target, GLenum pname, const GLfloat *params),
	(target, pname,  params));
OGL_WRAPPER(
	void,
	glConvolutionParameteri,
	(GLenum target, GLenum pname, GLint params),
	(target, pname, params));
OGL_WRAPPER(
	void,
	glConvolutionParameteriv,
	(GLenum target, GLenum pname, const GLint *params),
	(target, pname,  params));
OGL_WRAPPER(
	void,
	glCopyColorSubTable,
	(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width),
	(target, start, x, y, width));
OGL_WRAPPER(
	void,
	glCopyColorTable,
	(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width),
	(target, internalformat, x, y, width));
OGL_WRAPPER(
	void,
	glCopyConvolutionFilter1D,
	(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width),
	(target, internalformat, x, y, width));
OGL_WRAPPER(
	void,
	glCopyConvolutionFilter2D,
	(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height),
	(target, internalformat, x, y, width, height));
OGL_WRAPPER(
	void,
	glCopyPixels,
	(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type),
	(x, y, width, height, type));
OGL_WRAPPER(
	void,
	glCopyTexImage1D,
	(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border),
	(target, level, internalformat, x, y, width, border));
OGL_WRAPPER(
	void,
	glCopyTexImage2D,
	(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border),
	(target, level, internalformat, x, y, width, height, border));
OGL_WRAPPER(
	void,
	glCopyTexSubImage1D,
	(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width),
	(target, level, xoffset, x, y, width));
OGL_WRAPPER(
	void,
	glCopyTexSubImage2D,
	(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height),
	(target, level, xoffset, yoffset, x, y, width, height));
OGL_WRAPPER(
	void,
	glCopyTexSubImage3D,
	(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height),
	(target, level, xoffset, yoffset, zoffset, x, y, width, height));
OGL_WRAPPER(
	void,
	glCullFace,
	(GLenum mode),
	(mode));
OGL_WRAPPER(
	void,
	glDeleteLists,
	(GLuint list, GLsizei range),
	(list, range));

#ifdef MAC
OGL_WRAPPER_DEBUG2(
	void,
	glDeleteTextures,
	(GLsizei n, const GLuint *textures),
	(n,  textures));
#else
OGL_WRAPPER(
	void,
	glDeleteTextures,
	(GLsizei n, const GLuint *textures),
	(n,  textures));
#endif
OGL_WRAPPER(
	void,
	glDepthFunc,
	(GLenum func),
	(func));
OGL_WRAPPER(
	void,
	glDepthMask,
	(GLboolean flag),
	(flag));
OGL_WRAPPER(
	void,
	glDepthRange,
	(GLclampd zNear, GLclampd zFar),
	(zNear, zFar));
OGL_WRAPPER(
	void,
	glDisable,
	(GLenum cap),
	(cap));
OGL_WRAPPER(
	void,
	glDisableClientState,
	(GLenum array),
	(array));
OGL_WRAPPER(
	void,
	glDrawArrays,
	(GLenum mode, GLint first, GLsizei count),
	(mode, first, count));
OGL_WRAPPER(
	void,
	glDrawBuffer,
	(GLenum mode),
	(mode));
OGL_WRAPPER(
	void,
	glDrawElements,
	(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices),
	(mode, count, type,  indices));
OGL_WRAPPER(
	void,
	glDrawPixels,
	(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels),
	(width, height, format, type,  pixels));
OGL_WRAPPER(
	void,
	glDrawRangeElements,
	(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices),
	(mode, start, end, count, type,  indices));
OGL_WRAPPER(
	void,
	glEdgeFlag,
	(GLboolean flag),
	(flag));
OGL_WRAPPER(
	void,
	glEdgeFlagPointer,
	(GLsizei stride, const GLvoid *pointer),
	(stride,  pointer));
OGL_WRAPPER(
	void,
	glEdgeFlagv,
	(const GLboolean *flag),
	( flag));
OGL_WRAPPER(
	void,
	glEnable,
	(GLenum cap),
	(cap));
OGL_WRAPPER(
	void,
	glEnableClientState,
	(GLenum array),
	(array));
OGL_WRAPPER(
	void,
	glEnd,
	(),
	());
OGL_WRAPPER(
	void,
	glEndList,
	(),
	());
OGL_WRAPPER(
	void,
	glEvalCoord1d,
	(GLdouble u),
	(u));
OGL_WRAPPER(
	void,
	glEvalCoord1dv,
	(const GLdouble *u),
	( u));
OGL_WRAPPER(
	void,
	glEvalCoord1f,
	(GLfloat u),
	(u));
OGL_WRAPPER(
	void,
	glEvalCoord1fv,
	(const GLfloat *u),
	( u));
OGL_WRAPPER(
	void,
	glEvalCoord2d,
	(GLdouble u, GLdouble v),
	(u, v));
OGL_WRAPPER(
	void,
	glEvalCoord2dv,
	(const GLdouble *u),
	( u));
OGL_WRAPPER(
	void,
	glEvalCoord2f,
	(GLfloat u, GLfloat v),
	(u, v));
OGL_WRAPPER(
	void,
	glEvalCoord2fv,
	(const GLfloat *u),
	( u));
OGL_WRAPPER(
	void,
	glEvalMesh1,
	(GLenum mode, GLint i1, GLint i2),
	(mode, i1, i2));
OGL_WRAPPER(
	void,
	glEvalMesh2,
	(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2),
	(mode, i1, i2, j1, j2));
OGL_WRAPPER(
	void,
	glEvalPoint1,
	(GLint i),
	(i));
OGL_WRAPPER(
	void,
	glEvalPoint2,
	(GLint i, GLint j),
	(i, j));
OGL_WRAPPER(
	void,
	glFeedbackBuffer,
	(GLsizei size, GLenum type, GLfloat *buffer),
	(size, type,  buffer));
OGL_WRAPPER(
	void,
	glFinish,
	(),
	());
OGL_WRAPPER(
	void,
	glFlush,
	(),
	());
OGL_WRAPPER(
	void,
	glFogf,
	(GLenum pname, GLfloat param),
	(pname, param));
OGL_WRAPPER(
	void,
	glFogfv,
	(GLenum pname, const GLfloat *params),
	(pname,  params));
OGL_WRAPPER(
	void,
	glFogi,
	(GLenum pname, GLint param),
	(pname, param));
OGL_WRAPPER(
	void,
	glFogiv,
	(GLenum pname, const GLint *params),
	(pname,  params));
OGL_WRAPPER(
	void,
	glFrontFace,
	(GLenum mode),
	(mode));
OGL_WRAPPER(
	void,
	glFrustum,
	(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar),
	(left, right, bottom, top, zNear, zFar));
OGL_WRAPPER(
	GLuint,
	glGenLists,
	(GLsizei range),
	(range));
OGL_WRAPPER(
	void,
	glGenTextures,
	(GLsizei n, GLuint *textures),
	(n,  textures));
OGL_WRAPPER(
	void,
	glGetBooleanv,
	(GLenum pname, GLboolean *params),
	(pname,  params));
OGL_WRAPPER(
	void,
	glGetClipPlane,
	(GLenum plane, GLdouble *equation),
	(plane,  equation));
OGL_WRAPPER(
	void,
	glGetColorTable,
	(GLenum target, GLenum format, GLenum type, GLvoid *table),
	(target, format, type,  table));
OGL_WRAPPER(
	void,
	glGetColorTableParameterfv,
	(GLenum target, GLenum pname, GLfloat *params),
	(target, pname,  params));
OGL_WRAPPER(
	void,
	glGetColorTableParameteriv,
	(GLenum target, GLenum pname, GLint *params),
	(target, pname,  params));
OGL_WRAPPER(
	void,
	glGetConvolutionFilter,
	(GLenum target, GLenum format, GLenum type, GLvoid *image),
	(target, format, type,  image));
OGL_WRAPPER(
	void,
	glGetConvolutionParameterfv,
	(GLenum target, GLenum pname, GLfloat *params),
	(target, pname,  params));
OGL_WRAPPER(
	void,
	glGetConvolutionParameteriv,
	(GLenum target, GLenum pname, GLint *params),
	(target, pname,  params));
OGL_WRAPPER(
	void,
	glGetDoublev,
	(GLenum pname, GLdouble *params),
	(pname,  params));
OGL_WRAPPER(
	GLenum,
	glGetError,
	(),
	());
OGL_WRAPPER(
	void,
	glGetFloatv,
	(GLenum pname, GLfloat *params),
	(pname,  params));
OGL_WRAPPER(
	void,
	glGetHistogram,
	(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values),
	(target, reset, format, type,  values));
OGL_WRAPPER(
	void,
	glGetHistogramParameterfv,
	(GLenum target, GLenum pname, GLfloat *params),
	(target, pname,  params));
OGL_WRAPPER(
	void,
	glGetHistogramParameteriv,
	(GLenum target, GLenum pname, GLint *params),
	(target, pname,  params));
OGL_WRAPPER(
	void,
	glGetIntegerv,
	(GLenum pname, GLint *params),
	(pname,  params));
OGL_WRAPPER(
	void,
	glGetLightfv,
	(GLenum light, GLenum pname, GLfloat *params),
	(light, pname,  params));
OGL_WRAPPER(
	void,
	glGetLightiv,
	(GLenum light, GLenum pname, GLint *params),
	(light, pname,  params));
OGL_WRAPPER(
	void,
	glGetMapdv,
	(GLenum target, GLenum query, GLdouble *v),
	(target, query,  v));
OGL_WRAPPER(
	void,
	glGetMapfv,
	(GLenum target, GLenum query, GLfloat *v),
	(target, query,  v));
OGL_WRAPPER(
	void,
	glGetMapiv,
	(GLenum target, GLenum query, GLint *v),
	(target, query,  v));
OGL_WRAPPER(
	void,
	glGetMaterialfv,
	(GLenum face, GLenum pname, GLfloat *params),
	(face, pname,  params));
OGL_WRAPPER(
	void,
	glGetMaterialiv,
	(GLenum face, GLenum pname, GLint *params),
	(face, pname,  params));
OGL_WRAPPER(
	void,
	glGetMinmax,
	(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values),
	(target, reset, format, type,  values));
OGL_WRAPPER(
	void,
	glGetMinmaxParameterfv,
	(GLenum target, GLenum pname, GLfloat *params),
	(target, pname,  params));
OGL_WRAPPER(
	void,
	glGetMinmaxParameteriv,
	(GLenum target, GLenum pname, GLint *params),
	(target, pname,  params));
OGL_WRAPPER(
	void,
	glGetPixelMapfv,
	(GLenum map, GLfloat *values),
	(map,  values));
OGL_WRAPPER(
	void,
	glGetPixelMapuiv,
	(GLenum map, GLuint *values),
	(map,  values));
OGL_WRAPPER(
	void,
	glGetPixelMapusv,
	(GLenum map, GLushort *values),
	(map,  values));
OGL_WRAPPER(
	void,
	glGetPointerv,
	(GLenum pname, GLvoid* *params),
	(pname,  params));
OGL_WRAPPER(
	void,
	glGetPolygonStipple,
	(GLubyte *mask),
	( mask));
OGL_WRAPPER(
	void,
	glGetSeparableFilter,
	(GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span),
	(target, format, type,  row,  column,  span));
OGL_WRAPPER(
	void,
	glGetTexEnvfv,
	(GLenum target, GLenum pname, GLfloat *params),
	(target, pname,  params));
OGL_WRAPPER(
	void,
	glGetTexEnviv,
	(GLenum target, GLenum pname, GLint *params),
	(target, pname,  params));
OGL_WRAPPER(
	void,
	glGetTexGendv,
	(GLenum coord, GLenum pname, GLdouble *params),
	(coord, pname,  params));
OGL_WRAPPER(
	void,
	glGetTexGenfv,
	(GLenum coord, GLenum pname, GLfloat *params),
	(coord, pname,  params));
OGL_WRAPPER(
	void,
	glGetTexGeniv,
	(GLenum coord, GLenum pname, GLint *params),
	(coord, pname,  params));
OGL_WRAPPER(
	void,
	glGetTexImage,
	(GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels),
	(target, level, format, type,  pixels));
OGL_WRAPPER(
	void,
	glGetTexLevelParameterfv,
	(GLenum target, GLint level, GLenum pname, GLfloat *params),
	(target, level, pname,  params));
OGL_WRAPPER(
	void,
	glGetTexLevelParameteriv,
	(GLenum target, GLint level, GLenum pname, GLint *params),
	(target, level, pname,  params));
OGL_WRAPPER(
	void,
	glGetTexParameterfv,
	(GLenum target, GLenum pname, GLfloat *params),
	(target, pname,  params));
OGL_WRAPPER(
	void,
	glGetTexParameteriv,
	(GLenum target, GLenum pname, GLint *params),
	(target, pname,  params));
OGL_WRAPPER(
	void,
	glHint,
	(GLenum target, GLenum mode),
	(target, mode));
OGL_WRAPPER(
	void,
	glHistogram,
	(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink),
	(target, width, internalformat, sink));
OGL_WRAPPER(
	void,
	glIndexMask,
	(GLuint mask),
	(mask));
OGL_WRAPPER(
	void,
	glIndexPointer,
	(GLenum type, GLsizei stride, const GLvoid *pointer),
	(type, stride,  pointer));
OGL_WRAPPER(
	void,
	glIndexd,
	(GLdouble c),
	(c));
OGL_WRAPPER(
	void,
	glIndexdv,
	(const GLdouble *c),
	( c));
OGL_WRAPPER(
	void,
	glIndexf,
	(GLfloat c),
	(c));
OGL_WRAPPER(
	void,
	glIndexfv,
	(const GLfloat *c),
	( c));
OGL_WRAPPER(
	void,
	glIndexi,
	(GLint c),
	(c));
OGL_WRAPPER(
	void,
	glIndexiv,
	(const GLint *c),
	( c));
OGL_WRAPPER(
	void,
	glIndexs,
	(GLshort c),
	(c));
OGL_WRAPPER(
	void,
	glIndexsv,
	(const GLshort *c),
	( c));
OGL_WRAPPER(
	void,
	glIndexub,
	(GLubyte c),
	(c));
OGL_WRAPPER(
	void,
	glIndexubv,
	(const GLubyte *c),
	( c));
OGL_WRAPPER(
	void,
	glInitNames,
	(),
	());
OGL_WRAPPER(
	void,
	glInterleavedArrays,
	(GLenum format, GLsizei stride, const GLvoid *pointer),
	(format, stride,  pointer));
OGL_WRAPPER(
	GLboolean,
	glIsEnabled,
	(GLenum cap),
	(cap));
OGL_WRAPPER(
	GLboolean,
	glIsList,
	(GLuint list),
	(list));
OGL_WRAPPER(
	GLboolean,
	glIsTexture,
	(GLuint texture),
	(texture));
OGL_WRAPPER(
	void,
	glLightModelf,
	(GLenum pname, GLfloat param),
	(pname, param));
OGL_WRAPPER(
	void,
	glLightModelfv,
	(GLenum pname, const GLfloat *params),
	(pname,  params));
OGL_WRAPPER(
	void,
	glLightModeli,
	(GLenum pname, GLint param),
	(pname, param));
OGL_WRAPPER(
	void,
	glLightModeliv,
	(GLenum pname, const GLint *params),
	(pname,  params));
OGL_WRAPPER(
	void,
	glLightf,
	(GLenum light, GLenum pname, GLfloat param),
	(light, pname, param));
OGL_WRAPPER(
	void,
	glLightfv,
	(GLenum light, GLenum pname, const GLfloat *params),
	(light, pname,  params));
OGL_WRAPPER(
	void,
	glLighti,
	(GLenum light, GLenum pname, GLint param),
	(light, pname, param));
OGL_WRAPPER(
	void,
	glLightiv,
	(GLenum light, GLenum pname, const GLint *params),
	(light, pname,  params));
OGL_WRAPPER(
	void,
	glLineStipple,
	(GLint factor, GLushort pattern),
	(factor, pattern));
OGL_WRAPPER(
	void,
	glLineWidth,
	(GLfloat width),
	(width));
OGL_WRAPPER(
	void,
	glListBase,
	(GLuint base),
	(base));
OGL_WRAPPER(
	void,
	glLoadIdentity,
	(),
	());
OGL_WRAPPER(
	void,
	glLoadMatrixd,
	(const GLdouble *m),
	( m));
OGL_WRAPPER(
	void,
	glLoadMatrixf,
	(const GLfloat *m),
	( m));
OGL_WRAPPER(
	void,
	glLoadName,
	(GLuint name),
	(name));
OGL_WRAPPER(
	void,
	glLogicOp,
	(GLenum opcode),
	(opcode));
OGL_WRAPPER(
	void,
	glMap1d,
	(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points),
	(target, u1, u2, stride, order,  points));
OGL_WRAPPER(
	void,
	glMap1f,
	(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points),
	(target, u1, u2, stride, order,  points));
OGL_WRAPPER(
	void,
	glMap2d,
	(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points),
	(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder,  points));
OGL_WRAPPER(
	void,
	glMap2f,
	(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points),
	(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder,  points));
OGL_WRAPPER(
	void,
	glMapGrid1d,
	(GLint un, GLdouble u1, GLdouble u2),
	(un, u1, u2));
OGL_WRAPPER(
	void,
	glMapGrid1f,
	(GLint un, GLfloat u1, GLfloat u2),
	(un, u1, u2));
OGL_WRAPPER(
	void,
	glMapGrid2d,
	(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2),
	(un, u1, u2, vn, v1, v2));
OGL_WRAPPER(
	void,
	glMapGrid2f,
	(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2),
	(un, u1, u2, vn, v1, v2));
OGL_WRAPPER(
	void,
	glMaterialf,
	(GLenum face, GLenum pname, GLfloat param),
	(face, pname, param));
OGL_WRAPPER(
	void,
	glMaterialfv,
	(GLenum face, GLenum pname, const GLfloat *params),
	(face, pname,  params));
OGL_WRAPPER(
	void,
	glMateriali,
	(GLenum face, GLenum pname, GLint param),
	(face, pname, param));
OGL_WRAPPER(
	void,
	glMaterialiv,
	(GLenum face, GLenum pname, const GLint *params),
	(face, pname,  params));
OGL_WRAPPER(
	void,
	glMatrixMode,
	(GLenum mode),
	(mode));
OGL_WRAPPER(
	void,
	glMinmax,
	(GLenum target, GLenum internalformat, GLboolean sink),
	(target, internalformat, sink));
OGL_WRAPPER(
	void,
	glMultMatrixd,
	(const GLdouble *m),
	( m));
OGL_WRAPPER(
	void,
	glMultMatrixf,
	(const GLfloat *m),
	( m));
OGL_WRAPPER(
	void,
	glNewList,
	(GLuint list, GLenum mode),
	(list, mode));
OGL_WRAPPER(
	void,
	glNormal3b,
	(GLbyte nx, GLbyte ny, GLbyte nz),
	(nx, ny, nz));
OGL_WRAPPER(
	void,
	glNormal3bv,
	(const GLbyte *v),
	( v));
OGL_WRAPPER(
	void,
	glNormal3d,
	(GLdouble nx, GLdouble ny, GLdouble nz),
	(nx, ny, nz));
OGL_WRAPPER(
	void,
	glNormal3dv,
	(const GLdouble *v),
	( v));
OGL_WRAPPER(
	void,
	glNormal3f,
	(GLfloat nx, GLfloat ny, GLfloat nz),
	(nx, ny, nz));
OGL_WRAPPER(
	void,
	glNormal3fv,
	(const GLfloat *v),
	( v));
OGL_WRAPPER(
	void,
	glNormal3i,
	(GLint nx, GLint ny, GLint nz),
	(nx, ny, nz));
OGL_WRAPPER(
	void,
	glNormal3iv,
	(const GLint *v),
	( v));
OGL_WRAPPER(
	void,
	glNormal3s,
	(GLshort nx, GLshort ny, GLshort nz),
	(nx, ny, nz));
OGL_WRAPPER(
	void,
	glNormal3sv,
	(const GLshort *v),
	( v));
OGL_WRAPPER(
	void,
	glNormalPointer,
	(GLenum type, GLsizei stride, const GLvoid *pointer),
	(type, stride,  pointer));
OGL_WRAPPER(
	void,
	glOrtho,
	(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar),
	(left, right, bottom, top, zNear, zFar));
OGL_WRAPPER(
	void,
	glPassThrough,
	(GLfloat token),
	(token));
OGL_WRAPPER(
	void,
	glPixelMapfv,
	(GLenum map, GLint mapsize, const GLfloat *values),
	(map, mapsize,  values));
OGL_WRAPPER(
	void,
	glPixelMapuiv,
	(GLenum map, GLint mapsize, const GLuint *values),
	(map, mapsize,  values));
OGL_WRAPPER(
	void,
	glPixelMapusv,
	(GLenum map, GLint mapsize, const GLushort *values),
	(map, mapsize,  values));
OGL_WRAPPER(
	void,
	glPixelStoref,
	(GLenum pname, GLfloat param),
	(pname, param));
OGL_WRAPPER(
	void,
	glPixelStorei,
	(GLenum pname, GLint param),
	(pname, param));
OGL_WRAPPER(
	void,
	glPixelTransferf,
	(GLenum pname, GLfloat param),
	(pname, param));
OGL_WRAPPER(
	void,
	glPixelTransferi,
	(GLenum pname, GLint param),
	(pname, param));
OGL_WRAPPER(
	void,
	glPixelZoom,
	(GLfloat xfactor, GLfloat yfactor),
	(xfactor, yfactor));
OGL_WRAPPER(
	void,
	glPointSize,
	(GLfloat size),
	(size));
OGL_WRAPPER(
	void,
	glPolygonMode,
	(GLenum face, GLenum mode),
	(face, mode));
OGL_WRAPPER(
	void,
	glPolygonOffset,
	(GLfloat factor, GLfloat units),
	(factor, units));
OGL_WRAPPER(
	void,
	glPolygonStipple,
	(const GLubyte *mask),
	( mask));
OGL_WRAPPER(
	void,
	glPopAttrib,
	(),
	());
OGL_WRAPPER(
	void,
	glPopClientAttrib,
	(),
	());
OGL_WRAPPER(
	void,
	glPopMatrix,
	(),
	());
OGL_WRAPPER(
	void,
	glPopName,
	(),
	());
OGL_WRAPPER(
	void,
	glPrioritizeTextures,
	(GLsizei n, const GLuint *textures, const GLclampf *priorities),
	(n,  textures,  priorities));
OGL_WRAPPER(
	void,
	glPushAttrib,
	(GLbitfield mask),
	(mask));
OGL_WRAPPER(
	void,
	glPushClientAttrib,
	(GLbitfield mask),
	(mask));
OGL_WRAPPER(
	void,
	glPushMatrix,
	(),
	());
OGL_WRAPPER(
	void,
	glPushName,
	(GLuint name),
	(name));
OGL_WRAPPER(
	void,
	glRasterPos2d,
	(GLdouble x, GLdouble y),
	(x, y));
OGL_WRAPPER(
	void,
	glRasterPos2dv,
	(const GLdouble *v),
	( v));
OGL_WRAPPER(
	void,
	glRasterPos2f,
	(GLfloat x, GLfloat y),
	(x, y));
OGL_WRAPPER(
	void,
	glRasterPos2fv,
	(const GLfloat *v),
	( v));
OGL_WRAPPER(
	void,
	glRasterPos2i,
	(GLint x, GLint y),
	(x, y));
OGL_WRAPPER(
	void,
	glRasterPos2iv,
	(const GLint *v),
	( v));
OGL_WRAPPER(
	void,
	glRasterPos2s,
	(GLshort x, GLshort y),
	(x, y));
OGL_WRAPPER(
	void,
	glRasterPos2sv,
	(const GLshort *v),
	( v));
OGL_WRAPPER(
	void,
	glRasterPos3d,
	(GLdouble x, GLdouble y, GLdouble z),
	(x, y, z));
OGL_WRAPPER(
	void,
	glRasterPos3dv,
	(const GLdouble *v),
	( v));
OGL_WRAPPER(
	void,
	glRasterPos3f,
	(GLfloat x, GLfloat y, GLfloat z),
	(x, y, z));
OGL_WRAPPER(
	void,
	glRasterPos3fv,
	(const GLfloat *v),
	( v));
OGL_WRAPPER(
	void,
	glRasterPos3i,
	(GLint x, GLint y, GLint z),
	(x, y, z));
OGL_WRAPPER(
	void,
	glRasterPos3iv,
	(const GLint *v),
	( v));
OGL_WRAPPER(
	void,
	glRasterPos3s,
	(GLshort x, GLshort y, GLshort z),
	(x, y, z));
OGL_WRAPPER(
	void,
	glRasterPos3sv,
	(const GLshort *v),
	( v));
OGL_WRAPPER(
	void,
	glRasterPos4d,
	(GLdouble x, GLdouble y, GLdouble z, GLdouble w),
	(x, y, z, w));
OGL_WRAPPER(
	void,
	glRasterPos4dv,
	(const GLdouble *v),
	( v));
OGL_WRAPPER(
	void,
	glRasterPos4f,
	(GLfloat x, GLfloat y, GLfloat z, GLfloat w),
	(x, y, z, w));
OGL_WRAPPER(
	void,
	glRasterPos4fv,
	(const GLfloat *v),
	( v));
OGL_WRAPPER(
	void,
	glRasterPos4i,
	(GLint x, GLint y, GLint z, GLint w),
	(x, y, z, w));
OGL_WRAPPER(
	void,
	glRasterPos4iv,
	(const GLint *v),
	( v));
OGL_WRAPPER(
	void,
	glRasterPos4s,
	(GLshort x, GLshort y, GLshort z, GLshort w),
	(x, y, z, w));
OGL_WRAPPER(
	void,
	glRasterPos4sv,
	(const GLshort *v),
	( v));
OGL_WRAPPER(
	void,
	glReadBuffer,
	(GLenum mode),
	(mode));
OGL_WRAPPER(
	void,
	glReadPixels,
	(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels),
	(x, y, width, height, format, type,  pixels));
OGL_WRAPPER(
	void,
	glRectd,
	(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2),
	(x1, y1, x2, y2));
OGL_WRAPPER(
	void,
	glRectdv,
	(const GLdouble *v1, const GLdouble *v2),
	( v1,  v2));
OGL_WRAPPER(
	void,
	glRectf,
	(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2),
	(x1, y1, x2, y2));
OGL_WRAPPER(
	void,
	glRectfv,
	(const GLfloat *v1, const GLfloat *v2),
	( v1,  v2));
OGL_WRAPPER(
	void,
	glRecti,
	(GLint x1, GLint y1, GLint x2, GLint y2),
	(x1, y1, x2, y2));
OGL_WRAPPER(
	void,
	glRectiv,
	(const GLint *v1, const GLint *v2),
	( v1,  v2));
OGL_WRAPPER(
	void,
	glRects,
	(GLshort x1, GLshort y1, GLshort x2, GLshort y2),
	(x1, y1, x2, y2));
OGL_WRAPPER(
	void,
	glRectsv,
	(const GLshort *v1, const GLshort *v2),
	( v1,  v2));
OGL_WRAPPER(
	GLint,
	glRenderMode,
	(GLenum mode),
	(mode));
OGL_WRAPPER(
	void,
	glResetHistogram,
	(GLenum target),
	(target));
OGL_WRAPPER(
	void,
	glResetMinmax,
	(GLenum target),
	(target));
OGL_WRAPPER(
	void,
	glRotated,
	(GLdouble angle, GLdouble x, GLdouble y, GLdouble z),
	(angle, x, y, z));
OGL_WRAPPER(
	void,
	glRotatef,
	(GLfloat angle, GLfloat x, GLfloat y, GLfloat z),
	(angle, x, y, z));
OGL_WRAPPER(
	void,
	glScaled,
	(GLdouble x, GLdouble y, GLdouble z),
	(x, y, z));
OGL_WRAPPER(
	void,
	glScalef,
	(GLfloat x, GLfloat y, GLfloat z),
	(x, y, z));
OGL_WRAPPER(
	void,
	glScissor,
	(GLint x, GLint y, GLsizei width, GLsizei height),
	(x, y, width, height));
OGL_WRAPPER(
	void,
	glSelectBuffer,
	(GLsizei size, GLuint *buffer),
	(size,  buffer));
OGL_WRAPPER(
	void,
	glSeparableFilter2D,
	(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column),
	(target, internalformat, width, height, format, type,  row,  column));
OGL_WRAPPER(
	void,
	glShadeModel,
	(GLenum mode),
	(mode));
OGL_WRAPPER(
	void,
	glStencilFunc,
	(GLenum func, GLint ref, GLuint mask),
	(func, ref, mask));
OGL_WRAPPER(
	void,
	glStencilMask,
	(GLuint mask),
	(mask));
OGL_WRAPPER(
	void,
	glStencilOp,
	(GLenum fail, GLenum zfail, GLenum zpass),
	(fail, zfail, zpass));
OGL_WRAPPER(
	void,
	glTexCoord1d,
	(GLdouble s),
	(s));
OGL_WRAPPER(
	void,
	glTexCoord1dv,
	(const GLdouble *v),
	( v));
OGL_WRAPPER(
	void,
	glTexCoord1f,
	(GLfloat s),
	(s));
OGL_WRAPPER(
	void,
	glTexCoord1fv,
	(const GLfloat *v),
	( v));
OGL_WRAPPER(
	void,
	glTexCoord1i,
	(GLint s),
	(s));
OGL_WRAPPER(
	void,
	glTexCoord1iv,
	(const GLint *v),
	( v));
OGL_WRAPPER(
	void,
	glTexCoord1s,
	(GLshort s),
	(s));
OGL_WRAPPER(
	void,
	glTexCoord1sv,
	(const GLshort *v),
	( v));
OGL_WRAPPER(
	void,
	glTexCoord2d,
	(GLdouble s, GLdouble t),
	(s, t));
OGL_WRAPPER(
	void,
	glTexCoord2dv,
	(const GLdouble *v),
	( v));
OGL_WRAPPER(
	void,
	glTexCoord2f,
	(GLfloat s, GLfloat t),
	(s, t));
OGL_WRAPPER(
	void,
	glTexCoord2fv,
	(const GLfloat *v),
	( v));
OGL_WRAPPER(
	void,
	glTexCoord2i,
	(GLint s, GLint t),
	(s, t));
OGL_WRAPPER(
	void,
	glTexCoord2iv,
	(const GLint *v),
	( v));
OGL_WRAPPER(
	void,
	glTexCoord2s,
	(GLshort s, GLshort t),
	(s, t));
OGL_WRAPPER(
	void,
	glTexCoord2sv,
	(const GLshort *v),
	( v));
OGL_WRAPPER(
	void,
	glTexCoord3d,
	(GLdouble s, GLdouble t, GLdouble r),
	(s, t, r));
OGL_WRAPPER(
	void,
	glTexCoord3dv,
	(const GLdouble *v),
	( v));
OGL_WRAPPER(
	void,
	glTexCoord3f,
	(GLfloat s, GLfloat t, GLfloat r),
	(s, t, r));
OGL_WRAPPER(
	void,
	glTexCoord3fv,
	(const GLfloat *v),
	( v));
OGL_WRAPPER(
	void,
	glTexCoord3i,
	(GLint s, GLint t, GLint r),
	(s, t, r));
OGL_WRAPPER(
	void,
	glTexCoord3iv,
	(const GLint *v),
	( v));
OGL_WRAPPER(
	void,
	glTexCoord3s,
	(GLshort s, GLshort t, GLshort r),
	(s, t, r));
OGL_WRAPPER(
	void,
	glTexCoord3sv,
	(const GLshort *v),
	( v));
OGL_WRAPPER(
	void,
	glTexCoord4d,
	(GLdouble s, GLdouble t, GLdouble r, GLdouble q),
	(s, t, r, q));
OGL_WRAPPER(
	void,
	glTexCoord4dv,
	(const GLdouble *v),
	( v));
OGL_WRAPPER(
	void,
	glTexCoord4f,
	(GLfloat s, GLfloat t, GLfloat r, GLfloat q),
	(s, t, r, q));
OGL_WRAPPER(
	void,
	glTexCoord4fv,
	(const GLfloat *v),
	( v));
OGL_WRAPPER(
	void,
	glTexCoord4i,
	(GLint s, GLint t, GLint r, GLint q),
	(s, t, r, q));
OGL_WRAPPER(
	void,
	glTexCoord4iv,
	(const GLint *v),
	( v));
OGL_WRAPPER(
	void,
	glTexCoord4s,
	(GLshort s, GLshort t, GLshort r, GLshort q),
	(s, t, r, q));
OGL_WRAPPER(
	void,
	glTexCoord4sv,
	(const GLshort *v),
	( v));
OGL_WRAPPER(
	void,
	glTexCoordPointer,
	(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer),
	(size, type, stride,  pointer));
OGL_WRAPPER(
	void,
	glTexEnvf,
	(GLenum target, GLenum pname, GLfloat param),
	(target, pname, param));
OGL_WRAPPER(
	void,
	glTexEnvfv,
	(GLenum target, GLenum pname, const GLfloat *params),
	(target, pname,  params));
OGL_WRAPPER(
	void,
	glTexEnvi,
	(GLenum target, GLenum pname, GLint param),
	(target, pname, param));
OGL_WRAPPER(
	void,
	glTexEnviv,
	(GLenum target, GLenum pname, const GLint *params),
	(target, pname,  params));
OGL_WRAPPER(
	void,
	glTexGend,
	(GLenum coord, GLenum pname, GLdouble param),
	(coord, pname, param));
OGL_WRAPPER(
	void,
	glTexGendv,
	(GLenum coord, GLenum pname, const GLdouble *params),
	(coord, pname,  params));
OGL_WRAPPER(
	void,
	glTexGenf,
	(GLenum coord, GLenum pname, GLfloat param),
	(coord, pname, param));
OGL_WRAPPER(
	void,
	glTexGenfv,
	(GLenum coord, GLenum pname, const GLfloat *params),
	(coord, pname,  params));
OGL_WRAPPER(
	void,
	glTexGeni,
	(GLenum coord, GLenum pname, GLint param),
	(coord, pname, param));
OGL_WRAPPER(
	void,
	glTexGeniv,
	(GLenum coord, GLenum pname, const GLint *params),
	(coord, pname,  params));
OGL_WRAPPER(
	void,
	glTexImage1D,
	(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels),
	(target, level, internalformat, width, border, format, type,  pixels));
OGL_WRAPPER(
	void,
	glTexImage2D,
	(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels),
	(target, level, internalformat, width, height, border, format, type,  pixels));
OGL_WRAPPER(
	void,
	glTexImage3D,
	(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels),
	(target, level, internalformat, width, height, depth, border, format, type,  pixels));
OGL_WRAPPER(
	void,
	glTexParameterf,
	(GLenum target, GLenum pname, GLfloat param),
	(target, pname, param));
OGL_WRAPPER(
	void,
	glTexParameterfv,
	(GLenum target, GLenum pname, const GLfloat *params),
	(target, pname,  params));
OGL_WRAPPER(
	void,
	glTexParameteri,
	(GLenum target, GLenum pname, GLint param),
	(target, pname, param));
OGL_WRAPPER(
	void,
	glTexParameteriv,
	(GLenum target, GLenum pname, const GLint *params),
	(target, pname,  params));
OGL_WRAPPER(
	void,
	glTexSubImage1D,
	(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels),
	(target, level, xoffset, width, format, type,  pixels));
OGL_WRAPPER(
	void,
	glTexSubImage2D,
	(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels),
	(target, level, xoffset, yoffset, width, height, format, type,  pixels));
OGL_WRAPPER(
	void,
	glTexSubImage3D,
	(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels),
	(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type,  pixels));
OGL_WRAPPER(
	void,
	glTranslated,
	(GLdouble x, GLdouble y, GLdouble z),
	(x, y, z));
OGL_WRAPPER(
	void,
	glTranslatef,
	(GLfloat x, GLfloat y, GLfloat z),
	(x, y, z));
OGL_WRAPPER(
	void,
	glVertex2d,
	(GLdouble x, GLdouble y),
	(x, y));
OGL_WRAPPER(
	void,
	glVertex2dv,
	(const GLdouble *v),
	( v));
OGL_WRAPPER(
	void,
	glVertex2f,
	(GLfloat x, GLfloat y),
	(x, y));
OGL_WRAPPER(
	void,
	glVertex2fv,
	(const GLfloat *v),
	( v));
OGL_WRAPPER(
	void,
	glVertex2i,
	(GLint x, GLint y),
	(x, y));
OGL_WRAPPER(
	void,
	glVertex2iv,
	(const GLint *v),
	( v));
OGL_WRAPPER(
	void,
	glVertex2s,
	(GLshort x, GLshort y),
	(x, y));
OGL_WRAPPER(
	void,
	glVertex2sv,
	(const GLshort *v),
	( v));
OGL_WRAPPER(
	void,
	glVertex3d,
	(GLdouble x, GLdouble y, GLdouble z),
	(x, y, z));
OGL_WRAPPER(
	void,
	glVertex3dv,
	(const GLdouble *v),
	( v));
OGL_WRAPPER(
	void,
	glVertex3f,
	(GLfloat x, GLfloat y, GLfloat z),
	(x, y, z));
OGL_WRAPPER(
	void,
	glVertex3fv,
	(const GLfloat *v),
	( v));
OGL_WRAPPER(
	void,
	glVertex3i,
	(GLint x, GLint y, GLint z),
	(x, y, z));
OGL_WRAPPER(
	void,
	glVertex3iv,
	(const GLint *v),
	( v));
OGL_WRAPPER(
	void,
	glVertex3s,
	(GLshort x, GLshort y, GLshort z),
	(x, y, z));
OGL_WRAPPER(
	void,
	glVertex3sv,
	(const GLshort *v),
	( v));
OGL_WRAPPER(
	void,
	glVertex4d,
	(GLdouble x, GLdouble y, GLdouble z, GLdouble w),
	(x, y, z, w));
OGL_WRAPPER(
	void,
	glVertex4dv,
	(const GLdouble *v),
	( v));
OGL_WRAPPER(
	void,
	glVertex4f,
	(GLfloat x, GLfloat y, GLfloat z, GLfloat w),
	(x, y, z, w));
OGL_WRAPPER(
	void,
	glVertex4fv,
	(const GLfloat *v),
	( v));
OGL_WRAPPER(
	void,
	glVertex4i,
	(GLint x, GLint y, GLint z, GLint w),
	(x, y, z, w));
OGL_WRAPPER(
	void,
	glVertex4iv,
	(const GLint *v),
	( v));
OGL_WRAPPER(
	void,
	glVertex4s,
	(GLshort x, GLshort y, GLshort z, GLshort w),
	(x, y, z, w));
OGL_WRAPPER(
	void,
	glVertex4sv,
	(const GLshort *v),
	( v));
OGL_WRAPPER(
	void,
	glVertexPointer,
	(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer),
	(size, type, stride,  pointer));
OGL_WRAPPER(
	void,
	glViewport,
	(GLint x, GLint y, GLsizei width, GLsizei height),
	(x, y, width, height));
OGL_WRAPPER(
	void,
	glSampleCoverage,
	(GLclampf value, GLboolean invert),
	(value, invert));
OGL_WRAPPER(
	void,
	glSamplePass,
	(GLenum pass),
	(pass));
OGL_WRAPPER(
	void,
	glLoadTransposeMatrixf,
	(const GLfloat *m),
	( m));
OGL_WRAPPER(
	void,
	glLoadTransposeMatrixd,
	(const GLdouble *m),
	( m));
OGL_WRAPPER(
	void,
	glMultTransposeMatrixf,
	(const GLfloat *m),
	( m));
OGL_WRAPPER(
	void,
	glMultTransposeMatrixd,
	(const GLdouble *m),
	( m));
OGL_WRAPPER(
	void,
	glCompressedTexImage3D,
	(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data),
	(target, level, internalformat, width, height, depth, border, imageSize,  data));
OGL_WRAPPER(
	void,
	glCompressedTexImage2D,
	(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data),
	(target, level, internalformat, width, height, border, imageSize,  data));
OGL_WRAPPER(
	void,
	glCompressedTexImage1D,
	(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data),
	(target, level, internalformat, width, border, imageSize,  data));
OGL_WRAPPER(
	void,
	glCompressedTexSubImage3D,
	(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data),
	(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize,  data));
OGL_WRAPPER(
	void,
	glCompressedTexSubImage2D,
	(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data),
	(target, level, xoffset, yoffset, width, height, format, imageSize,  data));
OGL_WRAPPER(
	void,
	glCompressedTexSubImage1D,
	(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data),
	(target, level, xoffset, width, format, imageSize,  data));
OGL_WRAPPER(
	void,
	glGetCompressedTexImage,
	(GLenum target, GLint lod, GLvoid *img),
	(target, lod,  img));
OGL_WRAPPER(
	void,
	glActiveTexture,
	(GLenum texture),
	(texture));
OGL_WRAPPER(
	void,
	glClientActiveTexture,
	(GLenum texture),
	(texture));
OGL_WRAPPER(
	void,
	glMultiTexCoord1d,
	(GLenum target, GLdouble s),
	(target, s));
OGL_WRAPPER(
	void,
	glMultiTexCoord1dv,
	(GLenum target, const GLdouble *v),
	(target,  v));
OGL_WRAPPER(
	void,
	glMultiTexCoord1f,
	(GLenum target, GLfloat s),
	(target, s));
OGL_WRAPPER(
	void,
	glMultiTexCoord1fv,
	(GLenum target, const GLfloat *v),
	(target,  v));
OGL_WRAPPER(
	void,
	glMultiTexCoord1i,
	(GLenum target, GLint s),
	(target, s));
OGL_WRAPPER(
	void,
	glMultiTexCoord1iv,
	(GLenum target, const GLint *v),
	(target,  v));
OGL_WRAPPER(
	void,
	glMultiTexCoord1s,
	(GLenum target, GLshort s),
	(target, s));
OGL_WRAPPER(
	void,
	glMultiTexCoord1sv,
	(GLenum target, const GLshort *v),
	(target,  v));
OGL_WRAPPER(
	void,
	glMultiTexCoord2d,
	(GLenum target, GLdouble s, GLdouble t),
	(target, s, t));
OGL_WRAPPER(
	void,
	glMultiTexCoord2dv,
	(GLenum target, const GLdouble *v),
	(target,  v));
OGL_WRAPPER(
	void,
	glMultiTexCoord2f,
	(GLenum target, GLfloat s, GLfloat t),
	(target, s, t));
OGL_WRAPPER(
	void,
	glMultiTexCoord2fv,
	(GLenum target, const GLfloat *v),
	(target,  v));
OGL_WRAPPER(
	void,
	glMultiTexCoord2i,
	(GLenum target, GLint s, GLint t),
	(target, s, t));
OGL_WRAPPER(
	void,
	glMultiTexCoord2iv,
	(GLenum target, const GLint *v),
	(target,  v));
OGL_WRAPPER(
	void,
	glMultiTexCoord2s,
	(GLenum target, GLshort s, GLshort t),
	(target, s, t));
OGL_WRAPPER(
	void,
	glMultiTexCoord2sv,
	(GLenum target, const GLshort *v),
	(target,  v));
OGL_WRAPPER(
	void,
	glMultiTexCoord3d,
	(GLenum target, GLdouble s, GLdouble t, GLdouble r),
	(target, s, t, r));
OGL_WRAPPER(
	void,
	glMultiTexCoord3dv,
	(GLenum target, const GLdouble *v),
	(target,  v));
OGL_WRAPPER(
	void,
	glMultiTexCoord3f,
	(GLenum target, GLfloat s, GLfloat t, GLfloat r),
	(target, s, t, r));
OGL_WRAPPER(
	void,
	glMultiTexCoord3fv,
	(GLenum target, const GLfloat *v),
	(target,  v));
OGL_WRAPPER(
	void,
	glMultiTexCoord3i,
	(GLenum target, GLint s, GLint t, GLint r),
	(target, s, t, r));
OGL_WRAPPER(
	void,
	glMultiTexCoord3iv,
	(GLenum target, const GLint *v),
	(target,  v));
OGL_WRAPPER(
	void,
	glMultiTexCoord3s,
	(GLenum target, GLshort s, GLshort t, GLshort r),
	(target, s, t, r));
OGL_WRAPPER(
	void,
	glMultiTexCoord3sv,
	(GLenum target, const GLshort *v),
	(target,  v));
OGL_WRAPPER(
	void,
	glMultiTexCoord4d,
	(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q),
	(target, s, t, r, q));
OGL_WRAPPER(
	void,
	glMultiTexCoord4dv,
	(GLenum target, const GLdouble *v),
	(target,  v));
OGL_WRAPPER(
	void,
	glMultiTexCoord4f,
	(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q),
	(target, s, t, r, q));
OGL_WRAPPER(
	void,
	glMultiTexCoord4fv,
	(GLenum target, const GLfloat *v),
	(target,  v));
OGL_WRAPPER(
	void,
	glMultiTexCoord4i,
	(GLenum target, GLint a, GLint s, GLint t, GLint r),
	(target, a, s, t, r));
OGL_WRAPPER(
	void,
	glMultiTexCoord4iv,
	(GLenum target, const GLint *v),
	(target,  v));
OGL_WRAPPER(
	void,
	glMultiTexCoord4s,
	(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q),
	(target, s, t, r, q));
OGL_WRAPPER(
	void,
	glMultiTexCoord4sv,
	(GLenum target, const GLshort *v),
	(target,  v));
OGL_WRAPPER(
	void,
	glFogCoordf,
	(GLfloat coord),
	(coord));
OGL_WRAPPER(
	void,
	glFogCoordfv,
	(const GLfloat *coord),
	( coord));
OGL_WRAPPER(
	void,
	glFogCoordd,
	(GLdouble coord),
	(coord));
OGL_WRAPPER(
	void,
	glFogCoorddv,
	(const GLdouble * coord),
	(coord));
OGL_WRAPPER(
	void,
	glFogCoordPointer,
	(GLenum type, GLsizei stride, const GLvoid *pointer),
	(type, stride,  pointer));
OGL_WRAPPER(
	void,
	glSecondaryColor3b,
	(GLbyte red, GLbyte green, GLbyte blue),
	(red, green, blue));
OGL_WRAPPER(
	void,
	glSecondaryColor3bv,
	(const GLbyte *v),
	( v));
OGL_WRAPPER(
	void,
	glSecondaryColor3d,
	(GLdouble red, GLdouble green, GLdouble blue),
	(red, green, blue));
OGL_WRAPPER(
	void,
	glSecondaryColor3dv,
	(const GLdouble *v),
	( v));
OGL_WRAPPER(
	void,
	glSecondaryColor3f,
	(GLfloat red, GLfloat green, GLfloat blue),
	(red, green, blue));
OGL_WRAPPER(
	void,
	glSecondaryColor3fv,
	(const GLfloat *v),
	( v));
OGL_WRAPPER(
	void,
	glSecondaryColor3i,
	(GLint red, GLint green, GLint blue),
	(red, green, blue));
OGL_WRAPPER(
	void,
	glSecondaryColor3iv,
	(const GLint *v),
	( v));
OGL_WRAPPER(
	void,
	glSecondaryColor3s,
	(GLshort red, GLshort green, GLshort blue),
	(red, green, blue));
OGL_WRAPPER(
	void,
	glSecondaryColor3sv,
	(const GLshort *v),
	( v));
OGL_WRAPPER(
	void,
	glSecondaryColor3ub,
	(GLubyte red, GLubyte green, GLubyte blue),
	(red, green, blue));
OGL_WRAPPER(
	void,
	glSecondaryColor3ubv,
	(const GLubyte *v),
	( v));
OGL_WRAPPER(
	void,
	glSecondaryColor3ui,
	(GLuint red, GLuint green, GLuint blue),
	(red, green, blue));
OGL_WRAPPER(
	void,
	glSecondaryColor3uiv,
	(const GLuint *v),
	( v));
OGL_WRAPPER(
	void,
	glSecondaryColor3us,
	(GLushort red, GLushort green, GLushort blue),
	(red, green, blue));
OGL_WRAPPER(
	void,
	glSecondaryColor3usv,
	(const GLushort *v),
	( v));
OGL_WRAPPER(
	void,
	glSecondaryColorPointer,
	(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer),
	(size, type, stride,  pointer));
OGL_WRAPPER(
	void,
	glPointParameterf,
	(GLenum pname, GLfloat param),
	(pname, param));
OGL_WRAPPER(
	void,
	glPointParameterfv,
	(GLenum pname, const GLfloat *params),
	(pname,  params));
OGL_WRAPPER(
	void,
	glPointParameteri,
	(GLenum pname, GLint param),
	(pname, param));
OGL_WRAPPER(
	void,
	glPointParameteriv,
	(GLenum pname, const GLint *params),
	(pname,  params));
OGL_WRAPPER(
	void,
	glBlendFuncSeparate,
	(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha),
	(srcRGB, dstRGB, srcAlpha, dstAlpha));
OGL_WRAPPER(
	void,
	glMultiDrawArrays,
	(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount),
	(mode,  first,  count, primcount));
OGL_WRAPPER(
	void,
	glMultiDrawElements,
	(GLenum mode, const GLsizei *count, GLenum type, const GLvoid* *indices, GLsizei primcount),
	(mode,  count, type,  indices, primcount));
OGL_WRAPPER(
	void,
	glWindowPos2d,
	(GLdouble x, GLdouble y),
	(x, y));
OGL_WRAPPER(
	void,
	glWindowPos2dv,
	(const GLdouble *v),
	( v));
OGL_WRAPPER(
	void,
	glWindowPos2f,
	(GLfloat x, GLfloat y),
	(x, y));
OGL_WRAPPER(
	void,
	glWindowPos2fv,
	(const GLfloat *v),
	( v));
OGL_WRAPPER(
	void,
	glWindowPos2i,
	(GLint x, GLint y),
	(x, y));
OGL_WRAPPER(
	void,
	glWindowPos2iv,
	(const GLint *v),
	( v));
OGL_WRAPPER(
	void,
	glWindowPos2s,
	(GLshort x, GLshort y),
	(x, y));
OGL_WRAPPER(
	void,
	glWindowPos2sv,
	(const GLshort *v),
	( v));
OGL_WRAPPER(
	void,
	glWindowPos3d,
	(GLdouble x, GLdouble y, GLdouble z),
	(x, y, z));
OGL_WRAPPER(
	void,
	glWindowPos3dv,
	(const GLdouble *v),
	( v));
OGL_WRAPPER(
	void,
	glWindowPos3f,
	(GLfloat x, GLfloat y, GLfloat z),
	(x, y, z));
OGL_WRAPPER(
	void,
	glWindowPos3fv,
	(const GLfloat *v),
	( v));
OGL_WRAPPER(
	void,
	glWindowPos3i,
	(GLint x, GLint y, GLint z),
	(x, y, z));
OGL_WRAPPER(
	void,
	glWindowPos3iv,
	(const GLint *v),
	( v));
OGL_WRAPPER(
	void,
	glWindowPos3s,
	(GLshort x, GLshort y, GLshort z),
	(x, y, z));
OGL_WRAPPER(
	void,
	glWindowPos3sv,
	(const GLshort *v),
	( v));
OGL_WRAPPER(
	void,
	glGenQueries,
	(GLsizei n, GLuint *ids),
	(n,  ids));
OGL_WRAPPER(
	void,
	glDeleteQueries,
	(GLsizei n, const GLuint *ids),
	(n,  ids));
OGL_WRAPPER(
	GLboolean,
	glIsQuery,
	(GLuint id),
	(id));
OGL_WRAPPER(
	void,
	glBeginQuery,
	(GLenum target, GLuint id),
	(target, id));
OGL_WRAPPER(
	void,
	glEndQuery,
	(GLenum target),
	(target));
OGL_WRAPPER(
	void,
	glGetQueryiv,
	(GLenum target, GLenum pname, GLint *params),
	(target, pname,  params));
OGL_WRAPPER(
	void,
	glGetQueryObjectiv,
	(GLuint id, GLenum pname, GLint *params),
	(id, pname,  params));
OGL_WRAPPER(
	void,
	glGetQueryObjectuiv,
	(GLuint id, GLenum pname, GLuint *params),
	(id, pname,  params));
OGL_WRAPPER(
	void,
	glBindBuffer,
	(GLenum target, GLuint buffer),
	(target, buffer));
OGL_WRAPPER(
	void,
	glDeleteBuffers,
	(GLsizei n, const GLuint *buffers),
	(n,  buffers));
OGL_WRAPPER(
	void,
	glGenBuffers,
	(GLsizei n, GLuint *buffers),
	(n,  buffers));
OGL_WRAPPER(
	GLboolean,
	glIsBuffer,
	(GLuint buffer),
	(buffer));
OGL_WRAPPER(
	void,
	glBufferData,
	(GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage),
	(target, size,  data, usage));
OGL_WRAPPER(
	void,
	glBufferSubData,
	(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data),
	(target, offset, size,  data));
OGL_WRAPPER(
	void,
	glGetBufferSubData,
	(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid *data),
	(target, offset, size,  data));
OGL_WRAPPER(
	GLvoid *,
	glMapBuffer,
	(GLenum target, GLenum access),
	(target, access));
OGL_WRAPPER(
	GLboolean,
	glUnmapBuffer,
	(GLenum target),
	(target));
OGL_WRAPPER(
	void,
	glGetBufferParameteriv,
	(GLenum target, GLenum pname, GLint *params),
	(target, pname,  params));
OGL_WRAPPER(
	void,
	glGetBufferPointerv,
	(GLenum target, GLenum pname, GLvoid **params),
	(target, pname,   params));
OGL_WRAPPER(
	void,
	glDrawBuffers,
	(GLsizei n, const GLenum *bufs),
	(n,  bufs));
OGL_WRAPPER(
	void,
	glVertexAttrib1d,
	(GLuint index, GLdouble x),
	(index, x));
OGL_WRAPPER(
	void,
	glVertexAttrib1dv,
	(GLuint index, const GLdouble *v),
	(index,  v));
OGL_WRAPPER(
	void,
	glVertexAttrib1f,
	(GLuint index, GLfloat x),
	(index, x));
OGL_WRAPPER(
	void,
	glVertexAttrib1fv,
	(GLuint index, const GLfloat *v),
	(index,  v));
OGL_WRAPPER(
	void,
	glVertexAttrib1s,
	(GLuint index, GLshort x),
	(index, x));
OGL_WRAPPER(
	void,
	glVertexAttrib1sv,
	(GLuint index, const GLshort *v),
	(index,  v));
OGL_WRAPPER(
	void,
	glVertexAttrib2d,
	(GLuint index, GLdouble x, GLdouble y),
	(index, x, y));
OGL_WRAPPER(
	void,
	glVertexAttrib2dv,
	(GLuint index, const GLdouble *v),
	(index,  v));
OGL_WRAPPER(
	void,
	glVertexAttrib2f,
	(GLuint index, GLfloat x, GLfloat y),
	(index, x, y));
OGL_WRAPPER(
	void,
	glVertexAttrib2fv,
	(GLuint index, const GLfloat *v),
	(index,  v));
OGL_WRAPPER(
	void,
	glVertexAttrib2s,
	(GLuint index, GLshort x, GLshort y),
	(index, x, y));
OGL_WRAPPER(
	void,
	glVertexAttrib2sv,
	(GLuint index, const GLshort *v),
	(index,  v));
OGL_WRAPPER(
	void,
	glVertexAttrib3d,
	(GLuint index, GLdouble x, GLdouble y, GLdouble z),
	(index, x, y, z));
OGL_WRAPPER(
	void,
	glVertexAttrib3dv,
	(GLuint index, const GLdouble *v),
	(index,  v));
OGL_WRAPPER(
	void,
	glVertexAttrib3f,
	(GLuint index, GLfloat x, GLfloat y, GLfloat z),
	(index, x, y, z));
OGL_WRAPPER(
	void,
	glVertexAttrib3fv,
	(GLuint index, const GLfloat *v),
	(index,  v));
OGL_WRAPPER(
	void,
	glVertexAttrib3s,
	(GLuint index, GLshort x, GLshort y, GLshort z),
	(index, x, y, z));
OGL_WRAPPER(
	void,
	glVertexAttrib3sv,
	(GLuint index, const GLshort *v),
	(index,  v));
OGL_WRAPPER(
	void,
	glVertexAttrib4Nbv,
	(GLuint index, const GLbyte *v),
	(index,  v));
OGL_WRAPPER(
	void,
	glVertexAttrib4Niv,
	(GLuint index, const GLint *v),
	(index,  v));
OGL_WRAPPER(
	void,
	glVertexAttrib4Nsv,
	(GLuint index, const GLshort *v),
	(index,  v));
OGL_WRAPPER(
	void,
	glVertexAttrib4Nub,
	(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w),
	(index, x, y, z, w));
OGL_WRAPPER(
	void,
	glVertexAttrib4Nubv,
	(GLuint index, const GLubyte *v),
	(index,  v));
OGL_WRAPPER(
	void,
	glVertexAttrib4Nuiv,
	(GLuint index, const GLuint *v),
	(index,  v));
OGL_WRAPPER(
	void,
	glVertexAttrib4Nusv,
	(GLuint index, const GLushort *v),
	(index,  v));
OGL_WRAPPER(
	void,
	glVertexAttrib4bv,
	(GLuint index, const GLbyte *v),
	(index,  v));
OGL_WRAPPER(
	void,
	glVertexAttrib4d,
	(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w),
	(index, x, y, z, w));
OGL_WRAPPER(
	void,
	glVertexAttrib4dv,
	(GLuint index, const GLdouble *v),
	(index,  v));
OGL_WRAPPER(
	void,
	glVertexAttrib4f,
	(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w),
	(index, x, y, z, w));
OGL_WRAPPER(
	void,
	glVertexAttrib4fv,
	(GLuint index, const GLfloat *v),
	(index,  v));
OGL_WRAPPER(
	void,
	glVertexAttrib4iv,
	(GLuint index, const GLint *v),
	(index,  v));
OGL_WRAPPER(
	void,
	glVertexAttrib4s,
	(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w),
	(index, x, y, z, w));
OGL_WRAPPER(
	void,
	glVertexAttrib4sv,
	(GLuint index, const GLshort *v),
	(index,  v));
OGL_WRAPPER(
	void,
	glVertexAttrib4ubv,
	(GLuint index, const GLubyte *v),
	(index,  v));
OGL_WRAPPER(
	void,
	glVertexAttrib4uiv,
	(GLuint index, const GLuint *v),
	(index,  v));
OGL_WRAPPER(
	void,
	glVertexAttrib4usv,
	(GLuint index, const GLushort *v),
	(index,  v));
OGL_WRAPPER(
	void,
	glVertexAttribPointer,
	(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer),
	(index, size, type, normalized, stride,  pointer));
OGL_WRAPPER(
	void,
	glEnableVertexAttribArray,
	(GLuint index),
	(index));
OGL_WRAPPER(
	void,
	glDisableVertexAttribArray,
	(GLuint index),
	(index));
OGL_WRAPPER(
	void,
	glGetVertexAttribdv,
	(GLuint index, GLenum pname, GLdouble *params),
	(index, pname,  params));
OGL_WRAPPER(
	void,
	glGetVertexAttribfv,
	(GLuint index, GLenum pname, GLfloat *params),
	(index, pname,  params));
OGL_WRAPPER(
	void,
	glGetVertexAttribiv,
	(GLuint index, GLenum pname, GLint *params),
	(index, pname,  params));
OGL_WRAPPER(
	void,
	glGetVertexAttribPointerv,
	(GLuint index, GLenum pname, GLvoid* *pointer),
	(index, pname,  pointer));
OGL_WRAPPER(
	void,
	glDeleteShader,
	(GLuint shader),
	(shader));
OGL_WRAPPER(
	void,
	glDetachShader,
	(GLuint program, GLuint shader),
	(program, shader));
OGL_WRAPPER(
	GLuint,
	glCreateShader,
	(GLenum type),
	(type));
OGL_WRAPPER(
	void,
	glShaderSource,
	(GLuint shader, GLsizei count, const GLchar* *string, const GLint *length),
	(shader, count,  string,  length));
OGL_WRAPPER(
	void,
	glCompileShader,
	(GLuint shader),
	(shader));
OGL_WRAPPER(
	GLuint,
	glCreateProgram,
	(),
	());
OGL_WRAPPER(
	void,
	glGenProgramsARB,
	(GLsizei n, GLuint *programs),
	(n, programs)
);
OGL_WRAPPER(
	void,
	glAttachShader,
	(GLuint program, GLuint shader),
	(program, shader));
OGL_WRAPPER(
	void,
	glLinkProgram,
	(GLuint program),
	(program));
OGL_WRAPPER(
	void,
	glUseProgram,
	(GLuint program),
	(program));
OGL_WRAPPER(
	void,
	glDeleteProgram,
	(GLuint program),
	(program));
OGL_WRAPPER(
	void,
	glValidateProgram,
	(GLuint program),
	(program));
OGL_WRAPPER(
	void,
	glUniform1f,
	(GLint location, GLfloat v0),
	(location, v0));
OGL_WRAPPER(
	void,
	glUniform2f,
	(GLint location, GLfloat v0, GLfloat v1),
	(location, v0, v1));
OGL_WRAPPER(
	void,
	glUniform3f,
	(GLint location, GLfloat v0, GLfloat v1, GLfloat v2),
	(location, v0, v1, v2));
OGL_WRAPPER(
	void,
	glUniform4f,
	(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3),
	(location, v0, v1, v2, v3));
OGL_WRAPPER(
	void,
	glUniform1i,
	(GLint location, GLint v0),
	(location, v0));
OGL_WRAPPER(
	void,
	glUniform2i,
	(GLint location, GLint v0, GLint v1),
	(location, v0, v1));
OGL_WRAPPER(
	void,
	glUniform3i,
	(GLint location, GLint v0, GLint v1, GLint v2),
	(location, v0, v1, v2));
OGL_WRAPPER(
	void,
	glUniform4i,
	(GLint location, GLint v0, GLint v1, GLint v2, GLint v3),
	(location, v0, v1, v2, v3));
OGL_WRAPPER(
	void,
	glUniform1fv,
	(GLint location, GLsizei count, const GLfloat *value),
	(location, count,  value));
OGL_WRAPPER(
	void,
	glUniform2fv,
	(GLint location, GLsizei count, const GLfloat *value),
	(location, count,  value));
OGL_WRAPPER(
	void,
	glUniform3fv,
	(GLint location, GLsizei count, const GLfloat *value),
	(location, count,  value));
OGL_WRAPPER(
	void,
	glUniform4fv,
	(GLint location, GLsizei count, const GLfloat *value),
	(location, count,  value));
OGL_WRAPPER(
	void,
	glUniform1iv,
	(GLint location, GLsizei count, const GLint *value),
	(location, count,  value));
OGL_WRAPPER(
	void,
	glUniform2iv,
	(GLint location, GLsizei count, const GLint *value),
	(location, count,  value));
OGL_WRAPPER(
	void,
	glUniform3iv,
	(GLint location, GLsizei count, const GLint *value),
	(location, count,  value));
OGL_WRAPPER(
	void,
	glUniform4iv,
	(GLint location, GLsizei count, const GLint *value),
	(location, count,  value));
OGL_WRAPPER(
	void,
	glUniformMatrix2fv,
	(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value),
	(location, count, transpose,  value));
OGL_WRAPPER(
	void,
	glUniformMatrix3fv,
	(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value),
	(location, count, transpose,  value));
OGL_WRAPPER(
	void,
	glUniformMatrix4fv,
	(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value),
	(location, count, transpose,  value));
OGL_WRAPPER(
	GLboolean,
	glIsShader,
	(GLuint shader),
	(shader));
OGL_WRAPPER(
	GLboolean,
	glIsProgram,
	(GLuint program),
	(program));
OGL_WRAPPER(
	void,
	glGetShaderiv,
	(GLuint shader, GLenum pname, GLint *params),
	(shader, pname,  params));
OGL_WRAPPER(
	void,
	glGetProgramiv,
	(GLuint program, GLenum pname, GLint *params),
	(program, pname,  params));
OGL_WRAPPER(
	void,
	glGetAttachedShaders,
	(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders),
	(program, maxCount,  count,  shaders));
OGL_WRAPPER(
	void,
	glGetShaderInfoLog,
	(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog),
	(shader, bufSize,  length,  infoLog));
OGL_WRAPPER(
	void,
	glGetProgramInfoLog,
	(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog),
	(program, bufSize,  length,  infoLog));
OGL_WRAPPER(
	GLint,
	glGetUniformLocation,
	(GLuint program, const GLchar *name),
	(program,  name));
OGL_WRAPPER(
	void,
	glGetActiveUniform,
	(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name),
	(program, index, bufSize,  length,  size,  type,  name));
OGL_WRAPPER(
	void,
	glGetUniformfv,
	(GLuint program, GLint location, GLfloat *params),
	(program, location,  params));
OGL_WRAPPER(
	void,
	glGetUniformiv,
	(GLuint program, GLint location, GLint *params),
	(program, location,  params));
OGL_WRAPPER(
	void,
	glGetShaderSource,
	(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source),
	(shader, bufSize,  length,  source));
OGL_WRAPPER(
	void,
	glBindAttribLocation,
	(GLuint program, GLuint index, const GLchar *name),
	(program, index,  name));
OGL_WRAPPER(
	void,
	glGetActiveAttrib,
	(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name),
	(program, index, bufSize,  length,  size,  type,  name));
OGL_WRAPPER(
	GLint,
	glGetAttribLocation,
	(GLuint program, const GLchar *name),
	(program,  name));
OGL_WRAPPER(
	void,
	glStencilFuncSeparate,
	(GLenum face, GLenum func, GLint ref, GLuint mask),
	(face, func, ref, mask));
OGL_WRAPPER(
	void,
	glStencilOpSeparate,
	(GLenum face, GLenum fail, GLenum zfail, GLenum zpass),
	(face, fail, zfail, zpass));
OGL_WRAPPER(
	void,
	glStencilMaskSeparate,
	(GLenum face, GLuint mask),
	(face, mask));	
OGL_WRAPPER(
	void,
	glActiveStencilFaceEXT,
	(GLenum face),
	(face));
OGL_WRAPPER(
	void,
	glProgramLocalParameter4fvARB,
	(GLenum target, GLuint index, const GLfloat *params),
	(target, index, params));

OGL_WRAPPER(
	void,
	glBindProgramARB,
	(GLenum target, GLuint program),
	(target, program));

OGL_WRAPPER(
	void,
	glProgramStringARB,
	(GLenum target, GLenum format, GLsizei len, const GLvoid *string),
	(target, format, len,  string));

OGL_WRAPPER(
	void,
	glProgramEnvParameter4fv,
	(GLenum target, GLuint index, const GLfloat *params),
	(target, index,  params));

OGL_WRAPPER(
	void,
	glCombinerInputNV,
	(GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage),
	(stage, portion, variable, input, mapping, componentUsage)
);

OGL_WRAPPER(
	void,
	glCombinerOutputNV,
	(GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum),
	(stage, portion, abOutput, cdOutput, sumOutput, scale, bias, abDotProduct, cdDotProduct, muxSum)
);

OGL_WRAPPER(
	void,
	glCombinerParameterfNV,
	(GLenum pname, GLfloat param),
	(pname, param)
);

OGL_WRAPPER(
	void,
	glCombinerParameterfvNV,
	(GLenum pname, const GLfloat* params),
	(pname, params)
);

OGL_WRAPPER(
	void,
	glCombinerParameteriNV,
	(GLenum pname, GLint param),
	(pname, param)
);

OGL_WRAPPER(
	void,
	glCombinerParameterivNV,
	(GLenum pname, const GLint* params),
	(pname, params)
);

OGL_WRAPPER(
	void,
	glFinalCombinerInputNV,
	(GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage),
	(variable, input, mapping, componentUsage)
);

OGL_WRAPPER(
	void,
	glGetCombinerInputParameterfvNV,
	(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat* params),
	(stage, portion, variable, pname, params)
);

OGL_WRAPPER(
	void,
	glGetCombinerInputParameterivNV,
	(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint* params),
	(stage, portion, variable, pname, params)
);

OGL_WRAPPER(
	void,
	glGetCombinerOutputParameterfvNV,
	(GLenum stage, GLenum portion, GLenum pname, GLfloat* params),
	(stage, portion, pname, params)
);

OGL_WRAPPER(
	void,
	glGetCombinerOutputParameterivNV,
	(GLenum stage, GLenum portion, GLenum pname, GLint* params),
	(stage, portion, pname, params)
);

OGL_WRAPPER(
	void,
	glGetFinalCombinerInputParameterfvNV,
	(GLenum variable, GLenum pname, GLfloat* params),
	(variable, pname, params)
);

OGL_WRAPPER(
	void,
	glGetFinalCombinerInputParameterivNV,
	(GLenum variable, GLenum pname, GLint* params),
	(variable, pname, params)
);

#endif
