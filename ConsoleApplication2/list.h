#pragma once
#ifndef  LIST_H_
#define  LIST_H_
#include <stdbool.h>
#define  NAME_MAX  50
typedef struct item  //数据项
{
	char name[NAME_MAX];
	int value;
}Item;

typedef struct node //节点，包含数据和指针
{
	Item item;
    node * next;
}Node;

typedef struct list //链表本体 链表头指针和链表当前数量
{
	Node * head;
	int listcount;
}List;

//初始化链表为空
void initializeList(List * plist);

//判断链表是否为空
bool IsListEmpty(const List * plist);

//判断链表是否满
bool IsListFull(const List * plist);

//返回链表项数
int ListCount(const List * plist);

//添加项
bool AddListItem(const Item * pitem, List * plist);

//复制数据项到节点
void CopyItem(const Item * item, Node * pnode);

//遍历链表
void Traverse(const List *plist, void(*pfun)(const Item * item));

//搜素数据项
bool FindItem(const Item item, List *plist);

//删除数据项
bool DelItem(const Item item, List *plist);

//清零链表
void CleanList(List * plist);

//链表排序
void SortList(List *plist, bool(*pfun)(Item *item1, Item *item2));

//本链表专用排序判断
bool cmpitem(Item *item1, Item *item2);
//本链表专业输出
void ListPrintf(const Item * item);

#endif // ! LIST_H_
