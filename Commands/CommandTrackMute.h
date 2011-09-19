/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#ifndef __COMMAND_TRACK_MUTE_H
#define __COMMAND_TRACK_MUTE_H

#include "Globals.h"
#include "Command.h"
#include "Track.h"

class CommandTrackMute : public Command
{
public:
    	                CommandTrackMute();
	
	virtual 			~CommandTrackMute();
	virtual Command*	Clone();
	virtual void 		Execute();
	virtual void* 		Execute(void* p1, void* p2, void* p3);
	virtual bool    	IsUndoable();
	virtual void    	Undo();
	virtual void		Redo();
	
private:
			Track*		fTrack;
			bool		fState;
};

#endif
