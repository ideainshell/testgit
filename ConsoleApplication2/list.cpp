#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
void initializeList(List * plist)
{
	plist->listcount = 0;
	plist->head = NULL;
}

bool IsListEmpty(const List * plist)
{
	if (plist->listcount == 0 && plist->head == NULL)
		return true;
	return false;
}

bool IsListFull(const List * plist)
{
	Node *ptemp;
	ptemp = (Node *)malloc(sizeof(Node));
	if (ptemp == NULL)
	{
		free(ptemp);
		return true;
	}
	free(ptemp);
	return false;
}

int ListCount(List * plist)
{
	return plist->listcount;
}

bool AddListItem(const Item * pitem, List * plist)
{
	if (FindItem(*pitem, plist))
	{
		printf("it already exist!");
		return false;
	}
	Node * ptemp;
	Node * scan = plist->head;
	ptemp = (Node *)malloc(sizeof(Node));//申请内存
	if (ptemp == NULL)    //确保申请成功
		return false;
	CopyItem(pitem, ptemp);//存入数据项
	ptemp->next = NULL;    //完成节点的数据和指针
	if (plist->head == NULL) //判断是否为空链表
		plist->head = ptemp;
	else
	{
		while (scan->next != NULL)
			scan = scan->next;
		scan->next = ptemp;
	}
	plist->listcount++;
	return true;
}

void CopyItem(const Item * item, Node * pnode)
{
	pnode->item = *item;
}

void Traverse(const List *plist, void(*pfun)(const Item * item))
{
	Node * ptemp = plist->head;
	while (ptemp != NULL)
	{
		(*pfun)(&(ptemp->item));
		ptemp = ptemp->next;
	}
	printf("finish!\n");
}

bool FindItem(const Item item,List *plist)
{
	Node * ptemp = plist->head;
	while (ptemp != NULL)
	{
		if (strcmp(ptemp->item.name, item.name) == 0&&ptemp->item.value==item.value)
		{
			printf("find it!\n");
			return true;
		}
		ptemp = ptemp->next;
	}
	return false;
}

bool DelItem(const Item item, List * plist)
{
	Node * ptemp = plist->head;
	Node * plast;
	while (ptemp != NULL)
	{
		if (strcmp(ptemp->item.name, item.name) == 0 && ptemp->item.value == item.value)
		{
			if (plist->head == ptemp)
			{
				plist->head = plist->head->next;
			}
			else
			{
				plast->next = ptemp->next;
			}
			free(ptemp);
			plist->listcount--;
			printf("delete it!\n");
			return true;
		}
		plast = ptemp;
		ptemp = ptemp->next;
	}
		
	return false;
}


void CleanList(List * plist)
{
	Node * ptemp;
	while (plist->head!= NULL)
	{
		ptemp = plist->head;
		free(plist->head);
		plist->head = plist->head->next;
	}
}

void SortList(List *plist, bool(*pfun)(Item *item1, Item *item2))
{
	if (plist->head == NULL)
	{
		printf("no one i can find!\n");
		return;
	}
	Node * pnode1;
	Node * pnode2;
	Node temp;

	for (int i = 0; i < plist->listcount-1; i++)
	{
		printf(" i=%d\n",i);
		pnode1 = plist->head;
		pnode2 = pnode1->next;
		for (int j = 0; j < plist->listcount - i - 1; j++)
		{
			printf("  j=%d\n", j);
			if ((*pfun)(&(pnode1->item), &(pnode2->item)))
			{                      //仅仅交换数据项，链表结构不需要改变
				temp.item = pnode1->item;
				pnode1->item = pnode2->item;
				pnode2->item = temp.item;
			}
			pnode1 = pnode1->next;
			pnode2 = pnode1->next;
		}
		
	}


}

bool cmpitem(Item *item1, Item  *item2)
{
	if (item1->value > item2->value)
		return true;
	return false;

}

void ListPrintf(const Item * pitem)
{
	printf("%s is %d\n", pitem->name, pitem->value);
}