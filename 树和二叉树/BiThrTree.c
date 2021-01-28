#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct ThrNode {
    ElemType data;
    struct ThrNode *LChild, *RChild;
    int LTag, RTag;
} ThrNode, *BiThrTree;

BiThrTree pre;

// 以结点p为根的子树中序线索化

void InThreading(BiThrTree *p) {
    if(*p) {
        InThreading(&((*p)->LChild));
        if(!(*p)->LChild) {
            (*p)->LTag = 1;     // 给p加上线索
            (*p)->LChild = pre; // p的左孩子指针指向pre(前驱)
        } else {
            (*p)->LTag = 0;
        }
        if(!(pre->RChild)) {
            pre->RChild = p; // 前驱的右孩子指向p(后继)
            pre->RTag = 1;   // 给前驱加上线索
        }
        else p->RTag = 0;
        pre = p;
        InThreading(p->RChild);
    }
}

// 带头结点的二叉树中序线索化

void InOrderThreading(BiThrTree *Thrt, BiThrTree *T) {
    *Thrt = (BiThrTree)malloc(sizeof(ThrNode));
    (*Thrt)->LTag = 0;
    (*Thrt)->RTag = 1;
    (*Thrt)->RChild = (*Thrt);
    if(!T) (*Thrt)->LChild = *Thrt;
    else {
        (*Thrt)->LChild = *T;
        pre = *Thrt;
        InThreading(T);
        pre->RChild = (*Thrt);
        pre->RTag = 1;
        (*Thrt)->RChild = pre;
    }
}