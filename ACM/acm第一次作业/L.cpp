#include <iostream>
using namespace std;

int main()
{
    int t, n, i, j;
    int s[26];
    char m[100];
    cin >> t;
    while (t--)
    {
        for (i = 0; i < 26; i++)
        {
            s[i] = 0;
        }
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> m[i];
        s[m[0] - 'A'] = 1;
        for (j = 1; j < n; j++)
        {
            if (m[j] != m[j - 1])
            {
                if (s[m[j] - 'A'] == 1)
                {
                    cout << "NO" << endl;
                    break;
                }
                else
                    s[m[j] - 'A'] = 1;
            }
        }
        if (j == n)
            cout << "YES" << endl;
    }

    return 0;
}