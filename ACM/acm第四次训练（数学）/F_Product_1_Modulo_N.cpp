#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int gcd1(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main()
{
    int t = 0, n, a[200010];
    ll m = 1;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        if (gcd(i, n) == 1)
        {
            a[t] = i;
            t++;
            m = (m * i) % n;
        }
    }
    if (m != 1)
        t--;
    printf("%d\n", t);
    for (int i = 0; i < t; i++)
        printf("%d ", a[i]);
    return 0;
}