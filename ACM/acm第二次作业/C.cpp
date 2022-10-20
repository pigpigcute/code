#include <iostream>
using namespace std;

int main()
{
    long long int t;
    long long int n, k, m, number;
    cin >> t;
    while (t--)
    {
        m = 1;
        number = 0;
        cin >> n >> k;
        while (1)
        {
            if (m >= k)
            {
                break;
            }

            m *= 2;
            number++;
        }
        if (n - m > 0)
        {
            number = number + (n - m) / k;
            if ((n - m) % k != 0)
                number++;
        }
        cout << number << endl;
    }
    return 0;
}