#include <stdio.h>
int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
int len = sizeof(arr) / sizeof(int);
void printArray() {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void shellSort(int arr[], int len) {
    //计算h的初始值
    int h = 1;
    while (h < len / 3) {
        h = h * 3 + 1;
    }
    while (h > 0) {
        printf("h=%d\n", h);
        for (int i = h; i < len; i++) {
            int t = arr[i];
            int j = i - h;
            for (; j >= 0; j -= h) {
                if (arr[j] > t) { // move
                    arr[j + h] = arr[j];
                } else { // put
                    arr[j + h] = t;
                    break;
                }
            }
            if (j < 0)
                arr[j + h] = t; // put first
            printArray();
        }

        printArray();
        h = (h - 1) / 3;
    }
}

int main(int argc, char *argv[]) {
    printArray();
    shellSort(arr, len);
    printArray();
}
