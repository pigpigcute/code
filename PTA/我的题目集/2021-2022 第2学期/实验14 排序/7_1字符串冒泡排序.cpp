#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;        // n���м����ַ�����k��ɨ�輸��
    int i, j;        //����ѭ���������±�
    char a[100][11]; //���ڴ洢�ַ���
    char temp[11];
    scanf("%d%d", &n, &k); //�ṩ����n��k�Ĺ���
    getchar();
    for (i = 0; i < n; i++) //�ṩ�����ַ����Ĺ���
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
