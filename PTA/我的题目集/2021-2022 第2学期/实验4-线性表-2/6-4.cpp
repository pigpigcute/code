#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

void ReadInput( List L1, List L2 ); /* 裁判实现，细节不表 */
void PrintSublist( PtrToNode StartP ); /* 裁判实现，细节不表 */
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

/* 你的代码将被嵌在这里 */
PtrToNode Suffix( List L1, List L2 )
{
	List P1,P2;
	P1=L1->Next;
	P2=L2->Next;
	int len1=0,len2=0;
	while(P1)//求链表1的长度 len1
	{
		len1++;
		P1=P1->Next;
	}
	while(P2)//求链表2的长度 len2
	{
		len2++;
		P2=P2->Next;
	}
	for(P1=L1;len1>len2;len1--)//若len1>len2,令p1指向链表中的第len1-len2+1个结点 
	    P1=P1->Next;
	for(P2=L2;len2>len1;len2--)//若len2>len1,令p2指向链表中的第len2-len1+1个结点  
	    P2=P2->Next;
	while(P1->Next!=P2->Next) 
	{
		/*将指针P1和p2同步向后移动，
		直到P1和p2指向同一结点 */
		P1=P1->Next;
		P2=P2->Next;
	}
	return P1->Next; 
}
