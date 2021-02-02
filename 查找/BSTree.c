#include <stdio.h>
#include <stdlib.h>

typedef struct BSNode {
    int data;
    struct BSNode *LChild, *RChild;
} BSNode, *BSTree;

// 返回指向二叉树结点e的双亲结点的指针
static BSTree PPtr(BSTree T, int e) {
    BSTree pl, pr;
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

// 插入
Status Insert(BSTree *T, int e) {
    BSTree p;
    if(*T == NULL) {
        p = (BSTree)malloc(sizeof(BSNode));
        p->data = e;
        p->LChild = p->RChild = NULL;
        *T = p;
        printf("插入新子叶结点%d\n", p->data);
    }
    else if((*T)->data > e) Insert(&((*T)->LChild), e);
    else if((*T)->data < e) Insert(&((*T)->RChild), e);
    return OK;
}

// 创建二叉排序树
Status CreatBST(BSTree *T) {
    int judge;
    int e;
    *T = NULL;
    judge = scanf("%d", &e);
    while(judge == 1) {
        Insert(&(*T), e);
        judge = scanf("%d", &e);
    }
    return OK;
}

// 遍历
void InOrderTraverse(BSTree T) {
    if(T) {
        InOrderTraverse(T->LChild);
        printf("%d ", T->data);
        InOrderTraverse(T->RChild);
    }
}

// 查找
BSTree SearchBST(BSTree T, int e) {
    BSTree p;
    p = T;
    while(p) {
        if(p->data == e) return p;
        else if(p->data > e) p = p->LChild;
        else if(p->data < e) p = p->RChild;
    }
    return p;
}

// 删除
Status Delete(BSTree *T, int e) {
    BSTree f, p, q, s;
    p = SearchBST(*T, e);
    if(!p) return ERROR; // 找不到删除节点返回
    f = PPtr(*T, p->data); // 删除节点的父亲结点
    if((p->LChild) && (p->RChild)) { // 被删结点的左右子树均不为空
        q = p;
        s = p->LChild; //查找p的前驱，为左子树最右下方的结点
        while(s->RChild) {
            q = s;
            s = s->RChild;
        }
        p->data = s->data;
        if(q == p) p->LChild = s->LChild;
        else {
            p->RChild = s->LChild;
        }
        free(s);
        return OK;
    }
    else if(!(p->LChild)) {
        q = p;
        p = p->RChild;
    }
    else if(!(p->RChild)) {
        q = p;
        p = p->LChild;
    }
    if(!f) *T = p; // 被删除结点为根结点
    else if(q == f->LChild) f->LChild = p;
    else f->RChild = p;
    free(q);
    return OK;
}

int main() {
    BSTree T;
    BSTree p;
    Status status;
    int e;
    CreatBST(&T);
    InOrderTraverse(T);
    printf("--遍历得到递增线性表\n");
    printf("查找节点：");
    p = SearchBST(T, 17);
    if(!p) printf("结点%d不存在\n", e);
    else{
        printf("找到结点%d\n", p->data);
    } 
    printf("删除节点：");
    status = Delete(&T, 78);
    printf("删除结点%d：status=%d\n", 78, status);
    InOrderTraverse(T);
    printf("--遍历得到递增线性表\n");
    return 0;
}
