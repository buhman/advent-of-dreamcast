#include <stdint.h>
#include <stddef.h>

#include "input.h"

struct start_size {
  char * start;
  uint32_t size;
};

#include "input_dreamcast.inc"

const int input_size = (sizeof (input)) / (sizeof (input[0]));

void open_input(int day, char ** buf, int * length)
{
  if (day < 1 || day > input_size) {
    *buf = NULL;
    *length = 0;
  } else {
    *buf    = input[day - 1].start;
    *length = input[day - 1].size;
  }
}

void open_sample(int day, int part, char ** buf, int * length)
{
  if (day < 1 || day > input_size || part < 1 || part > 2) {
    *buf = NULL;
    *length = 0;
  } else {
    *buf    = sample[day - 1][part - 1].start;
    *length = sample[day - 1][part - 1].size;
  }
}
