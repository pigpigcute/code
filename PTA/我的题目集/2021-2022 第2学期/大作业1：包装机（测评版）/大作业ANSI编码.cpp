#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct ANode //�������ڼ�¼�𰸵�����͸�����Ԫ�ظ����Ľṹ��
{
    char data[1000010]; //��¼��
    int back;           //��¼������
};
typedef struct ANode *ans_vector;
ans_vector CreateAns_Vector() //�ڶ��ڴ�����𰸼�¼�ṹ��ռ�
{
    ans_vector Av = (ans_vector)malloc(sizeof(ANode));
    Av->back = 0;
    return Av;
}

typedef struct SNode *PtrToSNode;
struct SNode //ջ�ṹ��
{
    char *data;
    int Top;
    int MaxSize;
};
typedef PtrToSNode stack;
stack CreateStack(int Maxs) //�ڶ�������ջ�ռ�
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
        return false; //���ջ�����޲���
    else
    {
        av->data[(av->back)++] = s->data[(s->Top)--];
        return true;
    }
}

void push(stack s, char x, ans_vector av)
{
    if (is_full(s)) //���ջ�����Ƚ�ջ��Ԫ�س�ջ������У��ڽ���Ԫ��ѹջ
        pop_to_ans(s, av);
    s->data[++(s->Top)] = x;
}
int n, m, limit;
char shelve[110][1010]; //ÿ�����
int shelve_pos[110];    //ÿ�������ǰ����ͷ����Ԫ�ص��±�
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
    stack s = CreateStack(limit);       //����ջ
    ans_vector av = CreateAns_Vector(); //������¼�𰸵Ľṹ��
    int op;
    while (1)
    {
        scanf("%d", &op);
        if (op == -1)
            break; //����ǰ����Ĳ�����-1������ѭ��
        if (op == 0)
            pop_to_ans(s, av);
        else
        {
            op--; //������-1==��Ӧ�±�
            if (shelve_pos[op] == m)
                continue;                              //����ǰ�����ͷ��ָ����ָ���±�m����˵����ǰ����ϵ�����Ԫ����ȫ���������޲���
            push(s, shelve[op][shelve_pos[op]++], av); //���򽫵�ǰͷ��Ԫ��ѹ��ջ��
        }
    }
    for (int i = 0; i < (av->back); i++) //��������������Ԫ�����
    {
        printf("%c", av->data[i]);
    }

    return 0;
}