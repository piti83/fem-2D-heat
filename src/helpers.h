#ifndef SRC_HELPERS_H_
#define SRC_HELPERS_H_

#include <stdio.h>

#include "integrals.h"

double f1(const double x) {
  return 5 * x * x + 3 * x + 6;
}

double f2(const double x, const double y) {
  return 5 * x * x * y * y + 3 * x * y + 6;
}

void lab2sol() {
  printf("\n\n");
  printf("+--------------------------------------+\n");
  printf("| Method | f1           | f2           |\n");
  printf("+--------------------------------------+\n");
  printf("| 1D2P   | %-12lf |              |\n", Gauss1D2P(f1));
  printf("| 1D3P   | %-12lf |              |\n", Gauss1D3P(f1));
  printf("| 2D2P   |              | %-12lf |\n", Gauss2D2P(f2));
  printf("| 2D3P   |              | %-12lf |\n", Gauss2D3P(f2));
  printf("+--------------------------------------+\n");
}

#endif // SRC_HELPERS_H_
