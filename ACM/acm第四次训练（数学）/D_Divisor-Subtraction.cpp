#include <bits/stdc++.h>
#include <cmath>
using namespace std;

long long int is_prime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return i;
    }
    return x;
}

int main()
{
    long long int n, i, t = 0;
    cin >> n;
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            t = t + n / 2;
            break;
        }
        else if (is_prime(n) == n)
        {
            t = 1;
            break;
        }
        else
        {
            t++;
            for (i = 2; i <= n; i++)
            {
                if (n % i == 0)
                {
                    i = is_prime(i);
                }
            }
            n = n - i;
        }
    }
    cout << t;
    return 0;
}