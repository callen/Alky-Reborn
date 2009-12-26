/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#include <Nucleus/Nucleus.h>
#include <APIs/Windows/Core/Core.h>

#define NUMODULE_NAME "WinCore"

#include <string.h>

static void *tib[0xE];

#ifdef MAC
__asm__ (
	".globl _WinCore_HotPatch1\n"
	"_WinCore_HotPatch1:\n"
	"	jmp *0xDEADBEEF\n"
	".globl _WinCore_HotPatch2\n"
	"_WinCore_HotPatch2:\n"
	"	nop\n"
);
#else
__asm__ (
	".globl WinCore_HotPatch1\n"
	"WinCore_HotPatch1:\n"
	"	jmp *0xDEADBEEF\n"
	".globl WinCore_HotPatch2\n"
	"WinCore_HotPatch2:\n"
	"	nop\n"
);
#endif

void WinCore_HotPatch1();
void WinCore_HotPatch2();

static char log_buffer[1024];

int game_log(char *format) {
	snprintf(log_buffer, 1023, "Log (Game): %s", format);
	return fprintf(stdout, log_buffer);
}

void hotpatch(void *orig_addr, unsigned int orig_data, void *new_func) {
	void **patch;
	
	if(*((unsigned int *) orig_addr) == orig_data) {
		memcpy(
			(unsigned int *) orig_addr,
			WinCore_HotPatch1,
			(unsigned int) ((unsigned char *) WinCore_HotPatch2 - (unsigned char *) WinCore_HotPatch1)
		);
		
		patch = NuMemory_Alloc(sizeof(void *));
		*patch = new_func;
		
		*((void **) ((unsigned char *) orig_addr + 2)) = patch;
	}
}

bool WinCore_Setup() {
	NuLog("Setup");
	
	WinCore_SetupFS();

	NuGUI_Setup();
	NuThread_Setup();
	
	// NuMemory_TLSSet(NuMemory_TLSAlloc(), 0);
	
	// Re-enable Oblivion logging
	// hotpatch(0x00463110, 0xCCCCCCC3, game_log);
	
	// Patch Oblivion's memset to use OS X's native version
	// hotpatch(0x00966E40, 0x0C24548B, memset);
	
	// Patch Prey's atexit to use the system
	hotpatch(0x1028fb47, 0x042474ff, atexit);
	
	// Patch Prey's log methods to use game_log
	// hotpatch(0x004d3880, 0x7AD6ACA1, game_log);
	
	return True;
}

bool WinCore_Teardown() {
	NuLog("Teardown");
}

#ifdef MAC

#include <sys/param.h>
#include <i386/user_ldt.h>
#include <architecture/i386/table.h>
#include <architecture/i386/sel.h>
#include <i386/user_ldt.h>

sel_t create_ldt_entry_with_data(const void *base, size_t size)
{
  uintptr_t addr = (uintptr_t)base;
  ldt_entry_t new_desc;
  sel_t new_sel;
  int sel_idx;

  new_desc.data.limit00 = (size - 1) & 0xFFFF;
  new_desc.data.limit16 = ((size - 1) >> 16) & 0xF;
  new_desc.data.base00 = addr & 0xFFFF;
  new_desc.data.base16 = (addr >> 16) & 0xFF;
  new_desc.data.base24 = (addr >> 24) & 0xFF;
  new_desc.data.type = DESC_DATA_WRITE;
  new_desc.data.dpl = USER_PRIV;
  new_desc.data.present = 1;
  new_desc.data.stksz = DESC_CODE_32B;
  new_desc.data.granular = DESC_GRAN_BYTE;


  sel_idx = i386_set_ldt(LDT_AUTO_ALLOC, &new_desc, 1);
  if (sel_idx < 0)
    {
      perror("i386_set_ldt");
      return NULL_SEL;
    }


  new_sel.index = sel_idx;
  new_sel.rpl = USER_PRIV;
  new_sel.ti = SEL_LDT;


  return new_sel;
}

bool WinCore_SetupFS() {
	sel_t _fs;
	void *_esp;
	
	NuLog("Initializing TIB and LDT entry");
	
	memset(tib, 0, 0x38);
	
	__asm ("mov %%esp, %%eax" : "=a" (_esp));
	tib[1] = _esp;
	
	_fs = create_ldt_entry_with_data(tib, 0x38);
	
	NuLog("Setting %%fs");
	
	__asm ("mov %%ax, %%fs\n" : : "a" (_fs));
	
	return True;
}
#else

#include <syscall.h>
#include <errno.h>
#include <asm/unistd.h>
#include <asm/ldt.h>

#define LDT_SEL(idx) ((idx) << 3 | 1 << 2 | 3)

#ifndef TEB_SEL_IDX
#define TEB_SEL_IDX	1
#endif
#define TEB_SEL LDT_SEL(TEB_SEL_IDX)

int create_ldt_entry_with_data(const void *base, size_t size)
{
	struct user_desc new_desc;
	
	new_desc.base_addr = base;
	new_desc.limit = size - 1;
	new_desc.entry_number = TEB_SEL_IDX;
	new_desc.seg_32bit = 1;
	new_desc.read_exec_only = 0;
	new_desc.seg_not_present = 0;
	new_desc.contents = MODIFY_LDT_CONTENTS_DATA;
	new_desc.limit_in_pages = 0;
	new_desc.useable = 1;
	
	if(modify_ldt(0x1, &new_desc, sizeof(struct user_desc)))
		return False;
	
	return TEB_SEL;
}

bool WinCore_SetupFS() {
	int _fs;
	void *_esp;
	
	NuLog("Initializing TIB and LDT entry");
	
	memset(tib, 0, 0x38);
	
	_fs = create_ldt_entry_with_data(tib, 0x38);
	
	__asm ("mov %%esp, %%eax" : "=a" (_esp));
	tib[1] = _esp;
	
	NuLog("Setting %%fs");
	
	__asm ("mov %%ax, %%fs\n" : : "a" (_fs));
	
	return True;
}

bool WinCore_ReplaceStackAndRun(void *entry, void *param, bool use_param) {
	void *stack;
	unsigned int stack_size;

	stack_size = 64 * 1024 * 1024;
	stack = (unsigned int) malloc(stack_size);
	stack += stack_size - (1 * 1024 * 1024);
	
	if(use_param)
		__asm(
			"mov %%eax, %%esp\n"
			"mov %%eax, %%ebp\n"
			"push %%edx\n"
			"call *%%ecx\n"
			: : "a" (stack), "d" (param), "c" (entry)
		);
	else
		__asm(
			"mov %%eax, %%esp\n"
			"mov %%eax, %%ebp\n"
			"call *%%ecx\n"
			: : "a" (stack), "c" (entry)
		);
	
	return True;
}
#endif

