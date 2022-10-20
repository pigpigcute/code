#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); /*����ʵ�֣�ϸ�ڲ���*/
struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2);
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
    struct ListNode *list1, *list2;

    list1 = createlist();
    list2 = createlist();
    list1 = mergelists(list1, list2);
    printlist(list1);

    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *s, *head = NULL, *tail = NULL;
    while (1)
    {
        if (list1 == NULL || list2 == NULL)
            break;
        s = (struct ListNode *)malloc(sizeof(struct ListNode));
        if ((list1->data) > (list2->data))
        {
            s->data = list2->data;
            s->next = NULL;
            if (head == NULL)
            {
                head = s;
            }
            else
            {
                tail->next = s;
            }
            tail = s;
            list2 = list2->next;
        }
        else
        {
            s->data = list1->data;
            s->next = NULL;
            if (head == NULL)
            {
                head = s;
            }
            else
            {
                tail->next = s;
            }
            tail = s;
            list1 = list1->next;
        }
    }
    if (list1 != NULL)
        tail->next = list1;
    if (list2 != NULL)
        tail->next = list2;
    return head;
}
