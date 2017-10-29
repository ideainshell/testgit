#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mtree.h"

void InitializeTree(Tree * ptree)
{
	ptree->root = NULL;
	ptree->treecount = 0;
}


//是否树为空
bool IsTreeEmpty(const Tree * ptree)
{
	if (ptree->treecount == 0)
		return true;
	return false;
}

//是否树为满
bool IsTreeFull(const Tree * ptree)
{
	if (ptree->treecount == 0)
		return false;
	TNode * ptemp;
	ptemp = (TNode *)malloc(sizeof(TNode));
	if (ptemp == NULL)
	{
		free(ptemp);
		return true;
	}
	free(ptemp);
	return false;

}

//返回树的大小
int TreeSize(const Tree * ptree)
{
	return ptree->treecount;
}

//返回比较的大小
static int cmpTreeItem(const TItem *item1, const TItem *item2)
{
	if (strcmp(item1->name, item2->name) == 0)
	{
		if (item1->value == item2->value)
			return 0;
		else if (item1->value > item2->value)
			return 1;
		else if (item1->value < item2->value)
			return -1;
	}
	else
		return strcmp(item1->name, item2->name);
}

//查找项
TFind FindItemTree(const TItem *item, const Tree * ptree)
{
	TFind Fthis;
	Fthis.parent = NULL;
	Fthis.self = ptree->root;
	if (ptree->treecount == 0)
	{
		return Fthis;
	}
	while(Fthis.self!=NULL)
	{
		if (cmpTreeItem(item, &(Fthis.self->item)) > 0)
		{
			if (Fthis.self!= NULL)
			{
				Fthis.parent = Fthis.self;
				Fthis.self = Fthis.self->right;
			}
		}
		else if (cmpTreeItem(item, &(Fthis.self->item)) < 0)
		{
			if (Fthis.self!= NULL)
			{
				Fthis.parent = Fthis.self;
				Fthis.self = Fthis.self->left;
			}
		}
		else
			break;
	}
	return Fthis;
}

//添加项
bool AddItemTree(const TItem *item, Tree * ptree)
{
	if (IsTreeFull(ptree))
	{
		printf("full\n");
		return false;
	}
	if (FindItemTree(item, ptree).self!=NULL)
	{
		printf("the same\n");
		return false;
	}
	TNode * ptemp;
	TNode *ptest;
	ptemp = (TNode *)malloc(sizeof(TNode));
	if (ptemp == NULL)
		return false;
	else
	{
		ptemp->item = *item;
		ptemp->left = NULL;
		ptemp->right = NULL;
	}
	ptree->treecount++;
	ptest = ptree->root;
	if (ptree->root == NULL)
	{
		ptree->root = ptemp;
	}
	else
	{
		while (1)
		{
			if (cmpTreeItem(item, &(ptest->item)) < 0)
			{
				if (ptest->left == NULL)
				{
					ptest->left = ptemp;
					break;
				}
				else
				{
					ptest = ptest->left;
				}
			}
			else if (cmpTreeItem(item, &(ptest->item)) > 0)
			{
				if (ptest->right == NULL)
				{
					ptest->right = ptemp;
					break;
				}
				else
				{
					ptest = ptest->right;
				}
			}
		}
	}
	return true;
}
//删除节点
static void DelTNode(TNode **pnode)
{
	TNode * ptemp;
	if ((*pnode)->left == NULL)
	{
		ptemp = *pnode;
		*pnode = (*pnode)->right;
		free(ptemp);
	}
	else if ((*pnode)->right == NULL)
	{
		ptemp = *pnode;
		*pnode = (*pnode)->left;
		free(ptemp);
	}
	else
	{
		for (ptemp = (*pnode)->left; ptemp->right != NULL; ptemp = ptemp->right)
			continue;
		ptemp->right = (*pnode)->right;
		ptemp = *pnode;
		*pnode = (*pnode)->left;
		free(ptemp);
	}
}

//删除项
bool DelItemTree(const TItem *item, Tree * ptree)
{
	if (IsTreeEmpty(ptree))
	{
		return false;
	}
	TFind fthis = FindItemTree(item, ptree);
	if (fthis.self==NULL)
	{
		return false;
	}
	if (fthis.parent == NULL)
	{
		DelTNode(&ptree->root);
	}
	else if (fthis.parent->left == fthis.self)
		DelTNode(&fthis.parent->left);
	else
		DelTNode(&fthis.parent->right);
	ptree->treecount--;
	return true;
}
//本树输出函数
void TreePrintf(TItem *item)
{
	printf("%s is %d\n", item->name, item->value);
}

static void InOrder( TNode * pnode, void(*pfun)(TItem * item))
{
	if (pnode != NULL)
	{
		InOrder(pnode->left, pfun);
		(*pfun)(&(*pnode).item);
		InOrder(pnode->right, pfun);
	}

}
//遍历树
void TraverseTree(Tree * ptree, void(*pfun)(TItem * item))
{
	if (ptree != NULL)
		InOrder(ptree->root, pfun);

}

static void DelNode(TNode * pnode)
{
	TNode * ptemp;
	if (pnode != NULL)
	{
		ptemp = pnode->right;
		DelNode(pnode->left);
		free(pnode);
		DelNode(ptemp);
	}

}
//清空树
void CleanTree(Tree * ptree)
{
	if (ptree != NULL)
		DelNode(ptree->root);
	ptree->treecount = 0;
	ptree->root = NULL;
}