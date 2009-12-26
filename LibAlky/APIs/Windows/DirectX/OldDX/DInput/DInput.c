/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#define DEFINE_CLASSES
#include <APIs/Windows/DirectX/DInput/DInput.h>
#include <APIs/Windows/DirectX/DInput/DInput_Classes.h>

#define NUMODULE_NAME "DInput"

VTABLE_SETUP_FUNC(
	VTABLE_SETUP(IDirectInput7)
	VTABLE_SETUP(IDirectInput8)
	VTABLE_SETUP(IDirectInputDevice8)
	VTABLE_SETUP(IDirectInputDevice7A)
);

void dinput_add_event(NuGUI_Event *event, void *user_data) {
	CSTRUCT(IDirectInputDevice7A) *_Context;
	
	int i;
	
	_Context = (CSTRUCT(IDirectInputDevice7A) *) user_data;
	
	if(_Context->isMouse && (event->type == SDL_KEYDOWN || event->type == SDL_KEYUP))
		return;
	
	if(!_Context->isMouse &&
		(
			event->type == SDL_MOUSEBUTTONDOWN ||
			event->type == SDL_MOUSEBUTTONUP ||
			event->type == SDL_MOUSEMOTION
		)
	)
		return;
	
	for(i = 0; i < 256; ++i) {
		if(_Context->events[i] != None)
			continue;
		
		break;
	}
	
	_Context->events[i] = NuMemory_Alloc(sizeof(NuGUI_Event));
	memcpy(_Context->events[i], event, sizeof(NuGUI_Event));
}

int dinput_event_count(CSTRUCT(IDirectInputDevice7A) *_Context, int type) {
	int i, count = 0;
	
	for(i = 0; i < 256; ++i) {
		if(!_Context->events[i])
			continue;
		
		if(_Context->events[i]->type == type)
			++count;
	}
	
	return count;
}

NuGUI_Event *dinput_event_get(CSTRUCT(IDirectInputDevice7A) *_Context, int type, bool pop) {
	NuGUI_Event *ret;
	
	int i;
	
	for(i = 0; i < 256; ++i) {
		if(!_Context->events[i] || _Context->events[i]->type != type)
			continue;
		
		ret = _Context->events[i];
		
		if(pop)
			_Context->events[i] = None;
		
		return ret;
	}
	
	return None;
}

WINAPI HRESULT IDirectInput7_CreateDevice(
  void *this_,
  REFGUID rguid,
  void **lplpDirectInputDevice,
  LPUNKNOWN pUnkOuter
) {
	CSTRUCT(IDirectInputDevice7A) *_Context;
	
	NuLog("IDirectInput7::CreateDevice");
	
	if(pUnkOuter)
		lplpDirectInputDevice = pUnkOuter;
	
	INIT_CLASS(IDirectInputDevice7A, *lplpDirectInputDevice);
	_Context = GET_CLASS_STRUCT(IDirectInputDevice7A, *lplpDirectInputDevice);
	
	_Context->lpdf = None;
	
	if(rguid->Data1 == 0x6F1D2B60)
		_Context->isMouse = True;
	else if(rguid->Data1 == 0x6F1D2B61)
		_Context->isMouse = False;
	else
		NuError("Unsupported GUID to IDirectInput7::CreateDevice: %p", rguid->Data1);
	
	_Context->mutex = SDL_CreateMutex();
	
	_Context->sequence = 0;
	
	memset(_Context->events, 0, sizeof(NuGUI_Event *) * 256);
	
	NuGUI_AddEventCallback(dinput_add_event, _Context);
	
	return S_OK;
}

WINAPI HRESULT DirectInputCreateA(
  HINSTANCE hinst,
  DWORD dwVersion,
  LPVOID* ppvOut,
  LPUNKNOWN *pUnkOuter
) {
	NuLog("DirectInputCreateA");
	
	if(pUnkOuter != None)
		ppvOut = pUnkOuter;
	
	switch (dwVersion & 0xFF00) {
		case 0x0700:
			INIT_CLASS(IDirectInput7, *ppvOut);
			break;
		case 0x0800:
			INIT_CLASS(IDirectInput8, *ppvOut);
			break;
		default:
			NuError("dwVersion is not a valid identifier");
	}
	
	return DI_OK;
}

WINAPI HRESULT DirectInput8Create(
    HINSTANCE hinst,
    DWORD dwVersion,
    REFIID riidltf,
    LPVOID *ppvOut,
    LPUNKNOWN *pUnkOuter
) {
	return DirectInputCreateA(hinst, dwVersion, ppvOut, pUnkOuter);
}

WINAPI HRESULT IDirectInput7_Release(
    void *this_
) {
	return S_OK;
}

WINAPI HRESULT IDirectInputDevice7A_Release(
    void *this_
) {
	return S_OK;
}

WINAPI HRESULT IDirectInputDeviceA_GetDeviceData(
  void *this_,
  DWORD cbObjectData,
  LPDIDEVICEOBJECTDATA rgdod,
  LPDWORD pdwInOut,
  DWORD dwFlags
) {
	static DWORD timestamp = 0;
	static unsigned char *keys = None;
	static DWORD sequence = 0;
	
	CSTRUCT(IDirectInputDevice7A) *_Context;
	LPDIDATAFORMAT lpdf;
	NuGUI_Event *event;
	int i, max;
	int inbutton;
	int instance;
	
	bool pop;
	
	DIDEVICEOBJECTDATA data;
	
	void *rgdod_math;
	
	NuLog("IDirectInputDeviceA::GetDeviceData");
	
	if(keys == None) {
		keys = NuMemory_Alloc(256);
		memset(keys, 0, 256);
	}
	
	_Context = GET_CLASS_STRUCT(IDirectInputDevice7A, this_);
	
	NuLog("%s", (_Context->isMouse) ? "Mouse" : "Keyboard");
	
	SDL_LockMutex(_Context->mutex);
	lpdf = _Context->lpdf;
	
	if(lpdf == None) {
		SDL_UnlockMutex(_Context->mutex);
		return DI_OK;
	}
	
	if(*pdwInOut == 0) {
		if(_Context->isMouse) {
			*pdwInOut += dinput_event_count(_Context, SDL_MOUSEMOTION);
			*pdwInOut += dinput_event_count(_Context, SDL_MOUSEBUTTONDOWN);
			*pdwInOut += dinput_event_count(_Context, SDL_MOUSEBUTTONUP);
		} else {
			*pdwInOut += dinput_event_count(_Context, SDL_KEYUP);
			*pdwInOut += dinput_event_count(_Context, SDL_KEYDOWN);
		}
		SDL_UnlockMutex(_Context->mutex);
		return DI_BUFFEROVERFLOW;
	}
	
	max = *pdwInOut;
	
	*pdwInOut = 0;
	
	pop = (dwFlags & DIGDD_PEEK) ? False : True;
	
	while(*pdwInOut < max) {
		if(_Context->isMouse) {
			event = dinput_event_get(_Context, SDL_MOUSEMOTION, pop);
			if(event != None)
				goto event_recvd;
			
			event = dinput_event_get(_Context, SDL_MOUSEBUTTONDOWN, pop);
			if(event != None)
				goto event_recvd;
			
			event = dinput_event_get(_Context, SDL_MOUSEBUTTONUP, pop);
			if(event != None)
				goto event_recvd;
		} else {
			event = dinput_event_get(_Context, SDL_KEYDOWN, pop);
			if(event != None)
				goto event_recvd;
			
			event = dinput_event_get(_Context, SDL_KEYUP, pop);
			if(event != None)
				goto event_recvd;
		}
		
		if(event == None)
			break;
			
event_recvd:
		
		switch(event->type) {
			case SDL_MOUSEMOTION:
				if(!_Context->isMouse)
					break;
				
				if(event->motion.xrel == 0 || event->motion.yrel == 0)
					break;
				if(event->motion.x == 128 && event->motion.y == 128)
					break;
				for(i = 0; i < lpdf->dwNumObjs; ++i) {
					data.dwOfs = lpdf->rgodf[i].dwOfs;
					data.dwTimeStamp = NuGUI_GetTicks();
					data.dwSequence = sequence++;
					data.dwData = 0;
					
					if(lpdf->rgodf[i].dwType & DIDFT_AXIS) {
						if(lpdf->rgodf[i].pguid->Data1 == 0xA36D02E0)
							data.dwData = event->motion.xrel;
						else if(lpdf->rgodf[i].pguid->Data1 == 0xA36D02E1)
							data.dwData = event->motion.yrel;
						else
							continue;
					}
					
					/*
					NuLog(
						"Mouse: dwOfs: %p dwTimeStamp: %p dwSequence: %p dwData: %p cbObjectData: %p",
						data.dwOfs,
						data.dwTimeStamp,
						data.dwSequence,
						data.dwData,
						cbObjectData
					);
					*/
					
					if(rgdod != None) {
						rgdod_math = (void *) ((char *) rgdod) + (cbObjectData * *pdwInOut);
						memcpy(rgdod_math, &data, cbObjectData);
					}
					(*pdwInOut)++;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
			case SDL_MOUSEBUTTONUP:
				if(!_Context->isMouse)
					break;
				
				instance = 0;
				
				for(i = 0; i < lpdf->dwNumObjs; ++i) {
					data.dwOfs = lpdf->rgodf[i].dwOfs;
					data.dwTimeStamp = NuGUI_GetTicks();
					data.dwSequence = sequence++;
					data.dwData = 0;
					
					if(DIDFT_BUTTON == (lpdf->rgodf[i].dwType & 0xFF)) {
						if((lpdf->rgodf[i].dwType & DIDFT_ANYINSTANCE) == DIDFT_ANYINSTANCE) {
							if(instance == event->button.button - 1)
								data.dwData = (event->type == SDL_MOUSEBUTTONUP) ? 0x0 : 0x80;
							instance++;
						} else if((lpdf->rgodf[i].dwType & DIDFT_ANYINSTANCE) == event->button.button)
							data.dwData = (event->type == SDL_MOUSEBUTTONUP) ? 0x0 : 0x80;
						else
							continue;
						
						if(rgdod != None) {
							rgdod_math = (void *) ((char *) rgdod) + (cbObjectData * *pdwInOut);
							memcpy(rgdod_math, &data, cbObjectData);
						}
						(*pdwInOut)++;
					}
				}
				break;
			case SDL_KEYDOWN:
			case SDL_KEYUP:
				if(_Context->isMouse)
					break;
				
				if(event->key.keysym.sym > 255)
					break;
				
				data.dwOfs = sdl2dinput[event->key.keysym.sym];
				data.dwTimeStamp = NuGUI_GetTicks();
				data.dwSequence = sequence++;
				data.dwData = (event->type == SDL_KEYUP) ? 0x0 : 0x80;
				
				/*
				NuLog(
					"Keyboard: dwOfs: %p dwTimeStamp: %p dwSequence: %p dwData: %p cbObjectData: %p",
					data.dwOfs,
					data.dwTimeStamp,
					data.dwSequence,
					data.dwData,
					cbObjectData
				);
				*/
				
				if(rgdod != None) {
					rgdod_math = (void *) ((char *) rgdod) + (cbObjectData * *pdwInOut);
					memcpy(rgdod_math, &data, cbObjectData);
				}
				(*pdwInOut)++;
				
				break;
		}
		
		if(pop)
			NuGUI_FreeEvent(event);
	}
	
	SDL_UnlockMutex(_Context->mutex);
	
	return DI_OK;
}

WINAPI HRESULT IDirectInputDeviceA_SetDataFormat(
  void *this_,
  LPCDIDATAFORMAT lpdf
) {
	CSTRUCT(IDirectInputDevice7A) *_Context;
	LPDIDATAFORMAT lpdfCopy;
	int i;
	
	NuLog("IDirectInputDeviceA::SetDataFormat");
	
	_Context = GET_CLASS_STRUCT(IDirectInputDevice7A, this_);
	
	SDL_LockMutex(_Context->mutex);
	
	lpdfCopy = NuMemory_Alloc(sizeof(DIDATAFORMAT));
	lpdfCopy->rgodf = NuMemory_Alloc(lpdf->dwNumObjs * sizeof(DIOBJECTDATAFORMAT));
	
	memcpy(lpdfCopy, lpdf, sizeof(DIDATAFORMAT));
	memcpy(lpdfCopy->rgodf, lpdf->rgodf, lpdf->dwNumObjs * sizeof(DIOBJECTDATAFORMAT));
	
	for(i = 0; i < lpdf->dwNumObjs; ++i) {
		NuLog(
			"dwOfs: %p dwType: %p dwFlags: %p",
			lpdf->rgodf[i].dwOfs,
			lpdf->rgodf[i].dwType,
			lpdf->rgodf[i].dwFlags
		);
	}
	
	//for(i = 0; i < lpdf->dwNumObjs; ++i) {
	//	lpdfCopy->rgodf[i].pguid = NuMemory_Alloc(sizeof(GUID));
	//	memcpy(lpdfCopy->rgodf[i].pguid, lpdf->rgodf[i].pguid, sizeof(GUID));
	//}
	
	_Context->lpdf = lpdfCopy;
	
	SDL_UnlockMutex(_Context->mutex);

	return DI_OK;
}

WINAPI HRESULT IDirectInputDeviceA_SetCooperativeLevel(
  void *this_,
  HWND hwnd,
  DWORD dwFlags
) {
	NuLog("IDirectInputDeviceA::SetCooperativeLevel");

	return DI_OK;
}

WINAPI HRESULT IDirectInputDeviceA_SetProperty(
  void *this_,
  REFGUID rguidProp,
  LPCDIPROPHEADER pdiph
) {
	NuLog("IDirectInputDeviceA::SetProperty");
	
	return DI_OK;
}

WINAPI HRESULT IDirectInputDeviceA_Acquire(void *this_) {
	NuLog("IDirectInputDeviceA::Acquire");

	return DI_OK;
}

WINAPI HRESULT IDirectInputDeviceA_Unacquire(void *this_) {
	NuLog("IDirectInputDeviceA::Unacquire");
	
	return DI_OK;
}

WINAPI HRESULT IDirectInput8_Release(
    void *this_
) {
	return S_OK;
}

WINAPI HRESULT IDirectInput8_ConfigureDevices(
	void *this_,
	LPDICONFIGUREDEVICESCALLBACK lpdiCallback,
	LPDICONFIGUREDEVICESPARAMS lpdiCDParams,
	DWORD dwFlags
) {
	NuWarn("IDirectInput8::ConfigureDevices not yet implemeted");
	
	return -1;
}

WINAPI HRESULT IDirectInput8_CreateDevice(
  void *this_,
  REFGUID rguid,
  void ** lplpDirectInputDevice,
  LPUNKNOWN *pUnkOuter
) {
	CSTRUCT(IDirectInputDevice8) *_Context;
	
	NuLog("IDirectInput8::CreateDevice");
	
	if(pUnkOuter)
		lplpDirectInputDevice = pUnkOuter;
	
	INIT_CLASS(IDirectInputDevice8, *lplpDirectInputDevice);
	_Context = GET_CLASS_STRUCT(IDirectInputDevice8, *lplpDirectInputDevice);
	
	_Context->lpdf = None;
	
	if(rguid > 0xFFFF) {
		switch(rguid->Data1) {
			case 0x6F1D2B60:
				_Context->isMouse = True;
				break;
			case 0x6F1D2B61:
				_Context->isMouse = False;
				break;
			default:
				NuWarn("Unsupported GUID to IDirectInput8::CreateDevice: %p", rguid->Data1);
				
				goto error;
		}
	} else {
		switch((unsigned int) rguid) {
			case DI8DEVTYPE_MOUSE:
				_Context->isMouse = True;
				break;
			case DI8DEVTYPE_KEYBOARD:
				_Context->isMouse = False;
				break;
			default:
				NuWarn("Unsupported non-GUID to IDirectInput8::CreateDevice: %p", rguid);
				
				goto error;
		}
	}
	
	_Context->mutex = SDL_CreateMutex();
	
	_Context->sequence = 0;
	
	return S_OK;
	
error:
	NuWarn("Error occured, but no cleanup is done");

	return -1;
}

WINAPI HRESULT IDirectInputDevice8_Release(
    void *this_
) {
	return S_OK;
}

WINAPI HRESULT IDirectInputEffect_Release(
    void *this_
) {
	return S_OK;
}
