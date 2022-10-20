#include<stdio.h>
#include<stdlib.h>
typedef  int  KeyType;
typedef  struct {                      
  KeyType *elem; /*elem[0]一般作哨兵或缓冲区*/                       
  int Length;      
}SqList;
typedef SqList HeapType; 
void  CreatSqListHeapType *L);/*待排序列建立，由裁判实现，细节不表*/ 
void HeapAdjust( HeapType  H, int s, int m);
void HeapSort( HeapType  H);
int main()
{
  HeapType L;
  int i;
  CreatSqList(&L);
  HeapSort(L);
  for(i=1;i<=L.Length;i++)
   {        
     printf("%d ",L.elem[i]);
   }
  return 0;
}
void HeapSort( HeapType  H)
{ /*堆顺序表H进行堆排序*/
  int i; KeyType rc;
  /*建立初始堆*/
  for( i=H.Length/2;i>0; i--)
   {
      HeapAdjust(H, i, H.Length);
   }
  for(i=H.Length;i>1;i--)
   {
      rc=H.elem[1];
      H.elem[1]=H.elem[i]; 
      H.elem[i]=rc;
      HeapAdjust(H, 1, i-1); 
   }
 }
/*你的代码将被嵌在这里 */
void HeapAdjust( HeapType  H, int s, int m){
 KeyType a;
 int i;
 a=H.elem[s];
    for(i=2*s;i<=m;i*=2){
  if(i<m&&H.elem[i]<H.elem[i+1]) ++i; 
        if(a>=H.elem[i]) break;
  H.elem[s]=H.elem[i]; s=i; 
    }
 H.elem[s]=a; 
}
