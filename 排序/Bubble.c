#include <stdio.h>
/**
 * Ã°ÅÝÅÅÐò
 * Ê±¼ä¸´ÔÓ¶ÈO(n^2)
 * ¿Õ¼ä¸´ÔÓ¶ÈO(1)
*/
int main() {
    int i, m = 10, flag = 1, t;
    int sort[10] = {23, 12, 9, 5, 45, 10, 16, 4, 7, 76};
    while ((m > 0) && flag == 1)
    {
        flag = 0;
        for (i = 0; i < m; i++)
        {
            if(sort[i] > sort[i + 1]) {
                flag = 1;
                t = sort[i];
                sort[i] = sort[i + 1];
                sort[i + 1] = t;
            }
        }
        --m;
    }
    
    
    for (i = 0; i < 10; i++)
    {
        printf("%d ", sort[i]);
    }

    return 0;
}


