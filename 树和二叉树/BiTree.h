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
    TElemType data; //���������
    struct BiTNode *LChild, *RChild; // ���Һ���ָ��
} BiTNode, *BiTree;

// ����������������
Status CreateBiTree(BiTree *T);

// ����ն�����T
Status InitBiTree(BiTree *T);

// ���ٶ�����T
Status DestroyBiTree(BiTree *T);

// ����T��Ϊ����
Status ClearBiTree(BiTree *T);

// ���ض��������
int BiTreeDepth(BiTree T);

// �������Ƿ�Ϊ��
Status BiTreeEmpty(BiTree T);

/**
��ʼ���������������ڣ�e��T�е�ĳ�����
�������������e��ֵ
*/
TElemType Value(BiTree T, TElemType e);

// ����T�ĸ�
TElemType Root(BiTree T);

// e�Ƕ�����T�е�һ����㣬��e��ֵ
Status Assign(BiTree *T, TElemType e, TElemType value);

// e�Ƕ�����T�еĽ�㣬��e���Ǹ�����򷵻�e��˫��
TElemType Parent(BiTree T, TElemType e);

TElemType LeftChild(BiTree T, TElemType e);

TElemType RightChild(BiTree T, TElemType e);

TElemType LeftSibling(BiTree T, TElemType e);

TElemType RightSibling(BiTree T, TElemType e);

/*
��ʼ������������T����,pָ��T��ĳ����㣬LRΪ0��1, �ǿն����� c �� T ���ཻ��������Ϊ��
������������� LR Ϊ 0 �� 1, ���� c Ϊ T�� p ��ָ���������������p ��ָ����ԭ��������������
Ϊ c��������
*/
Status InsertChild(BiTree *T, TElemType p, int LR, BiTree *c);

Status DeleteChild(BiTree *T, TElemType p, int LR);

/*
��ʼ������������T���ڡ�
����������������T, ��ÿ��������һ�Ρ�
*/
void PreOrderTraverse(BiTree T);

/*
��ʼ������������T����
����������������T, ��ÿ��������һ�Ρ�
*/
void InOrderTraverse(BiTree T);

/*
��ʼ������������T���ڡ�
����������������T, ��ÿ��������һ��
*/
void PostOrderTraverse(BiTree T);

void LevelOrderTraverse(BiTree T);
//��ʼ������������T���ڡ�
//����������������T, ��ÿ��������һ��

//����ջ�ǵݹ��������
void PreOrderTraverseByStack(BiTree T);

//����ջ�ǵݹ��������
void InOrderTraverseByStack(BiTree T);

//����ջ�ǵݹ�������
void PostOrderTraverseByStack(BiTree T);

#endif