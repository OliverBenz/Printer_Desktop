#pragma once

#include <wx/wx.h>
#include "cMain.hpp"

class cApp: public wxApp{
	cMain* frameMain = nullptr;

public: 
	cApp();
	~cApp();

	virtual bool OnInit();
};

