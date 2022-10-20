#include <iostream>
using namespace std;

int main()
{
    int t;
    long long int n;
    cin >> t;
    while (t--)
    {
        cin >> n;

        while (n % 2 == 0)
        {
            n = n / 2;
        }
        if (n == 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}