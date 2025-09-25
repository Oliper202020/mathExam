#include "squareCalc.h"
#include <stdio.h>

void square_calc(void) {
    double x, result;

    printf("Enter a number to square: ");
    if (scanf("%lf", &x) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return;
    }

    result = x * x;
    printf("\n%g squared = %g\n", x, result);
}
