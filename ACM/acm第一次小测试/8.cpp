#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int l, n, t, k, s,b;
    cin >> l >> n;
    t = pow(26, l) - n;
    for(int i=1;i<n;i++)
    {
        s=pow(26,l-i);
        k=t/s;
        cout<<'a'+k;
        b=pow(10,l-i);
        t=t%b;
    }
    
    return 0;
}
// p 15
// a 0
// t 19
// 000 001 002---010 011----020---
// 26½øÖÆ
//10159 15
//676