/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#ifndef __APPLICATION_INIT_H
#define __APPLICATION_INIT_H

#include "Globals.h"
#include "CommandRepository.h"
#include "ProjectManager.h"
#include "Debug.h"

#include "MainWindow.h"


class ApplicationInit
{
public:
					ApplicationInit();
					~ApplicationInit();
	void			SetUpSystem(const char* commandLine);

private:
	MainWindow*		fMainWindow;
};

#endif
