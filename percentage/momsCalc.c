/* file2.c – apply a selectable factor to a number
 *
 * Compile:  gcc -o file2 file2.c
 *
 * Behaviour:
 *   1. Prompt for a numeric value (double).
 *   2. Prompt to choose:
 *        1 – multiply by 1.25
 *        2 – multiply by 0.80
 *   3. Perform the selected multiplication and display the result.
 */

#include <stdio.h>

int main(void) {
    double value, result;
    int choice;

    printf("Enter an amount of money: ");
    if (scanf("%lf", &value) != 1) {
        fprintf(stderr, "Invalid input for number.\n");
        return 1;
    }

    printf("do you want to add or remove moms:\n");
    printf("  1 – add\n");
    printf("  2 – remove\n");
    printf("Your choice: ");
    if (scanf("%d", &choice) != 1) {
        fprintf(stderr, "Invalid input for choice.\n");
        return 1;
    }

    switch (choice) {
        case 1:
            result = value * 1.25;
            printf("\n%g with moms is %g\n", value, result);
            break;
        case 2:
            result = value * 0.80;
            printf("\n%g without moms is %g\n", value, result);
            break;
        default:
            fprintf(stderr, "Choice must be 1 or 2.\n");
            return 1;
    }

    return 0;
}
