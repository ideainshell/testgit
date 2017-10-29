#pragma once
#ifndef MQUEUE_H_
#define MQUEUE_H
#include <stdbool.h>
#define MAX_NAME 50
typedef struct itemQ
{
	char name[MAX_NAME];
	int value;
}ItemQ;

typedef struct nodeQ
{
	ItemQ  itemQ;
	struct nodeQ * next;

}NodeQ;

typedef struct mqueue
{
	NodeQ * front;
	NodeQ * tail;
	int queuecount;
}mQueue;


//初始化队列
void InitializeQ(mQueue *pqueue);

//队列是否为空
bool IsQueueEmpty(const mQueue *pqueue);

//队列是否为满
bool IsQueueFull(const mQueue *pqueue);

//返回队列数据项数量
int QueueCount(const mQueue * pqueue);

//添加项   队列：末尾
bool AddQItem(const ItemQ *itemQ, mQueue * pqueue);

//复制数据项到节点
void CopyItemQ(const ItemQ *itemQ, NodeQ *pnode);

//遍历队列
void TraverseQ(mQueue *pqueue, void(*pfun)(ItemQ *itemQ));

//本队列专用输出
void QueuePrintf(ItemQ * itemQ);

//删除项   队列：队首
bool DelItemQ(mQueue *pqueue);

//搜索项
bool FindItemQ(const ItemQ *itemQ, const mQueue *pqueue);

//清空队列
void CleanQueue(mQueue *pqueue);

#endif // !MQUEUE_H_
