/**************************************
Author:����
Date:2017/12/23
Update:2018/1/6
Description:�����࣬�洢������
***************************************/
#ifndef CHPOLYLINE_H
#define CHPOLYLINE_H

#include "CHObject.h"

class CHPolyline: public CHObject
{
public:
    CHPolyline();
    ~CHPolyline();

    vector<CHPoint > points;//��������㼯

    /* ��ӵ�����
    pt:����ӵ����� */
    void AddPoint(CHPoint pt);

    /* ���߻���
    f0:Ŀ�������Ϣ
    maxx,maxy,minx,miny:��ͼ����MBR */
    void Draw(f f0,int maxx,int maxy,int minx,int miny);
};

#endif // CHPOLYLINE_H
