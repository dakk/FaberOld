/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#include <SeparatorView.h>
#include "TrackRepository.h"
#include "TimeTrack.h"

TrackRepository* TrackRepository::fInstance = NULL;


TrackRepository::TrackRepository(BRect frame, const char* name, uint32 resizingMode, uint32 flags)
				:
				BView(frame, name, resizingMode, flags)
{
	fInstance = this;
	SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
	
	fLayout = new BGroupLayout(B_VERTICAL, 0.0f);
	SetLayout(fLayout);

	fTrackList = new BList(10);
	fCursorTime = 3;
	fCurrentTime = 0;
	fZoomLevel = 5.0;
	fMasterVolume = 100;
	
	fTimeTrack = new TimeTrack(BRect(0, 30, 300, 30), "TimeTrack", B_FOLLOW_ALL_SIDES, B_WILL_DRAW);
	fLayout->AddView(fTimeTrack);
	//AddChild(fTimeTrack);
}


TrackRepository::~TrackRepository()
{
	Track *item;

	
	for(int32 i = 0; item = (Track *) fTrackList->ItemAt(i); i++)
	   delete item;

	delete fTrackList;
	delete fTimeTrack;
}

int32 TrackRepository::CursorTime()
{
	return fCursorTime;	
}

int32 TrackRepository::CountTracks()
{
	return fTrackList->CountItems();	
}

int32 TrackRepository::MasterVolume()
{
	return fMasterVolume;
}

void TrackRepository::SetMasterVolume(int32 vol)
{
	fMasterVolume = vol;	
}
			
			
BList* TrackRepository::TrackList()
{
	return fTrackList;	
}


float TrackRepository::ZoomLevel()
{
	return fZoomLevel;
}

int32 TrackRepository::CurrentTime()
{
	return fCurrentTime;	
}

TrackRepository* TrackRepository::Instance()
{
	if(fInstance != NULL)
		return fInstance;

	return NULL;
}



void TrackRepository::AddTrack(Track *track, int32 position)
{
	BLayoutItem *item;
	/*
	if(position == -1)
	{
		fTrackList->AddItem((void *) track);
		//AddChild(track);
		item = fLayout->AddView(track);
	}
	else
	{
		fTrackList->AddItem((void *) track, position);
		//AddChild(track);
		item = fLayout->AddView(position, track);
	}*/
}


void TrackRepository::SetZoomLevel(float zoom)
{
	if(zoom > 0.3) 
		fZoomLevel = zoom;	
}
			


bool TrackRepository::RemoveTrack(Track *track)
{
	bool result;

	result = fTrackList->RemoveItem((void *) track);
	fLayout->RemoveView(track);
	delete track;

	return result;
}



bool TrackRepository::RemoveTrack(int32 position)
{
	Track *track;

	track = (Track *) fTrackList->RemoveItem(position);

	if(track != NULL)
	{
		fLayout->RemoveView(track);
		delete track;
		return true;
	}

	return false;
}



