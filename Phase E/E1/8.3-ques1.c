#include <stdio.h>
#include <stdlib.h>
#define N 20

int a[N];

void gen_random(int upper_bound)
{
	int i;
	for (i = 0; i < N; i++)
		a[i] = rand() % upper_bound;
}

void print_random()
{
	int i;
	for (i = 0; i < N; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main(void)
{
    int i, histogram[10] = {0}, num = N;

	gen_random(10);
	print_random();
    for (i = 0; i < N; i++)
		histogram[a[i]]++;
    printf("0\t1\t2\t3\t4\t5\t6\t7\t8\t9\n");
    while (num != 0) {
        for (int i = 0; i < 10; i++) {
            if (histogram[i] != 0) {
                printf("*\t");
                num--;
                histogram[i]--;
            }
            else 
                printf("\t");
            
        }
        printf("\n");
    }
	return 0;
}