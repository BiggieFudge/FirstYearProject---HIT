#pragma once


// Show_All dialog

class Show_All : public CDialogEx
{
	DECLARE_DYNAMIC(Show_All)

public:
	Show_All(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Show_All();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Show_All };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	DECLARE_MESSAGE_MAP()
};
