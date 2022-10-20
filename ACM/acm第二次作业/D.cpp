#include <iostream>
using namespace std;

int a[110], b[110], n;

void ddw(int l, int r, int depth);

int main()
{
    int t;
    int l, r;

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i]=-1;
        }
        ddw(0, n-1, 0);
        for (int i = 0; i < n; i++)
        {
            cout << b[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

void ddw(int l, int r, int depth)
{
    if (l > r)
        return;
    int maxn = 0, maxi = -1;
    for (int i = l; i <= r; i++)
    {
        if (a[i] > maxn)
        {
            maxn = a[i];
            maxi = i;
        }
    }
    b[maxi] = depth;
    ddw(l, maxi - 1, depth + 1);
    ddw(maxi + 1, r, depth + 1);
    return;
}