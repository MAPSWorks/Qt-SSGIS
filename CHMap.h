/**************************************
Author:����
Date:2017/12/23
Update:2018/1/6
Description:��ͼ�࣬װ��ͼ����
***************************************/
#ifndef CHMAP_H
#define CHMAP_H

#include "CHLayer.h"

class CHMap
{
public:
    CHMap();
    ~CHMap();

    int maxx,maxy,minx,miny;//MBR
    int n;//����
    vector<f>fills;//������Ϣ
    vector<CHLayer* > layers;//ͼ�㼯

    /* ���ͼ��
    layer:�����ͼ�� */
    void AddLayer(CHLayer* layer);

    /* ��ͼ����
    maxx,maxy,minx,miny:��ͼ����MBR */
    void Draw(int maxx,int maxy,int minx,int miny);
};

#endif // CHMAP_H
