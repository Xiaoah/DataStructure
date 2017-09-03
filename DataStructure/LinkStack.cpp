#include<stdio.h>
#include<iostream>

using namespace std;
typedef int SElemType;
typedef int Status;

#define OK 1
#define ERROR 0


typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;
	int count;
}LinkStack;

Status LinkStackInit(LinkStack* LStack)
{
	LStack->top = NULL;
	LStack->count = 0;
	return OK;
}

Status Push(LinkStack *S, SElemType e)
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s->data = e;
	s->next = S->top;
	S->top = s;
	S->count++;
	return OK;
}

Status Pop(LinkStack *S, SElemType *e)
{
	LinkStackPtr p;
	if (S->count == 0)
	{
		return ERROR;
	}
	*e = S->top->data;
	p = S->top;
	S->top = S->top->next;
	free(p);
	S->count--;
	return OK;
}
/*
int main(void)
{
	LinkStack LStack;
	LinkStackInit(&LStack);
	Push(&LStack, 1);
	Push(&LStack, 2);
	SElemType e;
	Pop(&LStack, &e);
	printf("%d\n", e);
	Pop(&LStack, &e);
	printf("%d\n", e);
	return 0;
}
*/