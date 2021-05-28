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

	CTabCtrl* pTabCtrl2 = (CTabCtrl*)GetDlgItem(IDC_TAB);
	m_TAB2.Create(IDD_TAB2, pTabCtrl2);// TAB2 Connection

	CTabCtrl* pTabCtrl3 = (CTabCtrl*)GetDlgItem(IDC_TAB);
	m_TAB3.Create(IDD_TAB3, pTabCtrl3);// TAB3 Connection

	TCITEM item1, item2, item3;

	//choosing name for tab
	item1.mask = TCIF_TEXT | TCIF_PARAM;  
	item1.lParam = (LPARAM)&m_TAB1;
	item1.pszText = _T("Add new Shape");
	pTabCtrl->InsertItem(0, &item1);      

	item2.mask = TCIF_TEXT | TCIF_PARAM;
	item2.lParam = (LPARAM)&m_TAB2;
	item2.pszText = _T("Remove Shape");
	pTabCtrl2->InsertItem(1, &item2);

	item3.mask = TCIF_TEXT | TCIF_PARAM;
	item3.lParam = (LPARAM)&m_TAB3;
	item3.pszText = _T("Edit Shape");
	pTabCtrl3->InsertItem(2, &item3);

	CRect rcItem1, rcItem2,rcItem3;

	//choosing position/visibilty for tab
	pTabCtrl->GetItemRect(0, &rcItem1);
	m_TAB1.SetWindowPos(NULL, rcItem1.left, rcItem1.bottom + 1, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	m_TAB1.ShowWindow(SW_SHOW);

	pTabCtrl2->GetItemRect(0, &rcItem2);
	m_TAB2.SetWindowPos(NULL, rcItem2.left, rcItem2.bottom + 1, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	m_TAB2.ShowWindow(SW_HIDE); // Hide by default every page that is not 1;

	pTabCtrl3->GetItemRect(0, &rcItem3);
	m_TAB3.SetWindowPos(NULL, rcItem3.left, rcItem3.bottom + 1, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	m_TAB3.ShowWindow(SW_HIDE); // Hide by default every page that is not 1;
	//END TAB CONTROL


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
		m_TAB2.ShowWindow(SW_HIDE);
		m_TAB3.ShowWindow(SW_HIDE);
	}
	else if (iSel == 1)// Second Tab Chosen
	{
		m_TAB2.ShowWindow(SW_SHOW);
		m_TAB1.ShowWindow(SW_HIDE);
		m_TAB3.ShowWindow(SW_HIDE);
	}
	else {  //Third Tab
		m_TAB3.ShowWindow(SW_SHOW);
		m_TAB2.ShowWindow(SW_HIDE);
		m_TAB1.ShowWindow(SW_HIDE);
	}
	//ADD new TAB here!
}
//END TAB CONTROL
