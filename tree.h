
#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

struct treeNode
{
	struct treeNode *leftPtr;
	char data;
	struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void inOrder(TreeNodePtr treePtr)
{
	if (treePtr != NULL)
	{
		inOrder(treePtr->leftPtr);
		printf("%c ", treePtr->data);
		inOrder(treePtr->rightPtr);
	}
}
void preOrder(TreeNodePtr treePtr)
{
	if (treePtr != NULL)
	{
		printf("%c ", treePtr->data);
		preOrder(treePtr->leftPtr);
		preOrder(treePtr->rightPtr);
	}
}
void postOrder(TreeNodePtr treePtr)
{
	if (treePtr != NULL)
	{
		postOrder(treePtr->leftPtr);
		postOrder(treePtr->rightPtr);
		printf("%c ", treePtr->data);
	}
}
void insertNode(TreeNodePtr *treePtr, char value)
{
	if (*treePtr == NULL)
	{
		*treePtr = (TreeNodePtr)malloc(sizeof(TreeNode));

		if (*treePtr == NULL)
		{
			printf("%c not inserted. No memory available.\n", value);
		}
		else
		{
			(*treePtr)->data = value;
			(*treePtr)->leftPtr = NULL;
			(*treePtr)->rightPtr = NULL;
		}
		return;
	}
	if (value < (*treePtr)->data)
	{
		insertNode(&((*treePtr)->leftPtr), value);
	}
	else if (value > (*treePtr)->data)
	{
		insertNode(&((*treePtr)->rightPtr), value);
	}
	else
	{
		puts("dup");
	}
}

#endif //TREE_H
