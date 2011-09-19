/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#include "CommandTrackPan.h"
#include "Track.h"
#include "TrackRepository.h"


CommandTrackPan::~CommandTrackPan()
{
}

CommandTrackPan::CommandTrackPan() 
				: 
				Command("set track pan alignment")
{
}

void CommandTrackPan::Execute()
{
}


void* CommandTrackPan::Execute(void* p1, void* p2, void* p3)
{
	int32 id = (int32) p1;
	int32 pan = (int32) p2;
	
	fTrack = (Track*) TrackRepository::Instance()->TrackList()->ItemAt(id);
	
	if(fTrack == NULL)
		return (void*) false;
	
	
	fOldPan = fTrack->Pan();
	fTrack->SetPan(pan);
		
    return (void*) true;
}


Command* CommandTrackPan::Clone()
{
	return new CommandTrackPan();	
}


void CommandTrackPan::Undo()
{
	if(fTrack != NULL)
		fTrack->SetPan(fOldPan);
}


void CommandTrackPan::Redo()
{
}

bool CommandTrackPan::IsUndoable()
{
    return true;
}
