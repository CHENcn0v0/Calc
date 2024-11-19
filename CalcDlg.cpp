
// CalcDlg.cpp: 实现文件
//
#include <iostream>
//#include <afx.h>
#include "pch.h"
#include "framework.h"
#include "Calc.h"
#include "CalcDlg.h"
#include "afxdialogex.h"
#include <cstdio>
#include <cstring> 
#include <cstdlib>

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


// CCalcDlg 对话框



CCalcDlg::CCalcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALC_DIALOG, pParent)
	, outs(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, outs);
}

BEGIN_MESSAGE_MAP(CCalcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(Cin_0, &CCalcDlg::OnClickedCin_0)
	ON_BN_CLICKED(Cin_1, &CCalcDlg::OnClickedCin1)
	ON_BN_CLICKED(Cin_2, &CCalcDlg::OnClickedCin2)
	ON_BN_CLICKED(Cin_3, &CCalcDlg::OnClickedCin3)
	ON_BN_CLICKED(Cin_4, &CCalcDlg::OnClickedCin4)
	ON_BN_CLICKED(Cin_5, &CCalcDlg::OnClickedCin5)
	ON_BN_CLICKED(Cin_6, &CCalcDlg::OnClickedCin6)
	ON_BN_CLICKED(Cin_7, &CCalcDlg::OnClickedCin7)
	ON_BN_CLICKED(Cin_8, &CCalcDlg::OnClickedCin8)
	ON_BN_CLICKED(Cin_9, &CCalcDlg::OnClickedCin9)
	ON_BN_CLICKED(Cin_d, &CCalcDlg::OnClickedCinD)
	ON_BN_CLICKED(Cin_add, &CCalcDlg::OnClickedCinAdd)
	ON_BN_CLICKED(Cin_clear, &CCalcDlg::OnClickedCinClear)
	ON_BN_CLICKED(Cin_left, &CCalcDlg::OnClickedCinLeft)
	ON_BN_CLICKED(Cin_right, &CCalcDlg::OnClickedCinRight)
	ON_BN_CLICKED(Cin_time, &CCalcDlg::OnClickedCinTime)
	ON_BN_CLICKED(Cin_unadd, &CCalcDlg::OnClickedCinUnadd)
	ON_BN_CLICKED(Cin_untime, &CCalcDlg::OnClickedCinUntime)
	ON_BN_CLICKED(Out_e, &CCalcDlg::OnClickedOutE)
END_MESSAGE_MAP()


// CCalcDlg 消息处理程序

BOOL CCalcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

void CCalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalcDlg::OnPaint()
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
HCURSOR CCalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

bool yes = 0;
void CCalcDlg::up(char p) {
	if (yes == 1) {
		outs.Empty();
		UpdateData(false);
		yes = 0;
	}
	outs += p;
	UpdateData(false);
}
void CCalcDlg::OnClickedCin_0()
{
	up('0');
}
void CCalcDlg::OnClickedCin1()
{
	up('1');
}
void CCalcDlg::OnClickedCin2()
{
	up('2');
}
void CCalcDlg::OnClickedCin3()
{
	up('3');
}
void CCalcDlg::OnClickedCin4()
{
	up('4');
}
void CCalcDlg::OnClickedCin5()
{
	up('5');
}
void CCalcDlg::OnClickedCin6()
{
	up('6');
}
void CCalcDlg::OnClickedCin7()
{
	up('7');
}
void CCalcDlg::OnClickedCin8()
{
	up('8');
}
void CCalcDlg::OnClickedCin9()
{
	up('9');
}
void CCalcDlg::OnClickedCinD()
{
	up('.');
}
void CCalcDlg::OnClickedCinAdd()
{
	up('+');
}
void CCalcDlg::OnClickedCinLeft()
{
	up('(');
}
void CCalcDlg::OnClickedCinRight()
{
	up(')');
}
void CCalcDlg::OnClickedCinTime()
{
	up('X');
}
void CCalcDlg::OnClickedCinUnadd()
{
	up('-');
}
void CCalcDlg::OnClickedCinUntime()
{
	up('/');
}
void CCalcDlg::OnClickedOutE()
{
	calcwork();
	UpdateData(false);
	yes = 1;
}
void CCalcDlg::OnClickedCinClear()
{
	outs.Empty();
	UpdateData(false);
	yes = 0;
}
void change(char* mid, char* suxfix);
double countSuxfix(char* suxfix);
void zhuan(char str[], CString s) {
	for (int i = 0; i < s.GetLength(); i++) {
		if (s[i] == 'X') {
			str[i] = '*';
			continue;
		}
		str[i] = s[i];
	}
	str[s.GetLength()] = '\0';
}
void CCalcDlg::calcwork() {
	char str[1024];
	zhuan(str,outs);
	//char* strr = deleteSpace(str);
	char newStr[1024];
	change(str, newStr);
	double ans=countSuxfix(newStr);
	outs.Empty();
	outs.Format(_T("%lf"), ans);
}
const int  MAXSIZE = 100; // 栈的初始容量
const int  ADDSIZE = 5; // 栈的单位增加容量
using namespace std;// 命名空间
const int INF = -0xfffffff;// 用于空栈时防止尴尬，返回一个不能读取的地址，让读取的人尴尬；
template <class T>
struct Strack
{
	T* top;// 栈顶的指针
	T* base;// 栈底的指针
	int strackSize;//栈容量
	void init()//栈的初始化
	{
		base = (T*)malloc(MAXSIZE * sizeof(T));//分配内存
		top = base;
		strackSize = MAXSIZE;
	}

	T Top()
	{// 返回栈顶元素
		if (top == base)
			return INF;// 返回尴尬地址
		return *(top - 1);
	}

	bool pop()
	{// 删除栈顶元素
		if (top == base)
			return false;
		top--;
		return true;
	}

	void push(T x)
	{//栈顶插入元素
		if (isPull()) {//如果内存不够重新分配内存
			base = (T*)realloc(base, (strackSize + ADDSIZE) * (sizeof(T)));
			top = base + strackSize;
			strackSize += ADDSIZE;
		}
		*top++ = x;
	}

	bool isEmpty()
	{//判断栈是否为空
		if (top == base)
			return true;
		return false;
	}

	bool isPull()//判满函数
	{
		if (top - base == strackSize)// 一次push一个所以当top - base = strackSize时满
			return true;
		else
			return false;
	}
};

int compareNumber(char x)//用来比较符号的优先级
{
	if (x == '+' || x == '-')
		return 0;
	if (x == '*' || x == '/')
		return 1;
	return -1;
}

void change(char* mid, char* suxfix)//中缀表达式转换为后缀表达式     
{
	int i = 0, len = strlen(mid), mid_index = 0;
	char c;
	Strack<char >intElements;// int数据集
	intElements.init();
	intElements.push('#');// 特殊符号用来区分元素
	while (i < len)
	{
		if (mid[i] == '(')
		{
			intElements.push(mid[i]);
			i++;
		}
		else if (mid[i] == ')')
		{
			while (intElements.Top() != '(')
			{
				suxfix[mid_index++] = intElements.Top();
				suxfix[mid_index++] = ' ';
				intElements.pop();
			}
			intElements.pop();
			i++;
		}
		else if (mid[i] == '+' || mid[i] == '-' || mid[i] == '/' || mid[i] == '*')
		{
			while (compareNumber(intElements.Top()) >= compareNumber(mid[i]))
			{
				suxfix[mid_index++] = intElements.Top();
				suxfix[mid_index++] = ' ';
				intElements.pop();
			}
			intElements.push(mid[i]);
			i++;
		}
		else if ((mid[i] >= '0' && mid[i] <= '9')||mid[i]=='.')
		{
			while (mid[i] >= '0' && mid[i] <= '9'||mid[i]=='.')
			{
				suxfix[mid_index++] = mid[i];
				i++;
			}
			suxfix[mid_index++] = ' ';
		}
		else
		{

		}
	}
	while (intElements.Top() != '#') {
		suxfix[mid_index++] = intElements.Top();
		suxfix[mid_index++] = ' ';
		intElements.pop();
	}
	suxfix[mid_index] = 0;
}

double countSuxfix(char* suxfix)//计算后缀表达式   suxfix后缀表达式
{
	int len = strlen(suxfix);
	double x;
	Strack <double>intElements;
	intElements.init();
	int i = 0;
	while (i < len) {
		if (suxfix[i] == ' ')// 用于表达式有效字符集用完跳出循环
		{
			i++;
			continue;
		}
		switch (suxfix[i])
		{
		case '+':
			x = intElements.Top();//根据原理图看
			intElements.pop();
			x = intElements.Top() + x;
			intElements.pop(); i++;
			break;
		case '-':
			x = intElements.Top();
			intElements.pop();
			x = intElements.Top() - x;
			intElements.pop();
			i++;
			break;
		case '*':
			x = intElements.Top();
			intElements.pop();
			x = intElements.Top() * x;
			intElements.pop();
			i++;
			break;
		case '/':
			x = intElements.Top();
			intElements.pop();
			x = intElements.Top() / x;
			intElements.pop();
			i++;
			break;
		default:
		{
			x = 0;
			double xiaoshu = 1;
			while (suxfix[i] >= '0' && suxfix[i] <= '9'|| suxfix[i] == '.') {
				if (suxfix[i] == '.') {
					xiaoshu /= 10;
				}
				else if(xiaoshu==1)	x = x * 10 + suxfix[i] - '0';// 连续2个数，第一个*10，以此类推
				else {
					x += (suxfix[i] - '0') * xiaoshu;
					xiaoshu /= 10;
				}
				i++;
			}
		}	
		}

		intElements.push(x);
	}
	return intElements.Top();
}