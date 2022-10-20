#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    int t = 0, m, n, p, q, booll = 1;
    string k, s1 = "easy", s2 = "qiandao";
    cin >> m >>n;
    getchar();
    for (int i = 0; i < m; i++)
    {
        getline(cin, k);
        cin >> k;
        p = k.find(s1);
        q = k.find(s2);
        if (p != -1 || q != -1)
        {
            continue;
        }
        else
            t++;

        if (t > n)
        {
            cout << k;
            booll = 0;
        }
    }
    if (booll)
        cout << "Wo AK le";
    return 0;
}