
// OOP_ProjectDlg.cpp : implementation file
//


#include "pch.h"
#include "framework.h"
#include "OOP_Project.h"
#include "OOP_ProjectDlg.h"
#include "afxdialogex.h"
#include "CONTROLS.h"
#include "AXIS.h"





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
	
	//show_axis->Create(MAKEINTRESOURCE(IDD_AXIS), this);  //Create X,Y axis on main screen
	//show_axis->MoveWindow(30, 30, rect.Height()-73, rect.Height()-73);
	//show_axis->ShowWindow(SW_SHOW);


	Page->Create(MAKEINTRESOURCE(IDD_Show_All), this); //Create View tab
	Page->MoveWindow(900,30,280,450);
	Page->ShowWindow(SW_SHOW);


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
		dc.MoveTo(899,29);
		dc.LineTo(1181,29);
		dc.LineTo(1181, 481);
		dc.LineTo(899, 481);
		dc.LineTo(899, 29);

		

		
		
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
				indexPoly++;
			}
			else if (type == "CircleC") {
				
				dc.Ellipse(m_controls.m_TAB1.CircleArr_C[indexCircleC]->get_rekt());    //Draw CircleC
				indexCircleC++;
			}
			else if (type == "CircleP") {

				dc.Pie(m_controls.m_TAB1.CircleArr_P[indexCircleP]->get_rekt(),
					(m_controls.m_TAB1.CircleArr_P[indexCircleP]->get_angle_point())[0],
					(m_controls.m_TAB1.CircleArr_P[indexCircleP]->get_angle_point())[1]);
				indexCircleP++;
			}
			else {

				dc.Ellipse(m_controls.m_TAB1.CircleArr_E[indexCircleE]->get_rekt());
				indexCircleE++;
			}



		}

//		
//		if (m_controls.m_TAB1.CurrentPose_shape > 0) //checking amount of shapes
//		{
//			int i;
//			for(i=0;i<m_controls.m_TAB1.CurrentPose_shape ;i++)
//			{
//				if((m_controls.m_TAB1.ShapeArr[i])->get_color()==-1)
//				{
//					(m_controls.m_TAB1.ShapeArr[i])->set_color(i);
//				}
//			}
//		    
//			if (m_controls.m_TAB1.CurrentPose_poly > 0)//checking amount of polys
//			{
//			    int i;
//				for (i = 0; i < m_controls.m_TAB1.CurrentPose_poly; i++)
//				{
//				    
//					CPen penForShapes;
//					penForShapes.CreatePen(PS_SOLID, 4, arr_color[(m_controls.m_TAB1.PolyArr[i])->get_color()]);
//					dc.SelectObject(&penForShapes);
//					
//			
//					dc.Polygon(m_controls.m_TAB1.PolyArr[i]->GetArr(),             //Draw poly
//								m_controls.m_TAB1.PolyArr[i]->get_amount_edge());
//					//index_shape++;
//					
//				}
//			}
//			if(m_controls.m_TAB1.CurrentPose_circle > 0)//checking amount of circles
//			{
//				if (m_controls.m_TAB1.CurrentPose_circle_c > 0)//checking amount of circles circles
//				{
//					int i;
//					for (i = 0; i < m_controls.m_TAB1.CurrentPose_circle_c; i++){
//					     
//						CPen penForShapes;
//						penForShapes.CreatePen(PS_SOLID, 4, arr_color[(m_controls.m_TAB1.CircleArr_C[i])->get_color()]);
//						dc.SelectObject(&penForShapes);
//					     
//						dc.Ellipse(m_controls.m_TAB1.CircleArr_C[i]->get_rekt());
//						
//						//index_shape++;
//					
//
//									
//					}
//				}
//			}
//
//		}
//		//index_shape = 0;//restart the index
//		
	}
	
}



// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COOPProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void COOPProjectDlg::OnBnClickedButton1()//Open CONTROL dialog
{
	
	m_controls.ShowWindow(SW_SHOW);
}


HBRUSH COOPProjectDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)  //Set Background
{
	return (HBRUSH)GetStockObject(DC_BRUSH);
}





