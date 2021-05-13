// CTAB1.cpp : implementation file
//

#include "pch.h"
#include "OOP_Project.h"
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

END_MESSAGE_MAP()


// CTAB1 message handlers




//check if clicked on polygon option
void CTAB1::OnBnClickedPolygon()
{
	// TODO: Add your control notification handler code here
	if ( IsDlgButtonChecked(IDC_Polygon) == BST_CHECKED )//if chosen poligon
	{
		show_Poly();

	}
  
}
//display everything that is connected to poly
void CTAB1::show_Poly() {
   
	Poly[0]= (CWnd*)GetDlgItem(IDC_Poly);
	Poly[0]->ShowWindow(SW_SHOW);

	Poly[1] =(CWnd*)GetDlgItem(IDC_label);
	Poly[1]->ShowWindow(SW_SHOW);

	Poly[2]= (CWnd*)GetDlgItem(IDC_Points);
	Poly[2]->ShowWindow(SW_SHOW);

	Poly[3] = (CWnd*)GetDlgItem(IDC_Send);
	Poly[3]->ShowWindow(SW_SHOW);
	//display x and y labels
	GetDlgItem(IDC_X)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_Y)->ShowWindow(SW_SHOW);

	
	
}

//hide everything that is connected to poly
void CTAB1::hide_Poly()
{
	Poly[0]= (CWnd*)GetDlgItem(IDC_Poly);
	Poly[0]->ShowWindow(SW_HIDE);

	Poly[1] =(CWnd*)GetDlgItem(IDC_label);
	Poly[1]->ShowWindow(SW_HIDE);

	Poly[2]= (CWnd*)GetDlgItem(IDC_Points);
	Poly[2]->ShowWindow(SW_HIDE);   

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

//check if clicked on circle option
void CTAB1::OnBnClickedCircle()
{
	if ( IsDlgButtonChecked(IDC_Circle) == BST_CHECKED )//if chosen circle
	{
		hide_Poly();
	}
	
}



//choosing the number of points desired
void CTAB1::OnCbnSelchangePoints()
{
	

   // Add number to the combo box
   m_comboBoxCtrl.GetLBText(m_comboBoxCtrl.GetCurSel(), m_strTextCtrl); 
   UpdateData(FALSE);
   if(save_amount_points!=-1)//if already entered number before
   {
	   delete_buttons();
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

	   labels[i - 1] = new CStatic;         //Print nums;
	   labels[i - 1]->Create(NumToDisplay, WS_CHILD | WS_VISIBLE,
		   CRect(x-10 , y , x , y+20), this);


	   Xtextbox[i - 1] = new CEdit;        // Print Text Boxes
	   Xtextbox[i - 1]->Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER, CRect(x,y,x+20,y+20), this, 8888);
	   Ytextbox[i - 1] = new CEdit;
	   Ytextbox[i - 1]->Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER, CRect(x + 45 , y, x + 65, y + 20), this, 8888);
	   y += 35;
   }



 
}



