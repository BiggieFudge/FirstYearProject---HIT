// CONTROLS.cpp : implementation file
//

#include "pch.h"
#include "OOP_Project.h"
#include "CONTROLS.h"
#include "afxdialogex.h"


// CONTROLS dialog

IMPLEMENT_DYNAMIC(CONTROLS, CDialogEx)

CONTROLS::CONTROLS(CWnd* pParent /*=nullptr*/): CDialogEx(IDD_CONTROLS, pParent)
{

}

CONTROLS::~CONTROLS()
{
	
}

void CONTROLS::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CONTROLS, CDialogEx)
END_MESSAGE_MAP()


// CONTROLS message handlers
