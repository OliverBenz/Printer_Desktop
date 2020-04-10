#include "cApp.hpp"

wxIMPLEMENT_APP(cApp);

cApp::cApp() {

}

cApp::~cApp() {

}

bool cApp::OnInit() {
	frameMain = new cMain();
	frameMain->Show();
	return true;
}