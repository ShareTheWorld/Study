#include <stdio.h>
void printArray(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int p = arr[i];
        int j = i - 1;
        for (; j >= 0; j--) {
            if (arr[j] <= p) {
                arr[j + 1] = p;
                break;
            } else {
                arr[j + 1] = arr[j];
            }
        }
        if (j == -1)
            arr[0] = p;
        printf("%d  ->  ", i);
        printArray(arr, n);
    }
}

int main(int argc, char *argv[]) {
    int arr[] = {9, 5, 7, 8, 4, 2, 6, 1, 3};
    int len = sizeof(arr) / sizeof(arr[0]);
    insertSort(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}
