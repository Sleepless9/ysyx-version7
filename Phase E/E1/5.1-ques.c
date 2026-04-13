#include<stdio.h>
#include<math.h>

int is_leap_year(int);

double myround(double);

int main(void) {
    int year1 = 1600, year2 = 1701, year3 = 1900;
    double x = -3.51, y = 4.49;

    printf("year1: %d, year2: %d, year3: %d\n", is_leap_year(year1), 
        is_leap_year(year2), is_leap_year(year3));
    printf("After rounding, x: %f, y: %f\n", myround(x), myround(y));

    return 0;
}

int is_leap_year(int year) {
    if (!(year % 4) && (year % 100))
        return 1;
    else if (!(year % 400)) 
        return 1;
    else 
        return 0;
}

double myround(double x) {
    double fabs_x = fabs(x);
    if (fabs_x - (int)fabs_x >= 0.50) 
        fabs_x = (int)fabs_x + 1;
    else
        fabs_x = (int)fabs_x;
    
    if (x >= 0) 
        return fabs_x;
    else 
        return -fabs_x;
}