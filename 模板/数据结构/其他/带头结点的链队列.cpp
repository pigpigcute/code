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
    LinkNode *front, *rear; //头尾指针
    // int Maxsize;//可设置队列长度
} LinkQueue;

/* 1.初始化链队列 */
void InitQueue(LinkQueue *Q)
{
    //初始时，front与rear都指向头结点
    Q->front = Q->rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q->front->next = NULL;
}

/* 2.判断队列是否为空 */
Status IsEmpty(LinkQueue *Q)
{
    if (Q->front == Q->rear)
        return true;
    else
        return false;
}

/* 3.入队 */
Status InsertQueue(LinkQueue *Q, ElemType X)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    /*这是干嘛的？
     if(s==NULL)
        return false; */
    s->data = X;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
    return true;
}

/* 4.出队，输出 */
Status DeleteQueue(LinkQueue *Q)
{
    ElemType X;
    if (IsEmpty(Q))
        return false;
    LinkNode *p = Q->front->next;
    X = p->data;
    cout << X << endl;
    Q->front->next = p->next;
    if (Q->rear == p) //表示此时释放的是最后的元素；
        Q->rear = Q->front;
    free(p);
    return true;
}

int main()
{
    LinkQueue *Q;
    ElemType x = -1;
   /*  运行实例
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
        cout<<"空"<<endl;
    else
        cout<<"非空"<<endl;
}