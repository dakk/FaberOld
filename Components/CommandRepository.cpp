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
	
	fUndoStack->Clear();
	fRedoStack->Clear();
}

CommandRepository::~CommandRepository()
{
	for(i = 0; i < fUndoStack->CountItems(); i++)
	{
		BMessage* cmd = (BMessage *) fUndoStack->ItemAt(i);
		fUndoStack->RemoveItem(cmd);
		delete cmd;
	}
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
	/* Create a bmessage to save old and new data */
	BMessage *msg = new BMessage(FABER_MSG_MASTER_VOLUME);
	msg->AddInt32("oldValue", TrackRepository::Instance()->MasterVolume());
	msg->AddInt32("Value", vol);
	msg->AddString("Command", "Set Master Volume");
	
	/* Add the bmessage in the undo stack */
	fUndoStack->AddItem(msg);
		
	/* Set the value */
	TrackRepository::Instance()->SetMasterVolume(vol);	
}


void CommandRepository::AddTrack(TrackType type)
{
	Track *track;
	
	switch(type)
	{
		#ifdef AUDIO
		case ETT_AUDIO_MONO:
		{
			track = new TrackAudioMono();
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
	Track *track = (Track*) TrackRepository::Instance()->TrackList()->ItemAt(id);
	
	if(track == NULL)
		return;


	/* Create a bmessage to save old and new data */
	BMessage *msg = new BMessage(FABER_MSG_TRACK_MUTE);
	msg->AddBool("oldValue", track->Mute());
	msg->AddBool("Value", state);
	msg->AddString("Command", "Mute Track");
	
	/* Add the bmessage in the undo stack */
	fUndoStack->AddItem(msg);
		
	/* Set the value */
	track->SetMute(state);	
}


void CommandRepository::SetTrackPan(int32 id, int32 pan)
{
	Track *track = (Track*) TrackRepository::Instance()->TrackList()->ItemAt(id);
	
	if(track == NULL)
		return;


	/* Create a bmessage to save old and new data */
	BMessage *msg = new BMessage(FABER_MSG_TRACK_PAN);
	msg->AddInt32("oldValue", track->Pan());
	msg->AddInt32("Value", pan);
	msg->AddString("Command", "Set Track Pan");
	
	/* Add the bmessage in the undo stack */
	fUndoStack->AddItem(msg);
		
	/* Set the value */
	track->SetPan(pan);	
}


void CommandRepository::SetTrackSolo(int32 id, bool state)
{
	Track *track = (Track*) TrackRepository::Instance()->TrackList()->ItemAt(id);
	
	if(track == NULL)
		return;


	/* Create a bmessage to save old and new data */
	BMessage *msg = new BMessage(FABER_MSG_TRACK_SOLO);
	msg->AddBool("oldValue", track->Solo());
	msg->AddBool("Value", state);
	msg->AddString("Command", "Solo Track");
	
	/* Add the bmessage in the undo stack */
	fUndoStack->AddItem(msg);
		
	/* Set the value */
	track->SetSolo(state);		
}


void CommandRepository::SetTrackVolume(int32 id, int32 vol)
{
	Track *track = (Track*) TrackRepository::Instance()->TrackList()->ItemAt(id);
	
	if(track == NULL)
		return;


	/* Create a bmessage to save old and new data */
	BMessage *msg = new BMessage(FABER_MSG_TRACK_VOLUME);
	msg->AddInt32("oldValue", track->Volume());
	msg->AddInt32("Value", vol);
	msg->AddString("Command", "Set Track Volume");
	
	/* Add the bmessage in the undo stack */
	fUndoStack->AddItem(msg);
		
	/* Set the value */
	track->SetVolume(vol);	
}


