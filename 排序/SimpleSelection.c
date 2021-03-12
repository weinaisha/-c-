#include <stdio.h>
/**
 * ºÚµ•—°‘Ò≈≈–Ú O(n^2)
*/

int main() {
    int i, j, length = 10, min, t;
    int sort[10] = {23, 12, 9, 5, 45, 10, 16, 4, 7, 76};
    for (i = 0; i < length; i++)
    {
        min = i;
        for (j = i + 1; j < length; j++)
        {
            if(sort[j] < sort[min]) {
                min = j;
            }
        }
        if(min != i) {
            t = sort[i];
            sort[i] = sort[min];
            sort[min] = t;
        }
    }
    
    for (i = 0; i < 10; i++)
    {
        printf("%d ", sort[i]);
    }

    return 0;
}