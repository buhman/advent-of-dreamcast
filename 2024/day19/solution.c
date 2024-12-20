#include <stdint.h>

#include "parse.h"
#include "printf.h"

#include "radix.c"

const char * find_first_towel(const char * input)
{
  input = parse_find(input, '\n');
  input = parse_skip(input, '\n');
  return input;
}

static int towel_valid(const char * start, const char * end)
{
  if (end == start)
    return 1;

  int length = end - start;
  uint32_t matches = count_substring_matches(start, length);
  int ix = 1;

  int sum = 0;

  while (matches != 0) {
    if (matches & 1) {
      sum += towel_valid(&start[ix], end);
    }
    matches >>= 1;
    ix += 1;
  }

  return sum;
}

int64_t _2024_day19_part1(const char * input, int length)
{
  const char * end = input + length;
  const char * towel = find_first_towel(input);

  int valid = 0;
  while (towel < end) {
    const char * towel_end = parse_find(towel, '\n');
    valid += (int)(towel_valid(towel, towel_end) > 0);

    towel = parse_skip(towel_end + 1, '\n');
  }

  return valid;
}

int64_t _2024_day19_part2(const char * input, int length)
{
  const char * end = input + length;
  const char * towel = find_first_towel(input);

  int sum = 0;
  while (towel < end) {
    const char * towel_end = parse_find(towel, '\n');
    sum += towel_valid(towel, towel_end) > 0;

    towel = parse_skip(towel_end + 1, '\n');
  }

  return sum;
}
