#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;
typedef struct StackNode {
    ElemType data;
    struct StackNode *next;
} StackNode, *LinkStack;

Status InitStack(LinkStack *S) {
    *S = NULL;
    return OK;
}

int StackLength(LinkStack S) {
    int i = 0;
    LinkStack p = S;
    while(p) {
        p = p->next;
        i++;
    }
    return i;
}

Status Push(LinkStack *S, ElemType e) {
    LinkStack p = (*S);
    LinkStack q;
    q = (LinkStack)malloc(sizeof(struct StackNode));
    q->data = e;
    q->next = p;
    (*S) = q;
    return OK;
}

Status Pop(LinkStack *S, ElemType *e) {
    if(!S) return ERROR;
    LinkStack p = *S;
    *e = (*S)->data;
    (*S) = (*S)->next;
    free(p);
    return OK;
}

Status GetTop(LinkStack S, ElemType *e) {
    if(!S) return ERROR;
    *e = S->data;
    return OK;
}

int main() {
    LinkStack S;
    Status status;
    ElemType S_top;
    status = InitStack(&S);
    printf("��ʼ������ջ: status=%d, length=%d\n", status, StackLength(S));
    for(int i = 1; i < 4; i++) {
        status = Push(&S, i);
        printf("��ջ: status=%d, Ԫ��=%d, length=%d\n", status, i, StackLength(S));
    }
    status = GetTop(S, &S_top);
    printf("��ȡջ��Ԫ�أ�status=%d, S_top=%d\n", status, S_top);
    status = Pop(&S, &S_top);
    printf("��ջ��������S_top=%d, status=%d, length=%d\n", S_top, status, StackLength(S));
    return 0;
}