#include <stdio.h>
#include <stdlib.h>
/**
 * ��������
*/

void Merge(int *R, int *T, int low, int mid, int high) {
    int i, j, k, a, b;
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        // printf("�Ƚϣ�R[i]=%d, mid=%d, high=%d\n", low, mid, high);
        if (R[i] <= R[j]) T[k] = R[i++];
        else
        {
            T[k] = R[j++];
        }
        k++;
    }
    while (i <= mid)
    {
        T[k++] = R[i++];
    }
    while (j <= high)
    {
        T[k++] = R[j++];
    }
}

void MSort(int *R, int *T, int low, int high) {
    int mid;
    int S[10];
    if(low == high) T[low] = R[low];
    else
    {
        mid = (low + high) / 2; 
        MSort(R, S, low, mid); // �ֳ�һ��
        MSort(R, S, mid + 1, high); // �ֳ�һ��
        Merge(S, T, low, mid, high); // �鲢�ӳ���
    }
}

void MergeSort(int *r) {
    MSort(r, r, 0, 9);
}

int main() {
    int i;
    int sort[10] = {23, 12, 9, 5, 45, 10, 16, 4, 7, 76};
    MergeSort(sort);
    printf("�����");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", sort[i]);
    }
    return 0;
}
