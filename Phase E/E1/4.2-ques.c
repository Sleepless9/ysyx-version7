#include<stdio.h>

int get_s(int), get_g(int);

int main(void) {
    int x = 139;
    int x_, y, z;

    x_ = x % 100;
    y = x_ / 10;
    z = x_ % 10;

    printf("y: %d, z: %d.\n", y, z);

    int m = get_s(x), n = get_g(x);
    printf("m: %d, n: %d.\n", m, n);

    return 0;
}

int get_s(int num) {
    int num_ = num % 100;
    return num_ / 10;
}

int get_g(int num) {
    int num_ = num % 100;
    return num_ % 10;
}