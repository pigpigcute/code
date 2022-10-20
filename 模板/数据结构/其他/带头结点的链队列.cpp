#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;
typedef bool Status;

typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
} LinkNode;

typedef struct
{
    LinkNode *front, *rear; //ͷβָ��
    // int Maxsize;//�����ö��г���
} LinkQueue;

/* 1.��ʼ�������� */
void InitQueue(LinkQueue *Q)
{
    //��ʼʱ��front��rear��ָ��ͷ���
    Q->front = Q->rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q->front->next = NULL;
}

/* 2.�ж϶����Ƿ�Ϊ�� */
Status IsEmpty(LinkQueue *Q)
{
    if (Q->front == Q->rear)
        return true;
    else
        return false;
}

/* 3.��� */
Status InsertQueue(LinkQueue *Q, ElemType X)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    /*���Ǹ���ģ�
     if(s==NULL)
        return false; */
    s->data = X;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
    return true;
}

/* 4.���ӣ���� */
Status DeleteQueue(LinkQueue *Q)
{
    ElemType X;
    if (IsEmpty(Q))
        return false;
    LinkNode *p = Q->front->next;
    X = p->data;
    cout << X << endl;
    Q->front->next = p->next;
    if (Q->rear == p) //��ʾ��ʱ�ͷŵ�������Ԫ�أ�
        Q->rear = Q->front;
    free(p);
    return true;
}

int main()
{
    LinkQueue *Q;
    ElemType x = -1;
   /*  ����ʵ��
    InitQueue(Q);
    InsertQueue(Q, 3);
	InsertQueue(Q, 6);
    DeleteQueue(Q);
    DeleteQueue(Q);
	InsertQueue(Q, 8);
	InsertQueue(Q, 9);
    DeleteQueue(Q);
	InsertQueue(Q, 7);
	InsertQueue(Q, 5);
    DeleteQueue(Q);
    DeleteQueue(Q);
    DeleteQueue(Q); */
    
    if(IsEmpty(Q))
        cout<<"��"<<endl;
    else
        cout<<"�ǿ�"<<endl;
}