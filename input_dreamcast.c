#include <stdint.h>
#include <stddef.h>

#include "input.h"

struct start_size {
  char * start;
  uint32_t size;
};

#include "input_dreamcast.inc"

const int input_size = (sizeof (input)) / (sizeof (input[0]));

void open_input(int ix, char ** buf, int * length)
{
  if (ix < 0 || ix >= input_size) {
    *buf = NULL;
    *length = 0;
  } else {
    *buf    = input[ix].start;
    *length = input[ix].size;
  }
}

void open_sample(int ix, int part, char ** buf, int * length)
{
  if (ix < 0 || ix > input_size || part < 0 || part > 1) {
    *buf = NULL;
    *length = 0;
  } else {
    *buf    = sample[ix][part].start;
    *length = sample[ix][part].size;
  }
}
