
// MFCApplication1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg �Ի���



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, m_oringin(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1_SUM, m_oringin);
}


//�����ע��
/*
���ڣ���������MFC�����ش��롱���ᷢ���ÿ����ˡ�

�ȿ�DECLARE_MESSAGE_MAP()�꣬����MFC�ж������£�

#define DECLARE_MESSAGE_MAP() /
private: /
static const AFX_MSGMAP_ENTRY _messageEntries[]; /
protected: /
static AFX_DATA const AFX_MSGMAP messageMap; /
virtual const AFX_MSGMAP* GetMessageMap() const; /

���Կ���DECLARE_MESSAGE_MAP()������������Ϥ�������ṹ��һ���������Զ��׼��������Ϊÿ����Ҫʵ����Ϣӳ������ṩ����ر����ͺ�����

���ڼ��о�������һ��BEGIN_MESSAGE_MAP��END_MESSAGE_MAP��ON_COMMAND�����꣬������MFC�ж������£�����ON_COMMAND�����������겢û�ж�����ͬһ���ļ��У������ŵ�һ����Ϊ�˺ÿ�����

#define BEGIN_MESSAGE_MAP(theClass, baseClass) /
const AFX_MSGMAP* theClass::GetMessageMap() const /
{ return &theClass::messageMap; } /
AFX_COMDAT AFX_DATADEF const AFX_MSGMAP theClass::messageMap = /
{ &baseClass::messageMap, &theClass::_messageEntries[0] }; /
AFX_COMDAT const AFX_MSGMAP_ENTRY theClass::_messageEntries[] = /
{ /


#define ON_COMMAND(id, memberFxn) /
{ WM_COMMAND, CN_COMMAND, (WORD)id, (WORD)id, AfxSig_vv, (AFX_PMSG)&memberFxn },


#define END_MESSAGE_MAP() /
{0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 } /
}; /

һ���ӿ�����������е㸴�ӣ���������Ǹ��ӣ���ʽ�Ե����ִ��������Ǻ��ѡ��ҿ��������ӣ��������ǿ������һ�˵���Ϊ��Test���������������º꣺

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
ON_COMMAND(ID_TEST, OnTest)
END_MESSAGE_MAP()
��ô��չ��֮��õ����´��룺

const AFX_MSGMAP* CMainFrame::GetMessageMap() const
{ return &CMainFrame::messageMap; }
///����������Ϣ��ӳ����Ϣ
const AFX_MSGMAP CMainFrame::messageMap =
{ &CFrameWnd::messageMap, &CMainFrame::_messageEntries[0] };

//�������뱣���ŵ�ǰ�����Ȥ����Ϣ����������AFX_MSGMAP_ENTRY����
const AFX_MSGMAP_ENTRY CMainFrame::_messageEntries[] =
{
{ WM_COMMAND, CN_COMMAND, (WORD)ID_TEST, (WORD)ID_TEST, AfxSig_vv, (AFX_PMSG)&OnTest },       //       �����ID_TEST��Ϣ����
{0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 } //�������Ϣӳ��Ľ�����
};
*/
BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SUM, &CMFCApplication1Dlg::OnClickedButtonSum)
//	ON_NOTIFY(BCN_DROPDOWN, IDC_BUTTON_SUB, &CMFCApplication1Dlg::OnDropdownButtonSub)
//	ON_BN_DOUBLECLICKED(IDC_BUTTON_SUB, &CMFCApplication1Dlg::OnDoubleclickedButtonSub)
	//ON_BN_CLICKED(IDC_BUTTON_SUB, &CMFCApplication1Dlg::OnBnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_SUB, &CMFCApplication1Dlg::OnBnClickedButtonSub)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCApplication1Dlg::OnCbnSelchangeCombo1)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMFCApplication1Dlg ��Ϣ�������

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnClickedButtonSum()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_oringin = m_oringin + 1;
	UpdateData(FALSE);
	SetTimer(1, 1000, NULL);

}


//void CMFCApplication1Dlg::OnDropdownButtonSub(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMBCDROPDOWN pDropDown = reinterpret_cast<LPNMBCDROPDOWN>(pNMHDR);
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	CWpc pc;
//	INT_PTR nResponse = pc.DoModal();
//	if (nResponse == IDOK)
//	{
//		// TODO: �ڴ˷��ô����ʱ��
//		//  ��ȷ�������رնԻ���Ĵ���
//		AfxMessageBox(_T("123"),MB_OK,0);
//		
//	}
//	else if (nResponse == IDCANCEL)
//	{
//		// TODO: �ڴ˷��ô����ʱ��
//		//  ��ȡ�������رնԻ���Ĵ���
//	}
//	else if (nResponse == -1)
//	{
//		TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
//		TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
//	}
//	*pResult = 0;
//}


//void CMFCApplication1Dlg::OnDoubleclickedButtonSub()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	CWpc pc;
//	INT_PTR nResponse = pc.DoModal();
//	if (nResponse == IDOK)
//	{
//		// TODO: �ڴ˷��ô����ʱ��
//		//  ��ȷ�������رնԻ���Ĵ���
//		INT_PTR n1= AfxMessageBox(_T("shuang"), MB_OKCANCEL, 0);
//
//	}
//	else if (nResponse == IDCANCEL)
//	{
//		// TODO: �ڴ˷��ô����ʱ��
//		//  ��ȡ�������رնԻ���Ĵ���
//	}
//	else if (nResponse == -1)
//	{
//		TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
//		TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
//	}
//}


//void CMFCApplication1Dlg::OnBnClickedButtonSub()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	CWpc pc;
//	INT_PTR nResponse = pc.DoModal();
//	if (nResponse == IDOK)
//	{
//		// TODO: �ڴ˷��ô����ʱ��
//		//  ��ȷ�������رնԻ���Ĵ���
//		INT_PTR n1 = AfxMessageBox(_T("����"), MB_OKCANCEL | MB_ICONWARNING, 0);
//
//	}
//	else if (nResponse == IDCANCEL)
//	{
//		// TODO: �ڴ˷��ô����ʱ��
//		//  ��ȡ�������رնԻ���Ĵ���
//	}
//	else if (nResponse == -1)
//	{
//		TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
//		TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
//	}
//}


void CMFCApplication1Dlg::OnBnClickedButtonSub()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CWpc pc;
		INT_PTR nResponse = pc.DoModal();
		if (nResponse == IDOK)
		{
			// TODO: �ڴ˷��ô����ʱ��
			//  ��ȷ�������رնԻ���Ĵ���
			INT_PTR n1 = AfxMessageBox(_T("����"), MB_OKCANCEL | MB_ICONWARNING, 0);
	
		}
		else if (nResponse == IDCANCEL)
		{
			// TODO: �ڴ˷��ô����ʱ��
			//  ��ȡ�������رնԻ���Ĵ���
		}
		else if (nResponse == -1)
		{
			TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
			TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
		}
}


void CMFCApplication1Dlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMFCApplication1Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	UpdateData(TRUE);
	m_oringin = m_oringin + 1;
	UpdateData(FALSE);

	CDialogEx::OnTimer(nIDEvent);
}
