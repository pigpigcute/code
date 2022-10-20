#include <stdio.h>

int main()
{
    int t, m, n;
    char a[2000];
    scanf("%d %d", &n, &m);
    while (n--)
    {
        scanf("%s", a);
        t=0;
        for (int i = 0; a[i] != '\0'; i++)
        {
            
            if (a[i] == 'e' && a[i + 1] == 'a' && a[i + 2] == 's' && a[i + 3] == 'y')
            {
                t = 1;
            }
            if (a[i] == 'q' && a[i + 1] == 'i' && a[i + 2] == 'a' && a[i + 3] == 'n' && a[i + 4] == 'd' && a[i + 5] == 'a' && a[i + 6] == 'o')
            {
                t = 1;
            }
        }
        if (t == 0)
        {
            m--;
        }
        if (m == -1)
        {
            printf("%s", a);
            break;
        }
    }
    if(n==0){
        printf("Wo AK le");
    }

    return 0;
}