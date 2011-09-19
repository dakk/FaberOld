/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#ifndef __IMAGE_BUTTON_H
#define __IMAGE_BUTTON_H

#include <PictureButton.h>
#include <Picture.h>

class ImageButton : public BPictureButton
{
public:
                    ImageButton(BRect frame, const char* name, 
						const char* off_path, const char *on_path,
						BMessage* message, uint32 behavior = B_ONE_STATE_BUTTON,
						uint32 resizingMode = B_FOLLOW_LEFT | B_FOLLOW_TOP,
						uint32 flags = B_WILL_DRAW | B_NAVIGABLE);
						
                    ~ImageButton();
};

#endif
