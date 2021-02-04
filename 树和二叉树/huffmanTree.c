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