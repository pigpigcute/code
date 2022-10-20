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
void CreateBTree(BTree &bt, string str); //创建二叉树
void DispBTree(BTree bt);                //括号法输出二叉树
void PreOrder(BTree bt);                 //先序遍历二叉树
void InOrder(BTree bt);                  //中序遍历二叉树
void PostOrder(BTree bt);                //后序遍历二叉树
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
}
/* 请在这里填写答案 */
void CreateBTree(BTree &bt, string str) //创建二叉树
{
    BTree st[100],p;
    int top=-1,k,j=0;
    char ch;
    bt=NULL;
    ch=str[j];
    while(ch!='\0')
    {
        switch(ch)
        {
            case '(': top++;st[top]=p;k=1;break;
            case ')': top--;break;
            case ',': k=2;break;
            default: 
                p=(BTree)malloc(sizeof(TNode));
                p->data=ch;
                p->rchild=p->lchild=NULL;
                if(bt==NULL) bt=p;
                else{
                    switch(k)
                    {
                        case 1: st[top]->lchild=p;break;
                        case 2: st[top]->rchild=p;break;
                    }
                }
                break;
        }
        j++;
        ch=str[j];
    }
}
void DispBTree(BTree bt)  //括号法输出二叉树
{
    if(bt)
    {
        cout<<bt->data;
        if(bt->lchild!=NULL||bt->rchild!=NULL)
        {
            cout<<"(";
            DispBTree(bt->lchild);
            if(bt->rchild!=NULL)
                cout<<",";
            DispBTree(bt->rchild);
            cout<<")";
        }
    }
}
void PreOrder(BTree bt)   //先序遍历二叉树
{
    if(bt)
    {
        cout<<bt->data<<" ";
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}
void InOrder(BTree bt)    //中序遍历二叉树
{
    if(bt)
    {
        InOrder(bt->lchild);
        cout<<bt->data<<" ";
        InOrder(bt->rchild);
    }
}
void PostOrder(BTree bt)  //后序遍历二叉树
{
    if(bt)
    {
        PostOrder(bt->lchild);
        PostOrder(bt->rchild);
        cout<<bt->data<<" ";
    }
}

