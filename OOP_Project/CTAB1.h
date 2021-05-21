#pragma once

#include "Shape.h"
#include "Poligon.h"
#include "Ellipse.h"
#include "Pie.h"
#include <list>

// CTAB1 dialog

class CTAB1 : public CDialogEx
{
	DECLARE_DYNAMIC(CTAB1)
	
public:
	CTAB1(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CTAB1();

	
	

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB1 };
#endif

protected:

	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()


public:

	list<Shape*> ShapeList;
	list<Poligon*> PolyList;
	list<Circle*> CircleList;
	list<Circle*> CircleCList;
	list<ellipse*> CircleEList;
	list<pie*> CirclePList;

	int CurrentPose_shape = 0;//amount of shapes right now
	int CurrentPose_poly = 0;//amount of polygons right now
	int CurrentPose_circle = 0;//amount of circles right now
	int CurrentPose_circle_c = 0;//amount of circles right now
	int CurrentPose_circle_e = 0;//amount of circles right now
	int CurrentPose_circle_p = 0;//amount of circles right now

	CComboBox m_comboBoxCtrl; // ComboBox 8 number

	CString m_strTextCtrl;//text in combo box
	

	

	CStatic IDC_XX2;//display x label
	CStatic IDC_YY2;//display y label
	CStatic IDC_XX;//display x label
	CStatic IDC_YY;//display y label
	
	


	bool CreatePoly = 0;//check if created textboxes and labels
	CEdit* PolyX;//TextBoxes for point input
	CEdit* PolyY;//TextBoxes for point input
	CStatic* Polylabel;//display point number labels


	//if chosen circle shape
	CStatic IDC_Circle_GroupV;


	//if chose circle
	bool CreateCircleC = 0;
	CStatic* CircleTextBoxLabels; //Circle labels
	CEdit* CircleTextBox; //Input Circle shape


	//if chose Ellipse
	bool CreateCircleE = 0;
	CStatic* EllipseTextBoxLabels;
	CEdit* EllipseTextBox;

	//if chose pie
	bool CreateCircleP = 0;
	CStatic* PieTextBoxLabels;
	CEdit* PieTextBox;

	bool isHidden = 0; //Used for knowing if Xtextbox and Ytextbox are shown or hidden

	int save_amount_points=-1;//amount of points selected in combo box (polygon)

	void Create_Poly();

	afx_msg void OnBnClickedPolygon();
	afx_msg void OnBnClickedCircle();

	afx_msg void OnCbnSelchangePoints();
	
	//creating circle shape
	afx_msg void Create_Circle_C();
	afx_msg void show_Circle_C();
	afx_msg void hide_Circle_C();

	//creating ellipse shape
	afx_msg void Create_Circle_E();
	afx_msg void show_Circle_E();
	afx_msg void hide_Circle_E();

	//creating pie shape
	afx_msg void Create_Circle_P();
	afx_msg void show_Circle_P();
	afx_msg void hide_Circle_P();

	//functions regarding circle categorie
	afx_msg void delete_circle_textbox();
	afx_msg void hide_Circle();
	afx_msg void show_Circle();

	//functions regarding polygon
	afx_msg void show_Poly();
	afx_msg void hide_Poly();
	afx_msg void delete_buttons();
	afx_msg void HideTextBoxes();
	afx_msg void ShowTextBoxes();
	
	
	afx_msg void OnBnClickedCircleC();
	afx_msg void OnBnClickedCircleE();
	afx_msg void OnBnClickedCircleP();
	afx_msg void OnBnClickedSend();

	afx_msg bool InputItegrity();
	afx_msg void CleanInput();
};
