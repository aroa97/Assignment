#pragma once
#include "afxdialogex.h"


// CDlgException 대화 상자

class CDlgException : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgException)

public:
	CDlgException(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgException();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXCEPTION_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void setPos();
	void setTxt(int n);
};
