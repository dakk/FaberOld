/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#include "ImageButton.h"

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


BPicture *LoadPictureFromFile(const char *path)
{
	BPicture *b;
	BView *v;
	BWindow *w;
	
	BBitmap *icon = BTranslationUtils::GetBitmapFile(path);
	
	if(icon == NULL)
		return NULL;
		
	v = new BView(" ", B_WILL_DRAW, 0);
	w = new BWindow(BRect(0, 0, 24, 24), " ", B_TITLED_WINDOW, 0);
	w->SetLayout(new BGroupLayout(B_VERTICAL));
	w->GetLayout()->AddView(v);
	
	v->SetDrawingMode(B_OP_BLEND);
	v->BeginPicture(new BPicture);
	v->DrawBitmap(icon, BRect(0,0,24,24), BRect(0,0,24,24) );

	b = v->EndPicture();

	delete icon;
	delete w;
	return b;
}


ImageButton::ImageButton(BRect frame, const char* name, 
						const char* off_path, const char *on_path,
						BMessage* message, uint32 behavior,
						uint32 resizingMode, uint32 flags)
			:
			BPictureButton(frame, name, LoadPictureFromFile(off_path),
							LoadPictureFromFile(on_path), message, 
							behavior, resizingMode, flags)
{
}

ImageButton::~ImageButton()
{
}


