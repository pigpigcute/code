#include <bits/stdc++.h>
using namespace std;

#define itn int //防手滑打法QAQ（怪好笑的这个）
int dx[5] = {-1, 0, 0, 1};
int dy[5] = {0, 1, -1, 0};
int sign[52][52]; //标记用数组
int n, m;
int step;
char b;
char a[52][52];

void dfs(int x, int y, int start_x, int start_y, int used_x, int used_y) // s->开始位置,u->上一个位置
{
    step++;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i]; // x,y的新位置
        if (nx == used_x && ny == used_y)
            continue;
        if (step >= 4 && sign[nx][ny] == 1 && a[nx][ny] == a[start_x][start_y])
        {
            cout << "Yes";
            exit(0);
        }
        if (nx <= 0 || ny <= 0 || nx > n || ny > m || a[nx][ny] != a[start_x][start_y] || sign[nx][ny] == 1)
            continue;
        sign[nx][ny] = 1;
        dfs(nx, ny, start_x, start_y, x, y);
        step--;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (sign[i][j] == 0)
            {
                sign[i][j] = 1;
                step = 0;
                dfs(i, j, i, j, 0, 0);
            }
    cout << "No";
    return 0;
}