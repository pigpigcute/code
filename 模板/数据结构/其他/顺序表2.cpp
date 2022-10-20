#include <iostream>
#include <stdlib.h>
#define ElemType int
#define MaxSize 100
using namespace std;
typedef struct
{ //˳���ṹ��
    ElemType data[MaxSize];
    int length;
} SqList;
void InitList(SqList &L)
{ //��ʼ�����Ա�
    for (int i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0;
    }
    L.length = 0;
}
void DisplayList(SqList L)
{ //���˳����е�����
    cout << "˳����е������У�" << endl;
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
    cout << endl;
}
void ListInsert(SqList &L, ElemType e, int i)
{ //����һ�����ݵ�L��
    if (i < 0 || i > L.length + 1)
    {
        cout << "λ�ò��Ϸ�����" << endl;
        return;
    } //�ж�λ���Ƿ�Ϸ�
    for (int j = L.length - 1; j >= i - 1; j--)
    {
        L.data[j + 1] = L.data[j];
    }                  //Ԫ�غ���
    L.data[i - 1] = e; //��������
    L.length++;        //���ȼ�һ
}
void ListDelete(SqList &L, int i)
{ //ɾ��L�е�i������
    if (i < 0 || i > L.length + 1)
    {
        cout << "λ�ò��Ϸ�����" << endl;
        return;
    } //�ж�λ���Ƿ�Ϸ�
    for (int j = i - 1; j < L.length; j++)
    {
        L.data[j] = L.data[j + 1];
    }           //Ԫ��ǰ��
    L.length--; //���ȼ�һ
}
void ListEmpty(SqList L)
{ //�ж��Ƿ��ǿձ�
    int flag = 1;
    if (!L.length)
        flag = 0;
    if (flag)
        cout << "�ⲻ��һ���ձ�" << endl;
    else
        cout << "����һ���ձ�" << endl;
}
void GetElem(SqList L, int i, ElemType &e)
{ //�õ�˳����i��ֵ
    e = L.data[i - 1];
}
int LocateElem(SqList L, ElemType e)
{ //��Ԫ�ز���ĳֵ,��������򷵻���ţ��������򷵻�0
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            return i + 1;
    }
    return 0;
}
int ListLength(SqList L)
{ //�������Ա�ĳ���
    return L.length;
}
void DestroyList(SqList L)
{ //����˳���
    SqList *p = &L;
    free(p);
}
int main()
{
    SqList sl;
    ElemType e;
    InitList(sl); //��ʼ�����Ա�
    int a[1000], n, i;
    cout << "��������Ҫ������˳����ȣ�" << endl;
    cin >> n;
    cout << "��������Ҫ������˳������ݣ�" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; //��������
        ListInsert(sl, a[i], i + 1);
    }
    DisplayList(sl); //������ʾ
    cout << "��������Ҫ���������:";
    cin >> e;
    cout << "��������Ҫ�����λ��:";
    cin >> i;
    ListInsert(sl, e, i);
    DisplayList(sl);
    cout << "��������Ҫ��ѯ���ݵ�λ��:";
    cin >> i;
    GetElem(sl, i, e);
    cout << e << endl; // GetElem()������ʹ��
    cout << "��������Ҫ��ѯ������(�����������Ӧ��ţ����������0)��";
    cin >> i;
    cout << LocateElem(sl, i) << endl; //��ѯ����
    // DestroyList(sl);
    cout << "��������Ҫɾ�����ݵ�λ��:";
    cin >> i;
    ListDelete(sl, i);
    DisplayList(sl); //ɾ�����ݲ���ʾ
    return 0;
}
