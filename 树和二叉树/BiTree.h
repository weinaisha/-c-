#ifndef BITREE_H
#define BITREE_H

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 255
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef char TElemType;

typedef struct BiTNode {
    TElemType data; //结点数据域
    struct BiTNode *LChild, *RChild; // 左右孩子指针
} BiTNode, *BiTree;

// 构造先序建立二叉树
Status CreateBiTree(BiTree &T);

// 返回二叉树深度
int BiTreeDepth(BiTree T);

// 二叉树是否为空
Status BiTreeEmpty(BiTree T);

// 返回结点e的值
TElemType Value(BiTree T, BiTNode e);

// e是二叉树T中的一个结点，给e赋值
Status Assign(T, &e, value);

// e是二叉树T中的结点，若e不是根结点则返回e的双亲
BiTNode Parent(T, e);

//LeftChild(T,e);
//
//RightChild(T,e)
//
//LeftSibling(T,e)
//
//RightSibling(T,e)
//
//InsertChild(&T,p,LR,c)
//
//DeleteChild(&T,p, LR)
//
//PreOrderTraverse(T}
//初始条件：二叉树T存在。
//操作结果：先序遍历T, 对每个结点访问一次。
//InOrderTraverse(T)
//初始条件：二叉树T存在。
//操作结果：中序遍历T, 对每个结点访问一次。
//PostOrderTraverse(T}
//初始条件：二叉树T存在。
//操作结果：后序遍历T, 对每个结点访问一次5
//LevelOrderTraverse(T)
//初始条件：二叉树T存在。
//操作结果：层序遍历T, 对每个结点访问一次
#endif