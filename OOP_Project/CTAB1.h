#pragma once


// CTAB1 dialog

class CTAB1 : public CDialogEx
{
	DECLARE_DYNAMIC(CTAB1)

public:
	CTAB1(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CTAB1();


	

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB1 };
#endif

protected:

	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedPolygon();
	afx_msg void OnBnClickedCircle();

	CComboBox m_comboBoxCtrl; // ComboBox 8 number

	CString m_strTextCtrl;//text in combo box
	
	CWnd* Poly[4];//display input button

	CStatic IDC_XX2;
	CStatic IDC_YY2;
	CStatic IDC_XX;//display x label
	CStatic IDC_YY;//display y label
	
	CEdit* Xtextbox[8];//TextBoxes for point input
	CEdit* Ytextbox[8];//TextBoxes for point input
	CStatic* labels[8];//display point number labels

	bool isHidden = 0;

	int save_amount_points=-1;//amount of points selected in combo box

	afx_msg void OnCbnSelchangePoints();

	afx_msg void show_Poly();
	afx_msg void hide_Poly();
	afx_msg void delete_buttons();
	afx_msg void HideTextBoxes();
	afx_msg void ShowTextBoxes();
	
};
