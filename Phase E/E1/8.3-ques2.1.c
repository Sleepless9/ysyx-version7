#include <stdio.h>
// #include <math.h>

#define N 4
int a[N] = {1, 4, 3, 9};

long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// 交换两个元素
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// 打印数组
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 递归生成全排列
void permute(int arr[], int start, int end) {
    // Base case: 如果start == end，说明已经处理到最后一个元素
    if (start == end) {
        printArray(arr, end + 1);
        return;
    }
    
    // 递归处理：将每个元素换到start位置
    for (int i = start; i <= end; i++) {
        swap(&arr[start], &arr[i]);      // 将第i个元素换到start位置
        permute(arr, start + 1, end);    // 递归处理后面的元素
        swap(&arr[start], &arr[i]);      // 回溯，恢复原状
    }
}

int main() {
    printf("全排列结果（共%lld个）：\n", factorial(N));
    permute(a, 0, N - 1);
    return 0;
}