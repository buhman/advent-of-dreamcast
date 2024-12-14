#include "linear_algebra.h"

#include "printf.h"
//#include <stdio.h>

double determinant_2x2(double a, double b,
                       double c, double d)
{
  /*
    a b
    c d
   */

  return a * d - b * c;
}

/*
5550.00 450000000444000.00 600000000222000.00
81081081161.08 108108108148.11

-3876.00 -460000000548084.00 -400000000524792.00
118679050709.00 103199174542.00

-6595.00 -470000000250610.00 -690000000567170.00
71266110727.92 104624715779.71

4278.00 440000001045978.00 460000000280508.00
102851800151.00 107526881786.00
*/

union di {
  double d;
  int64_t i;
};

static int64_t raw_double(double n)
{
  union di di;
  di.d = n;
  return di.i;
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
