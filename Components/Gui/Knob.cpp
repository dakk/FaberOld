/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#include "Knob.h"

#include <TranslationUtils.h>
#include <Picture.h>
#include <View.h>
#include <Window.h>
#include <Rect.h>
#include <Bitmap.h>
#include <GraphicsDefs.h>
#include <Resources.h>
#include <GroupLayout.h>

#include "Globals.h"



Knob::Knob(		BRect frame, 
				const char* name, 
				const char* label,
				BMessage* message, 
				uint32 resizingMode = B_FOLLOW_LEFT | B_FOLLOW_TOP,
				uint32 flags = B_WILL_DRAW | B_NAVIGABLE);
			:
			BView(frame, name, resizingMode, flags)
{
}

Knob::~Knob()
{
}


void Knob::Draw(BRect updateRect)
{
	StrokeEllipse(updateRect, B_SOLID_HIGH);
}
