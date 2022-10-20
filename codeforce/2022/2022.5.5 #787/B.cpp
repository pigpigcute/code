#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t, n, a[50], number, flag;
    cin >> t;
    while (t--)
    {
        number = 0;
        flag = 1;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        if (a[n] < n-1)
        {
            cout << -1 << endl;
            continue;
        }

        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }

        for (int i = n - 1; i >= 1; i--)
        {
            while (a[i] >= a[i + 1] && a[i] != 0)
            {
                a[i] = a[i] / 2;
                number++;
            }

            if (i != 1 && a[i] == 0)
            {
                cout << -1 << endl;
                flag = 0;
                break;
            }
        }

        if (flag)
            cout << number << endl;
    }
    return 0;
}