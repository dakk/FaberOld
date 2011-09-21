/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#ifndef __TRACK_H
#define __TRACK_H

#include "Globals.h"
#include <View.h>

typedef enum
{
	ETT_AUDIO_MONO,
	ETT_AUDIO_STEREO,
	ETT_AUDIO_SURROUND,
	ETT_MIDI,
	ETT_VIDEO,
	ETT_SUBTITLE
} TrackType;

class Track : public BView
{
public:
					Track(BRect frame, const char* name, uint32 resizingMode, uint32 flags);
	virtual 		~Track();
	virtual	void 	Draw(BRect updateRect) = 0;
	
			int32	Volume();
			void	SetVolume(int32 volume);
			
	const	char*	Name();
			void	SetName(const char *name);
			
			bool	Mute();
			void	SetMute(bool mute);
			
			bool	Solo();
			void	SetSolo(bool solo);
	
			int32	Pan();
			void	SetPan(int32 pan);
private:
			char	fName[128];
			int32	fVolume;
			bool	fMute;
			bool	fSolo;
			
			// Pan is a value between -10 and 10 where 0 is centered
			int32	fPan;
};

#endif
