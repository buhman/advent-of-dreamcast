#include <stdbool.h>

#include "parse.h"
#include "printf.h"
#include "abs.h"

struct report {
  int level[16];
  int length;
};

static int parse_input(const char * input, int length, struct report * report)
{
  const char * end = input + length;

  int i = 0;
  while (input < end) {
    report[i].length = 0;
    while (true) {
      input = parse_base10(input, &report[i].level[report[i].length++]);
      if (*input != ' ')
        break;
      input = parse_skip(input, ' ');
    }
    input = parse_skip(input, '\n');
    i++;
  }
  return i;
}

static int int_sign(int n)
{
  if (n < 0)
    return -1;
  else
    return 1;
}

static bool report_safe(struct report * report, int skip)
{
  int last_sign = 0;
  int i = (skip == 0) ? 1 : 0;
  int last = report->level[i];

  for (++i; i < report->length; i++) {
    if (i == skip)
      continue;

    int cur = report->level[i];

    int rate = last - cur;

    if (abs(rate) < 1 || abs(rate) > 3)
      return false; // unsafe

    int sign = int_sign(rate);
    if (last_sign != 0 && sign != last_sign)
      return false; // unsafe

    last_sign = sign;
    last = cur;
  }

  return true;
}

int day2_part1(const char * input, int length)
{
  struct report report[1000];

  int report_count = parse_input(input, length, report);

  int sum = 0;
  for (int i = 0; i < report_count; i++) {
    sum += (int)report_safe(&report[i], -1);
  }

  return sum;
}

int day2_part2(const char * input, int length)
{
  struct report report[1000];

  int report_count = parse_input(input, length, report);

  int sum = 0;
  for (int i = 0; i < report_count; i++) {
    for (int j = -1; j < report[i].length; j++) {
      bool safe = report_safe(&report[i], j);
      sum += (bool)safe;
      if (safe)
        break;
    }
  }

  return sum;
}
