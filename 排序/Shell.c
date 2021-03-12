#include <stdio.h>
/**
 * 希尔排序
 * 跳跃式的移动-不稳定
 * 增量序列的最后一个增量必须等于1
*/

/**
 * shell增量N/2; O(N^2)
 * Frank&Lazarus 2[N/4]+1; O(N^(3/2)) 教材事例dt[k]=2^(t-k+l)-1 t未排序趟数，l<=k<=t<=log2(n+l)
 * Hibbard增量2^k - 1 => h = 1; h = 2h + 1; O(N^(3/2))
 * Knuth增量:1,4,13,40,...,(3^k - 1)/2 => h = 1; h = 3h + 1
*/
// void hibbard(int length, int *dk) {
//     int i, k = 1;
//     *dk = 2 * (length / 4) + 1;
//     i = *dk;
//     while (2 * (i / 4) + 1 > 1)
//     {
//         (*dk)[k] = i;
//         k++;
//     }
// }
int main() {
    int i, j, k, gap;
    int arr[3] = {5, 3, 1};
    int sort[10] = {0, 23, 12, 9, 5, 45, 10, 16, 4, 7};
    for (i = 0; i < 3; i++)
    {
        gap = arr[i];
        for (j = gap + 1; j < 10; ++j)
        {
            if(sort[j] < sort[j - gap]) {
                sort[0] = sort[j];
                for (k = j - gap; k > 0 && sort[0] < sort[k]; k -= gap)
                {
                    sort[k + gap] = sort[k];
                }
                sort[k + gap] = sort[0];
            }
        }
    }
    for (i = 1; i < 10; i++)
    {
       printf("%d ", sort[i]);
    }
    
    
    return 0;
}

