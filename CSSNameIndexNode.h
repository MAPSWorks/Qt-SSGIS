/**************************************
Author:��?
Date:2017/12/19
Update:2018/1/3
Description:�ֵ��������
***************************************/
#ifndef CSSNAMEINDEXNODE_H
#define CSSNAMEINDEXNODE_H

#include "CSSCity.h"

const int MaxBranchNum = 26;//����26����ĸ��������ִ�Сд��������չ��52

class CSSNameIndexNode
{
public:
    CSSNameIndexNode();
    ~CSSNameIndexNode();

    char* word; //�ڵ��ʾ�ĳ���ƴ������ĸ�����ʣ�
    CSSCity* city;//��Ӧ�ĳ�����Ϣָ��
    CSSNameIndexNode* nextBranch[MaxBranchNum];//ָ��26���ַ��ڵ��ָ��
};

#endif // CSSNAMEINDEXNODE_H
