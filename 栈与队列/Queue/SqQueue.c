#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 6

typedef int Status;
typedef int ElemType;
typedef struct {
    ElemType data[MAXSIZE];
    int front;
    int rear;
} SqQueue;

// 构造一个空队列Q
Status InitQueue(SqQueue *Q) {
    (*Q).rear = 0;
    (*Q).front = 0;
    return OK;
}

// Status QueueInsert(SqQueue *Q, ElemType e) {
//     if((*Q).top - (*Q).base == MAXSIZE) return ERROR;
//     printf("入e=%d", e);
//     *((*Q).top) = e;
//     (*Q).top++;
//     return OK;
// }

Status EnQueue(SqQueue *Q, ElemType e) {
    (*Q).data[(*Q).rear] = e;
    (*Q).rear++;
    printf("front=%d", (*Q).front);
    printf("rear=%d", (*Q).rear);
    return OK;
}

ElemType DeQueue(SqQueue *Q) {
    ElemType e = (*Q).data[(*Q).front];
    (*Q).front++;
    printf("front=%d", (*Q).front);
    return e;
}

ElemType GetHead(SqQueue Q) {
    printf("front=%d", Q.front);
    return Q.data[Q.front];
}

// int QueueLength(SqQueue Q) {
//     return Q.top - Q.base;
// }
