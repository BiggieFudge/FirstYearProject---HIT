// CTAB1.cpp : implementation file
//

#include "pch.h"
#include "OOP_Project.h"
#include "OOP_ProjectDlg.h"
#include "CTAB1.h"
#include "afxdialogex.h"
#include "AXIS.h"


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
		show_Poly();
		ShowTextBoxes();
		hide_Circle();
	}
  
}
//display everything that is connected to poly
void CTAB1::show_Poly() {
   
	GetDlgItem(IDC_Poly)->ShowWindow(SW_SHOW);

	GetDlgItem(IDC_label)->ShowWindow(SW_SHOW);

	GetDlgItem(IDC_Points)->ShowWindow(SW_SHOW);

	GetDlgItem(IDC_Send)->ShowWindow(SW_SHOW);

	
	
}
//hide everything that is connected to poly
void CTAB1::hide_Poly()
{
	GetDlgItem(IDC_Poly)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_label)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_Points)->ShowWindow(SW_HIDE);   

}





//deleting text boxes for input points in polygon
void CTAB1::delete_buttons()
{
	if (save_amount_points != -1)
	{
		int i;
		for (i = 0; i < save_amount_points; i++)
		{
			delete(Xtextbox[i]);
			delete(Ytextbox[i]);
			delete(labels[i]);
		}
	}
}
//deleting text boxes for input points in circle
void CTAB1::delete_circle_textbox()
{
	if(CreateCircleC==1)
		for(int i=0;i<3;i++)
			delete(CircleTextBox[i]);
	if (CreateCircleE == 1)
		for (int i = 0; i < 4; i++)
			delete(EllipseTextBox[i]);
	if (CreateCircleP == 1)
		for (int i = 0; i < 8; i++)
			delete(PieTextBox[i]);
	
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
	GetDlgItem(IDC_Circle_Group)->ShowWindow(SW_SHOW); GetDlgItem(IDC_Circle_C)->ShowWindow(SW_SHOW); GetDlgItem(IDC_Circle_E)->ShowWindow(SW_SHOW); GetDlgItem(IDC_Circle_P)->ShowWindow(SW_SHOW);

}
void CTAB1::hide_Circle()
{
	GetDlgItem(IDC_Circle_Group)->ShowWindow(SW_HIDE); GetDlgItem(IDC_Circle_C)->ShowWindow(SW_HIDE); GetDlgItem(IDC_Circle_E)->ShowWindow(SW_HIDE); GetDlgItem(IDC_Circle_P)->ShowWindow(SW_HIDE);
	hide_Circle_C(); hide_Circle_E(); hide_Circle_P();
}



//Function for displaying textboxes when moving from circle to poly
void CTAB1::ShowTextBoxes() {
	if (isHidden == 1) {
		for (int i = 0; i < save_amount_points; i++) {
			labels[i]->ShowWindow(SW_SHOW);
			Xtextbox[i]->ShowWindow(SW_SHOW);
			Ytextbox[i]->ShowWindow(SW_SHOW);
		}
	}
}
//Function for moving from poly to circle so we need to hide the textboxes createdl
void CTAB1::HideTextBoxes() {
	for (int i = 0; i < save_amount_points; i++) {
		labels[i]->ShowWindow(SW_HIDE);
		Xtextbox[i]->ShowWindow(SW_HIDE);
		Ytextbox[i]->ShowWindow(SW_HIDE);
	}
	//HIDE ALL X,Y LABEL (and yo kids)
	GetDlgItem(IDC_X)->ShowWindow(SW_HIDE); GetDlgItem(IDC_Y)->ShowWindow(SW_HIDE); GetDlgItem(IDC_X2)->ShowWindow(SW_HIDE);	GetDlgItem(IDC_Y2)->ShowWindow(SW_HIDE);
	isHidden = 1;
}


//choosing the number of points desired
void CTAB1::OnCbnSelchangePoints()
{
	//display x and y labels
	GetDlgItem(IDC_X)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_Y)->ShowWindow(SW_SHOW);

	   // Add number to the combo box
	   m_comboBoxCtrl.GetLBText(m_comboBoxCtrl.GetCurSel(), m_strTextCtrl); 
	   UpdateData(FALSE);
   
	   if(save_amount_points > m_comboBoxCtrl.GetCurSel() + 1)//if already entered number before
	   { 
		   //for loop is for removing textboxes that are not needed
		   for (int i = m_comboBoxCtrl.GetCurSel() + 1; i < save_amount_points; i++) {
			   delete labels[i];
			   delete Xtextbox[i];
			   delete Ytextbox[i];
			   labels[i]=NULL;
			   Xtextbox[i]=NULL;
			   Ytextbox[i]=NULL;
		  }
	   }
	   save_amount_points = m_comboBoxCtrl.GetCurSel() + 1;//get value according to place in combo box(starting from 0)


	   if (save_amount_points > 4)//if amount is bigger than 4,display x y labels in the right side as well 
	   {
		   GetDlgItem(IDC_X2)->ShowWindow(SW_SHOW);   GetDlgItem(IDC_Y2)->ShowWindow(SW_SHOW);

	 
	   }
	   else
	   {
		   GetDlgItem(IDC_X2)->ShowWindow(SW_HIDE);  GetDlgItem(IDC_Y2)->ShowWindow(SW_HIDE);
	   }

		//Add text box

	   int y=180;
	   int x = 25;
	   for (int i = 1; i <= save_amount_points; i++)
	   {
		   if (i == 5) { x = 120; y = 180; }

		   CString NumToDisplay;  NumToDisplay.Format(_T("%d"), i); //Enter i to string;

		   if (labels[i - 1] == NULL) {
			   labels[i - 1] = new CStatic;         //Print nums;
			   labels[i - 1]->Create(NumToDisplay, WS_CHILD | WS_VISIBLE,
				   CRect(x - 10, y, x, y + 20), this);
		   }
		   if (Xtextbox[i - 1] == NULL) {
			   Xtextbox[i - 1] = new CEdit;        // Print Text Boxes
			   Xtextbox[i - 1]->Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
				   CRect(x, y, x + 20, y + 20), this, 8888);
		   }
		   if (Ytextbox[i - 1] == NULL){
			   Ytextbox[i - 1] = new CEdit;
		   Ytextbox[i - 1]->Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER, 
			   CRect(x + 45, y, x + 65, y + 20), this, 8888);
	   }
	   y += 35;
	   }
 
}




//display everything that is connected to Circle C
void CTAB1::Create_Circle_C()
{
		//input x textbox
		CircleTextBox = new CEdit[3];
		CircleTextBox[0].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER, 
			CRect(25,180,45,200),this, 8888);
		//input y textbox
	
		CircleTextBox[1].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
			CRect(70, 180, 90,200), this, 8888);
		//input radious textbox
	
		CircleTextBox[2].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
			CRect(115, 180, 135, 200), this, 8888);
}

void CTAB1::show_Circle_C()
{
	if (CreateCircleC == 0) { Create_Circle_C(); CreateCircleC = 1; }
	else
		for (int i = 0; i < 3; i++)
			CircleTextBox[i].ShowWindow(SW_SHOW);
}

void CTAB1::hide_Circle_C()
{
	if (CreateCircleC == 1) {
		for(int i=0; i<3; i++)
			CircleTextBox[i].ShowWindow(SW_HIDE);
	}
}



void CTAB1::Create_Circle_E()
{
	//input x textbox
	EllipseTextBox = new CEdit[4];
	EllipseTextBox[0].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		CRect(25, 180, 45, 200), this, 8888);
	//input y textbox

	EllipseTextBox[1].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		CRect(70, 180, 90, 200), this, 8888);
	//input radious textbox

	EllipseTextBox[2].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		CRect(135, 180, 155, 200), this, 8888);

	EllipseTextBox[3].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		CRect(180, 180, 200, 200), this, 8888);
}

void CTAB1::show_Circle_E()
{
	if (CreateCircleE == 0) { Create_Circle_E(); CreateCircleE = 1; }
	else
		for(int i=0; i<4; i++)
			EllipseTextBox[i].ShowWindow(SW_SHOW);
}

void CTAB1::hide_Circle_E()
{
	if (CreateCircleE == 1) {
		for(int i=0; i<4; i++)
			EllipseTextBox[i].ShowWindow(SW_HIDE);
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
		if (IsDlgButtonChecked(IDC_Polygon) == BST_CHECKED) {//if chosen poly 
			UpdateData(TRUE);
			CString str;
			//gets input from textbox
			double x, y;
			POINT* PointArray = new POINT[save_amount_points];
			POINT* On_Screen = new POINT[save_amount_points];
			for (int i = 0; i < this->save_amount_points; i++) {
				Xtextbox[i]->GetWindowTextW(str);     //Take Data from textbox
				Xtextbox[i]->SetWindowTextW(_T("")); // Reset TextBox
				x = _ttoi(str);  //Convert from Cstring to double
				Ytextbox[i]->GetWindowTextW(str);   //Take Data from textbox
				Ytextbox[i]->SetWindowTextW(_T("")); // Reset TextBox
				y = _ttoi(str);  //Convert from Cstring to double
				PointArray[i].x = (double)x;
				PointArray[i].y = (double)y;
				On_Screen[i].x = ((double)x + 10) * SquareSide + SquareSide;  //ETN maths
				On_Screen[i].y = (10 - (double)y) * SquareSide + SquareSide;     //ETN maths
			}
			Poligon* p1 = new Poligon(On_Screen, PointArray, save_amount_points);
			//PolyArr[CurrentPose_poly] = p1;
			//ShapeArr[CurrentPose_shape] = p1;
			PolyList.push_back(p1);
			ShapeList.push_back(p1);
			CurrentPose_poly++;
			CurrentPose_shape++;


			CWnd* Main = GetParent()->GetParent()->GetParent();  //Get main window functions

			Main->RedrawWindow();      //Go to main window and redraw with new shape;

			delete[] PointArray;
			delete[] On_Screen;

			UpdateData(FALSE);


		}
		else {   //Chosen circle
			if ((IsDlgButtonChecked(IDC_Circle_C) == BST_CHECKED)) { //Chosen circle circle
				UpdateData(TRUE);
				CString str;
				CircleTextBox[2].GetWindowTextW(str);   //Get radius user entered
				CircleTextBox[2].SetWindowTextW(_T("")); // Reset TextBox
				double rad = _ttoi(str);
				POINT p1;
				POINT* p2 = new POINT[2];
				CircleTextBox[0].GetWindowTextW(str);
				CircleTextBox[0].SetWindowTextW(_T(""));// Reset TextBox
				p1.x = _ttoi(str);
				p2[0].x = ((_ttoi(str) - rad) + 10) * SquareSide + SquareSide;
				p2[1].x = ((_ttoi(str) + rad) + 10) * SquareSide + SquareSide;
				CircleTextBox[1].GetWindowTextW(str);
				CircleTextBox[1].SetWindowTextW(_T(""));// Reset TextBox
				p1.y = _ttoi(str);
				p2[0].y = (10 - (_ttoi(str) - rad)) * SquareSide + SquareSide;
				p2[1].y = (10 - (_ttoi(str) + rad)) * SquareSide + SquareSide;
				
				
				Circle* c1 = new Circle(p1, p2, rad);

				ShapeList.push_back(c1);
				CircleList.push_back(c1);
				CircleCList.push_back(c1);

				CurrentPose_circle++;
				CurrentPose_shape++;
				CurrentPose_circle_c++;

				CWnd* Main = GetParent()->GetParent()->GetParent();  //Get main window functions

				Main->RedrawWindow();      //Go to main window and redraw with new shape;

				delete[] p2;

				UpdateData(FALSE);


			}
			else if ((IsDlgButtonChecked(IDC_Circle_E) == BST_CHECKED)) {
				UpdateData(TRUE);
				CString str;
				
				POINT p1;
				
				POINT* p2 = new POINT[2];

				POINT p3;
				EllipseTextBox[0].GetWindowTextW(str);
				EllipseTextBox[0].SetWindowTextW(_T(""));// Reset TextBox
				p1.x = _ttoi(str);
				p2[0].x = ((_ttoi(str)) + 10) * SquareSide + SquareSide;
				
				EllipseTextBox[1].GetWindowTextW(str);
				EllipseTextBox[1].SetWindowTextW(_T(""));// Reset TextBox
				p1.y = _ttoi(str);
				p2[0].y = (10 - (_ttoi(str))) * SquareSide + SquareSide;
				


				EllipseTextBox[2].GetWindowTextW(str);
				EllipseTextBox[2].SetWindowTextW(_T(""));// Reset TextBox
				p3.x = _ttoi(str);
				p2[1].x = ((_ttoi(str)) + 10) * SquareSide + SquareSide;
				
				EllipseTextBox[3].GetWindowTextW(str);
				EllipseTextBox[3].SetWindowTextW(_T(""));// Reset TextBox
				p3.y = _ttoi(str);
				p2[1].y = (10 - (_ttoi(str))) * SquareSide + SquareSide;
		


				ellipse* e1 = new ellipse(p1, p3 , p2);


				ShapeList.push_back(e1);
				CircleList.push_back(e1);
				CircleEList.push_back(e1);

				CurrentPose_circle++;
				CurrentPose_shape++;
				CurrentPose_circle_e++;

				CWnd* Main = GetParent()->GetParent()->GetParent();  //Get main window functions

				Main->RedrawWindow();      //Go to main window and redraw with new shape;

				delete[] p2;

				UpdateData(FALSE);

			}
			else {
				UpdateData(TRUE);
				CString str;

				POINT p1;

				POINT* p2 = new POINT[2];

				POINT p3;

				POINT* p4 = new POINT[2];

				POINT p5;

				POINT p6;
				PieTextBox[0].GetWindowTextW(str);
				PieTextBox[0].SetWindowTextW(_T(""));// Reset TextBox
				p1.x = _ttoi(str);
				p2[0].x = ((_ttoi(str)) + 10) * SquareSide + SquareSide;

				PieTextBox[1].GetWindowTextW(str);
				PieTextBox[1].SetWindowTextW(_T(""));// Reset TextBox
				p1.y = _ttoi(str);
				p2[0].y = (10 - (_ttoi(str))) * SquareSide + SquareSide;



				PieTextBox[2].GetWindowTextW(str);
				PieTextBox[2].SetWindowTextW(_T(""));// Reset TextBox
				p3.x = _ttoi(str);
				p2[1].x = ((_ttoi(str)) + 10) * SquareSide + SquareSide;

				PieTextBox[3].GetWindowTextW(str);
				PieTextBox[3].SetWindowTextW(_T(""));// Reset TextBox
				p3.y = _ttoi(str);
				p2[1].y = (10 - (_ttoi(str))) * SquareSide + SquareSide;



				PieTextBox[4].GetWindowTextW(str);
				PieTextBox[4].SetWindowTextW(_T(""));// Reset TextBox
				p5.x = _ttoi(str);
				p4[0].x = ((_ttoi(str)) + 10) * SquareSide + SquareSide;

				PieTextBox[5].GetWindowTextW(str);
				PieTextBox[5].SetWindowTextW(_T(""));// Reset TextBox
				p5.y = _ttoi(str);
				p4[0].y = (10 - (_ttoi(str))) * SquareSide + SquareSide;


				PieTextBox[6].GetWindowTextW(str);
				PieTextBox[6].SetWindowTextW(_T(""));// Reset TextBox
				p6.x = _ttoi(str);
				p4[1].x = ((_ttoi(str)) + 10) * SquareSide + SquareSide;

				PieTextBox[7].GetWindowTextW(str);
				PieTextBox[7].SetWindowTextW(_T(""));// Reset TextBox
				p6.y = _ttoi(str);
				p4[1].y = (10 - (_ttoi(str))) * SquareSide + SquareSide;


				pie* e1 = new pie(p1, p3, p2,p5 , p6,p4);
	

				ShapeList.push_back(e1);
				CircleList.push_back(e1);
				CirclePList.push_back(e1);

				CurrentPose_circle++;
				CurrentPose_shape++;
				CurrentPose_circle_p++;

				CWnd* Main = GetParent()->GetParent()->GetParent();  //Get main window functions

				Main->RedrawWindow();      //Go to main window and redraw with new shape;

				delete[] p2;

				UpdateData(FALSE);
			}
		}
	}
	else
	{
		MessageBox(_T("You enter too much shape \n FUCK YOU"), _T("ERROR"), MB_OK);
	}
}
