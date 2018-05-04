#include "CHPolyline.h"

CHPolyline::CHPolyline()
{

}

CHPolyline::~CHPolyline()
{

}


/// <summary>
/// ��ӵ�����
/// </summary>
/// <param name="layer">����ӵ�����</returns>
void CHPolyline::AddPoint(CHPoint pt)
{
    points.push_back(pt);
}


/// <summary>
/// ���߻���
/// </summary>
/// <param name="f0">Ŀ�������Ϣ</returns>
/// <param name="maxx,maxy,minx,miny">��ͼ����MBR</returns>
void CHPolyline::Draw(f f0,int maxx,int maxy,int minx,int miny)
{
    if(f0.line == 1)
    {
        GLfloat r = ((float)f0.color1.r)/255;
        GLfloat g = ((float)f0.color1.g)/255;
        GLfloat b = ((float)f0.color1.b)/255;
        glColor3f(r,g,b);
        glLineWidth(f0.width);
        glBegin(GL_LINE_STRIP);
        for(int m = 0; m < points.size(); m++)
        {
            CHPoint point = points.at(m);
            int width = maxx - minx;
            int height = maxy - miny;
            float x = (float)(point.x - minx)/width * 2 - 1;
            float y = (float)(point.y - miny)/height * 2 - 1;
            glVertex2f(x,y);
        }
        glEnd();
    }
}
