/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#ifndef __MAIN_WINDOW_H
#define __MAIN_WINDOW_H

#include <Window.h>
#include "MainView.h"
#include "Globals.h"


class MainWindow : public BWindow
{
public:
                	MainWindow(BRect frame);
	virtual void	MessageReceived(BMessage* mesage);
	virtual bool    QuitRequested();

private:
	MainView*		fMainView;

};

#endif
