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
TElemType Value(BiTree T, TElemType e);

// 返回T的根
TElemType Root(BiTree T);

// e是二叉树T中的一个结点，给e赋值
Status Assign(BiTree *T, TElemType e, TElemType value);

// e是二叉树T中的结点，若e不是根结点则返回e的双亲
TElemType Parent(BiTree T, TElemType e);

TElemType LeftChild(BiTree T, TElemType e);

TElemType RightChild(BiTree T, TElemType e);

TElemType LeftSibling(BiTree T, TElemType e);

TElemType RightSibling(BiTree T, TElemType e);

/*
初始条件：二叉树T存在,p指向T中某个结点，LR为0或1, 非空二叉树 c 与 T 不相交且右子树为空
操作结果：根据 LR 为 0 或 1, 插入 c 为 T中 p 所指结点的左或右子树。p 所指结点的原有左或右子树则成
为 c的右子树
*/
Status InsertChild(BiTree *T, TElemType p, int LR, BiTree *c);

Status DeleteChild(BiTree *T, TElemType p, int LR);

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

//借助栈非递归先序遍历
void PreOrderTraverseByStack(BiTree T);

//借助栈非递归中序遍历
void InOrderTraverseByStack(BiTree T);

//借助栈非递归后序遍历
void PostOrderTraverseByStack(BiTree T);

#endif