/*
 * Copyright 2006 Falling Leaf Systems, LLC.
 * Refer to LICENSE in the root directory.
*/

#ifndef __NUCLEUS_NUCLEUS_H__
#define __NUCLEUS_NUCLEUS_H__

/* Retain the order of these includes! */
#include <Nucleus/Internal/Internal.h>
#include <Nucleus/Logging/Logging.h>

/* Alphabetical works well here */
#include <Nucleus/Context/Context.h>
#include <Nucleus/Core/Core.h>
#include <Nucleus/Event/Event.h>
#include <Nucleus/File/File.h>
#include <Nucleus/GUI/GUI.h>
#include <Nucleus/Memory/Memory.h>
#include <Nucleus/Process/Process.h>
#include <Nucleus/Render/Render.h>
#include <Nucleus/Thread/Thread.h>

#if defined(main) && main == SDL_Main
#undef main
#endif

#endif
