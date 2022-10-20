#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int a = s.find('0');
    if (a < s.size())
    {
        puts("YES");
        puts("0");
        return 0;
    }
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            for (int k = j + 1; k < s.size(); k++)
            {
                if (((s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0')) % 8 == 0)
                {
                    puts("YES");
                    cout << s[i] << s[j] << s[k] << endl;
                    return 0;
                }
            }
            if (((s[i] - '0') * 10 + (s[j] - '0')) % 8 == 0)
            {
                puts("YES");
                cout << s[i] << s[j] << endl;
                return 0;
            }
        }
        if ((s[i] - '0') % 8 == 0)
        {
            puts("YES");
            cout << s[i] << endl;
            return 0;
        }
    }
    puts("NO");
    return 0;
}