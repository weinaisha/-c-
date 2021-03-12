/**
 * �۰��������
 * ʱ�临�Ӷ�O(n^2)
 * �ռ临�Ӷ�O(1)
 * ��ֱ�Ӳ���Աȵ�n�ϴ�ʱ�۰���ұ�˳����ҿ죬��ֻ������˳��ṹ
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
typedef int keyType;
typedef struct {
    keyType key;
} RedType;
typedef struct SqList {
    RedType r[MAX + 1]; // r[0]�����ڱ���Ԫ
    int length;
} SqList;

int main() {
    int i, j, status = 0, k, flag = 0, low, high, m;
    k = 2;
    SqList list;
    list.length = 0;
    printf("status=%d, list.length=%d\n", status, list.length);
    printf("����Ҫ����������ÿո��������#�Ž���\n");
    flag = scanf("%d", &(list.r[1].key));
    while (flag == 1)
    {
        flag = scanf("%d", &(list.r[k].key));
        list.length++;
        k++;
    }
    printf("¼��Ҫ���������Ϊ: ");
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
    printf("\n�����������");
    for (i = 1; i <= list.length; i++) {
        printf("%d ", list.r[i].key);
    }
    
    return 0;
}
