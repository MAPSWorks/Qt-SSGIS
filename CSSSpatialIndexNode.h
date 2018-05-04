/**************************************
Author:��?
Date:2017/12/20
Update:2018/1/3
Description:�Ĳ��������
***************************************/
#ifndef CSSSPATIALINDEXNODE_H
#define CSSSPATIALINDEXNODE_H

#include "CSSCity.h"

class CSSSpatialIndexNode
{
public:
    CSSSpatialIndexNode();
    ~CSSSpatialIndexNode();

    CHPoint pos;//�ڵ��������
    CSSCity* city;//��Ӧ�ĳ�����Ϣָ��

    /* ָ���ĸ����޵�ָ�� */
    CSSSpatialIndexNode* NW;
    CSSSpatialIndexNode* NE;
    CSSSpatialIndexNode* SE;
    CSSSpatialIndexNode* SW;

    int LN;
    int LS;
    int LE;
    int LW;
};

#endif // CSSSPATIALINDEXNODE_H
