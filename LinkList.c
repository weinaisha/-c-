#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Elemtype;
typedef int Status;
typedef struct LNode
{
    Elemtype data;
    struct LNode *next;
} LNode, *LinkList;

Status InitList(LinkList L) {
    L->data = (Elemtype)malloc(sizeof(Elemtype));
    L->next = NULL;
    return OK;
}

Status GetElem(LinkList L, int i, Elemtype *e) {
    int j = 1;
    LinkList p = L->next;
    while(p && j < i) {
        p = p->next;
        j++;
    }
    if(!p || j>i) return ERROR;
    *e = p->data;
    return OK;
}

LNode *LocateElem(LinkList L, Elemtype e) {
    LinkList p = L->next;
    while(p && p->data != e) {
        p = p->next;
    }
    return p;
}

Status ListInsert(LinkList L, int i, Elemtype e) {
    LinkList p = L;
    int j = 0;
    while(p && j < i - 1) {
        p = p->next;
        j++;
    }
    if(!p || j > i-1) return ERROR;
    LinkList q;
    q->data = e;
    q->next = p->next;
    p->next = q;
    return OK;
}

Status ListDelete(LinkList L, int i) {
    LinkList p = L->next;
    LinkList q = L->next;
    int j = 1, k = 1;
    // 找到i位置的数据项
    while(p && j < i) {
        p = p->next;
        j++;
    }
    if(!p || j > i) return ERROR; // 没有找到i位置的数据项

    while(p && k < i-1) {
        q = q->next;
        k++;
    }

    q->next = p->next;
    return OK;
}

int main() {
    LinkList L;
    Elemtype e;
    Status status;
    Elemtype a = 1;
    LNode *node;
    InitList(L);
    printf("test InitList: L.next=%p\n", L->next);
    status = GetElem(L, 2, &e);
    printf("test GetElem: status=%d i=2 data=%d\n", status, e);
    node = LocateElem(L, a);
    if(node) {
        printf("test LocateElem: elem=%d node->data=%d\n", a, node->data);
    }else
    {
        printf("test LocateElem: NULL\n");
    }
    
    return 0;
}
