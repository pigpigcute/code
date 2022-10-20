#include <iostream>
using namespace std;

int main()
{
    int t, n, a[105], s[3], sum, m, booll;
    cin >> t;
    while (t--)
    {
        sum = 0;
        booll = 0;
        s[1] = 0;
        s[2] = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s[a[i]]++;
            sum = sum + a[i];
        }

        if (sum % 2 == 0)
        {
            m = sum / 2;
            while (s[2] > 0)
            {
                m = m - 2;
                if (m == 0 || (m == 1 && s[1] > 0))
                {
                    booll = 1;
                    break;
                }
                s[2]--;
            }

            while (booll==0&&s[1]>0)
            {
                m = m - 1;
                if (m == 0)
                {
                    booll = 1;
                    break;
                }
                s[1]--;
            }
        }

        if (booll == 1)
            cout << "YES" << endl;
        if (booll == 0)
            cout << "NO" << endl;
    }
    return 0;
}
