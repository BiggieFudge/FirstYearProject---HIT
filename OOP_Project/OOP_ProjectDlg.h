
// OOP_ProjectDlg.h : header file
//

#pragma once
#include "CONTROLS.h"
#include "Show_All.h"

// COOPProjectDlg dialog
class COOPProjectDlg : public CDialogEx
{
// Construction
public:
	COOPProjectDlg(CWnd* pParent = nullptr);	// standard constructor
	~COOPProjectDlg()
	{
		delete(show_axis);
		delete(Page);

	}
	

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OOP_PROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	AXIS* show_axis = new AXIS;
	Show_All* Page = new Show_All;
	
	
	


	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	
public:




	CONTROLS m_controls; //Show/Hide CONTROLS DIALOG
	afx_msg void OnBnClickedButton1();
	
};
