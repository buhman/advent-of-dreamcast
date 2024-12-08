#include "array.h"

int array_sum_char(char * a, int length)
{
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += a[i];
  }
  return sum;
}

int array_sum_int(int * a, int length)
{
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += a[i];
  }
  return sum;
}
