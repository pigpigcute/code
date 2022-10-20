#include <bits/stdc++.h>
using namespace std;

#define ERROR -1
typedef struct Qnode
{
    int *data;
    int front, rear;
    int Maxsize;
} Queue;

Queue *createqueue(int Maxsize); //���д���
bool isfull(Queue *Q);           //�ж϶����Ƿ����� (������һ��λ�õķ�ʽ��������)
bool isempty(Queue *Q);          //�ж��Ƿ�Ϊ��
bool addQ(Queue *Q);             //�������
int deleteQ(Queue *Q);           //ɾ�������ض���ͷԪ�أ�����Ϊ�շ���ERROR

int main()//������
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
        cout << "������" << endl;
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
        cout << "���п�" << endl;
        return ERROR;
    }
    else
    {
        Q->front = (Q->front + 1) % Q->Maxsize;
        return Q->data[Q->front];
    }
}