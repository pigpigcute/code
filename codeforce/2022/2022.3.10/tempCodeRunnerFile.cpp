#include <iostream>
using namespace std;

int main()
{
    int t, n, a[1010], m;
    cin >> t;
    while (t--)
    {
        m = 1;
        cin >> n; //数组a的长度
        if (n > 19)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            for (int i = 0; i < n - 1; i++)
            {
                cout << m << " ";
                m = m * 3;
            }
            cout << m << endl;
        }
    }

    return 0;
}