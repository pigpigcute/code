#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();
struct ListNode *deleteeven(struct ListNode *head);
void printlist(struct ListNode *head)
{
    struct ListNode *p = head;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode *head;

    head = createlist();
    head = deleteeven(head);
    printlist(head);

    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode *createlist()
{
    struct ListNode *head, *P, *q;
    int t;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next = NULL;
    q = head;
    while (1)
    {
        scanf("%d", &t);
        if (t == -1)
        {
            return head;
        }
        P = (struct ListNode *)malloc(sizeof(struct ListNode));
        P->data = t;
        P->next = NULL;
        q->next = P;
        q = q->next;
    }
}
struct ListNode *deleteeven(struct ListNode *head)
{
    struct ListNode *t, *p;
    t = head;
    p = t->next;
    while (p)
    {
        if (p->data % 2 == 0)
        {
            t->next = p->next;
            p = t->next;
        }
        else
        {
            t = t->next;
            p = t->next;
        }
    }
    return head->next;
}