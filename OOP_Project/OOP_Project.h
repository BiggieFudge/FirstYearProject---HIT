
// OOP_Project.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// COOPProjectApp:
// See OOP_Project.cpp for the implementation of this class
//

class COOPProjectApp : public CWinApp
{
public:
	COOPProjectApp();
	
// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern COOPProjectApp theApp;
