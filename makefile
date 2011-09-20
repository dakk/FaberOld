NAME= Faber
TYPE= APP

SRCS_GUI = Gui/MainWindow.cpp Gui/MainView.cpp Gui/SettingsWindow.cpp \
Gui/SettingsView.cpp Gui/MixerView.cpp Gui/MixerWindow.cpp 

SRCS_COMMANDS = Commands/CommandTrackAdd.cpp Commands/CommandTrackMute.cpp \
Commands/CommandTrackSolo.cpp Commands/CommandTrackVolume.cpp \
Commands/CommandMasterVolume.cpp Commands/CommandTrackPan.cpp

SRCS_COMPONENTS = Components/Command.cpp Components/Track.cpp Components/TrackRepository.cpp \
Components/ProjectManager.cpp Components/Debug.cpp Components/CommandRepository.cpp \
Components/Gui/ImageButton.cpp Components/Gui/Knob.cpp Components/TrackAudioMono.cpp \
Components/TimeTrack.cpp 

SRCS = Faber.cpp ApplicationInit.cpp  $(SRCS_GUI) $(SRCS_COMMANDS) $(SRCS_COMPONENTS)


RDEFS= 
	
LIBS= be translation tracker

LIBPATHS= 

DRIVER_PATH = 


SYSTEM_INCLUDE_PATHS = Components/Globals Components/Gui/ Components/ . Gui Commands


include $(BUILDHOME)/etc/makefile-engine
