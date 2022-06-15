
#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

struct queueNode
{
	char data;
	struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

void dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr)
{
	QueueNodePtr tempPtr = *headPtr;
	*headPtr = (*headPtr)->nextPtr;

	if (*headPtr == NULL)
	{
		*tailPtr = NULL;
	}

	free(tempPtr);
	tempPtr = NULL;
}
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value)
{
	QueueNodePtr newPtr = (QueueNodePtr)malloc(sizeof(QueueNode));

	if (newPtr == NULL)
	{
		exit(EXIT_FAILURE);
	}

	newPtr->data = value;
	newPtr->nextPtr = NULL;

	if (*headPtr == NULL)
	{
		*headPtr = newPtr;
	}
	else
	{
		(*tailPtr)->nextPtr = newPtr;
	}
	*tailPtr = newPtr;
}
void printQueue(QueueNodePtr currentPtr)
{

	if (currentPtr == NULL)
	{
		puts("Queue is empty.");
		return;
	}
	puts("The queue is: -");

	while (currentPtr != NULL)
	{
		printf("%c --> ", currentPtr->data);
		currentPtr = currentPtr->nextPtr;
	}
	puts("NULL");
}

#endif //QUEUE_H
