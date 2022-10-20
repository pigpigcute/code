/* void leaf(btree *T, int &count) // count 起计数作用
{
    if (T == NULL) //跳出递归条件
        return;
    if (T->lchild == NULL && T->rchild == NULL) //关系运算优先级== 大于逻辑运算&&
        count++;
    leaf(T->rchild, count); //可以与下式调换位置
    leaf(T->lchild, count);
}

//求二叉树中度为1结点个数

void degree1(btree *T, int &count)
{
    if (T == NULL)
        return;
    if ((T->lchild == NULL && T->rchild != NULL) || (T->rchild == NULL && T->lchild != NULL))
        count++;
    degree1(T->lchild, count);
    degree1(T->rchild, count);
}
//求二叉树度为2的点
void degree2(btree *T, int &count)
{
    if (T == NULL)
        return;
    if (T->lchild != NULL && T->rchild != NULL)
        count++;
    degree2(T->lchild, count);
    degree2(T->rchild, count);
}
 */
#include <iostream>

using namespace std;

template <class T>
struct BinTreeNode
{
    T data;
    BinTreeNode<T> *leftchild;
    BinTreeNode<T> *rightchild;
    BinTreeNode()
    {
        leftchild = NULL;
        rightchild = NULL;
    }
    BinTreeNode(T x)
    {
        data = x;
        leftchild = NULL;
        rightchild = NULL;
    }
};

template <class T>
class BinTree
{
public:
    BinTree();
    ~BinTree();
    void CreateTree(BinTreeNode<T> *&t);
    void deleTree(BinTreeNode<T> *t);
    void count(BinTreeNode<T> *root, int &i, int &j, int &k);
    BinTreeNode<T> *Get_root()
    {
        return root;
    }

private:
    BinTreeNode<T> *root;
};

template <class T>
BinTree<T>::BinTree()
{
    root = NULL;
}

template <class T>
BinTree<T>::~BinTree()
{
}

template <class T>
void BinTree<T>::CreateTree(BinTreeNode<T> *&t)
{
    T x;
    cin >> noskipws >> x;
    if (x == '#')
    {
        t = NULL;
        return;
    }
    t = new BinTreeNode<T>(x);
    if (t == NULL)
        return;
    CreateTree(t->leftchild);
    CreateTree(t->rightchild);
}

template <class T>
void BinTree<T>::deleTree(BinTreeNode<T> *t)
{
    if (t == NULL)
        return;
    deleTree(t->leftchild);
    deleTree(t->rightchild);
    delete t;
}

template <class T>
void BinTree<T>::count(BinTreeNode<T> *root, int &i, int &j, int &k)
{
    if (root != NULL)
    {
        if (root->leftchild == NULL && root->rightchild == NULL)
            k++;
        if (root->leftchild == NULL && root->rightchild != NULL || root->leftchild != NULL && root->rightchild == NULL)
            j++;
        if (root->leftchild != NULL && root->rightchild != NULL)
            i++;
        count(root->leftchild, i, j, k);
        count(root->rightchild, i, j, k);
    }
}

int main()
{
    BinTree<char> temp;
    BinTreeNode<char> *head = temp.Get_root();
    int i = 0, j = 0, k = 0;
    temp.CreateTree(head);
    temp.count(head, i, j, k);
    temp.deleTree(head);
    cout << k << ' ' << j << ' ' << i << ' ';
    return 0;
}
