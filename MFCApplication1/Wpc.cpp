// Wpc.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "Wpc.h"
#include "afxdialogex.h"


// CWpc �Ի���

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


// CWpc ��Ϣ�������


void CWpc::OnEditchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
}


BOOL CWpc::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_box.AddString(_T("wang"));
	m_box.AddString(_T("pei"));
	m_box.AddString(_T("ة"));
	m_box.SetCurSel(1);
	m_linewpc.SetWindowTextW(_T("666"));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CWpc::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	int sel;
	sel = m_box.GetCurSel();
	m_box.GetLBText(sel, str);
	SetDlgItemText(IDC_EDIT1, str);
}
