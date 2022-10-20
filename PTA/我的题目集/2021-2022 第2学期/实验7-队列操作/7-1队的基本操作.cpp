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
bool addQ(Queue *Q, int X);      //加入队列
bool deleteQ(Queue *Q);          //删除并返回队列头元素，队列为空返回ERROR

int m;

int main()
{
    Queue *Q;
    Q = createqueue(10);
    int t, n, a[100010], i = 0;
    static int g[100010];
    bool llog, P;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n == 0)
        {
            P = deleteQ(Q);
            if (P)
            {
                a[i] = m;
                i++;
            }
            else if (g[i - 1] != -1)
            {
                g[i] = -1;
                i++;
            }
        }
        else
        {
            llog = addQ(Q, n);
            if (!llog && g[i - 1] != -2)
            {
                g[i] = -2;
                i++;
            }
        }
    }
    for (int j = 0; j < i; j++)
    {
        if (g[j] == -1)
            cout << "EMPTY ";
        else if (g[j] == -2)
            cout << "FULL ";
        else
            cout << a[j] << " ";
    }
    cout << endl;
    while (!isempty(Q))
    {
        P = deleteQ(Q);
        cout << m << " ";
    }
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
        return false;
    }
    else
    {
        Q->rear = (Q->rear + 1) % Q->Maxsize;
        Q->data[Q->rear] = X;
        return true;
    }
}

bool deleteQ(Queue *Q)
{
    if (isempty(Q))
    {
        return false;
    }
    else
    {
        Q->front = (Q->front + 1) % Q->Maxsize;
        m = Q->data[Q->front];
        return true;
    }
}