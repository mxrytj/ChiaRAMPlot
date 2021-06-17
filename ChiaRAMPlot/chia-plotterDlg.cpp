

#include "stdafx.h"
#include "chia-plotter.h"
#include "chia-plotterDlg.h"
#include "afxdialogex.h"
#include "Chia.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



CchiaplotterDlg::CchiaplotterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CchiaplotterDlg::IDD, pParent)
{
	//IDR_MAINFRAME
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CchiaplotterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Plots, m_plots);
	DDX_Control(pDX, IDC_Threads, m_CobThreads);
	DDX_Control(pDX, IDC_Buckets, m_buckets);
	DDX_Control(pDX, IDC_cmd, m_cmdEdit);
	DDX_Control(pDX, IDC_btnStart, m_btnCreatePlot);

}

BEGIN_MESSAGE_MAP(CchiaplotterDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(MSG_DATAREC, OnDataRec)
	ON_BN_CLICKED(IDC_btnStart, &CchiaplotterDlg::OnBnClickedbtnstart)
	ON_BN_CLICKED(IDC_createplot, &CchiaplotterDlg::OnBnClickedcreateplot)
END_MESSAGE_MAP()





LRESULT CchiaplotterDlg::OnDataRec(WPARAM wparam, LPARAM lparam)
{

	this->m_cmdEdit.SetSel(-1, -1);
	this->m_cmdEdit.ReplaceSel(CString(m_data));

	return 0;
}


BOOL CchiaplotterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	memset(this->m_data, 0, 10000);


	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);		


	m_plots.AddString(L"1");
	m_plots.AddString(L"2");
	m_plots.AddString(L"3");
	m_plots.AddString(L"4");
	m_plots.AddString(L"5");
	m_plots.AddString(L"6");
	m_plots.AddString(L"7");
	m_plots.AddString(L"8");
	m_plots.AddString(L"9");
	m_plots.AddString(L"10");
	m_plots.AddString(L"11");
	m_plots.AddString(L"12");
	m_plots.AddString(L"13");
	m_plots.AddString(L"14");
	m_plots.AddString(L"15");
	m_plots.AddString(L"16");
	m_plots.AddString(L"17");
	m_plots.AddString(L"18");
	m_plots.AddString(L"19");
	m_plots.AddString(L"20");
	m_plots.AddString(L"21");
	m_plots.AddString(L"22");
	m_plots.AddString(L"23");
	m_plots.AddString(L"24");
	m_plots.AddString(L"25");
	m_plots.AddString(L"26");
	m_plots.AddString(L"27");
	m_plots.AddString(L"28");
	m_plots.AddString(L"29");
	m_plots.SetCurSel(0);

	m_CobThreads.AddString(L"4");
	m_CobThreads.AddString(L"6");
	m_CobThreads.AddString(L"8");
	m_CobThreads.AddString(L"10");
	m_CobThreads.AddString(L"12");
	m_CobThreads.AddString(L"14");
	m_CobThreads.AddString(L"16");
	m_CobThreads.AddString(L"18");
	m_CobThreads.AddString(L"20");
	m_CobThreads.AddString(L"22");
	m_CobThreads.AddString(L"24");
	m_CobThreads.AddString(L"26");
	m_CobThreads.AddString(L"28");
	m_CobThreads.AddString(L"30");
	m_CobThreads.AddString(L"32");
	m_CobThreads.AddString(L"34");
	m_CobThreads.AddString(L"36");
	m_CobThreads.AddString(L"38");
	m_CobThreads.AddString(L"40");
	m_CobThreads.AddString(L"42");
	m_CobThreads.AddString(L"44");
	m_CobThreads.AddString(L"46");
	m_CobThreads.AddString(L"48");
	m_CobThreads.AddString(L"50");
	m_CobThreads.AddString(L"52");
	m_CobThreads.AddString(L"54");
	m_CobThreads.AddString(L"58");
	m_CobThreads.AddString(L"60");
	m_CobThreads.AddString(L"62");
	m_CobThreads.AddString(L"64");
	m_CobThreads.SetCurSel(0);

	

	m_buckets.AddString(L"256");
	m_buckets.AddString(L"128");
	m_buckets.SetCurSel(0);


	


	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = true;

	if (!CreatePipe(&m_read, &m_write, &sa, 0))
	{
		MessageBox(L"CreatePipe return false!");
		return false;
	}

	if (!CreatePipe(&m_cread, &m_cwrite, &sa, 0))
	{
		MessageBox(L"CreatePipe return false!");
		return false;
	}
	
	return TRUE;  
}


void CchiaplotterDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this);

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);


		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

	
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}


HCURSOR CchiaplotterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

UINT ReadPipeProc(LPVOID param)
{
	CchiaplotterDlg *pAttachWnd = static_cast<CchiaplotterDlg *>(param);
	HANDLE hRead = pAttachWnd->m_read;
	HWND hWnd = pAttachWnd->GetSafeHwnd();

	DWORD bytesRead;
	while (1)
	{
		int len = 1000;
		memset(pAttachWnd->m_data, 0, 1000);
		if (!ReadFile(hRead, pAttachWnd->m_data, len, &bytesRead, NULL))
		{
			Sleep(10000);
		}
		else
		{
			SendMessage(hWnd, MSG_DATAREC, 0, 0);
		}

	
	}

	return 0;
}

void CchiaplotterDlg::RunCmd(CString szCmdPar)
{
	AfxBeginThread(ReadPipeProc, this, NULL);
	
	STARTUPINFO si;
	si.cb = sizeof(STARTUPINFO);
	GetStartupInfo(&si);
	si.hStdError = m_write;
	si.hStdOutput = m_write;
	si.hStdInput = m_cread;
	si.wShowWindow = SW_HIDE;
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;

	if (!CreateProcess(NULL, (LPTSTR)(LPCTSTR)szCmdPar, NULL, NULL, TRUE, NULL, NULL, NULL, &si, &pi))
	{
		MessageBox(L"CreateProcess failed!");
		return;
	}
}
HANDLE hRead, hWrite;


void CchiaplotterDlg::OnBnClickedOk()
{

}




void CchiaplotterDlg::OnBnClickedbtnstart()
{

	CString strPlots; /
	int cindexA = this->m_plots.GetCurSel();
	this->m_plots.GetLBText(cindexA, strPlots);

	CString strThread; 
	int cindexB = this->m_CobThreads.GetCurSel();
	this->m_CobThreads.GetLBText(cindexB, strThread);

	CString strbuckets; 
	int cindexC = this->m_buckets.GetCurSel();
	this->m_buckets.GetLBText(cindexC, strbuckets);


	CString selectedTemDir;
	GetDlgItemText(IDC_TemDir, selectedTemDir);

	if (selectedTemDir.IsEmpty())
	{
		MessageBoxEx(NULL, L"Temporary directory cannot be empty!", L"Alert", MB_OK, MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US));
		return;
	}

	CString selectedTemDir2;
	GetDlgItemText(IDC_TemDir2, selectedTemDir2);
	if (selectedTemDir2.IsEmpty())
	{
		MessageBoxEx(NULL, L"Temporary directory 2 cannot be empty!", L"Alert", MB_OK, MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US));
		return;
	}

	CString selectedFinaDir;
	GetDlgItemText(IDC_FinaDir, selectedFinaDir);
	if (selectedFinaDir.IsEmpty())
	{
		MessageBoxEx(NULL, L"Final directory cannot be empty!", L"Alert", MB_OK, MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US));
		return;
	}


	CString strPoolPublicKey;
	GetDlgItemText(IDC_PoolPublicKey, strPoolPublicKey);

	if (strPoolPublicKey.IsEmpty())
	{
		MessageBoxEx(NULL, L"Pool public key cannot be empty!", L"Alert", MB_OK, MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US));
		return;
	}

	CString strFarmerPublicKey;
	GetDlgItemText(IDC_FarmerPublicKye, strFarmerPublicKey);
	if (strFarmerPublicKey.IsEmpty())
	{
		MessageBoxEx(NULL, L"Farmer public key cannot be empty!", L"Alert", MB_OK, MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US));
		return;
	}
	CString cmd = L"chia_plot.exe -n " + strPlots + " -r " + strThread + " -u " + strbuckets + " -t " + selectedTemDir + " -2 " + selectedTemDir2 + " -d " + selectedFinaDir + " -p " + strPoolPublicKey + " -f " + strFarmerPublicKey;
	RunCmd(cmd);
}


