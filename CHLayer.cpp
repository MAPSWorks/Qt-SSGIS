#include "CHLayer.h"

CHLayer::CHLayer()
{

}

CHLayer::~CHLayer()
{
    //������Ա����objects
    for(vector<CHObject* >::iterator iter = objects.begin();iter != objects.end();iter++)
    {
        if((*iter) != 0x00)
        {
            delete *iter;
            *iter = 0x00;
        }
    }
    objects.clear();
}


/// <summary>
/// ���Ŀ��
/// </summary>
/// <param name="obj">�����Ŀ��</returns>
void CHLayer::AddObject(CHObject* obj)
{
    objects.push_back(obj);
}


/// <summary>
/// ͼ�����
/// </summary>
/// <param name="f0">ͼ�������Ϣ</returns>
/// <param name="maxx,maxy,minx,miny">��ͼ����MBR</returns>
void CHLayer::Draw(f f0,int maxx,int maxy,int minx,int miny)
{
    for(unsigned int i = 0;i < objects.size(); i++)
    {
         CHObject* obj = objects.at(i);
         obj->Draw(f0,maxx,maxy,minx,miny);
    }
}




