/*************************************************************************************************//**
@file   treeTraceCalc.c
@author Pestoff K.A.
@brief  5. There is a binary tree: 

		struct TreeNode 
		{ 
			struct TreeNode* leftChild; 
			struct TreeNode* rightChild; 
		} 
		
		Write a function that calculates the depth of the tree (the maximum 
		number of nodes in the path from the root to the leaf). Return 
		paths in the tree that have such depth. 

		I use this book Heathfield R., Kirby L. "C Unleashed" that i've write few years ago when i read it.

		we use c99.
*****************************************************************************************************/
#include "treeTraceCalc.h"

#include <stdlib.h> 
#include <assert.h> 
#include <stdlib.h>

int maxDepthTree(sBinTree* pThis)
{
	assert(pThis);
	
	sBinNode *pTree = pThis->pRoot;

	int lDepth = maxDepthTree((sBinNode*)pTree->pLeft);
	int rDepth = maxDepthTree((sBinNode*)pTree->pRight);

	if (lDepth > rDepth)
	{
		return(lDepth + 1);
	}
	else
	{ 
		return(rDepth + 1); 
	}
}

int binSearchTree(sBinTree* pTree, int item)
{
	const sBinNode* pNode;

	assert(pTree != NULL);

	pNode = pTree->pRoot;
	for (;;)
	{
		if (pNode == NULL)
			return 0;
		else if (item = pNode->data)
			return 1;
		else if (item > pNode->data)
			pNode = pNode->pRight;
		else
			pNode = pNode->pLeft;
	}
}

int binIsertionTree(sBinTree* pTree, int item)
{
	sBinNode* pNode, ** ppNew;

	assert(pTree != NULL);

	ppNew = &pTree->pRoot;
	pNode = pTree->pRoot;

	for (;;)
	{
		if (pNode == NULL)
		{
			pNode = *ppNew = malloc(sizeof(*pNode));
			if (pNode != NULL)
			{
				pNode->data = item;
				pNode->pLeft = NULL;
				pNode->pRight = NULL;
				pTree->count++;

				return 1;
			}
			else
				return 0;
		}

		else if (item == pNode->data)
			return 2;
		else if (item > pNode->data)
			pNode = pNode->pRight;
		else
			pNode = pNode->pLeft;
	}
}

int binDeleteTree(sBinTree* pTree, int item)
{
	sBinNode** q, * z;

	assert(pTree != NULL);

	q = &pTree->pRoot;
	z = pTree->pRoot;
	for (;;)
	{
		if (z == NULL)
			return 0;
		else if (item == z->data)
			break;
		else if (item > z->data)
		{
			q = &z->pRight;
			z = z->pRight;
		}
		else
		{
			q = &z->pLeft;
			z = z->pLeft;
		}
	}

	if (z->pRight == NULL)
		*q = z->pLeft;
	else
	{
		sBinNode* y = z->pRight;
		if (y->pLeft == NULL)
		{
			y->pLeft = z->pLeft;
			*q = y;
		}
		else
		{
			sBinNode* x = y->pLeft;
			while (x->pLeft != NULL)
			{
				y = x;
				x = y->pLeft;
			}

			y->pLeft = x->pRight;
			x->pLeft = z->pLeft;
			x->pRight = z->pRight;

			*q = x;

		}
	}
	pTree->count--;
	free(z);
	return 1;
}

void binTraverseTree(const sBinTree* pTree)
{
	int count = 0;

	sBinNode* stack[32];
	sBinNode* pNode;

	assert(pTree != NULL);

	pNode = pTree->pRoot;

	for (;;) 
	{
		while (pNode != NULL) {
			stack[count++] = pNode;
			pNode = pNode->pLeft;
		}
		if (count == 0)
			return;
		pNode = stack[count--];
		pNode = pNode->pRight;
	}
}
