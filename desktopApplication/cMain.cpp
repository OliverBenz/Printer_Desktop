#include "cMain.hpp"
#include <fstream>

void filterListNames(cMain* cmain, wxString filter);

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	// EVT_BUTTON(10001, OnFilterUpdate)
	EVT_TEXT(10002, OnFilterUpdate)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Main Window", wxPoint(50,50), wxSize(800, 600)){
	// Create Elements
	//searchButton = new wxButton(this, 10001, "Click Here", wxPoint(10, 10), wxSize(150, 50));
	searchField = new wxTextCtrl(this, 10002, "", wxPoint(10, 10), wxSize(300, 30));
	printList = new wxListBox(this, wxID_ANY, wxPoint(10, 50), wxSize(300, 300));
	
	// Set Font
	wxFont font(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);
	
	//searchButton->SetFont(font);
	searchField->SetFont(font);
	printList->SetFont(font);
	
	searchField->SetHint("Search prints..");

	// Read Prints from file
	readFile();
	
	// Add Filenames to list
	for (size_t i = 0; i < prints.size(); i++)
		printList->Append(prints[i].getPrintName());
	

	db = new dbHelper();
	wxMessageBox(db->getNameOne(), "");
}

cMain::~cMain() {
	delete searchButton;
	delete searchField;
	delete printList;
}

void cMain::readFile() {
	std::ifstream file("res/prints.csv");

	if (file.is_open()) {
		std::string line;
		while (getline(file, line))
			prints.push_back(Print(line));
		file.close();
	}
	else wxMessageBox("Could not open file");
}

void cMain::OnFilterUpdate(wxCommandEvent& evt) {
	// TODO: Check if Enter or search button is clicked
	filterListNames(this, searchField->GetValue());
	
	evt.Skip();
}

// TODO:
// Right structure to pass this??? 
void filterListNames(cMain* cmain, wxString filter) {
	cmain->printList->Clear();

	for (size_t i = 0; i < cmain->prints.size(); i++)
		if (cmain->prints[i].getPrintName().find(filter) != std::string::npos) 
			cmain->printList->Append(cmain->prints[i].getPrintName());
}
