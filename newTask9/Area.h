#pragma once
// Area 对话框

class Area : public CDialogEx
{
	DECLARE_DYNAMIC(Area)

public:
	Area(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Area();
	double areadata=0.0;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeAreatext();
};
