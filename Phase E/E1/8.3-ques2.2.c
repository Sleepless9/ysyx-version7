#include <stdio.h>

#define N 4
#define M 3  // 从N个数中取M个进行排列
int a[N] = {1, 2, 3, 4};

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int arr[], int m) {
    for (int i = 0; i < m; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 递归生成从N个数中取M个数的排列
void permute(int arr[], int start, int end, int m) {
    // Base case: 已经选够了M个数
    if (start == m) {
        printArray(arr, m);
        return;
    }
    
    // 从当前位置开始到数组末尾，选择元素放到start位置
    for (int i = start; i <= end; i++) {
        swap(&arr[start], &arr[i]);
        permute(arr, start + 1, end, m);
        swap(&arr[start], &arr[i]);  // 回溯
    }
}

int main() {
    permute(a, 0, N - 1, M);
    return 0;
}