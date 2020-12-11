#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef int SElemType;
typedef int Status;
typedef struct {
    int stackSize;
    SElemType* top;
    SElemType* base;
} SqStack;

Status InitStack(SqStack *S) {
    (*S).base = malloc(sizeof(SElemType) * MAXSIZE);
    if(!(*S).base) return ERROR;   // �洢����ʧ��
    (*S).top = (*S).base;        // top��ʼΪbase����ջ
    (*S).stackSize = MAXSIZE;
    return OK;
}
//
//DestroyStack() {}
//
Status ClearStack(SqStack *S) {
    (*S).top = (*S).base;
    return OK;
}

int StackLength(SqStack S) {
    return S.top - S.base;
}

SElemType *GetTop(SqStack S) {
    if(S.base == S.top) return ERROR; // �ж��Ƿ�Ϊ��ջ
    return S.top-1;
}

Status Push(SqStack *S, SElemType e) {
    if((*S).top - (*S).base == MAXSIZE) return ERROR; // �ж�ջ�Ƿ�����
    *((*S).top) = e; //Ԫ��eѹ��ջ����ջ��ָ���1
    (*S).top++;
    return OK;
}

Status Pop(SqStack *S, SElemType *e) {
    if((*S).base == (*S).top) return ERROR;
    e = (*S).top-1; // ջ��ָ���1����ջ��Ԫ�ظ���e
    (*S).top--;
    return OK;
}

//StackTraverse() {}

int main() {
    SqStack S;
    SElemType S_top;
    Status status;
    InitStack(&S);
    printf("��ʼ��һ����ջ��S.base=%p, S.top=%d\n", S.base, S.top);
    for(int i = 1; i < 4; i++) {
        status = Push(&S, i);
        printf("��ջ: status=%d, Ԫ��=%d\n", status, i);
    }
    S_top = *GetTop(S);
    printf("��ȡջ��Ԫ��%d\n", S_top);
    status = Pop(&S, &S_top);
    printf("��ջ��status=%d, Ԫ��=%d\n", status, S_top);
    printf("ջ���ȣ�length=%d\n", StackLength(S));
    status = ClearStack(&S);
    printf("���ջ��status=%d", status);
    printf("ջ���ȣ�length=%d\n", StackLength(S));
    return 0;
}
