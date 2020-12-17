#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef int Status;
typedef int ElemType;
typedef struct {
    int maxSize;
    ElemType* base;
    ElemType* top;
} SqQueue;

Status InitQueue(SqQueue *Q) {
    (*Q).base = malloc(sizeof(ElemType) * MAXSIZE);
    if(!(*Q).base) return ERROR;   // �洢����ʧ��
    (*Q).top = (*Q).base;
    (*Q).maxSize = MAXSIZE;
    return OK;
}

Status QueueInsert(SqQueue *Q, ElemType e) {
    if((*Q).top - (*Q).base == MAXSIZE) return ERROR;
    printf("��e=%d", e);
    *((*Q).top) = e;
    (*Q).top++;
    return OK;
}

int QueueLength(SqQueue Q) {
    return Q.top - Q.base;
}

int main() {
    SqQueue Q;
    Status status;
    status = InitQueue(&Q);
    printf("��ʼ������ status=%d, top=%p, base=%p\n", status, Q.top, Q.base);
    for(int j = 1; j<4; j++) {
        status = QueueInsert(&Q, j);
        printf("���ӣ�status=%d, ����Ԫ��=%d, length=%d\n", status, j, QueueLength(Q));
    }
    return 0;
}