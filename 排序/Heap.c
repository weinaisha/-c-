#include <stdio.h>
/**
 * 堆排序
*/

void heapAdjust(int *r, int s, int n) {
    int rc = r[s];
    int i;
    for (i = 2 * s; i <= n; i = i * 2)
    {
        if(i < n && r[i] < r[i + 1]) ++i;
        if(rc >= r[i]) break;
        r[s] = r[i];
        s = i;
    }
    r[s] = rc;
}

void creatHeap(int *r, int n) {
    int i;
    for (i = n/2; i > 0; i--)
    {
        heapAdjust(r, i, n);
    }
}

int main () {
    int i, j, t;
    int sort[11] = {0, 23, 12, 9, 5, 45, 10, 16, 4, 7, 76};
    creatHeap(sort, 10);
    printf("创建大根堆：");
    for (i = 1; i < 11; i++) printf("%d ", sort[i]);
    for (j = 10; j > 1; j--)
    {
        t = sort[j];
        sort[j] = sort[1];
        sort[1] = t;
        heapAdjust(sort, 1, j - 1);
    }
    printf("\n排序：");
    for (i = 1; i < 11; i++) printf("%d ", sort[i]);
    return 0;
}