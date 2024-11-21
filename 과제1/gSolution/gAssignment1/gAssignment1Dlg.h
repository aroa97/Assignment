
// gAssignment1Dlg.h: 헤더 파일
//
#include "CDlgImage.h"
#include "CDlgException.h"

#pragma once

// CgAssignment1Dlg 대화 상자
class CgAssignment1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CgAssignment1Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	CDlgImage* m_pDlgImage;
	CDlgException* m_pDlgException;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GASSIGNMENT1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP();

public:
	int m_nX1;
	int m_nY1;
	int m_nX2;
	int m_nY2;
	int m_nGray;
	int m_nRadius;
	CString m_sRadius;
	bool m_bDrawCirCle;

	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnDraw();
	afx_msg void OnBnClickedBtnAction();
	afx_msg void OnBnClickedBtnOpen();

	void drawCircle(unsigned char* fm, int x, int y, int nRadius, int nGray);
	bool inInCirCle(int nCenterX, int nCenterY, int x, int y, int nRadius);
	void moveRect(int x, int y);
	void UpdateDisplay();
	void onLoadImage();
	void saveCircleImg(int nIndex);
	void drawLoadImg(CImage* img);
	void drawCentroid();
	void drawLine(int nStartX, int nStartY, int nEndX, int nEndY, int nRed, int nGreen, int nBlue);
	void drawRadius(int nCenterX, int nCenterY, int nTh);
};
