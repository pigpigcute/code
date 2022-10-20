#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct stu
{
    int data;
    struct stu *next;
} node;

node *listcreat(int n) //链表创建，返回链表头
{
    node *r, *s, *l;
    l = (node *)malloc(sizeof(node));
    l->next = NULL;
    r = l;
    for (int i = 0; i < n; i++)
    {
        s = (node *)malloc(sizeof(node));
        cin >> s->data;
        r->next = s;
        r = r->next;
    }
    r->next = NULL;
    return l;
}

void listinsert(node *head, int m) //插入m
{
    node *r, *s, *p;
    r = head;
    s = (node *)malloc(sizeof(node));
    s->data = m;
    s->next = NULL;

    while (r->data < m)
    {
        p = r;
        r = r->next;
    }
    if (r->data == m)
        return;
    else
    {
        p->next = s;
        s->next = r;
    }
}

void hake(node *head) //输出
{
    node *t;
    t = head->next;
    while (t->next)
    {
        cout << t->data << " ";
        t = t->next;
    }
    cout<<t->data;
}

int main()
{
    int n, m;
    node *head;
    head = (node *)malloc(sizeof(node));
    head = NULL;
    cin >> n;
    head = listcreat(n);
    cin >> m;
    listinsert(head, m);
    hake(head);
}