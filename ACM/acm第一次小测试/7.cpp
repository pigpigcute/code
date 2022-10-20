#include <iostream>
using namespace std;
int main()
{
    int t, n, m;
    int a[1010];
    cin >> a[1] >> a[2] >> n;
    if (n == 1)
    {
        cout << a[1];
    }
    else
    {
        cout << a[1] << " " << a[2];
    }
    if (n > 2)
    {
        m = a[1] * a[2];
        if (m < 10)
        {
            a[3] = m;
            t = 4;
            cout << " " << a[3];
        }
        else
        {
            a[4] = m % 10;
            a[3] = m / 10;
            t = 5;
            if (n > 3)
            {
                cout << " " << a[3] << " " << a[4];
            }
            else
            {
                cout << " " << a[3];
            }
        }
    }
    if (n > 3)
    {

        for (int i = 2; i <= n, t <= n; i++)
        {
            m = a[i] * a[i + 1];
            if (m < 10)
            {
                a[t] = m;
                cout << " " << a[t];
                t++;
            }
            else
            {
                a[t] = m / 10;
                a[t + 1] = m % 10;
                if (t == n)
                {
                    cout << " " << a[t];
                }
                else if (t < n)
                {
                    cout << " " << a[t] << " " << a[t + 1];
                }

                t = t + 2;
            }
        }
    }
    return 0;
}