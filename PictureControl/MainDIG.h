#pragma once


// MainDIG dialog

class MainDIG : public CDialogEx
{
	DECLARE_DYNAMIC(MainDIG)

public:
	MainDIG(CWnd* pParent = nullptr);   // standard constructor
	virtual ~MainDIG();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
