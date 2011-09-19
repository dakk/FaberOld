/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#include <stdio.h>
#include "ApplicationInit.h"
#include "CommandTrackAdd.h"
#include "CommandTrackMute.h"
#include "CommandTrackSolo.h"
#include "CommandTrackVolume.h"
#include "CommandTrackPan.h"
#include "CommandMasterVolume.h"



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

    /* Add all commands */
    printf("Adding commands...\n");
	CommandRepository::Instance()->AddCommand(new CommandTrackAdd(), COMMAND_TRACK_ADD);
	CommandRepository::Instance()->AddCommand(new CommandTrackMute(), COMMAND_TRACK_MUTE);
	CommandRepository::Instance()->AddCommand(new CommandTrackSolo(), COMMAND_TRACK_SOLO);
	CommandRepository::Instance()->AddCommand(new CommandTrackVolume(), COMMAND_TRACK_VOLUME);
	CommandRepository::Instance()->AddCommand(new CommandMasterVolume(), COMMAND_MASTER_VOLUME);
	CommandRepository::Instance()->AddCommand(new CommandTrackPan(), COMMAND_TRACK_PAN);

	printf("Faber is loaded.\n");
	fMainWindow->Show();
}
