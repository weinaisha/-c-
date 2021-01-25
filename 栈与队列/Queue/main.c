#include "SqQueue.c"

int main() {
    SqQueue Q;
    Status status;
    status = InitQueue(&Q);
    printf("��ʼ������ status=%d, front=%p, rear=%p\n", status, Q.front, Q.rear);
    for(int i = 1; i < 3; i++) {
        status = EnQueue(&Q, i);
        printf("���ӣ�status=%d, ����Ԫ��=%d\n", status, i);
    }
    printf("���ӣ�Ԫ��=%d\n", DeQueue(&Q));
    printf("���ض�ͷԪ�أ�%d\n", GetHead(Q));
    return 0;
}