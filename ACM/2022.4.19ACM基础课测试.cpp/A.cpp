/* #include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    char a[110];
    string m;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>m;
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {

        }
    }

} */

// map
/* #include<bits/stdc++.h>
#define F(i,j,r) for(int i=j;i<=r;++i)

using namespace std;

string a;
string ans;
int M=-1;

map <  string , int > m;
int main(){
    cin>>a;
    cin>>a;
    F(i,0,a.size()-2)
        m[a.substr(i,2)]++;
    for( auto && p : m )
        if(p.second>M){
            M=p.second;
            ans=p.first.c_str();
        }
    cout<<ans<<endl;
    return 0;
} */

#include <bits/stdc++.h>
using namespace std;
int n;
int k[30][30];
char a[105];
int ma;
int main()
{
    scanf("%d", &n);
    cin >> a;
    for (int i = 0; i < n - 1; i++)
    {
        int x = a[i] - 'A', y = a[i + 1] - 'A';
        k[x][y]++;
        //转换为数字，个数加一
        if (k[x][y] > ma)
            ma = k[x][y];
        //找出现次数最多的
    }
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (k[i][j] == ma)
            {
                printf("%c%c", i + 'A', j + 'A');
                //一找到就输出
                return 0;
            }
        }
    }

    return 0;
}