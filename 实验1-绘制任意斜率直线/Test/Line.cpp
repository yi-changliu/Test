// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Line.h"
#include "math.h"
#define Round(d) int(floor(d+0.5))//四舍五入宏定义
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLine::CLine()
{ 

}

CLine::~CLine()
{
	
}

void CLine::MoveTo(CDC *pDC,CP2 p0)//绘制直线起点函数
{	
	P0=p0;
}

void CLine::MoveTo(CDC *pDC,double x0,double y0)//重载函数
{	
	P0=CP2(x0,y0);
}

void CLine::LineTo(CDC *pDC,CP2 p1)//绘制直线，不含终点
{
	P1=p1;
	CP2 p,t;
	CRGB clr=CRGB(0.0,0.0,0.0);//黑色像素点
	
	//绘制各个斜率的直线。该部分由同学完成


	P0=p1;
}
void CLine::LineTo(CDC *pDC,double x1,double y1)//重载函数
{
	LineTo(pDC,CP2(x1,y1));
}