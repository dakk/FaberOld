/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#include "CommandTrackMute.h"
#include "Track.h"
#include "TrackRepository.h"


CommandTrackMute::~CommandTrackMute()
{
}

CommandTrackMute::CommandTrackMute() 
				: 
				Command("mute track")
{
}

void CommandTrackMute::Execute()
{
}

void* CommandTrackMute::Execute(void* p1, void* p2, void* p3)
{
	int32 id = (int32) p1;
	fState = (bool) p2;
	
	fTrack = (Track*) TrackRepository::Instance()->TrackList()->ItemAt(id);
	
	if(fTrack == NULL)
		return (void*) false;
	
	fTrack->SetMute(fState);
		
    return (void*) true;
}


Command* CommandTrackMute::Clone()
{
	return new CommandTrackMute();	
}


void CommandTrackMute::Undo()
{
	if(fTrack != NULL)
		fTrack->SetMute(!fState);
}


void CommandTrackMute::Redo()
{
}

bool CommandTrackMute::IsUndoable()
{
    return true;
}
