#include <stdio.h>
#include <stdlib.h>
/**
 * 直接插入排序,当待排序的记录个数少且待排序序列的关键字基本有序时，效率较高
 * 时间复杂度 O(n^2)
 * 空间复杂度 O(1)
*/
#define MAX 50
typedef int keyType;
typedef struct {
    keyType key;
} RedType;
typedef struct SqList {
    RedType r[MAX + 1]; // r[0]用作哨兵单元
    int length;
} SqList;
int init(SqList *S) {
    S = (SqList*)malloc(sizeof(struct SqList));
    printf("%x", S);
    if (!S) {
        exit(0);
        return 0;
    }
    (*S).length = 0;
    return 1;
}

int main() {
    int i, j, status = 0, k, flag = 0;
    k = 2;
    SqList list;
    list.length = 0;
    printf("status=%d, list.length=%d\n", status, list.length);
    printf("输入要排序的数字用空格隔开，以#号结束\n");
    flag = scanf("%d", &(list.r[1].key));
    while (flag == 1)
    {
        flag = scanf("%d", &(list.r[k].key));
        list.length++;
        k++;
    }
    printf("录入要排序的数字为: ");
    for (i = 1; i <= list.length; i++) {
        printf("%d ", list.r[i].key);
    }
    for (i = 2; i <= list.length; i++)
    {
        if(list.r[i].key < list.r[i - 1].key) {
            list.r[0] = list.r[i];
            list.r[i] = list.r[i - 1];
            for (j = i - 2; list.r[0].key < list.r[j].key; j--)
            {
                list.r[j + 1] = list.r[j];
            }
            list.r[j + 1] = list.r[0];
        }
    }
    printf("\n输出排序结果：");
    for (i = 1; i <= list.length; i++) {
        printf("%d ", list.r[i].key);
    }
    
    return 0;
}
