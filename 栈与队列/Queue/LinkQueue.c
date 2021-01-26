#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef int ElemType;

// 队列元素结构
typedef struct QNode {
    ElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

// 队列结构
typedef struct {
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

Status InitQueue(LinkQueue *Q) {
    if(Q == NULL) return ERROR;
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if (!(Q->front)) exit(0);
    Q->front->next = NULL;
    return OK;
}

Status DestroyQueue(LinkQueue *Q) {
    if(Q == NULL) {
        return ERROR;
    }
    
    while((*Q).front) {
        (*Q).rear = (*Q).front->next;
        free((*Q).front);
        (*Q).front = (*Q).rear;
    }
    
    return OK;
}

Status QueueEmpty(LinkQueue Q) {
    if(Q.front == Q.rear) return TRUE;
    else {
        return FALSE;
    }
}

Status ClearQueue(LinkQueue *Q) {
    if(QueueEmpty(*Q)) return OK;
    Q->rear = Q->front->next;
    while(Q->rear) {
        Q->front->next = Q->rear->next;
        free(Q->rear);
        Q->rear = Q->front->next;
    }
    Q->rear = Q->front;
    return OK;
}

int QueueLength(LinkQueue Q) {
    if(QueueEmpty(Q)) return 0;
    int i = 0;
    QueuePtr p = Q.front; 
    while(p != Q.rear) {
        i++;
        p = p->next;
    }
    return i;
}

ElemType GetHead(LinkQueue Q) {
    if(QueueEmpty(Q)) return ERROR;
    return Q.front->next->data;
}

Status EnQueue(LinkQueue *Q, ElemType e) {
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return OK;
}

Status DeQueue(LinkQueue *Q, ElemType *e) {
    if(QueueEmpty(*Q)) return ERROR;
    QueuePtr p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if(Q->rear == p) Q->rear = Q->front; //队列只有最后一个元素时
    free(p);
    return OK;
}

void QueueTraverse(LinkQueue Q) {
    if(QueueEmpty(Q)) return;
    QueuePtr p = Q.front->next; 
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("遍历结束\n");
}