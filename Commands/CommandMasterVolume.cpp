/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#include "CommandMasterVolume.h"
#include "Track.h"
#include "TrackRepository.h"


CommandMasterVolume::~CommandMasterVolume()
{
}

CommandMasterVolume::CommandMasterVolume() 
				: 
				Command("set master volume")
{
}

void CommandMasterVolume::Execute()
{
}

void* CommandMasterVolume::Execute(void* p1, void* p2, void* p3)
{
	int32 vol = (int32) p1;
	
	
	fOldVolume = TrackRepository::Instance()->MasterVolume();
	TrackRepository::Instance()->SetMasterVolume(vol);
		
    return (void*) true;
}


Command* CommandMasterVolume::Clone()
{
	return new CommandMasterVolume();	
}


void CommandMasterVolume::Undo()
{
	TrackRepository::Instance()->SetMasterVolume(fOldVolume);
}


void CommandMasterVolume::Redo()
{
}

bool CommandMasterVolume::IsUndoable()
{
    return true;
}
