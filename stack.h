
#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef char data;

struct node
{
	data value;
	struct node *nextPtr;
};

typedef struct node node;
typedef node *node_ptr;

data pop(node_ptr *topPtr)
{

	if (*topPtr == NULL)
	{
		puts("Stack is empty.");
		return -1;
	}
	node_ptr tempPtr = *topPtr;

	data popValue = (*topPtr)->value;
	*topPtr = (*topPtr)->nextPtr;

	free(tempPtr);
	tempPtr = NULL;
	return popValue;
}
void push(node_ptr *topPtr, char value)
{

	node_ptr newPtr = (node_ptr)malloc(sizeof(node));

	if (newPtr == NULL)
	{
		printf("%c not inserted. No memory available.\n", value);
		return;
	}
	newPtr->value = value;
	newPtr->nextPtr = *topPtr;
	*topPtr = newPtr;
}
void print_stack(node_ptr currentPtr)
{
	if (currentPtr == NULL)
	{
		puts("Stack is empty.");
		return;
	}
	puts("The stack is: -");

	while (currentPtr != NULL)
	{
		printf("%c --> ", currentPtr->value);
		currentPtr = currentPtr->nextPtr;
	}
	puts("NULL");
}

#endif // STACK_H
