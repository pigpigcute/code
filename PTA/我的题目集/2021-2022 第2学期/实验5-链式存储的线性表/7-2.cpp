#include <iostream>
using namespace std;

typedef struct node *List;

struct node
{
    int date;
    struct node *next;
};

List listcreate();
List compare(List L1, List L2);
void output(List L);


int main()
{
    List list1 = listcreate();
    List list2 = listcreate();
    List list;
    list = compare(list1, list2);
    output(list);
    return 0;
}



List listcreate()
{
    List L, s, r;
    L = (List)malloc(sizeof(List));

    L->next = NULL;
    r = L;
    int n;
    cin >> n;
    while (n != -1)
    {
        s = (List)malloc(sizeof(List));
        s->date = n;
        s->next = NULL;
        r->next = s;
        r = s;
        cin >> n;
    }
    return L;
}

List compare(List L1, List L2)
{
    List L, r, p1, p2, s;
    L = (List)malloc(sizeof(List));
    L->next = NULL;
    r = L;
    p1 = L1->next;
    p2 = L2->next;
    while (p1 && p2)
    {
        if (p1->date == p2->date)
        {
            s = (List)malloc(sizeof(List));
            s->date = p1->date;
            s->next = NULL;
            r->next = s;
            r = s;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->date < p2->date)
            p1 = p1->next;
        else
            p2 = p2->next;
    }
    return L;
}

void output(List L)
{
    List p;
    p = L->next;
    if (!p)
    {
        cout << "NULL";
        return;
    }
    int t = 0;

    while (p)
    {
        if (t != 0)
            cout << " ";
        cout << p->date;
        p = p->next;
        t = 1;
    }
}