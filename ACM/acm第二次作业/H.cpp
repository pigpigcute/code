#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, a[15], ans, m;
    long long int k, sum;
    cin >> t;
    while (t--)
    {
        sum = 0;
        cin >> n >> k;
        k++;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] = pow(10, a[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            if (i == n)
            {
                sum = sum + a[i] * k;
            }
            else
            {

                m = a[i + 1] / a[i];
                if (k < m)
                {
                    sum = sum + a[i] * k;
                    break;
                }
                else
                {
                    k = k - (m - 1);
                    sum = sum + a[i] * (m - 1);
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}