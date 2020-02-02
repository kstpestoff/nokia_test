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

struct tBinNode
{
	int data;					///> key value 
	struct tBinNode* pLeft;		///> pointer to left node
	struct tBinNode* pRight;	///> pointer to right node
};

typedef struct tBinNode sBinNode;

typedef struct tBinTree
{
	int count;
	sBinNode* pRoot;
}sBinTree;

void binIsertionTree
(
	sBinNode** pNode, 
	int item
);

int maxDepthTree(sBinTree* pThis);

int printTree(sBinNode* pThis);
