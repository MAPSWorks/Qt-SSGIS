#include "CSSNameIndex.h"

CSSNameIndex::CSSNameIndex()
{
    pRoot = new CSSNameIndexNode();//ע���ֵ����ĸ�������ַ�
}


CSSNameIndex::~CSSNameIndex()
{
    Destory(pRoot);
}


/// <summary>
/// �����ֵ���
/// </summary>
/// <param name="citySet">ʡ��������ݼ�</param>
void CSSNameIndex::CreateTrie(list<CSSCity* > citySet)
{
    CSSCity* city;
    for(list<CSSCity* >::iterator iter = citySet.begin(); iter != citySet.end();iter++)
    {
        city = (*iter);
        Insert(city);
    }
}


/// <summary>
/// ����һ�����м�¼
/// </summary>
/// <param name="city">��������м�¼</param>
void CSSNameIndex::Insert(CSSCity* city)
{
    string pinyin = city->pinyin;
    transform(pinyin.begin(),pinyin.end(),pinyin.begin(),tolower);//��д��Сд
    const char* str = pinyin.c_str();

    int index;
    CSSNameIndexNode* pLoc = pRoot;
    for (int i = 0;str[i];i++)
    {
        index = str[i] - 'a';//������ִ�Сд��������չ

        if(index < 0 || index > MaxBranchNum)//��ִ�в���
        {
            cout << "Fail to identify a word.\n";
            exit(0);
        }

        if (0x00 == pLoc->nextBranch[index])//�õ��ʵ�ǰ׺�����ڣ�Ҫ���ɸý��
        {
            pLoc->nextBranch[index] = new CSSNameIndexNode();
        }
        pLoc = pLoc->nextBranch[index];
    }
    if (0x00 != pLoc->word)//�����Ѿ����ֹ�
    {
        exit(0);
    }
    else    //����û�г��ֹ���Ӧ�ò��뵥��
    {
        pLoc->word = new char[strlen(str) + 1];
        strcpy(pLoc->word,str);
        pLoc->city = city;
    }
}


/// <summary>
/// ����һ�����м�¼
/// </summary>
/// <param name="str">����ѯ������</param>
/// <returns>������Ļ����</returns>
bool CSSNameIndex::Search(const char* str)
{
    int index = -1;;
    CSSNameIndexNode* pLoc = pRoot;
    while(pLoc && *str)
    {
        index = *str - 'a';//������ִ�Сд��������չ

        if(index < 0 || index > MaxBranchNum)//����һ�����ʣ���ִ�в���
        {
            cout << "Fail to identify a word.\n";
            exit(0);
        }

        pLoc = pLoc->nextBranch[index];
        str++;
    }
    if (pLoc && pLoc->word)//�����������ҵ��õ���
    {
        cityResult = pLoc->city;
        return true;
    }
    else
    {
        cout << "Cannot find this city.\n";
        return false;
    }
}


/// <summary>
/// ����Trie��
/// </summary>���ڵ�</param>
void CSSNameIndex::Destory(CSSNameIndexNode* pRoot)
{
    if (0x00 == pRoot)
    {
        return;
    }
    for (int i = 0;i < MaxBranchNum;i++)
    {
        Destory(pRoot->nextBranch[i]);
    }
    if(pRoot->word != 0x00)
    {
        delete[] pRoot->word;
        pRoot->word = 0x00;
    }
    delete pRoot;//���ٽ��
    pRoot = 0x00;
}
