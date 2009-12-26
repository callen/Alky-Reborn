/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <Nucleus/Nucleus.h>
#include <Nucleus/Event/Event.h>

#define NUMODULE_NAME "NuEvent"

inline NuEvent_Timer *NuEvent_CreateTimer(int duration) {
	NuEvent_Timer *timer = NuMemory_Alloc(sizeof(NuEvent_Timer));
	
	memset(timer, 0, sizeof(NuEvent_Timer));
	
	if(timer == None)
		return None;
	
	NuEvent_TimerSetDuration(timer, duration);
	
	return timer;
}

inline bool NuEvent_TimerSetDuration(NuEvent_Timer *timer, int duration) {
	NuAssert(timer != None);
	
	timer->duration = duration;
	
	if(duration != 0)
		timer->start = time(None);
}

inline bool NuEvent_TimerStatus(NuEvent_Timer *timer) {
	NuAssert(timer != None);
	
	if(time(None) > timer->start + timer->duration)
		return True;
	return False;
}
