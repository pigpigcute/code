#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k, i, p;
    string s, ch;
    cin >> t;
    while (t--)
    {
        i = 0;
        cin >> n >> k;
        cin >> s;
        p = 0;
        while (k--)
        {
            ch = s;

            while ((s[i + 1] - 'a' <= k && i < n && s[i + 1] >= s[i]) || s[i] == 'a')
            {
                i++;
            }
            if (i == n)
                break;

            for (int j = 0; j < n; j++)
            {
                if (s[j] == ch[i])
                    s[j] = s[j] - 1;
            }
        }
        cout << s << endl;
    }
    return 0;
}