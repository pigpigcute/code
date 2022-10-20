#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, a, b, c, x, y;
    int m;
    cin >> t;
    while (t--)
    {
        m = 0;
        cin >> a >> b >> c >> x >> y;
        if (a >= x && b >= y)
            cout << "YES" << endl;
        else
        {
            if (a < x)
                m = m + x - a;
            if (b < y)
                m = m + y - b;
            if (c >= m)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}