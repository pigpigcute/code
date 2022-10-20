#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read();        /* ϸ���ڴ˲��� */
void Print(List L); /* ϸ���ڴ˲��� */

ElementType Find(List L, int m);

int main()
{
    List L;
    int m;
    L = Read();
    scanf("%d", &m);
    printf("%d\n", Find(L, m));
    Print(L);
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
ElementType Find(List L, int m)
{
    int a[m], count, i;
    List p = L;
    for (count = 0, i = 0; p != NULL; i++, count++, p = p->Next)
        a[i % m] = p->Data;
    if (count < m)
        return ERROR;
    return a[i % m];
}
