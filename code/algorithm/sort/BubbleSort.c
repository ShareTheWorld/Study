#include <stdio.h>
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

int main(int argc, char *args[]) {
    int arr[] = {6, 5, 7, 2, 3, 5, 3, 9};
    int len = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}
