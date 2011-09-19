/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#include <stdio.h>
#include "Debug.h"

Debug* Debug::fInstance = NULL;



Debug* Debug::Instance()
{
	if(fInstance != NULL)
		return fInstance;

	fInstance = new Debug();
	return fInstance;
}



void Debug::Write(const char *str)
{
	printf("%s\n", str);
}


Debug::Debug()
{
}

Debug::~Debug()
{
}
