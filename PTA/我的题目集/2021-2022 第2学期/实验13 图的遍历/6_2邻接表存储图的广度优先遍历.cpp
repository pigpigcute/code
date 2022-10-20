#include <stdio.h>

typedef enum {false, true} bool;
#define MaxVertexNum 10   /* ��󶥵�����Ϊ10 */
typedef int Vertex;       /* �ö����±��ʾ����,Ϊ���� */

/* �ڽӵ�Ķ��� */
typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    Vertex AdjV;        /* �ڽӵ��±� */
    PtrToAdjVNode Next; /* ָ����һ���ڽӵ��ָ�� */
};

/* �����ͷ���Ķ��� */
typedef struct Vnode{
    PtrToAdjVNode FirstEdge; /* �߱�ͷָ�� */
} AdjList[MaxVertexNum];     /* AdjList���ڽӱ����� */

/* ͼ���Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;     /* ������ */
    int Ne;     /* ����   */
    AdjList G;  /* �ڽӱ� */
};
typedef PtrToGNode LGraph; /* ���ڽӱ�ʽ�洢��ͼ���� */

bool Visited[MaxVertexNum]; /* ����ķ��ʱ�� */

LGraph CreateGraph(); /* ����ͼ���ҽ�Visited��ʼ��Ϊfalse������ʵ�֣�ϸ�ڲ��� */

void Visit( Vertex V )
{
    printf(" %d", V);
}

void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) );

int main()
{
    LGraph G;
    Vertex S;

    G = CreateGraph();
    scanf("%d", &S);
    printf("BFS from %d:", S);
    BFS(G, S, Visit);

    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) ){
	Visit(S);
	Visited[S] = true;
	Vertex queue[105];//����ģ�����
	int front = 0,rear = 0;
	queue[rear++] = S; 
	PtrToAdjVNode p;
	while(front<rear){//���в�Ϊ��
		Vertex x = queue[front];//���� 
		front++;
		p = Graph->G[x].FirstEdge;//�ҵ��߱�ͷָ�� 
		while(p){
			Vertex v = p->AdjV;
			if(!Visited[v]){
				Visit(v);
				Visited[v] = true;
				queue[rear++] = v;//��� 
			}
			p = p->Next;
		} 
	}
}
