#include <stdint.h>

#include "parse.h"

typedef int (* digit_parser_t)(const char * start, const char * end);

static int part1_digit_parser(const char * start, const char * end)
{
  return parse_base10_digit(*start);
}

static int part2_digit_parser(const char * start, const char * end)
{
  int length = end - start;
  if (length >= 1) {
    int n = parse_base10_digit(*start);
    if (n >= 0) return n;
  }
  if (length >= 3) {
    if (parse_match(start, "one")) return 1;
    if (parse_match(start, "two")) return 2;
    if (parse_match(start, "six")) return 6;
  }
  if (length >= 4) {
    if (parse_match(start, "four")) return 4;
    if (parse_match(start, "five")) return 5;
    if (parse_match(start, "nine")) return 9;
  }
  if (length >= 5) {
    if (parse_match(start, "three")) return 3;
    if (parse_match(start, "seven")) return 7;
    if (parse_match(start, "eight")) return 8;
  }
  return -1;
}

static int parse_digit_left(const char * start, const char * end, digit_parser_t parser)
{
  while (start < end) {
    int digit = parser(start, end);
    if (digit >= 0) {
      return digit;
    }
    start++;
  }
  return -1;
}

static int parse_digit_right(const char * start, const char * end, digit_parser_t parser)
{
  const char * s = end - 1;
  while (s >= start) {
    int digit = parser(s, end);
    if (digit >= 0) {
      return digit;
    }
    s--;
  }
  return -1;
}

int solve(const char * input, int length, digit_parser_t parser)
{
  const char * end = input + length;

  int sum = 0;

  while (input < end) {
    const char * newline = parse_find(input, '\n');
    int left = parse_digit_left(input, newline, parser);
    int right = parse_digit_right(input, newline, parser);

    sum += left * 10 + right;

    input = newline + 1;
  }


  return sum;
}

int64_t _2023_day1_part1(const char * input, int length)
{
  return solve(input, length, part1_digit_parser);
}

int64_t _2023_day1_part2(const char * input, int length)
{
  return solve(input, length, part2_digit_parser);
}
