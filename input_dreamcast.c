#include <stdint.h>
#include <stddef.h>

#include "input.h"

#include "day1/sample1.txt.h"
#include "day1/input.txt.h"

struct start_size {
  char * start;
  uint32_t size;
};

static struct start_size input[] = {
  { (  char *)&_binary_day1_input_txt_start,
    (uint32_t)&_binary_day1_input_txt_size   },
};

static struct start_size sample[][2] = {
  {
    { (  char *)&_binary_day1_sample1_txt_start,
      (uint32_t)&_binary_day1_sample1_txt_size   },
    { (  char *)&_binary_day1_sample1_txt_start,
      (uint32_t)&_binary_day1_sample1_txt_size   },
  },
};

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
