// Show_All.cpp : implementation file
//

#include "pch.h"
#include "OOP_Project.h"
#include "Show_All.h"
#include "afxdialogex.h"


// Show_All dialog

IMPLEMENT_DYNAMIC(Show_All, CDialogEx)

Show_All::Show_All(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Show_All, pParent)
{

}

Show_All::~Show_All()
{
}

void Show_All::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Show_All, CDialogEx)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// Show_All message handlers
HBRUSH Show_All::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)  //Set Background
{
	return (HBRUSH)GetStockObject(DC_BRUSH);
}