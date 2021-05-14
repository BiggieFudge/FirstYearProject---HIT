#pragma once


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

	//Functions
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};
