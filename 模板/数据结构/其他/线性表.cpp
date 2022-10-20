#include<iostream>
using namespace std;

#define MAXSIZE 20//根据需要调整线性表范围
#define ERROR -1
typedef int ElementType;//数据信息
typedef int Position;//位置信息
typedef struct LNode *List;
struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List MakeEmpty();//创建一个空的线性表
Position Find(List L, ElementType X);//返回X的位置，没有则返回ERROR
bool Insert(List L, ElementType X, Position P);//插入，若位置错误或者数据已满，返回false，正确插入则返回true
bool Delete(List L, Position P);//删除，若位置错误，返回false，正确删除则返回true

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;
    L = MakeEmpty();
    
    return 0;
}


List MakeEmpty() //创建一个空的线性表
{
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}

Position Find(List L, ElementType X) //返回X的位置，没有则返回ERROR
{
    for (int i = 0; i <= L->Last; i++)
    {
        if (L->Data[i] == X)
            return i;
    }
    return ERROR;
}

bool Insert(List L, ElementType X, Position P) //插入
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

bool Delete(List L, Position P) //删除
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