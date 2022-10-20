#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, s[110],k[11000];
    double m, a[110];
    double n, sum = 0, L;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        cin >> s[i];
        cin >> a[s[i]];
        sum = sum + a[i];
        
    }
    L = sum / n;
    for (i = 1; i <= n; i++)
    {
        if (i == m)
        {
            if (a[i] < 60)
                a[i] = 60;
        }
        else
        {
            if (a[i] > L)
                a[i]=a[i]-2;
        }
    }
    for (i = 1; i <= n - 1; i++)
    {
        cout << a[i] << " ";
    }
    cout << a[i];
}