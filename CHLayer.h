/**************************************
Author:����
Date:2017/12/23
Update:2018/1/6
Description:ͼ���࣬װ�ض�����
***************************************/
#ifndef CHLAYER_H
#define CHLAYER_H

#include "CHObject.h"

class CHLayer
{
public:
    CHLayer();
    ~CHLayer();

    string name;//����
    vector<CHObject* > objects;//����Ŀ�꼯

    /* ���Ŀ��
    layer:�����Ŀ�� */
    void AddObject(CHObject* obj);

    /* ͼ�����
    f0:ͼ�������Ϣ
    maxx,maxy,minx,miny:��ͼ����MBR */
    void Draw(f f0,int maxx,int maxy,int minx,int miny);

};

#endif // CHLAYER_H
