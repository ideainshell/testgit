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

//��ʼ����
void InitializeTree(Tree * ptree);

//�Ƿ���Ϊ��
bool IsTreeEmpty(const Tree * ptree);

//�Ƿ���Ϊ��
bool IsTreeFull(const Tree * ptree);

//�������Ĵ�С
int TreeSize(const Tree * ptree);

//�����
bool AddItemTree(const TItem *item, Tree * ptree);

//ɾ����
bool DelItemTree(const TItem *item, Tree * ptree);

//������
TFind FindItemTree(const TItem *item, const Tree * ptree);

//������
void TraverseTree(Tree * ptree,void (*pfun)(TItem * item));

//�����������
void TreePrintf(TItem *item);

//�����
void CleanTree(Tree * ptree);



#endif // !MTREE_H
