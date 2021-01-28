#ifndef BITREE_C
#define BITREE_C

#include "BiTree.h"

char str[] = "ABC##DE#G##F###";
int i = 0;

// 返回指向二叉树结点e的指针
static BiTree EPtr(BiTree T, TElemType e) {
    BiTree pl, pr;
    if(T == NULL) return NULL;
    if(T->data == e) return T;
    pl = EPtr(T->LChild, e);
    if(pl) return pl;
    pr = EPtr(T->RChild, e);
    if(pr) return pr;
    return NULL; 
}

// 返回指向二叉树结点e的双亲结点的指针
static BiTree PPtr(BiTree T, TElemType e) {
    BiTree pl, pr;
    if(T == NULL || T->data == e) { //空树，根结点没有双亲
        return NULL;
    }
    if(T->LChild != NULL && T->LChild->data == e) {
        return T;
    }
    if(T->RChild != NULL && T->RChild->data == e) {
        return T;
    }
    pl = PPtr(T->LChild, e);
    if(pl != NULL) return pl;
    pr = PPtr(T->RChild, e);
    if(pr != NULL) return pr;
    return NULL;
}

Status InitBiTree(BiTree *T) {
    *T = NULL;
    return OK;
}

Status CreateBiTree(BiTree *T) {
    TElemType ch;
    scanf("%c", &ch);
    if(ch == '#') *T = NULL;
    else {
        *T = (BiTree)malloc(sizeof(struct BiTNode));
        (*T)->data = ch;
        CreateBiTree(&((*T)->LChild));
        CreateBiTree(&((*T)->RChild));
    }
    return OK;
}

Status ClearBiTree(BiTree *T) {
    if(*T) {
        if((*T)->LChild != NULL) ClearBiTree(&((*T)->LChild));
        if((*T)->RChild != NULL) ClearBiTree(&((*T)->RChild));
        free(*T);
        *T = NULL;
    }
    return OK;
}

Status BiTreeEmpty(BiTree T) {
    if(T) return FALSE;
    else {
        return TRUE;
    }
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

TElemType Value(BiTree T, TElemType e) {
    if(BiTreeEmpty(T)) return '\0';
    BiTree p = EPtr(T, e);
    if(p) return p->data;
    else {
        return '\0';
    }
}

TElemType Root(BiTree T) {
    if(BiTreeEmpty(T)) return '\0';
    return T->data;
}

Status Assign(BiTree *T, TElemType e, TElemType value) {
    BiTree p;
    if(BiTreeEmpty(*T)) return ERROR;
    p = EPtr(*T, e);
    if(p) {
        p->data = value;
        return OK;
    } else {
        return ERROR;
    }
}

TElemType Parent(BiTree T, TElemType e) {
    BiTree p;
    if(BiTreeEmpty(T)) return '\0';
    p = PPtr(T, e);
    if(p) return p->data;
    return '\0';
}

TElemType LeftChild(BiTree T, TElemType e) {
    BiTree p;
    if(BiTreeEmpty(T)) return '\0';
    p = EPtr(T, e);
    if(p && p->LChild) return p->LChild->data;
    return '\0';
}

TElemType RightChild(BiTree T, TElemType e) {
    BiTree p;
    if(BiTreeEmpty(T)) return '\0';
    p = EPtr(T, e);
    if(p && p->RChild) return p->RChild->data;
    return '\0';
}

TElemType LeftSibling(BiTree T, TElemType e) {
    BiTree p;
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    p = PPtr(T, e);
    if(p != NULL && p->LChild != NULL) {
        return p->LChild->data;
    }
    return '\0';
}

TElemType RightSibling(BiTree T, TElemType e) {
    BiTree p;
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    p = PPtr(T, e);
    if(p != NULL && p->RChild != NULL) {
        return p->RChild->data;
    }
    return '\0';
}

Status InsertChild(BiTree *T, TElemType p, int LR, BiTree *c) {
    BiTree ptr;
    if(BiTreeEmpty(*c)) return ERROR;
    ptr = EPtr(*T, p);
    if(ptr == NULL) return ERROR;
    if(LR == 0) {
        (*c)->RChild = ptr->LChild;
        ptr->LChild = *c;
    }
    if(LR == 1) {
        (*c)->RChild = ptr->RChild;
        ptr->RChild = *c;
    }
    return OK;
}

Status DeleteChild(BiTree *T, TElemType p, int LR) {
    BiTree ptr;
    if((*T) == NULL) return ERROR;
    ptr = EPtr(*T, p);
    if(ptr == NULL) return ERROR;
    if(LR == 0) {
        ClearBiTree(&(ptr->LChild));
    }
    if(LR == 1) {
        ClearBiTree(&(ptr->RChild));
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

void InOrderTraverseByStack(BiTree T) {

}

void PostOrderTraverse(BiTree T) {
    if(T) {
        PostOrderTraverse(T->LChild);
        PostOrderTraverse(T->RChild);
        printf("%c", T->data);
    }
}

void LevelOrderTraverse(BiTree T) {
    if (BiTreeEmpty(T)) return;
    /**
    根结点入队
    while循环
    出队，变量缓存当前出队结点
    当前出队结点左、右孩子入队
    */
}


#endif