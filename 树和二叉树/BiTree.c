#ifndef BITREE_C
#define BITREE_C

#include "BiTree.h"
#include "SqQueue.c"

char str[] = "ABC##DE#G##F###";
int i = 0;

Status InitBiTree(BiTree *T) {
    *T = NULL;
    return OK;
}

Status CreateBiTree(BiTree *T) {
    TElemType ch;
    ch = str[i++];
    if(ch == '#') *T = NULL;
    else {
        *T = (BiTree)malloc(sizeof(struct BiTNode));
        (*T)->data = ch;
        CreateBiTree(&((*T)->LChild));
        CreateBiTree(&((*T)->RChild));
    }
    return OK;
}

void PreOrderTraverse(BiTree T) {
    if(T) {
        printf("%c", T->data);
        PreOrderTraverse(T->LChild);
        PreOrderTraverse(T->RChild);
    }
}

void InOrderTraverse(BiTree T) {
    if(T) {
        InOrderTraverse(T->LChild);
        printf("%c", T->data);
        InOrderTraverse(T->RChild);
    }
}

void PostOrderTraverse(BiTree T) {
    if(T) {
        PostOrderTraverse(T->LChild);
        PostOrderTraverse(T->RChild);
        printf("%c", T->data);
    }
}

void LevelOrderTraverse(BiTree T) {
    InitQueue Q;
    if (BiTreeEmpty(T)) return ERROR;
    /**
    根结点入队
    while循环
    出队，变量缓存当前出队结点
    当前出队结点左、右孩子入队
    */
}

int BiTreeDepth(BiTree T) {
    int m, n;
    if (!T) return 0;
    m = BiTreeDepth(T->LChild);
    n = BiTreeDepth(T->RChild);
    if(m > n) return m + 1;
    else {
        return n + 1;
    }
}

Status BiTreeEmpty(BiTree T) {
    if(T) return FALSE;
    else {
        return TRUE;
    }
}

#endif