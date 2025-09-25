/* percentageCalc.c – now provides a function, not a separate program */
#include <stdio.h>

/* Public entry point that the menu will call */
void percentage_calc(void) {
    double base, percent, result;

    printf("Enter the base number: ");
    if (scanf("%lf", &base) != 1) {
        fprintf(stderr, "Invalid input for base number.\n");
        return;
    }

    printf("Enter the percentage: ");
    if (scanf("%lf", &percent) != 1) {
        fprintf(stderr, "Invalid input for percentage.\n");
        return;
    }

    result = base * percent * 0.01;          /* same as (base * percent) / 100 */
    printf("\n%g%% of %g is %g\n", percent, base, result);
}
