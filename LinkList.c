#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1

typedef int Status;
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode;
typedef struct LNode *LinkList;

Status InitList(LinkList *L) {
    *L = (LinkList)malloc(sizeof(struct LNode)); //产生头结点，并使L指向此头结点
    if(!(*L)) return ERROR; // 分配失败
    (*L)->next = NULL;
    return OK;
}

Status LinstEmpty(LinkList L) {
    if(L->next) {
        return FALSE;
    } else {
        return TRUE;
    }
}

Status clearList(LinkList L) {
    if(!L->next) return ERROR;
    LinkList p, q;
    p = L->next;
    while(p) {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL; // 头指针域为空
    return OK;
}

int ListLength(LinkList L) {
    int i = 0;
    LinkList p = L->next;
    while(p) {
        p = p->next;
        i++;
    }
    return i;
}

Status ListInsert(LinkList L, int i, ElemType e) {
    //在带头结点的单链表L中第i个位置即插入到结点ai-1与ai之间插入值为e的新结点
    int j = 0;
    LinkList p = L;
    LinkList node;
    while(p && (j < i - 1)) {
        p = p->next;
        ++j;
    }
    if(!p || j>i-1) return ERROR;
    node = (LinkList)malloc(sizeof(struct LNode));
    node->data = e;
    node->next = p->next;
    p->next = node;
    return OK;
}

Status GetElem(LinkList L, int i, ElemType *e) {
    //在带头结点的单链表L中根据序号i获取元素的值,用e返回L中第i个数据元素的值
    int j = 1;
    LinkList p = L->next; //p指向第一个节点(首元节点)
    while(p && j < i) { 
        //指针p为空计数器j大于i, 说明指定的序号i值不合法（i大于表长n或l小于等于0
        p = p->next;
        j++;
    }
    if(!p || j>i) return ERROR;
    *e = p->data;
    return OK;
}

LNode *LocateElem(LinkList L, ElemType e) {
    //在带头结点的单链表L中查找值为e的元素
    LinkList p = L->next;
    while(p && p->data != e) {
        p = p->next;
    }
    if(!p || p->data != e) return ERROR;
    return p;
}

Status ListDelete(LinkList L, int i) {
    // 在带头结点的单链表L中，删除第i个元素
    int j = 0;
    LinkList p = L;
    LinkList q;
    while(p && j < i - 1) { //查找位置i的结点并由指针p指向该结点
        p = p->next;
        j++;
    }
    if(!p || j > i - 1) return ERROR;
    q = p->next;
    p->next = q->next;
    free(q);
    return OK;
}

// 前插法
void CreateList_H(LinkList *L, int n) {
    *L=(LinkList)malloc(sizeof(struct LNode));
    (*L)->next = NULL;
    for(int i = 0; i < n; i++) {
        LinkList p = (LinkList)malloc(sizeof(struct LNode));
        printf("input data:");
        scanf("%d", &(p->data));
        p->next = (*L)->next;
        (*L)->next = p;
    }
    return;
}

// 后插法
void CreateList_R(LinkList *L, int n) {
    *L = (LinkList)malloc(sizeof(struct LNode));
    (*L)->next = NULL;
    LinkList r = (*L);
    for(int i = 0; i < n; i++) {
        LinkList p = (LinkList)malloc(sizeof(struct LNode));
        printf("input data:");
        scanf("%d", &(p->data));
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

int main() {
    LinkList L;
    LinkList L_H;
    LinkList L_R;
    LNode node;
    int len_H = 0;
    int len = 0;
    ElemType elem;
    Status status;
    status = InitList(&L);
    printf("L->next=%d,L->data=%d,status=%d\n", L->next, L->data, status);
    printf("test CreateList_H start\n");
    CreateList_H(&L_H, 4);
    len_H = ListLength(L_H);
    printf("test CreateList_H end:L_H.length=%d\n", len);
    status = ListInsert(L_H, 2, 5);
    len_H = ListLength(L_H);
    printf("test ListInsert status=%d, L_H.length=%d\n", status, len);
    for(int i = 1; i<6; i++) {
        status = GetElem(L_H, i, &elem);
        printf("test GetElem status=%d, i=%d, elem=%d\n", status, i, elem);
    }
    node = *LocateElem(L_H, 2);
    printf("test LocateElem (node.next)->data=%d\n", (node.next)->data);
    status = ListDelete(L_H, 3);
    printf("test ListDelete status=%d, L_H.length=%d\n", status, ListLength(L_H));
    for(int i = 1; i<5; i++) {
        status = GetElem(L_H, i, &elem);
        printf("test GetElem status=%d, i=%d, elem=%d\n", status, i, elem);
    }
    printf("test CreateList_R start: L_R.length=%d\n", ListLength(L_R));
    CreateList_R(&L_R, 4);
    printf("test CreateList_R end: L_R.length=%d\n", ListLength(L_R));
    for(int i = 1; i<5; i++) {
        status = GetElem(L_R, i, &elem);
        printf("test GetElem status=%d, i=%d, elem=%d\n", status, i, elem);
    }
    return 0;
}