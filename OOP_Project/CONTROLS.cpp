// CONTROLS.cpp : implementation file
//

#include "pch.h"
#include "OOP_Project.h"
#include "CONTROLS.h"
#include "afxdialogex.h"



// CONTROLS dialog

IMPLEMENT_DYNAMIC(CONTROLS, CDialogEx)

BOOL CONTROLS::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	MoveWindow(1600, 350, 270, 430);
	//TAB CONTROL
	CTabCtrl* pTabCtrl = (CTabCtrl*)GetDlgItem(IDC_TAB);
	m_TAB1.Create(IDD_TAB1, pTabCtrl);  // TAB1 Connection


	TCITEM item1;

	//choosing name for tab
	item1.mask = TCIF_TEXT | TCIF_PARAM;  
	item1.lParam = (LPARAM)&m_TAB1;
	item1.pszText = _T("Add new Shape");
	pTabCtrl->InsertItem(0, &item1);      


	CRect rcItem1;

	//choosing position/visibilty for tab
	pTabCtrl->GetItemRect(0, &rcItem1);
	m_TAB1.SetWindowPos(NULL, rcItem1.left, rcItem1.bottom + 1, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	m_TAB1.ShowWindow(SW_SHOW);



	return TRUE;//must return true!!!!
}


CONTROLS::CONTROLS(CWnd* pParent /*=nullptr*/): CDialogEx(IDD_CONTROLS, pParent)
{
  
}

CONTROLS::~CONTROLS()
{
    //calling for the function deleting text boxes for input points in polygon 
	m_TAB1.delete_buttons();
	//calling for the function deleting text boxes for input points in circle
	m_TAB1.delete_circle_textbox();

}

void CONTROLS::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB, m_tabc);
}


BEGIN_MESSAGE_MAP(CONTROLS, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, AFX_ID_PREVIEW_PREV, &CONTROLS::OnTcnSelchangeIdPreviewPrev)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &CONTROLS::OnSelchangeTabcontrol)
END_MESSAGE_MAP()


//TAB CONTROL
void CONTROLS::OnTcnSelchangeIdPreviewPrev(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

void CONTROLS::OnSelchangeTabcontrol(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;

	int iSel = m_tabc.GetCurSel();

	if (iSel == 0) // First Tab Chosen
	{
		m_TAB1.ShowWindow(SW_SHOW);
		
	}
	
}
//END TAB CONTROL
