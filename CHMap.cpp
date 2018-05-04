#include "CHMap.h"

CHMap::CHMap()
{

}


CHMap::~CHMap()
{
    //������Ա����layers
    for(vector<CHLayer* >::iterator iter = layers.begin();iter != layers.end();iter++)
    {
        if((*iter) != 0x00)
        {
            delete *iter;
            *iter = 0x00;
        }
    }
    layers.clear();
}


/// <summary>
/// ���ͼ��
/// </summary>
/// <param name="layer">�����ͼ��</returns>
void CHMap::AddLayer(CHLayer* layer)
{
    layers.push_back(layer);
}


/// <summary>
/// ��ͼ����
/// </summary>
/// <param name="maxx,maxy,minx,miny">��ͼ����MBR</returns>
void CHMap::Draw(int maxx,int maxy,int minx,int miny)
{
    for(int i = 0; i < n; i++)
    {
        f f0;
        CHLayer *layer = layers.at(i);
        string name0 = layer->name;
        for(int j = 0; j < fills.size(); j++)
        {
            f0 = fills.at(j);
            if(f0.name == name0)
                break;
        }
        layer->Draw(f0,maxx,maxy,minx,miny);
    }
}

