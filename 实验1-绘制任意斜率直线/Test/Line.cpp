// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Line.h"
#include "math.h"
#define Round(d) int(floor(d+0.5))//��������궨��
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

void CLine::MoveTo(CDC *pDC,CP2 p0)//����ֱ����㺯��
{	
	P0=p0;
}

void CLine::MoveTo(CDC *pDC,double x0,double y0)//���غ���
{	
	P0=CP2(x0,y0);
}

void CLine::LineTo(CDC *pDC,CP2 p1)//����ֱ�ߣ������յ�
{
	P1=p1;
	CP2 p,t;
	CRGB clr=CRGB(0.0,0.0,0.0);//��ɫ���ص�
	
	//���Ƹ���б�ʵ�ֱ�ߡ��ò�����ͬѧ���


	P0=p1;
}
void CLine::LineTo(CDC *pDC,double x1,double y1)//���غ���
{
	LineTo(pDC,CP2(x1,y1));
}