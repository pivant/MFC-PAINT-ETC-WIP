// ChildView.h : CChildView Ŭ������ �������̽�
//


#pragma once


// CChildView â

class CChildView : public CWnd
{
// �����Դϴ�.
public:
	CChildView();

// Ư���Դϴ�.
public:

	CList <CPoint> m_pt;

	CPoint m_st;
	CPoint m_ed;
	bool m_RButton;

	COLORREF colorchange;
	int elre;

// �۾��Դϴ�.
public:

// �������Դϴ�.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// �����Դϴ�.
public:
	virtual ~CChildView();

	// ������ �޽��� �� �Լ�
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

