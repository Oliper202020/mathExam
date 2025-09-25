/* percentage/vatCalc.h – declares the VAT routine used by the whole program */

#ifndef PERCENTAGE_VAT_CALC_H
#define PERCENTAGE_VAT_CALC_H

/* Performs the VAT calculation and prints the result.
 * Reads from stdin, writes to stdout; returns nothing. */
void apply_factor(void);

/* Wrapper that the menu calls (keeps the old name). */
void vat_calc(void);

#endif /* PERCENTAGE_VAT_CALC_H */
