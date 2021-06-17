

#include "stdafx.h"
#include "chia-plotter.h"
#include "chia-plotterDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CchiaplotterApp

BEGIN_MESSAGE_MAP(CchiaplotterApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()




CchiaplotterApp::CchiaplotterApp()
{

	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;


}




CchiaplotterApp theApp;




BOOL CchiaplotterApp::InitInstance()
{

	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	CShellManager *pShellManager = new CShellManager;

	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));



	CchiaplotterDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();



	return FALSE;
}

