/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#ifndef __TRACK_AUDIO_MONO_H
#define __TRACK_AUDIO_MONO_H

#include <View.h>
#include "Globals.h"
#include "Track.h"


class TrackAudioMono : public Track
{
public:
					TrackAudioMono(BRect frame = BRect(), const char* name = "TrackAudioMono", uint32 resizingMode = B_FOLLOW_ALL_SIDES, uint32 flags = B_WILL_DRAW);
	virtual 		~TrackAudioMono();
	virtual	void 	Draw(BRect updateRect);
};

#endif
