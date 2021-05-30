
// OOP_ProjectDlg.h : header file
//

#pragma once
#include "Shape.h"
#include "CONTROLS.h"
#include "EDIT.h"
#include <string.h>


#define SquareSide 40//constant grid length


// COOPProjectDlg dialog
class COOPProjectDlg : public CDialogEx
{
	
// Construction
public:
	COOPProjectDlg(CWnd* pParent = nullptr);	// standard constructor
	~COOPProjectDlg()
	{
		
		delete_arr_labels();

		DeleteScreen();

		

		
		
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
	bool arr_check_color[5] = {false,false,false,false,false};
	
	CStatic** arr_labels[5];//array of labels for info
	int arr_sizes[5];//saves sizes of inner arrays in arr_labels

	
	HICON RemoveIcon = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON2), IMAGE_ICON, 32, 32, 0);
	HICON EditIcon = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON3), IMAGE_ICON, 32, 32, 0);
	
	
	CButton* arr_Btn[5];

	CButton* arr_EditBtn[5];
	
	//CStatic* label_x = new CStatic[20];//number labels on x axis
	//CStatic* label_y = new CStatic[20];//number labels on y axis

	CStatic* label_x;//number labels on x axis
	CStatic* label_y;//number labels on y axis


	
	//iterators for shapes
	list <Shape*> ::iterator shape_it;
	list <Poligon*> ::iterator poly_it ;
	list <Circle*> ::iterator circle_it;
	list <ellipse*> ::iterator ellipse_it;
	list <pie*> ::iterator pie_it;




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
	void delete_shape(int pos_in_shape);//deleting selected shape
	void delete_arr_labels();
	void edit_func(int);//edit selected shape
	void delete_buttons();
	

	afx_msg void RemoveShape1() { delete_shape(0); }//deleting shape 1
	afx_msg void RemoveShape2() { delete_shape(1); };//deleting shape 2
	afx_msg void RemoveShape3() { delete_shape(2); };//deleting shape 3
	afx_msg void RemoveShape4() { delete_shape(3); };//deleting shape 4
	afx_msg void RemoveShape5() { delete_shape(4); };//deleting shape 5

	afx_msg void EditShape1() { edit_func(1); }//editing shape 1
	afx_msg void EditShape2() { edit_func(2); }//editing shape 2
	afx_msg void EditShape3() { edit_func(3); }//editing shape 3
	afx_msg void EditShape4() { edit_func(4); }//editing shape 4
	afx_msg void EditShape5() { edit_func(5); }//editing shape 5

	



	
	CONTROLS m_controls; //Show/Hide CONTROLS DIALOG
	afx_msg void OnBnClickedButton1();
	
	afx_msg void OnBnClickedSave();
	afx_msg void OnBnClickedLoad();


	void SaveCircle(CFileDialog&);
	void LoadCircle(CFileDialog&);
	void SaveEllipse(CFileDialog&);
	void LoadEllipse(CFileDialog&);
	void SavePoli(CFileDialog&);
	void LoadPoli(CFileDialog&);
	void SavePie(CFileDialog&);
	void LoadPie(CFileDialog&);

	
	void DeleteScreen();//delete shape list and buttons

};
