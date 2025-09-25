/* percentage/vatCalc.c */
#include <stdio.h>
#include "vatCalc.h"          /* declares apply_factor and vat_calc */

/* ------------------------------------------------------------------ */
/* Core implementation – already present in your file */
void apply_factor(void) {
    double value, result;
    int    choice;

    printf("Enter an amount of money: ");
    if (scanf("%lf", &value) != 1) {
        fprintf(stderr, "Invalid input for number.\n");
        return;
    }

    printf("Do you want to add or remove vat:\n");
    printf("  1 – add (multiply by 1.25)\n");
    printf("  2 – remove (multiply by 0.80)\n");
    printf("Your choice: ");
    if (scanf("%d", &choice) != 1) {
        fprintf(stderr, "Invalid input for choice.\n");
        return;
    }

    switch (choice) {
        case 1:
            result = value * 1.25;
            printf("\n%g with vat is %g\n", value, result);
            break;
        case 2:
            result = value * 0.80;
            printf("\n%g without vat is %g\n", value, result);
            break;
        default:
            fprintf(stderr, "Choice must be 1 or 2.\n");
            return;
    }
}

/* ------------------------------------------------------------------ */
/* Wrapper required by percentage/menu.c */
void vat_calc(void) {
    /* Simply forward to the real routine */
    apply_factor();
}
