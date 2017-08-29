#include<stdio.h>
#include<iostream>

using namespace std;

#define ERROR 0
#define OK 1

typedef int ElemType;
typedef int Status;

typedef struct Node          //这里的Node不能省略
{
	ElemType data;
	struct Node* next;
}Node;

typedef struct Node* LinkList;

Status GetElem(LinkList L,int i,ElemType *e) {
	LinkList p = L->next;
	int j = 1;
	while (p && j < i) 
	{
		p = p->next;
		j++;
	}
	if (!p || j>i) {
		return ERROR;
	}
	*e = p->data;
	return OK;
}

int main(void)
{
	Node tail = { 3,NULL };
	Node mid2 = { 2,&tail };
	Node mid1 = { 1,&mid2 };
	Node head;
	head.next = &mid1;
	LinkList L = &head;

	int elem = 0;
	GetElem(L, 2, &elem);
	printf("%d\n", elem);


	return 0;
}