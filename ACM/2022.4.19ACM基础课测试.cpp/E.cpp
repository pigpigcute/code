#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, s[110], a[110], sum, L;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        cin >> a[s[i]];
        sum = sum + a[s[i]];
    }
    L = sum / n;
    for (int i = 1; i <= n; i++)
    {
        if (i == m)
        {
            if (a[i] < 60)
                a[i] = 60;
        }
        else
        {
            if (a[i] >= L && a[i] >= 2)
                a[i] = a[i] - 2;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
}