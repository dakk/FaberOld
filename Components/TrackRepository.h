/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#ifndef __TRACK_REPOSITORY_H
#define __TRACK_REPOSITORY_H

#include <View.h>
#include <List.h>
#include <ScrollView.h>
#include <GroupLayout.h>
#include <ListView.h>
#include "TimeTrack.h"
#include "Globals.h"
#include "Track.h"

class TrackRepository : public BView
{
public:
								TrackRepository(BRect frame = BRect(0, 0, 500, 300), 
												const char* name = "TrackRepository", 
												uint32 resizingMode = B_FOLLOW_ALL_SIDES, 
												uint32 flags = B_WILL_DRAW);
								~TrackRepository();

			void				AddTrack(Track *track, int32 position = -1);
			bool				RemoveTrack(Track *track);
			bool				RemoveTrack(int32 position);
			
			float				ZoomLevel();
			void				SetZoomLevel(float zoom);
			
			int32				CurrentTime();
			int32				CursorTime();

			BList*				TrackList();
			int32				CountTracks();
			int32				MasterVolume();
			void				SetMasterVolume(int32 vol);
	
	static	TrackRepository*	Instance();
	
private:
    static	TrackRepository*	fInstance;
			BList*				fTrackList;
			
			// Master volume
			int32				fMasterVolume;
			
			// Level of zooming: 1.0 -> 1 sec = 10 pixels
			float				fZoomLevel;
			BGroupLayout* 		fLayout;
			

			// Time where rendering starts
			int32				fCurrentTime;

			// Time of the current cursor
			int32				fCursorTime;
			
			TimeTrack*			fTimeTrack;
			
};

#endif
