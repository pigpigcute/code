#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
const int M = 2e5 + 10;

int n;
ll a[M], s[M], ans;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (i % 2 == 1)
            {
                s[i] = s[i - 1] - a[i];
                ans += a[i];
            }
            else
            {
                s[i] = s[i - 1] + a[i];
            }
        }

        ll temp1 = 1e15, temp0 = 1e15, res = -1e15;
        for (int i = 0; i <= n; i++)
        {
            if (i % 2 == 1)
            {
                temp1 = min(temp1, s[i]);
                res = max(res, s[i] - temp1);
            }
            else
            {
                temp0 = min(temp0, s[i]);
                res = max(res, s[i] - temp0);
            }
        }

        cout << ans + res << endl;
    }
    return 0;
}