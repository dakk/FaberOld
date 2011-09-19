/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#include "CommandRepository.h"
#include "MainView.h"

CommandRepository* CommandRepository::fInstance = NULL;


CommandRepository::CommandRepository()
{
	int i;

	for(i = 0; i < MAX_COMMANDS; i++)
	{
		fCommands[i] = NULL;
	}

	fUndoStack = new BList(20);
}

CommandRepository::~CommandRepository()
{
    int i;

	for(i = 0; i < MAX_COMMANDS; i++)
	{
		if(fCommands[i] != NULL)
			delete fCommands[i];
	}
	
	for(i = 0; i < fUndoStack->CountItems(); i++)
	{
		Command* cmd = (Command*) fUndoStack->ItemAt(i);
		fUndoStack->RemoveItem(cmd);
		delete cmd;
	}
}




bool CommandRepository::AddCommand(Command* command, int32 id)
{
	if(id >= MAX_COMMANDS)
		return false;
	if(fCommands[id] != NULL)
		return false;

	fCommands[id] = command;
	return true;
}


bool CommandRepository::CommandExists(int32 id)
{
	if(fCommands[id] != NULL)
		return true;
	return false;
}

bool CommandRepository::ExecuteCommand(int32 id)
{
	if(fCommands[id] == NULL)
		return false;


	printf("CommandRepository::ExecuteCommand(%x)\n", id);
	
	fCommands[id]->Execute();
	AddUsedCommand(fCommands[id]->Clone());
	return true;
}


void* CommandRepository::ExecuteCommand(int32 id, void* p1, void* p2, void* p3)
{
	if(fCommands[id] == NULL)
		return NULL;
		
	printf("CommandRepository::ExecuteCommand(%x, %x, %x, %x)\n", id, p1, p2, p3);
	
	/* Copy the used command object and add it on the undo stack */
	Command *cmd = fCommands[id];
	void *result;
	
	if(cmd->IsUndoable())
	{
		Command *clone = cmd->Clone();
		result = clone->Execute(p1, p2, p3);
		AddUsedCommand(clone);
	}
	else
		result = cmd->Execute(p1, p2, p3);	
		
	return result;
}



BList* CommandRepository::UndoStack()
{
	return fUndoStack;	
}


void CommandRepository::AddUsedCommand(Command *clone)
{
	// Check if there's many commands in fUsedCommands
	if(fUndoStack->CountItems() > MAX_UNDABLE_COMMANDS)
	{
		Command* data = (Command*) fUndoStack->RemoveItem((int32) 0);
		delete data;
	}
		
	// Add to the command list
	fUndoStack->AddItem((void *) clone);
	
	MainView::Instance()->UpdateUndoRedo();
}


void CommandRepository::Undo()
{
	if(fUndoStack->CountItems() != 0)
	{
		Command *cmd = (Command*) fUndoStack->RemoveItem(fUndoStack->CountItems()-1);
		cmd->Undo();
		
		delete cmd;
	}
}


void CommandRepository::Redo()
{
	
}


CommandRepository* CommandRepository::Instance()
{
	if(fInstance != NULL)
		return fInstance;

	fInstance = new CommandRepository();
	return fInstance;
}
