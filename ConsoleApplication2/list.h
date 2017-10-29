#pragma once
#ifndef  LIST_H_
#define  LIST_H_
#include <stdbool.h>
#define  NAME_MAX  50
typedef struct item  //������
{
	char name[NAME_MAX];
	int value;
}Item;

typedef struct node //�ڵ㣬�������ݺ�ָ��
{
	Item item;
    node * next;
}Node;

typedef struct list //������ ����ͷָ�������ǰ����
{
	Node * head;
	int listcount;
}List;

//��ʼ������Ϊ��
void initializeList(List * plist);

//�ж������Ƿ�Ϊ��
bool IsListEmpty(const List * plist);

//�ж������Ƿ���
bool IsListFull(const List * plist);

//������������
int ListCount(const List * plist);

//�����
bool AddListItem(const Item * pitem, List * plist);

//����������ڵ�
void CopyItem(const Item * item, Node * pnode);

//��������
void Traverse(const List *plist, void(*pfun)(const Item * item));

//����������
bool FindItem(const Item item, List *plist);

//ɾ��������
bool DelItem(const Item item, List *plist);

//��������
void CleanList(List * plist);

//��������
void SortList(List *plist, bool(*pfun)(Item *item1, Item *item2));

//������ר�������ж�
bool cmpitem(Item *item1, Item *item2);
//������רҵ���
void ListPrintf(const Item * item);

#endif // ! LIST_H_
