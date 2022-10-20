#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, number, n0, n1, n2, i, flag, p, q;
    string a;
    cin >> t;
    while (t--)
    {
        n0 = n1 = n2 = 0;

        flag = 1;
        cin >> a;
        p = 0;
        q = a.size() - 1;
        for (i = 0; i < a.size(); i++)
        {
            if (a[i] == '0' && flag == 1)
            {
                q = i;
                flag = 0;
                n0++;
            }
            else if (a[i] == '1')
            {
                p = i;
                n1++;
            }
            else if (a[i] == '?')
                n2++;
            /*  if ((i == 0 && a[i] == '0') || (a[i] == '1' && a[i + 1] == '\n') || (i > 0 && a[i] == '1' && a[i - 1] == '0' && a[i + 1] == '0'))
             {
                 cout << 1 << endl;
                 flag = 0;
                 break;
             } */
        }
        if (n0 == 0 && n1 == 0)
            cout << n2 << endl;
        else if (a[0] == '0' || a[a.size() - 1] == '1')
            cout << 1 << endl;
        else
        
            cout << q - p + 1 << endl;
        /*   if(flag)
          {
              if(n0==1&&n1==0) cout<<n2<<endl;
              else if(n0==0&&n2==0) cout<<n1<<endl;
              else if(n1==0&&n2==0) cout<<n0<<endl;
              else if(n0!=0&&n1!=0&&n2!=0) cout<<q-p+1<<endl;
          } */
    }
    return 0;
}