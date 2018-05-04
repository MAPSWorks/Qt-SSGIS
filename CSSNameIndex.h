/**************************************
Author:��?
Date:2017/12/19
Update:2018/1/3
Description:ר�������࣬�����ֵ�����Trie��ʵ�����Ե�ͼ�Ĳ�ѯ
***************************************/
#ifndef CSSNAMEINDEX_H
#define CSSNAMEINDEX_H

#include "CSSIndex.h"
#include "CSSNameIndexNode.h"

class CSSNameIndex: public CSSIndex
{
public:
    CSSNameIndex();
    ~CSSNameIndex();

    CSSCity* cityResult;//�������

    /* �����ֵ���
    citySet:ʡ��������ݼ�*/
    void CreateTrie(list<CSSCity* > citySet);

    /* ר���ѯ
    str:����ƴ������ĸ*/
    bool Search(const char* str);

private: 
    CSSNameIndexNode* pRoot;//���ڵ�

    /* ����
    city:���������ָ��*/
    void Insert(CSSCity* city);

    /* ����
    pRoot:���ڵ�*/
    void Destory(CSSNameIndexNode* pRoot);
};

#endif // CSSNAMEINDEX_H
