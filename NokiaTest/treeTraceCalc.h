
struct tBinNode
{
	int data;
	struct tBinNode* pLeft;
	struct tBinNode* pRight;
};

typedef struct tBinNode sBinNode;

typedef struct tBinTree
{
	int count;
	sBinNode* pRoot;
}sBinTree;

void binIsertionTree(sBinNode** pNode, int item);
int maxDepthTree(sBinTree* pThis);
int printTree(sBinNode* pThis);
