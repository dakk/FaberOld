/*
 * Copyright (c) Casalinuovo Dario. All rights reserved.
 * Copyright (c) Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#ifndef SETTINGS_VIEW_H
#define SETTINGS_VIEW_H

#include <View.h>
#include <MenuBar.h>
#include <Menu.h>
#include <Button.h>
#include <Slider.h>
#include <TextControl.h>


const int32 MSG_SETTINGS_DEFAULTS		= 0xA1;
const int32 MSG_SETTINGS_REVERT			= 0xA2;


class SettingsView : public BView {
public:
					SettingsView();
					~SettingsView();
			void	AttachedToWindow();	
	virtual	void	MessageReceived(BMessage* message);

private:
	BButton			*fDefaultsButton;
	BButton			*fRevertButton;
};



#endif
