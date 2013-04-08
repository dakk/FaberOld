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
#include <math.h>

#include "Globals.h"



Knob::Knob(BRect frame, const char* name, const char* label,
	BMessage* message, uint32 minValue, uint32 maxValue,
	uint32 resizingMode,
	uint32 flags)
	:
	BView(frame, name, resizingMode, flags),
	resizingMode(B_FOLLOW_LEFT | B_FOLLOW_TOP),
	flags(B_WILL_DRAW | B_NAVIGABLE)
	
{
	SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
	
	fMinValue = minValue;
	fMaxValue = maxValue;
	fValue = 0;
}

Knob::~Knob()
{
}


void Knob::Draw(BRect updateRect)
{
	int d = 26;
	ResizeTo(d+2,d+2);
	
	// Ellipses
	StrokeEllipse(BRect(1, 1, 1+d, 1+d), B_SOLID_HIGH);
	
	SetHighColor(150, 150, 150, 255);
	FillEllipse(BRect(1, 1, d+1, d+1), B_SOLID_HIGH);

	SetHighColor(100, 100, 100, 255);
	FillEllipse(BRect(4, 4, d - 2, d - 2), B_SOLID_HIGH);
	
	// Limits
	StrokeLine(BPoint(d/2 + 1, d/2 + 1), BPoint(d/2 - d/4 - 1, d/2 + d/4 + 1), B_SOLID_HIGH);
	StrokeLine(BPoint(d/2 + 1, d/2 + 1), BPoint(d/2 + d/4 + 1, d/2 + d/4 + 1), B_SOLID_HIGH);

	// Value indicator
	BPoint start;
	BPoint end;
	double rad;
	uint32 diff = fMaxValue - fMinValue;
	
	// Transform from fValue to radiant
	rad = (5/3 * 3.14) - fValue * (7/3 * 3.14) / diff; //5/3 * 3.14 - (fValue - fMinValue) * 5 / 3 * 3.14 / diff;

/*	
	4/3 * 3.14 = fMinValue;
	10/3 * 3.14 = fMaxValue;
	
	10 / 3 - 4 / 3 * 3.14 = 7 / * 3.14
*/	
	
	// Determinate indicator position
	start = BPoint(d/2 + 1, d/2 + 1);
	end = BPoint((d/2 + 1) + d/2 * cos(rad), (d/2 + 1) + d/2 * sin(rad));
	SetPenSize(2.0f);

	SetHighColor(200, 10, 10, 255);	
	StrokeLine(start, end, B_SOLID_HIGH);
	SetHighColor(0, 0, 0, 255);
	
	fValue = (fValue + 1) % fMaxValue;
}



/*
void Knob::MouseMoved(BPoint point, uint32 transit, const BMessage* message)
{
		
}
*/

void Knob::MouseDown(BPoint where)
{
	
	
}



uint32 Knob::Value()
{
	return fValue;
}


void Knob::SetValue(uint32 value)
{
	fValue = value;
	
	if(fValue < fMinValue)
		fValue = fMinValue;
	else if(fValue > fMaxValue)
		fValue = fMaxValue;
}


