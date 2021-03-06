// EDIT.cpp : implementation file
//

#include "pch.h"
#include "OOP_Project.h"
#include "EDIT.h"
#include "afxdialogex.h"
#define SquareSide 40

// EDIT dialog

IMPLEMENT_DYNAMIC(EDIT, CDialogEx)

EDIT::EDIT(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EDIT, pParent)
{

}
EDIT::EDIT(int amount,string type,CWnd* pParent /*=nullptr*/) 
	: CDialogEx(IDD_EDIT, pParent) {
	TextBoxAmount = amount;
	this->type = type;

}

EDIT::~EDIT()
{
	if (CreatePoly) {
		deletePoly();
	}
	else if (CreateCir) {
		deleteCir();
	}
	else if (CreateEll) {
		deleteEll();
	}
	else {
		deletePie();
	}
}

BOOL EDIT::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	create_text_boxes();
	return TRUE;
}

void EDIT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(EDIT, CDialogEx)
	ON_BN_CLICKED(IDOK, &EDIT::OnBnClickedOk)
END_MESSAGE_MAP()


// EDIT message handlers


void EDIT::create_text_boxes()
{
   if(type=="Polygon")
   {
        PolyX = new CEdit[8];              
		PolyY = new CEdit[8];    
		Polylabel = new CStatic[8]; 
		
		int y = 20;
		int x = 25;
		for (int i = 0; i < TextBoxAmount; i++) 
		{
			if (i == 4) { 
				x = 120; y = 20;
				
				CRect rect;
				GetWindowRect(&rect);
				MoveWindow(rect.left, rect.top, 220, rect.Height(),1);
				
			}

			CString NumToDisplay;  NumToDisplay.Format(_T("%d"), i+1);
			PolyX[i].Create(ES_MULTILINE | WS_CHILD  | WS_TABSTOP | WS_BORDER | WS_VISIBLE,
				CRect(x, y, x + 25, y + 20), this, 8888);
			PolyY[i].Create(ES_MULTILINE | WS_CHILD  | WS_TABSTOP | WS_BORDER| WS_VISIBLE,
				CRect(x + 45, y, x + 70, y + 20), this, 8888);
			Polylabel[i].Create(NumToDisplay, WS_CHILD | WS_VISIBLE,
				CRect(x - 10, y, x, y + 20), this);


			y += 35;
		}
		CreatePoly = 1;
   }
   else if(type=="CircleC"){

	   CircleTextBox = new CEdit[3];
	   CircleTextBoxLabels = new CStatic[4];
	   CircleTextBoxLabels[0].Create(_T("Enter Center Point:"), WS_CHILD | WS_VISIBLE,
		   CRect(10, 0, 150, 30), this);

	   CircleTextBoxLabels[1].Create(_T("x:"), WS_CHILD | WS_VISIBLE,
		   CRect(15, 30, 30, 60), this);

	   CircleTextBoxLabels[2].Create(_T("y:"), WS_CHILD | WS_VISIBLE,
		   CRect(70, 30, 85, 60), this);

	   CircleTextBoxLabels[3].Create(_T("Radius:"), WS_CHILD | WS_VISIBLE,
		   CRect(15, 60, 70, 90), this);

	   CircleTextBox[0].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		   CRect(30, 30, 55, 50), this, 8888);	//input x textbox


	   CircleTextBox[1].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		   CRect(90, 30, 115, 50), this, 8888);//input y textbox


	   CircleTextBox[2].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		   CRect(77, 60, 110, 80), this, 8888);//input radious textbox
	   CreateCir = 1;
   }
   else if(type=="CircleP") {
	   PieTextBox = new CEdit[7];
	   PieTextBoxLabels = new CStatic[6];


	   int y = 0;

	   PieTextBoxLabels[0].Create(_T("Enter Center Point:"), WS_CHILD | WS_VISIBLE,
		   CRect(25, y, 250, 32), this);

	   PieTextBoxLabels[1].Create(_T("x:"), WS_CHILD | WS_VISIBLE,
		   CRect(15,y+22, 30, y+52), this);

	   PieTextBoxLabels[2].Create(_T("y:"), WS_CHILD | WS_VISIBLE,
		   CRect(80,y+22, 95, y+52), this);

	   PieTextBoxLabels[3].Create(_T("Radius:"), WS_CHILD | WS_VISIBLE,
		   CRect(15, y+52, 80, y+82), this);

	   PieTextBox[0].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		   CRect(30, y+22, 55, y+42), this, 8888);	//input x textbox


	   PieTextBox[1].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		   CRect(100, y+22, 125, y+42), this, 8888);//input y textbox


	   PieTextBox[2].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		   CRect(77, y+52, 110, y+72), this, 8888);//input radious textbox


	   PieTextBoxLabels[4].Create(_T("Enter Start Angle:"), WS_CHILD | WS_VISIBLE,
		   CRect(17, y+72, 200, y+92), this);

	   PieTextBox[3].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		   CRect(30, y+92, 55, y+112), this, 8888);

	   PieTextBox[4].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		   CRect(70, y+92, 95, y+112), this, 8888);


	   PieTextBoxLabels[5].Create(_T("Enter End Angle:"), WS_CHILD | WS_VISIBLE,
		   CRect(17, y+112, 200, y+142), this);

	   PieTextBox[5].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		   CRect(30, y+142, 55, y+162), this, 8888);

	   PieTextBox[6].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		   CRect(70, y+142, 95, y+162), this, 8888);
   }
   else
   {
	   EllipseTextBox = new CEdit[4];
	   EllipseTextBoxLabels = new CStatic[6];

	   EllipseTextBoxLabels[0].Create(_T("Enter Left Bottom:"), WS_CHILD | WS_VISIBLE,
		   CRect(17, 5, 200, 30), this);

	   EllipseTextBoxLabels[1].Create(_T("x:"), WS_CHILD | WS_VISIBLE,
		   CRect(17, 30, 30, 50), this);

	   EllipseTextBox[0].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		   CRect(30, 30, 55, 50), this, 8888);

	   EllipseTextBoxLabels[2].Create(_T("y:"), WS_CHILD | WS_VISIBLE,
		   CRect(57, 30, 70, 50), this);
	   EllipseTextBox[1].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		   CRect(70, 30, 95, 50), this, 8888);


	   EllipseTextBoxLabels[3].Create(_T("Enter Right Top:"), WS_CHILD | WS_VISIBLE,
		   CRect(17, 50, 200, 70), this);
	   EllipseTextBoxLabels[4].Create(_T("x:"), WS_CHILD | WS_VISIBLE,
		   CRect(17, 70, 30, 90), this);
	   EllipseTextBox[2].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		   CRect(30, 70, 55, 90), this, 8888);
	   EllipseTextBoxLabels[5].Create(_T("y:"), WS_CHILD | WS_VISIBLE,
		   CRect(57, 70, 70, 90), this);
	   EllipseTextBox[3].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		   CRect(70, 70, 95, 90), this, 8888);
	   CreateEll = 1;
   }


}





void EDIT::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	
	if (type == "Polygon" && !PolyInputItegrity()) {
		
		CDialogEx::OnCancel();
	}
	else if (type == "CircleC" && !CirInputItegrity()) {
	
		CDialogEx::OnCancel();
	}
	else if (type == "CircleE" && !EllInputItegrity()) {
		
		CDialogEx::OnCancel();
	}
	else if(type =="CircleP" && !PieInputItegrity()) {
	
		CDialogEx::OnCancel();
	}
	else {
		CDialogEx::OnOK();
		CString str;
		if (type == "Polygon") {

			double x, y;
			POINT* PointArray = new POINT[TextBoxAmount];
			POINT* On_Screen = new POINT[TextBoxAmount];
			for (int i = 0; i < this->TextBoxAmount; i++) {
				PolyX[i].GetWindowTextW(str);     //Take Data from textbox
				PolyX[i].SetWindowTextW(_T("")); // Reset TextBox
				x = _tstof(str);  //Convert from Cstring to double
				PolyY[i].GetWindowTextW(str);   //Take Data from textbox
				PolyY[i].SetWindowTextW(_T("")); // Reset TextBox
				y = _tstof(str);  //Convert from Cstring to double
				PointArray[i].x = (double)x * 10;  // CASTING TO DOUBLE
				PointArray[i].y = (double)y * 10;   // CASTING TO DOUBLE
				On_Screen[i].x = ((double)x + 10) * SquareSide + SquareSide;  //ETN maths
				On_Screen[i].y = (10 - (double)y) * SquareSide + SquareSide;     //ETN maths
			}
			poly_ptr = new Poligon(On_Screen, PointArray, TextBoxAmount);





			


			delete[] PointArray;
			delete[] On_Screen;
		}

		else if (type == "CircleC") {

			CircleTextBox[2].GetWindowTextW(str);   //Get radius user entered
			CircleTextBox[2].SetWindowTextW(_T("")); // Reset TextBox
			double rad = _tstof(str);
			POINT p1;
			POINT* p2 = new POINT[2];
			CircleTextBox[0].GetWindowTextW(str);
			CircleTextBox[0].SetWindowTextW(_T(""));// Reset TextBox
			p1.x = _tstof(str) * 10; // CASTING TO DOUBLE
			p2[0].x = ((_tstof(str) - rad) + 10) * SquareSide + SquareSide;
			p2[1].x = ((_tstof(str) + rad) + 10) * SquareSide + SquareSide;
			CircleTextBox[1].GetWindowTextW(str);
			CircleTextBox[1].SetWindowTextW(_T(""));// Reset TextBox
			p1.y = _tstof(str) * 10; // CASTING TO DOUBLE
			p2[0].y = (10 - (_tstof(str) - rad)) * SquareSide + SquareSide;
			p2[1].y = (10 - (_tstof(str) + rad)) * SquareSide + SquareSide;



			circle_ptr = new Circle(p1, p2, rad);

			
			delete[] p2;
		}


		else if (type == "CircleP") {


			POINT center;


			POINT* p2 = new POINT[2];//rect points

			POINT p3;//start point

			POINT* p4 = new POINT[2];

			POINT p5;  //end point


			PieTextBox[0].GetWindowTextW(str);
			PieTextBox[0].SetWindowTextW(_T(""));// Reset TextBox
			center.x = _tstof(str) * 10; // CASTING TO DOUBLE




			PieTextBox[1].GetWindowTextW(str);
			PieTextBox[1].SetWindowTextW(_T(""));// Reset TextBox
			center.y = _tstof(str) * 10; // CASTING TO DOUBLE




			PieTextBox[2].GetWindowTextW(str);
			PieTextBox[2].SetWindowTextW(_T(""));// Reset TextBox
			double radius = _tstof(str); // CASTING TO DOUBLE

			p2[0].x = ((center.x / 10 + radius) + 10) * SquareSide + SquareSide;
			p2[0].y = (10 - (center.y / 10 + radius)) * SquareSide + SquareSide;
			p2[1].x = ((center.x / 10 - radius) + 10) * SquareSide + SquareSide;
			p2[1].y = (10 - (center.y / 10 - radius)) * SquareSide + SquareSide;


			PieTextBox[3].GetWindowTextW(str);
			PieTextBox[3].SetWindowTextW(_T(""));// Reset TextBox
			p3.x = _tstof(str) * 10; // CASTING TO DOUBLE
			p4[0].x = ((_tstof(str)) + 10) * SquareSide + SquareSide;
			PieTextBox[4].GetWindowTextW(str);
			PieTextBox[4].SetWindowTextW(_T(""));// Reset TextBox
			p3.y = _tstof(str) * 10; // CASTING TO DOUBLE
			p4[0].y = (10 - (_tstof(str))) * SquareSide + SquareSide;



			PieTextBox[5].GetWindowTextW(str);
			PieTextBox[5].SetWindowTextW(_T(""));// Reset TextBox
			p5.x = _tstof(str) * 10; // CASTING TO DOUBLE
			p4[1].x = ((_tstof(str)) + 10) * SquareSide + SquareSide;

			PieTextBox[6].GetWindowTextW(str);
			PieTextBox[6].SetWindowTextW(_T(""));// Reset TextBox
			p5.y = _tstof(str) * 10;// CASTING TO DOUBLE
			p4[1].y = (10 - (_tstof(str))) * SquareSide + SquareSide;


			pie_ptr = new pie(center, p2, radius, p3, p5, p4);

			delete[] p2;
			delete[] p4;

		}
		else if (type == "CircleE") {


			POINT p1;

			POINT* p2 = new POINT[2];

			POINT p3;
			EllipseTextBox[0].GetWindowTextW(str);
			EllipseTextBox[0].SetWindowTextW(_T(""));// Reset TextBox
			p1.x = _tstof(str) * 10; // CASTING TO DOUBLE
			p2[0].x = ((_tstof(str)) + 10) * SquareSide + SquareSide;

			EllipseTextBox[1].GetWindowTextW(str);
			EllipseTextBox[1].SetWindowTextW(_T(""));// Reset TextBox
			p1.y = _tstof(str) * 10; // CASTING TO DOUBLE
			p2[0].y = (10 - (_tstof(str))) * SquareSide + SquareSide;



			EllipseTextBox[2].GetWindowTextW(str);
			EllipseTextBox[2].SetWindowTextW(_T(""));// Reset TextBox
			p3.x = _tstof(str) * 10; // CASTING TO DOUBLE
			p2[1].x = ((_tstof(str)) + 10) * SquareSide + SquareSide;

			EllipseTextBox[3].GetWindowTextW(str);
			EllipseTextBox[3].SetWindowTextW(_T(""));// Reset TextBox
			p3.y = _tstof(str) * 10;// CASTING TO DOUBLE
			p2[1].y = (10 - (_tstof(str))) * SquareSide + SquareSide;


			ellipse_ptr = new ellipse(p1, p3, p2);

			delete[] p2;

		
		}
	}
}

bool EDIT::PolyInputItegrity() {
	CString str;
	for (int i = 0; i < this->TextBoxAmount; i++) {//checking poly input
		PolyX[i].GetWindowTextW(str);
		if (_tstof(str) < -10 || _tstof(str) > 10) {
			CleanInput();
			MessageBox(_T("Invalid input"), _T("ERROR"), MB_OK);
			return FALSE;
		}

		PolyY[i].GetWindowTextW(str);
		if (_tstof(str) < -10 || _tstof(str) > 10) {
			CleanInput();
			MessageBox(_T("Invalid input"), _T("ERROR"), MB_OK);
			return FALSE;
		}

	}
	return TRUE;
}

bool EDIT::CirInputItegrity() {
	CString str, str2, str3;
	CircleTextBox[0].GetWindowTextW(str);
	CircleTextBox[1].GetWindowTextW(str2);
	CircleTextBox[2].GetWindowTextW(str3);
	if (str3 == "") {
		CleanInput();
		MessageBox(_T("Invalid input"), _T("ERROR"), MB_OK);
		return FALSE;
	}
	if ((_tstof(str) < -10 || _tstof(str) > 10) || (_tstof(str2) < -10 || _tstof(str2) > 10) || (_tstof(str) + _tstof(str3) < -10 || _tstof(str) + _tstof(str3) > 10 || _tstof(str2) + _tstof(str3) < -10 || _tstof(str2) + _tstof(str3) > 10) || _tstof(str3) < 0) {

		CleanInput();
		MessageBox(_T("Invalid input"), _T("ERROR"), MB_OK);
		return FALSE;
	}
	return TRUE;
}


bool EDIT::EllInputItegrity() {
	CString str;
	for (int i = 0; i < 4; i++) {
		EllipseTextBox[i].GetWindowTextW(str);
		if (_tstof(str) < -10 || _tstof(str) > 10) {
			CleanInput();
			MessageBox(_T("Invalid input"), _T("ERROR"), MB_OK);
			return FALSE;
		}
	}
	return TRUE;
}


bool EDIT::PieInputItegrity() {
	CString str,str2,str3;

	PieTextBox[0].GetWindowTextW(str);
	PieTextBox[1].GetWindowTextW(str2);
	PieTextBox[2].GetWindowTextW(str3);
	if (str3 == "") {
		CleanInput();
		MessageBox(_T("Invalid input"), _T("ERROR"), MB_OK);
		return FALSE;
	}
	if ((_tstof(str) < -10 || _tstof(str) > 10) || (_tstof(str2) < -10 || _tstof(str2) > 10) || (_tstof(str) + _tstof(str3) < -10 || _tstof(str) + _tstof(str3) > 10 || _tstof(str2) + _tstof(str3) < -10 || _tstof(str2) + _tstof(str3) > 10) || _tstof(str3) < 0) {

		CleanInput();
		MessageBox(_T("Invalid input"), _T("ERROR"), MB_OK);
		return FALSE;
	}

	for (int i = 3; i < 7; i++) {//Check input itegrity for pie
		PieTextBox[i].GetWindowTextW(str);
		if (_tstof(str) < -10 || _tstof(str) > 10) {
			CleanInput();
			MessageBox(_T("Invalid input"), _T("ERROR"), MB_OK);
			return FALSE;
		}

	}
	return TRUE;

	
}


void EDIT::CleanInput() {//clean all the input
	if (type== "Polygon") {
		for (int i = 0; i < this->TextBoxAmount; i++) {
			PolyX[i].SetWindowTextW(_T(""));
			PolyY[i].SetWindowTextW(_T(""));
		}
	}
	else if (type == "CircleC") {
		for (int i = 0; i < 3; i++) {
			CircleTextBox[i].SetWindowTextW(_T(""));
		}
	}
	else if (type == "CircleE") {
		for (int i = 0; i < 4; i++) {
			EllipseTextBox[i].SetWindowTextW(_T(""));
		}
	}
	else {
		for (int i = 0; i < 7; i++) {
			PieTextBox[i].SetWindowTextW(_T(""));
		}
	}

}

void EDIT::deletePoly() {
	delete[] PolyX;
	delete[] PolyY;
	delete[] Polylabel;

}

void EDIT::deleteCir() {
	delete[] CircleTextBox;
	delete[] CircleTextBoxLabels;

}
void EDIT::deleteEll() {
	delete[] EllipseTextBox;
	delete[] EllipseTextBoxLabels;

}
void EDIT::deletePie() {

	delete[] PieTextBox;
	delete[] PieTextBoxLabels;
}
