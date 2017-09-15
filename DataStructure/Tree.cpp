#include<stdio.h>
#include<iostream>

#define MAX_TREE_SIZE 100

typedef int TElemType;

/*树的双亲表示法*/
typedef struct PTNode
{
	TElemType data;
	int parent;               //记录双亲的位置
}PTNode;

typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];
	int r, n;                //根的位置和结点数
}PTree;

/*树的孩子表示法*/
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

/*二叉树的二叉链表结点结构*/
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;
/*前序遍历*/
void PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	printf("%c", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}
/*中序遍历*/
void InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild);
	printf("%c", T->data);
	InOrderTraverse(T->rchild);
}
/*后序遍历*/
void PostOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c", T->data);
}

/*按前序输入二叉树中结点的值（一个字符）*/
/*#表示空树*/
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

/*线索二叉树*/
typedef enum {Link,Thread} PointerTag;
typedef struct BiThrNode
{
	TElemType data;
	struct BiThrNode *lchild, *rchild;
	PointerTag LTag;
	PointerTag RTag;
}BiThrNode,*BiThrTree;

