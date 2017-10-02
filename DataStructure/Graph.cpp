

#include<stdio.h>
#include<iostream>

using namespace std;

typedef char VertexType;             //顶点数据类型
typedef int EdgeType;               //边上的权值类型
#define MAXVEX 100
#define INFINITY 65535
#define TRUE 1
#define FALSE 0

typedef int Boolean;
Boolean visited[MAXVEX];         //访问标志的数组

/*邻接矩阵*/
typedef struct
{
	VertexType vexs[MAXVEX];               //顶点表
	EdgeType arc[MAXVEX][MAXVEX];         //邻接矩阵表
	int numVertexes, numEdges;            //图中当前的顶点数和边数
}MGraph;

void CreateMGraph(MGraph *G)
{
	int i, j, k, w;
	printf("输入顶点数和边数：\n");
	scanf("%d,%d", &G->numVertexes, &G->numEdges);
	for (i = 0; i < G->numVertexes; i++)              //读入顶点信息，建立顶点表
	{
		scanf(&G->vexs[i]);
	}

	for (i = 0; i < G->numVertexes; i++)              //初始化邻接矩阵
		for (j = 0; j < G->numVertexes; j++) 
		{
			G->arc[i][j] = INFINITY;
		}
	for (k = 0; k < G->numEdges; k++)
	{
		printf("输入边（vi，vj）上的下标i，j和权值w：\n");
		scanf("%d,%d,%d", &i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];                    //无向图，矩阵对称
	}
}

/*邻接表*/
typedef struct EdgeNode    //边表结点 
{
	int adjvex;              //邻接点域，存储该结点对应的下标
	EdgeType weight;         //用于存储权值，对于非网图可以不需要
	struct EdgeNode *next;   //链域，指向下一个邻接点
}EdgeNode;

typedef struct VertexNode      //顶点表结点
{
	VertexType data;          //顶点域，存储顶点信息
	EdgeNode *firstedge;      //边表头指针
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
	printf("输入顶点数和边数：");
	scanf("%d,%d", &G->numEdges, &G->numVertexes);
	for (i = 0; i < G->numVertexes; i++)           //读入顶点信息，建立顶点表
	{
		scanf(&G->adjList[i].data);
		G->adjList[i].firstedge = NULL;
	}

	for (k = 0; k < G->numEdges; k++)
	{
		printf("输入（vi，vj）上的顶点序号：\n");
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

/*邻接矩阵的深度优先遍历*/
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
/*邻接表的深度优先*/
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