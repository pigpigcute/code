#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t, n, m, k, s, sum = 0;
    int maxx = 0, maxt = 0;
    cin >> t;
    n = sqrt(t);
    for (int i = 2; i <= n; i++)
    {
        sum = 0;
        k = i;
        s = n;
        while (s % k == 0)
        {
            s /= k;
            k++;
            sum++;
        }
        if (sum > maxx)
        {
            maxx = sum;
            maxt = i;
        }
    }
    if (maxx != 0)
    {
        cout << maxx << endl;
        for (int i = maxt; maxx > 0; i++)
        {
            maxx--;
            if (i != maxt)
            {
                cout << "*";
            }
            cout << i;
        }
    }
    else
    {
        cout << 1 << endl
             << n;
    }

    return 0;
}
// 630 5*6*7=210