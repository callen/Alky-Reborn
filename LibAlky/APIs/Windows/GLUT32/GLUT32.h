/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __APIS_WINDOWS_GLUT32_GLUT32_H__
#define __APIS_WINDOWS_GLUT32_GLUT32_H__

#include <Nucleus/Nucleus.h>

#ifdef MAC
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <APIs/Windows/Windows.h>

#ifdef DEFINE_GLUT_WRAPPERS
#define GLUT_WRAPPER(ret__, name__, args__, argnames__) \
ret__ name__##_ args__ { /* NuLog(#name__); */ return name__ argnames__; }
#else
#define GLUT_WRAPPER(ret__, name__, args__, argnames__) \
ret__ name__##_ args__
#endif

	GLUT_WRAPPER(
		void,
		 glutInit,
		(int *argcp, char **argv),
		( argcp,   argv));
	GLUT_WRAPPER(
		void,
		 glutInitDisplayMode,
		(unsigned int mode),
		(mode));
	GLUT_WRAPPER(
		void,
		 glutInitDisplayString,
		(const char *string),
		( string));
	GLUT_WRAPPER(
		void,
		 glutInitWindowPosition,
		(int x, int y),
		(x, y));
	GLUT_WRAPPER(
		void,
		 glutInitWindowSize,
		(int width, int height),
		(width, height));
	GLUT_WRAPPER(
		void,
		 glutMainLoop,
		(),
		());
	GLUT_WRAPPER(
		int,
		 glutCreateWindow,
		(const char *title),
		( title));
	GLUT_WRAPPER(
		int,
		 glutCreateSubWindow,
		(int win, int x, int y, int width, int height),
		(win, x, y, width, height));
	GLUT_WRAPPER(
		void,
		 glutDestroyWindow,
		(int win),
		(win));
	GLUT_WRAPPER(
		void,
		 glutPostRedisplay,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutPostWindowRedisplay,
		(int win),
		(win));
	GLUT_WRAPPER(
		void,
		 glutSwapBuffers,
		(),
		());
	GLUT_WRAPPER(
		int,
		 glutGetWindow,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutSetWindow,
		(int win),
		(win));
	GLUT_WRAPPER(
		void,
		 glutSetWindowTitle,
		(const char *title),
		( title));
	GLUT_WRAPPER(
		void,
		 glutSetIconTitle,
		(const char *title),
		( title));
	GLUT_WRAPPER(
		void,
		 glutPositionWindow,
		(int x, int y),
		(x, y));
	GLUT_WRAPPER(
		void,
		 glutReshapeWindow,
		(int width, int height),
		(width, height));
	GLUT_WRAPPER(
		void,
		 glutPopWindow,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutPushWindow,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutIconifyWindow,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutShowWindow,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutHideWindow,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutFullScreen,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutSetCursor,
		(int cursor),
		(cursor));
	GLUT_WRAPPER(
		void,
		 glutWarpPointer,
		(int x, int y),
		(x, y));
	GLUT_WRAPPER(
		void,
		 glutSurfaceTexture,
		(GLenum target, GLenum internalformat, int surfacewin),
		(target, internalformat, surfacewin));
	GLUT_WRAPPER(
		void,
		glutWMCloseFunc,
		(void (*func)()),
		(func));
	GLUT_WRAPPER(
		void,
		 glutCheckLoop,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutEstablishOverlay,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutRemoveOverlay,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutUseLayer,
		(GLenum layer),
		(layer));
	GLUT_WRAPPER(
		void,
		 glutPostOverlayRedisplay,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutPostWindowOverlayRedisplay,
		(int win),
		(win));
	GLUT_WRAPPER(
		void,
		 glutShowOverlay,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutHideOverlay,
		(),
		());
	GLUT_WRAPPER(
		int,
		 glutCreateMenu,
		(void (*func)(int)),
		(func));
	GLUT_WRAPPER(
		void,
		 glutDestroyMenu,
		(int menu),
		(menu));
	GLUT_WRAPPER(
		int,
		 glutGetMenu,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutSetMenu,
		(int menu),
		(menu));
	GLUT_WRAPPER(
		void,
		 glutAddMenuEntry,
		(const char *label, int value),
		( label, value));
	GLUT_WRAPPER(
		void,
		 glutAddSubMenu,
		(const char *label, int submenu),
		( label, submenu));
	GLUT_WRAPPER(
		void,
		 glutChangeToMenuEntry,
		(int item, const char *label, int value),
		(item,  label, value));
	GLUT_WRAPPER(
		void,
		 glutChangeToSubMenu,
		(int item, const char *label, int submenu),
		(item,  label, submenu));
	GLUT_WRAPPER(
		void,
		 glutRemoveMenuItem,
		(int item),
		(item));
	GLUT_WRAPPER(
		void,
		 glutAttachMenu,
		(int button),
		(button));
	GLUT_WRAPPER(
		void,
		 glutDetachMenu,
		(int button),
		(button));
	GLUT_WRAPPER(
		void,
		 glutDisplayFunc,
		(void (*func)()),
		(func));
	GLUT_WRAPPER(
		void,
		 glutReshapeFunc,
		(void (*func)(int width, int height)),
		(func));
	GLUT_WRAPPER(
		void,
		 glutKeyboardFunc,
		(void (*func)(unsigned char key, int x, int y)),
		(func));
	GLUT_WRAPPER(
		void,
		 glutMouseFunc,
		(void (*func)(int button, int state, int x, int y)),
		(func));
	GLUT_WRAPPER(
		void,
		 glutMotionFunc,
		(void (*func)(int x, int y)),
		(func));
	GLUT_WRAPPER(
		void,
		 glutPassiveMotionFunc,
		(void (*func)(int x, int y)),
		(func));
	GLUT_WRAPPER(
		void,
		 glutEntryFunc,
		(void (*func)(int state)),
		(func));
	GLUT_WRAPPER(
		void,
		 glutVisibilityFunc,
		(void (*func)(int state)),
		(func));
	GLUT_WRAPPER(
		void,
		 glutIdleFunc,
		(void (*func)()),
		(func));
	GLUT_WRAPPER(
		void,
		 glutTimerFunc,
		(unsigned int millis, void (*func)(int value), int value),
		(millis, func, value));
	GLUT_WRAPPER(
		void,
		 glutMenuStateFunc,
		(void (*func)(int state)),
		(func));
	GLUT_WRAPPER(
		void,
		 glutSpecialFunc,
		(void (*func)(int key, int x, int y)),
		(func));
	GLUT_WRAPPER(
		void,
		 glutSpaceballMotionFunc,
		(void (*func)(int x, int y, int z)),
		(func));
	GLUT_WRAPPER(
		void,
		 glutSpaceballRotateFunc,
		(void (*func)(int x, int y, int z)),
		(func));
	GLUT_WRAPPER(
		void,
		 glutSpaceballButtonFunc,
		(void (*func)(int button, int state)),
		(func));
	GLUT_WRAPPER(
		void,
		 glutButtonBoxFunc,
		(void (*func)(int button, int state)),
		(func));
	GLUT_WRAPPER(
		void,
		 glutDialsFunc,
		(void (*func)(int dial, int value)),
		(func));
	GLUT_WRAPPER(
		void,
		 glutTabletMotionFunc,
		(void (*func)(int x, int y)),
		(func));
	GLUT_WRAPPER(
		void,
		 glutTabletButtonFunc,
		(void (*func)(int button, int state, int x, int y)),
		(func));
	GLUT_WRAPPER(
		void,
		 glutMenuStatusFunc,
		(void (*func)(int status, int x, int y)),
		(func));
	GLUT_WRAPPER(
		void,
		 glutOverlayDisplayFunc,
		(void (*func)()),
		(func));
	GLUT_WRAPPER(
		void,
		 glutWindowStatusFunc,
		(void (*func)(int state)),
		(func));
	GLUT_WRAPPER(
		void,
		 glutKeyboardUpFunc,
		(void (*func)(unsigned char key, int x, int y)),
		(func));
	GLUT_WRAPPER(
		void,
		 glutSpecialUpFunc,
		(void (*func)(int key, int x, int y)),
		(func));
	GLUT_WRAPPER(
		void,
		 glutJoystickFunc,
		(void (*func)(unsigned int buttonMask, int x, int y, int z), int pollInterval),
		(func, pollInterval));
	GLUT_WRAPPER(
		void,
		 glutSetColor,
		(int a, GLfloat red, GLfloat green, GLfloat blue),
		(a, red, green, blue));
	GLUT_WRAPPER(
		GLfloat,
		 glutGetColor,
		(int ndx, int component),
		(ndx, component));
	GLUT_WRAPPER(
		void,
		 glutCopyColormap,
		(int win),
		(win));
	GLUT_WRAPPER(
		int,
		 glutGet,
		(GLenum type),
		(type));
	GLUT_WRAPPER(
		int,
		 glutDeviceGet,
		(GLenum type),
		(type));
	GLUT_WRAPPER(
		int,
		 glutExtensionSupported,
		(const char *name),
		( name));
	GLUT_WRAPPER(
		int,
		 glutGetModifiers,
		(),
		());
	GLUT_WRAPPER(
		int,
		 glutLayerGet,
		(GLenum type),
		(type));
	GLUT_WRAPPER(
		void *,
		glutGetProcAddress,
		(const char *procName),
		( procName));
	GLUT_WRAPPER(
		void,
		 glutBitmapCharacter,
		(void *font, int character),
		( font, character));
	GLUT_WRAPPER(
		int,
		 glutBitmapWidth,
		(void *font, int character),
		( font, character));
	GLUT_WRAPPER(
		void,
		 glutStrokeCharacter,
		(void *font, int character),
		( font, character));
	GLUT_WRAPPER(
		int,
		 glutStrokeWidth,
		(void *font, int character),
		( font, character));
	GLUT_WRAPPER(
		int,
		 glutBitmapLength,
		(void *font, const unsigned char *string),
		( font,  string));
	GLUT_WRAPPER(
		int,
		 glutStrokeLength,
		(void *font, const unsigned char *string),
		( font,  string));
	GLUT_WRAPPER(
		void,
		 glutWireSphere,
		(GLdouble radius, GLint slices, GLint stacks),
		(radius, slices, stacks));
	GLUT_WRAPPER(
		void,
		 glutSolidSphere,
		(GLdouble radius, GLint slices, GLint stacks),
		(radius, slices, stacks));
	GLUT_WRAPPER(
		void,
		 glutWireCone,
		(GLdouble base, GLdouble height, GLint slices, GLint stacks),
		(base, height, slices, stacks));
	GLUT_WRAPPER(
		void,
		 glutSolidCone,
		(GLdouble base, GLdouble height, GLint slices, GLint stacks),
		(base, height, slices, stacks));
	GLUT_WRAPPER(
		void,
		 glutWireCube,
		(GLdouble size),
		(size));
	GLUT_WRAPPER(
		void,
		 glutSolidCube,
		(GLdouble size),
		(size));
	GLUT_WRAPPER(
		void,
		 glutWireTorus,
		(GLdouble innerRadius, GLdouble outerRadius, GLint sides, GLint rings),
		(innerRadius, outerRadius, sides, rings));
	GLUT_WRAPPER(
		void,
		 glutSolidTorus,
		(GLdouble innerRadius, GLdouble outerRadius, GLint sides, GLint rings),
		(innerRadius, outerRadius, sides, rings));
	GLUT_WRAPPER(
		void,
		 glutWireDodecahedron,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutSolidDodecahedron,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutWireTeapot,
		(GLdouble size),
		(size));
	GLUT_WRAPPER(
		void,
		 glutSolidTeapot,
		(GLdouble size),
		(size));
	GLUT_WRAPPER(
		void,
		 glutWireOctahedron,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutSolidOctahedron,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutWireTetrahedron,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutSolidTetrahedron,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutWireIcosahedron,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutSolidIcosahedron,
		(),
		());
	GLUT_WRAPPER(
		int,
		 glutVideoResizeGet,
		(GLenum param),
		(param));
	GLUT_WRAPPER(
		void,
		 glutSetupVideoResizing,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutStopVideoResizing,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutVideoResize,
		(int x, int y, int width, int height),
		(x, y, width, height));
	GLUT_WRAPPER(
		void,
		 glutVideoPan,
		(int x, int y, int width, int height),
		(x, y, width, height));
	GLUT_WRAPPER(
		void,
		 glutReportErrors,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutIgnoreKeyRepeat,
		(int ignore),
		(ignore));
	GLUT_WRAPPER(
		void,
		 glutSetKeyRepeat,
		(int repeatMode),
		(repeatMode));
	GLUT_WRAPPER(
		void,
		 glutForceJoystickFunc,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutGameModeString,
		(const char *string),
		( string));
	GLUT_WRAPPER(
		int,
		 glutEnterGameMode,
		(),
		());
	GLUT_WRAPPER(
		void,
		 glutLeaveGameMode,
		(),
		());
	GLUT_WRAPPER(
		int,
		 glutGameModeGet,
		(GLenum mode),
		(mode));
		
#endif
