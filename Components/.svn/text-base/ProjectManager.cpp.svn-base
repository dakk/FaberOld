/*
 * Copyright 2011 Davide Gessa. All rights reserved.
 * Distributed under the terms of the MIT License for non commercial use.
 *
 * Authors:
 *		Davide Gessa, dak.linux@gmail.com
 */
#include <string.h>
#include "ProjectManager.h"


ProjectManager* ProjectManager::fInstance = NULL;


ProjectManager::ProjectManager()
{
	fUpdated = false;
	fPath = "";
}

ProjectManager::~ProjectManager()
{
}


ProjectManager* ProjectManager::Instance()
{
	if(fInstance != NULL)
		return fInstance;

	fInstance = new ProjectManager();
	return fInstance;
}


void ProjectManager::New()
{
	fUpdated = true;
	strcpy(fName, "Untitled");
	fUpdated = true;
}


void ProjectManager::Close()
{
	fUpdated = false;
	fPath = "";
}


bool ProjectManager::IsUpdated()
{
	return fUpdated;
}


BPath ProjectManager::Path()
{
	return fPath;
}


void ProjectManager::SetPath(BPath path)
{
	fPath = path;	
	fUpdated = true;
}



bool ProjectManager::Load()
{
	if(fPath == "")
		return false;
	
	
	fUpdated = false;
	return true;	
}


bool ProjectManager::Save()
{
	if(fPath == "")
		return false;	
		
	fUpdated = false;
	return true;
}


const char* ProjectManager::Name()
{
	return fName;	
}


void ProjectManager::SetName(const char* name)
{
	strcpy(fName, name);
	fUpdated = true;	
}
