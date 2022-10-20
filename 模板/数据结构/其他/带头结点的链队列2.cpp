/*实现带头结点的链式队列*/
#include<bits/stdc++.h>
using namespace std;

typedef int ElemType;
typedef bool Status;

/*0.定义链式队列的基本结构*/
typedef struct LinkNode { //链式队列结点
	ElemType data;
	struct LinkNode* next;
}LinkNode;

typedef struct { //链式队列
	LinkNode* front, * rear; //队列的队头和队尾指针
}LinkQueue;

/*1.初始化链式队列*/
void InitQueue(LinkQueue& Q)
{//初试时，front、rear都指向头结点
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}
/*2.判断队列是为空*/
Status IsEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
/*3.入队*/
Status EnQueue(LinkQueue& Q, ElemType x)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL)
		return false;
	s->data = x;
	s->next = NULL;
	Q.rear->next = s; //新结点插入到rear之后
	Q.rear = s; //修改表尾指针
	return true;
}

/*4.出队*/
Status DeQueue(LinkQueue& Q, ElemType& x)
{
	if (Q.front == Q.rear)
		return false; //空队
	LinkNode* p = Q.front->next;
	x = p->data; //用变量x返回队头元素
	Q.front->next = p->next; //修改头结点的next指针
	if (Q.rear == p) //此次是最后一个结点出队
		Q.rear = Q.front; //修改 rear 指针
	free(p); //释放结点空间
	return true;
}

int main()
{
	LinkQueue Q;
	/* 输入输出实例
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
		cout<<"队列为空"<<endl;
	}
	else
	{
		cout<<"队列非空"<<endl;
	}
 */
	return 0;
}
