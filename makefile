NAME= Faber
TYPE= APP

SRCS_GUI = Gui/MainWindow.cpp Gui/MainView.cpp Gui/SettingsWindow.cpp \
Gui/SettingsView.cpp Gui/MixerView.cpp Gui/MixerWindow.cpp 

SRCS_COMPONENTS = Components/Track.cpp Components/TrackRepository.cpp \
Components/ProjectManager.cpp Components/Debug.cpp Components/CommandRepository.cpp \
Components/Gui/ImageButton.cpp Components/Gui/Knob.cpp Components/TrackAudioMono.cpp \
Components/TimeTrack.cpp 

SRCS = Faber.cpp ApplicationInit.cpp  $(SRCS_GUI) $(SRCS_COMMANDS) $(SRCS_COMPONENTS)


RDEFS= 
	
LIBS= be translation tracker stdc++

LIBPATHS= 

DRIVER_PATH = 


SYSTEM_INCLUDE_PATHS = Components/Globals Components/Gui/ Components/ . Gui Commands


include $(BUILDHOME)/etc/makefile-engine
