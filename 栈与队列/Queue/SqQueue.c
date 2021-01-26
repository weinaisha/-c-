#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 6

typedef int Status;
typedef int ElemType;
typedef struct {
    ElemType *base;
    int front;
    int rear;
} SqQueue;

// ����һ���ն���Q
Status InitQueue(SqQueue *Q) {
    if(Q == NULL) return ERROR;
    Q->base = malloc(sizeof(ElemType) * MAXSIZE);
    if(!(Q->base)) exit(0);
    Q->front = Q->rear = 0;
    return OK;
}

Status DestroyQueue(SqQueue *Q) {
    if(Q == NULL) {
        return ERROR;
    }
    
    if(Q->base) {
        free(Q->base);
    }
    
    Q->base = NULL;
    Q->front = Q->rear = 0;
    
    return OK;
}

Status ClearQueue(SqQueue *Q) {
    Q->front = Q->rear = 0;
    return OK;
}

Status QueueEmpty(SqQueue *Q) {
    if(Q->front == Q->rear)
        return TRUE;
    else
        return FALSE;
}

int QueueLength(SqQueue Q) {
    if(Q.base == NULL) return 0;
    // return Q.rear - Q.front; ��ѭ������,βָ��-ͷָ��
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE; //ѭ������
}

ElemType GetHead(SqQueue Q) {
    if(Q.front == Q.rear || Q.base == NULL) return ERROR;
    return Q.base[Q.front];
}

Status EnQueue(SqQueue *Q, ElemType e) {
    if(Q == NULL || Q->base == NULL) {
        return ERROR;
    }
    if(Q->front == (Q->rear + 1) % MAXSIZE) return ERROR;
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    printf("βָ�� %d ", Q->rear);
    return OK;
}

ElemType DeQueue(SqQueue *Q) {
    if(QueueEmpty(Q)) return ERROR; // �ӿ�
    ElemType e = Q->base[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    printf("ͷָ�� %d ", Q->front);
    return e;
}

void QueueTraverse(SqQueue Q) {
    if(QueueEmpty(&Q)) return;
    int i;
    i = Q.front;
    while(i != Q.rear) {
        printf("%d ", Q.base[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf(" ��������\n");
}

