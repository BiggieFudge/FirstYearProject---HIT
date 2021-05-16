
// OOP_ProjectDlg.h : header file
//

#pragma once
#include "CONTROLS.h"
#include "Show_All.h"
#include "Shape.h"


#define SquareSide 35//constant grid length


// COOPProjectDlg dialog
class COOPProjectDlg : public CDialogEx
{
	
// Construction
public:
	COOPProjectDlg(CWnd* pParent = nullptr);	// standard constructor
	~COOPProjectDlg()
	{
		//delete(show_axis);
		delete(Page);

		int i;
		
		for(i=0;i<m_controls.m_TAB1.CurrentPose_shape;i++){//deleting shape array

			delete(m_controls.m_TAB1.ShapeArr[i]);
		}
		
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
	//AXIS* show_axis = new AXIS;
	Show_All* Page = new Show_All;
	
	COLORREF arr_color[5] = { RGB(255,0,0),RGB(0,255,0),RGB(0,0,255),RGB(255,128,0) };//array containing colors for shapes
	int index_shape = 0;//indicating at what index you are in ShapeArr
	


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
