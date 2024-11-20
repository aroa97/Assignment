// CDlgException.cpp: 구현 파일
//

#include "pch.h"
#include "gAssignment1.h"
#include "afxdialogex.h"
#include "CDlgException.h"


// CDlgException 대화 상자

IMPLEMENT_DYNAMIC(CDlgException, CDialogEx)

CDlgException::CDlgException(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EXCEPTION_DLG, pParent)
{
}

CDlgException::~CDlgException()
{
}

void CDlgException::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgException, CDialogEx)
END_MESSAGE_MAP()


// CDlgException 메시지 처리기



BOOL CDlgException::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	setPos();
	setTxt(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

// 모니터 중앙에 위치 시키기
void CDlgException::setPos()
{
	CRect rect;
	GetClientRect(&rect);

	CPoint pos;
	pos.x = GetSystemMetrics(SM_CXSCREEN) / 2.0f - rect.Width() / 2.0f;
	pos.y = GetSystemMetrics(SM_CYSCREEN) / 2.0f - rect.Height() / 2.0f;

	SetWindowPos(NULL, pos.x, pos.y, 0, 0, SWP_NOSIZE);
}

void CDlgException::setTxt(int n)
{
	CString str;
	switch (n) {
	case 0: str = _T("지정된 범위 안의 숫자를 입력하세요\nX : 30 ~ 610\nY : 30 ~ 450"); break;
	case 1: str = _T("원을 그려주세요"); break;
	}
	SetDlgItemText(IDC_STATIC_TEXT, str);
}