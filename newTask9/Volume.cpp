// Volume.cpp: 实现文件
//

#include "stdafx.h"
#include "newTask9.h"
#include "Area.h"
#include "Volume.h"
#include "afxdialogex.h"
#include <sstream>

// Volume 对话框

IMPLEMENT_DYNAMIC(Volume, CDialogEx)

Volume::Volume(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

Volume::~Volume()
{
}

void Volume::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Volume, CDialogEx)
	//ON_EN_CHANGE(IDC_EDIT, &Volume::OnChangeEdit)
END_MESSAGE_MAP()


// Volume 消息处理程序


void Volume::OnChangeEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
