#include <bits/stdc++.h>
using namespace std;
/*
n为奇数，每只队伍都赢(n-1)/2次即可
n为偶数时，每只队伍赢（n-2）/2次，平局一次
*/
int main()
{
    int k, t, n;
    int a[110], time[110];
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n % 2 == 1)
            k = (n - 1) / 2;
        else
            k = (n - 2) / 2;

        memset(a, 0, sizeof(a));
        memset(time, 0, sizeof(time));

        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (a[i] < k)
                {
                    a[i]++;
                    cout << 1 << " ";
                    time[i]++;
                    time[j]++;
                }
                else if (a[i] == k && a[j] < k)
                {

                    if (n % 2 == 1)
                    {
                        a[j]++;
                        cout << -1 << " ";
                    }
                    else
                    {
                        if (time[i] == 2 * k)
                            cout << 0 << " ";
                        else
                        {
                            a[j]++;
                            cout << -1 << " ";
                        }
                    }
                    time[i]++;
                    time[j]++;
                }
                else if (a[i] == k && a[j] == k)
                {
                    cout << 0 << " ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}