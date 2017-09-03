#include<stdio.h>
#include<iostream>

using namespace std;

#define MAXSIZE 1000
#define OK 1
#define ERROR 0

typedef int SElemType;
typedef int Status;

typedef struct
{
	SElemType data[MAXSIZE];
	int top;
}SqStack;

Status Push(SqStack* S, SElemType e)
{
	if (S->top == MAXSIZE - 1) {
		return ERROR;
	}
	S->top++;
	S->data[S->top] = e;
	return OK;
}

Status Pop(SqStack *S, SElemType *e)
{
	if (S->top == -1)
	{
		return ERROR;
	}
	*e = S->data[S->top];
	S->top--;
	return OK;
}
/*
int main(void)
{
	SqStack stack;
	stack.top = -1;
	SElemType se1 = 1;
	SElemType se2 = 2;
	Push(&stack, se1);
	Push(&stack, se2);

	SElemType se;
	Pop(&stack, &se);
	printf("%d\n", se);
	Pop(&stack, &se);
	printf("%d\n", se);


	return 0;
}
*/