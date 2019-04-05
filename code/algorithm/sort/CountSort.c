#include <stdio.h>

int arr[] = {92, 93, 96, 97, 94, 98, 99, 90, 96, 94, 95};
int len = sizeof(arr) / sizeof(int);

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void countSort(int arr[], int len) {
    // get max and min
    int min = arr[0], max = arr[0];
    for (int i = 0; i < len; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    printf("min=%d,max=%d\n", min, max);

    //统计出现次数
    int n = max - min + 1;
    int countArray[n];
    for (int i = 0; i < n; i++)
        countArray[i] = 0;
    for (int i = 0; i < len; i++) {
        countArray[arr[i] - min]++;
    }
    printArray(countArray, n);

    //统计元素应该在的位置，对数组作变形
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += countArray[i];
        countArray[i] = sum;
    }
    printArray(countArray, n);

    // sort
    int temp[len];
    for (int i = len - 1; i >= 0; i--) {
        int p = --countArray[arr[i] - min];
        temp[p] = arr[i];
    }
    printArray(temp, len);

    // copy
    for (int i = 0; i < len; i++) {
        arr[i] = temp[i];
    }
    printArray(arr, len);
}
int main(int argc, char *argv[]) {
    printArray(arr, len);
    countSort(arr, len);
}
