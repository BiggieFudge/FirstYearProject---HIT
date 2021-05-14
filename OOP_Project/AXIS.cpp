// AXIS.cpp : implementation file
//

#include "pch.h"
#include "OOP_Project.h"
#include "AXIS.h"
#include "afxdialogex.h"


// AXIS dialog

IMPLEMENT_DYNAMIC(AXIS, CDialogEx)

AXIS::AXIS(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AXIS, pParent)
{

}

AXIS::~AXIS()
{
	int i;
	for (i = 0; i <= 20; i++) {
		if (i != 10) {
			delete(Xshnatot[i]);
			delete(Yshnatot[i]);
		}
	}

	for (i = 0; i < 2; i++) {
		delete(paint_xy[i]);
	}
}

void AXIS::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AXIS, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// AXIS message handlers

HBRUSH AXIS::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	return (HBRUSH)GetStockObject(WHITE_BRUSH);
}


void AXIS::OnPaint(){

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
	}
	else
	{
		
		//Draw NEW AXIS AND GRID 1.1
		CPaintDC dc(this);
		CRect rect;
		GetClientRect(&rect);
		int SquareSide = rect.Width() / 20;

		CPen penForSquare;
		penForSquare.CreatePen(PS_DOT, 1, RGB(128, 128,128));
		CPen penForAxis;
		penForAxis.CreatePen(PS_SOLID, 3, RGB(0, 0, 0));

		for (int i = 0; i < 20; i++) {     // Draw Grid and Shnatot
			for (int j = 0; j < 20; j++) {
				dc.SelectObject(&penForSquare);
				dc.Rectangle(CRect(i * SquareSide, j * SquareSide, i * SquareSide + SquareSide, j * SquareSide + SquareSide)); //Draw Square
				dc.SelectObject(&penForAxis);
				if (i == 10 && j!=0) {
					dc.MoveTo(i * SquareSide - 7, j * SquareSide);//shnatot on y axis
					dc.LineTo(i * SquareSide + 7, j * SquareSide);
				}
				if (j == 10 && i!=0) {
					dc.MoveTo(i * SquareSide , j * SquareSide - 7); //shnatot on x axis
					dc.LineTo(i * SquareSide , j * SquareSide + 7);
				}
			}
		}

		dc.MoveTo(0, rect.Height() / 2);
		dc.LineTo(rect.Width(), rect.Height() / 2); //draw Y axis
		dc.MoveTo(rect.Width() / 2, 0);
		dc.LineTo(rect.Width() / 2, rect.Height()); //draw X axis




	//	//

	//	 // device context for painting
	//	CRect rect;
	//	CString a;//string in labels
	//	GetClientRect(&rect);


	//	//drawing y axis
	//	dc.MoveTo(0, rect.Height() / 2);
	//	dc.LineTo(rect.Width(), rect.Height() / 2);

	//	int Hei = rect.Width() / 20;

	//	//Test GRID
	//	CPen penBlack;
	//	penBlack.CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	//	dc.DrawEdge(CRect(0, 0, Hei, Hei), BDR_RAISEDOUTER | BDR_SUNKENINNER, BF_RECT);
	//	//END test


	//	for (int i = 0; i <= 20; i++) {
	//		if (i != 10) {

	//			Yshnatot[i] = new CStatic;

	//			a.Format(_T("%d"), 10 - i);  //Create Shnatot label
	//			(*Yshnatot[i]).Create(a, WS_CHILD | WS_VISIBLE,
	//				CRect(rect.Width() / 2 + 7, i * Hei - 20, rect.Width() / 2 + 34, i * Hei + 10), this);

	//			dc.MoveTo(rect.Width() / 2 - 5, i * Hei);  //Create Shnatot kav
	//			dc.LineTo(rect.Width() / 2 + 5, i * Hei);
	//		}
	//	}

	//	//drawing x axis
	//	dc.MoveTo(rect.Width() / 2, 0);
	//	dc.LineTo(rect.Width() / 2, rect.Height());

	//	int Wid = rect.Width() / 20;
	//	for (int i = 0; i <= 20; i++) {
	//		if (i != 10) {

	//			a.Format(_T("%d"), i - 10);

	//			Xshnatot[i] = new CStatic;
	//			(*Xshnatot[i]).Create(a, WS_CHILD | WS_VISIBLE, //Create Shnatot label
	//				CRect(i * Hei + 3, rect.Height() / 2 - 30, i * Hei + 30, rect.Height() / 2 - 7), this);

	//			dc.MoveTo(i * Hei, rect.Height() / 2 - 5);  //Create Shnatot kav
	//			dc.LineTo(i * Hei, rect.Height() / 2 + 5);
	//		}
	//	}



	//	//print x and y labels
	//	paint_xy[0] = new CStatic;
	//	paint_xy[1] = new CStatic;

	//	//create x label
	//	a.Format(_T("X"));
	//	(*paint_xy[0]).Create(a, WS_CHILD | WS_VISIBLE,
	//		CRect(rect.Width() - 20, rect.Height() / 2 + 5, rect.Width(), rect.Height() + 20), this);

	//	//create y label
	//	a.Format(_T("Y"));
	//	(*paint_xy[1]).Create(a, WS_CHILD | WS_VISIBLE,
	//		CRect(rect.Width() / 2 + 5, 0, rect.Width() / 2 + 25, 20), this);


	}


}