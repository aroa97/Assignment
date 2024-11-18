
// gAssignment1Dlg.h: 헤더 파일
//
#include "CDlgImage.h"

#pragma once


// CgAssignment1Dlg 대화 상자
class CgAssignment1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CgAssignment1Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	CDlgImage* m_pDlgImage;

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
	afx_msg void OnDestroy();
};
