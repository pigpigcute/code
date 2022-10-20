#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd1(ll a, ll b);
int gcd2(int a, int b); //求最大公因数
int lcm(int a, int b);  //求最小公倍数

int main()
{
    ll a, b;
    int c, d;
    cin >> a >> b;
    cin >> c >> d;
    cout << gcd(c, d) << endl
         << gcd1(a, b) << endl
         << lcm(c, d) << endl;
}

int gcd(int a, int b)
{
    int r;
    while (b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

ll gcd1(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}