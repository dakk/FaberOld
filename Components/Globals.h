/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdio.h>
#include <SupportDefs.h>

#define MIDI
#define AUDIO
#define AUDIO_SURROUND
#define VIDEO
#define SUBTITLE


const int32 WINDOW_DEFAULT_SIZE_X			= 600;
const int32 WINDOW_DEFAULT_SIZE_Y			= 400;

const int32 MAX_UNDABLE_COMMANDS			= 20;
const int32 MAX_COMMANDS					= 200;

const int32	COMMAND_MASTER_VOLUME			= 0x0F;
const int32 COMMAND_TRACK_ADD				= 0x10;
const int32	COMMAND_TRACK_MUTE				= 0x11;
const int32	COMMAND_TRACK_SOLO				= 0x12;
const int32	COMMAND_TRACK_VOLUME			= 0x13;
const int32 COMMAND_TRACK_PAN				= 0x14;

#endif
