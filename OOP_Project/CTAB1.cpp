// CTAB1.cpp : implementation file
//

#include "pch.h"
#include "OOP_Project.h"
#include "OOP_ProjectDlg.h"
#include "CTAB1.h"
#include "afxdialogex.h"



// CTAB1 dialog

IMPLEMENT_DYNAMIC(CTAB1, CDialogEx)

CTAB1::CTAB1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB1, pParent)
	, m_strTextCtrl(_T(""))
{

}  

CTAB1::~CTAB1()
{
	
}

void CTAB1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_Points, m_comboBoxCtrl);
	DDX_CBString(pDX, IDC_Points, m_strTextCtrl);
	DDX_Control(pDX, IDC_X, IDC_XX);
	DDX_Control(pDX, IDC_Y, IDC_YY);
	DDX_Control(pDX, IDC_X2, IDC_XX2);
	DDX_Control(pDX, IDC_Y2, IDC_YY2);
	DDX_Control(pDX, IDC_Circle_Group, IDC_Circle_GroupV);

}

BOOL CTAB1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//initalyzing combo box values 
	CString str;
	for (int i = 1; i<9; i++)
	{
	 str.Format(_T("%d"), i);
	 m_comboBoxCtrl.AddString(str);
	}

	return TRUE;
}


BEGIN_MESSAGE_MAP(CTAB1, CDialogEx)
	ON_BN_CLICKED(IDC_Polygon, &CTAB1::OnBnClickedPolygon)
	ON_BN_CLICKED(IDC_Circle, &CTAB1::OnBnClickedCircle)
	ON_CBN_SELCHANGE(IDC_Points, &CTAB1::OnCbnSelchangePoints)
	ON_CBN_SELCHANGE(IDC_Points, &CTAB1::OnCbnSelchangePoints)

	ON_BN_CLICKED(IDC_Circle_C, &CTAB1::OnBnClickedCircleC)
	ON_BN_CLICKED(IDC_Circle_E, &CTAB1::OnBnClickedCircleE)
	ON_BN_CLICKED(IDC_Circle_P, &CTAB1::OnBnClickedCircleP)
	ON_BN_CLICKED(IDC_Send, &CTAB1::OnBnClickedSend)
END_MESSAGE_MAP()


// CTAB1 message handlers




//check if clicked on polygon option
void CTAB1::OnBnClickedPolygon()
{
	// TODO: Add your control notification handler code here
	if ( IsDlgButtonChecked(IDC_Polygon) == BST_CHECKED )//if chosen poligon
	{
		hide_Circle();
		show_Poly();
		ShowTextBoxes();
		
	}
  
}
//display everything that is connected to poly
void CTAB1::show_Poly() {
	Create_Poly();
	
	GetDlgItem(IDC_Circle_Group)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_Circle_Group)->SetWindowTextW(_T("Poly Insert:"));

	GetDlgItem(IDC_label)->ShowWindow(SW_SHOW);

	GetDlgItem(IDC_Points)->ShowWindow(SW_SHOW);

	GetDlgItem(IDC_Send)->ShowWindow(SW_SHOW);

	
	
}
//hide everything that is connected to poly
void CTAB1::hide_Poly()
{
	GetDlgItem(IDC_X)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_Y)->ShowWindow(SW_HIDE);
	
	GetDlgItem(IDC_Bottom_Group)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_label)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_Points)->ShowWindow(SW_HIDE);   

}



void CTAB1::Create_Poly() {//creating poly textboxes and labels
	if (CreatePoly == 0) {   //Check if memory allocated
		PolyX = new CEdit[8];
		PolyY = new CEdit[8];
		Polylabel = new CStatic[8];
		
		int y = 180;
		int x = 25;
		for (int i = 0; i < 8; i++) {
			if (i == 4) { x = 120; y = 180; }

			CString NumToDisplay;  NumToDisplay.Format(_T("%d"), i+1);
			PolyX[i].Create(ES_MULTILINE | WS_CHILD  | WS_TABSTOP | WS_BORDER,
				CRect(x, y, x + 25, y + 20), this, 8888);
			PolyY[i].Create(ES_MULTILINE | WS_CHILD  | WS_TABSTOP | WS_BORDER,
				CRect(x + 45, y, x + 70, y + 20), this, 8888);
			Polylabel[i].Create(NumToDisplay, WS_CHILD ,
				CRect(x - 10, y, x, y + 20), this);


			y += 35;
		}
		CreatePoly = 1;    //Do not allocate more memory
	}

}


//deleting text boxes for input points in polygon
void CTAB1::delete_buttons()
{
	if (CreatePoly) {
		
		delete[] PolyX;
		delete[] PolyY;
		delete[] Polylabel;
	}
	
}
//deleting text boxes for input points in circle
void CTAB1::delete_circle_textbox()
{
	if(CreateCircleC==1){
		delete[] CircleTextBox;
		delete[] CircleTextBoxLabels;
	}

		
			
	if (CreateCircleE == 1) {
		delete[] EllipseTextBox;
		delete[] EllipseTextBoxLabels;
	}

			

	if (CreateCircleP == 1) {
		delete[] PieTextBox;
		delete[] PieTextBoxLabels;
	}

			
	
}



//check if clicked on circle categorie option
void CTAB1::OnBnClickedCircle()
{
	if ( IsDlgButtonChecked(IDC_Circle) == BST_CHECKED )//if chosen circle
	{
		
		hide_Poly();
		HideTextBoxes();
		show_Circle();
	}
	(CWnd*)GetDlgItem(IDC_Send)->ShowWindow(SW_SHOW);
}
void CTAB1::show_Circle() {
	GetDlgItem(IDC_Circle_Group)->ShowWindow(SW_SHOW); 
	GetDlgItem(IDC_Circle_Group)->SetWindowTextW(_T("Circle Type:"));
	GetDlgItem(IDC_Circle_C)->ShowWindow(SW_SHOW); GetDlgItem(IDC_Circle_E)->ShowWindow(SW_SHOW); GetDlgItem(IDC_Circle_P)->ShowWindow(SW_SHOW);

}
void CTAB1::hide_Circle()
{
	GetDlgItem(IDC_Circle_Group)->ShowWindow(SW_HIDE); GetDlgItem(IDC_Circle_C)->ShowWindow(SW_HIDE); GetDlgItem(IDC_Circle_E)->ShowWindow(SW_HIDE); GetDlgItem(IDC_Circle_P)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_Bottom_Group)->ShowWindow(SW_HIDE);
	hide_Circle_C(); hide_Circle_E(); hide_Circle_P();
}



//Function for displaying textboxes when moving from circle to poly
void CTAB1::ShowTextBoxes() {
	if (isHidden == 1) {
		for (int i = 0; i < save_amount_points; i++) {
			Polylabel[i].ShowWindow(SW_SHOW);
			PolyX[i].ShowWindow(SW_SHOW);
			PolyY[i].ShowWindow(SW_SHOW);
		}
		if (save_amount_points > 0) {
			GetDlgItem(IDC_Bottom_Group)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_X)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_Y)->ShowWindow(SW_SHOW);
			if (save_amount_points > 4)//if amount is bigger than 4,display x y labels in the right side as well 
			{
				GetDlgItem(IDC_X2)->ShowWindow(SW_SHOW);   GetDlgItem(IDC_Y2)->ShowWindow(SW_SHOW);
			}
		}
	
	}
}
//Function for moving from poly to circle so we need to hide the textboxes createdl
void CTAB1::HideTextBoxes() {
	for (int i = 0; i < save_amount_points; i++) {
		Polylabel[i].ShowWindow(SW_HIDE);
		PolyX[i].ShowWindow(SW_HIDE);
		PolyY[i].ShowWindow(SW_HIDE);
	}
	//HIDE ALL X,Y LABEL (and yo kids)
	GetDlgItem(IDC_X)->ShowWindow(SW_HIDE); GetDlgItem(IDC_Y)->ShowWindow(SW_HIDE); GetDlgItem(IDC_X2)->ShowWindow(SW_HIDE);	GetDlgItem(IDC_Y2)->ShowWindow(SW_HIDE);
	isHidden = 1;
}


//choosing the number of points desired
void CTAB1::OnCbnSelchangePoints()
{
	
	save_amount_points = m_comboBoxCtrl.GetCurSel() + 1;//get value according to place in combo box(starting from 0)
	
	GetDlgItem(IDC_X)->ShowWindow(SW_SHOW); GetDlgItem(IDC_Y)->ShowWindow(SW_SHOW);
	if (save_amount_points > 4)//if amount is bigger than 4,display x y labels in the right side as well 
	{
		GetDlgItem(IDC_X2)->ShowWindow(SW_SHOW);   GetDlgItem(IDC_Y2)->ShowWindow(SW_SHOW);
		
	}
	else
	{
		GetDlgItem(IDC_X2)->ShowWindow(SW_HIDE);  GetDlgItem(IDC_Y2)->ShowWindow(SW_HIDE);
	}

	GetDlgItem(IDC_Bottom_Group)->ShowWindow(SW_SHOW);
	   
	// Add number to the combo box
	m_comboBoxCtrl.GetLBText(m_comboBoxCtrl.GetCurSel(), m_strTextCtrl); 
	UpdateData(FALSE);
   
	   
	   


	  

		//Add text box
	   int i;
	   for ( i= 0; i < save_amount_points; i++) {
		   PolyX[i].ShowWindow(SW_SHOW);
		   PolyY[i].ShowWindow(SW_SHOW);
		   Polylabel[i].ShowWindow(SW_SHOW);
	   }
	   for (; i < 8; i++) {
		   PolyX[i].SetWindowTextW(_T(""));
		   PolyX[i].ShowWindow(SW_HIDE);
		   PolyY[i].SetWindowTextW(_T(""));
		   PolyY[i].ShowWindow(SW_HIDE);
		   Polylabel[i].ShowWindow(SW_HIDE);
	   }

	 
 
}




//display everything that is connected to Circle C
void CTAB1::Create_Circle_C()
{
		
		CircleTextBox = new CEdit[3];
		CircleTextBoxLabels = new CStatic[4];
		CircleTextBoxLabels[0].Create(_T("Enter Center Point:"), WS_CHILD | WS_VISIBLE,
			CRect(25, 158, 250, 190), this);
		
		CircleTextBoxLabels[1].Create(_T("x:"), WS_CHILD | WS_VISIBLE,
			CRect(15, 190, 30, 220), this);

		CircleTextBoxLabels[2].Create(_T("y:"), WS_CHILD | WS_VISIBLE,
			CRect(80, 190, 95, 220), this);

		CircleTextBoxLabels[3].Create(_T("Radius:"), WS_CHILD | WS_VISIBLE,
			CRect(15, 230, 80, 250), this);

		CircleTextBox[0].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER, 
			CRect(30,190,55,210),this, 8888);	//input x textbox
	
	
		CircleTextBox[1].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
			CRect(100, 190, 125,210), this, 8888);//input y textbox
		
	
		CircleTextBox[2].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
			CRect(77, 230, 110, 250), this, 8888);//input radious textbox
}

void CTAB1::show_Circle_C()
{
	GetDlgItem(IDC_Bottom_Group)->ShowWindow(SW_SHOW);
	if (CreateCircleC == 0) { Create_Circle_C(); CreateCircleC = 1; }
	else
		for (int i = 0; i < 3; i++) {
			CircleTextBoxLabels[i].ShowWindow(SW_SHOW);
			CircleTextBox[i].ShowWindow(SW_SHOW);
		}
	CircleTextBoxLabels[3].ShowWindow(SW_SHOW);
}

void CTAB1::hide_Circle_C()
{
	if (CreateCircleC == 1) {
		for (int i = 0; i < 3; i++) {
			CircleTextBoxLabels[i].ShowWindow(SW_HIDE);
			CircleTextBox[i].ShowWindow(SW_HIDE);
		}
		CircleTextBoxLabels[3].ShowWindow(SW_HIDE);
	}
}


void CTAB1::Create_Circle_E()
{
	
	EllipseTextBox = new CEdit[4];
	EllipseTextBoxLabels = new CStatic[6];

	EllipseTextBoxLabels[0].Create(_T("Enter Left Bottom:"), WS_CHILD | WS_VISIBLE,
		CRect(17, 160, 200, 190), this);

	EllipseTextBoxLabels[1].Create(_T("x:"), WS_CHILD | WS_VISIBLE,
		CRect(17, 180, 30, 200), this);

	EllipseTextBox[0].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		CRect(30, 180, 55, 200), this, 8888);
	
	EllipseTextBoxLabels[2].Create(_T("y:"), WS_CHILD | WS_VISIBLE,
		CRect(57, 180, 70, 200), this);
	EllipseTextBox[1].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		CRect(70, 180, 95, 200), this, 8888);
	

	EllipseTextBoxLabels[3].Create(_T("Enter Right Top:"), WS_CHILD | WS_VISIBLE,
		CRect(17, 210, 200, 240), this);
	EllipseTextBoxLabels[4].Create(_T("x:"), WS_CHILD | WS_VISIBLE,
		CRect(17, 230, 30, 250), this);
	EllipseTextBox[2].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		CRect(30, 230, 55, 250), this, 8888);
	EllipseTextBoxLabels[5].Create(_T("y:"), WS_CHILD | WS_VISIBLE,
		CRect(57, 230, 70, 250), this);
	EllipseTextBox[3].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		CRect(70, 230, 95, 250), this, 8888);
}

void CTAB1::show_Circle_E()
{
	GetDlgItem(IDC_Bottom_Group)->ShowWindow(SW_SHOW);
	if (CreateCircleE == 0) { Create_Circle_E(); CreateCircleE = 1; }
	else {
		int i;
		for ( i= 0; i < 4; i++) {
			EllipseTextBox[i].ShowWindow(SW_SHOW);
			EllipseTextBoxLabels[i].ShowWindow(SW_SHOW);
		}
		for (; i < 6; i++) {
			EllipseTextBoxLabels[i].ShowWindow(SW_SHOW);
		}
	}
}

void CTAB1::hide_Circle_E()
{
	if (CreateCircleE == 1) {
		int i;
		for ( i= 0; i < 4; i++) {
			EllipseTextBox[i].ShowWindow(SW_HIDE);
			EllipseTextBoxLabels[i].ShowWindow(SW_HIDE);
		}
		for (; i < 6; i++) {
			EllipseTextBoxLabels[i].ShowWindow(SW_HIDE);
		}
	}
}



void CTAB1::Create_Circle_P()
{

	//input x textbox
	PieTextBox = new CEdit[8];
	PieTextBox[0].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		CRect(25, 180, 45, 200), this, 8888);
	//input y textbox
	
	PieTextBox[1].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		CRect(70, 180, 90, 200), this, 8888);
	//input radious textbox

	PieTextBox[2].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		CRect(135, 180, 155, 200), this, 8888);
	
	PieTextBox[3].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		CRect(180, 180, 200, 200), this, 8888);




	PieTextBox[4].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		CRect(25, 220, 45, 240), this, 8888);
	
	PieTextBox[5].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		CRect(70, 220, 90, 240), this, 8888);

	PieTextBox[6].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		CRect(135, 220, 155, 240), this, 8888);

	PieTextBox[7].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		CRect(180, 220, 200, 240), this, 8888);
}

void CTAB1::show_Circle_P()
{
	GetDlgItem(IDC_Bottom_Group)->ShowWindow(SW_SHOW);
	if (CreateCircleP == 0) { Create_Circle_P(); CreateCircleP = 1; }
	else
		for (int i = 0; i < 8; i++) { PieTextBox[i].ShowWindow(SW_SHOW); }
}

void CTAB1::hide_Circle_P()
{
	if (CreateCircleP == 1) {
		for(int i=0; i <8; i++){ PieTextBox[i].ShowWindow(SW_HIDE); }
	}
}






//On Circle Radio button click

void CTAB1::OnBnClickedCircleC()
{
	if ( IsDlgButtonChecked(IDC_Circle_C) == BST_CHECKED )//if chosen circle 
	{
		hide_Circle_E();
		hide_Circle_P();
		show_Circle_C();
			
		
	}
}


void CTAB1::OnBnClickedCircleE()
{
	if ( IsDlgButtonChecked(IDC_Circle_E) == BST_CHECKED )//if chosen ellipse
	{
		hide_Circle_P();
		hide_Circle_C();
		show_Circle_E();
			
		
	}
}


void CTAB1::OnBnClickedCircleP()
{
	if ( IsDlgButtonChecked(IDC_Circle_P) == BST_CHECKED )//if chosen pie
	{
		hide_Circle_E();
		hide_Circle_C();
		show_Circle_P();
		
		

	}
}


void CTAB1::OnBnClickedSend() {
	if (CurrentPose_shape < 5)
	{
		if (InputItegrity()) {
			UpdateData(TRUE);

			CWnd* Main = GetParent()->GetParent()->GetParent();  //Get main window functions

			CString str;

			if (IsDlgButtonChecked(IDC_Polygon) == BST_CHECKED) {//if chosen poly 


				//gets input from textbox
				double x, y;
				POINT* PointArray = new POINT[save_amount_points];
				POINT* On_Screen = new POINT[save_amount_points];
				for (int i = 0; i < this->save_amount_points; i++) {
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
				Poligon* p1 = new Poligon(On_Screen, PointArray, save_amount_points);
				

				p1->set_pos_type_list(CurrentPose_poly);
				p1->set_pos_shape_list(CurrentPose_shape);

				polygon_shapes.AddTail(p1);
				PolyList.push_back(p1);
				ShapeList.push_back(p1);
				CurrentPose_poly++;
				CurrentPose_shape++;

				


				delete[] PointArray;
				delete[] On_Screen;


				Main->RedrawWindow();      //Go to main window and redraw with new shape;








			}
			else {   //Chosen circle
				if ((IsDlgButtonChecked(IDC_Circle_C) == BST_CHECKED)) { //Chosen circle circle


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


					Circle* c1 = new Circle(p1, p2, rad);
					

					c1->set_pos_type_list(CurrentPose_circle_c);
					c1->set_pos_shape_list(CurrentPose_shape);

					ShapeList.push_back(c1);
					CircleList.push_back(c1);
					CircleCList.push_back(c1);
					circle_shapes.AddTail(c1);


					CurrentPose_circle++;
					CurrentPose_shape++;
					CurrentPose_circle_c++;

					

					delete[] p2;

					Main->RedrawWindow();      //Go to main window and redraw with new shape;





				}
				else if ((IsDlgButtonChecked(IDC_Circle_E) == BST_CHECKED)) {



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



					ellipse* e1 = new ellipse(p1, p3, p2);
					//e1->position_in_shape++;
					e1->set_pos_type_list(CurrentPose_circle_e);
					e1->set_pos_shape_list(CurrentPose_shape);

					delete[] p2;

					ShapeList.push_back(e1);
					CircleList.push_back(e1);
					CircleEList.push_back(e1);
					ellipse_shapes.AddTail(e1);


					CurrentPose_circle++;
					CurrentPose_shape++;
					CurrentPose_circle_e++;

					

					Main->RedrawWindow();      //Go to main window and redraw with new shape;





				}
				else {



					POINT p1;

					POINT* p2 = new POINT[2];

					POINT p3;

					POINT* p4 = new POINT[2];

					POINT p5;

					POINT p6;
					PieTextBox[0].GetWindowTextW(str);
					PieTextBox[0].SetWindowTextW(_T(""));// Reset TextBox
					p1.x = _tstof(str) * 10; // CASTING TO DOUBLE
					p2[0].x = ((_tstof(str)) + 10) * SquareSide + SquareSide;

					PieTextBox[1].GetWindowTextW(str);
					PieTextBox[1].SetWindowTextW(_T(""));// Reset TextBox
					p1.y = _tstof(str) * 10; // CASTING TO DOUBLE
					p2[0].y = (10 - (_tstof(str))) * SquareSide + SquareSide;



					PieTextBox[2].GetWindowTextW(str);
					PieTextBox[2].SetWindowTextW(_T(""));// Reset TextBox
					p3.x = _tstof(str) * 10; // CASTING TO DOUBLE
					p2[1].x = ((_tstof(str)) + 10) * SquareSide + SquareSide;

					PieTextBox[3].GetWindowTextW(str);
					PieTextBox[3].SetWindowTextW(_T(""));// Reset TextBox
					p3.y = _tstof(str) * 10; // CASTING TO DOUBLE
					p2[1].y = (10 - (_tstof(str))) * SquareSide + SquareSide;



					PieTextBox[4].GetWindowTextW(str);
					PieTextBox[4].SetWindowTextW(_T(""));// Reset TextBox
					p5.x = _tstof(str) * 10; // CASTING TO DOUBLE
					p4[0].x = ((_tstof(str)) + 10) * SquareSide + SquareSide;

					PieTextBox[5].GetWindowTextW(str);
					PieTextBox[5].SetWindowTextW(_T(""));// Reset TextBox
					p5.y = _tstof(str) * 10;// CASTING TO DOUBLE
					p4[0].y = (10 - (_tstof(str))) * SquareSide + SquareSide;


					PieTextBox[6].GetWindowTextW(str);
					PieTextBox[6].SetWindowTextW(_T(""));// Reset TextBox
					p6.x = _tstof(str) * 10; // CASTING TO DOUBLE
					p4[1].x = ((_tstof(str)) + 10) * SquareSide + SquareSide;

					PieTextBox[7].GetWindowTextW(str);
					PieTextBox[7].SetWindowTextW(_T(""));// Reset TextBox
					p6.y = _tstof(str) * 10; // CASTING TO DOUBLE
					p4[1].y = (10 - (_tstof(str))) * SquareSide + SquareSide;


					pie* e1 = new pie(p1, p3, p2, p5, p6, p4);

					//e1->position_in_shape++;

					e1->set_pos_type_list(CurrentPose_circle_p);
					e1->set_pos_shape_list(CurrentPose_shape);
					

					ShapeList.push_back(e1);
					CircleList.push_back(e1);
					CirclePList.push_back(e1);
					pie_shapes.AddTail(e1);
					CurrentPose_circle++;
					CurrentPose_shape++;
					CurrentPose_circle_p++;

					

					delete[] p2;
					delete[] p4;

					Main->RedrawWindow();      //Go to main window and redraw with new shape;




				}
				UpdateData(FALSE);
			}
		}
	}
	else
	{
		MessageBox(_T("You enter too much shape \n FUCK YOU"), _T("ERROR"), MB_OK);
	}
}



bool CTAB1::InputItegrity() {//checking input if correct
	CString str,str2,str3;
	if (IsDlgButtonChecked(IDC_Polygon) == BST_CHECKED) {
		for (int i = 0; i < this->save_amount_points; i++) {//checking poly input
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
	}
	else if ((IsDlgButtonChecked(IDC_Circle_C) == BST_CHECKED)) { //Check input itegrity for circleC
			CircleTextBox[0].GetWindowTextW(str);
			CircleTextBox[1].GetWindowTextW(str2);
			CircleTextBox[2].GetWindowTextW(str3);
			if ((_tstof(str) < -10 || _tstof(str) > 10) || (_tstof(str2) < -10 || _tstof(str2) > 10) || (_tstof(str) + _tstof(str3) < -10 || _tstof(str) + _tstof(str3) > 10 || _tstof(str2) + _tstof(str3) < -10 || _tstof(str2) + _tstof(str3) > 10) || _tstof(str3)<0) {
				
				CleanInput();
				MessageBox(_T("Invalid input"), _T("ERROR"), MB_OK);
				return FALSE;
			}
		}
	else if (IsDlgButtonChecked(IDC_Circle_E) == BST_CHECKED) {//checking ellipse input
		for (int i = 0; i < 4; i++) {
			EllipseTextBox[i].GetWindowTextW(str);
			if (_tstof(str) < -10 || _tstof(str) > 10) {
				CleanInput();
				MessageBox(_T("Invalid input"), _T("ERROR"), MB_OK);
				return FALSE;
			}
		}
		}
	else {
		for (int i = 0; i < 8; i++) {//Check input itegrity for pie
			PieTextBox[i].GetWindowTextW(str);
			if (_tstof(str) < -10 || _tstof(str) > 10) {
				CleanInput();
				MessageBox(_T("Invalid input"), _T("ERROR"), MB_OK);
				return FALSE;
			}

		}
	}
	return TRUE;
}



	



	


void CTAB1::CleanInput() {//clean all the input
	if (IsDlgButtonChecked(IDC_Polygon) == BST_CHECKED) {
		for (int i = 0; i < this->save_amount_points; i++) {
			PolyX[i].SetWindowTextW(_T(""));
			PolyY[i].SetWindowTextW(_T(""));
		}
	}
	else if (IsDlgButtonChecked(IDC_Circle_C) == BST_CHECKED) {
		for (int i = 0; i < 3; i++) {
			CircleTextBox[i].SetWindowTextW(_T(""));
		}
	}
	else if (IsDlgButtonChecked(IDC_Circle_E) == BST_CHECKED) {
		for (int i = 0; i < 4; i++) {
			EllipseTextBox[i].SetWindowTextW(_T(""));
		}
	}
	else {
		for (int i = 0; i < 8; i++) {
			PieTextBox[i].SetWindowTextW(_T(""));
		}
	}
	}