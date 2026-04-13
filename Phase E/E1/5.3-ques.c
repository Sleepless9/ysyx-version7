#include<stdio.h>
#include<stdlib.h>

int euclid(int, int);
int fibonacci(int);

int main(void) {
    int x = -5, y = 5;
    printf("The gcd(x, y) is %d\n", euclid(x, y));

    int n = 3, m = 5;
    printf("The 3rd of the fibonacci array is %d, the 5th is %d\n", fibonacci(n), fibonacci(m));

    return 0;
}

int euclid(int a, int b) {
    if (a == 0 || b == 0) return 0;

    if (a == 1 || b == 1) return 1;

    int abs_a = abs(a), abs_b = abs(b);
    int flag = abs_a > abs_b ? 1 : 0;
    int temp = flag ? (abs_a % abs_b) : (abs_b % abs_a);

    if (!temp && flag) return abs_b;
    else if (!temp && !flag) return abs_a;
    else 
        return (euclid(temp, abs_b));
}

int gcd_recursive(int a, int b) {
    a = abs(a);
    b = abs(b);
    
    if (b == 0) return a;
    return gcd_recursive(b, a % b);
}

int fibonacci(int n) {
    if (n == 0 || n == 1) return 1;
    else    
        return fibonacci(n-1) + fibonacci(n-2);
}