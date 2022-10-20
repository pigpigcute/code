#include <bits/stdc++.h>
using namespace std;

#define ERROR -1
typedef struct Qnode
{
    int *data;
    int front, rear;
    int Maxsize;
} Queue;

Queue *createqueue(int Maxsize); //队列创建
bool isfull(Queue *Q);           //判断队列是否满了 (以牺牲一个位置的方式储存数据)
bool isempty(Queue *Q);          //判断是否为空
bool addQ(Queue *Q);             //加入队列
int deleteQ(Queue *Q);           //删除并返回队列头元素，队列为空返回ERROR

int main()//主函数
{
    return 0;
}

Queue *createqueue(int Maxsize)
{
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    Q->data = (int *)malloc(Maxsize * sizeof(int));
    Q->front = Q->rear = 0;
    Q->Maxsize = Maxsize;
    return Q;
}

bool isfull(Queue *Q)
{
    return ((Q->rear + 1) % Q->Maxsize == Q->front);
}

bool isempty(Queue *Q)
{
    return ((Q->front == Q->rear));
}

bool addQ(Queue *Q, int X)
{
    if (isfull(Q))
    {
        cout << "队列满" << endl;
        return false;
    }
    else
    {
        Q->rear = (Q->rear + 1) % Q->Maxsize;
        Q->data[Q->rear] = X;
        return true;
    }
}

int deleteQ(Queue *Q)
{
    if (isempty(Q))
    {
        cout << "队列空" << endl;
        return ERROR;
    }
    else
    {
        Q->front = (Q->front + 1) % Q->Maxsize;
        return Q->data[Q->front];
    }
}