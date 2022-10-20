/*ʵ�ִ�ͷ������ʽ����*/
#include<bits/stdc++.h>
using namespace std;

typedef int ElemType;
typedef bool Status;

/*0.������ʽ���еĻ����ṹ*/
typedef struct LinkNode { //��ʽ���н��
	ElemType data;
	struct LinkNode* next;
}LinkNode;

typedef struct { //��ʽ����
	LinkNode* front, * rear; //���еĶ�ͷ�Ͷ�βָ��
}LinkQueue;

/*1.��ʼ����ʽ����*/
void InitQueue(LinkQueue& Q)
{//����ʱ��front��rear��ָ��ͷ���
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}
/*2.�ж϶�����Ϊ��*/
Status IsEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
/*3.���*/
Status EnQueue(LinkQueue& Q, ElemType x)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL)
		return false;
	s->data = x;
	s->next = NULL;
	Q.rear->next = s; //�½����뵽rear֮��
	Q.rear = s; //�޸ı�βָ��
	return true;
}

/*4.����*/
Status DeQueue(LinkQueue& Q, ElemType& x)
{
	if (Q.front == Q.rear)
		return false; //�ն�
	LinkNode* p = Q.front->next;
	x = p->data; //�ñ���x���ض�ͷԪ��
	Q.front->next = p->next; //�޸�ͷ����nextָ��
	if (Q.rear == p) //�˴������һ��������
		Q.rear = Q.front; //�޸� rear ָ��
	free(p); //�ͷŽ��ռ�
	return true;
}

int main()
{
	LinkQueue Q;
	/* �������ʵ��
    ElemType x = -1;
	InitQueue(Q);
	EnQueue(Q, 3);
	EnQueue(Q, 6);
	EnQueue(Q, 8);
	EnQueue(Q, 9);
	EnQueue(Q, 7);
	EnQueue(Q, 5);
	for (int i = 1; i < 7; i++)
	{
		DeQueue(Q, x);
        cout<<x<<endl;
	}
	if (IsEmpty(Q))
	{
		cout<<"����Ϊ��"<<endl;
	}
	else
	{
		cout<<"���зǿ�"<<endl;
	}
 */
	return 0;
}
