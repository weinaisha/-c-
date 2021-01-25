#include "BiTree.c"

int main() {
    BiTree T;
    int status = 0;
    int depth = 0;
    
    status = CreateBiTree(&T);
    printf("先序构造二叉树 status=%d\n", status);
    PreOrderTraverse(T);
    printf("先序遍历\n");
    InOrderTraverse(T);
    printf("中序遍历\n");
    PostOrderTraverse(T);
    printf("后序遍历\n");
    depth = BiTreeDepth(T);
    printf("二叉树T的深度depth=%d\n", depth);
    return 0;
}