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

const int32	FABER_MSG_MASTER_VOLUME			= 'FMVo';
const int32 FABER_MSG_TRACK_ADD				= 'FTAd';
const int32	FABER_MSG_TRACK_MUTE			= 'FTMu';
const int32	FABER_MSG_TRACK_SOLO			= 'FTSo';
const int32	FABER_MSG_TRACK_VOLUME			= 'FTVo';
const int32 FABER_MSG_TRACK_PAN				= 'FTPa';

#endif
