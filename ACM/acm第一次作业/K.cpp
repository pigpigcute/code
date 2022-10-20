#include <iostream>
using namespace std;

int cp(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

int main()
{
    int t, s[4];
    int max1, max2, m, n;
    cin >> t;
    while (t--)
    {
        max1 = 0;
        max2 = 0;
        for (int i = 0; i < 4; i++)
        {
            cin >> s[i];
            if (max1 < s[i])
                max1 = s[i];
        }
        for (int i = 0; i < 4; i++)
        {
            if (max2 < s[i] && max1 > s[i])
                max2 = s[i];
        }
        m = cp(s[1], s[0]);
        n = cp(s[2], s[3]);
        if ((m == max1 && n == max2) || (m == max2 && n == max1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}