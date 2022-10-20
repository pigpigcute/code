#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;
typedef struct node *BTree;
typedef struct node
{
    char data;
    BTree lchild;
    BTree rchild;
} TNode;
void CreateBTree(BTree &bt, string str); //����������
void DispBTree(BTree bt);                //���ŷ����������
void PreOrder(BTree bt);                 //�������������
void InOrder(BTree bt);                  //�������������
void PostOrder(BTree bt);                //�������������
void LevelOrder(BTree bt);               //��α���������
int flag = 0;
int main()
{
    string str;
    BTree bt, p;
    str = "A(B(D,F(E)),C(G(,H),I))";
    CreateBTree(bt, str);
    cout << "btree:";
    DispBTree(bt);
    cout << endl
         << "preorder:";
    PreOrder(bt);
    flag = 0;
    cout << endl
         << "inorder:";
    InOrder(bt);
    flag = 0;
    cout << endl
         << "postorder:";
    PostOrder(bt);
    flag = 0;
    cout << endl
         << "levelorder:";
    LevelOrder(bt);
}
/* ����������д�� */
void CreateBTree(BTree &bt, string str)
{
    BTree s[100], p;
    int high = -1, k, j = 0;
    char ch;
    bt = NULL;
    ch = str[j];
    while (ch != '\0')
    {
        switch (ch)
        {
        case '(':
            high++;
            s[high] = p;
            k = 1;
            break;
        case ')':
            high--;break;
        case ',':
            k = 2;
        default:
            p = (BTree)malloc(sizeof(TNode));
            p->data = ch;
            p->lchild = p->rchild = NULL;
            if (bt == NULL)
                bt = p;
            else
            {
                switch (k)
                {
                case 1:
                    s[high]->lchild = p;
                    break;
                case 2:
                    s[high]->rchild = p;
                    break;
                }
            }
        }
        j++;
        ch = str[j];
    }
}
void DispBTree(BTree bt)
{
    if (bt)
    {
        cout << bt->data;
        if (bt->lchild || bt->rchild)
        {
            cout << "(";
            DispBTree(bt->lchild);
            if (bt->rchild)
                cout << ",";
            DispBTree(bt->rchild);
            cout << ")";
        }
    }
    // cout<<"A(B(D,F(E)),C(G(,H),I))";
}
void PreOrder(BTree bt)
{
    if (bt)
    {
        cout << bt->data << " ";
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
    // cout<<"A B D F E C G H I";
}
void InOrder(BTree bt)
{
    if (bt)
    {
        InOrder(bt->lchild);
        cout << bt->data << " ";
        InOrder(bt->rchild);
    }
    // cout<<"D B E F A G H C I";
}
void PostOrder(BTree bt)
{
    if (bt)
    {
        PostOrder(bt->lchild);
        PostOrder(bt->rchild);
        cout << bt->data << " ";
    }
    // cout<<"D E F B H G I C A";
}
void LevelOrder(BTree bt)
{
    BTree p;
    queue<BTree> qu;
    if (bt != nullptr)
    {
        qu.push(bt);
        while (!qu.empty())
        {
            p = qu.front();
            qu.pop();
            cout << p->data;
            if (p->data != 'H')
                cout << ' ';
            if (p->lchild != NULL)
                qu.push(p->lchild);
            if (p->rchild != NULL)
                qu.push(p->rchild);
        }
    }
    // cout<<"A B C D F G I E H";
}