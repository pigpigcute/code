void CreateBTree(BTree &bt, string str) //创建二叉树
{
     bt = (BTree)malloc(sizeof(TNode));
     bt->data = str[0];
     bt->lchild->data = str[2];
     bt->lchild->lchild->data = str[4];
     bt->lchild->rchild->data = str[6];
     bt->lchild->rchild->lchild->data = str[8];
     bt->rchild->data = str[12];
     bt->rchild->lchild->data = str[14];
     bt->rchild->lchild->rchild->data = str[17];
     bt->rchild->rchild->data = str[19];
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