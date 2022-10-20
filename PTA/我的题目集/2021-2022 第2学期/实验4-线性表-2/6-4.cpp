#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* �洢������� */
    PtrToNode   Next; /* ָ����һ������ָ�� */
};
typedef PtrToNode List; /* ���嵥�������� */

void ReadInput( List L1, List L2 ); /* ����ʵ�֣�ϸ�ڲ��� */
void PrintSublist( PtrToNode StartP ); /* ����ʵ�֣�ϸ�ڲ��� */
PtrToNode Suffix( List L1, List L2 );

int main()
{
    List L1, L2;
    PtrToNode P;

    L1 = (List)malloc(sizeof(struct Node));
    L2 = (List)malloc(sizeof(struct Node));
    L1->Next = L2->Next = NULL;
    ReadInput( L1, L2 );
    P = Suffix( L1, L2 );
    PrintSublist( P );

    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
PtrToNode Suffix( List L1, List L2 )
{
	List P1,P2;
	P1=L1->Next;
	P2=L2->Next;
	int len1=0,len2=0;
	while(P1)//������1�ĳ��� len1
	{
		len1++;
		P1=P1->Next;
	}
	while(P2)//������2�ĳ��� len2
	{
		len2++;
		P2=P2->Next;
	}
	for(P1=L1;len1>len2;len1--)//��len1>len2,��p1ָ�������еĵ�len1-len2+1����� 
	    P1=P1->Next;
	for(P2=L2;len2>len1;len2--)//��len2>len1,��p2ָ�������еĵ�len2-len1+1�����  
	    P2=P2->Next;
	while(P1->Next!=P2->Next) 
	{
		/*��ָ��P1��p2ͬ������ƶ���
		ֱ��P1��p2ָ��ͬһ��� */
		P1=P1->Next;
		P2=P2->Next;
	}
	return P1->Next; 
}
