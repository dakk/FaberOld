/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#ifndef __COMMAND_H
#define __COMMAND_H

#include <List.h>
#include "Globals.h"


class Command
{
public:
						Command(const char *name);
	virtual 			~Command();
	virtual Command*	Clone() = 0;
	virtual void 		Execute() = 0;
	virtual void* 		Execute(void* p1, void* p2, void* p3) = 0;
	virtual void    	Undo() = 0;
	virtual void		Redo() = 0;
	virtual bool    	IsUndoable() = 0;

			char*		Name();
protected:
			char		fName[128];
};

#endif
