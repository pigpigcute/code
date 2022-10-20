#include <iostream>
using namespace std;

int main()
{
    int t, n, k, m, i, j;
    cin >> t;
    while (t--)
    {
        m = 0;
        k = 0;
        cin >> n;
        i = n;
        while (i != 0)
        {
            k++;
            j = i % 10;
            i = i / 10;
        }
        m = (k - 1) * 9;
        i = j;
        for (int x = 0; x < k - 1; x++)
        {
            i = i * 10 + j;
        }
        if (n >= i)
            cout << m + j << endl;
        else
            cout << m + j - 1 << endl;
    }

    return 0;
}

// 1-9 9
// 10-99 9
// 100-999 9
// 1000-9999 9
//.....