#include <stdio.h>

#define MAXSIZE 100
typedef char ElemType;

// 树的双亲表示法
typedef struct
{
    ElemType data;
    int parent; //双亲位置域
} PTNode;

typedef struct
{
    PTNode node[MAXSIZE]; // 双亲表示
    int n; // 结点数
} PTree;

// 孩子表示法，将每个结点的孩子都用单链表链接起来形成一个线性结构

// 孩子兄弟表示法
