#include<stdio.h>
#include<iostream>
#include<time.h>

using namespace std;

#define ERROR 0
#define OK 1

typedef int ElemType;
typedef int Status;

typedef struct Node          //�����Node����ʡ��
{
	ElemType data;
	struct Node* next;
}Node;

typedef struct Node* LinkList;

void CreateListHead(LinkList* L, int n)             //��ͷ���뷨����һ������
{
	LinkList p;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for (int i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}

}

void CreateListTail(LinkList *L, int n)                //��β���뷨����һ���±�
{
	LinkList p, r;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for (int i = 0; i < n; i++)
	{
		p = (Node *)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

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

Status ListInsert(LinkList* L, int i, ElemType e)
{
	LinkList p,s;
	p = *L;
	int j = 1;
	while (p && j < i)                  //ʵ����Ѱ�ҵ��ǵ�i-1�����
	{
		p = p->next;
		j++;
	}
	if (!p || j>i) 
	{
		return ERROR;
	}
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;

//	Node w;
//	w.data = e;
//	w.next = p->next;
//	p->next = &w;

	return OK;

}

Status ListDelete(LinkList *L, int i, ElemType *e)
{
	LinkList p, q;
	p = *L;
	int j = 1;
	while (p->next && j < i)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j>i)
	{
		return ERROR;
	}
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}

Status ClearList(LinkList* L)
{
	LinkList p, q;
	p = (*L)->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}
/*
int main(void)
{
	Node tail = { 3,NULL };
	Node secondnode = { 2,&tail };
	Node firstnode = { 1,&secondnode };
	Node head;
	head.next = &firstnode;
	LinkList L = &head;

	int elem = 0;
	GetElem(L, 2, &elem);
	printf("%d\n", elem);
	printf("insert the 23 in the second node\n");
	ListInsert(&L, 2, 23);
	GetElem(L, 2, &elem);
	printf("%d\n", elem);
	ListDelete(&L, 2, &elem);
	GetElem(L, 2, &elem);
	printf("%d\n", elem);
	

	return 0;
}
*/