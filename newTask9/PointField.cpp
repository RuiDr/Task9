// PointField.cpp: 实现文件
//

#include "stdafx.h"
#include "newTask9.h"
#include "PointField.h"
#include "afxdialogex.h"
#include <iostream>
using namespace std;

// PointField 对话框

IMPLEMENT_DYNAMIC(PointField, CDialogEx)

PointField::PointField(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, pointindex(_T(""))
	, fieldindex(_T(""))
{

}

PointField::~PointField()
{
}

void PointField::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, ID_EDIT_CLEAR, pointindex);
	DDX_Text(pDX, ID_EDIT_PASTE, fieldindex);
}


BEGIN_MESSAGE_MAP(PointField, CDialogEx)
	ON_EN_CHANGE(PointIndex, &PointField::OnEnChangePointindex)
	ON_BN_CLICKED(IDC_BUTTON1, &PointField::OnBnClickedButton1)
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

// 按钮事件
void PointField::OnBnClickedButton1()
{
	AllocConsole();
	int index;
	int nField;
	// TODO: 在此添加控件通知处理程序代码
	CString strEDIT1, strEDIT2, strEDIT3;
	GetDlgItem(ID_EDIT_CLEAR)->GetWindowText(strEDIT1);
	GetDlgItem(ID_EDIT_PASTE)->GetWindowText(strEDIT2);

	// 领域
	index = _ttol(strEDIT1);
	this->index = index;
	nField = _ttol(strEDIT2);
	this->field = nField;
	freopen("CONOUT$", "w+t", stdout);// 申请写
	freopen("CONIN$", "r+t", stdin);  // 申请读
	cout << "求领域" << endl;
}

