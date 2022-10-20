#include <stdio.h>
#include <stdlib.h>
typedef struct SNode
{
    int *data;
    int top;
    int maxsize;
} * PtrToSNode;
typedef PtrToSNode stack;
stack CreateStack(int size)
{
    stack st = (stack)malloc(sizeof(struct SNode));
    st->data = (int *)malloc(sizeof(int) * size);
    st->top = -1;
    st->maxsize = size;
    return st;
}
int is_empty(stack s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}
int is_full(stack s)
{
    return s->top == s->maxsize - 1;
}
int push(stack s, int val)
{
    if (is_full(s))
        return 0;
    s->data[++(s->top)] = val;
    return 1;
}
int pop(stack s)
{
    if (is_empty(s))
        return 0;
    else
        return s->data[(s->top)--];
}
//以上为栈的实玄1�7
int n, limit;
int box_seq[1000010];        //按填装顺序记录盒子编叄1�7
int pushing_seq[10010][110]; //记录每次栈空时的压栈顺序
int end[1000010];            //记录朢�终每个编号的盒子中的徽章种类
int main()
{
    scanf("%d%d", &n, &limit);
    for (int i = 1; i <= n; i++)
        scanf("%d", box_seq + i);
    stack st = CreateStack(limit);
    for (int i = 1; i <= n / limit; i++)
        for (int j = 1; j <= limit; j++)
            scanf("%d", pushing_seq[i] + j);
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        if (is_empty(st))
        {
            for (int j = 1; j <= limit; j++)
            {
                push(st, pushing_seq[cnt][j]);
            }
            cnt++;
        }
        end[box_seq[i]] = pop(st);
    }

    int q;
    scanf("%d", &q);
    while (q--)
    {
        int now;
        scanf("%d", &now);
        if (!end[now])
            printf("Wrong Number\n"); //由于徽章种类丄1�71-9的数字，而end数组初始化为兄1�70，则若最终为0则说明无编号为该数的盒子
        else
            printf("%d\n", end[now]);
    }

    return 0;
}