#include <iostream>
using namespace std;

int main()
{
    int t, n, a[200050], b[200050];
    int m1, m2,sum;
    cin >> t;
    while (t--)
    {
        sum=0;
        m1 = 0;
        m2 = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[m1] < a[i])
                m1 = i;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            if (b[m2] < b[i])
                m2 = i;
        }
        for(int i=0;i<n;i++)
        {
            
        }
    }
    return 0;
}