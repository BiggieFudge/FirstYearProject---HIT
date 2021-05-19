
// OOP_ProjectDlg.h : header file
//

#pragma once
#include "CONTROLS.h"
#include "Show_All.h"
#include "Shape.h"


#define SquareSide 40//constant grid length


// COOPProjectDlg dialog
class COOPProjectDlg : public CDialogEx
{
	
// Construction
public:
	COOPProjectDlg(CWnd* pParent = nullptr);	// standard constructor
	~COOPProjectDlg()
	{
		
		int i,j=0;

		for (i = 0; i < m_controls.m_TAB1.CurrentPose_shape; i++)//deleting info labels array
		{
		    
			for(j=0; j < arr_sizes[i]; j++)
			{
				delete(arr_labels[i][j]);
			}
			delete[] arr_labels[i];
		}

		list <Shape*>::iterator it;
		for(it=m_controls.m_TAB1.ShapeList.begin();it != m_controls.m_TAB1.ShapeList.end();it++){//deleting shape array

			delete(*it);
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
	
	
	COLORREF arr_color[5] = { RGB(255,0,0),RGB(0,255,0),RGB(0,0,255),RGB(255,128,0),RGB(255,255,0)};//array containing colors for shapes
	
	CStatic** arr_labels[5];//array of labels for info//delete me!!!!
	int arr_sizes[5];//saves sizes of inner arrays in arr_labels

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	
	DECLARE_MESSAGE_MAP()
	
public:

	void INFOPoly(list <Shape*> ::iterator indexS, list <Poligon*> ::iterator indexP);//shows info about polygon
	void INFOCircleC(list <Shape*> ::iterator indexS, list <Circle*> ::iterator indexC);//shows info about circle
	void INFOCircleE(list <Shape*> ::iterator indexS, list <ellipse*> ::iterator indexE);//shows info about ellipse
	void INFOCircleP(list <Shape*> ::iterator indexS, list <pie*> ::iterator indexP);//shows info about pie

	
	CONTROLS m_controls; //Show/Hide CONTROLS DIALOG
	afx_msg void OnBnClickedButton1();
	
	
	
};
