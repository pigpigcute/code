#include <bits/stdc++.h>
using namespace std;

int Find(int x) //Ñ°ÕÒÖÊÊı£¨ËØÊı£©
{
    /* for(int i=2;i*i<=x;i++)
    {
        if(x%i==0) return false;
    }
    return true; */
    if (x == 2 || x == 3 || x == 5)
        return x;
    else
    {
        int flag = 1;
        if (x % 2 == 0)
            x++;
        while (x)
        {
            flag = 1;
            for (int i = 3; i <= x - 2; i += 2)
            {
                if (x % i == 0)
                    flag = 0;
            }
            if (flag)
                return x;
            x = x + 2;
        }
    }
}

int main()
{
    int t, d, x, y;
    cin >> t;
    while (t--)
    {
        cin >> d;
        x = Find(d + 1);
        y = Find(x + d);
        cout << x * y << endl;
    }
    return 0;
}