#include <iostream>
#include <cstdlib>
#define ElemType int
using namespace std;
///单链表LinkNode！！！
typedef struct LNode
{//这里是链表结点的结构体
    ElemType data;
    struct LNode *next;
} LinkNode;
void CreatListF(LinkNode *&L,ElemType a[],int n)
{//以头插法的方式创建单链表（带有数据）
    LinkNode *s;
    L=(LinkNode *)malloc(sizeof(LinkNode));//创建头结点
    L->next=NULL;
    for(int i=0; i<n; i++)
    {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=a[i];
        s->next=L->next;
        L->next=s;
    }
}
void CreatListR(LinkNode *&L,ElemType a[],int n)
{//这里是尾插法创建单链表（带有数据）
    LinkNode *s,*r;
    L=(LinkNode *)malloc(sizeof(LinkNode));//创建头结点
    r=L;//r指针永远指向当前的尾结点
    for(int i=0; i<n; i++)
    {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=NULL;//尾结点的next为空
}
void InitList(LinkNode *&L)
{//初始化链表
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next=NULL;
}
void DestroyList(LinkNode *&L)
{//销毁链表
    LinkNode *pre=L,*p=L->next;
    while(p!=NULL)
    {
        //两个标记指针同时后移，如果第二个指针不为空则释放第一个指针
        free(pre);
        pre=p;
        p=pre->next;
    }
    free(pre);
}
bool ListEmpty(LinkNode *L)
{//判断链表是否为空
    return (L->next==NULL);
}
int ListLength(LinkNode *L)
{//计算链表的长度（结点的数量）
    int n=0;
    LinkNode *p=L;//p指向头结点，n为0，头结点的序号为0
    while(p->next!=NULL)
    {
        n++;
        p=p->next;//指针后移
    }
    return n;
}
void DispList(LinkNode *L)
{//输出链表
    LinkNode *p=L->next;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
bool GetElem(LinkNode *L,int i,ElemType &e)
{//寻找链表中的第i个值，返回给e
    int j=0;
    LinkNode *p=L;
    if(i<=0)
        return false;
    while(j<i&&p!=NULL)
    {
        //跳出循环时找到的是第i个结点
        j++;
        p=p->next;
    }
    if(p==NULL)//不存在第i个结点
        return false;
    else
    {
        e=p->data;
        return true;
    }
}
int LocateElem(LinkNode *L,ElemType e)
{//查找链表中第一个与e相等的序号
    int i=1;
    LinkNode *p=L->next;
    while(p!=NULL&&p->data!=e)
    {
        p=p->next;
        i++;
    }
    if(p==NULL)//不存在data为e的结点
        return 0;
    else
        return i;
}
bool ListInsert(LinkNode *&L,int i,ElemType e)
{//插入数据e到链表中的第i个位置
    int j=0;
    LinkNode *p=L,*s;
    if(i<=0)
        return false;//i无意义
    while(j<i-1&&p!=NULL)
    {
        //查找第i-1个结点
        j++;
        p=p->next;
    }
    if(p==NULL)//第i-1个结点为空，i个更是空了，无法插入数据
        return false;
    else
    {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=e;
        s->next=p->next;
        p->next=s;
        return true;
    }
}
bool ListDelete(LinkNode *&L,int i,ElemType &e)
{//删除第i个结点
    int j=0;
    LinkNode *p=L,*q;
    if(i<=0)
        return false;
    while(j<i-1&&p!=NULL)
    {
        //查找第i个结点
        j++;
        p=p->next;
    }
    if(p==NULL)
        return false;//不存在第i-1个结点
    else
    {
        q=p->next;
        if(q==NULL)
            return false;//不存在第i个结点
        e=q->data;
        p->next=q->next;
        free(q);
        return true;
    }
}
int main()
{
    LinkNode *s;
    ElemType e;
    int i;
    int a[4]= {2,3,1,5};
    //CreatListF(s,a,4);//头插法方式创建链表
    //DispList(s);
    CreatListR(s,a,4);//尾插法创建链表
    DispList(s);
    ///以下是检验GetElem（）
    /*cout<<"请问你要查询链表中第几个值？：";
    cin>>i;
    GetElem(s,i,e);
    cout<<"第"<<i<<"个值为:"<<e<<endl;*/
    ///以下是检验ListLength（）
    /*int l;
    l=ListLength(s);
    cout<<"链表的长度为："<<l<<endl;*/
    ///以下是检验ListInsert（）
    /*cout<<"请输入您要插入的数据:";
    cin>>e;
    cout<<"请输入您要插入的位置：";
    cin>>i;
    ListInsert(s,i,e);
    DispList(s);*/
    ///以下是检验LocateElem（）
    /*cout<<"请输入您要查询的值:";
    cin>>e;
    int l=LocateElem(s,e);
    if(!l)
        cout<<"不存在该值！"<<endl;
    else
        cout<<"该值在第"<<l<<"位"<<endl;*/
    ///以下是检验ListDelete（）
    /*cout<<"请输入您所要删除的位置：";
    cin>>i;
    ListDelete(s,i,e);*/
    DestroyList(s);
    DispList(s);

    return 0;
}


