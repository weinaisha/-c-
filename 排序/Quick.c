#include <stdio.h>
/**
 * 快速排序
*/

int Partition(int *sort, int low, int high) {
    int pivotkey = sort[low];
    while (low < high)
    {
        while (low < high && sort[high] >= pivotkey) --high;
        sort[low] = sort[high];
        while (low < high && sort[low] <= pivotkey) ++low;
        sort[high] = sort[low];
    }
    sort[low] = pivotkey;
    return low;
}

void Quick(int *sort, int low, int high) {
    if(low < high) {
        int pivotloc = Partition(sort, low, high);
        Quick(sort, low, pivotloc - 1);
        Quick(sort, pivotloc + 1, high);
    }
}

void QuickSort(int *sort, int length) {
    Quick(sort, 0, length - 1);
}

int main() {
    int i;
    int sort[10] = {23, 12, 9, 5, 45, 10, 16, 4, 7, 76};
    QuickSort(sort, 10);
    printf("\n结果：");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", sort[i]);
    }
    return 0;
}