#include <stdio.h>

int main(void) {
    int arr1[5] = {1, 2, 3, 4, 5}, arr2[5];

    for (int i = 0; i < 5; i++) {
        printf("The number in arr1 is %d, that in arr2 is %d\n", arr1[i], arr2[i]);
        arr2[i] = arr1[i];
        printf("After assignment, the number is %d\n", arr2[i]);
    }

    return 0;
}