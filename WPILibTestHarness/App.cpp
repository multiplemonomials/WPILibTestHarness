/*
    WPILib Test Harness
    Copyright (C) 2009 Dustin Spicuzza <dustin@virtualroadside.com>
	
	$Id: App.cpp 304 2009-03-14 09:31:05Z dspicuzz $

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License v3 as published by
    the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <wx/wx.h>
#include <wx/xrc/xmlres.h>
#include <wx/mstream.h>

#ifdef USE_MSVC_MEMORY_TRACING
	// this enables advanced memory leak detection
	#include <wx/msw/msvcrt.h>
#endif


#include "SimulationWindow.h"
#include "LogMacros.h"

class MyApp : public wxApp
{
public:
	virtual bool OnInit();

	void OnClose(wxCloseEvent &event);

private:

};

//from http://forums.wxwidgets.org/viewtopic.php?f=1&t=15574
std::string wx2std(const wxString& input)
{
	if (input.empty())
	   return "";
	return std::string(input.mb_str(*wxConvCurrent));
}

wxString std2wx(const std::string& input)
{
	if (input.empty())
	   return wxT("");
	return wxString(input.c_str(), wxConvCurrent);
}

IMPLEMENT_APP_CONSOLE(MyApp);

bool MyApp::OnInit()
{
	// initialize XRC
	wxXmlResource::Get()->InitAllHandlers();
    
	wxString errorMessage;
	
	static wxString wxEndl = wxT("\n");
	
	errorMessage << wxT("WPILibTestHarness.xrc was not found! This file must be in the current working directory or this program cannot execute!") << wxEndl;
	
	// try and find the silly xrc file
	wxFileName file(wxGetCwd());
	file.SetFullName(wxT("WPILibTestHarness.xrc"));
	errorMessage << wxT("Looking for XRC file at location ") << file.GetPath() << wxEndl;
	
	
	if (!file.IsFileReadable() || 
		!wxXmlResource::Get()->Load(file.GetFullPath()))
	{

		// try going up
		file.AppendDir(wxT("WPILibTestHarness"));
		
		errorMessage << wxT("Looking for XRC file at location ") << file.GetPath() << wxEndl;

		if (!file.IsFileReadable() || 
			!wxXmlResource::Get()->Load(file.GetFullPath()))
		{

			// try going back a dir
			file.RemoveLastDir();
			file.RemoveLastDir();
			file.AppendDir(wxT("WPILibTestHarness"));
			
			errorMessage << wxT("Looking for XRC file at location ") << file.GetPath() << wxEndl;

			if (!file.IsFileReadable() || 
				!wxXmlResource::Get()->Load(file.GetFullPath()))
			{

				// try the *nix install dir
				file.Assign(wxT("/usr/share/WPILibTestHarness/WPILibTestHarness.xrc"));

				if (!file.IsFileReadable() || 
					!wxXmlResource::Get()->Load(file.GetFullPath()))
				{
				
					errorMessage << wxT("Looking for XRC file at location ") << file.GetPath() << wxEndl;
				
					wxMessageBox(errorMessage, wxT("Error finding XRC file"));
					return false;
				}
			}
		}
	}	

	// create the window
	SimulationWindow * simulationWindow = new SimulationWindow(NULL);
	simulationWindow->Show();

	return true;
}

void MyApp::OnClose(wxCloseEvent &event)
{
	ExitMainLoop();
}

