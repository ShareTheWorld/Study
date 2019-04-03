#include<stdio.h>
int len=0;
void printArray(int arr[]){

    for(int i = 0; i < len; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void quickSort(int arr[],int low,int high){
    int key=arr[low];
    int i=low;
    int j=high;
    if(high-low<=1) return;
    while(1){
        //from right to left find item<key
        while(i<j&&arr[--j]>=key){
        }
        //swap
        arr[i]=arr[j];
        arr[j]=key;
        printArray(arr);

        //from left to right find item>key
        while(i<j&&arr[++i]<=key){
        }
        //swap
        arr[j]=arr[i];
        arr[i]=key;
        printArray(arr);
        //break;
        if(i==j)break;
    }
    printf("\n\n");
    //递归
    quickSort(arr,low,i);
    quickSort(arr,i+1,high);
}


int main (int argc, char* argv){
    int arr[]={9,7,6,5,4,3,2,1,0};
    len=sizeof(arr) / sizeof(int);
    printArray(arr);
    quickSort(arr,0,len);
}
