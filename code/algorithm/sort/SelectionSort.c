#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int p = i;
        for (int j = i; j < n; j++) {
            if (arr[j] < arr[p])
                p = j;
        }
        int t = arr[i];
        arr[i] = arr[p];
        arr[p] = t;
    }
}

int main(int argc, char *argv[]) {
    int arr[] = {1, 3, 6, 8, 4, 5, 7, 2, 0};
    int n = sizeof(arr) / sizeof(int);
    selectionSort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
