
// testImageXView.h : CtestImageXView ��Ľӿ�
//

#pragma once


class CtestImageXView : public CScrollView
{
protected: // �������л�����
	CtestImageXView();
	DECLARE_DYNCREATE(CtestImageXView)

// ����
public:
	CtestImageXDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CtestImageXView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // testImageXView.cpp �еĵ��԰汾
inline CtestImageXDoc* CtestImageXView::GetDocument() const
   { return reinterpret_cast<CtestImageXDoc*>(m_pDocument); }
#endif

