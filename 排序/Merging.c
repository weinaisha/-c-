#include <stdio.h>
/**
 * ≤¢πÈ≈≈–Ú
*/

void Merge(int *R, int *T, int low, int mid, int high) {
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
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
        MSort(R, S, low, mid);
        MSort(R, S, mid + 1, high);
        Merge(S, T, low, mid, high);
    }
    
}

void MergeSort(int *r) {
    MSort(r, r, 0, 9);
}

int main() {
    int i;
    int sort[10] = {23, 12, 9, 5, 45, 10, 16, 4, 7, 76};
    MergeSort(sort);
    printf("Ω·π˚£∫");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", sort[i]);
    }
    return 0;
}