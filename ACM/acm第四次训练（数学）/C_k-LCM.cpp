#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k;
    k = 3;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        if (n % 2 == 1)
            cout << 1 << " " << n / 2 << " " << n / 2 << endl;
        else
        {
            if (n % 4 == 0)
                cout << n / 2 << " " << n / 4 << " " << n / 4 << endl;
            else
                cout << 2 << " " << n / 2 - 1 << " " << n / 2 - 1 << endl;
        }
    }
    return 0;
}