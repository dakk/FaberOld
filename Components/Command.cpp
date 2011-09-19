/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#include <string.h>
#include "Command.h"


Command::Command(const char *name)
{
	strcpy(fName, name);
}

Command::~Command()
{
}


char* Command::Name()
{
	return fName;
}
