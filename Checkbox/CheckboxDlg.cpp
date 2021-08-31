
// CheckboxDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Checkbox.h"
#include "CheckboxDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCheckboxDlg dialog



CCheckboxDlg::CCheckboxDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHECKBOX_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCheckboxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_CPP, cb_cpp_);
	DDX_Control(pDX, IDC_CHECK_C_SHARP, cb_c_sharp_);
	DDX_Control(pDX, IDC_CHECK_JAVA, cb_java_);
}

BEGIN_MESSAGE_MAP(CCheckboxDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_BN_CLICKED(IDC_CHECK3, &CCheckboxDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_BUTTON1, &CCheckboxDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK_JAVA, &CCheckboxDlg::OnBnClickedCheckJava)
	ON_BN_CLICKED(IDC_CHECK_CPP, &CCheckboxDlg::OnBnClickedCheckCpp)
END_MESSAGE_MAP()


// CCheckboxDlg message handlers

BOOL CCheckboxDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCheckboxDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCheckboxDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCheckboxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCheckboxDlg::OnBnClickedCheck3()
{
	// TODO: Add your control notification handler code here
}


void CCheckboxDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	int cpp = cb_cpp_.GetCheck(), csh = cb_c_sharp_.GetCheck(), java = cb_java_.GetCheck() ;
	CString str_cpp = _T(""), str_sharp=_T(""), str_java= _T("");
	if (cpp == 1) str_cpp = _T("Cpp ");
	if (csh == 1) str_sharp = _T("C sharp ");
	if (java == 1) str_java = _T("Java ");
	CString str_info = _T("He can used:") + str_cpp + str_sharp + str_java;
	MessageBox(str_info, _T("Info"));
	// TODO: Add your control notification handler code here
}


void CCheckboxDlg::OnBnClickedCheckJava()
{
	// TODO: Add your control notification handler code here
}


void CCheckboxDlg::OnBnClickedCheckCpp()
{
	cb_java_.SetCheck(1);
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}
