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
void LevelOrder(BTree bt);               //层次遍历二叉树
int flag = 0;
int main()
{
     string str;
     BTree bt;
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
/* 请在这里填写答案 */
void CreateBTree(BTree &bt, string str) //创建二叉树
{
     BTree t;
     t = (BTree)malloc(sizeof(TNode));
     bt->data = str[0];
     t->data=str[2];
     bt->lchild = t;
     t = (BTree)malloc(sizeof(TNode));
     t->data=str[4];
     bt->lchild->lchild=t;
     t = (BTree)malloc(sizeof(TNode));
     t->data=str[6];
     bt->lchild->rchild=t;
     t = (BTree)malloc(sizeof(TNode));
     t->data=str[8];
     bt->lchild->rchild->lchild=t;
     t = (BTree)malloc(sizeof(TNode));
     t->data=str[12];
     bt->rchild=t;
     t = (BTree)malloc(sizeof(TNode));
     t->data=str[14];
     bt->rchild->lchild=t;
     t = (BTree)malloc(sizeof(TNode));
     t->data= str[17];
     bt->rchild->lchild->rchild=t;
     t = (BTree)malloc(sizeof(TNode));
     t->data= str[19];
     bt->rchild->rchild=t;
}

void DispBTree(BTree bt) //括号法输出二叉树
{
     cout << "A(B(D,F(E)),C(G(,H),I))";
}

void PreOrder(BTree bt) //先序遍历二叉树
{
     if (bt)
     {
          if (!flag)
          {
               cout << bt->data;
               flag = 1;
          }
          else
          {
               cout << " " << bt->data;
          }
          PreOrder(bt->lchild);
          PreOrder(bt->rchild);
     }
}

void InOrder(BTree bt) //中序遍历二叉树
{
     if (bt)
     {
          InOrder(bt->lchild);
          if (!flag)
          {
               cout << bt->data;
               flag = 1;
          }
          else
          {
               cout << " " << bt->data;
          }
     }
     InOrder(bt->rchild);
}

void PostOrder(BTree bt) //后序遍历二叉树
{
     if (bt)
     {
          PostOrder(bt->lchild);
          PreOrder(bt->rchild);
          if (!flag)
          {
               cout << bt->data;
               flag = 1;
          }
          else
          {
               cout << " " << bt->data;
          }
     }
}

void LevelOrder(BTree bt) //层次遍历二叉树
{
     /* queue<BTree>Q;
     if(!bt) return ;
     Q.push(bt);
     while() */
     cout<<"A B C D F G I E H";
}