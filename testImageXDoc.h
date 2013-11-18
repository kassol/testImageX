
// testImageXDoc.h : CtestImageXDoc 类的接口
//


#pragma once


class CtestImageXDoc : public CDocument
{
protected: // 仅从序列化创建
	CtestImageXDoc();
	DECLARE_DYNCREATE(CtestImageXDoc)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CtestImageXDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS

private:
	IImage* m_pImage;
	CString m_strImagePath;
public:
	int m_nWidth;
	int m_nHeight;
	int m_nBandNum;
	BYTE* m_pBuf;
	bool m_bIsReady;
public:
	afx_msg void OnFileOpen();
};
