/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#ifndef __DEBUG_H
#define __DEBUG_H

#include "Globals.h"

class Debug
{
public:
					~Debug();
	void			Write(const char *str);
	
	static Debug*   Instance();
	
private:
					Debug();
	static Debug*   fInstance;
};

#endif
