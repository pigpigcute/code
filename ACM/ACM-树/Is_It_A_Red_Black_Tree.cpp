#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *l, *r;
};
int v[40];
node *root;

void build(node *qqt, int val)
{
    int v = qqt->val;
    if (abs(val) < abs(v))
    {
        if (qqt->l == NULL)
            qqt->l = new node(), qqt->l->val = val;
        else
            build(qqt->l, val);
    }
    else
    {
        if (qqt->r == NULL)
            qqt->r = new node(), qqt->r->val = val;
        else
            build(qqt->r, val);
    }
}

int cal(node *x)
{
    if (!x)
        return 0;
    int numl = cal(x->l), numr = cal(x->r);
    if (numl == numr && numl != -1)
        return x->val > 0 ? numl + 1 : numl;
    return -1;
}

bool judge(node *x)
{
    if (!x)
        return true;
    if (x->val < 0)
        if (x->l && x->l->val < 0 || x->r && x->r->val < 0)
            return false;
    return judge(x->l) && judge(x->r);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> v[i];
        root = new node();
        root->val = v[1], root->l = root->r = NULL;
        for (int i = 2; i <= n; i++)
            build(root, v[i]);
        if (v[1] > 0 && judge(root) && cal(root) != -1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}