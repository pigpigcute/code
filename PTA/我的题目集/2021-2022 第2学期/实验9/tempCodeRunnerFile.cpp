int g = 0;
bool Findxpath(BiTree bt, char x, vector<char> tmppath, vector<char> &path)
{
    if (x == bt->data)
    {
        path = tmppath;
    }
    tmppath[g++] = bt->data;

    Findxpath(bt->lchild, x, tmppath, path);
    Findxpath(bt->rchild, x, tmppath, path);
    g--;
}