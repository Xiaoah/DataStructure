#include<stdio.h>
#include<iostream>

#define MAX_TREE_SIZE 100

typedef int TElemType;

/*����˫�ױ�ʾ��*/
typedef struct PTNode
{
	TElemType data;
	int parent;               //��¼˫�׵�λ��
}PTNode;

typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];
	int r, n;                //����λ�úͽ����
}PTree;

/*���ĺ��ӱ�ʾ��*/
typedef struct CTNode
{
	int child;
	struct CTNode *next;
}*ChildPtr;

typedef struct
{
	TElemType data;
	ChildPtr firstchild;
}CTBox;

typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int r, n;
}CTree;

/*�������Ķ���������ṹ*/
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;
/*ǰ�����*/
void PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	printf("%c", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}
/*�������*/
void InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild);
	printf("%c", T->data);
	InOrderTraverse(T->rchild);
}
/*�������*/
void PostOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c", T->data);
}

/*��ǰ������������н���ֵ��һ���ַ���*/
/*#��ʾ����*/
void CreateBiTree(BiTree *T)
{
	TElemType ch;
	scanf("%c", &ch);
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T)
		{
			exit(OVERFLOW);
		}
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}

}

/*����������*/
typedef enum {Link,Thread} PointerTag;
typedef struct BiThrNode
{
	TElemType data;
	struct BiThrNode *lchild, *rchild;
	PointerTag LTag;
	PointerTag RTag;
}BiThrNode,*BiThrTree;

