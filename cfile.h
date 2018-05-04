/**************************************
Author:��������?
Date:2017/12/23
Update:2018/1/6
Description:����Դ��
***************************************/
#ifndef CFILE_H
#define CFILE_H
#define CONVERT(start, end, code, letter) if(code >= start && code <= end) return letter

#include "CHMap.h"
#include "CSSCity.h"
#include "CHPolyline.h"
#include "CHPolygon.h"
#include "CSSNameIndex.h"
#include "CSSSpatialIndex.h"
#include <fstream>
#include <list>

class CFile
{
public:
    CFile(const char* readFilePath1,const char* readFilePath2,
          const char* readFilePath3);
    ~CFile();

    CHMap *map;//ͼ�λ�������
    list<CSSCity* >citySet;//ʡ��������ݼ�
    string strPinyin;//�û�����ĳ���ƴ������ĸ

    /* ��ȡͼ�λ����ļ� */
    void FileOpenDat();

    /* ��ȡ������Ϣ�ļ� */
    void FileOpenOpt();

    /* ��ȡʡ��������ݼ� */
    void GetCitySet();

    /* ��ȡ�������ִʵ�ƴ������ĸ��д
    name:��ת���������� */
    string  GetFirstLetters(string name);

private:
    const char* readFilePath1;//ͼ�λ����ļ�·��
    const char* readFilePath2;//������Ϣ�ļ�·��
    const char* readFilePath3;//ʡ������ļ�·��

    /* ��ȡʡ������ļ� */
    void ReadTxtFile();

    /* ���ַ���ת��Ϊ������¼
    str:��ת���ַ���
    size:�ַ�������*/
    void StringToRecord(CSSCity* city,string str,int size);

    /* ��ʡ��������ݼ����û�����ĳ�����ת��Ϊ����ƴ������ĸ��д */
    void GetPinYin();

};

#endif // CFILE_H
