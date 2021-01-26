#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 10
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;
typedef struct SNode {
    ElemType data;
    struct SNode *next;
} SNode, *LinkStack;

Status InitStack(LinkStack *S) {
    *S = NULL;
    return OK;
}

Status DestroyStack(LinkStack *S) {
}

Status ClearStack(LinkStack *S) {
    LinkStack p, q;
    p = *S;
    while(p) {
        q = p;
        p = p->next;
        printf("清除%d，", q->data);
        free(q);
    }
    return OK;
}

Status StackEmpty(LinkStack S) {
    return (int)(S == NULL);
}

int StackLength(LinkStack S) {
    int count = 0;
    LinkStack p = S;
    while(p) {
        count++;
        p = p->next;
    }
    return count;
}

ElemType GetTop(LinkStack S) {
    return S->data;
}

Status Push(LinkStack *S, ElemType e) {
    LinkStack p = (LinkStack)malloc(sizeof(SNode));
    if(!p) return ERROR;
    p->data = e;
    p->next = *S;
    *S = p;
    return OK;
}

Status Pop(LinkStack *S, ElemType *e) {
   if(StackEmpty(*S)) return ERROR;
   LinkStack p = *S;
   *e = p->data;
   *S = (*S)->next;
   free(p);
   return OK;
}

void StackTraverse(LinkStack S) {
    LinkStack p = S;
    while(p) {
        printf("%d", p->data);
        p = p->next;
    };
    printf(" 遍历结束\n");
}

int main() {
    LinkStack S;
    ElemType e;
    Status status;
    InitStack(&S);
    for(int i = 1; i < 7; i++) {
        status = Push(&S, i);
        printf("进栈：status=%d, 进栈元素=%d\n", status, i);
    }
    status = Pop(&S, &e);
    printf("出栈：status=%d, 出栈元素=%d\n", status, e);
    printf("栈顶元素：%d\n", GetTop(S));
    printf("元素个数：%d\n", StackLength(S));
    StackTraverse(S);
    status = ClearStack(&S);
    return 0;
}
