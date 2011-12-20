/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#include <Application.h>
#include <GroupLayout.h>
#include "MainWindow.h"


MainWindow::MainWindow(BRect frame)
		:
		BWindow(frame, "Faber Media Editor", B_TITLED_WINDOW, B_NOT_ZOOMABLE)
{
	SetLayout(new BGroupLayout(B_VERTICAL));
	fMainView = new MainView();
	GetLayout()->AddView(fMainView);
	
	fMainView->PostMessage(new BMessage(MSG_NEW));
}



void MainWindow::MessageReceived(BMessage* message)
{
	switch (message->what)
	{
		default:
			BWindow::MessageReceived(message);
	}

}



bool MainWindow::QuitRequested()
{
	fMainView->RemoveSelf();
	delete fMainView;

	be_app->PostMessage(B_QUIT_REQUESTED);
	return true;
}

