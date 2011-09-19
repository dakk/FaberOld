/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#include "CommandTrackVolume.h"
#include "Track.h"
#include "TrackRepository.h"


CommandTrackVolume::~CommandTrackVolume()
{
}

CommandTrackVolume::CommandTrackVolume() 
				: 
				Command("set track volume")
{
}

void CommandTrackVolume::Execute()
{
}


void* CommandTrackVolume::Execute(void* p1, void* p2, void* p3)
{
	int32 id = (int32) p1;
	int32 vol = (int32) p2;
	
	fTrack = (Track*) TrackRepository::Instance()->TrackList()->ItemAt(id);
	
	if(fTrack == NULL)
		return (void*) false;
	
	
	fOldVolume = fTrack->Volume();
	fTrack->SetVolume(vol);
		
    return (void*) true;
}


Command* CommandTrackVolume::Clone()
{
	return new CommandTrackVolume();	
}


void CommandTrackVolume::Undo()
{
	if(fTrack != NULL)
		fTrack->SetVolume(fOldVolume);
}


void CommandTrackVolume::Redo()
{
}

bool CommandTrackVolume::IsUndoable()
{
    return true;
}
