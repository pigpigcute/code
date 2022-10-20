#include <bits/stdc++.h>
using namespace std;

typedef struct TNode *Position;
typedef Position BinTree;
typedef int ElementType;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

int GetHeight(BinTree bt)
{
    int HL, HR, MaxH;

    if (bt)
    {
        HL = GetHeight(bt->Left);
        HR = GetHeight(bt->Right);
        MaxH = HL > HR ? HL : HR;
        return (MaxH + 1);
    }
    else
        return 0;
}