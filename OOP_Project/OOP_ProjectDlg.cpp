
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
		
		
		int i_color = 0;//index for color choosing
		int indexPoly = 0, indexCircleC = 0, indexCircleP = 0, indexCircleE = 0;     // Create and reset index's
		
		
		list <Shape*> ::iterator shape_it;
		list <Poligon*> ::iterator poly_it = m_controls.m_TAB1.PolyList.begin();;
		list <Circle*> ::iterator circle_it = m_controls.m_TAB1.CircleCList.begin();
		list <ellipse*> ::iterator ellipse_it = m_controls.m_TAB1.CircleEList.begin();
		list <pie*> ::iterator pie_it= m_controls.m_TAB1.CirclePList.begin();


		dc.SelectStockObject(NULL_BRUSH);      //Set the background to be transparent.


		for (shape_it = m_controls.m_TAB1.ShapeList.begin(); shape_it != m_controls.m_TAB1.ShapeList.end(); shape_it++) {   //Test To print shapes
			
		

			string type = (*shape_it)->type();


			if ((*shape_it)->get_color() == -1){
				(*shape_it)->set_color(i_color);
			}
			penForShapes.DeleteObject();
			penForShapes.CreatePen(PS_SOLID, 4, arr_color[(*shape_it)->get_color()]); //Change Color according to shape.color
			dc.SelectObject(&penForShapes);
			
			

			if (type == "Poly") {
				
				
				dc.Polygon((*poly_it)->GetArr(), (*poly_it)->get_amount_edge());  //Draw Polygon
				INFOPoly(shape_it, poly_it);
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


		}


	}
	
}



// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COOPProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void COOPProjectDlg::INFOPoly(list <Shape*> ::iterator indexS,list <Poligon*> ::iterator indexP){//delete here!!
	if (!(*indexS)->get_is_shown()) {
		
		arr_labels[(*indexS)->get_color()] = new CStatic*[(*indexP)->get_amount_edge() + 3];

		arr_sizes[(*indexS)->get_color()] = (*indexP)->get_amount_edge() + 3;

		for (int i = 0; i < (*indexP)->get_amount_edge() + 3; i++) {
			
			arr_labels[(*indexS)->get_color()][i] = new CStatic;

		}
		


		CString ctmp;
	    ctmp.Format(_T("Type: %S"), (*indexS)->type().c_str());
		
		arr_labels[(*indexS)->get_color()][0]->Create(ctmp, WS_CHILD | WS_VISIBLE, 
			CRect(875,35+ (*indexS)->get_color() *100,960,70 + (*indexS)->get_color() * 100),this);

	    ctmp.Format(_T("Area: %.2f"), (*indexS)->area());
		arr_labels[(*indexS)->get_color()][1]->Create(ctmp, WS_CHILD | WS_VISIBLE, 
			CRect(990,35+ (*indexS)->get_color() *100,1080,70 + (*indexS)->get_color() * 100),this);

		ctmp.Format(_T("Parimeter: %.2f"), (*indexS)->perimeter());
		arr_labels[(*indexS)->get_color()][2]->Create(ctmp, WS_CHILD | WS_VISIBLE, 
			CRect(1100,35+ (*indexS)->get_color() *100,1200,70 + (*indexS)->get_color() * 100),this);



	
		for (int i = 3; i < (*indexP)->get_amount_edge()+3;i++){

		
			ctmp.Format(_T(" %d: (%d,%d)"),(i-2) ,
				((*indexP)->get_fake_arr())[i - 3].x, 
				((*indexP)->get_fake_arr())[i - 3].y);

			
			arr_labels[(*indexS)->get_color()][i]->Create(ctmp, WS_CHILD | WS_VISIBLE, 
				CRect(875 +(i-3)* 35, 75 + (*indexS)->get_color() * 100, 910 + (i - 3) * 35, 105 + (*indexS)->get_color() * 100), this);
		}
		


		
		(*indexS)->set_is_shown(TRUE);
	}
}

void COOPProjectDlg::INFOCircleC(list <Shape*> ::iterator indexS, list <Circle*> ::iterator indexC){
	if (!(*indexS)->get_is_shown()) {


		arr_labels[(*indexS)->get_color()] = new CStatic*[4];
		arr_sizes[(*indexS)->get_color()] = 4;
		for (int i = 0; i < 4; i++) {

			arr_labels[(*indexS)->get_color()][i] = new CStatic;

		}



		CString ctmp;
		ctmp.Format(_T("Type: %S"), (*indexS)->type().c_str());

		arr_labels[(*indexS)->get_color()][0]->Create(ctmp, WS_CHILD | WS_VISIBLE, 
			CRect(875, 35 + (*indexS)->get_color() * 100, 960, 70 + (*indexS)->get_color() * 100), this);

		ctmp.Format(_T("Area: %.2f"), (*indexS)->area());
		arr_labels[(*indexS)->get_color()][1]->Create(ctmp, WS_CHILD | WS_VISIBLE, 
			CRect(990, 35 + (*indexS)->get_color() * 100, 1080, 70 + (*indexS)->get_color() * 100), this);

		ctmp.Format(_T("Parimeter: %.2f"), (*indexS)->perimeter());
		arr_labels[(*indexS)->get_color()][2]->Create(ctmp, WS_CHILD | WS_VISIBLE, 
			CRect(1100, 35 + (*indexS)->get_color() * 100, 1200, 70 + (*indexS)->get_color() * 100), this);

		

		ctmp.Format(_T("Center Point: (%d,%d). Radius:%.1f"),
				(*indexC)->get_center().x,
				(*indexC)->get_center().y,
				(*indexC)->get_radius());

	
			arr_labels[(*indexS)->get_color()][3]->Create(ctmp, WS_CHILD | WS_VISIBLE, 
				CRect(875 , 75 + (*indexS)->get_color() * 100, 1200, 105 + (*indexS)->get_color() * 100), this);
		




		(*indexS)->set_is_shown(TRUE);
	}





}

void COOPProjectDlg::INFOCircleE(list <Shape*> ::iterator indexS, list <ellipse*> ::iterator indexE)
{
	if (!(*indexS)->get_is_shown()) {
		
			arr_labels[(*indexS)->get_color()] = new CStatic*[4];
			arr_sizes[(*indexS)->get_color()] = 4;
			for (int i = 0; i < 4; i++) {
			
				arr_labels[(*indexS)->get_color()][i] = new CStatic;

			}
		


			CString ctmp;
			ctmp.Format(_T("Type: %S"), (*indexS)->type().c_str());
		
			arr_labels[(*indexS)->get_color()][0]->Create(ctmp, WS_CHILD | WS_VISIBLE,
				CRect(875,35+ (*indexS)->get_color() *100,960,70 + (*indexS)->get_color() * 100),this);

			ctmp.Format(_T("Area: %.2f"), (*indexS)->area());
			arr_labels[(*indexS)->get_color()][1]->Create(ctmp, WS_CHILD | WS_VISIBLE,
				CRect(990,35+ (*indexS)->get_color() *100,1080,70 + (*indexS)->get_color() * 100),this);

			ctmp.Format(_T("Parimeter: %.2f"), (*indexS)->perimeter());
			arr_labels[(*indexS)->get_color()][2]->Create(ctmp, WS_CHILD | WS_VISIBLE,
				CRect(1100,35+ (*indexS)->get_color() *100,1200,70 + (*indexS)->get_color() * 100),this);



	
			

		
			ctmp.Format(_T("Top Left:(%d,%d) ,  Bottom Right:(%d,%d)"),
				(*indexE)->get_lp().x,
				(*indexE)->get_lp().y,
				(*indexE)->get_rp().x,
				(*indexE)->get_rp().y);


			
			arr_labels[(*indexS)->get_color()][3]->Create(ctmp, WS_CHILD | WS_VISIBLE,
				CRect(875, 75 + (*indexS)->get_color() * 100, 1200, 105 + (*indexS)->get_color() * 100), this);
			
		


		
			(*indexS)->set_is_shown(TRUE);
		}
}

void COOPProjectDlg::INFOCircleP(list <Shape*> ::iterator indexS, list <pie*> ::iterator indexP)
{
	if (!(*indexS)->get_is_shown()) {
		
			arr_labels[(*indexS)->get_color()] = new CStatic*[5];
			arr_sizes[(*indexS)->get_color()] = 5;
			for (int i = 0; i < 5; i++) {
			
				arr_labels[(*indexS)->get_color()][i] = new CStatic;

			}
		


			CString ctmp;
			ctmp.Format(_T("Type: %S"), (*indexS)->type().c_str());
		
			arr_labels[(*indexS)->get_color()][0]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(875,35+ (*indexS)->get_color()*100,960,70 + (*indexS)->get_color() * 100),this);

			ctmp.Format(_T("Area: %f"), (*indexS)->area());
			arr_labels[(*indexS)->get_color()][1]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(990,35+ (*indexS)->get_color()*100,1080,70 + (*indexS)->get_color() * 100),this);

			ctmp.Format(_T("Parimeter: %f"), (*indexS)->perimeter());
			arr_labels[(*indexS)->get_color()][2]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(1100,35+ (*indexS)->get_color()*100,1200,70 + (*indexS)->get_color() * 100),this);



	       ctmp.Format(_T("Top Left:(%d,%d) ,  Bottom Right:(%d,%d)"),
				(*indexP)->get_lp().x,
				(*indexP)->get_lp().y,
				(*indexP)->get_rp().x,
				(*indexP)->get_rp().y);

			arr_labels[(*indexS)->get_color()][3]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(875, 75 + (*indexS)->get_color() * 100, 1200, 95 + (*indexS)->get_color() * 100), this);
			
			ctmp.Format(_T("Start angle:(%d,%d) ,  End angle:(%d,%d)"),
				(*indexP)->get_start_angle().x,
				(*indexP)->get_start_angle().y,
				(*indexP)->get_end_angle().x,
				(*indexP)->get_end_angle().y);

			arr_labels[(*indexS)->get_color()][4]->Create(ctmp, WS_CHILD | WS_VISIBLE, CRect(875, 100 + (*indexS)->get_color() * 100, 1200, 120 + (*indexS)->get_color() * 100), this);



		
			(*indexS)->set_is_shown(TRUE);
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





