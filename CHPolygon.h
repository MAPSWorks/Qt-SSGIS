/**************************************
Author:����
Date:2017/12/23
Update:2018/1/6
Description:�����࣬�洢������
***************************************/
#ifndef CHPOLYGON_H
#define CHPOLYGON_H

#include "CHObject.h"

class CHPolygon: public CHObject
{
public:
    CHPolygon();
    ~CHPolygon();

    vector<CHPoint > points;//���������㼯

    /* ��ӵ�����
    pt:����ӵ����� */
    void AddPoint(CHPoint pt);

    /* ����λ���
    f0:Ŀ�������Ϣ
    maxx,maxy,minx,miny:��ͼ����MBR */
    void Draw(f f0,int maxx,int maxy,int minx,int miny);
};

#endif // CHPOLYGON_H
