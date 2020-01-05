
// MFCApplication1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CMFCApplication1Dlg 대화 상자



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CString01, &CMFCApplication1Dlg::OnBnClickedButtonCstring01)
	ON_BN_CLICKED(IDC_BUTTON_MBCS, &CMFCApplication1Dlg::OnBnClickedButtonMbcs)
	ON_BN_CLICKED(IDC_BUTTON_UNICODE, &CMFCApplication1Dlg::OnBnClickedButtonUnicode)
	ON_BN_CLICKED(IDC_BUTTON_GETLENGTH, &CMFCApplication1Dlg::OnBnClickedButtonGetlength)
	ON_BN_CLICKED(IDC_BUTTON_CSTRINGTOWIDECHAR, &CMFCApplication1Dlg::OnBnClickedButtonCstringtowidechar)
	ON_BN_CLICKED(IDC_BUTTON_FORMAT, &CMFCApplication1Dlg::OnBnClickedButtonFormat)
	ON_BN_CLICKED(IDC_BUTTON_ARRAY, &CMFCApplication1Dlg::OnBnClickedButtonArray)
	ON_BN_CLICKED(IDC_BUTTON_TRIM, &CMFCApplication1Dlg::OnBnClickedButtonTrim)
	ON_BN_CLICKED(IDC_BUTTON_FIND, &CMFCApplication1Dlg::OnBnClickedButtonFind)
	ON_BN_CLICKED(IDC_BUTTON_REVERSEFIND, &CMFCApplication1Dlg::OnBnClickedButtonReversefind)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 메시지 처리기

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//////////////////////////////////////////////////////////////////////////
void CMFCApplication1Dlg::OnBnClickedButtonCstring01()
{
	CString strTmp = _T("Hello CString!");	// 유니코드로 정의된 프로젝트에서는 L"문자열"을 리턴. L은 유니코드 형태로 인식하겠다.
	char szBuffer[32] = { "Hello" };

	szBuffer[1] = _T('H');
	//AfxMessageBox(strTmp);
	::MessageBoxA(NULL, szBuffer, "MBCS", MB_OK);
}

//////////////////////////////////////////////////////////////////////////
void CMFCApplication1Dlg::OnBnClickedButtonMbcs()
{
	// C
	char szBuffer[32] = {"Hello"};
	strcat_s(szBuffer, ", CString!");
	::MessageBoxA(NULL, szBuffer, "MBCS", MB_OK);
}
//////////////////////////////////////////////////////////////////////////
void CMFCApplication1Dlg::OnBnClickedButtonUnicode()
{
	// C
	wchar_t wcsBuffer[32] = { L"Hello" };
	wcscat_s(wcsBuffer, L", CString!");
	::MessageBoxW(NULL, wcsBuffer, L"MBCS", MB_OK); 
	//::MessageBoxA(NULL, wcsBuffer, L"MBCS", MB_OK);
}

//////////////////////////////////////////////////////////////////////////
void CMFCApplication1Dlg::OnBnClickedButtonGetlength()
{
	CString strTmp = _T("Test");
	//GetLength() : 글자 수. 메모리 크기가 아님
	int nLength = strTmp.GetLength();
	
	//LPTSTR == TCHAR *(Long Pointer)
	LPTSTR pBuffer = strTmp.GetBuffer();
}

//////////////////////////////////////////////////////////////////////////

void CMFCApplication1Dlg::OnBnClickedButtonCstringtowidechar()
{
	TCHAR wcsBuffer[32] = { 0, };
	CString strData = _T("Hello");

	// Win32 API
	::wsprintf(wcsBuffer, _T("%s"), strData);
}

//////////////////////////////////////////////////////////////////////////
void CMFCApplication1Dlg::OnBnClickedButtonFormat()
{
	CString strTmp;
	strTmp.Format(_T("DATA:%d"), 10);	// Format 멤버함수를 사용해 printf 와 같이 쓸 수도 있다.
	AfxMessageBox(strTmp);
}

//////////////////////////////////////////////////////////////////////////
void CMFCApplication1Dlg::OnBnClickedButtonArray()
{
	CString strTmp = _T("Hello, World!");
	TCHAR ch = strTmp[2];
	strTmp.SetAt(2, _T('L')); // CString 변수를 L-Value로 하여 값을 바꾸고 싶을때는 SetAt 인덱스 지정

	AfxMessageBox(strTmp);
}

//////////////////////////////////////////////////////////////////////////
void CMFCApplication1Dlg::OnBnClickedButtonTrim()
{
	CString strData = _T(" DATA");	// 공백이 있는 문자열
	TCHAR wcsBuffer[32];

	strData.TrimLeft();	// 왼쪽에 있는 공백을 제거한다.
	wsprintf(wcsBuffer, _T("%s"), strData);
}

//////////////////////////////////////////////////////////////////////////
void CMFCApplication1Dlg::OnBnClickedButtonFind()
{
	CString strPath = _T("C:\\Windows\\System32\\a.exe");

	int nIndex = strPath.Find(_T("a.exe"));
	if (nIndex >= 0)
	{
		AfxMessageBox(strPath.Left(nIndex));	// nIndex 왼쪽 문자열
		AfxMessageBox(strPath.Right(strPath.GetLength() - nIndex));	// 우측에서 Index 만큼의 문자열
	}
	
}

//////////////////////////////////////////////////////////////////////////
// 실행 파일의 경로를 알고자 할때는 ReverseFind를 사용한다.
void CMFCApplication1Dlg::OnBnClickedButtonReversefind()
{
	CString strPath = _T("C:\\Windows\\System32\\a.exe");

	int nIndex = strPath.ReverseFind(_T('\\'));
	if (nIndex >= 0)
	{
		AfxMessageBox(strPath.Left(nIndex));	// nIndex 왼쪽 문자열
		AfxMessageBox(strPath.Right(strPath.GetLength() - nIndex - 1));	// 우측에서 Index 만큼의 문자열
	}
}
