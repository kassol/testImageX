
// testImageX.h : testImageX Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CtestImageXApp:
// �йش����ʵ�֣������ testImageX.cpp
//

class CtestImageXApp : public CWinApp
{
public:
	CtestImageXApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CtestImageXApp theApp;
