/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __APIS_WINDOWS_OPENAL32_OPENAL32_H__
#define __APIS_WINDOWS_OPENAL32_OPENAL32_H__

#include <APIs/Windows/Windows.h>

#ifdef MAC
#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#else
#include <AL/al.h>
#include <AL/alc.h>
#endif

/*
#ifdef DEFINE_OAL_WRAPPERS
#define OAL_WRAPPER(ret, name, args, argnames) \
WINAPI_CDECL ret name##_ args { return name argnames; }
#define OALC_WRAPPER(ret, name, args, argnames) \
WINAPI_CDECL ret name##_ args { return name argnames; }
#else
#define OAL_WRAPPER(ret, name, args, argnames) \
WINAPI_CDECL ret name##_ args;
#define OALC_WRAPPER(ret, name, args, argnames) \
WINAPI_CDECL ret name##_ args;
#endif

OAL_WRAPPER(
	void,
	alEnable,
	( ALenum capability ),
	(capability));
OAL_WRAPPER(
	void,
	alDisable,
	( ALenum capability ),
	(capability));
OAL_WRAPPER(
	ALboolean,
	alIsEnabled,
	( ALenum capability ),
	(capability));
OAL_WRAPPER(
	ALubyte*,
	alGetString,
	( ALenum param ),
	(param));
OAL_WRAPPER(
	void,
	alGetBooleanv,
	( ALenum param, ALboolean* data ),
	(param, data));
OAL_WRAPPER(
	void,
	alGetIntegerv,
	( ALenum param, ALint* data ),
	(param, data));
OAL_WRAPPER(
	void,
	alGetFloatv,
	( ALenum param, ALfloat* data ),
	(param, data));
OAL_WRAPPER(
	void,
	alGetDoublev,
	( ALenum param, ALdouble* data ),
	(param, data));
OAL_WRAPPER(
	ALboolean,
	alGetBoolean,
	( ALenum param ),
	(param));
OAL_WRAPPER(
	ALint,
	alGetInteger,
	( ALenum param ),
	(param));
OAL_WRAPPER(
	ALfloat,
	alGetFloat,
	( ALenum param ),
	(param));
OAL_WRAPPER(
	ALdouble,
	alGetDouble,
	( ALenum param ),
	(param));
OAL_WRAPPER(
	ALenum,
	alGetError,
	(),
	());
/* OAL_WRAPPER(
	ALboolean,
	alIsExtensionPresent,
	( const ALubyte* extname ),
	(extname));
OAL_WRAPPER(
	void*,
	alGetProcAddress,
	( const ALubyte* fname ),
	(fname));
OAL_WRAPPER(
	ALenum,
	alGetEnumValue,
	( const ALubyte* ename ),
	(ename));
OAL_WRAPPER(
	void,
	alListenerf,
	( ALenum param, ALfloat value ),
	(param, value));
OAL_WRAPPER(
	void,
	alListener3f,
	( ALenum param, ALfloat value1, ALfloat value2, ALfloat value3 ),
	(param, value1, value2, value3));
OAL_WRAPPER(
	void,
	alListenerfv,
	( ALenum param, const ALfloat* values ),
	(param, values));
OAL_WRAPPER(
	void,
	alListeneri,
	( ALenum param, ALint value ),
	(param, value));
OAL_WRAPPER(
	void,
	alListener3i,
	( ALenum param, ALint value1, ALint value2, ALint value3 ),
	(param, value1, value2, value3));
OAL_WRAPPER(
	void,
	alListeneriv,
	( ALenum param, const ALint* values ),
	(param, values));
OAL_WRAPPER(
	void,
	alGetListenerf,
	( ALenum param, ALfloat* value ),
	(param, value));
OAL_WRAPPER(
	void,
	alGetListener3f,
	( ALenum param, ALfloat *value1, ALfloat *value2, ALfloat *value3 ),
	(param,  value1,  value2,  value3));
OAL_WRAPPER(
	void,
	alGetListenerfv,
	( ALenum param, ALfloat* values ),
	(param, values));
OAL_WRAPPER(
	void,
	alGetListeneri,
	( ALenum param, ALint* value ),
	(param, value));
OAL_WRAPPER(
	void,
	alGetListener3i,
	( ALenum param, ALint *value1, ALint *value2, ALint *value3 ),
	(param,  value1,  value2,  value3));
OAL_WRAPPER(
	void,
	alGetListeneriv,
	( ALenum param, ALint* values ),
	(param, values));
OAL_WRAPPER(
	void,
	alGenSources,
	( ALsizei n, ALuint* sources ),
	(n, sources));
OAL_WRAPPER(
	void,
	alDeleteSources,
	( ALsizei n, const ALuint* sources ),
	(n, sources));
OAL_WRAPPER(
	ALboolean,
	alIsSource,
	( ALuint sid ),
	(sid));
OAL_WRAPPER(
	void,
	alSourcef,
	( ALuint sid, ALenum param, ALfloat value ),
	(sid, param, value));
OAL_WRAPPER(
	void,
	alSource3f,
	( ALuint sid, ALenum param, ALfloat value1, ALfloat value2, ALfloat value3 ),
	(sid, param, value1, value2, value3));
OAL_WRAPPER(
	void,
	alSourcefv,
	( ALuint sid, ALenum param, const ALfloat* values ),
	(sid, param, values));
OAL_WRAPPER(
	void,
	alSourcei,
	( ALuint sid, ALenum param, ALint value ),
	(sid, param, value));
OAL_WRAPPER(
	void,
	alSource3i,
	( ALuint sid, ALenum param, ALint value1, ALint value2, ALint value3 ),
	(sid, param, value1, value2, value3));
OAL_WRAPPER(
	void,
	alSourceiv,
	( ALuint sid, ALenum param, const ALint* values ),
	(sid, param, values));
OAL_WRAPPER(
	void,
	alGetSourcef,
	( ALuint sid, ALenum param, ALfloat* value ),
	(sid, param, value));
OAL_WRAPPER(
	void,
	alGetSource3f,
	( ALuint sid, ALenum param, ALfloat* value1, ALfloat* value2, ALfloat* value3),
	(sid, param, value1, value2, value3));
OAL_WRAPPER(
	void,
	alGetSourcefv,
	( ALuint sid, ALenum param, ALfloat* values ),
	(sid, param, values));
OAL_WRAPPER(
	void,
	alGetSourcei,
	( ALuint sid,  ALenum param, ALint* value ),
	(sid, param, value));
OAL_WRAPPER(
	void,
	alGetSource3i,
	( ALuint sid, ALenum param, ALint* value1, ALint* value2, ALint* value3),
	(sid, param, value1, value2, value3));
OAL_WRAPPER(
	void,
	alGetSourceiv,
	( ALuint sid,  ALenum param, ALint* values ),
	(sid, param, values));
OAL_WRAPPER(
	void,
	alSourcePlayv,
	( ALsizei ns, const ALuint *sids ),
	(ns,  sids));
OAL_WRAPPER(
	void,
	alSourceStopv,
	( ALsizei ns, const ALuint *sids ),
	(ns,  sids));
OAL_WRAPPER(
	void,
	alSourceRewindv,
	( ALsizei ns, const ALuint *sids ),
	(ns,  sids));
OAL_WRAPPER(
	void,
	alSourcePausev,
	( ALsizei ns, const ALuint *sids ),
	(ns,  sids));
OAL_WRAPPER(
	void,
	alSourcePlay,
	( ALuint sid ),
	(sid));
OAL_WRAPPER(
	void,
	alSourceStop,
	( ALuint sid ),
	(sid));
OAL_WRAPPER(
	void,
	alSourceRewind,
	( ALuint sid ),
	(sid));
OAL_WRAPPER(
	void,
	alSourcePause,
	( ALuint sid ),
	(sid));
OAL_WRAPPER(
	void,
	alSourceQueueBuffers,
	( ALuint sid, ALsizei numEntries, const ALuint *bids ),
	(sid, numEntries,  bids));
OAL_WRAPPER(
	void,
	alSourceUnqueueBuffers,
	( ALuint sid, ALsizei numEntries, ALuint *bids ),
	(sid, numEntries,  bids));
OAL_WRAPPER(
	void,
	alGenBuffers,
	( ALsizei n, ALuint* buffers ),
	(n, buffers));
OAL_WRAPPER(
	void,
	alDeleteBuffers,
	( ALsizei n, const ALuint* buffers ),
	(n, buffers));
OAL_WRAPPER(
	ALboolean,
	alIsBuffer,
	( ALuint bid ),
	(bid));
OAL_WRAPPER(
	void,
	alBufferData,
	( ALuint bid, ALenum format, const ALvoid* data, ALsizei size, ALsizei freq ),
	(bid, format, data, size, freq));
OAL_WRAPPER(
	void,
	alBufferf,
	( ALuint bid, ALenum param, ALfloat value ),
	(bid, param, value));
OAL_WRAPPER(
	void,
	alBuffer3f,
	( ALuint bid, ALenum param, ALfloat value1, ALfloat value2, ALfloat value3 ),
	(bid, param, value1, value2, value3));
OAL_WRAPPER(
	void,
	alBufferfv,
	( ALuint bid, ALenum param, const ALfloat* values ),
	(bid, param, values));
OAL_WRAPPER(
	void,
	alBufferi,
	( ALuint bid, ALenum param, ALint value ),
	(bid, param, value));
OAL_WRAPPER(
	void,
	alBuffer3i,
	( ALuint bid, ALenum param, ALint value1, ALint value2, ALint value3 ),
	(bid, param, value1, value2, value3));
OAL_WRAPPER(
	void,
	alBufferiv,
	( ALuint bid, ALenum param, const ALint* values ),
	(bid, param, values));
OAL_WRAPPER(
	void,
	alGetBufferf,
	( ALuint bid, ALenum param, ALfloat* value ),
	(bid, param, value));
OAL_WRAPPER(
	void,
	alGetBuffer3f,
	( ALuint bid, ALenum param, ALfloat* value1, ALfloat* value2, ALfloat* value3),
	(bid, param, value1, value2, value3));
OAL_WRAPPER(
	void,
	alGetBufferfv,
	( ALuint bid, ALenum param, ALfloat* values ),
	(bid, param, values));
OAL_WRAPPER(
	void,
	alGetBufferi,
	( ALuint bid, ALenum param, ALint* value ),
	(bid, param, value));
OAL_WRAPPER(
	void,
	alGetBuffer3i,
	( ALuint bid, ALenum param, ALint* value1, ALint* value2, ALint* value3),
	(bid, param, value1, value2, value3));
OAL_WRAPPER(
	void,
	alGetBufferiv,
	( ALuint bid, ALenum param, ALint* values ),
	(bid, param, values));
OAL_WRAPPER(
	void,
	alDopplerFactor,
	( ALfloat value ),
	(value));
OAL_WRAPPER(
	void,
	alDopplerVelocity,
	( ALfloat value ),
	(value));
OAL_WRAPPER(
	void,
	alSpeedOfSound,
	( ALfloat value ),
	(value));
OAL_WRAPPER(
	void,
	alDistanceModel,
	( ALenum distanceModel ),
	(distanceModel));

OALC_WRAPPER(
	ALCcontext *   ,
	alcCreateContext,
	( ALCdevice *device, const ALCint* attrlist ),
	( device, attrlist));
OALC_WRAPPER(
	ALCboolean     ,
	alcMakeContextCurrent,
	( ALCcontext *context ),
	( context));
OALC_WRAPPER(
	void           ,
	alcProcessContext,
	( ALCcontext *context ),
	( context));
OALC_WRAPPER(
	void           ,
	alcSuspendContext,
	( ALCcontext *context ),
	( context));
OALC_WRAPPER(
	void           ,
	alcDestroyContext,
	( ALCcontext *context ),
	( context));
OALC_WRAPPER(
	ALCcontext *   ,
	alcGetCurrentContext,
	(),
	());
OALC_WRAPPER(
	ALCdevice*     ,
	alcGetContextsDevice,
	( ALCcontext *context ),
	( context));
OALC_WRAPPER(
	ALCdevice *    ,
	alcOpenDevice,
	( const ALCubyte *devicename ),
	( devicename));
OALC_WRAPPER(
	ALCvoid     ,
	alcCloseDevice,
	( ALCdevice *device ),
	( device));
OALC_WRAPPER(
	ALCenum        ,
	alcGetError,
	( ALCdevice *device ),
	( device));
OALC_WRAPPER(
	ALCboolean     ,
	alcIsExtensionPresent,
	( ALCdevice *device, const ALCubyte *extname ),
	( device,  extname));
OALC_WRAPPER(
	void  *        ,
	alcGetProcAddress,
	( ALCdevice *device, const ALCubyte *funcname ),
	( device,  funcname));
OALC_WRAPPER(
	ALCenum        ,
	alcGetEnumValue,
	( ALCdevice *device, const ALCubyte *enumname ),
	( device,  enumname));
OALC_WRAPPER(
	const ALCubyte *,
	alcGetString,
	( ALCdevice *device, ALCenum param ),
	( device, param));
OALC_WRAPPER(
	void           ,
	alcGetIntegerv,
	( ALCdevice *device, ALCenum param, ALCsizei size, ALCint *data ),
	( device, param, size,  data));
OALC_WRAPPER(
	ALCdevice*     ,
	alcCaptureOpenDevice,
	( const ALCubyte *devicename, ALCuint frequency, ALCenum format, ALCsizei buffersize ),
	( devicename, frequency, format, buffersize));
OALC_WRAPPER(
	ALCboolean     ,
	alcCaptureCloseDevice,
	( ALCdevice *device ),
	( device));
OALC_WRAPPER(
	void           ,
	alcCaptureStart,
	( ALCdevice *device ),
	( device));
OALC_WRAPPER(
	void           ,
	alcCaptureStop,
	( ALCdevice *device ),
	( device));
OALC_WRAPPER(
	void           ,
	alcCaptureSamples,
	( ALCdevice *device, ALCvoid *buffer, ALCsizei samples ),
	( device,  buffer, samples));
*/

#endif
