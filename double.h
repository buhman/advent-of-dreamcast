#pragma once

#include <stdint.h>

#define infinity (__builtin_inf())

#ifdef __cplusplus
extern "C" {
#endif

struct double2 {
  double x;
  double y;
};

#ifdef __cplusplus
}
#endif
