// AXIS.cpp : implementation file
//


#include "pch.h"
#include "OOP_Project.h"
#include "OOP_ProjectDlg.h"
#include "AXIS.h"
#include "afxdialogex.h"
#include <string.h>
#include "CONTROLS.h"
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
		penForSquare.CreatePen(PS_DOT, 1, RGB(128, 128, 128));
		CPen penForAxis;
		penForAxis.CreatePen(PS_SOLID, 3, RGB(0, 0, 0));

		for (int i = 0; i < 20; i++) {     // Draw Grid and Shnatot
			for (int j = 0; j < 20; j++) {
				dc.SelectObject(&penForSquare);
				dc.Rectangle(CRect(i * SquareSide, j * SquareSide, i * SquareSide + SquareSide, j * SquareSide + SquareSide)); //Draw Square
				dc.SelectObject(&penForAxis);
				if (i == 10 && j != 0) {
					dc.MoveTo(i * SquareSide - 7, j * SquareSide);//shnatot on y axis
					dc.LineTo(i * SquareSide + 7, j * SquareSide);
				}
				if (j == 10 && i != 0) {
					dc.MoveTo(i * SquareSide, j * SquareSide - 7); //shnatot on x axis
					dc.LineTo(i * SquareSide, j * SquareSide + 7);
				}
			}
		}

		dc.MoveTo(0, rect.Height() / 2);
		dc.LineTo(rect.Width(), rect.Height() / 2); //draw Y axis
		dc.MoveTo(rect.Width() / 2, 0);
		dc.LineTo(rect.Width() / 2, rect.Height()); //draw X axis


		
		

		//total_arr_poli

		//changing points to be relative to the grid screen

		

		
		//for (int i = 0; i < CTAB1::CurrentPose; i++)
		//{
		//	if (m_tab->ShapeArr[i]->type()=="polygon")//if painting poli
		//	{
		//		m_tab->ShapeArr[i];
		//	}
		//	//dc.Polygon();
		//}
		//




	}


}