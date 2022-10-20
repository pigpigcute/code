#include <iostream>
using namespace std;

int main()
{
    int t, n, m, k;
    cin >> t;
    while (t--)
    {
        cin >> n;
        m = n % 3;
        k = n / 3;
        if (m != 2)
        {
            if (m == 1)
            {
                cout << "1";
            }
            for (int i = 0; i < k; i++)
            {
                cout << "21";
            }
            cout << endl;
        }
        else
        {
            cout << "2";
            for (int i = 0; i < k; i++)
            {
                cout << "12";
            }
            cout << endl;
        }
    }
    return 0;
}