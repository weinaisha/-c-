#include <stdio.h>
#include <stdlib.h>
/**
 * ֱ�Ӳ�������,��������ļ�¼�������Ҵ��������еĹؼ��ֻ�������ʱ��Ч�ʽϸ�
 * ʱ�临�Ӷ� O(n^2)
 * �ռ临�Ӷ� O(1)
*/
#define MAX 50
typedef int keyType;
typedef struct {
    keyType key;
} RedType;
typedef struct SqList {
    RedType r[MAX + 1]; // r[0]�����ڱ���Ԫ
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
    printf("\n�����������");
    for (i = 1; i <= list.length; i++) {
        printf("%d ", list.r[i].key);
    }
    
    return 0;
}
