#pragma once


// CTAB2 dialog

class CTAB2 : public CDialogEx
{
	DECLARE_DYNAMIC(CTAB2)

public:
	CTAB2(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CTAB2();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB2 };
#endif

protected:

	//virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_comboBoxCtrl;


	//afx_msg void OnCbnSelchangeShapecb();
};
