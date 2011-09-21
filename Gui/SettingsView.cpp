/*
 * Copyright (c) Casalinuovo Dario. All rights reserved.
 * Copyright (c) Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Casalinuovo Dario, barrett666@gmail.com
 *		Davide Gessa, dak.linux@gmail.com
 */
#include <Application.h>
#include <Alert.h>
#include <Button.h>
#include <GroupLayout.h>
#include <GroupView.h>
#include <OS.h>
#include <Menu.h>
#include <MenuBar.h>
#include <MenuItem.h>
#include <Slider.h>
#include <TextControl.h>
#include <Window.h>
#include <TabView.h>
#include <View.h>
#include <Box.h>
#include <Catalog.h>
#include <CheckBox.h>
#include <File.h>
#include <FindDirectory.h>
#include <Input.h>
#include <LayoutBuilder.h>
#include <SpaceLayoutItem.h>
#include "SettingsView.h"


SettingsView::~SettingsView()
{

}


SettingsView::SettingsView()
	:
	BView("SettingsView", B_WILL_DRAW, 0)
{
	SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
	
	// Main layout
	BGroupLayout* rootLayout = new BGroupLayout(B_VERTICAL);
	SetLayout(rootLayout);

	BRect r;
	BTabView *tabView;
	BTab *tab;
	
	tabView = new BTabView(r, " ");
	tabView->SetViewColor(216,216,216,0);

	r = tabView->Bounds();
	r.InsetBy(5,5);
	r.bottom -= tabView->TabHeight();
	rootLayout->AddView(tabView);


	// Interface
	BView *interfaceView = new BView(" ", B_WILL_DRAW,  0);
	
	tab = new BTab();
	tabView->AddTab(interfaceView, tab);
	tab->SetLabel("Interface");


	// Interface
	BView *hotkeyView = new BView(" ", B_WILL_DRAW,  0);
	
	tab = new BTab();
	tabView->AddTab(hotkeyView, tab);
	tab->SetLabel("Hotkeys");



	// Audio I/O
	BView *audioView = new BView(" ", B_WILL_DRAW,  0);
	
	//engineCombo = new BComboBox(BRect(0,0, 200, 30), " ", "Engine", new BMessage(MSG_SETTINGS_DEFAULTS));
	//audioView->AddView(engineCombo);
	
	
	tab = new BTab();
	tabView->AddTab(audioView, tab);
	tab->SetLabel("Audio IO");
	

	
	// Defaults and revert buttons
	BGroupView* buttonGroup = new BGroupView(B_HORIZONTAL);

	fDefaultsButton = new BButton("Defaults", new BMessage(MSG_SETTINGS_DEFAULTS));						
	buttonGroup->GroupLayout()->AddView(fDefaultsButton);

	fRevertButton = new BButton("Revert", new BMessage(MSG_SETTINGS_REVERT));							
	buttonGroup->GroupLayout()->AddView(fRevertButton);

	rootLayout->AddView(buttonGroup);
}


void SettingsView::AttachedToWindow()
{
	fDefaultsButton->SetTarget(this);
	fRevertButton->SetTarget(this);
	
	Window()->CenterOnScreen();
}


void SettingsView::MessageReceived(BMessage *message)
{
	switch(message->what)
	{
		case MSG_SETTINGS_REVERT:
		case MSG_SETTINGS_DEFAULTS:
		default:
			BView::MessageReceived(message);
	}			
}


