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

int maxDepthTree(sBinNode* pThis)
{
	if (pThis == NULL)
		return 0;

	int lDepth = maxDepthTree((sBinNode*)pThis->pLeft);
	int rDepth = maxDepthTree((sBinNode*)pThis->pRight);

	if (lDepth > rDepth)
	{
		return(lDepth + 1);
	}
	else
	{ 
		return(rDepth + 1); 
	}
}

int printTree(sBinNode* pThis)
{
	if (pThis == NULL)
		return 0;

	printTree(pThis->pLeft);
	printTree(pThis->pRight);

	printf("node: [%p %p %p, %d ]\n",pThis, pThis->pLeft, pThis->pRight, pThis->data);
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

void binIsertionTree(sBinNode** ppNode, int item)
{
	sBinNode* pNew = NULL;
	sBinNode* pNode = (*ppNode);

	if (!((*ppNode)))
	{
		printf("add item %d\n", item);
		pNew = (sBinNode*)malloc(sizeof(sBinNode));
		pNew->pLeft = pNew->pRight = NULL;
		pNew->data = item;
		(*ppNode) = pNew;
		return;
	}

	if (item < (*ppNode)->data)
	{
		binIsertionTree(&(*ppNode)->pLeft, item);
	}

	else if (item > (*ppNode)->data)
	{
		binIsertionTree(&(*ppNode)->pRight, item);
	}
}