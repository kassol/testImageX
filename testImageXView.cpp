
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

void CtestImageXView::OnDraw(CDC* /*pDC*/)
{
	CtestImageXDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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
