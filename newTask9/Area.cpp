// Area.cpp: 实现文件
//

#include "stdafx.h"
#include "newTask9.h"
#include "Area.h"
#include "Volume.h"
#include "afxdialogex.h"
#include <sstream>
using namespace std;

// Area 对话框

IMPLEMENT_DYNAMIC(Area, CDialogEx)

Area::Area(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

Area::~Area()
{
}

void Area::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Area, CDialogEx)
	ON_EN_CHANGE(ID_AREATEXT, &Area::OnEnChangeAreatext)
END_MESSAGE_MAP()
// Area 消息处理程序
void Area::OnEnChangeAreatext()
{
	

	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	// TODO:  在此添加控件通知处理程序代码
	//CString strID_AREATEXT;
	//strID_AREATEXT.Format(_T("%lf"), areadata);
	//SetDlgItemText(ID_AREATEXT, strID_AREATEXT);
}
