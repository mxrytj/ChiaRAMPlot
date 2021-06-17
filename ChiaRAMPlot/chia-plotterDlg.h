


#pragma once
#include "afxwin.h"
#include "afxbutton.h"



class CchiaplotterDlg : public CDialogEx
{

public:
	CchiaplotterDlg(CWnd* pParent = NULL);	


	enum { IDD = IDD_CHIAPLOTTER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	


protected:
	HICON m_hIcon;


	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_plots;
	CComboBox m_CobThreads;
	CComboBox m_buckets;
	afx_msg void OnBnClickedOk();
	void RunCmd(CString cmd);
	CEdit m_cmdEdit;
	HANDLE m_read, m_write, m_cread, m_cwrite;
	char m_data[10000];
	LRESULT OnDataRec(WPARAM wparam, LPARAM lparam);
	PROCESS_INFORMATION pi;
	afx_msg void OnBnClickedbtnstart();
	BOOL bSend = false;
	CButton m_btnCreatePlot;
	afx_msg void OnBnClickedcreateplot();
};
