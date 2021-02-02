#include <stdio.h>
#include <stdlib.h>

typedef struct BSNode {
    int data;
    struct BSNode *LChild, *RChild;
} BSNode, *BSTree;

// ����ָ����������e��˫�׽���ָ��
static BSTree PPtr(BSTree T, int e) {
    BSTree pl, pr;
    if(T == NULL || T->data == e) { //�����������û��˫��
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

// ����
Status Insert(BSTree *T, int e) {
    BSTree p;
    if(*T == NULL) {
        p = (BSTree)malloc(sizeof(BSNode));
        p->data = e;
        p->LChild = p->RChild = NULL;
        *T = p;
        printf("��������Ҷ���%d\n", p->data);
    }
    else if((*T)->data > e) Insert(&((*T)->LChild), e);
    else if((*T)->data < e) Insert(&((*T)->RChild), e);
    return OK;
}

// ��������������
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

// ����
void InOrderTraverse(BSTree T) {
    if(T) {
        InOrderTraverse(T->LChild);
        printf("%d ", T->data);
        InOrderTraverse(T->RChild);
    }
}

// ����
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

// ɾ��
Status Delete(BSTree *T, int e) {
    BSTree f, p, q, s;
    p = SearchBST(*T, e);
    if(!p) return ERROR; // �Ҳ���ɾ���ڵ㷵��
    f = PPtr(*T, p->data); // ɾ���ڵ�ĸ��׽��
    if((p->LChild) && (p->RChild)) { // ��ɾ����������������Ϊ��
        q = p;
        s = p->LChild; //����p��ǰ����Ϊ�����������·��Ľ��
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
    if(!f) *T = p; // ��ɾ�����Ϊ�����
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
    printf("--�����õ��������Ա�\n");
    printf("���ҽڵ㣺");
    p = SearchBST(T, 17);
    if(!p) printf("���%d������\n", e);
    else{
        printf("�ҵ����%d\n", p->data);
    } 
    printf("ɾ���ڵ㣺");
    status = Delete(&T, 78);
    printf("ɾ�����%d��status=%d\n", 78, status);
    InOrderTraverse(T);
    printf("--�����õ��������Ա�\n");
    return 0;
}
