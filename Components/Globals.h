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


const int32	FABER_MSG_MASTER_VOLUME			= "FUnd";
const int32 FABER_MSG_TRACK_ADD				= "FAdd";
const int32	FABER_MSG_TRACK_MUTE			= "FMut";
const int32	FABER_MSG_TRACK_SOLO			= "FSol";
const int32	FABER_MSG_TRACK_VOLUME			= "FVol";
const int32 FABER_MSG_TRACK_PAN				= "FPan";

#endif
