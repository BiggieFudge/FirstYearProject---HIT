#pragma once


// CONTROLS dialog

class CONTROLS : public CDialogEx
{
	DECLARE_DYNAMIC(CONTROLS)

public:
	CONTROLS(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CONTROLS();  //strandard

	

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONTROLS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	
	DECLARE_MESSAGE_MAP()
};
