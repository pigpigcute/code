#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;        // n→有几个字符串，k→扫描几次
    int i, j;        //用于循环和数组下标
    char a[100][11]; //用于存储字符串
    char temp[11];
    scanf("%d%d", &n, &k); //提供输入n、k的功能
    getchar();
    for (i = 0; i < n; i++) //提供输入字符串的功能
        scanf("%s", a[i]);

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(a[j], a[j + 1]) > 0)
            {
                strcpy(temp, a[j]);
                strcpy(a[j], a[j + 1]);
                strcpy(a[j + 1], temp);
            }
        }
    }

    for (i = 0; i < n; i++)
        printf("%s\n", a[i]);
    return 0;
}
