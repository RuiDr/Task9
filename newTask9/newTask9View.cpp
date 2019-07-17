
// newTask9View.cpp: CnewTask9View 类的实现
//

#include "stdafx.h"
#include <atlstr.h>

// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "newTask9.h"
#endif
#include "newTask9Doc.h"
#include "newTask9View.h"
#include <iostream>
#include "Model.h"
#include "MyPoint.h"
#include "Facet.h"
#include <io.h> 
#include "Volume.h"
#include "Area.h"
#include <fcntl.h>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// CnewTask9View
Volume *volume;
Area *area;
GLfloat x_min = .0, x_max = 20.0, y_min = .0, y_max = 20.0, z_min = .0, z_max = 20.0;
GLfloat modelview_z_dis;
GLfloat PI = 3.141596;
GLfloat modelview_matrix[16];
GLfloat default_matrix[16];
GLfloat angle = 0.0;
double Sarea = 0.0;
double Vvolume;
void ReadStlFile(string fileName);

Model model;
IMPLEMENT_DYNCREATE(CnewTask9View, CView)

BEGIN_MESSAGE_MAP(CnewTask9View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()

	ON_COMMAND(ID_OPENGL1_DRAW, &CnewTask9View::OnOpengl1Draw)
	ON_WM_SIZE()
	ON_WM_DESTROY()
	//ON_COMMAND(ID_32775, &CnewTask9View::OnOpenFile)

	//ON_COMMAND(ID_32776, &CnewTask9View::OnShowModel)
	ON_COMMAND(ID_OPENGL_DRAW, &CnewTask9View::OnToPly)
	ON_COMMAND(ID_32780, &CnewTask9View::OnFileOpen)
	ON_COMMAND(ID_32781, &CnewTask9View::OnModelShow)
	//ON_COMMAND(ID_N32779, &CnewTask9View::OnNFile)
	ON_COMMAND(ID_Volume, &CnewTask9View::OnVolume)
	ON_COMMAND(ID_Area, &CnewTask9View::OnArea)
	ON_COMMAND(32785, &CnewTask9View::OnSArea)
END_MESSAGE_MAP()

// CnewTask9View 构造/析构

CnewTask9View::CnewTask9View() noexcept
{
	// TODO: 在此处添加构造代码

}

CnewTask9View::~CnewTask9View()
{
}

BOOL CnewTask9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CnewTask9View 绘图

void CnewTask9View::OnDraw(CDC* /*pDC*/)
{
	CnewTask9Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此添加命令处理程序代码
// TODO: 在此添加命令处理程序代码
	cout << "面片数 " << model.modelFacet.size() << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DOUBLE);
	glMatrixMode(GL_MODELVIEW);
	for (auto it = model.modelFacet.begin();it != model.modelFacet.end();it++)
	{
		glPushMatrix();
		glBegin(GL_TRIANGLES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(it->second._vertex_1._x / 100, it->second._vertex_1._y / 100, it->second._vertex_1._z / 100);
		glVertex3f(it->second._vertex_3._x / 100, it->second._vertex_3._y / 100, it->second._vertex_3._z / 100);
		glVertex3f(it->second._vertex_2._x / 100, it->second._vertex_2._y / 100, it->second._vertex_2._z / 100);
		glEnd(); //三角形
		glPopMatrix();
		// 画线
		glBegin(GL_LINES);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(it->second._vertex_1._x / 100, it->second._vertex_1._y / 100, it->second._vertex_1._z / 100);
		glVertex3f(it->second._vertex_3._x / 100, it->second._vertex_3._y / 100, it->second._vertex_3._z / 100);
		glEnd();


		glBegin(GL_LINES);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(it->second._vertex_1._x / 100, it->second._vertex_1._y / 100, it->second._vertex_1._z / 100);
		glVertex3f(it->second._vertex_2._x / 100, it->second._vertex_2._y / 100, it->second._vertex_2._z / 100);
		glEnd();

		glBegin(GL_LINES);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(it->second._vertex_3._x / 100, it->second._vertex_3._y / 100, it->second._vertex_3._z / 100);
		glVertex3f(it->second._vertex_2._x / 100, it->second._vertex_2._y / 100, it->second._vertex_2._z / 100);
		glEnd();
	}
	SwapBuffers(wglGetCurrentDC());
	// 交换缓冲区  
	cout << " 绘制完成" << endl;

	// TODO: 在此处为本机数据添加绘制代码
}
// CnewTask9View 打印

BOOL CnewTask9View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CnewTask9View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CnewTask9View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}
// CnewTask9View 诊断

#ifdef _DEBUG
void CnewTask9View::AssertValid() const
{
	CView::AssertValid();
}

void CnewTask9View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CnewTask9Doc* CnewTask9View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CnewTask9Doc)));
	return (CnewTask9Doc*)m_pDocument;
}
#endif //_DEBUG
// CnewTask9View 消息处理程序
BOOL CnewTask9View::setPixelFormat()
{
	// TODO: 在此处添加实现代码.
	static PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR), // 结构的大小  
		1, // 结构的版本  
		PFD_DRAW_TO_WINDOW | // 在窗口(而不是位图)中绘图  
		PFD_SUPPORT_OPENGL | // 支持在窗口中进行OpenGL调用  
		PFD_DOUBLEBUFFER, // 双缓冲模式  
		PFD_TYPE_RGBA, // RGBA颜色模式  
		32, // 需要32位颜色  
		0, 0, 0, 0, 0, 0, // 不用于选择模式  
		0, 0, // 不用于选择模式  
		0, 0, 0, 0, 0, // 不用于选择模式  
		16, // 深度缓冲区的大小  
		0, // 在此不使用  
		0, // 在此不使用  
		0, // 在此不使用  
		0, // 在此不使用  
		0, 0, 0 // 在此不使用  
	};
	// 选择一种与pfd所描述的最匹配的像素格式  
	// 为设备环境设置像素格式  
	int pixelformat;
	pixelformat = ChoosePixelFormat(m_pDC->GetSafeHdc(), &pfd);
	if (0 == pixelformat) return false;
	// 为设备环境设置像素格式  
	return SetPixelFormat(m_pDC->GetSafeHdc(), pixelformat, &pfd);
	return false;
}


int CnewTask9View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	m_pDC = new CClientDC(this);
	ASSERT(m_pDC != NULL);
	// 选择像素格式  
	if (!setPixelFormat()) return -1;
	// 创建渲染环境, 并使它成为当前渲染环境  
	m_hRC = wglCreateContext(m_pDC->GetSafeHdc());

	wglMakeCurrent(m_pDC->GetSafeHdc(), m_hRC);

	return 0;
}

void CnewTask9View::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	glClearColor(1, 1, 1, 0);
	glShadeModel(GL_FLAT);


	// TODO: 在此添加专用代码和/或调用基类
}
void CnewTask9View::OnOpengl1Draw()
{
	// TODO: 在此添加命令处理程序代码
	glClear(GL_COLOR_BUFFER_BIT | GL_DOUBLE);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(-0.5, 0.5);
	glVertex2f(-0.5, -0.5);
	glEnd();
	glPopMatrix();
	// 交换缓冲区  
	SwapBuffers(wglGetCurrentDC());
}
void CnewTask9View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	glViewport(0, 0, cx, cy);
	// 设置投影矩阵(透视投影)  
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)cx / (GLfloat)cy, 1.0, 1000.0);
	// 设置模型视图矩阵  
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

}
void CnewTask9View::OnDestroy()
{
	CView::OnDestroy();
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(m_hRC);
	delete m_pDC;
	// TODO: 在此处添加消息处理程序代码
}

// 读取stl文件
void ReadStlFile(string fileName)
{
	cout << "file name is "<<fileName<< endl;

	// 存储点的信息
	map<int, MyPoint>_mapPoint;
	// 存储面片的信息
	map<int, Facet>_mapFacet;
	map<string, int>_setPoint;
	string s;
	int nodeNumber = 0;
	int pointCount = 0;
	int facetCount = 0;
	try
	{
		fstream fin(fileName);
		Facet cFacet;
		while (getline(fin, s))
		{
			if (strstr(s.c_str(), "vertex") != NULL)
			{
				pointCount++;
				istringstream iss(s);
				string first;
				double x1, y1, z1;
				iss >> first >> x1 >> y1 >> z1;
				MyPoint point(x1, y1, z1);
				//point.index = 0;
				// 判断map中是否已经存在该点
				auto it = _setPoint.find(s);
				if (it == _setPoint.end())
				{
					_setPoint.insert(pair<string, int>(s, nodeNumber));
					point.addFacet(facetCount);
					point.index = nodeNumber;
					model.addPoint(point, nodeNumber);
					nodeNumber++;
				}
				else
				{
					auto itt = model.modelPoint.find(it->second);
					itt->second.addFacet(facetCount);
				}
				if (pointCount % 3 == 1)
				{
					cFacet._vertex_1 = point;
				}
				else if (pointCount % 3 == 2)
				{
					cFacet._vertex_2 = point;
				}
				else if (pointCount % 3 == 0)
				{
					cFacet._vertex_3 = point;
					cFacet.index = facetCount;
					// 计算方向向量
					cFacet.getNormal();
					// 计算面积
					cFacet.getS();
					// 计算体积
					cFacet.getVolume();
					model.addFacet(facetCount, cFacet);
					facetCount++;
					Facet cFacet;
				}
			}
		}
	}
	catch (const std::exception&)
	{
		cout << "打开文件错误" << endl;
	}
	cout << " 多少点：" << model.modelPoint.size() << endl;
	cout << " 多少面片：" << model.modelFacet.size() << endl;
	for (auto it = model.modelFacet.begin();it != model.modelFacet.end();it++)
	{
	    Vvolume += it->second.volume;
		Sarea += it->second.s;
	}
}
void InitConsoleWindow()
{
	AllocConsole();
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	int hCrt = _open_osfhandle((long)handle, _O_TEXT);
	FILE * hf = _fdopen(hCrt, "w");
	*stdout = *hf;
}

// stl转换成ply文档并实现另存为
void CnewTask9View::OnToPly()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog fileDlg(FALSE);
	//fileDlg.m_ofn.lpstrFilter= "TXT文件(*.txt)\0*.txt\0所有文件(*.*)\0*.*\0\0";

}
void CnewTask9View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	// TODO: 在此添加命令处理程序代码
		// TODO: 在此添加命令处理程序代码
	AllocConsole();                     // 打开控制台资源
	char ch = getchar();                // 读数据
	CString filename;
	CFileDialog opendlg(TRUE, _T("*"), _T("*.stl"), OFN_OVERWRITEPROMPT, _T("所有文件(*.*;)|*.*||"), NULL);
	int n = opendlg.DoModal();
	// 用户是否选择了文件
	if (n == IDOK)
	{
		filename = opendlg.GetPathName();
		// 文件名路径
		std::string str(CW2A(filename.GetString()));
		freopen("CONOUT$", "w+t", stdout);// 申请写
		freopen("CONIN$", "r+t", stdin);  // 申请读
		cout << "filename is " << str << endl;   // 写数据（可以输出需要的调试信息等）
		ReadStlFile(str);
	}
}

void CnewTask9View::OnModelShow()
{
	// TODO: 在此添加命令处理程序代码
	// TODO: 在此添加命令处理程序代码
	cout << "面片数 " << model.modelFacet.size() << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DOUBLE);
	glMatrixMode(GL_MODELVIEW);
	for (auto it = model.modelFacet.begin();it != model.modelFacet.end();it++)
	{
		glPushMatrix();
		glBegin(GL_TRIANGLES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(it->second._vertex_1._x / 100, it->second._vertex_1._y / 100, it->second._vertex_1._z / 100);
		glVertex3f(it->second._vertex_3._x / 100, it->second._vertex_3._y / 100, it->second._vertex_3._z / 100);
		glVertex3f(it->second._vertex_2._x / 100, it->second._vertex_2._y / 100, it->second._vertex_2._z / 100);
		glEnd(); //三角形
		glPopMatrix();
		// 画线
		glBegin(GL_LINES);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(it->second._vertex_1._x / 100, it->second._vertex_1._y / 100, it->second._vertex_1._z / 100);
		glVertex3f(it->second._vertex_3._x / 100, it->second._vertex_3._y / 100, it->second._vertex_3._z / 100);
		glEnd();


		glBegin(GL_LINES);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(it->second._vertex_1._x / 100, it->second._vertex_1._y / 100, it->second._vertex_1._z / 100);
		glVertex3f(it->second._vertex_2._x / 100, it->second._vertex_2._y / 100, it->second._vertex_2._z / 100);
		glEnd();

		glBegin(GL_LINES);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(it->second._vertex_3._x / 100, it->second._vertex_3._y / 100, it->second._vertex_3._z / 100);
		glVertex3f(it->second._vertex_2._x / 100, it->second._vertex_2._y / 100, it->second._vertex_2._z / 100);
		glEnd();
	}
	SwapBuffers(wglGetCurrentDC());
	// 交换缓冲区  
	cout << " 绘制完成" << endl;
}


void CnewTask9View::OnVolume()
{
	// TODO: 在此添加命令处理程序代码

	if (NULL == volume)
	{
		// 创建非模态对话框实例  
		volume = new Volume();
		volume->Create(IDD_DIALOG2, this);
	}
	// 若对话框已打开，则显示非模态对话框  
	volume->ShowWindow(SW_SHOW);
}


void CnewTask9View::OnArea()
{
	// TODO: 在此添加命令处理程序代码
	if (NULL == area)
	{
		// 创建非模态对话框实例  
		area = new Area();
		area->Create(IDD_DIALOG3, this);
	}
	// 若对话框已打开，则显示非模态对话框  
	area->ShowWindow(SW_SHOW);
	//area->areadata = Sarea;
	//area->DoDataExchange.SetWindowTextW();
	
}
// 体积计算函数
double GetVolume()
{
	return Vvolume;
}
// 面积计算函数
double GetArea()
{
	return Sarea;
}


void CnewTask9View::OnSArea()
{
	// TODO: 在此添加命令处理程序代码
	if (NULL == area)
	{
		// 创建非模态对话框实例  
		area = new Area();
		area->Create(IDD_DIALOG3, this);
	}
	// 若对话框已打开，则显示非模态对话框  
	area->ShowWindow(SW_SHOW);
	//area->areadata = Sarea;
	//area->DoDataExchange.SetWindowTextW();

}
