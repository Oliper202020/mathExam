#include "partToProcentCalc.h"
#include <stdio.h>
#include <math.h>   /* for NAN */

/* ------------------------------------------------------------------ */
/* Core calculation – static because it is used only inside this file */
static double calc_percent(double part, double whole)
{
    if (whole <= 0.0) {
        return NAN;               /* avoid division by zero */
    }
    return (part / whole) * 100.0;
}

/* ------------------------------------------------------------------ */
/* Public wrapper that the menu (or any caller) will use */
double partToProcentCalc(double part, double whole)
{
    return calc_percent(part, whole);
}

/* ------------------------------------------------------------------ */
/* Optional: a tiny test driver – you can keep this in the same file.
 * If you compile this file alone, it will produce an executable that
 * lets you try the function interactively. */
#ifdef TEST_DRIVER   /* compile with -DTEST_DRIVER to enable */
int main(void)
{
    double part, whole;

    printf("Enter the part value: ");
    if (scanf("%lf", &part) != 1) {
        printf("Bad input.\n");
        return 1;
    }

    printf("Enter the whole value: ");
    if (scanf("%lf", &whole) != 1) {
        printf("Bad input.\n");
        return 1;
    }

    double percent = partToProcentCalc(part, whole);
    if (isnan(percent))
        printf("Invalid input – whole must be > 0.\n");
    else
        printf("Result: %.2f%%\n", percent);

    return 0;
}
#endif /* TEST_DRIVER */
