#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, i, m;
    int a[200050] = {0};
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 1; i <= n; i++)
            a[i] = 0;

        for (i = 1; i <= n; i++)
        {
            cin >> m;
            a[m]++;
        }

        if (n < 3)
        {
            cout << -1 << endl;
            continue;
        }

        for (i = 1; i <= n; i++)
            if (a[i] >= 3)
            {
                cout << i << endl;
                break;
            }

        if (i == n + 1)
            cout << -1 << endl;
    }

    return 0;
}