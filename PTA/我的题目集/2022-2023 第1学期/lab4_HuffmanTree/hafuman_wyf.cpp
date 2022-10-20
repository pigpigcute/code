#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int weight;
    int parent;
    int lchild;
    int rchild;
} HTNode, *HuffmanTree;
typedef char ** HuffmanCode;

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


    
    return 0;
}

void SelectTwoMin(int upbound, HuffmanTree HT, int &s1, int &s2){
	s1 = s2 = 0;
	int i;int min1 =0 ,min2 = 0;int t;
	for ( int j = 1; j <=upbound;j++){
		if (HT[j].parent == 0) {
			min1 = j;
			break;
		}
	}
	i = min1+1;
	while ( i <= upbound){
		if (HT[i].weight<HT[min1].weight && HT[i].parent == 0 ) {
			min1 = i;	
		}
		i++;
	}
	for ( int j = 1; j <=upbound;j++){
		if (HT[j].parent == 0 && j != min1) {
			min2 = j;
			break;
		}
	}
	i = min2+1;
	while ( i <= upbound){
		if (HT[i].weight<HT[min2].weight && HT[i].parent == 0 && i != min1) {
			min2 = i;	
		}
		i++;
	}
	if (min1 < min2 ) {
		s1 = min1;
		s2 = min2;
	}
	else {
		s1 = min2;
		s2 = min1;
	}

}

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n){
	int m = n;int f;
    HT = (HuffmanTree) malloc ((2*n) * sizeof(HTNode));
    HC = (HuffmanCode) malloc ((n+1) * sizeof(char*));
    int s1,s2;
    for( int i=1;i <=2*n-1;i++){
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    for( int i=1;i <=n;i++){
        HT[i].weight = w[i-1];
    }
    int x = 2*n-1;
    n=n+1;
    while ( n <= x){
    	SelectTwoMin(n-1,HT,s1,s2);
			HT[n].weight = HT[s1].weight + HT[s2].weight;
    		HT[s1].parent = HT[s2].parent = n;
    		HT[n].lchild = s1;
    		HT[n].rchild = s2;
    	n++;
	}
	char* cd=(char *)malloc( m*sizeof(char));
	cd[m-1]='\0';int c;int start;
	for (int i=1;i<=m;++i){
		start=m-1;c=i;f=HT[i].parent;
		while (f!=0){
			--start;
			if (HT[f].lchild==c) cd[start]='0';
			else cd[start]='1';
			c=f;f=HT[f].parent;
		}
		HC[i]=(char*)malloc((m-start)*sizeof(char));
		strcpy(HC[i],&cd[start]);
	}

}


