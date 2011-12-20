/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#include <Alert.h>
#include <Application.h>
#include <GroupLayout.h>
#include <MenuItem.h>
#include <GroupView.h>
#include <Button.h>

#include "MainView.h"
#include "ProjectManager.h"
#include "CommandRepository.h"
#include "TrackRepository.h"
#include "Track.h"
#include "TrackAudioMono.h"
#include "SettingsWindow.h"
#include "ImageButton.h"
#include "Knob.h"
#include "TimeTrack.h"
#include "MixerWindow.h"


MainView* MainView::fInstance = NULL;


MainView::MainView()
	:
	BView("MainView", B_WILL_DRAW, 0)
{
	SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));

	// Main layout
	BGroupLayout* rootLayout = new BGroupLayout(B_VERTICAL);
	SetLayout(rootLayout);


	// Menu bar
	fMenuBar = new BMenuBar("MenuBar");
	rootLayout->AddView(fMenuBar);
	
	fFileMenu = new BMenu("File");
	fFileMenu->AddItem(new BMenuItem("New", new BMessage(MSG_NEW), 'N'));
	fFileMenu->AddItem(new BMenuItem("Open", new BMessage(MSG_OPEN), 'O'));
	fFileMenu->AddItem(new BMenuItem("Close", new BMessage(MSG_CLOSE), 'W'));
	fFileMenu->AddItem(new BSeparatorItem);	
	fFileMenu->AddItem(new BMenuItem("Save", new BMessage(MSG_SAVE), 'S'));
	fFileMenu->AddItem(new BMenuItem("Save As...", new BMessage(MSG_SAVE_AS)));
	
	BMenu *exportMenu = new BMenu("Export");
	exportMenu->AddItem(new BMenuItem("Wave", new BMessage((long unsigned) 0)));
	fFileMenu->AddItem(exportMenu);
	
	fFileMenu->AddItem(new BSeparatorItem);	
	fFileMenu->AddItem(new BMenuItem("Quit", new BMessage(MSG_QUIT), 'Q'));
	fMenuBar->AddItem(fFileMenu);
	
	fEditMenu = new BMenu("Edit");
	fUndoMenuItem = new BMenuItem("Undo", new BMessage(MSG_UNDO), 'U');
	fUndoMenuItem->SetEnabled(false);
	fEditMenu->AddItem(fUndoMenuItem);
	fRedoMenuItem = new BMenuItem("Redo", new BMessage(MSG_REDO), 'R');
	fRedoMenuItem->SetEnabled(false);
	fEditMenu->AddItem(fRedoMenuItem);
	fEditMenu->AddItem(new BSeparatorItem);	
	fEditMenu->AddItem(new BMenuItem("Cut", new BMessage(MSG_CUT), 'X'));
	fEditMenu->AddItem(new BMenuItem("Copy", new BMessage(MSG_COPY), 'C'));
	fEditMenu->AddItem(new BMenuItem("Paste", new BMessage(MSG_PASTE), 'P'));
	fEditMenu->AddItem(new BSeparatorItem);	
	fEditMenu->AddItem(new BMenuItem("Settings", new BMessage(MSG_SETTINGS), 'S'));
	fMenuBar->AddItem(fEditMenu);

	fViewMenu = new BMenu("View");
	fViewMenu->AddItem(new BMenuItem("Mixer", new BMessage(MSG_MIXER), 'M'));
	fViewMenu->AddItem(new BSeparatorItem);	
	fViewMenu->AddItem(new BMenuItem("Zoom In", new BMessage(MSG_ZOOM_IN), '+'));
	fViewMenu->AddItem(new BMenuItem("Zoom Out", new BMessage(MSG_ZOOM_OUT), '-'));
	fViewMenu->AddItem(new BSeparatorItem);	
	fViewMenu->AddItem(new BMenuItem("Fullscreen", new BMessage(MSG_FULLSCREEN), 'F'));
	fMenuBar->AddItem(fViewMenu);

	fSeekMenu = new BMenu("Seek");
	fSeekMenu->AddItem(new BMenuItem("Play", new BMessage(MSG_PLAY)));
	fSeekMenu->AddItem(new BMenuItem("Play Loop", new BMessage(MSG_PLAY_LOOP)));
	fSeekMenu->AddItem(new BMenuItem("Play Region", new BMessage(MSG_PLAY_REGION)));
	fSeekMenu->AddItem(new BMenuItem("Stop", new BMessage(MSG_STOP)));
	fSeekMenu->AddItem(new BSeparatorItem);	
	fSeekMenu->AddItem(new BMenuItem("Seek Start", new BMessage(MSG_SEEK_START)));
	fSeekMenu->AddItem(new BMenuItem("Seek End", new BMessage(MSG_SEEK_END)));
	fMenuBar->AddItem(fSeekMenu);
	
	
	
	
	fTrackMenu = new BMenu("Track");
	fTrackAddMenu = new BMenu("Add Track");
	
	#ifdef AUDIO
	fTrackAddMenu->AddItem(new BMenuItem("Audio Mono", new BMessage(MSG_ADD_AUDIO_MONO)));
	fTrackAddMenu->AddItem(new BMenuItem("Audio Stereo", new BMessage(MSG_ADD_AUDIO_STEREO)));
	#ifdef AUDIO_SURROUND
	fTrackAddMenu->AddItem(new BMenuItem("Audio Surround", new BMessage(MSG_ADD_AUDIO_SURROUND)));
	#endif
	#endif
	
	#ifdef MIDI
	fTrackAddMenu->AddItem(new BMenuItem("Midi", new BMessage(MSG_ADD_MIDI)));
	#endif
	
	#ifdef VIDEO
	fTrackAddMenu->AddItem(new BMenuItem("Video", new BMessage(MSG_ADD_VIDEO)));
	#endif
	
	#ifdef SUBTITLE
	fTrackAddMenu->AddItem(new BMenuItem("Subtitles", new BMessage(MSG_ADD_SUBTITLE)));
	#endif
	
	fTrackMenu->AddItem(fTrackAddMenu);
	
	fMenuBar->AddItem(fTrackMenu);


	fHelpMenu = new BMenu("Help");
	fHelpMenu->AddItem(new BMenuItem("About", new BMessage(MSG_ABOUT)));
	fMenuBar->AddItem(fHelpMenu);


	// Toolbar	
	BGroupView* buttonGroup = new BGroupView(B_HORIZONTAL);
	
	//buttonGroup->GroupLayout()->AddView(new ImageButton(BRect(0,0,24,24), "PlayIcon", "Data/play.png",
	//													"Data/play_off.png", new BMessage(MSG_PLAY)));
	BButton *b;
	
	
	/*b = new BButton("<<", new BMessage(MSG_SEEK_START));						
	buttonGroup->GroupLayout()->AddView(b);
	b = new BButton(">>", new BMessage(MSG_SEEK_END));						
	buttonGroup->GroupLayout()->AddView(b);*/
	b = new BButton("Play", new BMessage(MSG_PLAY));						
	buttonGroup->GroupLayout()->AddView(b);
	b = new BButton("Stop", new BMessage(MSG_STOP));						
	buttonGroup->GroupLayout()->AddView(b);
	/*b = new BButton("Cut", new BMessage(MSG_CUT));						
	buttonGroup->GroupLayout()->AddView(b);
	b = new BButton("Copy", new BMessage(MSG_COPY));						
	buttonGroup->GroupLayout()->AddView(b);
	b = new BButton("Paste", new BMessage(MSG_PASTE));						
	buttonGroup->GroupLayout()->AddView(b);*/
	fPositionControl = new BTextControl(BRect(), "PositionControl", "", "0", new BMessage(MSG_SEEK_TO));
	buttonGroup->GroupLayout()->AddView(fPositionControl);

	rootLayout->AddView(buttonGroup);


	// Track view	
	BScrollView *scrollView;
	fTrackRepository = new TrackRepository(BRect(0, 0, 500, 300), "TrackRepository", B_FOLLOW_ALL_SIDES, B_WILL_DRAW);
	scrollView = new BScrollView("TrackScrollView", fTrackRepository, B_FOLLOW_ALL_SIDES, B_WILL_DRAW, true, true);
	rootLayout->AddView(scrollView);
	

	// Status bar
	fStatusBar = new BStatusBar(BRect(), "StatusBar", NULL, NULL);
	fStatusBar->SetBarColor(ui_color(B_PANEL_BACKGROUND_COLOR));
	fStatusBar->SetText("Ready.");
	rootLayout->AddView(fStatusBar);
	
	// Create FilePanels
	fOpenFilePanel = new BFilePanel(B_OPEN_PANEL);
	fSaveFilePanel = new BFilePanel(B_SAVE_PANEL);	
	
	fInstance = this;		
}




MainView::~MainView()
{
	delete fOpenFilePanel;
	delete fSaveFilePanel;
}



void MainView::AttachedToWindow()
{
	fFileMenu->SetTargetForItems(this);
	fEditMenu->SetTargetForItems(this);
	fTrackMenu->SetTargetForItems(this);
	fTrackAddMenu->SetTargetForItems(this);
	fViewMenu->SetTargetForItems(this);
	fHelpMenu->SetTargetForItems(this);
	
	Window()->CenterOnScreen();
	//Window()->SetPulseRate(5000);
}



void MainView::UpdateUndoRedo()
{
	BList *l = CommandRepository::Instance()->UndoStack();
	
	if(l->CountItems() != 0)
	{
		char undoText[128];
		//sprintf(undoText, "Undo '%s'", ((Command *) (l->LastItem()))->Name());
		fUndoMenuItem->SetEnabled(true);
		//fUndoMenuItem->SetLabel(undoText);
	}
	else
	{
		fUndoMenuItem->SetEnabled(false);
		fUndoMenuItem->SetLabel("Undo");
	}
}


void MainView::UpdateTitle()
{
	char newTitle[512];
	
	if(ProjectManager::Instance()->Path().Path() != NULL)
		sprintf(newTitle, "Faber Media Editor - %s (%s)", 
				ProjectManager::Instance()->Name(), 
				ProjectManager::Instance()->Path().Path());
	else
		sprintf(newTitle, "Faber Media Editor - %s", ProjectManager::Instance()->Name());
	
	if(ProjectManager::Instance()->IsUpdated())
		strcat(newTitle, " *");
	Window()->SetTitle(newTitle);	
}


MainView* MainView::Instance()
{
	return fInstance;
}

void MainView::MessageReceived(BMessage *message)
{
    switch(message->what)
    {
        /* File commands */
        case MSG_QUIT:
        {
			if(ProjectManager::Instance()->IsUpdated())
			{
				BAlert *askAlert = new BAlert("Quit", "Are you sure to quit without saving?", "Save", "Quit", NULL, 
					B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_WARNING_ALERT);
				
				askAlert->SetShortcut(0, B_ESCAPE);
				int32 resp = askAlert->Go();
				
				if(resp == 0)
					Looper()->PostMessage(new BMessage(MSG_SAVE));
			}
			
			// Quit
			be_app->Looper()->PostMessage(B_QUIT_REQUESTED);
            break;
		}

		case MSG_FILE_OPEN:
		{
			entry_ref ref;
			BEntry *entry;
			BPath path;
			
			fOpenFilePanel->Hide();
			if(fOpenFilePanel->GetNextSelectedRef(&ref) == B_ENTRY_NOT_FOUND)
				break;
				
			entry = new BEntry(&ref);
			entry->GetPath(&path);
			
			ProjectManager::Instance()->SetPath(path);
			if(ProjectManager::Instance()->Load())
			{
			}
			else
			{
				BAlert *alert = new BAlert("Warning", "Invalid file", "OK", NULL, 
					NULL, B_WIDTH_FROM_WIDEST, B_EVEN_SPACING, B_WARNING_ALERT);
				alert->Go();
				
				ProjectManager::Instance()->Close();
				ProjectManager::Instance()->New();
			}
			UpdateTitle();
			
			delete entry;
			break;
    	}	
			
        case MSG_OPEN:
        {
			if(ProjectManager::Instance()->IsUpdated())
			{
				BAlert *askAlert = new BAlert("Open", "Are you sure to open another project without saving?", "Save", "Open", NULL, 
					B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_WARNING_ALERT);
				
				askAlert->SetShortcut(0, B_ESCAPE);
				int32 resp = askAlert->Go();
				
				if(resp == 0)
					Looper()->PostMessage(new BMessage(MSG_SAVE));
			}
			ProjectManager::Instance()->Close();
			fOpenFilePanel->Show();
			fOpenFilePanel->SetTarget((BHandler*) this);
			fOpenFilePanel->SetMessage(new BMessage(MSG_FILE_OPEN));
			
            break;
        }
        
        case MSG_CLOSE:
        {
        	if(ProjectManager::Instance()->IsUpdated())
			{
				BAlert *askAlert = new BAlert("Open", "Are you sure to close this project without saving?", "Save", "Close", NULL, 
					B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_WARNING_ALERT);
				
				askAlert->SetShortcut(0, B_ESCAPE);
				int32 resp = askAlert->Go();
				
				if(resp == 0)
					Looper()->PostMessage(new BMessage(MSG_SAVE));
			}
			
			ProjectManager::Instance()->Close();
			UpdateTitle();
            break;        	
        }
        
        case MSG_NEW:
        {
			if(ProjectManager::Instance()->IsUpdated())
			{
				BAlert *askAlert = new BAlert("New", "Are you sure to create a new project without saving?", "Save", "New", NULL, 
					B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_WARNING_ALERT);
				
				askAlert->SetShortcut(0, B_ESCAPE);
				int32 resp = askAlert->Go();
				
				if(resp == 0)
					Looper()->PostMessage(new BMessage(MSG_SAVE));
			}
			
			ProjectManager::Instance()->Close();
			ProjectManager::Instance()->New();
			
			UpdateTitle();
            break;
        }
        

		case MSG_FILE_SAVE:
		{
			entry_ref ref;
			BEntry *entry;
			BPath path;
			
			fSaveFilePanel->Hide();
			if(fSaveFilePanel->GetNextSelectedRef(&ref) == B_ENTRY_NOT_FOUND)
				break;
				
			entry = new BEntry(&ref);
			entry->GetPath(&path);
			
			ProjectManager::Instance()->SetPath(path);
						
			if(ProjectManager::Instance()->Save())
			{
			}
			else
			{
				BAlert *alert = new BAlert("Warning", "Invalid file", "OK", NULL, 
					NULL, B_WIDTH_FROM_WIDEST, B_EVEN_SPACING, B_WARNING_ALERT);
				alert->Go();
			}
			UpdateTitle();
			
			break;
    	}
    	
        case MSG_SAVE:
		{
			if(!ProjectManager::Instance()->IsUpdated())
				break;
			
			if(ProjectManager::Instance()->Path().Path() == NULL)
			{
				fSaveFilePanel->Show();
				fSaveFilePanel->SetTarget((BHandler*) this);
				fSaveFilePanel->SetMessage(new BMessage(MSG_FILE_SAVE));
			}	
			else
			{
				ProjectManager::Instance()->Save();
				UpdateTitle();
			}
            break;
		}
		
        case MSG_SAVE_AS:
        {
        	fSaveFilePanel->Show();
			fSaveFilePanel->SetTarget((BHandler*) this);
			fSaveFilePanel->SetMessage(new BMessage(MSG_FILE_SAVE));
            break;
        }


        /* Edit commands */
        case MSG_UNDO:
        {
        	CommandRepository::Instance()->Undo();
        	UpdateUndoRedo();
            break;
        }

        case MSG_REDO:
        {
        	CommandRepository::Instance()->Redo();
        	UpdateUndoRedo();
            break;
        }

        case MSG_CUT:
            break;

        case MSG_COPY:
            break;

        case MSG_PASTE:
            break;

        case MSG_SETTINGS:
        {
        	SettingsWindow *settingsWindow = new SettingsWindow();
        	settingsWindow->Show();
            break;
        }


		/* View commands */
		case MSG_FULLSCREEN:
		{
			if(Window()->Look() != B_BORDERED_WINDOW_LOOK)
			{
				Window()->SetLook(B_BORDERED_WINDOW_LOOK);
			}
			else
			{
				Window()->SetLook(B_TITLED_WINDOW_LOOK);
			}
			
			break;	
		}
		
		case MSG_MIXER:
		{
			MixerWindow *mixerWindow = new MixerWindow();
			mixerWindow->Show();
			break;	
		}
		
		case MSG_ZOOM_IN:
			TrackRepository::Instance()->SetZoomLevel(TrackRepository::Instance()->ZoomLevel() / 1.5);
			break;
			
		case MSG_ZOOM_OUT:
			TrackRepository::Instance()->SetZoomLevel(TrackRepository::Instance()->ZoomLevel() * 1.5);
			break;
		
        /* Help commands */
        case MSG_ABOUT:
        {
        	BAlert *alert = new BAlert("About Faber Media Editor", 
			"\nFaber v0.0.1\n\n"
			"Copyright ©2011 Davide Gessa \n\n"
			"Copyright ©2011 Casalinuovo Dario\n\n",
			"OK", NULL, NULL, B_WIDTH_FROM_WIDEST, B_EVEN_SPACING, B_INFO_ALERT);
			alert->Go();

            break;
        }
        
        case MSG_MANUAL:
            break;


        /* Tracks commands */
        #ifdef MIDI
        case MSG_ADD_MIDI:
		{
			//CommandRepository::Instance()->ExecuteCommand(COMMAND_TRACK_ADD, (void *) ETT_MIDI);
            UpdateUndoRedo();
            break;
        }
        #endif

        #ifdef SUBTITLE
        case MSG_ADD_SUBTITLE:
		{
			//CommandRepository::Instance()->ExecuteCommand(COMMAND_TRACK_ADD, (void *) ETT_SUBTITLE);
            UpdateUndoRedo();
            break;
        }
        #endif

        #ifdef VIDEO
        case MSG_ADD_VIDEO:
		{
			//CommandRepository::Instance()->ExecuteCommand(COMMAND_TRACK_ADD, (void *) ETT_VIDEO);
            UpdateUndoRedo();
            break;
        }
        #endif

        #ifdef AUDIO
        case MSG_ADD_AUDIO_MONO:
		{
			//CommandRepository::Instance()->ExecuteCommand(COMMAND_TRACK_ADD, (void *) ETT_AUDIO_MONO);
            UpdateUndoRedo();
            break;
        }

        case MSG_ADD_AUDIO_STEREO:
		{
			//CommandRepository::Instance()->ExecuteCommand(COMMAND_TRACK_ADD, (void *) ETT_AUDIO_STEREO);
            UpdateUndoRedo();
            break;
        }
            
		#ifdef AUDIO_SURROUND
        case MSG_ADD_AUDIO_SURROUND:
		{
			//CommandRepository::Instance()->ExecuteCommand(COMMAND_TRACK_ADD, (void *) ETT_AUDIO_SURROUND);
            UpdateUndoRedo();
            break;
        }
        #endif
        #endif


        /* Seek commands */
        case MSG_SEEK_END:
            break;

        case MSG_SEEK_START:
            break;

        case MSG_SEEK_TO:
            break;

		case MSG_PLAY_LOOP:
			break;
			
		case MSG_PLAY_REGION:
			break;
			
        case MSG_PLAY:
            break;

        case MSG_STOP:
            break;

    }
}

