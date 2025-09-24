/* Behaviour:
 *   1. Prompt for the base number (integer or floating‑point).
 *   2. Prompt for the percentage (e.g., 25 for 25%).
 *   3. Compute (base * percentage) / 100 and display the result.
 *
 * The program is deliberately simple so it can be called from the
 * menu program (main.c) without any extra arguments.
 */

#include <stdio.h>

int main(void) {
    double base, percent, result;

    printf("Enter the base number: ");
    if (scanf("%lf", &base) != 1) {
        fprintf(stderr, "Invalid input for base number.\n");
        return 1;
    }

    printf("Enter the percentage: ");
    if (scanf("%lf", &percent) != 1) {
        fprintf(stderr, "Invalid input for percentage.\n");
        return 1;
    }

    result = base * percent * 0.01;
    printf("\n%g%% of %g is %g\n", percent, base, result);
    return 0;
}
