#include <bits/stdc++.h>
using namespace std;
int n, t, k;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i < n; ++i)
        {
            int j = i + 1;
            if (!(n & 1) && (i & 1))
            {
                ++j;
                cout << 0 << " ";
            }
            
            for (j; j <= n; ++j)
            {
                k = (j - i) & 1 ? -1 : 1;
                cout << k << " ";
            }
        }

        putchar(10);
    }
    return 0;
}