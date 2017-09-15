#include<stdio.h>
#include<iostream>

typedef int QElemType;
typedef int Status;

#define OK 1
#define ERROR 0
#define MAXSIZE 1000

//队列的顺序存储
typedef struct
{
	QElemType data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

Status InitQueue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

Status EnQueue(SqQueue *Q, QElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)       //判断队满
	{
		return ERROR;
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return OK;
}

Status DeQueue(SqQueue *Q, QElemType *e)
{
	if (Q->front == Q->rear)                //判断队空
	{
		return ERROR;
	}
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;

	return OK;
}

//队列的链式存储
typedef struct QNode
{
	QElemType data;
	struct QNode* next;
}QNode,*QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueueList(LinkQueue *Q)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	p->next = NULL;
	Q->front = Q->rear = p;
	return OK;
}

Status EnQueueList(LinkQueue *Q, QElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if (!s)
	{
		exit(OVERFLOW);
	}
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
	return OK;
}

Status DeQueueList(LinkQueue *Q, QElemType *e)
{
	if (Q->front == Q->rear)
	{
		return ERROR;
	}
	QueuePtr p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)
	{
		Q->rear = Q->front;
	}
	free(p);
	return OK;
}

/*
int main(void)
{
	SqQueue queue;
	InitQueue(&queue);
	QElemType e1 = 1;
	QElemType e2 = 2;
	EnQueue(&queue, e1);
	EnQueue(&queue, e2);
	QElemType e;
	DeQueue(&queue, &e);
	printf("%d\n", e);

	LinkQueue lq;
	InitQueueList(&lq);
	QElemType e3 = 3;
	QElemType e4 = 4;
	EnQueueList(&lq, e4);
	EnQueueList(&lq, e3);
	QElemType ee;
	DeQueueList(&lq, &ee);
	printf("%d\n", ee);
	return 0;
}
*/