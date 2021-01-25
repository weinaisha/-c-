#ifndef BITREE_H
#define BITREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
Status CreateBiTree(BiTree *T);

// 构造空二叉树T
Status InitBiTree(BiTree *T);

// 销毁二叉树T
Status DestroyBiTree(BiTree *T);

// 将树T清为空树
Status ClearBiTree(BiTree *T);

// 返回二叉树深度
int BiTreeDepth(BiTree T);

// 二叉树是否为空
Status BiTreeEmpty(BiTree T);

/**
初始条件：二叉树存在，e是T中的某个结点
操作结果：返回e的值
*/
TElemType Value(BiTree T, BiTNode e);

// 返回T的根
BiTNode Root(BiTree T);

// e是二叉树T中的一个结点，给e赋值
Status Assign(BiTree T, BiTNode e, TElemType value);

// e是二叉树T中的结点，若e不是根结点则返回e的双亲
// BiTNode Parent(T, e);

//LeftChild(T,e);
//
//RightChild(T,e)
//
//LeftSibling(T,e)
//
//RightSibling(T,e)
/*
初始条件：二叉树T存在,p指向T中某个结点，LR为0或1, 非空二叉树 c 与 T 不相交且右子树为空
操作结果：根据 LR 为 0 或 1, 插入 c 为 T中 p 所指结点的左或右子树。p 所指结点的原有左或右子树则成
为 c的右子树
*/
// Status InsertChild(BiTree T, p, int LR, c);
//
//DeleteChild(&T,p, LR)
//
/*
初始条件：二叉树T存在。
操作结果：先序遍历T, 对每个结点访问一次。
*/
void PreOrderTraverse(BiTree T);

/*
初始条件：二叉树T存在
操作结果：中序遍历T, 对每个结点访问一次。
*/
void InOrderTraverse(BiTree T);

/*
初始条件：二叉树T存在。
操作结果：后序遍历T, 对每个结点访问一次
*/
void PostOrderTraverse(BiTree T);

void LevelOrderTraverse(BiTree T);
//初始条件：二叉树T存在。
//操作结果：层序遍历T, 对每个结点访问一次
#endif