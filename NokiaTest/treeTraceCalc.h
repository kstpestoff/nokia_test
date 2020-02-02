
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

int binIsertionTree(sBinTree* pTree, int item);
