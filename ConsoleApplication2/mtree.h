#pragma once
#ifndef MTREE_H_
#define MTREE_H_
#include <stdbool.h>
#define MAX_C 50

typedef struct titem
{
	char name[MAX_C];
	int value;
}TItem;

typedef struct tnode
{
	TItem item;
	tnode * right;
	tnode * left;
}TNode;

typedef struct tree
{
	TNode * root;
	int treecount;
}Tree;

typedef struct tfind
{
	TNode *parent;
	TNode *self;
}TFind;

//初始化树
void InitializeTree(Tree * ptree);

//是否树为空
bool IsTreeEmpty(const Tree * ptree);

//是否树为满
bool IsTreeFull(const Tree * ptree);

//返回树的大小
int TreeSize(const Tree * ptree);

//添加项
bool AddItemTree(const TItem *item, Tree * ptree);

//删除项
bool DelItemTree(const TItem *item, Tree * ptree);

//查找项
TFind FindItemTree(const TItem *item, const Tree * ptree);

//遍历树
void TraverseTree(Tree * ptree,void (*pfun)(TItem * item));

//本树输出函数
void TreePrintf(TItem *item);

//清空树
void CleanTree(Tree * ptree);



#endif // !MTREE_H
