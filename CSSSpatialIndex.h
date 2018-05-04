/**************************************
Author:��?
Date:2017/12/20
Update:2018/1/3
Description:�ռ������࣬�����Ĳ�����QuadTree��ʵ��ͼ�����ԵĲ�ѯ
***************************************/
#ifndef CSSSPATIALINDEX_H
#define CSSSPATIALINDEX_H

#include "CSSIndex.h"
#include "CSSSpatialIndexNode.h"
#include <queue>

class CSSSpatialIndex: public CSSIndex
{
public:
    CSSSpatialIndex();
    ~CSSSpatialIndex();

    /* �����Ĳ���
    citySet:ʡ��������ݼ� */
    void CreateQuadTree(list<CSSCity* > citySet);

    /* ����һ�����м�¼
    pt:��Ļ���� */
    bool Search(CHPoint pt,CSSCity* city);

    /* ����ȷ����һ�����м�¼
    pt:��Ļ����
    r:�������뾶 */
    bool CheckCircle(CHPoint pt, int r);

    CSSCity* cityResult;

private:
    CSSSpatialIndexNode* root;//���ڵ�
    CSSSpatialIndexNode* target;//Ŀ���

    /* ����
    city:���������ָ�� */
    void Insert(CSSCity* city);

    /* ���ɽڵ�
    pos:������ڵ���Ļ���� */
    CSSSpatialIndexNode* MakeNode(CHPoint pos);

    /* �Ƚϵ������Ƿ����
    temp:���ڵ�
    target:Ŀ��� */
    bool IsEqualCoordinates(CSSSpatialIndexNode* temp, CSSSpatialIndexNode* target);

    /* �ж�Ŀ�����������
    temp:���ڵ�
    target:Ŀ��� */
    CSSSpatialIndexNode* GetQuadrant(CSSSpatialIndexNode* temp, CSSSpatialIndexNode* target);

    /* ��Ŀ��������ӦҶ�ӽڵ���
    temp:���ڵ�
    target:Ŀ��� */
    void InsertPointInFinalQuadrant(CSSSpatialIndexNode* temp, CSSSpatialIndexNode* target);

    /* Ŀ����Ƿ����ڻ�������
    pt:��Ļ����
    r:�������뾶
    target:Ŀ��� */
    bool IsInCircle(CHPoint pt, int r, CSSSpatialIndexNode* target);

    /* ������� */
    int Dist(int x1, int y1, int x2, int y2);

};

#endif // CSSSPATIALINDEX_H
