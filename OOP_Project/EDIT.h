#pragma once
#include "Shape.h"
#include "Circle.h"
#include "Poligon.h"
#include "Pie.h"
#include "Ellipse.h"


// EDIT dialog

class EDIT : public CDialogEx
{
	DECLARE_DYNAMIC(EDIT)

public:
	EDIT(CWnd* pParent = nullptr);   // standard constructor
	EDIT(int,string,CWnd* pParent = nullptr);
	virtual ~EDIT();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EDIT };
#endif

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	
public:
	string type;
	int TextBoxAmount;


	Shape* shape_ptr;
	Poligon* poly_ptr;
	pie* pie_ptr;
	Circle* circle_ptr;
	ellipse* ellipse_ptr;

	int CreatePoly = 0;
	CEdit* PolyX;//TextBoxes for point input
	CEdit* PolyY;//TextBoxes for point input
	CStatic* Polylabel;//display point number labels

	int CreateCir = 0;
	CStatic* CircleTextBoxLabels; //Circle labels
	CEdit* CircleTextBox; //Input Circle shape
	
	int CreateEll = 0;
	CStatic* EllipseTextBoxLabels;
	CEdit* EllipseTextBox;

	int CreatePie = 0;
	CStatic* PieTextBoxLabels;
	CEdit* PieTextBox;


	//create text box
	void create_text_boxes();

	//checking input 
	bool PolyInputItegrity();
	bool CirInputItegrity();
	bool EllInputItegrity();
	bool PieInputItegrity();
	void CleanInput();

	//deleting buttons
	void deletePoly();
	void deleteCir();
	void deleteEll();
	void deletePie();

	afx_msg void OnBnClickedOk();
};
