#include <stdio.h>
#include <stdlib.h>

typedef struct TNode *BinTree;
struct TNode
{
    int Key;
    BinTree Left;
    BinTree Right;
};

BinTree BuildTree(); /* details omitted */
BinTree KthLargest(BinTree T, int K);

int main()
{
    BinTree T, P;
    int K;

    T = BuildTree();
    scanf("%d", &K);
    P = KthLargest(T, K);
    printf("%d\n", P->Key);
    if (P->Left)
        printf("%d\n", P->Left->Key);
    else
        printf("NULL\n");
    if (P->Right)
        printf("%d\n", P->Right->Key);
    else
        printf("NULL\n");

    return 0;
}
/* Your function will be put here */
BinTree KthLargest(BinTree T, int X)
{
    BinTree RXB = T;
    BinTree Klargest = NULL;
    int count = 0;
    while (RXB != NULL)
    {
        if (RXB->Right == NULL)
        {
            if (++count == X)
                Klargest = RXB;
            RXB = RXB->Left;
        }
        else
        {
            BinTree TTG = RXB->Right;
            while (TTG->Left != NULL && TTG->Left != RXB)
                TTG = TTG->Left;
            if (TTG->Left == NULL)
            {
                TTG->Left = RXB;
                RXB = RXB->Right;
            }
            else
            {

                TTG->Left = NULL;
                if (++count == X)
                    Klargest = RXB;
                RXB = RXB->Left;
            }
        }
    }
    return Klargest;
}