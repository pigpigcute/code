#include<bits/stdc++.h>
using namespace std;

int IsPrime(int N) //判断
{
    if (N == 0 || N == 1)
    {
        return 0;
    }
    if (N > 2) //判断是否是素数
    {
        int i;
        for (i = 2; i <= sqrt(N) + 1; i++)
            if (N % i == 0)
                return 0;
    }
    return 1;
}

int NextPrime(int N)
{
    int i = N + 1; //进行+1
    while (1)
    {
        if (IsPrime(i)) //判断是否是素数
            return i;
        i++; //加1
    }
    return i;
}

int main()
{
    int M, N;
    scanf("%d %d", &M, &N);
    if (!IsPrime(M))
        M = NextPrime(M);
    int visit[M];
    memset(visit, 0, sizeof(visit));
    int pos[N];
    int i, x;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &x);
        int key = x % M;
        int d, temp = key;
        for (d = 0; d < M; d++)
        {
            key = temp + d * d;
            if (!visit[key % M])
            {
                visit[key % M] = 1;
                pos[i] = key % M;
                break;
            }
        }
        if (d == M)
            pos[i] = -1;
    }
    for (i = 0; i < N; i++)
    {

        if (pos[i] == -1)
            printf("-");
        else
            printf("%d", pos[i]);

        if (i != N - 1)
            printf(" ");
    }
    return 0;
}

