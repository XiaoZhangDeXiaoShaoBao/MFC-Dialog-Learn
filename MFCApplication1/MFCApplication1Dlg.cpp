
// MFCApplication1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFCApplication1Dlg 对话框



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


//下面的注释
/*
现在，我们来看MFC“神秘代码”，会发觉好看多了。

先看DECLARE_MESSAGE_MAP()宏，它在MFC中定义如下：

#define DECLARE_MESSAGE_MAP() /
private: /
static const AFX_MSGMAP_ENTRY _messageEntries[]; /
protected: /
static AFX_DATA const AFX_MSGMAP messageMap; /
virtual const AFX_MSGMAP* GetMessageMap() const; /

可以看出DECLARE_MESSAGE_MAP()定义了我们熟悉的两个结构和一个函数，显而易见，这个宏为每个需要实现消息映射的类提供了相关变量和函数。

现在集中精力来看一下BEGIN_MESSAGE_MAP，END_MESSAGE_MAP和ON_COMMAND三个宏，它们在MFC中定义如下（其中ON_COMMAND与另外两个宏并没有定义在同一个文件中，把它放到一起是为了好看）：

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

一下子看三个宏觉得有点复杂，但这仅仅是复杂，公式性的文字代换并不是很难。且看下面例子，假设我们框架中有一菜单项为“Test”，即定义了如下宏：

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
ON_COMMAND(ID_TEST, OnTest)
END_MESSAGE_MAP()
那么宏展开之后得到如下代码：

const AFX_MSGMAP* CMainFrame::GetMessageMap() const
{ return &CMainFrame::messageMap; }
///以下填入消息表映射信息
const AFX_MSGMAP CMainFrame::messageMap =
{ &CFrameWnd::messageMap, &CMainFrame::_messageEntries[0] };

//下面填入保存着当前类感兴趣的消息，可填入多个AFX_MSGMAP_ENTRY对象
const AFX_MSGMAP_ENTRY CMainFrame::_messageEntries[] =
{
{ WM_COMMAND, CN_COMMAND, (WORD)ID_TEST, (WORD)ID_TEST, AfxSig_vv, (AFX_PMSG)&OnTest },       //       加入的ID_TEST消息参数
{0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 } //本类的消息映射的结束项
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


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnClickedButtonSum()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_oringin = m_oringin + 1;
	UpdateData(FALSE);
	SetTimer(1, 1000, NULL);

}


//void CMFCApplication1Dlg::OnDropdownButtonSub(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMBCDROPDOWN pDropDown = reinterpret_cast<LPNMBCDROPDOWN>(pNMHDR);
//	// TODO: 在此添加控件通知处理程序代码
//	CWpc pc;
//	INT_PTR nResponse = pc.DoModal();
//	if (nResponse == IDOK)
//	{
//		// TODO: 在此放置处理何时用
//		//  “确定”来关闭对话框的代码
//		AfxMessageBox(_T("123"),MB_OK,0);
//		
//	}
//	else if (nResponse == IDCANCEL)
//	{
//		// TODO: 在此放置处理何时用
//		//  “取消”来关闭对话框的代码
//	}
//	else if (nResponse == -1)
//	{
//		TRACE(traceAppMsg, 0, "警告: 对话框创建失败，应用程序将意外终止。\n");
//		TRACE(traceAppMsg, 0, "警告: 如果您在对话框上使用 MFC 控件，则无法 #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS。\n");
//	}
//	*pResult = 0;
//}


//void CMFCApplication1Dlg::OnDoubleclickedButtonSub()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	CWpc pc;
//	INT_PTR nResponse = pc.DoModal();
//	if (nResponse == IDOK)
//	{
//		// TODO: 在此放置处理何时用
//		//  “确定”来关闭对话框的代码
//		INT_PTR n1= AfxMessageBox(_T("shuang"), MB_OKCANCEL, 0);
//
//	}
//	else if (nResponse == IDCANCEL)
//	{
//		// TODO: 在此放置处理何时用
//		//  “取消”来关闭对话框的代码
//	}
//	else if (nResponse == -1)
//	{
//		TRACE(traceAppMsg, 0, "警告: 对话框创建失败，应用程序将意外终止。\n");
//		TRACE(traceAppMsg, 0, "警告: 如果您在对话框上使用 MFC 控件，则无法 #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS。\n");
//	}
//}


//void CMFCApplication1Dlg::OnBnClickedButtonSub()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	CWpc pc;
//	INT_PTR nResponse = pc.DoModal();
//	if (nResponse == IDOK)
//	{
//		// TODO: 在此放置处理何时用
//		//  “确定”来关闭对话框的代码
//		INT_PTR n1 = AfxMessageBox(_T("单机"), MB_OKCANCEL | MB_ICONWARNING, 0);
//
//	}
//	else if (nResponse == IDCANCEL)
//	{
//		// TODO: 在此放置处理何时用
//		//  “取消”来关闭对话框的代码
//	}
//	else if (nResponse == -1)
//	{
//		TRACE(traceAppMsg, 0, "警告: 对话框创建失败，应用程序将意外终止。\n");
//		TRACE(traceAppMsg, 0, "警告: 如果您在对话框上使用 MFC 控件，则无法 #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS。\n");
//	}
//}


void CMFCApplication1Dlg::OnBnClickedButtonSub()
{
	// TODO: 在此添加控件通知处理程序代码
	CWpc pc;
		INT_PTR nResponse = pc.DoModal();
		if (nResponse == IDOK)
		{
			// TODO: 在此放置处理何时用
			//  “确定”来关闭对话框的代码
			INT_PTR n1 = AfxMessageBox(_T("单机"), MB_OKCANCEL | MB_ICONWARNING, 0);
	
		}
		else if (nResponse == IDCANCEL)
		{
			// TODO: 在此放置处理何时用
			//  “取消”来关闭对话框的代码
		}
		else if (nResponse == -1)
		{
			TRACE(traceAppMsg, 0, "警告: 对话框创建失败，应用程序将意外终止。\n");
			TRACE(traceAppMsg, 0, "警告: 如果您在对话框上使用 MFC 控件，则无法 #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS。\n");
		}
}


void CMFCApplication1Dlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication1Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	UpdateData(TRUE);
	m_oringin = m_oringin + 1;
	UpdateData(FALSE);

	CDialogEx::OnTimer(nIDEvent);
}
