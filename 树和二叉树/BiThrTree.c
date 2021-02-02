#include <stdio.h>
#include <stdlib.h>

#define OK 1;
#define ERROR 0;
typedef char ElemType;
typedef int Status;

typedef struct ThrNode {
    ElemType data;
    struct ThrNode *LChild, *RChild;
    int LTag, RTag;
} ThrNode, *BiThrTree;

BiThrTree pre;

// 返回指向二叉树结点e的指针
static BiThrTree EPtr(BiThrTree T, ElemType e) {
    BiThrTree p;
    p = T->LChild;
    while(p != T) {
        while(p->LTag == 0) p = p->LChild; // 沿左孩子向下
        if(p->data == e) return p;
        while(p->RTag == 1 && p->RChild != T) {
            p = p->RChild; // 沿右线索访问后继结点
            if(p->data == e) return p;
        }
        p = p->RChild;
    }
    return NULL;
}

Status CreateBiTree(BiThrTree *T) {
    char ch;
    scanf("%c", &ch);
    if(ch == '#') *T = NULL;
    else {
        *T = (BiThrTree)malloc(sizeof(struct ThrNode));
        (*T)->data = ch;
        CreateBiTree(&((*T)->LChild));
        CreateBiTree(&((*T)->RChild));
    }
    return OK;
}

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
            pre->RChild = *p; // 前驱的右孩子指向p(后继)
            pre->RTag = 1;   // 给前驱加上线索
        }
        else (*p)->RTag = 0;
        pre = *p;
        InThreading(&((*p)->RChild));
    }
}

// 带头结点的二叉树中序线索化

void InOrderThreading(BiThrTree *Thrt, BiThrTree *T) {
    *Thrt = (BiThrTree)malloc(sizeof(ThrNode));
    (*Thrt)->LTag = 0;
    (*Thrt)->RTag = 1;
    (*Thrt)->RChild = (*Thrt);
    if(!(*T)) (*Thrt)->LChild = *Thrt;
    else {
        (*Thrt)->LChild = *T;
        pre = *Thrt;
        InThreading(&(*T));
        pre->RChild = (*Thrt);
        pre->RTag = 1;
        (*Thrt)->RChild = pre;
    }
}

// 遍历中序线索二叉树
void InOrderTraverse_Thr(BiThrTree T) {
    BiThrTree p;
    p = T->LChild;
    while(p != T) {
        while(p->LTag == 0) p = p->LChild; // 沿左孩子向下
        printf("%c", p->data);
        while(p->RTag == 1 && p->RChild != T) {
            p = p->RChild; // 沿右线索访问后继结点
            printf("%c", p->data);
        }
        p = p->RChild;
    }
}

ElemType ValuePre(BiThrTree T) {
    BiThrTree p;
    if(!T) return '\0';
    if(T->LTag == 1) return T->LChild->data;
    else {
        p = T->LChild;
        while(p->LTag == 0) p = p->LChild;
        return p->data;
    }
}

ElemType ValueNext(BiThrTree T) {
    BiThrTree p;
    if(!T) return '\0';
    if(T->RTag == 1) return T->RChild->data;
    else {
        p = T->RChild;
        while(p->LTag == 0) p = p->LChild;
        return p->data;
    }
}

void InOrderTraverse(BiThrTree T) {
    if(T) {
        InOrderTraverse(T->LChild);
        printf("%c", T->data);
        InOrderTraverse(T->RChild);
    }
}

int main() {
    BiThrTree T;
    BiThrTree ThrTree;
    BiThrTree p1; 
    BiThrTree p2;
    Status status;
    status = CreateBiTree(&T);
    printf("创建二叉树 status=%d\n", status);
    InOrderTraverse(T);
    printf("遍历中序二叉树\n");
    InOrderThreading(&ThrTree, &T);
    InOrderTraverse_Thr(ThrTree);
    printf("遍历中序线索二叉树\n");
    p1 = EPtr(ThrTree, 'A');
    printf("查找A结点的指针=%c\n", p1->data);
    printf("A的前驱=%c\n", ValuePre(p1));
    printf("A的后驱=%c\n", ValueNext(p1));
    p2 = EPtr(ThrTree, 'C');
    printf("查找C结点的指针=%c\n", p2->data);
    printf("C的前驱=%c\n", ValuePre(p2));
    printf("C的后驱=%c\n", ValueNext(p2));
    return 0;
}
