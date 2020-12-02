#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 20
typedef int ElementType;
typedef struct LNode *List;
struct LNode
{
    ElementType Data[MAXSIZE];
    int Last;
};

// 初始化一个空线性表L
List MackEmpty() {
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNode));
    PtrL->Last = -1;
    return PtrL;
}

// 根据位序K，返回相应元素
ElementType FindKth(int K, List PtrL) {
    if(K > PtrL->Last || K < 0){
        printf("不存在第%d个元素", K);
    }
    return PtrL->Data[K];
}

// 在线性表L中查找X的第一次出现位置
int Find(ElementType X, List PtrL) {
    int i = 0;
    while(i <= PtrL->Last && PtrL->Data[i] != X) {
        i++;
    }
    if(i > PtrL->Last) {
        return -1;
    } else {
        return i;
    }
    
}

// 在位序i前插入一个新元素X
void Insert(ElementType X, int i, List PtrL) {
    int j;
    if(PtrL->Last+1 == MAXSIZE) {
        printf("表空间已满");
        return;
    }
    if(i < 1 || i > PtrL->Last + 2) {
        printf("位置不合法"); // 判断是否在1到n+1之间
        return;
    }
    for (j = PtrL->Last; j >= i - 1; j--) {
        PtrL->Data[j+1] = PtrL->Data[j];
    }
    PtrL->Data[i-1] = X;
    PtrL->Last++;
    return;
}

// 删除指定位序i的元素
void Delete(int i, List PtrL) {
    int j;
    if(i < 1 || i > PtrL->Last + 1) {
        printf("不存在第%d个元素", i);
        return;
    }
    for(j = i; j < PtrL->Last + 1; j++) {
        // 将ai+1-an顺序向前移动
        PtrL->Data[j] = PtrL->Data[j+1];
    }
    PtrL->Last--;
    return;
}

// 返回线性表L的长度n
int Length(List L) {
    return L->Last+1;
}

int main() {
    List L;
    int index;
    L = MackEmpty();
    printf("test MackEmpty: L.last=%d\n, L=%p\n", L->Last, L); // L地址
    for (int i = 5; i >= 1; i--)
    {
        Insert(i, 1, L);
    }
    for (int j = 0; j < 5; j++)
    {
       printf("test Insert: L.data[%d]=%d\n", j, L->Data[j]);
    }
    index = Find(3, L);
    printf("test Find: 3 index=%d\n", index);
    Delete(2, L);
    printf("test Delete: delete data[2]\n");
    for (int j = 0; j < 5; j++)
    {
       printf("%d ", L->Data[j]);
    }
    printf("\n");
    
    return 0;
}