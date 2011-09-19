/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#include "CommandTrackSolo.h"
#include "Track.h"
#include "TrackRepository.h"


CommandTrackSolo::~CommandTrackSolo()
{
}

CommandTrackSolo::CommandTrackSolo() 
				: 
				Command("solo track")
{
}

void CommandTrackSolo::Execute()
{
}

void* CommandTrackSolo::Execute(void* p1, void* p2, void* p3)
{
	int32 id = (int32) p1;
	fState = (bool) p2;
	
	fTrack = (Track*) TrackRepository::Instance()->TrackList()->ItemAt(id);
	
	if(fTrack == NULL)
		return (void*) false;
	
	fTrack->SetSolo(fState);
		
    return (void*) true;
}


Command* CommandTrackSolo::Clone()
{
	return new CommandTrackSolo();	
}


void CommandTrackSolo::Undo()
{
	if(fTrack != NULL)
		fTrack->SetSolo(!fState);
}


void CommandTrackSolo::Redo()
{
}

bool CommandTrackSolo::IsUndoable()
{
    return true;
}
