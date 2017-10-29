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


//��ʼ������
void InitializeQ(mQueue *pqueue);

//�����Ƿ�Ϊ��
bool IsQueueEmpty(const mQueue *pqueue);

//�����Ƿ�Ϊ��
bool IsQueueFull(const mQueue *pqueue);

//���ض�������������
int QueueCount(const mQueue * pqueue);

//�����   ���У�ĩβ
bool AddQItem(const ItemQ *itemQ, mQueue * pqueue);

//����������ڵ�
void CopyItemQ(const ItemQ *itemQ, NodeQ *pnode);

//��������
void TraverseQ(mQueue *pqueue, void(*pfun)(ItemQ *itemQ));

//������ר�����
void QueuePrintf(ItemQ * itemQ);

//ɾ����   ���У�����
bool DelItemQ(mQueue *pqueue);

//������
bool FindItemQ(const ItemQ *itemQ, const mQueue *pqueue);

//��ն���
void CleanQueue(mQueue *pqueue);

#endif // !MQUEUE_H_
