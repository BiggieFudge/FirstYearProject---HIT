
// OOP_ProjectDlg.cpp : implementation file
//


#include "pch.h"
#include "framework.h"
#include "OOP_Project.h"
#include "OOP_ProjectDlg.h"
#include "afxdialogex.h"
#include "CONTROLS.h"
#include "AXIS.h"
#include <iostream>
#include <string.h>




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
	if (change == false) {  CenterWindow(); change = true; }

    
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
		dc.LineTo(SquareSide * 11, SquareSide*21); //draw Y axis
		dc.MoveTo(SquareSide, SquareSide*11);
		dc.LineTo(SquareSide*21, SquareSide * 11); //draw X axis

		//create frame around show_All;
		dc.MoveTo(869,29);
		dc.LineTo(1201,29);
		dc.LineTo(1201, 581);
		dc.LineTo(869, 581);
		dc.LineTo(869, 29);

		

		
		
		CPen penForShapes;
		
		

		int indexPoly = 0, indexCircleC = 0, indexCircleP = 0, indexCircleE = 0;     // Create and reset index's
		for (int i = 0; i < m_controls.m_TAB1.CurrentPose_shape; i++) {   //Test To print shapes
			
			string type = (m_controls.m_TAB1.ShapeArr[i])->type();


			if ((m_controls.m_TAB1.ShapeArr[i])->get_color() == -1){
					(m_controls.m_TAB1.ShapeArr[i])->set_color(i);
			}
			penForShapes.DeleteObject();
			penForShapes.CreatePen(PS_SOLID, 4, arr_color[(m_controls.m_TAB1.ShapeArr[i])->get_color()]); //Change Color according to shape.color
			dc.SelectObject(&penForShapes);

			

			if (type == "Poly") {
				
				dc.Polygon(m_controls.m_TAB1.PolyArr[indexPoly]->GetArr(),             //Draw poly
					m_controls.m_TAB1.PolyArr[indexPoly]->get_amount_edge());
				INFOPoly(i, indexPoly);
				indexPoly++;
			}
			else if (type == "CircleC") {
				
				dc.Ellipse(m_controls.m_TAB1.CircleArr_C[indexCircleC]->get_rekt());    //Draw CircleC
				INFOCircleC(i, indexCircleC);
				indexCircleC++;
			}
			else if (type == "CircleP") {

				
				dc.Pie(m_controls.m_TAB1.CircleArr_P[indexCircleP]->get_rekt(),
					(m_controls.m_TAB1.CircleArr_P[indexCircleP]->get_angle_point())[0],
					(m_controls.m_TAB1.CircleArr_P[indexCircleP]->get_angle_point())[1]);
				INFOCircleP(i, indexCircleP);
				indexCircleP++;
			}
			else {
			     
			    
				dc.Ellipse(m_controls.m_TAB1.CircleArr_E[indexCircleE]->get_rekt());
				INFOCircleE(i, indexCircleE);
				indexCircleE++;
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


void COOPProjectDlg::INFOPoly(int indexS,int indexP){//delete here!!
	if (!(m_controls.m_TAB1.ShapeArr[indexS])->get_is_shown()) {
		
		arr_labels[indexS] = new CStatic*[(m_controls.m_TAB1.PolyArr[indexP])->get_amount_edge() + 3];

		arr_sizes[indexS] = (m_controls.m_TAB1.PolyArr[indexP])->get_amount_edge() + 3;

		for (int i = 0; i < (m_controls.m_TAB1.PolyArr[indexP])->get_amount_edge() + 3; i++) {
			
			arr_labels[indexS][i] = new CStatic;

		}
		


		CString ctmp;
	    ctmp.Format(_T("Type: %S"), (m_controls.m_TAB1.ShapeArr[indexS])->type().c_str());
		
		arr_labels[indexS][0]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(875,35+ indexS*100,960,70 + indexS * 100),this);

	    ctmp.Format(_T("Area: %.2f"), (m_controls.m_TAB1.ShapeArr[indexS])->area());
		arr_labels[indexS][1]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(990,35+ indexS*100,1080,70 + indexS * 100),this);

		ctmp.Format(_T("Parimeter: %.2f"), (m_controls.m_TAB1.ShapeArr[indexS])->perimeter());
		arr_labels[indexS][2]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(1100,35+ indexS*100,1200,70 + indexS * 100),this);



	
		for (int i = 3; i < (m_controls.m_TAB1.PolyArr[indexP])->get_amount_edge()+3;i++){

		
			ctmp.Format(_T(" %d: (%d,%d)"),(i-2) ,
				(((m_controls.m_TAB1.PolyArr[indexP])->get_fake_arr())[i - 3].x), 
				((m_controls.m_TAB1.PolyArr[indexP])->get_fake_arr())[i - 3].y);

			
			arr_labels[indexS][i]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(875 +(i-3)* 35, 75 + indexS * 100, 910 + (i - 3) * 35, 105 + indexS * 100), this);
		}
		


		
		(m_controls.m_TAB1.ShapeArr[indexS])->set_is_shown(TRUE);
	}
}

void COOPProjectDlg::INFOCircleC(int indexS, int indexC){
	if (!(m_controls.m_TAB1.ShapeArr[indexS])->get_is_shown()) {


		arr_labels[indexS] = new CStatic * [4];
		arr_sizes[indexS] = 4;
		for (int i = 0; i < 4; i++) {

			arr_labels[indexS][i] = new CStatic;

		}



		CString ctmp;
		ctmp.Format(_T("Type: %S"), (m_controls.m_TAB1.ShapeArr[indexS])->type().c_str());

		arr_labels[indexS][0]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(875, 35 + indexS * 100, 960, 70 + indexS * 100), this);

		ctmp.Format(_T("Area: %.2f"), (m_controls.m_TAB1.ShapeArr[indexS])->area());
		arr_labels[indexS][1]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(990, 35 + indexS * 100, 1080, 70 + indexS * 100), this);

		ctmp.Format(_T("Parimeter: %.2f"), (m_controls.m_TAB1.ShapeArr[indexS])->perimeter());
		arr_labels[indexS][2]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(1100, 35 + indexS * 100, 1200, 70 + indexS * 100), this);

		

		ctmp.Format(_T("Center Point: (%d,%d). Radius:%.1f"),
				((m_controls.m_TAB1.CircleArr_C[indexC])->get_center()).x,
				(m_controls.m_TAB1.CircleArr_C[indexC])->get_center().y,
				(m_controls.m_TAB1.CircleArr_C[indexC])->get_radius());

	
			arr_labels[indexS][3]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(875 , 75 + indexS * 100, 1200, 105 + indexS * 100), this);
		




		(m_controls.m_TAB1.ShapeArr[indexS])->set_is_shown(TRUE);
	}





}

void COOPProjectDlg::INFOCircleE(int indexS, int indexE)
{
	if (!(m_controls.m_TAB1.ShapeArr[indexS])->get_is_shown()) {
		
			arr_labels[indexS] = new CStatic*[4];
			arr_sizes[indexS] = 4;
			for (int i = 0; i < 4; i++) {
			
				arr_labels[indexS][i] = new CStatic;

			}
		


			CString ctmp;
			ctmp.Format(_T("Type: %S"), (m_controls.m_TAB1.ShapeArr[indexS])->type().c_str());
		
			arr_labels[indexS][0]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(875,35+ indexS*100,960,70 + indexS * 100),this);

			ctmp.Format(_T("Area: %.2f"), (m_controls.m_TAB1.ShapeArr[indexS])->area());
			arr_labels[indexS][1]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(990,35+ indexS*100,1080,70 + indexS * 100),this);

			ctmp.Format(_T("Parimeter: %.2f"), (m_controls.m_TAB1.ShapeArr[indexS])->perimeter());
			arr_labels[indexS][2]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(1100,35+ indexS*100,1200,70 + indexS * 100),this);



	
			

		
			ctmp.Format(_T("Top Left:(%d,%d) ,  Bottom Right:(%d,%d)"),
				(m_controls.m_TAB1.CircleArr_E[indexE])->get_lp().x,
				((m_controls.m_TAB1.CircleArr_E[indexE])->get_lp()).y,
				((m_controls.m_TAB1.CircleArr_E[indexE])->get_rp()).x,
				((m_controls.m_TAB1.CircleArr_E[indexE])->get_rp()).y);


			
			arr_labels[indexS][3]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(875, 75 + indexS * 100, 1200, 105 + indexS * 100), this);
			
		


		
			(m_controls.m_TAB1.ShapeArr[indexS])->set_is_shown(TRUE);
		}
}

void COOPProjectDlg::INFOCircleP(int indexS , int indexP)
{
	if (!(m_controls.m_TAB1.ShapeArr[indexS])->get_is_shown()) {
		
			arr_labels[indexS] = new CStatic*[5];
			arr_sizes[indexS] = 5;
			for (int i = 0; i < 5; i++) {
			
				arr_labels[indexS][i] = new CStatic;

			}
		


			CString ctmp;
			ctmp.Format(_T("Type: %S"), (m_controls.m_TAB1.ShapeArr[indexS])->type().c_str());
		
			arr_labels[indexS][0]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(875,35+ indexS*100,960,70 + indexS * 100),this);

			ctmp.Format(_T("Area: %f"), (m_controls.m_TAB1.ShapeArr[indexS])->area());
			arr_labels[indexS][1]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(990,35+ indexS*100,1080,70 + indexS * 100),this);

			ctmp.Format(_T("Parimeter: %f"), (m_controls.m_TAB1.ShapeArr[indexS])->perimeter());
			arr_labels[indexS][2]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(1100,35+ indexS*100,1200,70 + indexS * 100),this);



	       ctmp.Format(_T("Top Left:(%d,%d) ,  Bottom Right:(%d,%d)"),
				(m_controls.m_TAB1.CircleArr_P[indexP])->get_lp().x,
				((m_controls.m_TAB1.CircleArr_P[indexP])->get_lp()).y,
				((m_controls.m_TAB1.CircleArr_P[indexP])->get_rp()).x,
				((m_controls.m_TAB1.CircleArr_P[indexP])->get_rp()).y);

			arr_labels[indexS][3]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(875, 75 + indexS * 100, 1200, 95 + indexS * 100), this);
			
			ctmp.Format(_T("Start angle:(%d,%d) ,  End angle:(%d,%d)"),
				(m_controls.m_TAB1.CircleArr_P[indexP])->get_start_angle().x,
				((m_controls.m_TAB1.CircleArr_P[indexP])->get_start_angle()).y,
				((m_controls.m_TAB1.CircleArr_P[indexP])->get_end_angle()).x,
				((m_controls.m_TAB1.CircleArr_P[indexP])->get_end_angle()).y);

			arr_labels[indexS][4]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(875, 100 + indexS * 100, 1200, 120 + indexS * 100), this);



		
			(m_controls.m_TAB1.ShapeArr[indexS])->set_is_shown(TRUE);
		}
}




void COOPProjectDlg::OnBnClickedButton1()//Open CONTROL dialog
{
	
	m_controls.ShowWindow(SW_SHOW);
}


HBRUSH COOPProjectDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)  //Set Background
{
	return (HBRUSH)GetStockObject(DC_BRUSH);
}





