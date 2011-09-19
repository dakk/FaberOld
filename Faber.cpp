/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#include "Faber.h"

#include "Globals.h"
#include "ApplicationInit.h"


Faber::Faber() : BApplication("application/x-vnd.Faber")
{
}

Faber::~Faber()
{
}


void Faber::MessageReceived(BMessage* message)
{
	switch (message->what)
	{
		default:
			BApplication::MessageReceived(message);
	}

}


int main()
{
	Faber *fb = new Faber();
	try
	{
		ApplicationInit apInit;
		apInit.SetUpSystem(" ");

		fb->Run();
	}
	catch(...)
	{
	}
	delete fb;
}
