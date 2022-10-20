#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, l, r, k;
    cin >> t;
    while (t--)
    {
        cin >> l >> r >> k;
        if (l == r)
        {
            if (l > 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else if (l < r)
        {

            if ((r - l + 1) & 1)
            {
                if (!(l & 1) && k >= (r - l) / 2)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    if (k >= (r - l) / 2 + 1)
                    {
                        cout << "YES" << endl;
                    }
                    else
                        cout << "NO" << endl;
                }
            }
            else
            {
                if (k >= (r - l + 1) / 2)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
    }
    return 0;
}