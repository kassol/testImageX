
// testImageXDoc.cpp : CtestImageXDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "testImageX.h"
#endif

#include "testImageXDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CtestImageXDoc

IMPLEMENT_DYNCREATE(CtestImageXDoc, CDocument)

BEGIN_MESSAGE_MAP(CtestImageXDoc, CDocument)
	ON_COMMAND(ID_FILE_OPEN, &CtestImageXDoc::OnFileOpen)
END_MESSAGE_MAP()


// CtestImageXDoc 构造/析构

CtestImageXDoc::CtestImageXDoc()
{
	// TODO: 在此添加一次性构造代码
	m_pBuf = NULL;
	m_bIsReady = false;
}

CtestImageXDoc::~CtestImageXDoc()
{
}

BOOL CtestImageXDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CtestImageXDoc 序列化

void CtestImageXDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CtestImageXDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CtestImageXDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CtestImageXDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CtestImageXDoc 诊断

#ifdef _DEBUG
void CtestImageXDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CtestImageXDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CtestImageXDoc 命令


void CtestImageXDoc::OnFileOpen()
{
	// TODO: Add your command handler code here
	m_bIsReady = false;
	HRESULT hr = CoCreateInstance(CLSID_ImageDriverX, NULL, CLSCTX_ALL, IID_IImageX, (void**)&m_pImage);
	if (FAILED(hr))
	{
		AfxMessageBox(_T("组件注册失败！"));
		return;
	}
	USES_CONVERSION;
	BYTE* szFilterName = new BYTE[500];
	m_pImage->GetSupExts(szFilterName, modeRead);

	CString strFilterName;
	strFilterName.Format(_T("%s"), A2T((char*)szFilterName));

	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, strFilterName, NULL);
	if (IDOK == dlg.DoModal())
	{
		m_strImagePath = dlg.GetPathName();
		m_pImage->Open(m_strImagePath.AllocSysString(), modeRead|modeAqlut);
		m_pImage->GetBandNum(&m_nBandNum);
		m_pImage->GetCols(&m_nWidth);
		m_pImage->GetRows(&m_nHeight);

		m_nHeight = 5000;
		m_nWidth = 5000;

		if (m_pBuf != NULL)
		{
			delete []m_pBuf;
			m_pBuf = NULL;
		}
		m_pBuf = new BYTE[m_nWidth*m_nHeight*m_nBandNum];

		//m_pImage->ReadImg(13883, 1, 16383, 2501, m_pBuf, 5000, 5000, 1, 0, 0, 2500, 2500, -1, 0);

		m_pImage->ReadImg(13884, 18454, 18884, 23454, m_pBuf, m_nWidth, m_nHeight, 1, 0, 0,
			m_nWidth, m_nHeight, 0, 0);

		/*m_pImage->ReadImg(0, 0, m_nWidth, m_nHeight, m_pBuf, 
		m_nWidth, m_nHeight, 3, 0, 0, m_nWidth, m_nHeight, 0, 2);
		m_pImage->ReadImg(0, 0, m_nWidth, m_nHeight, m_pBuf, 
		m_nWidth, m_nHeight, 3, 0, 0, m_nWidth, m_nHeight, 1, 1);
		m_pImage->ReadImg(0, 0, m_nWidth, m_nHeight, m_pBuf, 
		m_nWidth, m_nHeight, 3, 0, 0, m_nWidth, m_nHeight, 2, 0);*/
		m_bIsReady = true;
		UpdateAllViews(NULL);
	}
}
