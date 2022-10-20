#include <bits/stdc++.h>
using namespace std;
#define AC return
#define Please 0
#define itn int
#define enld '\n' // IO?
#define endl '\n' // IO?
#define Endl '\n' // IO?
#define esle else
#define ciN cin
#define YES "YES"
#define NO "NO"
#define wide(x, ch) setw(x) << setfill(ch)

int n, m, limit;
stack<int> st[1010];
void run()
{
    cin >> n >> m >> limit;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        reverse(str.begin(), str.end());
        for (int j = 0; j < str.size(); j++)
        {
            st[i].push(str[j]);
        }
    }
    string ans;
    stack<char> v;
    while (1)
    {
        int op;
        cin >> op;
        if (op == -1)
            break;
        if (!op)
        {
            if (!v.empty())
            {
                ans.push_back(v.top());
                v.pop();
            }
        }
        else
        {
            if (!st[op].empty())
            {
                if (v.size() < limit)
                {
                    v.push(st[op].top());
                    st[op].pop();
                }
                else
                {
                    ans.push_back(v.top());
                    v.pop();
                    v.push(st[op].top());
                    st[op].pop();
                }
            }
        }
    }
    cout << ans;
    return;
    // T==1?
}
int main()
{
    // freopen("D:\\MY_std_input\\std_input.txt", "r", stdin);
    // freopen("D:\\MY_std_input\\std_output1.txt", "w", stdout);
    // freopen("D:\\MY_std_input\\std_output2.txt", "w", stdout);
    ios::sync_with_stdio(false);
    int T = 1;
    // cin>>T;
    while (T--)
    {
        run();
    }
    AC Please;
}