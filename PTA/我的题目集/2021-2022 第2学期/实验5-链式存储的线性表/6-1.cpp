#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode
{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

List MakeEmpty();
Position Find(List L, ElementType X);
bool Insert(List L, ElementType X, Position P);
bool Delete(List L, Position P);

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;
    bool flag;

    L = MakeEmpty();
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &X);
        flag = Insert(L, X, L->Next);
        if (flag == false)
            printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &X);
        P = Find(L, X);
        if (P == ERROR)
            printf("Finding Error: %d is not in.\n", X);
        else
        {
            flag = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if (flag == false)
                printf("Wrong Answer.\n");
        }
    }
    flag = Insert(L, X, NULL);
    if (flag == false)
        printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    flag = Insert(L, X, P);
    if (flag == true)
        printf("Wrong Answer\n");
    flag = Delete(L, P);
    if (flag == true)
        printf("Wrong Answer\n");
    for (P = L->Next; P; P = P->Next)
        printf("%d ", P->Data);
    return 0;
}
/* 你的代码将被嵌在这里 */
List MakeEmpty()
{
    List L;
    L = (List)malloc(sizeof(List));
    L->Next = NULL;
    return L;
}

Position Find(List L, ElementType X)
{
    L = L->Next;
    while (L)
    {
        if (L->Data == X)
        {
            return L;
        }
        L = L->Next;
    }
    return ERROR;
}

bool Insert(List L, ElementType X, Position P)
{
    List t = (List)malloc(sizeof(List));
    t->Data = X;
    t->Next = NULL;
    List q = L;
    while (q)
    {
        if (q->Next == P)
        {
            t->Next = P;
            q->Next = t;
            return true;
        }
        q = q->Next;
    }
    printf("Wrong Position for Insertion\n");
    return false;
}
bool Delete(List L, Position P)
{
    if (L == P)
    {
        L = L->Next;
        return true;
    }
    while (L)
    {
        if (L->Next == P)
        {
            L->Next = P->Next;
            return true;
        }
        L = L->Next;
    }
    printf("Wrong Position for Deletion\n");
    return false;
}