/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#include "CommandRepository.h"
#include "MainView.h"

CommandRepository* CommandRepository::fInstance = NULL;


CommandRepository::CommandRepository()
{
	fUndoStack = new BList(20);
	fRedoStack = new BList(20);
}

CommandRepository::~CommandRepository()
{
}




BList* CommandRepository::UndoStack()
{
	return fUndoStack;	
}




void CommandRepository::Redo()
{
	
}


void CommandRepository::Undo()
{
	
}




CommandRepository* CommandRepository::Instance()
{
	if(fInstance != NULL)
		return fInstance;

	fInstance = new CommandRepository();
	return fInstance;
}



void CommandRepository::SetMasterVolume(int32 vol)
{
	// Save old volume in the undo stack
	int32 oldVolume = TrackRepository::Instance()->MasterVolume();
	
	TrackRepository::Instance()->SetMasterVolume(vol);	
}


void CommandRepository::AddTrack(TrackType type)
{
	switch(type)
	{
		#ifdef AUDIO
		case ETT_AUDIO_MONO:
		{
			Track *track = new TrackAudioMono();
			TrackRepository::Instance()->AddTrack(track);
		}		
		case ETT_AUDIO_STEREO:
		{
			//Track *track = new TrackAudioStereo();
			//TrackRepository::Instance()->AddTrack(track);
		}		
		
		#ifdef AUDIO_SURROUND
		case ETT_AUDIO_SURROUND:
		{
			//Track *track = new TrackAudioSurround();
			//TrackRepository::Instance()->AddTrack(track);
		}		
		#endif
		#endif
		
		#ifdef MIDI
		case ETT_MIDI:
		{
			//Track *track = new TrackMidi();
			//TrackRepository::Instance()->AddTrack(track);
		}		
		#endif
		
		
		#ifdef VIDEO
		case ETT_VIDEO:
		{
			//Track *track = new TrackVideo();
			//TrackRepository::Instance()->AddTrack(track);
		}		
		#endif
		
		
		#ifdef SUBTITLE
		case ETT_SUBTITLE:
		{
			//Track *track = new TrackSubtitle();
			//TrackRepository::Instance()->AddTrack(track);
		}		
		#endif
	}	
}


void CommandRepository::SetTrackMute(int32 id, bool state)
{	
	track = (Track*) TrackRepository::Instance()->TrackList()->ItemAt(id);
	
	if(fTrack == NULL)
		return;
	
	bool oldState = track->GetMute();
	track->SetMute(state);	
}


void CommandRepository::SetTrackPan(int32 id, int32 pan)
{
	track = (Track*) TrackRepository::Instance()->TrackList()->ItemAt(id);
	
	if(fTrack == NULL)
		return;
	
	int32 oldPan = track->GetPan();
	track->SetPan(pan);		
}


void CommandRepository::SetTrackSolo(int32 id, bool state)
{
	track = (Track*) TrackRepository::Instance()->TrackList()->ItemAt(id);
	
	if(fTrack == NULL)
		return;
	
	bool oldState = track->GetSolo();
	track->SetSolo(state);	
}


void CommandRepository::SetTrackVolume(int32 id, int32 vol)
{
	track = (Track*) TrackRepository::Instance()->TrackList()->ItemAt(id);
	
	if(fTrack == NULL)
		return;
	
	int32 oldVolume = track->GetVolume();
	track->SetVolume(vol);		
}


