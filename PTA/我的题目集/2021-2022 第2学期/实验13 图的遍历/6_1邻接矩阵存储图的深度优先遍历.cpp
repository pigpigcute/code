#include <stdio.h>

typedef enum {false, true} bool;
#define MaxVertexNum 10  /* ��󶥵�����Ϊ10 */
#define INFINITY 65535   /* ����Ϊ˫�ֽ��޷������������ֵ65535*/
typedef int Vertex;      /* �ö����±��ʾ����,Ϊ���� */
typedef int WeightType;  /* �ߵ�Ȩֵ��Ϊ���� */

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;  /* ������ */
    int Ne;  /* ����   */
    WeightType G[MaxVertexNum][MaxVertexNum]; /* �ڽӾ��� */
};
typedef PtrToGNode MGraph; /* ���ڽӾ���洢��ͼ���� */
bool Visited[MaxVertexNum]; /* ����ķ��ʱ�� */

MGraph CreateGraph(); /* ����ͼ���ҽ�Visited��ʼ��Ϊfalse������ʵ�֣�ϸ�ڲ��� */

void Visit( Vertex V )
{
    printf(" %d", V);
}

void DFS( MGraph Graph, Vertex V, void (*Visit)(Vertex) );


int main()
{
    MGraph G;
    Vertex V;

    G = CreateGraph();
    scanf("%d", &V);
    printf("DFS from %d:", V);
    DFS(G, V, Visit);

    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
void DFS( MGraph Graph, Vertex V, void (*Visit)(Vertex) ){
    //cout << vertex[v];
    Visit(V);
    Visited[V] = true;
	for (int j = 0; j < Graph->Nv; j++)
		if (Graph->G[V][j] == 1 && Visited[j] == false) DFS(Graph,j,Visit);
}
