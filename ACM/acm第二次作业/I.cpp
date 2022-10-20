#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> s;
        if (s.find("aa") != string::npos)
            cout << 2 << endl;
        else if (s.find("aba") != string::npos || s.find("aca") != string::npos)
            cout << 3 << endl;
        else if (s.find("abca") != string::npos || s.find("acba") != string::npos)
            cout << 4 << endl;
        else if (s.find("abbacca") != string::npos || s.find("accabba") != string::npos)
            cout << 7 << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}