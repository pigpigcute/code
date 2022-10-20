#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
#define MinData -1

typedef struct HeapStruct *PriorityQueue;
struct HeapStruct
{
    ElementType *Elements;
    int Capacity;
    int Size;
};

PriorityQueue Initialize(int MaxElements); /* details omitted */

void PercolateUp(int p, PriorityQueue H);
void PercolateDown(int p, PriorityQueue H);

void Insert(ElementType X, PriorityQueue H)
{
    int p = ++H->Size;
    H->Elements[p] = X;
    PercolateUp(p, H);
}

ElementType DeleteMin(PriorityQueue H)
{
    ElementType MinElement;
    MinElement = H->Elements[1];
    H->Elements[1] = H->Elements[H->Size--];
    PercolateDown(1, H);
    return MinElement;
}

int main()
{
    int n, i, op, X;
    PriorityQueue H;

    scanf("%d", &n);
    H = Initialize(n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            scanf("%d", &X);
            Insert(X, H);
            break;
        case 0:
            printf("%d ", DeleteMin(H));
            break;
        }
    }
    printf("\nInside H:");
    for (i = 1; i <= H->Size; i++)
        printf(" %d", H->Elements[i]);
    return 0;
}

/* Your function will be put here */
void PercolateUp(int p, PriorityQueue H)
{ //插入时，小的数字向上调整
    int i;
    int temp = H->Elements[p];
    for (i = H->Size; temp < H->Elements[i / 2] && i > 1; i /= 2)
    { //当插入的数字小于父节点则向上调整
        H->Elements[i] = H->Elements[i / 2];
    }
    H->Elements[i] = temp;
}

void PercolateDown(int p, PriorityQueue H)
{ //删除调整节点时，将该节点下沉到末尾
    int temp = H->Elements[p];
    int parent, son;
    for (parent = p; parent * 2 <= H->Size; parent = son)
    {
        son = parent * 2;
        if (son < H->Size && H->Elements[son] > H->Elements[son + 1])
        {
            son++; //当孩子节点有兄弟的时候，判断当前孩子节点和右兄弟的大小
        }
        if (temp <= H->Elements[son])
            break; //当前节点重新形成小根堆则结束
        else
            H->Elements[parent] = H->Elements[son];
    }
    H->Elements[parent] = temp;
}
