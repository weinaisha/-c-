#include "BiTree.c"

int main() {
    BiTree T;
    int status = 0;
    int depth = 0;
    
    status = CreateBiTree(&T);
    printf("����������� status=%d\n", status);
    PreOrderTraverse(T);
    printf("�������\n");
    InOrderTraverse(T);
    printf("�������\n");
    PostOrderTraverse(T);
    printf("�������\n");
    depth = BiTreeDepth(T);
    printf("������T�����depth=%d\n", depth);
    return 0;
}