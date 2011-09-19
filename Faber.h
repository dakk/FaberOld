/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#ifndef __FABER_H
#define __FABER_H

#include <Application.h>
#include "Globals.h"


class Faber : public BApplication
{
public:
						Faber();
	virtual				~Faber();
	virtual void		MessageReceived(BMessage *msg);
};

#endif


