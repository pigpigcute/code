#include <iostream>
#include <cstdlib>
#define ElemType int
using namespace std;
///������LinkNode������
typedef struct LNode
{//������������Ľṹ��
    ElemType data;
    struct LNode *next;
} LinkNode;
void CreatListF(LinkNode *&L,ElemType a[],int n)
{//��ͷ�巨�ķ�ʽ�����������������ݣ�
    LinkNode *s;
    L=(LinkNode *)malloc(sizeof(LinkNode));//����ͷ���
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
{//������β�巨�����������������ݣ�
    LinkNode *s,*r;
    L=(LinkNode *)malloc(sizeof(LinkNode));//����ͷ���
    r=L;//rָ����Զָ��ǰ��β���
    for(int i=0; i<n; i++)
    {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=NULL;//β����nextΪ��
}
void InitList(LinkNode *&L)
{//��ʼ������
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next=NULL;
}
void DestroyList(LinkNode *&L)
{//��������
    LinkNode *pre=L,*p=L->next;
    while(p!=NULL)
    {
        //�������ָ��ͬʱ���ƣ�����ڶ���ָ�벻Ϊ�����ͷŵ�һ��ָ��
        free(pre);
        pre=p;
        p=pre->next;
    }
    free(pre);
}
bool ListEmpty(LinkNode *L)
{//�ж������Ƿ�Ϊ��
    return (L->next==NULL);
}
int ListLength(LinkNode *L)
{//��������ĳ��ȣ�����������
    int n=0;
    LinkNode *p=L;//pָ��ͷ��㣬nΪ0��ͷ�������Ϊ0
    while(p->next!=NULL)
    {
        n++;
        p=p->next;//ָ�����
    }
    return n;
}
void DispList(LinkNode *L)
{//�������
    LinkNode *p=L->next;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
bool GetElem(LinkNode *L,int i,ElemType &e)
{//Ѱ�������еĵ�i��ֵ�����ظ�e
    int j=0;
    LinkNode *p=L;
    if(i<=0)
        return false;
    while(j<i&&p!=NULL)
    {
        //����ѭ��ʱ�ҵ����ǵ�i�����
        j++;
        p=p->next;
    }
    if(p==NULL)//�����ڵ�i�����
        return false;
    else
    {
        e=p->data;
        return true;
    }
}
int LocateElem(LinkNode *L,ElemType e)
{//���������е�һ����e��ȵ����
    int i=1;
    LinkNode *p=L->next;
    while(p!=NULL&&p->data!=e)
    {
        p=p->next;
        i++;
    }
    if(p==NULL)//������dataΪe�Ľ��
        return 0;
    else
        return i;
}
bool ListInsert(LinkNode *&L,int i,ElemType e)
{//��������e�������еĵ�i��λ��
    int j=0;
    LinkNode *p=L,*s;
    if(i<=0)
        return false;//i������
    while(j<i-1&&p!=NULL)
    {
        //���ҵ�i-1�����
        j++;
        p=p->next;
    }
    if(p==NULL)//��i-1�����Ϊ�գ�i�����ǿ��ˣ��޷���������
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
{//ɾ����i�����
    int j=0;
    LinkNode *p=L,*q;
    if(i<=0)
        return false;
    while(j<i-1&&p!=NULL)
    {
        //���ҵ�i�����
        j++;
        p=p->next;
    }
    if(p==NULL)
        return false;//�����ڵ�i-1�����
    else
    {
        q=p->next;
        if(q==NULL)
            return false;//�����ڵ�i�����
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
    //CreatListF(s,a,4);//ͷ�巨��ʽ��������
    //DispList(s);
    CreatListR(s,a,4);//β�巨��������
    DispList(s);
    ///�����Ǽ���GetElem����
    /*cout<<"������Ҫ��ѯ�����еڼ���ֵ����";
    cin>>i;
    GetElem(s,i,e);
    cout<<"��"<<i<<"��ֵΪ:"<<e<<endl;*/
    ///�����Ǽ���ListLength����
    /*int l;
    l=ListLength(s);
    cout<<"����ĳ���Ϊ��"<<l<<endl;*/
    ///�����Ǽ���ListInsert����
    /*cout<<"��������Ҫ���������:";
    cin>>e;
    cout<<"��������Ҫ�����λ�ã�";
    cin>>i;
    ListInsert(s,i,e);
    DispList(s);*/
    ///�����Ǽ���LocateElem����
    /*cout<<"��������Ҫ��ѯ��ֵ:";
    cin>>e;
    int l=LocateElem(s,e);
    if(!l)
        cout<<"�����ڸ�ֵ��"<<endl;
    else
        cout<<"��ֵ�ڵ�"<<l<<"λ"<<endl;*/
    ///�����Ǽ���ListDelete����
    /*cout<<"����������Ҫɾ����λ�ã�";
    cin>>i;
    ListDelete(s,i,e);*/
    DestroyList(s);
    DispList(s);

    return 0;
}


