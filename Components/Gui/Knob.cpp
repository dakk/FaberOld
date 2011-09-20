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
				uint32 flags = B_WILL_DRAW | B_NAVIGABLE)
			:
			BView(frame, name, resizingMode, flags)
{
	SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
	
}

Knob::~Knob()
{
}


void Knob::Draw(BRect updateRect)
{
	ResizeTo(26,26);
	
	StrokeEllipse(BRect(1, 1, 26, 26), B_SOLID_HIGH);
	
	SetHighColor(150, 150, 150, 255);
	FillEllipse(BRect(2, 2, 25, 25), B_SOLID_HIGH);

	SetHighColor(100, 100, 100, 255);
	FillEllipse(BRect(4, 4, 23, 23), B_SOLID_HIGH);
	
	SetPenSize(2.0f);

	SetHighColor(200, 10, 10, 255);	
	StrokeLine(BPoint(14, 14), BPoint(14, 0), B_SOLID_HIGH);
	SetHighColor(0, 0, 0, 255);
}

