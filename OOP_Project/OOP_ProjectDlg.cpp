// OOP_ProjectDlg.cpp : implementation file
//


#include "pch.h"
#include "framework.h"
#include "OOP_Project.h"
#include "OOP_ProjectDlg.h"
#include "afxdialogex.h"
#include "CONTROLS.h"


#include <iostream>
#include <string.h>

#define RemoveBtn1 69
#define RemoveBtn2 70
#define RemoveBtn3 71
#define RemoveBtn4 72
#define RemoveBtn5 73

#define EditBtn1 74
#define EditBtn2 75
#define EditBtn3 76
#define EditBtn4 77
#define EditBtn5 78

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();



	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:

};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

END_MESSAGE_MAP()


// COOPProjectDlg dialog



COOPProjectDlg::COOPProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OOP_PROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1); // Change the app icon.ETN
}

void COOPProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

}

BEGIN_MESSAGE_MAP(COOPProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &COOPProjectDlg::OnBnClickedButton1)

	ON_BN_CLICKED(RemoveBtn1, &COOPProjectDlg::RemoveShape1)
	ON_BN_CLICKED(RemoveBtn2, &COOPProjectDlg::RemoveShape2)
	ON_BN_CLICKED(RemoveBtn3, &COOPProjectDlg::RemoveShape3)
	ON_BN_CLICKED(RemoveBtn4, &COOPProjectDlg::RemoveShape4)
	ON_BN_CLICKED(RemoveBtn5, &COOPProjectDlg::RemoveShape5)

	ON_BN_CLICKED(EditBtn1, &COOPProjectDlg::EditShape1)
	ON_BN_CLICKED(EditBtn2, &COOPProjectDlg::EditShape2)
	ON_BN_CLICKED(EditBtn3, &COOPProjectDlg::EditShape3)
	ON_BN_CLICKED(EditBtn4, &COOPProjectDlg::EditShape4)
	ON_BN_CLICKED(EditBtn5, &COOPProjectDlg::EditShape5)


	ON_BN_CLICKED(IDC_SAVE, &COOPProjectDlg::OnBnClickedSave)
	ON_BN_CLICKED(IDC_LOAD, &COOPProjectDlg::OnBnClickedLoad)
END_MESSAGE_MAP()


// COOPProjectDlg message handlers

BOOL COOPProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CRect rect;
	GetClientRect(&rect);

	

	
	
	m_controls.Create(IDD_CONTROLS, this);  //Create CONTROL DIALOG
	


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COOPProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
bool change = false; //Auto update screen size;
void COOPProjectDlg::OnPaint()
{

	//create window size
	if (change == false) {
		MoveWindow(CRect(0, 0, 1380, 900));
		CenterWindow();
		change = true;
	}


	if (IsIconic())
	{

		CPaintDC dc(this); // device context for painting
		
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;



		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{

		CPaintDC dc(this);
		
		CRect rect;
		GetClientRect(&rect);
		//int SquareSide = rect.Width()*(0.65) / 20;



		CPen penForSquare;
		penForSquare.CreatePen(PS_DOT, 1, RGB(128, 128, 128));
		CPen penForAxis;
		penForAxis.CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
		

		for (int i = 1; i < 21; i++) {     // Draw Grid and Shnatot
			for (int j = 1; j < 21; j++) {
				dc.SelectObject(&penForSquare);
				dc.Rectangle(CRect(i * SquareSide, j * SquareSide, i * SquareSide + SquareSide, j * SquareSide + SquareSide)); //Draw Square
				dc.SelectObject(&penForAxis);
				if (i == 11 && j != 0) {
					dc.MoveTo(i * SquareSide - 7, j * SquareSide);//shnatot on y axis
					dc.LineTo(i * SquareSide + 7, j * SquareSide);
				
				}
				if (j == 11 && i != 0) {
					dc.MoveTo(i * SquareSide, j * SquareSide - 7); //shnatot on x axis
					dc.LineTo(i * SquareSide, j * SquareSide + 7);
				
				}
			}
		}

		



		dc.MoveTo(SquareSide * 11, SquareSide);
		dc.LineTo(SquareSide * 11, SquareSide * 21); //draw Y axis
		dc.MoveTo(SquareSide, SquareSide * 11);
		dc.LineTo(SquareSide * 21, SquareSide * 11); //draw X axis

		//create frame around show_All;
		dc.MoveTo(869, 29);
		dc.LineTo(1331, 29);
		dc.LineTo(1331, 527);
		dc.LineTo(869, 527);
		dc.LineTo(869, 29);





		CPen penForShapes;


		int i_color = 0;//index for color choosing
		int indexPoly = 0, indexCircleC = 0, indexCircleP = 0, indexCircleE = 0;     // Create and reset index's

		poly_it = m_controls.m_TAB1.PolyList.begin();      //RESERT ITTERATORS
		circle_it = m_controls.m_TAB1.CircleCList.begin();
		pie_it = m_controls.m_TAB1.CirclePList.begin();
		ellipse_it = m_controls.m_TAB1.CircleEList.begin();
		dc.SelectStockObject(NULL_BRUSH);      //Set the background to be transparent.

		int index = 0;
		for (shape_it = m_controls.m_TAB1.ShapeList.begin(); shape_it != m_controls.m_TAB1.ShapeList.end(); shape_it++) {   //Test To print shapes



			string type = (*shape_it)->type();


			if ((*shape_it)->get_color() == -1)
			{
				int j;
				for (j = 0; j < 5; j++)
				{
					if (arr_check_color[j] == false)
					{
						//i_color = j;
						arr_check_color[j] = true;
						break;
					}
				}
				//(*shape_it)->set_color(i_color);
				(*shape_it)->set_color(j);
				
			}

		    
			/*(*shape_it)->set_pos_shape_list()(index);*/
			(*shape_it)->set_pos_shape_list(index);

			index++;
			penForShapes.DeleteObject();
			penForShapes.CreatePen(PS_SOLID, 4, arr_color[(*shape_it)->get_color()]); //Change Color according to shape.color
			dc.SelectObject(&penForShapes);



			if (type == "Polygon") {
				INFOPoly(shape_it, poly_it);

				if ((*poly_it)->get_amount_edge() == 1) {
					penForShapes.DeleteObject();
					penForShapes.CreatePen(PS_SOLID, 8, arr_color[(*shape_it)->get_color()]);
					dc.SelectObject(&penForShapes);
					dc.Ellipse(CRect((*poly_it)->GetArr()[0].x,
								(*poly_it)->GetArr()[0].y, 
								(*poly_it)->GetArr()[0].x+1,
								(*poly_it)->GetArr()[0].y+1));
				}
				else {
					dc.Polygon((*poly_it)->GetArr(), (*poly_it)->get_amount_edge());  //Draw Polygon
				}



				indexPoly++;
				poly_it++;
			}
			else if (type == "CircleC") {

				
				dc.Ellipse((*circle_it)->get_rekt());            //Draw CircleC
				INFOCircleC(shape_it, circle_it);



				indexCircleC++;
				circle_it++;
			}
			else if (type == "CircleP") {


				
				dc.Pie((*pie_it)->get_rekt(),
					(*pie_it)->get_angle_point()[0],
					(*pie_it)->get_angle_point()[1]);   //Draw CircleP
				INFOCircleP(shape_it, pie_it);

				indexCircleP++;
				pie_it++;
			}
			else {

				
				dc.Ellipse((*ellipse_it)->get_rekt());  //Draw Ellipse
				INFOCircleE(shape_it, ellipse_it);

				ellipse_it++;
				indexCircleE++;
			}
			
			i_color++;//index for color choosing
			//Draw line at end of info section
			if (index != 5) {  //dont draw the last line;
			dc.SelectObject(&penForAxis);
			dc.MoveTo(870, 125 + (*shape_it)->get_pos_shape_list() * 100);
			dc.LineTo(1330, 125 + (*shape_it)->get_pos_shape_list() * 100);
			}
		}


	}

}



// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COOPProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void COOPProjectDlg::INFOPoly(list <Shape*> ::iterator indexS, list <Poligon*> ::iterator indexP) {//delete here!!
	if (!(*indexS)->get_is_shown()) {

		arr_labels[(*indexS)->get_pos_shape_list()] = new CStatic * [(*indexP)->get_amount_edge() + 3];

		arr_sizes[(*indexS)->get_pos_shape_list()] = (*indexP)->get_amount_edge() + 3;

		for (int i = 0; i < (*indexP)->get_amount_edge() + 3; i++) {

			arr_labels[(*indexS)->get_pos_shape_list()][i] = new CStatic;

		}



		CString ctmp;
		ctmp.Format(_T("Type: %S"), (*indexP)->PrintType().c_str());

		arr_labels[(*indexS)->get_pos_shape_list()][0]->Create(ctmp, WS_CHILD | WS_VISIBLE,
			CRect(875, 35 + (*indexS)->get_pos_shape_list() * 100, 960, 70 + (*indexS)->get_pos_shape_list() * 100), this);

		ctmp.Format(_T("Area: %.2f"), (*indexS)->area());
		arr_labels[(*indexS)->get_pos_shape_list()][1]->Create(ctmp, WS_CHILD | WS_VISIBLE,
			CRect(990, 35 + (*indexS)->get_pos_shape_list() * 100, 1080, 70 + (*indexS)->get_pos_shape_list() * 100), this);

		ctmp.Format(_T("Parimeter: %.2f"), (*indexS)->perimeter());
		arr_labels[(*indexS)->get_pos_shape_list()][2]->Create(ctmp, WS_CHILD | WS_VISIBLE,
			CRect(1200, 35 + (*indexS)->get_pos_shape_list() * 100, 1300, 70 + (*indexS)->get_pos_shape_list() * 100), this);




		for (int i = 3; i < (*indexP)->get_amount_edge() + 3; i++) {


			ctmp.Format(_T("   %d: (%.1f,%.1f)"), (i - 2),
				(double)((*indexP)->get_fake_arr())[i - 3].x / 10, // note:delete/10
				(double)((*indexP)->get_fake_arr())[i - 3].y / 10);// note:delete/10


			arr_labels[(*indexS)->get_pos_shape_list()][i]->Create(ctmp, WS_CHILD | WS_VISIBLE | WS_BORDER,
				CRect(870 + (i - 3) * 55, 75 + (*indexS)->get_pos_shape_list() * 100, 930 + (i - 3) * 55, 115 + (*indexS)->get_pos_shape_list() * 100), this);

		}



		//pic test

		arr_Btn[(*indexS)->get_pos_shape_list()] = new CButton;
		arr_Btn[(*indexS)->get_pos_shape_list()]->Create(_T(""), WS_CHILD | WS_VISIBLE | BS_ICON , CRect(1333, 90 + (*indexS)->get_pos_shape_list() * 100, 1365, 122 + (*indexS)->get_pos_shape_list() * 100), this, RemoveBtn1 + (*indexS)->get_pos_shape_list());
		arr_Btn[(*indexS)->get_pos_shape_list()]->SetIcon(RemoveIcon);


		arr_EditBtn[(*indexS)->get_pos_shape_list()] = new CButton; 
		arr_EditBtn[(*indexS)->get_pos_shape_list()]->Create(_T(""), WS_CHILD | WS_VISIBLE | BS_ICON , CRect(1333, 58 + (*indexS)->get_pos_shape_list() * 100, 1365, 90 + (*indexS)->get_pos_shape_list() * 100), this, EditBtn1 + (*indexS)->get_pos_shape_list());
		arr_EditBtn[(*indexS)->get_pos_shape_list()]->SetIcon(EditIcon);
		

		(*indexS)->set_is_shown(TRUE);
	}
}

void COOPProjectDlg::INFOCircleC(list <Shape*> ::iterator indexS, list <Circle*> ::iterator indexC) {
	if (!(*indexS)->get_is_shown()) {


		arr_labels[(*indexS)->get_pos_shape_list()] = new CStatic * [4];
		arr_sizes[(*indexS)->get_pos_shape_list()] = 4;
		for (int i = 0; i < 4; i++) {

			arr_labels[(*indexS)->get_pos_shape_list()][i] = new CStatic;

		}



		CString ctmp;
		//ctmp.Format(_T("Type: %S"), (*indexS)->type().c_str());
		ctmp.Format(_T("Type: Circle"));

		arr_labels[(*indexS)->get_pos_shape_list()][0]->Create(ctmp, WS_CHILD | WS_VISIBLE,
			CRect(875, 35 + (*indexS)->get_pos_shape_list() * 100, 960, 70 + (*indexS)->get_pos_shape_list() * 100), this);

		ctmp.Format(_T("Area: %.2f"), (*indexS)->area());
		arr_labels[(*indexS)->get_pos_shape_list()][1]->Create(ctmp, WS_CHILD | WS_VISIBLE,
			CRect(990, 35 + (*indexS)->get_pos_shape_list() * 100, 1080, 70 + (*indexS)->get_pos_shape_list() * 100), this);

		ctmp.Format(_T("Parimeter: %.2f"), (*indexS)->perimeter());
		arr_labels[(*indexS)->get_pos_shape_list()][2]->Create(ctmp, WS_CHILD | WS_VISIBLE,
			CRect(1200, 35 + (*indexS)->get_pos_shape_list() * 100, 1300, 70 + (*indexS)->get_pos_shape_list() * 100), this);



		ctmp.Format(_T("Center Point: (%.1f,%.1f). Radius:%.1f"),
			(double)(*indexC)->get_center().x / 10,
			(double)(*indexC)->get_center().y / 10,
			(*indexC)->get_radius());


		arr_labels[(*indexS)->get_pos_shape_list()][3]->Create(ctmp, WS_CHILD | WS_VISIBLE,
			CRect(875, 75 + (*indexS)->get_pos_shape_list() * 100, 1200, 105 + (*indexS)->get_pos_shape_list() * 100), this);


		arr_Btn[(*indexS)->get_pos_shape_list()] = new CButton;
		arr_Btn[(*indexS)->get_pos_shape_list()]->Create(_T("Del."), WS_CHILD | WS_VISIBLE | BS_ICON , CRect(1333, 90 + (*indexS)->get_pos_shape_list() * 100, 1365, 122 + (*indexS)->get_pos_shape_list() * 100), this, RemoveBtn1 + (*indexS)->get_pos_shape_list());
		arr_Btn[(*indexS)->get_pos_shape_list()]->SetIcon(RemoveIcon);

		arr_EditBtn[(*indexS)->get_pos_shape_list()] = new CButton; 
		arr_EditBtn[(*indexS)->get_pos_shape_list()]->Create(_T(""), WS_CHILD | WS_VISIBLE | BS_ICON, CRect(1333, 58 + (*indexS)->get_pos_shape_list() * 100, 1365, 90 + (*indexS)->get_pos_shape_list() * 100), this, EditBtn1 + (*indexS)->get_pos_shape_list());
		arr_EditBtn[(*indexS)->get_pos_shape_list()]->SetIcon(EditIcon);

		(*indexS)->set_is_shown(TRUE);
	}





}

void COOPProjectDlg::INFOCircleE(list <Shape*> ::iterator indexS, list <ellipse*> ::iterator indexE)
{
	if (!(*indexS)->get_is_shown()) {

		arr_labels[(*indexS)->get_pos_shape_list()] = new CStatic * [4];
		arr_sizes[(*indexS)->get_pos_shape_list()] = 4;
		for (int i = 0; i < 4; i++) {

			arr_labels[(*indexS)->get_pos_shape_list()][i] = new CStatic;

		}



		CString ctmp;
		ctmp.Format(_T("Type: Ellipse"));

		arr_labels[(*indexS)->get_pos_shape_list()][0]->Create(ctmp, WS_CHILD | WS_VISIBLE,
			CRect(875, 35 + (*indexS)->get_pos_shape_list() * 100, 960, 70 + (*indexS)->get_pos_shape_list() * 100), this);

		ctmp.Format(_T("Area: %.2f"), (*indexS)->area());
		arr_labels[(*indexS)->get_pos_shape_list()][1]->Create(ctmp, WS_CHILD | WS_VISIBLE,
			CRect(990, 35 + (*indexS)->get_pos_shape_list() * 100, 1080, 70 + (*indexS)->get_pos_shape_list() * 100), this);

		ctmp.Format(_T("Parimeter: %.2f"), (*indexS)->perimeter());
		arr_labels[(*indexS)->get_pos_shape_list()][2]->Create(ctmp, WS_CHILD | WS_VISIBLE,
			CRect(1200, 35 + (*indexS)->get_pos_shape_list() * 100, 1300, 70 + (*indexS)->get_pos_shape_list() * 100), this);







		ctmp.Format(_T("Bottom Left:(%.1f,%.1f) ,  Top Right:(%.1f,%.1f)"),
			(double)(*indexE)->get_lp().x / 10,
			(double)(*indexE)->get_lp().y / 10,
			(double)(*indexE)->get_rp().x / 10,
			(double)(*indexE)->get_rp().y / 10);



		arr_labels[(*indexS)->get_pos_shape_list()][3]->Create(ctmp, WS_CHILD | WS_VISIBLE,
			CRect(875, 75 + (*indexS)->get_pos_shape_list() * 100, 1200, 105 + (*indexS)->get_pos_shape_list() * 100), this);


		arr_Btn[(*indexS)->get_pos_shape_list()] = new CButton;
		arr_Btn[(*indexS)->get_pos_shape_list()]->Create(_T("Del."), WS_CHILD | WS_VISIBLE | BS_ICON , CRect(1333, 90 + (*indexS)->get_pos_shape_list() * 100, 1365, 122 + (*indexS)->get_pos_shape_list() * 100), this, RemoveBtn1 + (*indexS)->get_pos_shape_list());
		arr_Btn[(*indexS)->get_pos_shape_list()]->SetIcon(RemoveIcon);

		arr_EditBtn[(*indexS)->get_pos_shape_list()] = new CButton; 
		arr_EditBtn[(*indexS)->get_pos_shape_list()]->Create(_T(""), WS_CHILD | WS_VISIBLE | BS_ICON, CRect(1333, 58 + (*indexS)->get_pos_shape_list() * 100, 1365, 90 + (*indexS)->get_pos_shape_list() * 100), this, EditBtn1 + (*indexS)->get_pos_shape_list());
		arr_EditBtn[(*indexS)->get_pos_shape_list()]->SetIcon(EditIcon);

		(*indexS)->set_is_shown(TRUE);
	}
}

void COOPProjectDlg::INFOCircleP(list <Shape*> ::iterator indexS, list <pie*> ::iterator indexP)
{
	if (!(*indexS)->get_is_shown()) {

		arr_labels[(*indexS)->get_pos_shape_list()] = new CStatic * [5];
		arr_sizes[(*indexS)->get_pos_shape_list()] = 5;
		for (int i = 0; i < 5; i++) {

			arr_labels[(*indexS)->get_pos_shape_list()][i] = new CStatic;

		}

		



		CString ctmp;
		ctmp.Format(_T("Type: Pie"));

		arr_labels[(*indexS)->get_pos_shape_list()][0]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(875, 35 + (*indexS)->get_pos_shape_list() * 100, 960, 70 + (*indexS)->get_pos_shape_list() * 100), this);

		ctmp.Format(_T("Area: %f"), (*indexS)->area());
		arr_labels[(*indexS)->get_pos_shape_list()][1]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(990, 35 + (*indexS)->get_pos_shape_list() * 100, 1080, 70 + (*indexS)->get_pos_shape_list() * 100), this);

		ctmp.Format(_T("Parimeter: %f"), (*indexS)->perimeter());
		arr_labels[(*indexS)->get_pos_shape_list()][2]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(1200, 35 + (*indexS)->get_pos_shape_list() * 100, 1300, 70 + (*indexS)->get_pos_shape_list() * 100), this);



		ctmp.Format(_T("Center Point: (%.1f,%.1f). Radius:%.1f. Angle:%.1f"),
			(double)(*indexP)->get_center().x / 10,
			(double)(*indexP)->get_center().y / 10,
			(double)(*indexP)->get_radius(),
			(*indexP)->get_angle());

		arr_labels[(*indexS)->get_pos_shape_list()][3]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(875, 75 + (*indexS)->get_pos_shape_list() * 100, 1200, 95 + (*indexS)->get_pos_shape_list() * 100), this);

		ctmp.Format(_T("Start Point:(%.1f,%.1f) ,  End Point:(%.1f,%.1f)"),
			(double)(*indexP)->get_start_angle().x / 10,
			(double)(*indexP)->get_start_angle().y / 10,
			(double)(*indexP)->get_end_angle().x / 10,
			(double)(*indexP)->get_end_angle().y / 10);

		arr_labels[(*indexS)->get_pos_shape_list()][4]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(875, 100 + (*indexS)->get_pos_shape_list() * 100, 1200, 120 + (*indexS)->get_pos_shape_list() * 100), this);

		

		


		arr_Btn[(*indexS)->get_pos_shape_list()] = new CButton;
		arr_Btn[(*indexS)->get_pos_shape_list()]->Create(_T("Del."), WS_CHILD | WS_VISIBLE | BS_ICON , CRect(1333, 90 + (*indexS)->get_pos_shape_list() * 100, 1365, 122 + (*indexS)->get_pos_shape_list() * 100), this, RemoveBtn1 + (*indexS)->get_pos_shape_list());
		arr_Btn[(*indexS)->get_pos_shape_list()]->SetIcon(RemoveIcon);

		arr_EditBtn[(*indexS)->get_pos_shape_list()] = new CButton; 
		arr_EditBtn[(*indexS)->get_pos_shape_list()]->Create(_T(""), WS_CHILD | WS_VISIBLE | BS_ICON, CRect(1333, 58 + (*indexS)->get_pos_shape_list() * 100, 1365, 90 + (*indexS)->get_pos_shape_list() * 100), this, EditBtn1 + (*indexS)->get_pos_shape_list());
		arr_EditBtn[(*indexS)->get_pos_shape_list()]->SetIcon(EditIcon);

		(*indexS)->set_is_shown(TRUE);
	}
}




void COOPProjectDlg::OnBnClickedButton1()//Open CONTROL dialog
{

	m_controls.ShowWindow(SW_SHOW);
}


HBRUSH COOPProjectDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)  //Set Background
{
	//if (nCtlColor == 4) {
	//	SetBkMode(pDC->GetSafeHdc(),TRANSPARENT);
	//	return (HBRUSH)GetStockObject(NULL_BRUSH);
	//}
	
	return (HBRUSH)GetStockObject(DC_BRUSH);
	
}



void COOPProjectDlg::delete_shape(int pos_in_shape)//deletes selected shape
{
	
	
	
    list <Shape*> ::iterator S_it;
	
    delete_buttons();
    S_it = m_controls.m_TAB1.ShapeList.begin();
    advance(S_it, pos_in_shape);

	int position_delete;     //getting the position in the specifiec 'type of shape' list that we want to delete
	
	position_delete = (*S_it)->get_pos_type_list();

	//(*S_it)->set_pos_type_list(position_delete - 1);


	string type = (*S_it)->type();//checking type of shape
	int color_index = (*S_it)->color_index;//get color index before deleting shape
	
	if (type == "Polygon") {
		list <Poligon*> ::iterator P_it = m_controls.m_TAB1.PolyList.begin();
		
		
		advance(P_it, position_delete);
		POSITION pos = m_controls.m_TAB1.polygon_shapes.Find((*P_it));
		m_controls.m_TAB1.polygon_shapes.RemoveAt(pos);
		
		
		delete[] (*P_it);
 
		m_controls.m_TAB1.PolyList.erase(P_it);

		m_controls.m_TAB1.CurrentPose_poly--;
		
	}
	else if (type == "CircleC") {

		list <Circle*> ::iterator C_it = m_controls.m_TAB1.CircleCList.begin();
		advance(C_it, position_delete);
		
		POSITION pos = m_controls.m_TAB1.circle_shapes.Find((*C_it));
		m_controls.m_TAB1.circle_shapes.RemoveAt(pos);

		delete[](*C_it);

		m_controls.m_TAB1.CircleCList.erase(C_it);
		

		

		m_controls.m_TAB1.CurrentPose_circle_c--;
		m_controls.m_TAB1.CurrentPose_circle--;

	}
	else if (type == "CircleP") {

		list <pie*> ::iterator pie_it  = m_controls.m_TAB1.CirclePList.begin();
		advance(pie_it, position_delete);
		
		POSITION pos = m_controls.m_TAB1.pie_shapes.Find((*pie_it));
		m_controls.m_TAB1.pie_shapes.RemoveAt(pos);

		delete[](*pie_it);
		m_controls.m_TAB1.CirclePList.erase(pie_it);

		

		m_controls.m_TAB1.CurrentPose_circle_p--;
		m_controls.m_TAB1.CurrentPose_circle--;


	}
	else {    //delete ellipse

		list <ellipse*> ::iterator e_it = m_controls.m_TAB1.CircleEList.begin();
		
		advance(e_it, position_delete);

		POSITION pos = m_controls.m_TAB1.ellipse_shapes.Find((*e_it));
		m_controls.m_TAB1.ellipse_shapes.RemoveAt(pos);


		delete[](*e_it);
		m_controls.m_TAB1.CircleEList.erase(e_it);
		
		m_controls.m_TAB1.CurrentPose_circle_e--;
		m_controls.m_TAB1.CurrentPose_circle--;

	}
	
	arr_check_color[color_index] = false;

	S_it=m_controls.m_TAB1.ShapeList.erase(S_it);//deleting in shapelist as well
	m_controls.m_TAB1.CurrentPose_shape--;
	
	
	for (; S_it != m_controls.m_TAB1.ShapeList.end(); S_it++) {   //WORST Function ever omfgggg
		if ((*S_it)->type() == type) {
			int x = (*S_it)->get_pos_type_list();
			(*S_it)->set_pos_type_list(--x);   //change the index of all other objects in the specifiec list
			
		}
		
		int y = (*S_it)->get_pos_shape_list();
		(*S_it)->set_pos_shape_list(--y);
		
	}


	RedrawWindow();
}
void COOPProjectDlg::delete_arr_labels()//delete arr_labels
{
	int i, j = 0;

	for (i = 0; i < m_controls.m_TAB1.CurrentPose_shape; i++)//deleting info labels array
	{

		for (j = 0; j < arr_sizes[i]; j++)
		{
			delete(arr_labels[i][j]);
		}
		delete[] arr_labels[i];
	}
}


void COOPProjectDlg::OnBnClickedSave()
{
	// TODO: Add your control notification handler code here
	const TCHAR czFilter[] = _T("Axis files (*.axis)|*.axis|All FIles (*.*)|*.*");

	CFileDialog fDialog(FALSE, _T("axis"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, czFilter, this);

	if (fDialog.DoModal() == IDOK) {
		CFile file(fDialog.GetPathName(), CFile::modeCreate | CFile::modeWrite);
		SaveCircle(fDialog);
		SaveEllipse(fDialog);
		SavePoli(fDialog);
		SavePie(fDialog);
		file.Close();
	}
}


void COOPProjectDlg::OnBnClickedLoad()
{
	// TODO: Add your control notification handler code here
	

	const TCHAR czFilter[] = _T("Axis files (*.axis)|*.axis|All FIles (*.*)|*.*");

	CFileDialog fDialog(TRUE, _T("axis"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, czFilter, this);
	
	if (fDialog.DoModal() == IDOK) {
		
		DeleteScreen();//makes sure nothing is on the screen before loading
		

		
		LoadEllipse(fDialog);
		LoadCircle(fDialog);
		LoadPoli(fDialog);
		LoadPie(fDialog);


		
		
		circle_it = m_controls.m_TAB1.CircleCList.begin();
		ellipse_it= m_controls.m_TAB1.CircleEList.begin();
		pie_it= m_controls.m_TAB1.CirclePList.begin();
		poly_it=m_controls.m_TAB1.PolyList.begin();
		
		int index = 0;
		for( ; circle_it !=m_controls.m_TAB1.CircleCList.end() ||
			ellipse_it!= m_controls.m_TAB1.CircleEList.end() || 
			pie_it!= m_controls.m_TAB1.CirclePList.end() || 
			poly_it!= m_controls.m_TAB1.PolyList.end();){

			if (circle_it != m_controls.m_TAB1.CircleCList.end() &&(m_controls.m_TAB1.CircleCList.size()>0) &&(*circle_it)->get_pos_shape_list() == index) {
			 m_controls.m_TAB1.ShapeList.push_back((*circle_it));
			 
			
			 circle_it++;

			}
			else if (ellipse_it!= m_controls.m_TAB1.CircleEList.end() && (m_controls.m_TAB1.CircleEList.size()>0)&&(*ellipse_it)->get_pos_shape_list() == index) {
				m_controls.m_TAB1.ShapeList.push_back((*ellipse_it));
				
				ellipse_it++;
			}
			else if (pie_it!=m_controls.m_TAB1.CirclePList.end()&&(m_controls.m_TAB1.CirclePList.size()>0)&&(*pie_it)->get_pos_shape_list() == index) {
				m_controls.m_TAB1.ShapeList.push_back((*pie_it));
			
				pie_it++;
			}
			else if(poly_it!= m_controls.m_TAB1.PolyList.end() && (m_controls.m_TAB1.PolyList.size()>0) && (*poly_it)->get_pos_shape_list() == index)
			{
				m_controls.m_TAB1.ShapeList.push_back((*poly_it));
				
				poly_it++;
			}

			
			shape_it = m_controls.m_TAB1.ShapeList.begin(); advance(shape_it, index);
			arr_check_color[(*shape_it)->get_color()] = true;        //Set the color as taken
			//shape_it++;
			index++;
		}

		
		RedrawWindow();
	}
}



void COOPProjectDlg::SaveCircle(CFileDialog & fDialog) {
	CString filename = fDialog.GetFolderPath() + "\\Circle.crc";

	CFile file(filename, CFile::modeCreate | CFile::modeWrite);

	CArchive ar(&file, CArchive::store);




	m_controls.m_TAB1.circle_shapes.Serialize(ar);

	ar.Close();
	file.Close();
}

void COOPProjectDlg::LoadCircle(CFileDialog & fDialog) 
{
	
	   

	CString filename = fDialog.GetFolderPath() + "\\Circle.crc";


	CFile file(filename, CFile::modeRead);
		
	CArchive ar(&file, CArchive::load);
		
	
	
	
	
	m_controls.m_TAB1.circle_shapes.Serialize(ar);
		
		
		


	//circle
	POSITION pos = m_controls.m_TAB1.circle_shapes.GetHeadPosition();
	while (pos != NULL) {
		m_controls.m_TAB1.CurrentPose_shape++;
		m_controls.m_TAB1.CurrentPose_circle++;
		m_controls.m_TAB1.CurrentPose_circle_c++;
		m_controls.m_TAB1.CircleCList.push_back(m_controls.m_TAB1.circle_shapes.GetNext(pos));
	}
		
		
	//for (circle_it = m_controls.m_TAB1.CircleCList.begin();
	//		circle_it != m_controls.m_TAB1.CircleCList.end();circle_it++) {

	//	m_controls.m_TAB1.ShapeList.push_back((*circle_it));
	//}
		
		
		
	file.Close();
	ar.Close();
		
	
}





void COOPProjectDlg::SaveEllipse(CFileDialog& fDialog) {
	CString filename = fDialog.GetFolderPath() + "\\Ellipse.crc";

	CFile file(filename, CFile::modeCreate | CFile::modeWrite);

	CArchive ar(&file, CArchive::store);




	m_controls.m_TAB1.ellipse_shapes.Serialize(ar);

	ar.Close();
	file.Close();
}


void COOPProjectDlg::LoadEllipse(CFileDialog& fDialog)
{

	CString filename = fDialog.GetFolderPath() + "\\Ellipse.crc";


	CFile file(filename, CFile::modeRead);

	CArchive ar(&file, CArchive::load);





	m_controls.m_TAB1.ellipse_shapes.Serialize(ar);





	//ellipsa
	POSITION pos = m_controls.m_TAB1.ellipse_shapes.GetHeadPosition();
	while (pos != NULL) {
		m_controls.m_TAB1.CurrentPose_shape++;
		m_controls.m_TAB1.CurrentPose_circle++;
		m_controls.m_TAB1.CurrentPose_circle_e++;
		m_controls.m_TAB1.CircleEList.push_back(m_controls.m_TAB1.ellipse_shapes.GetNext(pos));
	}


	//for (ellipse_it = m_controls.m_TAB1.CircleEList.begin();
	//	ellipse_it != m_controls.m_TAB1.CircleEList.end(); ellipse_it++) {

	//	m_controls.m_TAB1.ShapeList.push_back((*ellipse_it));
	//}



	file.Close();
	ar.Close();

	
}



void COOPProjectDlg::SavePoli(CFileDialog & fDialog) {
	CString filename = fDialog.GetFolderPath() + "\\Poly.crc";

	CFile file(filename, CFile::modeCreate | CFile::modeWrite);

	CArchive ar(&file, CArchive::store);




	m_controls.m_TAB1.polygon_shapes.Serialize(ar);

	ar.Close();
	file.Close();
}


void COOPProjectDlg::LoadPoli(CFileDialog & fDialog) 
{
	
	   

	CString filename = fDialog.GetFolderPath() + "\\Poly.crc";


	CFile file(filename, CFile::modeRead);
		
	CArchive ar(&file, CArchive::load);
		
	
	
	
	
	m_controls.m_TAB1.polygon_shapes.Serialize(ar);
		
		
	POSITION pos = m_controls.m_TAB1.polygon_shapes.GetHeadPosition();
	while (pos != NULL) {
		m_controls.m_TAB1.CurrentPose_shape++;
		m_controls.m_TAB1.CurrentPose_poly++;
		m_controls.m_TAB1.PolyList.push_back(m_controls.m_TAB1.polygon_shapes.GetNext(pos));
	}
		
		
	//for (poly_it = m_controls.m_TAB1.PolyList.begin();
	//		poly_it != m_controls.m_TAB1.PolyList.end();poly_it++) {

	//	m_controls.m_TAB1.ShapeList.push_back((*poly_it));
	//}
		
		
		
	file.Close();
	ar.Close();
		

}

void COOPProjectDlg::LoadPie(CFileDialog & fDialog) 
{
	
	   

	CString filename = fDialog.GetFolderPath() + "\\Pie.crc";


	CFile file(filename, CFile::modeRead);
		
	CArchive ar(&file, CArchive::load);
		
	
	
	
	
	m_controls.m_TAB1.pie_shapes.Serialize(ar);
		
		
		


	//circle
	POSITION pos = m_controls.m_TAB1.pie_shapes.GetHeadPosition();
	while (pos != NULL) {
		m_controls.m_TAB1.CurrentPose_shape++;
		m_controls.m_TAB1.CurrentPose_circle_p++;
		m_controls.m_TAB1.CirclePList.push_back(m_controls.m_TAB1.pie_shapes.GetNext(pos));
	}
		
		
	//for (pie_it = m_controls.m_TAB1.CirclePList.begin();
	//		pie_it != m_controls.m_TAB1.CirclePList.end();pie_it++) {

	//	m_controls.m_TAB1.ShapeList.push_back((*pie_it));
	//}
		
		
		
	file.Close();
	ar.Close();
		
	
}

void COOPProjectDlg::SavePie(CFileDialog & fDialog) {
	CString filename = fDialog.GetFolderPath() + "\\Pie.crc";

	CFile file(filename, CFile::modeCreate | CFile::modeWrite);

	CArchive ar(&file, CArchive::store);




	m_controls.m_TAB1.pie_shapes.Serialize(ar);

	ar.Close();
	file.Close();
}

void COOPProjectDlg::DeleteScreen()
{
    
	m_controls.m_TAB1.CurrentPose_shape = 0;//reset count of shapes
	m_controls.m_TAB1.CurrentPose_circle = 0;//reset count of circle
	m_controls.m_TAB1.CurrentPose_circle_c = 0;//reset count of circleC
	m_controls.m_TAB1.CurrentPose_circle_e = 0;//reset count of circleE
	m_controls.m_TAB1.CurrentPose_poly = 0;//reset count of poly
	m_controls.m_TAB1.CurrentPose_circle_p = 0;//reset count of poly
    list <Shape*>::iterator it;
		
	for(it=m_controls.m_TAB1.ShapeList.begin();it != m_controls.m_TAB1.ShapeList.end();it++){//deleting shape array

			
		if ((*it)->is_shown == true)
		{

			delete arr_Btn[(*it)->get_pos_shape_list()];//deleting existing buttons
			delete arr_EditBtn[(*it)->get_pos_shape_list()];//deleting existing buttons
		}
		delete[] * it;
	}

	
	//deleting x y number labels on grid
	
	
	

	m_controls.m_TAB1.circle_shapes.RemoveAll();
	m_controls.m_TAB1.ellipse_shapes.RemoveAll();
	m_controls.m_TAB1.polygon_shapes.RemoveAll();
	m_controls.m_TAB1.pie_shapes.RemoveAll();

	m_controls.m_TAB1.ShapeList.clear();
	m_controls.m_TAB1.CircleCList.clear();
	m_controls.m_TAB1.CircleEList.clear();
	m_controls.m_TAB1.CirclePList.clear();
	m_controls.m_TAB1.PolyList.clear();
}


void COOPProjectDlg::edit_func(int position)
{
  

  

   shape_it = m_controls.m_TAB1.ShapeList.begin();
   advance(shape_it, position - 1);
   int amount = -1;

   
   if ((*shape_it)->type() == "Polygon") {
	   poly_it = m_controls.m_TAB1.PolyList.begin();
	   advance(poly_it, (*shape_it)->get_pos_type_list());
	   amount = (*poly_it)->get_amount_edge();
		
   }
   else if ((*shape_it)->type() == "CircleC") {
	   circle_it = m_controls.m_TAB1.CircleCList.begin();
	   advance(circle_it, (*shape_it)->get_pos_type_list());
	   amount = 3;

   }
   else if ((*shape_it)->type() == "CircleE") {

	   ellipse_it = m_controls.m_TAB1.CircleEList.begin();
	   advance(ellipse_it, (*shape_it)->get_pos_type_list());
	   amount = 4;
   }

   else {
	   pie_it = m_controls.m_TAB1.CirclePList.begin();
	   advance(pie_it, (*shape_it)->get_pos_type_list());
	   amount = 8;
   }

   
   EDIT* m_edit = new EDIT(amount,(*shape_it)->type(),this);
  
   
   if (m_edit->DoModal() == IDOK) {
	   

	   if ((*shape_it)->type() == "Polygon") {
	        //shape functions
			m_edit->poly_ptr->set_pos_type_list((*shape_it)->get_pos_type_list());
			m_edit->poly_ptr->set_pos_shape_list((*shape_it)->get_pos_type_list());
			m_edit->poly_ptr->set_color((*shape_it)->get_color());


			POSITION pos = m_controls.m_TAB1.polygon_shapes.Find((*poly_it));
			m_controls.m_TAB1.polygon_shapes.InsertBefore(pos, m_edit->poly_ptr);
			m_controls.m_TAB1.polygon_shapes.RemoveAt(pos);  //remove old item from weird list
			
			
			

			
			m_controls.m_TAB1.ShapeList.insert(shape_it, m_edit->poly_ptr);
			m_controls.m_TAB1.ShapeList.remove((*shape_it));      // remove old shape
			m_controls.m_TAB1.PolyList.insert(poly_it, m_edit->poly_ptr); 
			m_controls.m_TAB1.PolyList.remove((*poly_it));       // remove old shape from poly list
			
			
	   }

	   else if ((*shape_it)->type() == "CircleC") {
	   

		   m_edit->circle_ptr->set_pos_type_list((*shape_it)->get_pos_type_list());
		   m_edit->circle_ptr->set_pos_shape_list((*shape_it)->get_pos_type_list());
		   m_edit->circle_ptr->set_color((*shape_it)->get_color());


		   POSITION pos = m_controls.m_TAB1.circle_shapes.Find((*circle_it));
		   m_controls.m_TAB1.circle_shapes.InsertBefore(pos, m_edit->circle_ptr);
		   m_controls.m_TAB1.circle_shapes.RemoveAt(pos);  //remove old item from weird list





		   m_controls.m_TAB1.ShapeList.insert(shape_it, m_edit->circle_ptr);
		   m_controls.m_TAB1.ShapeList.remove((*shape_it));      // remove old shape
		   m_controls.m_TAB1.CircleCList.insert(circle_it, m_edit->circle_ptr);
		   m_controls.m_TAB1.CircleCList.remove((*circle_it));       // remove old shape from poly list
	   
	   }
	   else if ((*shape_it)->type() == "CircleE") {

		   m_edit->ellipse_ptr->set_pos_type_list((*shape_it)->get_pos_type_list());
		   m_edit->ellipse_ptr->set_pos_shape_list((*shape_it)->get_pos_type_list());
		   m_edit->ellipse_ptr->set_color((*shape_it)->get_color());


		   POSITION pos = m_controls.m_TAB1.ellipse_shapes.Find((*ellipse_it));
		   m_controls.m_TAB1.ellipse_shapes.InsertBefore(pos, m_edit->ellipse_ptr);
		   m_controls.m_TAB1.ellipse_shapes.RemoveAt(pos);  //remove old item from weird list





		   m_controls.m_TAB1.ShapeList.insert(shape_it, m_edit->ellipse_ptr);
		   m_controls.m_TAB1.ShapeList.remove((*shape_it));      // remove old shape
		   m_controls.m_TAB1.CircleEList.insert(ellipse_it, m_edit->ellipse_ptr);
		   m_controls.m_TAB1.CircleEList.remove((*ellipse_it));       // remove old shape from poly list
	   }

	   else {

		   m_edit->pie_ptr->set_pos_type_list((*shape_it)->get_pos_type_list());
		   m_edit->pie_ptr->set_pos_shape_list((*shape_it)->get_pos_type_list());
		   m_edit->pie_ptr->set_color((*shape_it)->get_color());


		   POSITION pos = m_controls.m_TAB1.pie_shapes.Find((*pie_it));
		   m_controls.m_TAB1.pie_shapes.InsertBefore(pos, m_edit->pie_ptr);
		   m_controls.m_TAB1.pie_shapes.RemoveAt(pos);  //remove old item from weird list





		   m_controls.m_TAB1.ShapeList.insert(shape_it, m_edit->pie_ptr);
		   m_controls.m_TAB1.ShapeList.remove((*shape_it));      // remove old shape
		   m_controls.m_TAB1.CirclePList.insert(pie_it, m_edit->pie_ptr);
		   m_controls.m_TAB1.CirclePList.remove((*pie_it));       // remove old shape from pie list
	   }





	   delete_buttons();


	   RedrawWindow();
   }

   
   delete m_edit;
}

void COOPProjectDlg::delete_buttons()
{

     list <Shape*> ::iterator S_it;
	   //deleting buttons
	   delete_arr_labels();
	   int i = 0;
	   for (S_it = m_controls.m_TAB1.ShapeList.begin(); S_it != m_controls.m_TAB1.ShapeList.end(); S_it++, i++) {
		   delete arr_Btn[i];
		   delete arr_EditBtn[i];

		   (*S_it)->set_is_shown(false);

	   }
	   
}



