


#pragma once



#include "resource.h"		




class CchiaplotterApp : public CWinApp
{
public:
	CchiaplotterApp();


public:
	virtual BOOL InitInstance();



	DECLARE_MESSAGE_MAP()
};

extern CchiaplotterApp theApp;