#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i = 0, a[2] = {0, 0}, sum;
    string s;
    cin >> n;
    cin >> s;
    while (s[i] != '\0' && i < n)
    {
        if (s[i] == 'L')
            a[0]++;
        else if (s[i] == 'R')
            a[1]++;
        i++;
    }
    sum = a[0] + a[1]+1;
    cout << sum;
    return 0;
}