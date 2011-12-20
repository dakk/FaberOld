/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#ifndef __COMMAND_REPOSITORY_H
#define __COMMAND_REPOSITORY_H

#include <List.h>
#include "Track.h"
#include "Globals.h"

class CommandRepository
{
public:
								~CommandRepository();

	static 	CommandRepository*  Instance();
			BList*				UndoStack();
			void				Undo();
			void				Redo();


	// Commands
			void				SetMasterVolume(int32 vol);
			
			void				AddTrack(TrackType type);
			void				SetTrackMute(int32 track, bool state);
			void				SetTrackPan(int32 track, int32 pan);
			void				SetTrackSolo(int32 track, bool state);
			void				SetTrackVolume(int32 track, int32 vol);

protected:
								CommandRepository();

private:
    static 	CommandRepository*	fInstance;
		    BList*				fUndoStack;
		    BList*				fRedoStack;
};

#endif
