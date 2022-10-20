#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, t, flag;
    string s;

    cin >> n >> m;
    while (n--)
    {
        queue<char> q;
        flag = 1;
        cin >> s;
        t = s.size();
        if (t % 2 == 1)
            flag = 0;
        else
        {
            for (int i = 0; i < t && flag; i++)
            {
                if (s[i] == 'S' && q.size() < m)
                    q.push(s[i]);
                else if (s[i] == 'X' && !s.empty())
                    q.pop();
                else
                    flag = 0;
            }
        }
        if (!q.empty())
            flag = 0;
        if (flag == 0)
            cout << "NO" << endl;
        if (flag == 1)
            cout << "YES" << endl;
    }
}

/* #include <stdio.h>
#define MAX_STR_LEN 100
int main(void){
    int N, M, i, cnt;
    char seq[MAX_STR_LEN];
    scanf("%d%d", &N, &M); //�����������Żس���
    //getchar(); //���߻�������ʣ��Ļس���
    while(N--){
        //gets(seq);
        scanf("%s", seq); //�б�Ҫ��ʽ����һ���ո���߿հ׷�?%s�Զ�����
        cnt = 0;
        i = 0;
        while(seq[i]){
            if(seq[i]=='S'){
                cnt++;
            }
            else if(seq[i]=='X'){
                cnt--;
            }
            if(cnt<0 || cnt>M){
                break;
            }
            i++;
        }
        if(cnt==0){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }

    }

    return 0;
} */