#include <stdio.h>
#include <stdlib.h>
#define M 100
struct node{
    int i,j,v;
};

struct tripletable
{
    struct node S[M];
    int m,n,t;
};

struct tripletable * create()
{    
    int i;
    struct tripletable *head=(struct tripletable *)malloc(sizeof(struct tripletable));
    scanf("%d%d%d",&(head->m),&(head->n),&(head->t));
    for(i=0;i<head->t;i++)
        scanf("%d%d%d",&(head->S[i].i),&(head->S[i].j),&(head->S[i].v));
    return head;
}

void print(struct tripletable * head)
{
    int i;
    for(i=0;i<head->t;i++)
    printf("%d %d %d\n",(head->S[i].i),(head->S[i].j),(head->S[i].v));
}

struct tripletable * trans(struct tripletable *t1);
int main()
{ 
    struct tripletable * head,*t2;
    head=create();
    t2=trans(head);
    print(t2);
    return 0;
}

/* 请在这里填写答案 */
struct tripletable * trans(struct tripletable *t1)
{
    struct tripletable *t3=(struct tripletable *)malloc(sizeof(struct tripletable));
    int p,q,col;
    t3->m=t1->m;t3->n=t1->n;t3->t=t1->t;
   // if(t3->t){
        q=0;
        for(col=0;col<t1->n;col++)
        {
            for(p=0;p<t1->t;p++)
            {
                if(t1->S[p].j==col){
                    t3->S[q].i=t1->S[p].j;
                    t3->S[q].j=t1->S[p].i;
                    t3->S[q].v=t1->S[p].v;
                    q++;
                }
            }
        }
    //}
    return t3;
}
