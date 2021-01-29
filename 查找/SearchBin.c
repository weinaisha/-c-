#include <stdio.h>

int SearchBin(int *ST, int length, int key) {
    int low = 1;
    int high = length;
    int mid;
    while( low <= high ) {
        mid = (low + high) / 2;
        if(ST[mid - 1] == key) {
            return mid;
        } else if(ST[mid - 1] > key) {
            high = mid - 1;
        } else if(ST[mid - 1] < key) {
            low = mid + 1;
        }
    }
    return 0;
}

int main() {
    int arr[11] = { 5, 16, 20, 27, 30, 36, 44, 55, 60, 67, 72 };
    int index;
    index = SearchBin(arr, sizeof(arr)/sizeof(arr[0]), 43);
    if(index == 0) {
        printf("û���ҵ�\n");
    } else {
        printf("�ҵ���%d�ǵ�%d��Ԫ��\n", 44, index);
    }
    return 0;
}