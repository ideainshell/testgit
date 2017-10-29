#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "mqueue.h"
#include "mtree.h"
#include <time.h>
int main()
{
	Tree classT;
		InitializeTree(&classT);
	
	if (IsTreeEmpty(&classT))
		printf("it is empty!\n");
	else
		printf("it has something!\n");

	if (IsTreeFull(&classT))
		printf("it is full!\n");
	else
		printf("it can be more!\n");

	printf("it has %d items!\n", TreeSize(&classT));
	TraverseTree(&classT, &TreePrintf);
	TItem item[5];
	printf("input some:\n");
	for (int i = 0; i < 5; i++)
	{
		scanf("%s %d", item[i].name, &item[i].value);
		if (AddItemTree(&(item[i]),&classT))
			printf("add success!\n");
		else
			printf("something wrong!\n");
	}
	printf("it has %d items!\n", TreeSize(&classT));
	TraverseTree(&classT, &TreePrintf);
	if (FindItemTree(&(item[2]), &classT).self!=NULL)
	{
		printf("find it\n");
	}
	if (DelItemTree(&(item[2]),&classT))
	{
		printf("del succuess!\n");
	}
	printf("it has %d items!\n", TreeSize(&classT));

	TraverseTree(&classT, &TreePrintf);
	CleanTree(&classT);
	TraverseTree(&classT, &TreePrintf);
	/*TraverseQ(&classQ,&QueuePrintf);
	if (DelItemQ(&classQ))
		printf("delete one!\n");
	else
		printf("something wrong!\n");
	TraverseQ(&classQ, &QueuePrintf);
	printf("it has %d items!\n", QueueCount(&classQ));

	if (FindItemQ(&(item[2]), &classQ))
		printf("find it \n");

	CleanQueue(&classQ);
	TraverseQ(&classQ, &QueuePrintf);
	printf("it has %d items!\n", QueueCount(&classQ));*/
	
	return 0;
}
