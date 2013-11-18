
// testImageXView.h : CtestImageXView 类的接口
//

#pragma once


class CtestImageXView : public CScrollView
{
protected: // 仅从序列化创建
	CtestImageXView();
	DECLARE_DYNCREATE(CtestImageXView)

// 特性
public:
	CtestImageXDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CtestImageXView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // testImageXView.cpp 中的调试版本
inline CtestImageXDoc* CtestImageXView::GetDocument() const
   { return reinterpret_cast<CtestImageXDoc*>(m_pDocument); }
#endif

