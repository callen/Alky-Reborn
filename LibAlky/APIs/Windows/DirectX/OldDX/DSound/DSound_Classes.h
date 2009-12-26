/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __APIS_WINDOWS_DSOUND_DSOUND_CLASSES_H__
#define __APIS_WINDOWS_DSOUND_DSOUND_CLASSES_H__

#include <APIs/Windows/Windows.h>
#include <APIs/Windows/COM/COM.h>

CLASS(
	IDirectSound8,
	STRUCT(),
	VTABLE(
		CMEMBER(IDirectSound8_Compact),
		CMEMBER(IDirectSound8_CreateSoundBuffer),
		CSTUB(IDirectSound8_DuplicateSoundBuffer),
		CMEMBER(IDirectSound8_GetCaps),
		CSTUB(IDirectSound8_GetSpeakerConfig),
		CMEMBER(IDirectSound8_Initialize),
		CSTUB(IDirectSound8_SetCooperativeLevel),
		CSTUB(IDirectSound8_SetSpeakerConfig),
		CSTUB(IDirectSound8_VerifyCertification)
	)
);

CLASS(
	IDirectSoundBuffer8,
	STRUCT(),
	VTABLE(
		CSTUB(IDirectSoundBuffer8_GetCaps),
		CSTUB(IDirectSoundBuffer8_GetCurrentPosition),
		CSTUB(IDirectSoundBuffer8_GetFormat),
		CSTUB(IDirectSoundBuffer8_GetVolume),
		CSTUB(IDirectSoundBuffer8_GetPan),
		CSTUB(IDirectSoundBuffer8_GetFrequency),
		CSTUB(IDirectSoundBuffer8_GetStatus),
		CSTUB(IDirectSoundBuffer8_Initialize),
		CSTUB(IDirectSoundBuffer8_Lock),
		CSTUB(IDirectSoundBuffer8_Play),
		CSTUB(IDirectSoundBuffer8_SetCurrentPosition),
		CSTUB(IDirectSoundBuffer8_SetFormat),
		CSTUB(IDirectSoundBuffer8_SetVolume),
		CSTUB(IDirectSoundBuffer8_SetPan),
		CSTUB(IDirectSoundBuffer8_SetFrequently),
		CSTUB(IDirectSoundBuffer8_Stop),
		CSTUB(IDirectSoundBuffer8_Unlock),
		CSTUB(IDirectSoundBuffer8_Restore),
		CSTUB(IDirectSoundBuffer8_SetFX),
		CSTUB(IDirectSoundBuffer8_AcquireResources),
		CSTUB(IDirectSoundBuffer8_GetObjectInPath)
	)
);

#endif
