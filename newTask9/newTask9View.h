
// newTask9View.h: CnewTask9View 类的接口
//

#pragma once


class CnewTask9View : public CView
{
private :
	HGLRC m_hRC;
	CClientDC* m_pDC;
protected: // 仅从序列化创建
	CnewTask9View() noexcept;
	DECLARE_DYNCREATE(CnewTask9View)

// 特性
public:
	CnewTask9Doc* GetDocument() const;
	int m_iViewWide;					// 视图宽度
	int m_iViewHeigth;				// 视图高度

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CnewTask9View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	BOOL setPixelFormat();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void OnInitialUpdate();

	afx_msg void OnOpengl1Draw();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	afx_msg void OnOpenFile();
	afx_msg void OnShow();
	afx_msg void OnShowModel();
	afx_msg void OnToPly();
};
#ifndef _DEBUG  // newTask9View.cpp 中的调试版本
inline CnewTask9Doc* CnewTask9View::GetDocument() const
   { return reinterpret_cast<CnewTask9Doc*>(m_pDocument); }
#endif

