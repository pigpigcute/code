#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int weight; //权值
    int parent; //父节点
    int lchild; //左孩子
    int rchild; //右孩子
} HTNode, *HuffmanTree;
typedef char ** HuffmanCode;  //字符指针数组中存储的元素类型

void SelectTwoMin(int upbound, HuffmanTree HT, int &s1, int &s2);
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n);

int main() {
    HuffmanTree ht;
    HuffmanCode hc;

    int n;
    scanf("%d", &n);
    
    int *w = (int *) malloc (n * sizeof(int));
    for(int i = 0; i < n; ++ i)
        scanf("%d", &w[i]);

    HuffmanCoding(ht, hc, w, n);
    
    for (int i = 1; i <= 2 * n - 1; ++ i) {
        printf("%d %d %d %d\n", 
        ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);
    }

    for (int i = 1; i <= n; ++ i)
        printf("%s\n", hc[i]);

    free(w);
    free(ht);
    for (int i = 1; i <= n; ++ i)
        free(hc[i]);
    
    return 0;
}
/* 你的代码将被嵌在这里 */
void SelectTwoMin(int upbound, HuffmanTree HT, int &s1, int &s2)
{
    int a1=0,a2=0;
    int m1=1000,m2=1000;
    for(int i=1;i<=upbound;i++){
        if(HT[i].parent==0&&HT[i].weight<m1){
            m2=m1;
            a2=a1;
            a1=i;
            m1=HT[i].weight;
        }
        else if(HT[i].parent==0&&HT[i].weight<m2){
            a2=i;
            m2=HT[i].weight;
        }
    }
    s1=a1;s2=a2;
}

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n)
{
    int s1=0,s2=0;
    int m=n*2-1;
    HT=(HuffmanTree)malloc(sizeof(HTNode)*(m+1));
    HC = (HuffmanCode)malloc(sizeof(char)*(n+1));
    for(int i=0;i<n;i++){
        HT[i+1].weight=w[i];
    }

    for(int i=1;i<=n;i++){
        HC[i]=(char*)malloc(sizeof(char)*(n+1));
        memset(HC[i],0,sizeof(char)*(n+1));
    }

    for(int i=1;i<=m;i++){
        HT[i].parent=0;
        HT[i].rchild=0;
        HT[i].lchild=0;
    }

    for(int i=n+1;i<=m;i++){
        SelectTwoMin(i-1,HT,s1,s2);
        HT[i].lchild=s1;
        HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
        HT[s1].parent=HT[s2].parent=i;
    }

    for(int i=1;i<=n;i++){
        int start=n-1;
        char *bm = new char[n];
        bm[n-1]='\0';
        int x=i;
        int f=HT[i].parent;
        while(f!=0){
            start--;
            if(HT[f].lchild==x){
                bm[start]='0';
            }
            else if(HT[f].rchild==x){
                bm[start]='1';
            }
            x=f;
            f=HT[f].parent;
        }
        HC[i]=new char [n-start];
        strcpy(HC[i],&bm[start]);
    }
}

