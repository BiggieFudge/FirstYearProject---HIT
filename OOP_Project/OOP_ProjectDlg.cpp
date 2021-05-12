
// OOP_ProjectDlg.cpp : implementation file
//


#include "pch.h"
#include "framework.h"
#include "OOP_Project.h"
#include "OOP_ProjectDlg.h"
#include "afxdialogex.h"
#include "CONTROLS.h"


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
	m_controls.Create(IDD_CONTROLS, this);
	

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
	if (change == false) { MoveWindow(0, 0, 1600, 1000); change = true; }

    
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

		//CDialogEx::OnPaint();
		CPaintDC dc(this); // device context for painting
		CRect rect;
		CString a;//string in labels
		GetClientRect(&rect);

		//drawing y axis
		dc.MoveTo(0, rect.Height()/2);
		dc.LineTo(rect.Width(), rect.Height() / 2);
		int Hei = rect.Height() / 20;
		for (int i = 0; i <= 20; i++) {
			if (i != 10) {

				Yshnatot[i] = new CStatic;

				a.Format(_T("%d"), 10 - i);  //Create Shnatot label
				(*Yshnatot[i]).Create(a, WS_CHILD | WS_VISIBLE,
					CRect(rect.Width() / 2 + 7, i*Hei - 20, rect.Width() / 2 + 34, i*Hei + 10), this);

				dc.MoveTo(rect.Width() / 2 - 5, i*Hei);  //Create Shnatot kav
				dc.LineTo(rect.Width() / 2 + 5, i*Hei);
			}
		}
		
		//drawing x axis
		dc.MoveTo(rect.Width()/2, 0);
		dc.LineTo(rect.Width()/2, rect.Height());
		int Wid = rect.Width() / 20;
		for (int i = 0; i <= 20; i++) {
			if (i != 10) {

				a.Format(_T("%d"), i - 10);

				Xshnatot[i] = new CStatic;
				(*Xshnatot[i]).Create(a, WS_CHILD | WS_VISIBLE, //Create Shnatot label
					CRect(i*Wid + 3, rect.Height() / 2 - 30, i*Wid + 30, rect.Height() / 2 - 7), this);

				dc.MoveTo(i*Wid, rect.Height() / 2 - 5);  //Create Shnatot kav
				dc.LineTo(i*Wid, rect.Height() / 2 + 5);
			}
		}
		
		

		//print x and y labels
		paint_xy[0] = new CStatic;
		paint_xy[1]= new CStatic;


		a.Format(_T("X"));
		(*paint_xy[0]).Create(a, WS_CHILD | WS_VISIBLE,
			CRect(rect.Width() - 20, rect.Height() / 2 + 5, rect.Width(), rect.Height() + 20), this);


		a.Format(_T("Y"));
		(*paint_xy[1]).Create(a, WS_CHILD | WS_VISIBLE,
			CRect(rect.Width() / 2 +5, 0, rect.Width()/2 +25, 20), this);


	

	}
	
}



// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COOPProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COOPProjectDlg::OnBnClickedButton1()//creating CONTROL dialog
{

	m_controls.ShowWindow(SW_SHOW);




	
}
