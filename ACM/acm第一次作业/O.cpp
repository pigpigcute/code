#include <iostream>
using namespace std;

int main()
{
    int t, n, a[105], s[105];
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 105; i++)
        {
            s[i] = 0;
        }
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s[a[i]]++;
        }
        if (n == 1)
            cout << a[0] << endl;
        else
        {
            for (int i = 0; i < 105; i++)
            {
                if (s[i])
                {
                    cout << i << " ";
                    s[i]--;
                }
            }
            for (int i = 0; i < 105; i++)
            {
                if (s[i])
                {
                    for (int j = 0; j < s[i]; j++)
                    {
                        cout << i << " ";
                    }
                }
            }
        }
        cout << endl;
    }

    return 0;
}