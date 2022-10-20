#include <iostream>
using namespace std;

int main()
{
    int t, n, i, j, m, s;
    cin >> t;
    while (t--)
    {
        cin >> n;
        m = n % 2;
        if (m == 0)
        {
            for (i = 1; i < n; i += 2)
            {
                cout << i + 1 << " " << i << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "3 1 2 ";
            for (i = 4; i < n; i += 2)
            {
                cout << i + 1 << " " << i << " ";
            }
            cout << endl;
        }
    }
}
// 123456789  10
//