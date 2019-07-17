// Volume.cpp: 实现文件
//

#include "stdafx.h"
#include "newTask9.h"
#include "Volume.h"
#include "afxdialogex.h"


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
END_MESSAGE_MAP()


// Volume 消息处理程序
