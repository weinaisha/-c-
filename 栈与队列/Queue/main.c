#include "SqQueue.c"

int main() {
    SqQueue Q;
    Status status;
    status = InitQueue(&Q);
    printf("��ʼ������ status=%d, front=%p, rear=%p\n", status, Q.front, Q.rear);
    for(int i = 1; i < 7; i++) {
        status = EnQueue(&Q, i);
        printf("���ӣ�status=%d, ����Ԫ��=%d\n", status, i);
    }
    printf("ͷԪ�أ�%d\n", GetHead(Q));
    printf("���ӣ�Ԫ��=%d\n", DeQueue(&Q));
    status = EnQueue(&Q, 7);
    printf("���ӣ�status=%d, ����Ԫ��=%d\n", status, 7);
    QueueTraverse(Q);
    return 0;
}