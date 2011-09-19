/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#include "TrackAudioMono.h"


TrackAudioMono::TrackAudioMono(BRect frame, const char* name, uint32 resizingMode, uint32 flags)
		:
		Track(BRect(frame.left, 0, frame.right, 100), name, resizingMode, flags)
{
	//ResizeTo(frame.right - frame.left, 100);
	SetName("Audio");
}

TrackAudioMono::~TrackAudioMono()
{
}



void TrackAudioMono::Draw(BRect updateRect)
{
	MovePenTo(BPoint(10, 10));
	DrawString("TrackAudioMono");	
	StrokeLine(BPoint(updateRect.left, updateRect.bottom), BPoint(updateRect.right, updateRect.bottom));
}

