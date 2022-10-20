#include <stdio.h>
#include <stdlib.h>

#define MAXN 10

int Height_of_BST(int preorder[], int N);

int main()
{
    int preorder[MAXN], N, i;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &preorder[i]);
    printf("%d\n", Height_of_BST(preorder, N));

    return 0;
}

/* Your function will be put here */
int Height_of_BST(int preorder[], int N)
{
    if (N)
    {
        int T;
        for (T = 0; T < N; T++)
        {
            if (preorder[T] > preorder[0])
                break;
        }

        int m = Height_of_BST(preorder + 1, T - 1);
        int n = Height_of_BST(preorder + T, N - T);
        if (m < n)
            return n + 1;
        else
            return m + 1;
    }
    return -1;
}
