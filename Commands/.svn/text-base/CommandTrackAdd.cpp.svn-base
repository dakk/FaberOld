/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#include "CommandTrackAdd.h"
#include "Track.h"
#include "TrackAudioMono.h"
#include "TrackRepository.h"


CommandTrackAdd::~CommandTrackAdd()
{
}

CommandTrackAdd::CommandTrackAdd() 
				: 
				Command("add track")
{
}

void CommandTrackAdd::Execute()
{
}

void* CommandTrackAdd::Execute(void* p1, void* p2, void* p3)
{
	TrackType trackType = (TrackType) (int32) p1;
	
	switch(trackType)
	{
		#ifdef AUDIO
		case ETT_AUDIO_MONO:
		{
			Track *track = new TrackAudioMono(BRect(), "TrackAudioMono", B_FOLLOW_ALL_SIDES, B_WILL_DRAW);
			TrackRepository::Instance()->AddTrack(track);
		}		
		case ETT_AUDIO_STEREO:
		{
			//Track *track = new TrackAudioStereo(BRect(), "TrackAudioStereo", B_FOLLOW_ALL_SIDES, B_WILL_DRAW);
			//TrackRepository::Instance()->AddTrack(track);
		}		
		
		#ifdef AUDIO_SURROUND
		case ETT_AUDIO_SURROUND:
		{
			//Track *track = new TrackAudioSurround(BRect(), "TrackAudioSurround", B_FOLLOW_ALL_SIDES, B_WILL_DRAW);
			//TrackRepository::Instance()->AddTrack(track);
		}		
		#endif
		#endif
		
		#ifdef MIDI
		case ETT_MIDI:
		{
			//Track *track = new TrackMidi(BRect(), "TrackMidi", B_FOLLOW_ALL_SIDES, B_WILL_DRAW);
			//TrackRepository::Instance()->AddTrack(track);
		}		
		#endif
		
		
		#ifdef VIDEO
		case ETT_VIDEO:
		{
			//Track *track = new TrackVideo(BRect(), "TrackVideo", B_FOLLOW_ALL_SIDES, B_WILL_DRAW);
			//TrackRepository::Instance()->AddTrack(track);
		}		
		#endif
		
		
		#ifdef SUBTITLE
		case ETT_SUBTITLE:
		{
			//Track *track = new TrackSubtitle(BRect(), "TrackSubtitle", B_FOLLOW_ALL_SIDES, B_WILL_DRAW);
			//TrackRepository::Instance()->AddTrack(track);
		}		
		#endif
	}
	
    return NULL;
}


Command* CommandTrackAdd::Clone()
{
	return new CommandTrackAdd();	
}

void CommandTrackAdd::Undo()
{


}

void CommandTrackAdd::Redo()
{
}

bool CommandTrackAdd::IsUndoable()
{
    return false;
}
