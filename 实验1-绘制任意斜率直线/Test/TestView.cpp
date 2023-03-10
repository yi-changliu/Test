
// TestView.cpp : CTestView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Test.h"
#endif

#include "TestDoc.h"
#include "TestView.h"
#include "math.h"//包含数学头文件
#define  PI 3.1415926//PI的宏定义
#define Round(d) int(floor(d+0.5))//四舍五入宏定义

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestView

IMPLEMENT_DYNCREATE(CTestView, CView)

BEGIN_MESSAGE_MAP(CTestView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_DRAWPIC, &CTestView::OnDrawpic)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CTestView 构造/析构

CTestView::CTestView()
{
	// TODO: 在此处添加构造代码

}

CTestView::~CTestView()
{
}

BOOL CTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CTestView 绘制

void CTestView::OnDraw(CDC* /*pDC*/)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	GetClientRect(&rect);//获得客户区矩形的大小
}


// CTestView 打印

BOOL CTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CTestView 诊断

#ifdef _DEBUG
void CTestView::AssertValid() const
{
	CView::AssertValid();
}

void CTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestDoc* CTestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDoc)));
	return (CTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestView 消息处理程序


void CTestView::OnDrawpic() 
{
	// TODO: Add your command handler code here
	MessageBox(CString("请按下鼠标左键绘图！"),CString("提示"),MB_ICONEXCLAMATION|MB_OK);
	RedrawWindow();
}

void CTestView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	p0.x=point.x;
	p0.y=point.y;
	p0.x=p0.x-rect.Width()/2;                           //设备坐标系向自定义坐标系转换
	p0.y=rect.Height()/2-p0.y;
	CView::OnLButtonDown(nFlags, point);
}


void CTestView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	p1.x=point.x;
	p1.y=point.y;
	CLine *line=new CLine;
	CDC *pDC=GetDC();                                   //定义设备上下文指针
	pDC->SetMapMode(MM_ANISOTROPIC);                    //自定义坐标系
	pDC->SetWindowExt(rect.Width(),rect.Height());      //设置窗口比例
	pDC->SetViewportExt(rect.Width(),-rect.Height());   //设置视区比例，且x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);//设置客户区中心为坐标系原点
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);  //矩形与客户区重合	
	p1.x=p1.x-rect.Width()/2;
	p1.y=rect.Height()/2-p1.y;
	line->MoveTo(pDC,p0);
	line->LineTo(pDC,p1);
	delete line;
	ReleaseDC(pDC);
	CView::OnLButtonUp(nFlags, point);
}
