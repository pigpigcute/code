#include <iostream>
using namespace std;

int main()
{
    int t, n, m, k;
    cin >> t;
    while (t--)
    {
        cin >> n;
        m = n / 2020;
        k = n % 2020;
        if (k <= m)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}