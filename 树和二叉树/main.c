#include "BiTree.c"

int main() {
    BiTree T;
    BiTree C;
    char T_chr[] = "ABC##DE#G##F###";
    char C_chr[] = "LM#N####";
    int status = 0;
    int depth = 0;
    
    status = CreateBiTree(&T);
    printf("先序创建T： status=%d\n", status);
    PreOrderTraverse(T);
    printf("--先序遍历T\n");
    InOrderTraverse(T);
    printf("--中序遍历T\n");
    PostOrderTraverse(T);
    printf("--后序遍历T\n");
    depth = BiTreeDepth(T);
    printf("深度：depth=%d\n", depth);
    Assign(&T, 'F', 'G');
    Assign(&T, 'G', 'F');
    printf("修改F=>G, G=>F：");
    PreOrderTraverse(T);
    printf("--先序遍历\n");
    printf("根结点：%c\n", Root(T));
    printf("D结点的双亲：%c\n", Parent(T, 'D'));
    printf("E结点的左孩子：%c\n", LeftChild(T, 'E'));
    printf("E结点的右孩子：%c\n", RightChild(T, 'E'));
    printf("D结点的左兄弟：%c\n", LeftSibling(T, 'D'));
    printf("E结点的右兄弟：%c\n", RightSibling(T, 'E'));
    printf("先序创建C： status=%d\n", status);
    status = CreateBiTree(&C);
    InsertChild(&T, 'D', 1, &C);
    PreOrderTraverse(T);
    printf("--先序遍历T\n");
    InOrderTraverse(T);
    printf("--中序遍历T\n");
    status = DeleteChild(&T, 'M', 1);
    printf("删除M结点的右孩子：status=%d\n", status);
    PreOrderTraverse(T);
    printf("--先序遍历T\n");
    return 0;
}