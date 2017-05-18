// ChildView.h : CChildView 클래스의 인터페이스
//


#pragma once


// CChildView 창

class CChildView : public CWnd
{
// 생성입니다.
public:
	CChildView();

// 특성입니다.
public:

	CList <CPoint> m_pt;

	CPoint m_st;
	CPoint m_ed;
	bool m_RButton;

	COLORREF colorchange;
	int elre;

// 작업입니다.
public:

// 재정의입니다.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CChildView();

	// 생성된 메시지 맵 함수
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnColorchangeBlue();
	afx_msg void OnUpdateColorchangeBlue(CCmdUI *pCmdUI);
	afx_msg void OnColorchangeRed();
	afx_msg void OnUpdateColorchangeRed(CCmdUI *pCmdUI);
	afx_msg void OnColorchangeGreen();
	afx_msg void OnUpdateColorchangeGreen(CCmdUI *pCmdUI);
	afx_msg void OnTbBlue();
	afx_msg void OnTbGreen();
	afx_msg void OnTbRed();
	afx_msg void OnTbElli();
	afx_msg void OnTbRect();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

