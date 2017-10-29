#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mqueue.h"

//��ʼ������
void InitializeQ(mQueue * pqueue)
{
	pqueue->front = NULL;
	pqueue->queuecount = 0;
	pqueue->tail = NULL;
}

//�����Ƿ�Ϊ��
bool IsQueueEmpty(const mQueue *pqueue)
{
	if (pqueue->queuecount == 0)
		return true;
	return false;
}

//�����Ƿ�Ϊ��
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

//���ض�������������
int QueueCount(const mQueue * pqueue)
{
	return pqueue->queuecount;
}

//�����   ���У�ĩβ
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

//��������
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
//ɾ����   ���У�����
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

//������
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

//��ն���
void CleanQueue(mQueue *pqueue)
{
	while(!IsQueueEmpty(pqueue))
	{
		DelItemQ(pqueue);
	}
}