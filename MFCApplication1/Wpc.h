#pragma once
#include "afxwin.h"


// CWpc 对话框

class CWpc : public CDialogEx
{
	DECLARE_DYNAMIC(CWpc)

public:
	CWpc(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CWpc();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WPC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_box;
	afx_msg void OnEditchangeCombo1();
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeCombo1();
	CEdit m_linewpc;
};
