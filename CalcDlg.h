
// CalcDlg.h: 头文件
//

#pragma once


// CCalcDlg 对话框
class CCalcDlg : public CDialogEx
{
// 构造
public:
	CCalcDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void calcwork();
	//afx_msg void OnClickedCin0();
	afx_msg void OnClickedCin_0();
	void up(char p);
	CString outs;
	afx_msg void OnClickedCin1();
	afx_msg void OnClickedCin2();
	afx_msg void OnClickedCin3();
	afx_msg void OnClickedCin4();
	afx_msg void OnClickedCin5();
	afx_msg void OnClickedCin6();
	afx_msg void OnClickedCin7();
	afx_msg void OnClickedCin8();
	afx_msg void OnClickedCin9();
	afx_msg void OnClickedCinD();
	afx_msg void OnClickedCinAdd();
	afx_msg void OnClickedCinClear();
	afx_msg void OnClickedCinLeft();
	afx_msg void OnClickedCinRight();
	afx_msg void OnClickedCinTime();
	afx_msg void OnClickedCinUnadd();
	afx_msg void OnClickedCinUntime();
	afx_msg void OnClickedOutE();
};
