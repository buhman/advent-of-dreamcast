#include "linear_algebra.h"

#include "printf.h"

double determinant_2x2(double a, double b,
                       double c, double d)
{
  /*
    a b
    c d
   */

  return a * d - b * c;
}

struct double2 cramers_rule_2x2(double a1, double b1, double c1,
                                double a2, double b2, double c2)
{
  double denom = determinant_2x2(a1, b1,
                                 a2, b2);

  double x_numer = determinant_2x2(c1, b1,
                                   c2, b2);

  double y_numer = determinant_2x2(a1, c1,
                                   a2, c2);

  return (struct double2){x_numer / denom, y_numer / denom};
}
