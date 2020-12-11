#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1

typedef int Status;
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *prior; // 直接前驱
    struct LNode *next;  // 直接后驱
} LNode, *LinkList_DOL;