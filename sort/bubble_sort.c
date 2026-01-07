#include <stdio.h>

/**
 * 交换两个整数的值
 * @param xp 指向第一个整数的指针
 * @param yp 指向第二个整数的指针
 */
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/**
 * 冒泡排序算法
 * 
 * 冒泡排序（Bubble Sort）是一种简单的排序算法。它重复地走访过要排序的数列，
 * 一次比较两个元素，如果他们的顺序错误就把他们交换过来。
 * 
 * 时间复杂度: O(n^2)
 * 空间复杂度: O(1)
 * 
 * @param arr 待排序的数组
 * @param n 数组的长度
 */
void bubbleSort(int arr[], int n) {
    int i, j;
    // 外层循环控制排序轮数，n个元素需要进行 n-1 轮排序
    for (i = 0; i < n - 1; i++) {
        // 优化：标记在这一轮中是否发生了交换
        int swapped = 0;
        
        // 内层循环进行两两比较，每一轮都会将当前未排序部分的最大值移到末尾
        // 因为后面 i 个元素已经是有序的了，所以只需要比较到 n-i-1
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        
        // 如果在这一轮中没有发生任何交换，说明数组已经有序，可以直接退出
        if (swapped == 0) {
            break;
        }
    }
}

/**
 * 打印数组元素
 * @param arr 数组
 * @param size 数组大小
 */
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * 主函数，程序入口
 */
int main() {
    // 定义一个待排序的数组
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("排序前的原始数组: \n");
    printArray(arr, n);
    
    // 调用冒泡排序
    bubbleSort(arr, n);
    
    printf("排序后的有序数组: \n");
    printArray(arr, n);
    
    return 0;
}
