#include <stdio.h>

#define N 5
#define M 3  // 从N个数中取M个进行组合
int a[N] = {1, 2, 3, 4, 5};

// 存储当前组合的数组
int combination[M];

long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// 计算组合数 C(n, m)
long long combination_count(int n, int m) {
    if (m < 0 || m > n) return 0;
    if (m == 0 || m == n) return 1;
    
    // 优化：C(n, m) = C(n, n-m)
    if (m > n - m) m = n - m;
    
    long long result = 1;
    for (int i = 1; i <= m; i++) {
        result = result * (n - m + i) / i;
    }
    return result;
}

void printCombination() {
    for (int i = 0; i < M; i++) {
        printf("%d ", combination[i]);
    }
    printf("\n");
}

// 递归生成组合
// arr: 原始数组
// start: 在原始数组中开始搜索的位置
// index: 当前正在填充combination数组的索引
// n: 原始数组长度
// m: 需要选取的元素个数
void combine(int arr[], int start, int index, int n, int m) {
    // Base case: 已经选够了m个元素
    if (index == m) {
        printCombination();
        return;
    }
    
    // 从start位置开始，选择元素放入combination[index]
    // 注意：需要留足够的元素给后面的位置
    // 所以循环到 n - (m - index) 即可
    for (int i = start; i <= n - (m - index); i++) {
        combination[index] = arr[i];
        combine(arr, i + 1, index + 1, n, m);
    }
}

int main() {
    printf("从%d个数中取%d个数的组合（共%lld个）：\n", N, M, 
            combination_count(N, M));  // 实际数量为 C(N,M)
    combine(a, 0, 0, N, M);
    return 0;
}