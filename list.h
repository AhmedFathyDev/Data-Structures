
#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

struct listNode
{
	char data;
	struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void printList(ListNodePtr currentPtr)
{
	if (currentPtr == NULL)
	{
		puts("List is empty.");
		return;
	}
	puts("The list is: -");

	while (currentPtr != NULL)
	{
		printf("%c --> ", currentPtr->data);
		currentPtr = currentPtr->nextPtr;
	}
	puts("NULL");
}
void listInsert(ListNodePtr *startPtr, char value)
{
	ListNodePtr newPtr = (ListNodePtr)malloc(sizeof(ListNode));

	if (newPtr == NULL)
	{
		printf("%c not inserted. No memory available.\n", value);
		return;
	}
	newPtr->data = value;
	newPtr->nextPtr = NULL;

	ListNodePtr previousPtr = NULL;
	ListNodePtr currentPtr = *startPtr;

	while (currentPtr != NULL && value > currentPtr->data)
	{
		previousPtr = currentPtr;
		currentPtr = currentPtr->nextPtr;
	}

	if (previousPtr == NULL)
	{
		newPtr->nextPtr = NULL;
		*startPtr = newPtr;
	}
	else
	{
		previousPtr->nextPtr = newPtr;
		newPtr->nextPtr = currentPtr;
	}
}
char listDelete(ListNodePtr *startPtr, char value)
{
	if (value == (*startPtr)->data)
	{
		ListNodePtr tempPtr = *startPtr;
		*startPtr = (*startPtr)->nextPtr;

		free(tempPtr);
		tempPtr = NULL;
		return value;
	}
	ListNodePtr previousPtr = *startPtr;
	ListNodePtr currentPtr = (*startPtr)->nextPtr;

	while (currentPtr != NULL && currentPtr->data != value)
	{
		previousPtr = currentPtr;
		currentPtr = currentPtr->nextPtr;
	}

	if (currentPtr != NULL)
	{
		ListNodePtr tempPtr = currentPtr;
		previousPtr->nextPtr = currentPtr->nextPtr;
		free(tempPtr);
		tempPtr = NULL;
		return value;
	}

	return '\0';
}

#endif //LIST_H
