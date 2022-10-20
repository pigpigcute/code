#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct ANode //包含用于记录答案的数组和该数组元素个数的结构体
{
    char data[1000010]; //记录答案
    int back;           //记录答案数量
};
typedef struct ANode *ans_vector;
ans_vector CreateAns_Vector() //在堆内存申请答案记录结构体空间
{
    ans_vector Av = (ans_vector)malloc(sizeof(ANode));
    Av->back = 0;
    return Av;
}

typedef struct SNode *PtrToSNode;
struct SNode //栈结构体
{
    char *data;
    int Top;
    int MaxSize;
};
typedef PtrToSNode stack;
stack CreateStack(int Maxs) //在堆区申请栈空间
{
    stack S = (stack)malloc(sizeof(struct SNode));
    S->data = (char *)malloc(Maxs * sizeof(char));
    S->MaxSize = Maxs;
    S->Top = -1;
    return S;
}

bool is_full(stack s)
{
    return (s->Top == (s->MaxSize) - 1);
}
bool is_empty(stack s)
{
    return (s->Top) == -1;
}

bool pop_to_ans(stack s, ans_vector av)
{
    if (is_empty(s))
        return false; //如果栈空则无操作
    else
    {
        av->data[(av->back)++] = s->data[(s->Top)--];
        return true;
    }
}

void push(stack s, char x, ans_vector av)
{
    if (is_full(s)) //如果栈满则先将栈顶元素出栈放入答案中，在将新元素压栈
        pop_to_ans(s, av);
    s->data[++(s->Top)] = x;
}
int n, m, limit;
char shelve[110][1010]; //每条轨道
int shelve_pos[110];    //每条轨道当前处于头部的元素的下标
int main()
{
    scanf("%d%d%d", &n, &m, &limit);
    getchar();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%c", shelve[i] + j);
        }
        getchar();
    }
    stack s = CreateStack(limit);       //建立栈
    ans_vector av = CreateAns_Vector(); //建立记录答案的结构体
    int op;
    while (1)
    {
        scanf("%d", &op);
        if (op == -1)
            break; //若当前输入的操作是-1则跳出循环
        if (op == 0)
            pop_to_ans(s, av);
        else
        {
            op--; //轨道序号-1==对应下标
            if (shelve_pos[op] == m)
                continue;                              //若当前轨道的头部指针以指向下标m，则说明当前轨道上的所有元素已全部弹出，无操作
            push(s, shelve[op][shelve_pos[op]++], av); //否则将当前头部元素压入栈中
        }
    }
    for (int i = 0; i < (av->back); i++) //将答案数组中所有元素输出
    {
        printf("%c", av->data[i]);
    }

    return 0;
}