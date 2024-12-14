#pragma once

#include <stdint.h>

#include "double.h"

#ifdef __cplusplus
extern "C" {
#endif

double determinant_2x2(double a, double b,
                       double c, double d);

struct double2 cramers_rule_2x2(double a1, double b1, double c1,
                                double a2, double b2, double c2);

#ifdef __cplusplus
}
#endif
