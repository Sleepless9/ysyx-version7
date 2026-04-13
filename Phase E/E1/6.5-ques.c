#include <stdio.h>

void diamond(int, char);

int main(void) {
    for (int i=1; i <= 9; i++) {
        for (int j=1; j <= i; j++) {
            printf("%d\t", i*j);
        }
        printf("\n");
    }

    diamond(5, '+');

    return 0;
}

void diamond(int num, char c) {
    if (!(num%2)) {
        printf("The 1st parameter should be odd.");
        return;
    }

    int mid = num / 2;
    for (int i = 0; i <= mid; i++) {
        for (int j = 0; j < mid-i; j++) {
            printf("\t");
        }
        for (int j = 0; j < 2*i+1; j++) {
            printf("%c\t", c);
        }
        printf("\n");
    }

    for (int i = mid - 1; i >= 0; i--) {
        for (int j = 0; j < mid - i; j++) {
            printf("\t");
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            printf("%c\t", c);
        }
        printf("\n");
    }

}