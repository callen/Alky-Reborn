/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __APIS_WINDOWS_GLU32_GLU32_H__
#define __APIS_WINDOWS_GLU32_GLU32_H__

#include <APIs/Windows/Windows.h>

#ifdef DEFINE_GLU_WRAPPERS
#define GLU_WRAPPER(ret, name, args, argnames) \
WINAPI ret name##_ args { /* NuLog(#name); */ return name argnames; }
#else
#define GLU_WRAPPER(ret, name, args, argnames) \
WINAPI ret name##_ args
#endif

GLU_WRAPPER(
	void,
	gluBeginCurve,
	(GLUnurbs* nurb),
	(nurb));
GLU_WRAPPER(
	void,
	gluBeginPolygon,
	(GLUtesselator* tess),
	(tess));
GLU_WRAPPER(
	void,
	gluBeginSurface,
	(GLUnurbs* nurb),
	(nurb));
GLU_WRAPPER(
	void,
	gluBeginTrim,
	(GLUnurbs* nurb),
	(nurb));
GLU_WRAPPER(
	GLint,
	gluBuild1DMipmapLevels,
	(GLenum target, GLint internalFormat, GLsizei width, GLenum format, GLenum type, GLint level, GLint base, GLint max, const void *data),
	(target, internalFormat, width, format, type, level, base, max,  data));
GLU_WRAPPER(
	GLint,
	gluBuild1DMipmaps,
	(GLenum target, GLint internalFormat, GLsizei width, GLenum format, GLenum type, const void *data),
	(target, internalFormat, width, format, type,  data));
GLU_WRAPPER(
	GLint,
	gluBuild2DMipmapLevels,
	(GLenum target, GLint internalFormat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLint level, GLint base, GLint max, const void *data),
	(target, internalFormat, width, height, format, type, level, base, max,  data));
GLU_WRAPPER(
	GLint,
	gluBuild2DMipmaps,
	(GLenum target, GLint internalFormat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *data),
	(target, internalFormat, width, height, format, type,  data));
GLU_WRAPPER(
	GLint,
	gluBuild3DMipmapLevels,
	(GLenum target, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLint level, GLint base, GLint max, const void *data),
	(target, internalFormat, width, height, depth, format, type, level, base, max,  data));
GLU_WRAPPER(
	GLint,
	gluBuild3DMipmaps,
	(GLenum target, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data),
	(target, internalFormat, width, height, depth, format, type,  data));
GLU_WRAPPER(
	GLboolean,
	gluCheckExtension,
	(const GLubyte *extName, const GLubyte *extString),
	( extName,  extString));
GLU_WRAPPER(
	void,
	gluCylinder,
	(GLUquadric* quad, GLdouble base, GLdouble top, GLdouble height, GLint slices, GLint stacks),
	(quad, base, top, height, slices, stacks));
GLU_WRAPPER(
	void,
	gluDeleteNurbsRenderer,
	(GLUnurbs* nurb),
	(nurb));
GLU_WRAPPER(
	void,
	gluDeleteQuadric,
	(GLUquadric* quad),
	(quad));
GLU_WRAPPER(
	void,
	gluDeleteTess,
	(GLUtesselator* tess),
	(tess));
GLU_WRAPPER(
	void,
	gluDisk,
	(GLUquadric* quad, GLdouble inner, GLdouble outer, GLint slices, GLint loops),
	(quad, inner, outer, slices, loops));
GLU_WRAPPER(
	void,
	gluEndCurve,
	(GLUnurbs* nurb),
	(nurb));
GLU_WRAPPER(
	void,
	gluEndPolygon,
	(GLUtesselator* tess),
	(tess));
GLU_WRAPPER(
	void,
	gluEndSurface,
	(GLUnurbs* nurb),
	(nurb));
GLU_WRAPPER(
	void,
	gluEndTrim,
	(GLUnurbs* nurb),
	(nurb));
GLU_WRAPPER(
	const GLubyte *,
	gluErrorString,
	(GLenum error),
	(error));
GLU_WRAPPER(
	void,
	gluGetNurbsProperty,
	(GLUnurbs* nurb, GLenum property, GLfloat* data),
	(nurb, property, data));
GLU_WRAPPER(
	const GLubyte *,
	gluGetString,
	(GLenum name),
	(name));
GLU_WRAPPER(
	void,
	gluGetTessProperty,
	(GLUtesselator* tess, GLenum which, GLdouble* data),
	(tess, which, data));
GLU_WRAPPER(
	void,
	gluLoadSamplingMatrices,
	(GLUnurbs* nurb, const GLfloat *model, const GLfloat *perspective, const GLint *view),
	(nurb,  model,  perspective,  view));
GLU_WRAPPER(
	void,
	gluLookAt,
	(GLdouble eyeX, GLdouble eyeY, GLdouble eyeZ, GLdouble centerX, GLdouble centerY, GLdouble centerZ, GLdouble upX, GLdouble upY, GLdouble upZ),
	(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ));
GLU_WRAPPER(
	GLUnurbs *,
	gluNewNurbsRenderer,
	(),
	());
GLU_WRAPPER(
	GLUquadric*,
	gluNewQuadric,
	(),
	());
GLU_WRAPPER(
	GLUtesselator*,
	gluNewTess,
	(),
	());
GLU_WRAPPER(
	void,
	gluNextContour,
	(GLUtesselator* tess, GLenum type),
	(tess, type));
GLU_WRAPPER(
	void,
	gluNurbsCallback,
	(GLUnurbs* nurb, GLenum which, GLvoid (*CallBackFunc)()),
	(nurb, which, CallBackFunc));
GLU_WRAPPER(
	void,
	gluNurbsCallbackData,
	(GLUnurbs* nurb, GLvoid* userData),
	(nurb, userData));
GLU_WRAPPER(
	void,
	gluNurbsCallbackDataEXT,
	(GLUnurbs* nurb, GLvoid* userData),
	(nurb, userData));
GLU_WRAPPER(
	void,
	gluNurbsCurve,
	(GLUnurbs* nurb, GLint knotCount, GLfloat *knots, GLint stride, GLfloat *control, GLint order, GLenum type),
	(nurb, knotCount,  knots, stride,  control, order, type));
GLU_WRAPPER(
	void,
	gluNurbsProperty,
	(GLUnurbs* nurb, GLenum property, GLfloat value),
	(nurb, property, value));
GLU_WRAPPER(
	void,
	gluNurbsSurface,
	(GLUnurbs* nurb, GLint sKnotCount, GLfloat* sKnots, GLint tKnotCount, GLfloat* tKnots, GLint sStride, GLint tStride, GLfloat* control, GLint sOrder, GLint tOrder, GLenum type),
	(nurb, sKnotCount, sKnots, tKnotCount, tKnots, sStride, tStride, control, sOrder, tOrder, type));
GLU_WRAPPER(
	void,
	gluOrtho2D,
	(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top),
	(left, right, bottom, top));
GLU_WRAPPER(
	void,
	gluPartialDisk,
	(GLUquadric* quad, GLdouble inner, GLdouble outer, GLint slices, GLint loops, GLdouble start, GLdouble sweep),
	(quad, inner, outer, slices, loops, start, sweep));
GLU_WRAPPER(
	void,
	gluPerspective,
	(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar),
	(fovy, aspect, zNear, zFar));
GLU_WRAPPER(
	void,
	gluPickMatrix,
	(GLdouble x, GLdouble y, GLdouble delX, GLdouble delY, GLint *viewport),
	(x, y, delX, delY,  viewport));
GLU_WRAPPER(
	GLint,
	gluProject,
	(GLdouble objX, GLdouble objY, GLdouble objZ, const GLdouble *model, const GLdouble *proj, const GLint *view, GLdouble* winX, GLdouble* winY, GLdouble* winZ),
	(objX, objY, objZ,  model,  proj,  view, winX, winY, winZ));
GLU_WRAPPER(
	void,
	gluPwlCurve,
	(GLUnurbs* nurb, GLint count, GLfloat* data, GLint stride, GLenum type),
	(nurb, count, data, stride, type));
GLU_WRAPPER(
	void,
	gluQuadricCallback,
	(GLUquadric* quad, GLenum which, GLvoid (*CallBackFunc)()),
	(quad, which, CallBackFunc));
GLU_WRAPPER(
	void,
	gluQuadricDrawStyle,
	(GLUquadric* quad, GLenum draw),
	(quad, draw));
GLU_WRAPPER(
	void,
	gluQuadricNormals,
	(GLUquadric* quad, GLenum normal),
	(quad, normal));
GLU_WRAPPER(
	void,
	gluQuadricOrientation,
	(GLUquadric* quad, GLenum orientation),
	(quad, orientation));
GLU_WRAPPER(
	void,
	gluQuadricTexture,
	(GLUquadric* quad, GLboolean texture),
	(quad, texture));
GLU_WRAPPER(
	GLint,
	gluScaleImage,
	(GLenum format, GLsizei wIn, GLsizei hIn, GLenum typeIn, const void *dataIn, GLsizei wOut, GLsizei hOut, GLenum typeOut, GLvoid* dataOut),
	(format, wIn, hIn, typeIn,  dataIn, wOut, hOut, typeOut, dataOut));
GLU_WRAPPER(
	void,
	gluSphere,
	(GLUquadric* quad, GLdouble radius, GLint slices, GLint stacks),
	(quad, radius, slices, stacks));
GLU_WRAPPER(
	void,
	gluTessBeginContour,
	(GLUtesselator* tess),
	(tess));
GLU_WRAPPER(
	void,
	gluTessBeginPolygon,
	(GLUtesselator* tess, GLvoid* data),
	(tess, data));
GLU_WRAPPER(
	void,
	gluTessCallback,
	(GLUtesselator* tess, GLenum which, GLvoid (*CallBackFunc)()),
	(tess, which, CallBackFunc));
GLU_WRAPPER(
	void,
	gluTessEndContour,
	(GLUtesselator* tess),
	(tess));
GLU_WRAPPER(
	void,
	gluTessEndPolygon,
	(GLUtesselator* tess),
	(tess));
GLU_WRAPPER(
	void,
	gluTessNormal,
	(GLUtesselator* tess, GLdouble valueX, GLdouble valueY, GLdouble valueZ),
	(tess, valueX, valueY, valueZ));
GLU_WRAPPER(
	void,
	gluTessProperty,
	(GLUtesselator* tess, GLenum which, GLdouble data),
	(tess, which, data));
GLU_WRAPPER(
	void,
	gluTessVertex,
	(GLUtesselator* tess, GLdouble *location, GLvoid* data),
	(tess,  location, data));
GLU_WRAPPER(
	GLint,
	gluUnProject,
	(GLdouble winX, GLdouble winY, GLdouble winZ, const GLdouble *model, const GLdouble *proj, const GLint *view, GLdouble* objX, GLdouble* objY, GLdouble* objZ),
	(winX, winY, winZ,  model,  proj,  view, objX, objY, objZ));
GLU_WRAPPER(
	GLint,
	gluUnProject4,
	(GLdouble winX, GLdouble winY, GLdouble winZ, GLdouble clipW, const GLdouble *model, const GLdouble *proj, const GLint *view, GLdouble near, GLdouble far, GLdouble* objX, GLdouble* objY, GLdouble* objZ, GLdouble* objW),
	(winX, winY, winZ, clipW,  model,  proj,  view, near, far, objX, objY, objZ, objW));

#endif
