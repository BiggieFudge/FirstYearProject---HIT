#pragma once


// CTAB3 dialog

class CTAB3 : public CDialogEx
{
	DECLARE_DYNAMIC(CTAB3)

public:
	CTAB3(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CTAB3();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
