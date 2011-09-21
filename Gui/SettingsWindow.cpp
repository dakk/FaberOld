/*
 * Copyright (c) Casalinuovo Dario. All rights reserved.
 * Copyright (c) Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#include <Application.h>
#include <GroupLayout.h>
#include <Window.h>
#include <View.h>
#include "SettingsWindow.h"
#include "SettingsView.h"



SettingsWindow::SettingsWindow() 
		:
		BWindow(BRect(150, 150, 540, 320), "Faber Settings", B_TITLED_WINDOW,
					B_NOT_ZOOMABLE)
{	
	SetLayout(new BGroupLayout(B_VERTICAL));

	fSettingsView = new SettingsView();
	GetLayout()->AddView(fSettingsView);
}


void SettingsWindow::MessageReceived(BMessage* message)
{
	switch (message->what)
	{
		default:
			BWindow::MessageReceived(message);
	}

}



bool SettingsWindow::QuitRequested()
{
	//delete fSettingsView;
	return true;
}

