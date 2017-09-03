#include<stdio.h>
#include<iostream>

using namespace std;

typedef int ElemType;
typedef int Status;

#define OK 1
#define ERROR 0
#define MAXSIZE 1000

typedef struct
{
	ElemType data;
	int cur;
}Component, StaticLinkList[MAXSIZE];

Status InitList(StaticLinkList space)
{
	for (int i = 0; i < MAXSIZE-1; i++)
	{
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0;
	return OK;
}

int Malloc_SLL(StaticLinkList space)            //返回备用空间链表的下标
{
	int i = space[0].cur;
	if (space[0].cur)
	{
		space[0].cur = space[i].cur;
	}
	return i;
}

int ListLength(StaticLinkList space)
{
	int j = 0;
	int i = space[MAXSIZE - 1].cur;
	while (i)
	{
		i = space[i].cur;
		j++;
	}
	return j;
}

Status ListInsert(StaticLinkList L, int i, ElemType e)
{
	int k = MAXSIZE - 1;
	if (i<1 || i> ListLength(L) + 1) {
		return ERROR;
	}
	int j = Malloc_SLL(L);
	if (j)
	{
		L[j].data = e;
		for (int l = 1; l <= i - 1; l++)
		{
			k = L[k].cur;
		}
		L[j].cur = L[k].cur;
		L[k].cur = j;
		return OK;
	}
	return ERROR;
}

void Free_SLL(StaticLinkList space, int k)        //回收删除的节点
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

Status ListDelete(StaticLinkList L, int i)
{
	if (i<1 || i>ListLength(L))
	{
		return ERROR;
	}
	int k = MAXSIZE - 1;
	int j;
	for (j = 1; j <= i - 1; j++)
	{
		k = L[k].cur;
	}
	j = L[k].cur;
	L[k].cur = L[j].cur;
	Free_SLL(L, j);
	return OK;
}
/*
int main(void)
{
	StaticLinkList space;
	InitList(space);
	//printf("%d\n", Malloc_SLL(space));
	ListInsert(space, 1, 11);
	ListInsert(space, 2, 22);
	ListInsert(space, 3, 33);
	printf("%d  %d\n", space[0].data,space[0].cur);
	printf("%d  %d\n", space[1].data,space[1].cur);
	printf("%d  %d\n", space[2].data,space[2].cur);
	printf("%d  %d\n", space[3].data,space[3].cur);
	ListDelete(space, 2);
	printf("%d\n", space[0].cur);
	return 0;
}
*/