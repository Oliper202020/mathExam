#include "rootCalc.h"
#include <stdio.h>
#include <math.h>

void root_calc(void) {
    double x, result;

    printf("Enter a non‑negative number: ");
    if (scanf("%lf", &x) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return;
    }
    if (x < 0.0) {
        fprintf(stderr, "Cannot take the square root of a negative number.\n");
        return;
    }

    result = sqrt(x);
    printf("\nthe square root of %g is about %g\n", x, result);
}
