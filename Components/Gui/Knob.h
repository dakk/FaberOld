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
							uint32 minValue = 0,
							uint32 maxValue = 100,
							uint32 resizingMode = B_FOLLOW_LEFT | B_FOLLOW_TOP,
							uint32 flags = B_WILL_DRAW | B_NAVIGABLE);
						
                    ~Knob();
	virtual	void 	Draw(BRect updateRect);
	virtual void	MouseDown(BPoint where);
	//virtual void	MouseMoved(BPoint point, uint32 transit, const BMessage* message);
	
			uint32	Value();
			void	SetValue(uint32 value);

	
protected:
			uint32	fMinValue;
			uint32	fMaxValue;
			uint32	fValue;
private:
			uint32 resizingMode;
			uint32 flags;
};

#endif
