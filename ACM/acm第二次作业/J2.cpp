#include <bits/stdc++.h>
using namespace std;

int n, m, step, sign[52][52], dx[4] = {-1, 0, 0, 1}, dy[4] = {0, 1, -1, 0};
int used_x, used_y, start_x, start_y;
char a[52][52];

void dfs(int x, int y)
{
    step++;
    int nx, ny;
    for (int i = 0; i < 4; i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx == used_x && ny == used_y)
            continue;
        if (nx == start_x && ny == start_y && step >= 4 && sign[nx][ny] == 1 && a[nx][ny] == a[start_x][start_y])
        {
            cout << "Yes";
            exit(0);
        }
        if (nx <= 0 || ny <= 0 || nx > n || ny > m || sign[nx][ny] == 1 || a[nx][ny] != a[start_x][start_y])
            continue;
        used_x = x;
        used_y = y;
        sign[nx][ny] = 1;
        dfs(nx, ny);
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
        {
            if (sign[i][j] == 0)
            {
                step = 0;
                used_x = i;
                used_y = j;
                start_x = i;
                start_y = j;
                dfs(i, j);
            }
        }
    cout << "No";
    return 0;
}