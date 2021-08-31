
// PictureControlDlg.h : header file
//

#pragma once


// CPictureControlDlg dialog
class CPictureControlDlg : public CDialogEx
{
// Construction
public:
	CPictureControlDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PICTURECONTROL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	CBitmap cbimap_;
	unsigned int counter_;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	CStatic picture_control_;
public:
	afx_msg void OnBnClickedBtnNextImg();
};
