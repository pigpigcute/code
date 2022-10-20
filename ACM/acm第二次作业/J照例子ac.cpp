#include <bits/stdc++.h>
using namespace std;

#define itn int //防手滑打法QAQ（怪好笑的这个）
int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, 1, -1, 0};
static int sign[52][52]; //标记用数组
int n, m, step;
char a[52][52];

void dfs(int x, int y, int used_x, int used_y, int srart_x, int start_y) // s->开始位置,u->上一个位置
{
    step++;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i]; // x,y的新位置
        if  (used_x == nx && used_y == ny)
            continue;
        if (sign[nx][ny]==1&&a[nx][ny]==a[srart_x][start_y]&&step>=4&&nx==srart_x&&ny==start_y)
        {
            cout<<"Yes";
            exit(0);
        }
        if (nx < 1 || ny < 1 || nx > n || ny > m || sign[nx][ny] == 1||a[nx][ny]!=a[srart_x][start_y])
            continue;
        sign[nx][ny] = 1;
        dfs(nx, ny, x, y, srart_x, start_y);
        step--;
    }
}

int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(sign[i][j]==0)
            {
                sign[i][j]=1;
                step=0;
                dfs(i,j,0,0,i,j);
            }
        }
    }
    cout<<"No";
    return 0;
}