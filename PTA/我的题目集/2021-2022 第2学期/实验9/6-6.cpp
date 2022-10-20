#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
typedef struct BiNode
{
    char data;
    struct BiNode *lchild, *rchild;
} BiTNode, *BiTree;

void CreateBiTree(BiTree &T)
{
    char ch;
    cin >> ch;
    if (ch == '#')
        T = NULL;
    else
    {
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

bool Findxpath(BiTree bt, char x, vector<char> tmppath, vector<char> &path);

int main()
{
    BiTree T;
    char x;
    vector<char> tmppath;
    vector<char> path;
    CreateBiTree(T);
    cin >> x;
    Findxpath(T, x, tmppath, path);
    for (int i = 0; i < path.size(); i++)
        cout << path[i] << " ";
    return 0;
}

/* 请在这里填写答案 */


// bool Findxpath(BiTree bt, char x, vector<char> tmppath, vector<char> &path)
// {
//     if (bt == NULL)
//         return false;
//     tmppath.push_back(bt->data);
//     if (bt->data == x)
//     {
//         path.assign(tmppath.begin(), tmppath.end());
//         return;
//     }
//     Findxpath(bt->lchild, x, tmppath, path);
//     Findxpath(bt->rchild, x, tmppath, path);
//     tmppath.pop_back();
//     /* if (x == bt->data)
//     {
//         path = &tmppath;
//     }
//     tmppath[g++] = bt->data;

//     Findxpath(bt->lchild, x, tmppath, path);
//     Findxpath(bt->rchild, x, tmppath, path);
//     g--; */
// }

bool Findxpath(BiTree bt, char x, vector<char> tmppath, vector<char> &path)
{
    if (bt == NULL)
        return false;
    tmppath.push_back(bt->data);
    if (bt->data == x)
    {
        path = tmppath;
        return true;
    }
    bool find = Findxpath(bt->lchild, x, tmppath, path);
    if (find)
        return true;
    else
        return Findxpath(bt->rchild, x, tmppath, path);
}