#ifndef PARTTOPROCENTCALC_H
#define PARTTOPROCENTCALC_H

/**
 * @brief Compute the percentage that a given part represents of a whole.
 *
 * Formula:  percent = (part / whole) * 100
 *
 * @param part   The part value (must be non‑negative).
 * @param whole  The whole value (must be > 0).
 * @return double  Percentage (0‑100+). Returns NaN if @p whole ≤ 0.
 */
double partToProcentCalc(double part, double whole);

#endif /* PARTTOPROCENTCALC_H */
