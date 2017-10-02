

#include<stdio.h>
#include<iostream>

using namespace std;

typedef char VertexType;             //������������
typedef int EdgeType;               //���ϵ�Ȩֵ����
#define MAXVEX 100
#define INFINITY 65535
#define TRUE 1
#define FALSE 0

typedef int Boolean;
Boolean visited[MAXVEX];         //���ʱ�־������

/*�ڽӾ���*/
typedef struct
{
	VertexType vexs[MAXVEX];               //�����
	EdgeType arc[MAXVEX][MAXVEX];         //�ڽӾ����
	int numVertexes, numEdges;            //ͼ�е�ǰ�Ķ������ͱ���
}MGraph;

void CreateMGraph(MGraph *G)
{
	int i, j, k, w;
	printf("���붥�����ͱ�����\n");
	scanf("%d,%d", &G->numVertexes, &G->numEdges);
	for (i = 0; i < G->numVertexes; i++)              //���붥����Ϣ�����������
	{
		scanf(&G->vexs[i]);
	}

	for (i = 0; i < G->numVertexes; i++)              //��ʼ���ڽӾ���
		for (j = 0; j < G->numVertexes; j++) 
		{
			G->arc[i][j] = INFINITY;
		}
	for (k = 0; k < G->numEdges; k++)
	{
		printf("����ߣ�vi��vj���ϵ��±�i��j��Ȩֵw��\n");
		scanf("%d,%d,%d", &i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];                    //����ͼ������Գ�
	}
}

/*�ڽӱ�*/
typedef struct EdgeNode    //�߱��� 
{
	int adjvex;              //�ڽӵ��򣬴洢�ý���Ӧ���±�
	EdgeType weight;         //���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ
	struct EdgeNode *next;   //����ָ����һ���ڽӵ�
}EdgeNode;

typedef struct VertexNode      //�������
{
	VertexType data;          //�����򣬴洢������Ϣ
	EdgeNode *firstedge;      //�߱�ͷָ��
}VertexNode,AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;
}GraphAdjList;

void CreateALGraph(GraphAdjList* G)
{
	int i, j, k;
	EdgeNode *e;
	printf("���붥�����ͱ�����");
	scanf("%d,%d", &G->numEdges, &G->numVertexes);
	for (i = 0; i < G->numVertexes; i++)           //���붥����Ϣ�����������
	{
		scanf(&G->adjList[i].data);
		G->adjList[i].firstedge = NULL;
	}

	for (k = 0; k < G->numEdges; k++)
	{
		printf("���루vi��vj���ϵĶ�����ţ�\n");
		scanf("%d,%d", &i, &j);
		
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex = j;
		e->next = G->adjList[i].firstedge;
		G->adjList[i].firstedge = e;

		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex = i;
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;
	}

}

/*�ڽӾ����������ȱ���*/
void DFS(MGraph G, int i)
{
	int j;
	visited[i] = TRUE;
	printf("%c", G.vexs[i]);
	for (j = 0; j < G.numVertexes; j++)
	{
		if (G.arc[i][j] == 1 && !visited[j])
		{
			DFS(G, j);
		}
	}
}
void DFSTraverse(MGraph G)
{
	int i;
	for (i = 0; i < G.numVertexes; i++)
	{
		visited[i] = False;
	}
	for (i = 0; i < G.numVertexes; i++)
	{
		if (!visited[i])
			DFS(G, i);
	}
}
/*�ڽӱ���������*/
void DFSAL(GraphAdjList GL, int i)
{
	EdgeNode *p;
	visited[i] = TRUE;
	printf("%c", GL.adjList[i].data);
	p = GL.adjList[i].firstedge;
	while (p)
	{
		if (!visited[p->adjvex])
			DFSAL(GL, p->adjvex);
		p = p->next;
	}

}
void DFSALTraverse(GraphAdjList GL)
{
	int i;
	for (i = 0; i < GL.numVertexes; i++)
	{
		visited[i] = FALSE;
	}
	for (i = 0; i < GL.numVertexes; i++)
	{
		if (!visited[i])
			DFSAL(GL, i);
	}
}
/*
int main(void)
{
	MGraph G;
	CreateMGraph(&G);
	DFSTraverse(G);

	return 0;
}
*/