#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b);

int main()
{
    int t, n, a[101],result,b[101];
    int G;
    bool thesame; //判断是否为无穷大
    cin >> t;
    while (t--)
    {
        cin >> n;
        thesame = true;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(i>0)
            {
                b[i]=a[i]-a[i-1];
                if(b[i]<0) b[i]=-b[i];
            }
            if (i > 0 && a[i] != a[i - 1])
            {
                thesame = false;
            }
        }
        if (thesame)
        {
            cout << -1 << endl;
        }
        else
        {
            G=b[1];
            for(int i=2;i<n;i++)
            {
                G=gcd(G,b[i]);
            }
            cout<<G<<endl;
        }
    }
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

/* int gcd(int n,int m){
    if(n % m == 0){
        return m;
    }
    return gcd(m,n%m);
} */
