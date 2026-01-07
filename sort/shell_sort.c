#include <stdio.h>

/**
 * 希尔排序算法
 * 
 * 希尔排序（Shell Sort）是插入排序的一种改进版本，也称为缩小增量排序。
 * 它通过比较相距一定间隔的元素来工作，各趟比较所用的距离随着算法的进行而减小，
 * 直到只比较相邻元素的最后一趟排序为止。
 * 
 * 命名由来：
 * 该算法由美国计算机科学家 Donald Shell 于 1959 年发明，并在当年 7 月的
 * 《Communications of the ACM》期刊上首次发表。算法直接以其发明者的姓氏命名。
 * 希尔排序是第一个突破 O(n^2) 时间复杂度的排序算法，在计算机科学史上具有
 * 重要意义。
 * 
 * 算法思想：
 * 1. 选择一个增量序列 t1, t2, ..., tk，其中 ti > tj (i < j)，tk = 1
 * 2. 按增量序列个数 k，对序列进行 k 趟排序
 * 3. 每趟排序，根据对应的增量 ti，将待排序列分割成若干长度为 m 的子序列
 * 4. 分别对各子表进行直接插入排序
 * 5. 仅增量因子为 1 时，整个序列作为一个表来处理，表长度即为整个序列的长度
 * 
 * 时间复杂度: O(n log n) ~ O(n^2)，取决于增量序列
 * 空间复杂度: O(1)
 * 
 * @param arr 待排序的数组
 * @param n 数组的长度
 */
void shellSort(int arr[], int n) {
    // 初始增量为数组长度的一半，每次减半
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 从第 gap 个元素开始，逐个对其所在的组进行直接插入排序
        for (int i = gap; i < n; i++) {
            // 保存当前要插入的元素
            int temp = arr[i];
            int j;
            
            // 对当前元素所在的组进行插入排序
            // 从 i 位置开始，向前查找合适的插入位置
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                // 将较大的元素向后移动
                arr[j] = arr[j - gap];
            }
            
            // 将 temp 插入到正确的位置
            arr[j] = temp;
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
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50, 32, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("排序前的原始数组: \n");
    printArray(arr, n);
    
    // 调用希尔排序
    shellSort(arr, n);
    
    printf("排序后的有序数组: \n");
    printArray(arr, n);
    
    return 0;
}
