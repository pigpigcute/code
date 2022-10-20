#include<iostream>
using namespace std;

#define MAXSIZE 20//������Ҫ�������Ա�Χ
#define ERROR -1
typedef int ElementType;//������Ϣ
typedef int Position;//λ����Ϣ
typedef struct LNode *List;
struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List MakeEmpty();//����һ���յ����Ա�
Position Find(List L, ElementType X);//����X��λ�ã�û���򷵻�ERROR
bool Insert(List L, ElementType X, Position P);//���룬��λ�ô��������������������false����ȷ�����򷵻�true
bool Delete(List L, Position P);//ɾ������λ�ô��󣬷���false����ȷɾ���򷵻�true

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;
    L = MakeEmpty();
    
    return 0;
}


List MakeEmpty() //����һ���յ����Ա�
{
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}

Position Find(List L, ElementType X) //����X��λ�ã�û���򷵻�ERROR
{
    for (int i = 0; i <= L->Last; i++)
    {
        if (L->Data[i] == X)
            return i;
    }
    return ERROR;
}

bool Insert(List L, ElementType X, Position P) //����
{
    if (L->Last == MAXSIZE - 1)
    {
        return false;
    }
    else if (P < 0 || P > L->Last+1)
    {
        return false;
    }

    for (int i = L->Last; i >= P; i--)
    {
        L->Data[i + 1] = L->Data[i];
    }
    L->Data[P] = X;
    L->Last++;
    return true;
}

bool Delete(List L, Position P) //ɾ��
{
    if (P < 0 || P > L->Last)
    {
        return false;
    }

    for (int i = P; i <= L->Last; i++)
    {
        L->Data[i] = L->Data[i + 1];
    }
    L->Last--;
    return true;
}