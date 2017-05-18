// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "CListTest.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_RButton = false;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_COLORCHANGE_BLUE, &CChildView::OnColorchangeBlue)
	ON_UPDATE_COMMAND_UI(ID_COLORCHANGE_BLUE, &CChildView::OnUpdateColorchangeBlue)
	ON_COMMAND(ID_COLORCHANGE_RED, &CChildView::OnColorchangeRed)
	ON_UPDATE_COMMAND_UI(ID_COLORCHANGE_RED, &CChildView::OnUpdateColorchangeRed)
	ON_COMMAND(ID_COLORCHANGE_GREEN, &CChildView::OnColorchangeGreen)
	ON_UPDATE_COMMAND_UI(ID_COLORCHANGE_GREEN, &CChildView::OnUpdateColorchangeGreen)
	ON_COMMAND(ID_TB_BLUE, &CChildView::OnTbBlue)
	ON_COMMAND(ID_TB_GREEN, &CChildView::OnTbGreen)
	ON_COMMAND(ID_TB_RED, &CChildView::OnTbRed)
	ON_COMMAND(ID_TB_ELLI, &CChildView::OnTbElli)
	ON_COMMAND(ID_TB_RECT, &CChildView::OnTbRect)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



// CChildView �޽��� ó����

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

	CRect rect;
	GetClientRect(rect);
	CDC memDC; // ���� DC
	memDC.CreateCompatibleDC(&dc);
	CBitmap bitmap; // �׸��� ������ ���� ����
	bitmap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	memDC.SelectObject(&bitmap);

	memDC.PatBlt(0, 0, rect.Width(), rect.Height(), WHITENESS);


	CPen pen;
	pen.CreatePen(PS_DOT, 3, colorchange);    
	CPen* oldPen = memDC.SelectObject(&pen);
	CBrush brush;
	brush.CreateSolidBrush(colorchange);     
	CBrush* oldBrush = memDC.SelectObject(&brush);
	//dc.Rectangle(point.x + 10, point.y + 10, point.x + 30, point.y + 30);
	//dc.SelectObject(oldBrush);

	/*CString msg;
	msg.Format(_T("��: %d"), 1234);
	memDC.DrawText(100, 100,msg);*/
	
	
	POSITION ppp = m_pt.GetHeadPosition();

	CString str11;
	str11.Format(_T("��: %d"), m_pt.GetCount());
	memDC.DrawText(str11, CRect(10, 20, 500, 40), DT_VCENTER | DT_SINGLELINE);
	

	while(ppp != NULL)
	{
		CPoint pt = m_pt.GetAt(ppp);
		if (elre == 2)
			memDC.Rectangle(pt.x - 5, pt.y - 5, pt.x + 5, pt.y + 5);
		else
			memDC.Ellipse(pt.x - 5, pt.y - 5, pt.x + 5, pt.y + 5);

		m_pt.GetNext(ppp);
	}

	if(m_RButton == true)
	{
		CPen pen;
		pen.CreatePen(PS_DOT, 3, RGB(5,254,204));
		CPen* oldPen = memDC.SelectObject(&pen);
		CBrush brush;
		brush.CreateStockObject(NULL_BRUSH);    //NULL �귯�� ����
		memDC.SelectObject(brush);
		memDC.Rectangle(m_st.x, m_st.y, m_ed.x, m_ed.y);
	}
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.

	dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);
	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	if(nFlags == MK_LBUTTON)
	{
		m_pt.AddTail(point);
		Invalidate();
	}
	else if(nFlags == MK_RBUTTON)
	{
		m_ed = point;
		Invalidate();
	}

	CWnd::OnMouseMove(nFlags, point);
}

void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	m_st = point;
	m_ed = point;
	m_RButton = true;

	CWnd::OnRButtonDown(nFlags, point);
}

void CChildView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	m_ed = point;
	m_RButton = false;

	POSITION ppp = m_pt.GetHeadPosition();
	while(ppp != NULL)
	{
		POSITION cur = ppp;		
		CPoint pt = m_pt.GetAt(ppp);
		m_pt.GetNext(ppp);

		if (m_st.x < m_ed.x && m_st.y < m_ed.y)
		{
			if (m_st.x < pt.x && pt.x < m_ed.x && m_st.y < pt.y && pt.y < m_ed.y)
			{
				m_pt.RemoveAt(cur);
			}
		}

		if (m_st.x > m_ed.x && m_st.y > m_ed.y)
		{
			if (m_st.x > pt.x && pt.x > m_ed.x && m_st.y > pt.y && pt.y > m_ed.y)
			{
				m_pt.RemoveAt(cur);
			}
		}

		if (m_st.x < m_ed.x && m_st.y > m_ed.y)
		{
			if (m_st.x < pt.x && pt.x < m_ed.x &&
				m_st.y > pt.y && pt.y > m_ed.y)
			{
				m_pt.RemoveAt(cur);
			}
		}

		if (m_st.x > m_ed.x && m_st.y < m_ed.y)
		{
			if (m_st.x > pt.x && pt.x > m_ed.x &&
				m_st.y < pt.y && pt.y < m_ed.y)
			{
				m_pt.RemoveAt(cur);
			}
		}
	}

	Invalidate();

	CWnd::OnRButtonUp(nFlags, point);
}




void CChildView::OnColorchangeBlue()
{
	colorchange = (RGB(0, 0, 255));
	Invalidate();
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CChildView::OnUpdateColorchangeBlue(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->SetCheck(colorchange == RGB(0, 0, 255));
}


void CChildView::OnColorchangeRed()
{
	colorchange = (RGB(255, 0, 0));
	Invalidate();
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CChildView::OnUpdateColorchangeRed(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->SetCheck(colorchange == RGB(255, 0, 0));
}


void CChildView::OnColorchangeGreen()
{
	colorchange = (RGB(0, 255, 0));
	Invalidate();
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CChildView::OnUpdateColorchangeGreen(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->SetCheck(colorchange == RGB(0, 255, 0));
}



void CChildView::OnTbBlue()
{
	colorchange = (RGB(0, 0, 255));
	Invalidate();
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CChildView::OnTbGreen()
{
	colorchange = (RGB(0, 255, 0));
	Invalidate();
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CChildView::OnTbRed()
{
	colorchange = (RGB(255, 0, 0));
	Invalidate();
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CChildView::OnTbElli()
{
	elre = 1;
	Invalidate();
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CChildView::OnTbRect()
{
	elre = 2;
	Invalidate();
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	return true;
	//return CWnd::OnEraseBkgnd(pDC);
}
