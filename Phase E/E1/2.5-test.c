#include<stdio.h>

int main() {
    int c = 2, b;
    int a = b = c;

    printf("a: %d, b: %d, c: %d;\n", a, b, c);

    return 0;
}