#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mqueue.h"

//初始化队列
void InitializeQ(mQueue * pqueue)
{
	pqueue->front = NULL;
	pqueue->queuecount = 0;
	pqueue->tail = NULL;
}

//队列是否为空
bool IsQueueEmpty(const mQueue *pqueue)
{
	if (pqueue->queuecount == 0)
		return true;
	return false;
}

//队列是否为满
bool IsQueueFull(const mQueue *pqueue)
{
	NodeQ * ptemp;
	ptemp = (NodeQ *)malloc(sizeof(NodeQ));
	if (ptemp == NULL)
	{
		free(ptemp);
		return true;
	}
	free(ptemp);
	return false;

}

//返回队列数据项数量
int QueueCount(const mQueue * pqueue)
{
	return pqueue->queuecount;
}

//添加项   队列：末尾
bool AddQItem(const ItemQ *itemQ, mQueue * pqueue)
{
	NodeQ * ptemp;
	if (IsQueueFull(pqueue))
	{
		return false;
	}
	ptemp = (NodeQ *)malloc(sizeof(NodeQ));
	if (ptemp == NULL)
		return false;
	CopyItemQ(itemQ, ptemp);
	ptemp->next = NULL;
	if (pqueue->front == NULL)
	{
		pqueue->front = ptemp;
	}
	else
		pqueue->tail->next = ptemp;
	pqueue->tail = ptemp;
	pqueue->queuecount++;
	return true;
}

void CopyItemQ(const ItemQ *itemQ, NodeQ *pnode)
{
	pnode->itemQ = *itemQ;
}

//遍历队列
void TraverseQ(mQueue *pqueue, void(*pfun)(ItemQ *itemQ))
{
	NodeQ * ptemp;
	ptemp = pqueue->front;
	while (ptemp != NULL)
	{
		(*pfun)(&(ptemp->itemQ));
		ptemp = ptemp->next;
	}
}

void QueuePrintf(ItemQ * itemQ)
{
	printf("%s is %d\n", itemQ->name, itemQ->value);
}
//删除项   队列：队首
bool DelItemQ(mQueue *pqueue)
{
	if (IsQueueEmpty(pqueue))
		return false;
	NodeQ *ptemp;
	ptemp = pqueue->front;
	if (ptemp->next == NULL)
	{
		pqueue->tail = NULL;
	}
	pqueue->front = pqueue->front->next;
	free(ptemp);
	pqueue->queuecount--;
	return true;

}

//搜索项
bool FindItemQ(const ItemQ *itemQ, const mQueue *pqueue)
{
	NodeQ * ptemp;
	ptemp = pqueue->front;
	while (ptemp != NULL)
	{
		if (strcmp(ptemp->itemQ.name, itemQ->name) == 0 && ptemp->itemQ.value == itemQ->value)
			return true;
		ptemp = ptemp->next;
	}
	return false;

}

//清空队列
void CleanQueue(mQueue *pqueue)
{
	while(!IsQueueEmpty(pqueue))
	{
		DelItemQ(pqueue);
	}
}