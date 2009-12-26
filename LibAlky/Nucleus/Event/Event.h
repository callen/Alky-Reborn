/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __NUCLEUS_EVENT_EVENT_H__
#define __NUCLEUS_EVENT_EVENT_H__

#include <Nucleus/Nucleus.h>

struct NuEvent_Object_s {
	char *name;
	bool  isSignaled;
} typedef NuEvent_Object;

struct NuEvent_Timer_s {
	int start;
	int duration;
} typedef NuEvent_Timer;

inline NuEvent_Object *NuEvent_Create(char *name);
inline bool            NuEvent_Signal(NuEvent_Object *event);
inline bool            NuEvent_Reset(NuEvent_Object *event);
inline bool            NuEvent_Status(NuEvent_Object *event);

inline NuEvent_Timer  *NuEvent_CreateTimer(int duration);
inline bool            NuEvent_TimerSetDuration(NuEvent_Timer *timer, int duration);
inline bool            NuEvent_TimerStatus(NuEvent_Timer *timer);

#endif
