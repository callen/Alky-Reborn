/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __APIS_WINDOWS_COM_COM_H__
#define __APIS_WINDOWS_COM_COM_H__

#include <APIs/Windows/Windows.h>

#ifdef DEFINE_CLASSES
#define CLASS(name, struct_, vtable) \
typedef void *name; \
struct STRUCT_##name##_s { void *__padding__; struct_ } typedef STRUCT_##name; \
void *VTABLE_##name[] = { \
    vtable, \
    None \
}; \
int VTABLE_##name##_Length() { \
	return sizeof(VTABLE_##name); \
} \
struct EAT_SEMICOLON_##name { void *nada; }
#else
#define CLASS(name, struct_, vtable) \
typedef void *name; \
struct STRUCT_##name##_s { void *__padding__; struct_ } typedef STRUCT_##name; \
extern void **VTABLE_##name; \
int VTABLE_##name##_Length()
#endif

#define STRUCT(st...) st
#define VTABLE(vt...) vt
#define CMEMBER(name) (void *) name
#define CSTUB(name) (void *) ("\xef\xbe\xad\xde" #name)

#define INIT_CLASS(name, var) \
do { \
	(var) = NuMemory_Alloc(sizeof(void *)); \
	INIT_CLASS_PTR(name, var); \
} while(0)

#define INIT_CLASS_PTR(name, var) \
do { \
	int vtable_len = VTABLE_##name##_Length(); \
	void **obj = (void **) (var); \
	*obj = NuMemory_Alloc(sizeof(STRUCT_##name) + vtable_len); \
	memset(*obj, 0, sizeof(STRUCT_##name) + vtable_len); \
	*obj = ((unsigned char *) *obj) + sizeof(STRUCT_##name); \
	memcpy(*obj, &VTABLE_##name, vtable_len); \
} while(0)

#define CSTRUCT(name) STRUCT_##name
#define GET_CLASS_STRUCT(name, obj) \
(*((STRUCT_##name **) (obj)) - 1)

// (STRUCT_##name *) (*((unsigned char **) obj) - sizeof(STRUCT_##name))

#define VTABLE_SETUP_FUNC(name, setups...) \
void name##_VTable_Setup() { \
	static bool init = False; \
	\
	if(!init) { \
		setups \
		init = True; \
	} \
}

#define SETUP_VTABLE(name) \
name##_VTable_Setup()

#define VTABLE_SETUP_DECL(name) \
void name##_VTable_Setup();

#define VTABLE_SETUP(class) \
	{ \
		void ***ptr = VTABLE_##class; \
		while(*ptr != None) { \
			if(**ptr == (void *) 0xDEADBEEF) { \
				NuCore_AddImportAddr(ptr, strdup(&((*ptr)[1]))); \
				*ptr = NuCore_CreateUnsupportedWrapper(ptr); \
			} \
			++ptr; \
		} \
	}

WINAPI HRESULT IUnknown_QueryInterface(
    void *this_
);

#endif
