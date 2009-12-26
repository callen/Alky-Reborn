/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <Nucleus/Nucleus.h>
#include <Nucleus/GUI/GUI.h>

#define NUMODULE_NAME "NuGUI"

void NuGUI_PumpEvents() {
	SDL_Event event, *copy;
	NuGUI_EventLink *link;
	
	NuGUI *_Context = NuGUI_GetContext();
	
	while(1) {
		if(SDL_PollEvent(&event) == 0)
			break;
		
		switch(event.type) {
			case SDL_MOUSEMOTION:
			case SDL_MOUSEBUTTONDOWN:
			case SDL_MOUSEBUTTONUP:
			case SDL_KEYDOWN:
			case SDL_KEYUP:
				break;
			case SDL_QUIT:
				NuError("Dying");
			default:
				continue;
		}
		
		if(event.type == SDL_KEYDOWN) {
			_Context->keyboard[event.key.keysym.sym] = True;
		} else if(event.type == SDL_KEYUP) {
			_Context->keyboard[event.key.keysym.sym] = False;
		}
		
		copy = NuMemory_Alloc(sizeof(SDL_Event));
		memcpy(copy, &event, sizeof(SDL_Event));
		
		NuGUI_HandleEvent((NuGUI_Event *) copy);
		
		link = NuMemory_Alloc(sizeof(NuGUI_EventLink));
		link->event = copy;
		link->prev = None;
		link->next = None;
		
		SDL_LockMutex(_Context->eventMutex);
		if(_Context->events == None)
			_Context->events = link;
		
		if(_Context->lastEvent != None) {
			link->prev = _Context->lastEvent;
			_Context->lastEvent->next = link;
		}
		
		_Context->lastEvent = link;
		
		SDL_UnlockMutex(_Context->eventMutex);
	}
}

int NuGUI_GetEventCount(int type) {
	int count = 0;
	NuGUI *_Context = NuGUI_GetContext();
	NuGUI_EventLink *link;
	
	NuGUI_PumpEvents();
	
	SDL_LockMutex(_Context->eventMutex);
	link = _Context->events;
	
	while(link != None) {
		if(link->event->type == type)
			count++;
		link = link->next;
	}
	
	SDL_UnlockMutex(_Context->eventMutex);
	
	return count;
}

NuGUI_Event *NuGUI_GetEvent(int type, bool pop) {
	NuGUI_EventLink *link;
	NuGUI_Event *event;
	
	NuGUI *_Context = NuGUI_GetContext();
	
	NuGUI_PumpEvents();
	
	SDL_LockMutex(_Context->eventMutex);
	link = _Context->events;
	
	while(link != None) {
		if(link->event->type != type) {
			link = link->next;
			continue;
		}
		
		event = link->event;
		
		if(pop) {
			if(link->prev != None)
				link->prev->next = link->next;
			else
				_Context->events = link->next;
			
			if(link->next != None)
				link->next->prev = link->prev;
			else
				_Context->lastEvent = link->prev;
			
			NuMemory_Free(link);
		}
		
		SDL_UnlockMutex(_Context->eventMutex);
		
		return event;
	}
	
	SDL_UnlockMutex(_Context->eventMutex);
	
	return None;
}

NuGUI_Event *NuGUI_EventsPresent(bool getEvent) {
	SDL_Event event;
	SDL_Event *copy;
	
	NuGUI *_Context = NuGUI_GetContext();

	SDL_LockMutex(_Context->eventMutex);

	SDL_PumpEvents();
    
	if(SDL_PollEvent(None) == 0) {
		SDL_UnlockMutex(_Context->eventMutex);
		return None;
	}
	
	if(getEvent == False) {
		SDL_UnlockMutex(_Context->eventMutex);
		return True;
	}
	
	if(SDL_PeepEvents(&event, 1, SDL_PEEKEVENT, 0xFFFFFFFF) != 1) {
		SDL_UnlockMutex(_Context->eventMutex);
		return None;
	}
	
	copy = NuMemory_Alloc(sizeof(SDL_Event));
	
	memcpy(copy, &event, sizeof(SDL_Event));
	
	SDL_UnlockMutex(_Context->eventMutex);
	return copy;
}

NuGUI_Event *NuGUI_PopEvent() {
	SDL_Event *event;
	
	NuGUI *_Context = NuGUI_GetContext();

	SDL_LockMutex(_Context->eventMutex);

	SDL_PumpEvents();
	
	if(SDL_PollEvent(None) == 0) {
		SDL_UnlockMutex(_Context->eventMutex);

		return None;
	}
	
	event = NuMemory_Alloc(sizeof(SDL_Event));
	
	SDL_PollEvent(event);
	
	SDL_UnlockMutex(_Context->eventMutex);

	return event;
}

NuGUI_Event *NuGUI_WaitEvent() {
	SDL_Event *event;
	
	NuGUI *_Context = NuGUI_GetContext();

	SDL_LockMutex(_Context->eventMutex);

	event = NuMemory_Alloc(sizeof(SDL_Event));
	
	SDL_WaitEvent(event);
	
	SDL_UnlockMutex(_Context->eventMutex);
	
	return event;
}

bool NuGUI_FreeEvent(NuGUI_Event *event) {
	NuMemory_Free(event);
	
	return True;
}

void NuGUI_HandleEvent(NuGUI_Event *event) {
	NuGUI *_Context = NuGUI_GetContext();

	NuGUI_EventCallChain *link;
	
	NuLog("NuGUI_HandleEvent");
	
	NuLog("Callchain == %p", _Context->callChain);

	link = _Context->callChain;
	
	while(link) {
		NuLog("Got Link? %p", link);
		link->callback(event, link->user_data);
		
		link = link->next;
	}
}

bool NuGUI_AddEventCallback(NuGUI_EventCallback callback, void *user_data) {
	NuGUI *_Context = NuGUI_GetContext();
	
	NuGUI_EventCallChain *link;
	
	link = NuMemory_Alloc(sizeof(NuGUI_EventCallChain) * 5);
	
	link->callback = callback;
	link->user_data = user_data;
	link->next = None;
	
	if(_Context->callChain == None)
		_Context->callChain = link;
	
	if(_Context->lastCall != None)
		_Context->lastCall->next = link;
	
	_Context->lastCall = link;
	
	NuLog("Callchain == %p", _Context->callChain);
	
	return True;
}

bool NuGUI_KeyState(int sdl_key) {
	NuGUI *_Context = NuGUI_GetContext();
	
	return _Context->keyboard[sdl_key];
}
