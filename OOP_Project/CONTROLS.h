#pragma once
#include "CTAB1.h"
#include "CTAB2.h"
#include "CTAB3.h"

// CONTROLS dialog

class CONTROLS : public CDialogEx
{
	DECLARE_DYNAMIC(CONTROLS)

public:
	CONTROLS(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CONTROLS();  //strandard

	

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONTROLS };
#endif

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	
	DECLARE_MESSAGE_MAP()
public:



	//TAB CONTROL
	CTabCtrl m_tabc;
	CTAB1 m_TAB1;
	CTAB2 m_TAB2;
	CTAB3 m_TAB3;
	afx_msg void OnTcnSelchangeIdPreviewPrev(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangeTabcontrol(NMHDR* pNMHDR, LRESULT* pResult);
	//END TAB CONTROL

};
