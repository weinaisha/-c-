/**
 * 折半插入排序
 * 时间复杂度O(n^2)
 * 空间复杂度O(1)
 * 与直接插入对比当n较大时折半查找比顺序查找快，但只能用于顺序结构
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
typedef int keyType;
typedef struct {
    keyType key;
} RedType;
typedef struct SqList {
    RedType r[MAX + 1]; // r[0]用作哨兵单元
    int length;
} SqList;

int main() {
    int i, j, status = 0, k, flag = 0, low, high, m;
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
        list.r[0] = list.r[i];
        low = 1;
        high = i - 1;
        while (low <= high)
        {
            m = (low + high) / 2;
            if(list.r[0].key < list.r[m].key) high = m - 1;
            else {
                low = m + 1;
            }
        }
        for (j = i - 1; j >= high + 1; j--)
        {
            list.r[j + 1] = list.r[j];
        }
        list.r[high + 1] = list.r[0];
    }
    printf("\n输出排序结果：");
    for (i = 1; i <= list.length; i++) {
        printf("%d ", list.r[i].key);
    }
    
    return 0;
}
