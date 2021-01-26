#include "SqQueue.c"
// #include "LinkQueue.c"

int main() {
    SqQueue Q;
    Status status;
    status = InitQueue(&Q);
    printf("初始化队列 status=%d, front=%p, rear=%p\n", status, Q.front, Q.rear);
    for(int i = 1; i < 7; i++) {
        status = EnQueue(&Q, i);
        printf("进队：status=%d, 进队元素=%d\n", status, i);
    }
    printf("头元素：%d\n", GetHead(Q));
    printf("出队：元素=%d\n", DeQueue(&Q));
    status = EnQueue(&Q, 7);
    printf("进队：status=%d, 进队元素=%d\n", status, 7);
    QueueTraverse(Q);
    return 0;
}

// int main() {
//     LinkQueue Q;
//     Status status;
//     QueuePtr headPtr;
//     ElemType e;
//     status = InitQueue(&Q);
//     printf("初始化队列 status=%d, front=%p, rear=%p\n", status, Q.front, Q.rear);
//     for(int i = 1; i < 6; i++) {
//         status = EnQueue(&Q, i);
//         printf("进队：status=%d, 进队元素=%d\n", status, i);
//     }
//     printf("头元素：%d\n", GetHead(Q));
//     status = DeQueue(&Q, &e);
//     printf("出队：元素=%d\n", e);
//     printf("队列长度：%d\n", QueueLength(Q));
//     EnQueue(&Q, 7);
//     QueueTraverse(Q);
//     status = ClearQueue(&Q);
//     printf("清除队列：status=%d, 长度=%d\n", status, QueueLength(Q));
//     return 0;
// }