#include "SqQueue.c"

int main() {
    SqQueue Q;
    Status status;
    status = InitQueue(&Q);
    printf("初始化队列 status=%d, front=%p, rear=%p\n", status, Q.front, Q.rear);
    for(int i = 1; i < 3; i++) {
        status = EnQueue(&Q, i);
        printf("进队：status=%d, 进队元素=%d\n", status, i);
    }
    printf("出队：元素=%d\n", DeQueue(&Q));
    printf("返回对头元素：%d\n", GetHead(Q));
    return 0;
}