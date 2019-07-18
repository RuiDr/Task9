#pragma once


// Volume 对话框

class Volume : public CDialogEx
{
	DECLARE_DYNAMIC(Volume)

public:
	Volume(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Volume();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChangeEdit();
};
