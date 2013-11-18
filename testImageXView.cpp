
// testImageXView.cpp : CtestImageXView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "testImageX.h"
#endif

#include "testImageXDoc.h"
#include "testImageXView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtestImageXView

IMPLEMENT_DYNCREATE(CtestImageXView, CScrollView)

BEGIN_MESSAGE_MAP(CtestImageXView, CScrollView)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CtestImageXView ����/����

CtestImageXView::CtestImageXView()
{
	// TODO: �ڴ˴���ӹ������

}

CtestImageXView::~CtestImageXView()
{
}

BOOL CtestImageXView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CScrollView::PreCreateWindow(cs);
}

// CtestImageXView ����

void CtestImageXView::OnDraw(CDC* pDC)
{
	CtestImageXDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (pDoc->m_bIsReady)
	{
		CSize sizeTotal;
		sizeTotal.cx = pDoc->m_nWidth;
		sizeTotal.cy = pDoc->m_nHeight;
		SetScrollSizes(MM_TEXT, sizeTotal);
		LONG LineBytes;
		BITMAPINFO* m_pBitmapInfo = (BITMAPINFO*)new char[sizeof(BITMAPINFO)];
		m_pBitmapInfo->bmiHeader.biClrUsed = 0;
		m_pBitmapInfo->bmiHeader.biBitCount = 24;
		m_pBitmapInfo->bmiHeader.biClrImportant = 0;
		m_pBitmapInfo->bmiHeader.biCompression = BI_RGB;
		m_pBitmapInfo->bmiHeader.biWidth = pDoc->m_nWidth;
		m_pBitmapInfo->bmiHeader.biHeight = pDoc->m_nHeight;
		m_pBitmapInfo->bmiHeader.biPlanes = 1;
		m_pBitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		m_pBitmapInfo->bmiHeader.biSizeImage = (pDoc->m_nWidth*24+31)/32*4*pDoc->m_nHeight;
		m_pBitmapInfo->bmiHeader.biXPelsPerMeter = 0;	
		m_pBitmapInfo->bmiHeader.biYPelsPerMeter = 0;

		LineBytes = (pDoc->m_nWidth*24 + 31)/32*4;

		CDC dcMem;
		CBitmap bmp;
		dcMem.CreateCompatibleDC(pDC);
		bmp.CreateCompatibleBitmap(pDC, pDoc->m_nWidth, pDoc->m_nHeight);
		BYTE* pBuf;
		HBITMAP hbitmap = CreateDIBSection(NULL, m_pBitmapInfo, DIB_RGB_COLORS, (void**)&pBuf, NULL, 0);
		for (int y = 0; y <pDoc->m_nHeight; ++y)
		{
			memcpy(pBuf+y*LineBytes, pDoc->m_pBuf+y*pDoc->m_nWidth*3, pDoc->m_nWidth*3);
		}
		HBITMAP holdmap = (HBITMAP)dcMem.SelectObject(hbitmap);
		pDC->StretchBlt(0, 0, pDoc->m_nWidth, pDoc->m_nHeight, &dcMem, 0, 0, 
			m_pBitmapInfo->bmiHeader.biWidth, m_pBitmapInfo->bmiHeader.biHeight, SRCCOPY);
		dcMem.SelectObject(holdmap);
		dcMem.DeleteDC();
		bmp.DeleteObject();
		DeleteObject(hbitmap);
	}
	else
	{
		CBrush backBrush(RGB(100, 100, 100));

		//����ɵ�brush 
		CBrush* pOldBrush = pDC->SelectObject(&backBrush); 
		CRect rect; 
		pDC->GetClipBox(&rect);

		//����Ҫ������
		pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(), PATCOPY); 
		pDC->SelectObject(pOldBrush); 
	}
}

void CtestImageXView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �������ͼ�ĺϼƴ�С
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CtestImageXView ���

#ifdef _DEBUG
void CtestImageXView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CtestImageXView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CtestImageXDoc* CtestImageXView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CtestImageXDoc)));
	return (CtestImageXDoc*)m_pDocument;
}
#endif //_DEBUG


// CtestImageXView ��Ϣ�������


BOOL CtestImageXView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	return TRUE;
	//return CScrollView::OnEraseBkgnd(pDC);
}
