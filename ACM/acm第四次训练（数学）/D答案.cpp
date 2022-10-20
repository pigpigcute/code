/* #include <cstdio>
long long n, res;         //�ǵ�long long
bool isprime(long long x) //����ĳ����O(n/6)�������ж�
{
    if (x == 1ll)
        return false;
    if (x == 2ll || x == 3ll)
        return true;
    if (x % 6ll != 1ll && x % 6ll != 5ll)
        return false;
    for (register long long i = 5ll; i * i <= x; i += 6ll)
        if (!(x % i) || !(x % (i + 2ll)))
            return false;
    return true;
}
long long findmin(long long x) // findmin����
{
    for (register long long i = 3ll; i * i < x; i += 2)
        if (!(x % i))
            return i;
    return 0ll;
}
int main()
{
    scanf("%lld", &n);
    if (isprime(n))
        printf("1\n"); //���n�����������1
    else if (!(n & 1))
        printf("%lld\n", n >> 1ll); //���n��ż�������n/2
    else
        printf("%lld\n", ((n - findmin(n)) >> 1ll) + 1ll); //��������(n-findmin(n))/2+1
    return 0;
} */


/* #include <iostream>
using namespace std;

long long int a(long long int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return i;
    return x;
}

long long int b(long long int x)
{
    if (x == 0)
        return 0;
    if (x % 2 == 0)
        return x / 2;
    return b(x - a(x)) + 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    long long int n;
    cin >> n;
    cout << b(n) << endl;
    return 0;
} */

