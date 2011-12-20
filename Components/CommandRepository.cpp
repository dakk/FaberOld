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
	fUndoStack = new BList(20);
	fRedoStack = new BList(20);
}

CommandRepository::~CommandRepository()
{
}




BList* CommandRepository::UndoStack()
{
	return fUndoStack;	
}




void CommandRepository::Redo()
{
	
}


void CommandRepository::Undo()
{
	
}




CommandRepository* CommandRepository::Instance()
{
	if(fInstance != NULL)
		return fInstance;

	fInstance = new CommandRepository();
	return fInstance;
}
