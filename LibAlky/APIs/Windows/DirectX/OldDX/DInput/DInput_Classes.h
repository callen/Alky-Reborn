/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
 */

#ifndef __APIS_WINDOWS_DINPUT_CLASSES_H__
#define __APIS_WINDOWS_DINPUT_CLASSES_H__

#include <APIs/Windows/Windows.h>
#include <APIs/Windows/COM/COM.h>

unsigned char sdl2dinput[256] = {
	0, 0, 0, 0, // 0
	0, 0, 0, 0, // 4
	0x0E, 0xF, 0, 0, // 8
	0, 0x1C, 0, 0, // 12
	0, 0, 0, 0, // 16
	0, 0, 0, 0, // 20
	0, 0, 0, 0x01, // 24
	0, 0, 0, 0, // 28
	0x39, 0, 0, 0, // 32
	0, 0, 0, 0x28, // 36
	0, 0, 0, 0, // 40
	0x33, 0x0C, 0x34, 0x35, // 44
	0x0B, 0x02, 0x03, 0x04, // 48
	0x05, 0x06, 0x07, 0x08, // 52
	0x09, 0x0A, 0, 0x27, // 56
	0, 0, 0, 0, // 60
	0, 0, 0, 0, // 64
	0, 0, 0, 0, // 68
	0, 0, 0, 0, // 72
	0, 0, 0, 0, // 76
	0, 0, 0, 0, // 80
	0, 0, 0, 0, // 84
	0, 0, 0, 0x1A, // 88
	0x2B, 0x1B, 0, 0, // 92
	0x29, 0x1E, 0x30, 0x2E, // 96
	0x20, 0x12, 0x21, 0x22, // 100
	0x23, 0x17, 0x24, 0x25, // 104
	0x26, 0x32, 0x31, 0x18, // 108
	0x19, 0x10, 0x13, 0x1F, // 112
	0x14, 0x16, 0x2F, 0x11, // 116
	0x11, 0x2D, 0x15, 0x2C, // 120
	0, 0, 0, 0, // 124
	0, 0, 0, 0, 0, 0, 0, 0, // 128
	0, 0, 0, 0, 0, 0, 0, 0, // 144
	0, 0, 0, 0, 0, 0, 0, 0, // 160
	0, 0, 0, 0, 0, 0, 0, 0, // 176
	0, 0, 0, 0, 0, 0, 0, 0, // 192
	0, 0, 0, 0, 0, 0, 0, 0, // 208
	0, 0, 0, 0, 0, 0, 0, 0, // 224
	0, 0, 0, 0, 0, 0, 0, 0  // 240
};

CLASS(
	IDirectInput7,
	STRUCT(),
	VTABLE(
		CMEMBER(IDirectInput7_CreateDevice)
	)
);

CLASS(
	IDirectInputDevice7A,
	STRUCT(
		SDL_mutex *mutex;
		bool isMouse;
		LPDIDATAFORMAT lpdf;
		int sequence;
		
		NuGUI_Event *events[256];
	),
	VTABLE(
		CSTUB(IDirectInputDeviceA_GetCapabilitiesA),
		CSTUB(IDirectInputDeviceA_EnumObjects),
		CSTUB(IDirectInputDeviceA_GetProperty),
		CMEMBER(IDirectInputDeviceA_SetProperty),
		CMEMBER(IDirectInputDeviceA_Acquire),
		CMEMBER(IDirectInputDeviceA_Unacquire),
		CSTUB(IDirectInputDeviceA_GetDeviceState),
		CMEMBER(IDirectInputDeviceA_GetDeviceData),
		CMEMBER(IDirectInputDeviceA_SetDataFormat),
		CSTUB(IDirectInputDeviceA_SetEventNotification),
		CMEMBER(IDirectInputDeviceA_SetCooperativeLevel),
		CSTUB(IDirectInputDeviceA_GetObjectInfo),
		CSTUB(IDirectInputDeviceA_GetDeviceInfo),
		CSTUB(IDirectInputDeviceA_RunControlPanel),
		CSTUB(IDirectInputDeviceA_Initialize),
		
		CSTUB(IDirectInputDevice2A_CreateEffect),
		CSTUB(IDirectInputDevice2A_EnumEffects),
		CSTUB(IDirectInputDevice2A_GetEffectInfo),
		CSTUB(IDirectInputDevice2A_GetForceFeedbackState),
		CSTUB(IDirectInputDevice2A_SendForceFeedbackCommand),
		CSTUB(IDirectInputDevice2A_EnumCreatedEffectObjects),
		CSTUB(IDirectInputDevice2A_Escape),
		CSTUB(IDirectInputDevice2A_Poll),
		CSTUB(IDirectInputDevice2A_SendDeviceData),

		CSTUB(IDirectInputDevice7A_EnumEffectsInFile),
		CSTUB(IDirectInputDevice7A_WriteEffectsToFile)
	)
);

CLASS(
	IDirectInput8,
	STRUCT(),
	VTABLE(
		CMEMBER(IDirectInput8_ConfigureDevices),
		CMEMBER(IDirectInput8_CreateDevice),
		CSTUB(IDirectInput8_EnumDevices),
		CSTUB(IDirectInput8_EnumDevicesBySemantics),
		CSTUB(IDirectInput8_FindDevice),
		CSTUB(IDirectInput8_GetDeviceStatus),
		CSTUB(IDirectInput8_Initialize),
		CSTUB(IDirectInput8_RunControlPanel)
	)
);

CLASS(
	IDirectInputDevice8,
	STRUCT(
		SDL_mutex *mutex;
		bool isMouse;
		LPDIDATAFORMAT lpdf;
		int sequence;
	),
	VTABLE(
		CSTUB(IDirectInputDevice8_Acquire),
		CSTUB(IDirectInputDevice8_Unacquire),
		CSTUB(IDirectInputDevice8_BuildActionMap),
		CSTUB(IDirectInputDevice8_GetImageInfo),
		CSTUB(IDirectInputDevice8_SetActionMap),
		CSTUB(IDirectInputDevice8_GetCapabilities),
		CSTUB(IDirectInputDevice8_GetDeviceData),
		CSTUB(IDirectInputDevice8_GetDeviceInfo),
		CSTUB(IDirectInputDevice8_GetDeviceState),
		CSTUB(IDirectInputDevice8_Poll),
		CSTUB(IDirectInputDevice8_SetDataFormat),
		CSTUB(IDirectInputDevice8_SetEventNotification),
		CSTUB(IDirectInputDevice8_EnumObjects),
		CSTUB(IDirectInputDevice8_GetObjectInfo),
		CSTUB(IDirectInputDevice8_GetProperty),
		CSTUB(IDirectInputDevice8_SetCooperativeLevel),
		CSTUB(IDirectInputDevice8_SetProperty),
		CSTUB(IDirectInputDevice8_CreateEffect),
		CSTUB(IDirectInputDevice8_EnumCreatedEffectObjects),
		CSTUB(IDirectInputDevice8_EnumEffects),
		CSTUB(IDirectInputDevice8_EnumEffectsInFile),
		CSTUB(IDirectInputDevice8_Escape),
		CSTUB(IDirectInputDevice8_GetEffectInfo),
		CSTUB(IDirectInputDevice8_GetForceFeedbackState),
		CSTUB(IDirectInputDevice8_SendForceFeedbackState),
		CSTUB(IDirectInputDevice8_WriteEffectToFile),
		CSTUB(IDirectInputDevice8_Initialize),
		CSTUB(IDirectInputDevice8_RunControlPanel),
		CSTUB(IDirectInputDevice8_SendDeviceData)
	)
);

CLASS(
	IDirectInputEffect,
	STRUCT(),
	VTABLE(
		CSTUB(IDirectInputEffect_GetEffectGuid),
		CSTUB(IDirectInputEffect_GetEffectStatus),
		CSTUB(IDirectInputEffect_GetParameters),
		CSTUB(IDirectInputEffect_Download),
		CSTUB(IDirectInputEffect_Initialize),
		CSTUB(IDirectInputEffect_SetParameters),
		CSTUB(IDirectInputEffect_Start),
		CSTUB(IDirectInputEffect_Stop),
		CSTUB(IDirectInputEffect_Unload),
		CSTUB(IDirectInputEffect_Escape)
	)
);

#endif
