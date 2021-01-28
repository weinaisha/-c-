#include "BiTree.c"

int main() {
    BiTree T;
    BiTree C;
    char T_chr[] = "ABC##DE#G##F###";
    char C_chr[] = "LM#N####";
    int status = 0;
    int depth = 0;
    
    status = CreateBiTree(&T);
    printf("���򴴽�T�� status=%d\n", status);
    PreOrderTraverse(T);
    printf("--�������T\n");
    InOrderTraverse(T);
    printf("--�������T\n");
    PostOrderTraverse(T);
    printf("--�������T\n");
    depth = BiTreeDepth(T);
    printf("��ȣ�depth=%d\n", depth);
    Assign(&T, 'F', 'G');
    Assign(&T, 'G', 'F');
    printf("�޸�F=>G, G=>F��");
    PreOrderTraverse(T);
    printf("--�������\n");
    printf("����㣺%c\n", Root(T));
    printf("D����˫�ף�%c\n", Parent(T, 'D'));
    printf("E�������ӣ�%c\n", LeftChild(T, 'E'));
    printf("E�����Һ��ӣ�%c\n", RightChild(T, 'E'));
    printf("D�������ֵܣ�%c\n", LeftSibling(T, 'D'));
    printf("E�������ֵܣ�%c\n", RightSibling(T, 'E'));
    printf("���򴴽�C�� status=%d\n", status);
    status = CreateBiTree(&C);
    InsertChild(&T, 'D', 1, &C);
    PreOrderTraverse(T);
    printf("--�������T\n");
    InOrderTraverse(T);
    printf("--�������T\n");
    status = DeleteChild(&T, 'M', 1);
    printf("ɾ��M�����Һ��ӣ�status=%d\n", status);
    PreOrderTraverse(T);
    printf("--�������T\n");
    return 0;
}