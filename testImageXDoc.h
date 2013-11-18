
// testImageXDoc.h : CtestImageXDoc ��Ľӿ�
//


#pragma once


class CtestImageXDoc : public CDocument
{
protected: // �������л�����
	CtestImageXDoc();
	DECLARE_DYNCREATE(CtestImageXDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CtestImageXDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
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
