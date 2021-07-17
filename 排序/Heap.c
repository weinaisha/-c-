#include <stdio.h>
/**
 * 堆排序
*/

void heapAdjust(int *r, int s, int n) {
    int rc = r[s];
    int i;
    for (i = 2 * s; i <= n; i = i * 2)
    {
        if(i < n && r[i] < r[i + 1]) ++i;  // 大根堆
        if(rc >= r[i]) break;
        // if(i < n && r[i] > r[i + 1]) ++i; // 小根堆
        // if(rc <= r[i]) break;
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
    int sort[9] = {0, 15, 9, 7, 8, 20, -1, 7, 4 };
    creatHeap(sort, 8);
    printf("创建大根堆：");
    for (i = 1; i < 9; i++) printf("%d ", sort[i]);
    for (j = 8; j > 1; j--)
    {
        t = sort[j];
        sort[j] = sort[1];
        sort[1] = t;
        heapAdjust(sort, 1, j - 1);
    }
    printf("\n排序：");
    for (i = 1; i < 9; i++) printf("%d ", sort[i]);
    return 0;
}