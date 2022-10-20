#include <stdio.h>

#define MAXSIZE 20
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput();       /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�0��ʼ�洢 */
void PrintList(List L); /* ����ʵ�֣�ϸ�ڲ��� */
List Delete(List L, ElementType minD, ElementType maxD);

int main()
{
    List L;
    ElementType minD, maxD;
    int i;

    L = ReadInput();
    scanf("%d %d", &minD, &maxD);
    L = Delete(L, minD, maxD);
    PrintList(L);

    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
List Delete(List L, ElementType minD, ElementType maxD)
{
    int count = 0;
    for (int i = 0; i <= L->Last; i++)
    {
        if (L->Data[i] > minD && L->Data[i] < maxD)
        {
            count++;
        }
        else
        {
            L->Data[i - count] = L->Data[i];
        }
    }
    L->Last -= count;
    return L;
}
