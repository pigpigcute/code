//暴力解题，不通过
/* #include <bits/stdc++.h>
using namespace std;

int gcd(int a); //求最大公因数

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        while (1)
        {
            if (gcd(n) > 1)
                break;
            else
                n++;
        }
        cout << n << endl;
    }
    return 0;
}

int gcd(int a)
{
    int b = 0, n, t;
    int r;
    n = a;
    while (n > 0)
    {
        t = n % 10;
        b = b + t;
        n = n / 10;
    }
    while (b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
} */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll gcdsum(ll n)
{
    ll m = 0;
    for (ll i = n; i > 0; i /= 10)
    {
        m += i % 10;
    }
    return gcd(n, m);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        ll n, ans;
        scanf("%lld", &n);
        ans = n;
        while (gcdsum(ans) == 1)
            ans++;
        printf("%lld\n", ans);
    }
    return 0;
}