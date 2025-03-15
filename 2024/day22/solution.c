#include <stdint.h>

#include "parse.h"
#include "printf.h"

static inline unsigned int mix(unsigned int a, unsigned int b)
{
  return (a ^ b) % 16777216;
}

static int random(int n)
{
  n = mix(n, n * 64);
  n = mix(n, n / 32);
  n = mix(n, n * 2048);
  return n;
}

static int random_n(int n, int m)
{
  for (int i = 0; i < m; i++) {
    n = random(n);
  }

  return n;
}

static int parse_input(const char * input, int length, int * ns)
{
  const char * end = input + length;
  int i = 0;
  while (input < end) {
    input = parse_base10(input, &ns[i]);
    input = parse_skip(input, '\n');
    i++;
  }
  return i;
}

int64_t _2024_day22_part1(const char * input, int length)
{
  int ns[2048];

  int ns_length = parse_input(input, length, ns);

  int64_t sum = 0;
  for (int i = 0; i < ns_length; i++) {
    sum += (int64_t)random_n(ns[i], 2000);
  }

  return sum;
}

int64_t _2024_day22_part2(const char * input, int length)
{
  return -1;
}
