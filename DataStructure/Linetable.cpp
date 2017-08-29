#include<stdio.h>
#include<iostream>

using namespace std;

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct {
	ElemType data[MAXSIZE];
	int length;
}SqList;

Status GetElem(SqList L, int i, ElemType* e)
{
	if (L.length == 0 || i<1 || i>L.length) {
		return ERROR;
	}
	*e = L.data[i - 1];
	return OK;
}

Status ListInsert(SqList *L, int i, ElemType e)
{
	if (L->length == MAXSIZE)
	{
		return ERROR;
	}
	if (i<1 || i> L->length + 1)
	{
		return ERROR;
	}
	if (i <= L->length)
	{
		for (int k = L->length - 1; k >= i; k--) {
			L->data[k + 1] = L->data[k];
		}
	}
	L->data[i - 1] = e;
	L->length++;
	return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e) 
{
	if (L->length == 0) 
	{
		return ERROR;
	}
	if (i<1 || i>L->length) 
	{
		return ERROR;
	}
	*e = L->data[i - 1];
	if (i < L->length) 
	{
		for (int k = i; k < L->length; k++) 
		{
			L->data[k - 1] = L->data[k];
		}
	}
	L->length--;
	return OK;
}
int main() 
{
	SqList L = { {1,2,3}, 3 };
	ElemType elem=0 ;
	Status s = GetElem(L, 2, &elem);
	printf("%d\n", elem);
	ListInsert(&L, 3, 12);
	printf("%d\n", L.data[2]);
	return 0;
}
