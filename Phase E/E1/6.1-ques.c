#include <stdio.h>
#include <stdlib.h>
// #include "4.2-ques.c"

int euclid(int, int);
int fibonacci(int);
int num_9(void);

int main(void) {
    // 6.1
    int x = -5, y = 5;
    printf("The gcd(x, y) is %d\n", euclid(x, y));

    int n = 3, m = 5;
    printf("The 3rd of the fibonacci array is %d, the 5th is %d\n", fibonacci(n), fibonacci(m));

    // 6.2
    int num = num_9();
    printf("The number of number 9 appearing in the integer 1 to 100 is %d.\n", num);

    return 0;
}

int euclid(int a, int b) {
    a = abs(a);
    b = abs(b);
    
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int fibonacci(int n) {
        if (n == 0 || n == 1) return 1;
    
    int prev = 1;
    int curr = 1;
    int i = 2;
    
    while (i <= n) {
        int next = prev + curr;
        prev = curr;
        curr = next;
        i++;
    }
    
    return curr;
}

int get_s(int num) {
    int num_ = num % 100;
    return num_ / 10;
}

int get_g(int num) {
    int num_ = num % 100;
    return num_ % 10;
}

int num_9(void) {
    int i = 1;
    int count = 0;

    while (i != 100) {
        // 十位
        int a = get_s(i);
        if (a == 9) count += 1;
        // 个位
        int b = get_g(i);
        if (b == 9) count += 1;

        i++;
    }

    return count;
}