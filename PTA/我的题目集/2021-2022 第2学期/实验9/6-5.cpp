#include <iostream>
#include <string.h>
#define N 100;
using namespace std;

typedef struct BiNode
{
    char data;
    struct BiNode *lchild, *rchild;
} BiTNode, *BiTree;

void CreateBiTree(BiTree &T, char a[], int &i)
{
    char ch;
    ch = a[i++];
    if (ch == '#')
        T = NULL;
    else
    {
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild, a, i);
        CreateBiTree(T->rchild, a, i);
    }
}

bool Isomorphism(BiTree T1, BiTree T2);

int main()
{
    BiTree T1, T2;
    int i = 0, j = 0;
    char a[100];
    char b[100];
    cin >> a >> b;
    CreateBiTree(T1, a, i);
    CreateBiTree(T2, b, j);
    cout << Isomorphism(T1, T2);
    return 0;
}

/* 请在这里填写答案 */
bool Isomorphism(BiTree T1, BiTree T2)
{
    if (T1 && T2)
    {
        Isomorphism(T1->lchild, T2->lchild);
        Isomorphism(T1->rchild, T2->rchild);
    }
    else if (!T1 && !T2)
        return true;
    else
        return false;
}