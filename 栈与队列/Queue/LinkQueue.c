#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef char ElemType;

typedef struct QNode {
    ElemType data;
    Queue head;
    Queue tail
} QNode, *Queue;

Status InitQueue();

Status DestroyQueue();

Status ClearQueue();

Status QueueEmpty();

int QueueLength(Queue Q) {
    int i = 0;
    return i;
}

GetHead();

/**
初始条件：Q为非空队列
操作结果：插入元素为Q的队尾元素
*/
EnQueue();

DeQueue();

QueueTraverse();