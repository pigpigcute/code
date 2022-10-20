#include <iostream>

using namespace std;

int numb(int x, int y)
{
    int i, s = 0;
    for (i = x; i <= y; i++)
    {
        if (i % 4 == 0 && i % 100 != 0)
            s++;
        else if (i % 400 == 0)
            s++;
    }
    return s;
}

int main()
{
    int t, m, n, k;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        if (m + n < 10000)
        {
            if (n < 0)
                k = numb(m + n, m);
            else
                k = numb(m, m + n);
        }
        else
        {
            if (9999 - (m + n - 9999) < m)
                k = numb(9999 - (m + n - 9999), m);
            else
                k = numb(m, 9999 - (m + n - 9999));
        }
        cout << k << endl;
    }

    return 0;
}