// PointField.cpp: 实现文件
//

#include "stdafx.h"
#include "newTask9.h"
#include "PointField.h"
#include "afxdialogex.h"


// PointField 对话框

IMPLEMENT_DYNAMIC(PointField, CDialogEx)

PointField::PointField(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

PointField::~PointField()
{
}

void PointField::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PointField, CDialogEx)
	ON_EN_CHANGE(PointIndex, &PointField::OnEnChangePointindex)
END_MESSAGE_MAP()


// PointField 消息处理程序


void PointField::OnEnChangePointindex()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
