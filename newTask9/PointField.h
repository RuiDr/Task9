#pragma once


// PointField 对话框

class PointField : public CDialogEx
{
	DECLARE_DYNAMIC(PointField)

public:
	PointField(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~PointField();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int index;
	int field;
	afx_msg void OnEnChangePointindex();
	afx_msg void OnBnClickedButton1();
	CString pointindex;
	CString fieldindex;
};
