#include<stdio.h>
#include<iostream>

using namespace std;
typedef int Status;

#define OK 1
#define ERROR 0

typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTnode, *BiTree;

Status SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
	if(!T)
	{
		*p = f;
		return ERROR;
	}
	else if (key == T->data)
	{
		*p = T;
		return OK;
	}
	else if (key < T->data)
		return SearchBST(T->lchild, key, T, p);
	else
		return SearchBST(T->rchild, key, T, p);
}

Status InsertBST(BiTree *T, int key)
{
	BiTree p, s;
	if (!SearchBST(*T, key, NULL, &p)) {
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p)
		{
			*T = s;
		}
		else if (key < p->data)
			p->lchild = s;
		else
			p->rchild = s;
		return OK;
	}
	else
		return ERROR;
}

Status DeleteBST(BiTree *T, int key) {
	if (!*T)
	{
		return ERROR;
	}
	else
	{
		if (key == (*T)->data)
			return Delete(T);
		else if (key < (*T)->data)
			return DeleteBST(&(*T)->lchild, key);
		else
			return DeleteBST(&(*T)->rchild, key);
	}
}

Status Delete(BiTree *p)
{
	BiTree q, s;
	if ((*p)->rchild == NULL)
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else if ((*p)->lchild == NULL)
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else
	{
		q = *p;
		s = (*p)->lchild;
		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if (q != *p)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
		free(s);
	}
	return OK;
}