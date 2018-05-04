#include "CSSSpatialIndex.h"

CSSSpatialIndex::CSSSpatialIndex()
{
    root = 0x00;
    target = 0x00;
}

CSSSpatialIndex::~CSSSpatialIndex()
{
    if (root != 0x00)
    {
        delete root;//���ٽ��
        root = 0x00;
    }

    if (target != 0x00)
    {
        delete target;//���ٽ��
        target = 0x00;
    }
}


/// <summary>
/// �����Ĳ���
/// </summary>
/// <param name="citySet">ʡ��������ݼ�</param>
void CSSSpatialIndex::CreateQuadTree(list<CSSCity* > citySet)
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
void CSSSpatialIndex::Insert(CSSCity* city)
{
    CHPoint pos = city->geoPt;
    target = MakeNode(pos);
    target->city = city;

    if(root == 0x00)
    {
        root = new CSSSpatialIndexNode();
        root->city = city;
        root = target;
        root->LN = 0;
        root->LS = 500;
        root->LW = 0;
        root->LE = 500;
        return ;
    }

    CSSSpatialIndexNode* temp = root;
    while(temp != 0x00 && !IsEqualCoordinates(temp, target))
    {
        CSSSpatialIndexNode* quadrant = GetQuadrant(temp, target);
        if(quadrant == 0x00)
        {
            InsertPointInFinalQuadrant(temp, target);
            temp = 0x00;
            return ;
        }
        else
        {
            temp = quadrant;
        }
    }
    return ;
}


/// <summary>
/// ���ɽڵ�
/// </summary>
/// <param name="city">�����ɽڵ����Ļ����</param>
CSSSpatialIndexNode* CSSSpatialIndex::MakeNode(CHPoint pos)
{
    CSSSpatialIndexNode* temp = new CSSSpatialIndexNode();
    temp->pos = pos;
    temp->NW = 0x00;
    temp->NE = 0x00;
    temp->SE = 0x00;
    temp->SW = 0x00;
    return temp;
}


/// <summary>
/// �Ƚϵ������Ƿ����
/// </summary>
/// <param name="temp">���ڵ�</param>
/// <param name="target">Ŀ���</param>
bool CSSSpatialIndex::IsEqualCoordinates(CSSSpatialIndexNode* temp, CSSSpatialIndexNode* target)
{
    if((temp->pos.x == target->pos.x)&&(temp->pos.y == target->pos.y))
        return true;
    else
        return false;
}


/// <summary>
/// �ж�Ŀ�����������
/// </summary>
/// <param name="temp">���ڵ�</param>
/// <param name="target">Ŀ���</param>
CSSSpatialIndexNode* CSSSpatialIndex::GetQuadrant(CSSSpatialIndexNode* temp, CSSSpatialIndexNode* target)
{
    if(temp->pos.x < target->pos.x)
    {
        if(temp->pos.y < target->pos.y)
        {
            return temp->SE;
        }
        else
        {
            return temp->NE;
        }
    }

    else if(temp->pos.y < target->pos.y)
    {
        return temp->SW;
    }
    else
    {
        return temp->NW;
    }
}


/// <summary>
/// ��Ŀ��������ӦҶ�ӽڵ���
/// </summary>
/// <param name="temp">���ڵ�</param>
/// <param name="target">Ŀ���</param>
void CSSSpatialIndex::InsertPointInFinalQuadrant(CSSSpatialIndexNode* temp, CSSSpatialIndexNode* target)
{
    if(temp->pos.x < target->pos.x)
    {
        if(temp->pos.y < target->pos.y)
        {
            temp->SE = target;
            target->LN = temp->pos.y;
            target->LW = temp->pos.x;
            target->LS = temp->LS;
            target->LE = temp->LE;
        }
        else
        {
            temp->NE = target;
            target->LN = temp->LN;
            target->LW = temp->pos.x;
            target->LS = temp->pos.y;
            target->LE = temp->LE;
        }
    }

    else if(temp->pos.y < target->pos.y)
    {
        temp->SW = target;
        target->LN = temp->pos.y;
        target->LW = temp->LW;
        target->LS = temp->LS;
        target->LE = temp->pos.x;
    }
    else
    {
        temp->NW = target;
        target->LN = temp->LN;
        target->LW = temp->LW;
        target->LS = temp->pos.y;
        target->LE = temp->pos.x;
    }
}


/// <summary>
/// ����һ�����м�¼
/// </summary>
/// <param name="pt">��Ļ����</param>
/// <returns>��ѯ���м�¼</returns>
bool CSSSpatialIndex::Search(CHPoint pt,CSSCity* city)
{
    CSSSpatialIndexNode* target = MakeNode(pt);

    if(root == 0x00)
    {
        cout << "Empty Quad Tree.\n" << endl;
        return false;
    }

    if(IsEqualCoordinates(root, target))
    {
        city = root->city;
        return true;
    }

    CSSSpatialIndexNode* temp = root;
    while(temp != 0x00)
    {
        if(IsEqualCoordinates(temp, target))
        {
            city = temp->city;
            return true;
        }
        else
        {
            temp = GetQuadrant(temp, target);
        }
    }
    return false;
}


/// <summary>
/// ����ȷ���ҳ��м�¼
/// </summary>
/// <param name="pt">��Ļ����</param>
/// <param name="r">�������뾶</param>
bool CSSSpatialIndex::CheckCircle(CHPoint pt, int r)
{
    queue<CSSSpatialIndexNode*> q;
    if(q.empty())
        q.push(root);

    while(!q.empty())
    {
        CSSSpatialIndexNode* popped = q.front();
        q.pop();
        if(IsInCircle(pt, r, popped))
        {
            cityResult = popped->city;
            return true;
        }
        if(popped->NE != 0x00)
            q.push(popped->NE);
        if(popped->NW != 0x00)
            q.push(popped->NW);
        if(popped->SW != 0x00)
            q.push(popped->SW);
        if(popped->SE != 0x00)
            q.push(popped->SE);
    }
    return false;
}


/// <summary>
/// Ŀ����Ƿ����ڻ�������
/// </summary>
/// <param name="pt">��Ļ����</param>
/// <param name="r">�������뾶</param>
/// <param name="r">Ŀ���</param>
bool CSSSpatialIndex::IsInCircle(CHPoint pt, int r, CSSSpatialIndexNode* target)
{
    return(Dist(pt.x,pt.y,target->pos.x,target->pos.y)<r);
}


/// <summary>
/// �������
/// </summary>
int CSSSpatialIndex::Dist(int x1, int y1, int x2, int y2)
{
    double distx = (double)pow((x2-x1)/100,2);
    double disty = (double)pow((y2-y1)/100,2);
    double dist = sqrt(distx+disty);
    return (int)dist;
}

