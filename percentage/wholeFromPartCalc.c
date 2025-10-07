#include "wholeFromPartCalc.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* ------------------------------------------------------------------ */
/* Core calculation – unchanged from what you posted */
double whole_from_percentage(double part, double percent)
{
    if (percent <= 0.0) {
        return NAN;               /* guard against division‑by‑zero */
    }
    return part * 100.0 / percent;
}

/* ------------------------------------------------------------------ */
/* Helper: read a double from stdin with a prompt */
static double read_double(const char *prompt)
{
    char line[64];
    double value;

    printf("%s", prompt);
    if (!fgets(line, sizeof line, stdin))
        return NAN;

    if (sscanf(line, "%lf", &value) != 1)
        return NAN;

    return value;
}

/* ------------------------------------------------------------------ */
/* Public wrapper used by the menu */
void wholeFromPartCalc(void)
{
    double part    = read_double("Enter the part value: ");
    double percent = read_double("Enter the percentage (e.g., 25 for 25%): ");

    if (isnan(part) || isnan(percent) || percent <= 0.0) {
        printf("Invalid input – percentage must be > 0.\n");
        return;
    }

    double whole = whole_from_percentage(part, percent);
    printf("Whole (base) value = %.2f\n", whole);
}
