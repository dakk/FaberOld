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
#include "Globals.h"
#include "Command.h"

class CommandRepository
{
public:
								~CommandRepository();

			bool				AddCommand(Command* command, int32 id);
			bool				CommandExists(int32 id);
			bool				ExecuteCommand(int32 id);
			void* 				ExecuteCommand(int32 id, void* p1, void* p2 = NULL, void* p3 = NULL);
	static 	CommandRepository*  Instance();
			BList*				UndoStack();
			void				Undo();
			void				Redo();

protected:
								CommandRepository();
			void				AddUsedCommand(Command* clone);

private:
    static 	CommandRepository*	fInstance;
		    BList*				fUndoStack;
		    BList*				fRedoStack;
			Command*			fCommands[MAX_COMMANDS];
};

#endif
