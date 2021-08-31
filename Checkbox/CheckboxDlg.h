
// CheckboxDlg.h : header file
//

#pragma once


// CCheckboxDlg dialog
class CCheckboxDlg : public CDialogEx
{
// Construction
public:
	CCheckboxDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHECKBOX_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheck3();
protected:
	CButton cb_cpp_;
	CButton cb_c_sharp_;
	CButton cb_java_;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCheckJava();
	afx_msg void OnBnClickedCheckCpp();
};
