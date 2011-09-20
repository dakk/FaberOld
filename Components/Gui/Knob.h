/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#ifndef __KNOB_H
#define __KNOB_H

#include <View.h>

class Knob : public BView
{
public:
                    Knob(	BRect frame, 
							const char* name,
							const char* label,
							BMessage* message, 
							uint32 resizingMode = B_FOLLOW_LEFT | B_FOLLOW_TOP,
							uint32 flags = B_WILL_DRAW | B_NAVIGABLE);
						
                    ~Knob();
	virtual	void 	Draw(BRect updateRect);
};

#endif
