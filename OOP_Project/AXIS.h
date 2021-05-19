#pragma once
#include "CTAB1.h"


// AXIS dialog

class AXIS : public CDialogEx
{
	DECLARE_DYNAMIC(AXIS)
	
public:
	
	
	AXIS(CWnd* pParent = nullptr);   // standard constructor
	virtual ~AXIS() ;
	HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AXIS };
#endif

protected:
	//Varaibles
	/*CStatic* Xshnatot;
	CStatic* Yshnatot;
	CStatic* paint_xy;
	CTAB1* m_tab;*/

	

	//POINT* total_arr_poli[5];//remember to delete
	//int amount_arr_poli = 0;

	//Functions
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};
