/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#ifndef __PROJECT_MANAGER_H
#define __PROJECT_MANAGER_H

#include <Path.h>
#include "Globals.h"

class ProjectManager
{
public:
								~ProjectManager();
								
	///> Return the singleton instnace
	static	ProjectManager*		Instance();
	
	///> Close the opened project
			void				Close();
			
	///> Create an empty project
			void				New();
			
	///> Save the project in the path set by SetPath
			bool				Save();
			
	///> Load the project from the path set by SetPath
			bool				Load();
			
	///> Return current project path
			BPath				Path();
	
	///> Set new project path
			void				SetPath(BPath path);
	
	///> True if there're unsaved data
			bool				IsUpdated();
	
	///> Return the name of the projectt
	const	char*				Name();
	
	///> Set a name for the project
			void				SetName(const char* name);
	
protected:
								ProjectManager();

private:
	static	ProjectManager*		fInstance;
			bool				fUpdated;
    		BPath				fPath;
    		char				fName[512];
};

#endif
