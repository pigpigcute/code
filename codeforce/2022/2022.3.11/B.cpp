#include <iostream>
using namespace std;

int main()
{
    int t, n, m, k, a[105][105], booll = 0, s;
    char sb[800];
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> sb;
            for (int j = 0; j < m; j++)
            {
                a[i][j] = sb[j] - '0';
            }
        }
        booll = 0;
        if (n != 1 && m != 1)
        {
            for (int i = 1; booll == 0, i < n; i++)
            {
                for (int j = 1; booll == 0, j < m; j++)
                {
                    k = a[i][j] + a[i - 1][j] + a[i][j - 1] + a[i - 1][j - 1];
                    if (k == 3)
                        booll = 1;
                }
            }
        }

        if (booll == 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}