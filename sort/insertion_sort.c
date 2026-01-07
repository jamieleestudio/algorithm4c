#include <stdio.h>

/**
 * 插入排序算法
 * 
 * 插入排序（Insertion Sort）是一种简单直观的排序算法。它的工作原理是通过构建有序序列，
 * 对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
 * 
 * 算法思想：
 * 1. 从第一个元素开始，该元素可以认为已经被排序
 * 2. 取出下一个元素，在已经排序的元素序列中从后向前扫描
 * 3. 如果该元素（已排序）大于新元素，将该元素移到下一位置
 * 4. 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
 * 5. 将新元素插入到该位置后
 * 6. 重复步骤2~5
 * 
 * 算法特点：
 * - 在接近有序的数据集上表现优异
 * - 对于小规模数据集效率较高
 * - 是稳定的排序算法
 * - 实现简单，代码量少
 * 
 * 时间复杂度: 
 *   - 最好情况: O(n) - 数组已经有序
 *   - 平均情况: O(n^2)
 *   - 最坏情况: O(n^2) - 数组逆序
 * 空间复杂度: O(1)
 * 
 * @param arr 待排序的数组
 * @param n 数组的长度
 */
void insertionSort(int arr[], int n) {
    int j, key;
    
    // 从第二个元素开始，逐个插入到前面已排序的序列中
    for (int i = 1; i < n; i++) {
        // 保存当前要插入的元素
        key = arr[i];
        j = i - 1;
        
        // 将所有大于 key 的元素向后移动一位
        // 为 key 腾出插入位置
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        // 将 key 插入到正确的位置
        arr[j + 1] = key;
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
    
    // 调用插入排序
    insertionSort(arr, n);
    
    printf("排序后的有序数组: \n");
    printArray(arr, n);
    
    return 0;
}
