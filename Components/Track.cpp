/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#include "Track.h"

#include <string.h>

Track::Track(BRect frame, const char* name, uint32 resizingMode, uint32 flags)
		:
		BView(frame, name, resizingMode, flags)
{
	strcpy(fName, "Track");
	fVolume = 50;
	fMute = false;
	fSolo = false;
	fPan = 0;
}

Track::~Track()
{
}


void Track::SetPan(int32 pan)
{
	fPan = pan;	
}


int32 Track::Pan()
{
	return fPan;
}

bool Track::Mute()
{
	return fMute;
}


void Track::SetMute(bool mute)
{
	fMute = mute;	
}


bool Track::Solo()
{
	return fSolo;
}


void Track::SetSolo(bool solo)
{
	fSolo = solo;	
}

void Track::SetName(const char *name)
{
	strcpy(fName, name);	
}


const char* Track::Name()
{
	return fName;
}


int32 Track::Volume()
{
	return fVolume;	
}


void Track::SetVolume(int32 volume)
{
	fVolume = volume;	
}
