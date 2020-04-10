#pragma once

#include <wx/wx.h>

#include "lib/Print.hpp"
#include "dbHelper.hpp"
#include <vector>

class cMain: public wxFrame{
	dbHelper* db = nullptr;

public:
	cMain();
	~cMain();

	wxButton* searchButton = nullptr;
	wxTextCtrl* searchField = nullptr;
	wxListBox* printList = nullptr;

	std::vector<Print> prints;
	
	void readFile();
	void OnFilterUpdate(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

