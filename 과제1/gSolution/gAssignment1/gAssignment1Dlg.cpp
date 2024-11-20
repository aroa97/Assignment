
// gAssignment1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "gAssignment1.h"
#include "gAssignment1Dlg.h"
#include "afxdialogex.h"

#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
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


// CgAssignment1Dlg 대화 상자



CgAssignment1Dlg::CgAssignment1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GASSIGNMENT1_DIALOG, pParent)
	, m_nX1(30)
	, m_nY1(30)
	, m_nX2(320)
	, m_nY2(240)
	, m_nRadius(0)
	, m_nGray(0)
	, m_sRadius(_T(TEXT_RADIUS))
	, m_bDrawCirCle(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CgAssignment1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_X1, m_nX1);
	DDX_Text(pDX, IDC_EDIT_Y1, m_nY1);
	DDX_Text(pDX, IDC_EDIT_X2, m_nX2);
	DDX_Text(pDX, IDC_EDIT_Y2, m_nY2);
	DDX_Text(pDX, IDC_RADIUS, m_sRadius);
}

BEGIN_MESSAGE_MAP(CgAssignment1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_DRAW, &CgAssignment1Dlg::OnBnClickedBtnDraw)
	ON_BN_CLICKED(IDC_BTN_ACTION, &CgAssignment1Dlg::OnBnClickedBtnAction)
	ON_BN_CLICKED(IDC_BTN_OPEN, &CgAssignment1Dlg::OnBnClickedBtnOpen)
END_MESSAGE_MAP()


// CgAssignment1Dlg 메시지 처리기

BOOL CgAssignment1Dlg::OnInitDialog()
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

	// 윈도우 크기 설정
	MoveWindow(0,0,810,610);

	// Static Text, Edit Control 크기 및 위치 설정
	CStatic* pStaticStart =  (CStatic*)GetDlgItem(IDC_START_POSITION);
	CStatic* pStaticEnd =    (CStatic*)GetDlgItem(IDC_END_POSITION);
	CStatic* pStaticX1 =     (CStatic*)GetDlgItem(IDC_START_POSITION_X_MIN_MAX);
	CStatic* pStaticY1 =     (CStatic*)GetDlgItem(IDC_START_POSITION_Y_MIN_MAX);
	CStatic* pStaticX2 =     (CStatic*)GetDlgItem(IDC_END_POSITION_X_MIN_MAX);
	CStatic* pStaticY2 =     (CStatic*)GetDlgItem(IDC_END_POSITION_Y_MIN_MAX);
	CStatic* pStaticRadius = (CStatic*)GetDlgItem(IDC_RADIUS);

	CEdit* pEditX1 =         (CEdit*)GetDlgItem(IDC_EDIT_X1);
	CEdit* pEditY1 =         (CEdit*)GetDlgItem(IDC_EDIT_Y1);
	CEdit* pEditX2 =         (CEdit*)GetDlgItem(IDC_EDIT_X2);
	CEdit* pEditY2 =         (CEdit*)GetDlgItem(IDC_EDIT_Y2);

	int nStaticSttX = 20;
	int nStaticSttY = 40;
	int nStaticSttW = 80;
	int nStaticSttH = 30;
	int nEditW =      80;
	int nEditH =      25;
	int nEndX = nStaticSttX + nStaticSttW + nEditW * 2 + 25;
	int nRadiusW = 200;

	if (pStaticStart != nullptr)
		pStaticStart->MoveWindow(nStaticSttX, nStaticSttY, nStaticSttW, nStaticSttH);
	if (pEditX1 != nullptr)
		pEditX1->     MoveWindow(nStaticSttX + nStaticSttW + 10, nStaticSttY, nEditW, nEditH);
	if (pEditY1 != nullptr)
		pEditY1->     MoveWindow(nStaticSttX + nStaticSttW + nEditW + 10, nStaticSttY, nEditW, nEditH);
	if (pStaticX1 != nullptr)
		pStaticX1->   MoveWindow(nStaticSttX + nStaticSttW + 10, 15, nEditW, nEditH);
	if (pStaticY1 != nullptr)
		pStaticY1->   MoveWindow(nStaticSttX + nStaticSttW + nEditW + 10, 15, nEditW, nEditH);

	if (pStaticEnd != nullptr)
		pStaticEnd->  MoveWindow(nEndX, nStaticSttY, nStaticSttW, nStaticSttH);
	if (pEditX2 != nullptr)
		pEditX2->     MoveWindow(nEndX + nStaticSttW + 10, nStaticSttY, nEditW, nEditH);
	if (pEditY2 != nullptr)
		pEditY2->     MoveWindow(nEndX + nStaticSttW + nEditW + 10, nStaticSttY, nEditW, nEditH);
	if (pStaticX2 != nullptr)
		pStaticX2->   MoveWindow(nEndX + nStaticSttW + 10, 15, nEditW, nEditH);
	if (pStaticY2 != nullptr)
		pStaticY2->   MoveWindow(nEndX + nStaticSttW + nEditW + 10, 15, nEditW, nEditH);

	if (pStaticRadius != nullptr)
		pStaticRadius->MoveWindow(nEndX * 2 - 5, nStaticSttY, nRadiusW, nStaticSttH);

	// 버튼 위치 설정
	CButton* pBtn1 = (CButton*)GetDlgItem(IDC_BTN_DRAW);
	CButton* pBtn2 = (CButton*)GetDlgItem(IDC_BTN_ACTION);
	CButton* pBtn3 = (CButton*)GetDlgItem(IDC_BTN_OPEN);

	int nBtnWidth = 100;
	int nBtnHeight = 40;
	int nBtnX = 670;
	int nBtnY = 80;

	if (pBtn1 != nullptr) 
		pBtn1->MoveWindow(nBtnX, nBtnY, nBtnWidth, nBtnHeight);
	if (pBtn2 != nullptr) 
		pBtn2->MoveWindow(nBtnX, nBtnY + 50, nBtnWidth, nBtnHeight);
	if (pBtn3 != nullptr) 
		pBtn3->MoveWindow(nBtnX, nBtnY + 100, nBtnWidth, nBtnHeight);

	// 무게중심 좌표 위치 설정
	CStatic* pCenterTxt = (CStatic*)GetDlgItem(IDC_CENTER_TEXT);
	CStatic* pCenterXY =  (CStatic*)GetDlgItem(IDC_CENTER_X_Y);

	int nCenterWidth = 100;
	int nCenterHeight = 40;
	int nCenterX = 670;
	int nCenterY = 220;

	if (pCenterTxt != nullptr)
		pCenterTxt->MoveWindow(nCenterX, nCenterY, nCenterWidth, nCenterHeight);
	if (pCenterXY != nullptr)
		pCenterXY-> MoveWindow(nCenterX, nCenterY + 40, nCenterWidth, nCenterHeight);

	// 다이얼로그 이미지 초기화
	m_pDlgImage = new CDlgImage;
	m_pDlgImage->Create(IDD_CDIGIMAGE, this);
	m_pDlgImage->ShowWindow(SW_SHOW);

	// 다이얼로그 예외처리창 초기화
	m_pDlgException = new CDlgException;
	m_pDlgException->Create(IDD_EXCEPTION_DLG, this);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CgAssignment1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CgAssignment1Dlg::OnPaint()
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
HCURSOR CgAssignment1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// new로 만든 변수 삭제
void CgAssignment1Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	if (m_pDlgImage)     delete m_pDlgImage;
	if (m_pDlgException) delete m_pDlgException;
}



void CgAssignment1Dlg::OnBnClickedBtnDraw() // 원 그리는 함수
{
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_Image.GetBits();
	
	int nWidth =  m_pDlgImage->m_Image.GetWidth();
	int nHeight = m_pDlgImage->m_Image.GetHeight();
	m_nRadius =   10 + rand() % (20 + 1); //원의 반지름 (10~30)
	m_nGray =     100 + rand() % (155 + 1); //원의 색 (100 ~ 255)
	
	// 입력값 -> 멤버 변수
	UpdateData();

	// x1 y1 좌표가 원의 반지름보다 작거나 이미지 크기 - 반지름보다 클 경우 Dlglog 출력 and return
	if (m_nX1 < m_nRadius || m_nY1 < m_nRadius || m_nX1 > nWidth - m_nRadius || m_nY1 > nHeight - m_nRadius) {
		m_pDlgException->setTxt(0);
		m_pDlgException->ShowWindow(SW_SHOW);
		return;
	}

	// 원 그리기
	drawCircle(fm, m_nX1, m_nY1, m_nRadius, m_nGray);

	m_bDrawCirCle = true;

	// 그린 원의 반지름 윈도우 창에 표시
	CString str;
	str.Format(_T("%s%d"), _T(TEXT_RADIUS), m_nRadius);
	m_sRadius = str;
	UpdateData(false);

	m_pDlgImage->Invalidate();
}

// 원을 반지름의 길이만큼 그리는 함수
void CgAssignment1Dlg::drawCircle(unsigned char* fm, int x, int y, int nRadius, int nGray)
{
	int nWidth =  m_pDlgImage->m_Image.GetWidth();
	int nHeight = m_pDlgImage->m_Image.GetHeight();
	int nPitch =  m_pDlgImage->m_Image.GetPitch();

	memset(fm, 0, nWidth * nHeight);

	for (int i = y - nRadius; i < y + nRadius; i++) {
		for (int j = x - nRadius; j < x + nRadius; j++) {
			if (inInCirCle(x, y, j, i, nRadius))
				fm[i * nPitch + j] = nGray;
		}
	}
}

// 현재 좌표가 원 안에 위치하는 지 판단하는 함수
bool CgAssignment1Dlg::inInCirCle(int nCenterX, int nCenterY, int x, int y, int nRadius)
{
	bool bRet = false;

	double dX = x - nCenterX;
	double dY = y - nCenterY;
	double dDist = dX * dX + dY * dY;

	bRet = (dDist < nRadius * nRadius) ? true : false;

	return bRet;
}

void CgAssignment1Dlg::OnBnClickedBtnAction()
{
	// 입력값 받기
	UpdateData();

	// 원이 그려지지 않았으면 return
	if (m_bDrawCirCle == false) { 
		m_pDlgException->setTxt(1);
		m_pDlgException->ShowWindow(SW_SHOW);
		return; 
	}
	// 좌표값이 정해진 범위보다 작거나 크면 return
	if (m_nX2 < 30 || m_nY2 < 30 || m_nX2 > 610 || m_nY2 > 450) {
		m_pDlgException->setTxt(0);
		m_pDlgException->ShowWindow(SW_SHOW);
		return;
	}


	// End Position으로 이동
	int nMoveSpaceCnt = 30;
	int nPixelX = m_nX2 - m_nX1;
	int nPixelY = m_nY2 - m_nY1;

	// 일정 픽셀만큼 이동
	for (int i = 1; i <= nMoveSpaceCnt; i++) {
		moveRect(m_nX1 + nPixelX / nMoveSpaceCnt * i, m_nY1 + nPixelY / nMoveSpaceCnt * i);

		if (i == nMoveSpaceCnt) 
			moveRect(m_nX2, m_nY2);

		// 이미지 저장
		saveCircleImg(i);
		Sleep(10);
	}
	


	// Start Position을 End Position으로 Update
	m_nX1 = m_nX2;
	m_nY1 = m_nY2;
	UpdateData(false);
}

// 지정된 좌표에 원 그리기
void CgAssignment1Dlg::moveRect(int x, int y)
{
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_Image.GetBits();
	int nWidth =  m_pDlgImage->m_Image.GetWidth();
	int nHeight = m_pDlgImage->m_Image.GetHeight();
	int nPitch =  m_pDlgImage->m_Image.GetPitch();

	memset(fm, 0, nWidth * nHeight);

	drawCircle(fm, x, y, m_nRadius, m_nGray);

	UpdateDisplay();
}

// 다이얼로그 이미지 Update
void CgAssignment1Dlg::UpdateDisplay()
{
	CClientDC dc(m_pDlgImage);
	m_pDlgImage->m_Image.Draw(dc, 0, 0);
}


void CgAssignment1Dlg::OnBnClickedBtnOpen()
{
	onLoadImage();

}

void CgAssignment1Dlg::onLoadImage()
{
	// 현재 경로
	TCHAR szCurrentDir[MAX_PATH];
	DWORD dwRet = GetCurrentDirectory(MAX_PATH, szCurrentDir);

	CFileDialog fileDlg(TRUE, _T("jpg"), NULL, OFN_FILEMUSTEXIST, _T("이미지 파일 (*.bmp;*.jpg;*.png)|*.bmp;*.jpg;*.png|모든 파일 (*.*)|*.*||"));
	
	// 경로 수정
	CString absolutePath = CString(szCurrentDir) + _T("\\images");
	fileDlg.m_ofn.lpstrInitialDir = absolutePath;

	if (fileDlg.DoModal() == IDOK) {
		CString filePath = fileDlg.GetPathName();

		
		CImage img;
		HRESULT hr = img.Load(filePath);
		if (FAILED(hr)) {
			AfxMessageBox(_T("이미지 파일을 열 수 없습니다."));
			return;
		}

		// 다시 원을 그리도록 값 변경
		m_bDrawCirCle = false;

		// load image를 DlgImage에 출력한다.
		showLoadImg(&img);

		drawCentroid();

		UpdateDisplay();
	}
}

void CgAssignment1Dlg::saveCircleImg(int nIndex)
{
	CString str;
	str.Format(_T("%s%d%s"), _T(".\\image\\circleImage_"), nIndex, _T(".bmp"));
	m_pDlgImage->m_Image.Save(str);
}

void CgAssignment1Dlg::showLoadImg(CImage* img)
{
	if (img == NULL) {
		AfxMessageBox(_T("이미지 파일을 표시할 수 없습니다."));
		return;
	}
	
	unsigned char* fm =  (unsigned char*)m_pDlgImage->m_Image.GetBits();
	unsigned char* fm2 = (unsigned char*)img->GetBits();

	int nWidth =  m_pDlgImage->m_Image.GetWidth();
	int nHeight = m_pDlgImage->m_Image.GetHeight();
	int nPitch =  m_pDlgImage->m_Image.GetPitch();

	for (int i = 0; i < nHeight; i++) {
		for (int j = 0; j < nWidth; j++) {
			// GetPitch 값이 음수이기 때문에 -를 붙인다.
			fm[i * nPitch + j] = fm2[i * -nPitch + j];
		}
	}
}

void CgAssignment1Dlg::drawCentroid()
{
	// 무게 중심 파악
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_Image.GetBits();
	int nWidth =  m_pDlgImage->m_Image.GetWidth();
	int nHeight = m_pDlgImage->m_Image.GetHeight();
	int nPitch =  m_pDlgImage->m_Image.GetPitch();
	int nSumX = 0;
	int nSumY = 0;
	int nCnt =  0;
	int nTh = 100;

	for (int i = 0; i < nHeight; i++) {
		for (int j = 0; j < nWidth; j++) {
			if (fm[i * nPitch + j] >= nTh) {
				nSumX += j;
				nSumY += i;
				nCnt++;
			}
		}
	}
	double dCenterX = nSumX / nCnt;
	double dCenterY = nSumY / nCnt;

	// 무게중심 Static Text에 표시
	CStatic* pCenterXY =  (CStatic*)GetDlgItem(IDC_CENTER_X_Y);

	CString str;
	str.Format(_T("%d, %d"), (int)dCenterX, (int)dCenterY);
	SetDlgItemText(IDC_CENTER_X_Y, str);

	//std::cout << dCenterX << ' ' << dCenterY << std::endl;

	// 무게 중심에 X 표시하기
	for (int i = -4, j = -4; i <= 4; i++, j++) {
		for (int a = -1; a <= 1; a++) {
			for (int b = -1; b <= 1; b++) {
				fm[((int)dCenterY + i + a) * nPitch + (int)dCenterX + j + b] = 0;
				fm[((int)dCenterY + i + a) * nPitch + (int)dCenterX - j + b] = 0;
			}
		}
	}
}