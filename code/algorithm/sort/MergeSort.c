#include <stdio.h>
int len;

void printArray(int arr[]) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}
void mergeSort(int arr[], int low, int high) {
    if (high - low <= 1)
        return;
    if (high - low == 2) {
        if (arr[low] > arr[high - 1]) {
            int t = arr[low];
            arr[low] = arr[high - 1];
            arr[high - 1] = t;
        }
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid, high);
    int t[high - low];
    int i = low;
    int j = mid;
    int p = 0;
    while (1) {
        if (i == mid) {
            t[p++] = arr[j++];
        } else if (j == high) {
            t[p++] = arr[i++];
        } else if (arr[i] > arr[j]) {
            t[p++] = arr[j++];
        } else if (arr[i] <= arr[j]) {
            t[p++] = arr[i++];
        }
        if (p >= high - low)
            break;
    }
    for (int k = 0; k < high - low; k++) {
        arr[low + k] = t[k];
    }
}

int main(int argc, char *argv[]) {
    int arr[] = {6, 8, 5, 4, 9, 2, 7, 3, 1, 0};
    len = sizeof(arr) / sizeof(int);
    mergeSort(arr, 0, len);
    printArray(arr);
}
