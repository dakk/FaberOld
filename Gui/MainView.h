/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#ifndef __MAIN_VIEW_H
#define __MAIN_VIEW_H

#include <View.h>
#include <Menu.h>
#include <MenuBar.h>
#include <MenuItem.h>
#include <TextControl.h>
#include <StatusBar.h>
#include <FilePanel.h>

#include "TrackRepository.h"
#include "Globals.h"


/* Gui buttons */
const int32 MSG_PLAY_REGION			=  0xA1;
const int32 MSG_PLAY_LOOP			=  0xA2;
const int32 MSG_PLAY                =  0xA3;
const int32 MSG_STOP                =  0xA4;

/* File commands */
const int32 MSG_QUIT                =  0x01;
const int32 MSG_OPEN                =  0x02;
const int32 MSG_NEW                 =  0x03;
const int32 MSG_SAVE                =  0x04;
const int32 MSG_SAVE_AS             =  0x05;
const int32 MSG_CLOSE				=  0x06;

/* Edit commands */
const int32 MSG_UNDO                =  0x11;
const int32 MSG_REDO                =  0x12;
const int32 MSG_CUT                 =  0x13;
const int32 MSG_COPY                =  0x14;
const int32 MSG_PASTE               =  0x15;
const int32 MSG_SETTINGS	        =  0x16;

/* Help commands */
const int32 MSG_ABOUT               =  0x21;
const int32 MSG_MANUAL              =  0x22;

/* View commands */
const int32 MSG_MIXER				=  0x61;
const int32 MSG_ZOOM_IN				=  0x62;
const int32 MSG_ZOOM_OUT			=  0x63;

/* Tracks commands */
const int32 MSG_ADD_MIDI            =  0x32;
const int32 MSG_ADD_SUBTITLE        =  0x33;
const int32 MSG_ADD_VIDEO           =  0x34;
const int32 MSG_ADD_AUDIO_MONO      =  0x35;
const int32 MSG_ADD_AUDIO_STEREO    =  0x36;
const int32 MSG_ADD_AUDIO_SURROUND  =  0x37;

/* Seek commands */
const int32 MSG_SEEK_END            =  0x41;
const int32 MSG_SEEK_START          =  0x42;
const int32 MSG_SEEK_TO             =  0x43;

/* File chooser */
const int32 MSG_FILE_OPEN			=  0x51;
const int32 MSG_FILE_SAVE			=  0x52;



class MainView : public BView
{
public:
    	            			MainView();
	                			~MainView();
			void				AttachedToWindow();	
	virtual	void				MessageReceived(BMessage* message);
	
	static	MainView*			Instance();

			void				UpdateUndoRedo();
			void				UpdateTitle();
	
private:
    static	MainView*			fInstance;
    		
    		TrackRepository*	fTrackRepository;
			BMenu*				fFileMenu;
			BMenu*				fEditMenu;
			BMenu*				fHelpMenu;
			BMenu*				fSeekMenu;
			BMenu*				fViewMenu;
			BMenu*				fTrackMenu;
			BMenu*				fTrackAddMenu;
			BMenuItem*			fUndoMenuItem;
			BMenuItem*			fRedoMenuItem;
			BMenuBar*			fMenuBar;
			BStatusBar*			fStatusBar;
			BTextControl*		fPositionControl;	
			BFilePanel*			fOpenFilePanel;		
			BFilePanel*			fSaveFilePanel;	
};

#endif
