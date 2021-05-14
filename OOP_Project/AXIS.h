#pragma once
#include "CTAB1.h"

// AXIS dialog

class AXIS : public CDialogEx
{
	DECLARE_DYNAMIC(AXIS)
	
public:
	AXIS(CWnd* pParent = nullptr);   // standard constructor
	virtual ~AXIS();
	HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AXIS };
#endif

protected:
	//Varaibles
	CStatic* Xshnatot[21];
	CStatic* Yshnatot[21];
	CStatic* paint_xy[2];
	CTAB1* m_tab;

	POINT* total_arr_poli[5];//remember to delete
	int amount_arr_poli = 0;

	//Functions
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};
