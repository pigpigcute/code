typedef  int  KeyType;
typedef  struct {                      
  KeyType *elem; /*elem[0]һ�����ڱ��򻺳���*/                       
  int Length;      
}SqList;
���в��Գ���������
#include<stdio.h>
#include<stdlib.h>
typedef  int  KeyType;
typedef  struct {                      
  KeyType *elem; /*elem[0]һ�����ڱ��򻺳���*/                       
  int Length;      
}SqList;
void  CreatSqList(SqList *L);/*�������н������ɲ���ʵ�֣�ϸ�ڲ���*/ 
void  ShellInsert(SqList L,int dk);
void  ShellSort(SqList L);

int main()
{
  SqList L;
  int i;
  CreatSqList(&L);
  ShellSort(L);
  for(i=1;i<=L.Length;i++)
   {        
     printf("%d ",L.elem[i]);
   }
  return 0;
}
void   ShellSort(SqList L)
{
  /*����������dlta[0��t-1]��˳���L��Shell����,����涨��������Ϊ5,3,1*/
   int k;
   int dlta[3]={5,3,1};
   int t=3;
   for(k=0;k<t;++k)
       ShellInsert(L,dlta[k]);
} 
/*��Ĵ��뽫��Ƕ������ */
void  ShellInsert(SqList L,int dk){
    
    for(int i=dk+1;i<=L.Length;i++){//elem[0]���ڱ�
        if(L.elem[i-dk]>L.elem[i]){
            L.elem[0]=L.elem[i-dk];
            L.elem[i-dk]=L.elem[i];
            L.elem[i]=L.elem[0];
            i=dk+1;
        }
    }
}
