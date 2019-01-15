// Wpc.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "Wpc.h"
#include "afxdialogex.h"


// CWpc 对话框

IMPLEMENT_DYNAMIC(CWpc, CDialogEx)

CWpc::CWpc(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_WPC, pParent)
{

}

CWpc::~CWpc()
{
	
	//OnInitDialog();

}

void CWpc::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_box);
	DDX_Control(pDX, IDC_EDIT1, m_linewpc);
}


BEGIN_MESSAGE_MAP(CWpc, CDialogEx)
	ON_CBN_EDITCHANGE(IDC_COMBO1, &CWpc::OnEditchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CWpc::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CWpc 消息处理程序


void CWpc::OnEditchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	
}


BOOL CWpc::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_box.AddString(_T("wang"));
	m_box.AddString(_T("pei"));
	m_box.AddString(_T("丞"));
	m_box.SetCurSel(1);
	m_linewpc.SetWindowTextW(_T("666"));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CWpc::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	int sel;
	sel = m_box.GetCurSel();
	m_box.GetLBText(sel, str);
	SetDlgItemText(IDC_EDIT1, str);
}
