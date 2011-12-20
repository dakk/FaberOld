/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#include <stdio.h>
#include "ApplicationInit.h"


ApplicationInit::ApplicationInit()
{
	printf("Creating singletons...\n");
    CommandRepository::Instance();
    TrackRepository::Instance();
    ProjectManager::Instance();
    Debug::Instance();
}

ApplicationInit::~ApplicationInit()
{
	printf("Destroying singletons...\n");
	//delete CommandRepository::Instance();
	//delete ProjectManager::Instance();
	//delete TrackRepository::Instance();
	//delete Debug::Instance();
	printf("Quit.\n");
}


void ApplicationInit::SetUpSystem(const char* commandLine)
{
    printf("Faber Media Editor\nStartup sequence.\n");

    /* Show a splash screen during loading */


    /* Create main window */
    printf("Creating main window...\n");
    fMainWindow = new MainWindow(BRect(0, 0, WINDOW_DEFAULT_SIZE_X, WINDOW_DEFAULT_SIZE_Y));


	printf("Faber is loaded.\n");
	fMainWindow->Show();
}
