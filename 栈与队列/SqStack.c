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
    if(!(*S).base) return ERROR;   // 存储分配失败
    (*S).top = (*S).base;        // top初始为base，空栈
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
    if(S.base == S.top) return ERROR; // 判断是否为空栈
    return S.top-1;
}

Status Push(SqStack *S, SElemType e) {
    if((*S).top - (*S).base == MAXSIZE) return ERROR; // 判断栈是否已满
    *((*S).top) = e; //元素e压入栈顶，栈顶指针加1
    (*S).top++;
    return OK;
}

Status Pop(SqStack *S, SElemType *e) {
    if((*S).base == (*S).top) return ERROR;
    e = (*S).top-1; // 栈顶指针减1，将栈顶元素赋给e
    (*S).top--;
    return OK;
}

//StackTraverse() {}

int main() {
    SqStack S;
    SElemType S_top;
    Status status;
    InitStack(&S);
    printf("初始化一个空栈：S.base=%p, S.top=%d\n", S.base, S.top);
    for(int i = 1; i < 4; i++) {
        status = Push(&S, i);
        printf("入栈: status=%d, 元素=%d\n", status, i);
    }
    S_top = *GetTop(S);
    printf("获取栈顶元素%d\n", S_top);
    status = Pop(&S, &S_top);
    printf("出栈：status=%d, 元素=%d\n", status, S_top);
    printf("栈长度：length=%d\n", StackLength(S));
    status = ClearStack(&S);
    printf("清除栈：status=%d", status);
    printf("栈长度：length=%d\n", StackLength(S));
    return 0;
}
