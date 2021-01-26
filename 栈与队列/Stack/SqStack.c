#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 10
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;
typedef struct {
    int stackSize;
    ElemType* top;
    ElemType* base;
} SqStack;

Status InitStack(SqStack *S) {
    S->base = malloc(sizeof(ElemType) * MAXSIZE);
    if(!(S->base)) return ERROR;
    S->top = S->base;
    S->stackSize = MAXSIZE;
    return OK;
}

Status StackEmpty(SqStack S) {
    return S.top - S.base == 0;
}

Status DestroyStack(SqStack *S) {
    if(S == NULL) return ERROR;
    free(S->base);
    S->top = S->base = NULL;
    S->stackSize = 0;
    return OK;
}

Status ClearStack(SqStack *S) {
    S->top = S->base;
    return OK;
}

int StackLength(SqStack S) {
    if(S.base == NULL) return 0;
    return (int)(S.top - S.base);
}

ElemType GetTop(SqStack S) {
    return *(S.top - 1);
}

Status Push(SqStack *S, ElemType e) {
   if(S->top - S->base == MAXSIZE) return ERROR;
   *(S->top) = e;
   S->top++;
   return OK;
}

Status Pop(SqStack *S, ElemType *e) {
   if(StackEmpty(*S)) return ERROR;
   --S->top;
   *e = *(S->top);
   return OK;
}

void StackTraverse(SqStack S) {
    int *i;
    ElemType *p = S.base;
    while(p < S.top) { // ��ջ�׿�ʼ����
        printf("%d ", *p);
        p++;
    }
    // for(i = S.top - 1; i >= S.base; i--) {
    //     printf("%d ", *i); // ��ջ����ʼ����
    // }
    printf(" ��������\n");
}

int main() {
    SqStack S;
    Status status;
    ElemType e;
    InitStack(&S);
    for(int i = 1; i < 7; i++) {
        status = Push(&S, i);
        printf("��ջ��status=%d, ��ջԪ��=%d\n", status, i);
    }
    status = Pop(&S, &e);
    printf("��ջ��status=%d, ��ջԪ��=%d\n", status, e);
    printf("ջ��Ԫ�أ�%d\n", GetTop(S));
    printf("Ԫ�ظ�����%d\n", StackLength(S));
    StackTraverse(S);
    return 0;
}
