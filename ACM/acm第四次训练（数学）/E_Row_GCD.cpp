#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
typedef long long ll;
ll a[N], b[N];
int n, m;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main()
{
    int i;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= m; i++)
        scanf("%lld", &b[i]);
    sort(a + 1, a + n + 1);
    if (n == 1)
    {
        for (i = 1; i <= m; i++)
            printf("%lld ", b[i] + a[n]);
        return 0;
    }
    ll res = 0;
    for (i = 2; i <= n; i++)
        res = gcd(a[i] - a[i - 1], res);
    for (i = 1; i <= m; i++)
        printf("%lld ", gcd(a[1] + b[i], res));
    return 0;
}