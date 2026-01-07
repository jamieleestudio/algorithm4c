//
// Created by lixiaofeng on 1/5/2026.
//
#include <stdio.h>

void testSort(int arr[], int n) {
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n-i-1;j++){
//            if(arr[j] > arr[j+1] ){
//                int temp = arr[j+1];
//                arr[j+1] = arr[j];
//                arr[j] = temp;
//            }
//        }
//    }
//选择排序，选择最小的数，放在最前面

for(int i=0;i<n-1;i++){
    //最小的下标
    int minIndex = i;
    for(int j=i;j<n-1;j++){
        if(arr[j+1] < arr[minIndex]){
            minIndex = j+1;
        }
    }
    //swap
    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
}

}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // 定义一个待排序的数组
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50, 32, 19};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("before sort: \n");
    printArray(arr, n);

    testSort(arr, n);

    printf("after sort: \n");
    printArray(arr, n);

    return 0;
}