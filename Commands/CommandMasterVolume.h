/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#ifndef __COMMAND_MASTER_VOLUME_H
#define __COMMAND_MASTER_VOLUME_H

#include "Globals.h"
#include "Command.h"
#include "Track.h"

class CommandMasterVolume : public Command
{
public:
    	                CommandMasterVolume();
	
	virtual 			~CommandMasterVolume();
	virtual Command*	Clone();
	virtual void 		Execute();
	virtual void* 		Execute(void* p1, void* p2, void* p3);
	virtual bool    	IsUndoable();
	virtual void    	Undo();
	virtual void		Redo();
	
private:
			int32		fOldVolume;
};

#endif
