#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 255
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int TElemType;

typedef struct TNode {
    int weight;
    struct TNode *lchild, *rchild, *parent;
} TNode, *HFTree;

/**
 * 给定n个权值分别为w1,w2,...,wn的结点构造哈夫曼树
 * 1）n个结点分别作为n棵仅含一个结点的二叉树，构成森林F
 * 2）从F中选出权值最小的两棵树作为左右结点，构成一棵新树，且这棵新树的权值为选中两棵树的权值之和
 * 3）从F中删除选中的两棵树，将新得到的树加入F中
 * 4）重复2）3），直到F中只剩一棵树为止
*/