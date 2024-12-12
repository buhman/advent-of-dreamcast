#include <stdint.h>

#include "parse.h"
#include "heap.h"
#include "cartesian.h"
#include "printf.h"

#define MAX_HEAP_SIZE 2000

typedef int (* accumulate_func)(int * n, int length);
typedef bool (* predicate_func)(char c);

static bool is_symbol_part1(char c)
{
  switch (c) {
  case '#':
  case '$':
  case '%':
  case '&':
  case '*':
  case '+':
  case '-':
  case '/':
  case '=':
  case '@':
    return true;
  default:
    return false;
  }
}

static bool is_symbol_part2(char c)
{
  switch (c) {
  case '*':
    return true;
  default:
    return false;
  }
}

int accumulate_part1(int * n, int length)
{
  int sum = 0;
  for (int i = 0; i < length; i++)
    sum += n[i];
  return sum;
}

int accumulate_part2(int * n, int length)
{
  if (length == 2)
    return n[0] * n[1];
  else
    return 0;
}

static int next_symbol(const char * input, const char * end, int ix, predicate_func pred)
{
  while (&input[ix] < end) {
    if (pred(input[ix]))
      break;
    ix++;
  }
  return ix;
}

static int start_of_base10(const char * input, int ix)
{
  while (ix > 0) {
    char c = input[ix - 1];
    if (c == '\n')
      return ix;
    if (parse_base10_digit(c) == -1)
      return ix;
    ix--;
  }
  return ix;
}

static inline bool n_in_array(int * a, int length, int n)
{
  for (int i = 0; i < length; i++)
    if (a[i] == n)
      return true;
  return false;
}

int solve(const char * input, int length, predicate_func pred, accumulate_func acc)
{
  const char * end = input + length;

  int stride = parse_stride(input, length);
  int height = parse_height(input, length);
  int width = stride - 1;

  int sum = 0;
  int ix = 0;
  while (true) {
    ix = next_symbol(input, end, ix, pred);
    if (&input[ix] >= end)
      break;

    int x = ix % stride;
    int y = ix / stride;

    int neighbor_indices[4];
    int symbol_n[4];
    int neighbor_length = 0;

    for (int direction = 0; direction < cartesian_diagonal_neighbor_count; direction++) {
      int nx = x + cartesian_diagonal_neighbor[direction].x;
      int ny = y + cartesian_diagonal_neighbor[direction].y;

      if (!cartesian_inside(width, height, nx, ny))
        continue;

      int nix = ny * stride + nx;
      char nc = input[nix];
      if (parse_base10_digit(nc) == -1)
        continue;

      int nix_start = start_of_base10(input, nix);
      if (n_in_array(neighbor_indices, neighbor_length, nix_start))
        continue;

      neighbor_indices[neighbor_length] = nix_start;
      parse_base10(&input[nix_start], &symbol_n[neighbor_length]);
      neighbor_length++;
    }

    sum += acc(symbol_n, neighbor_length);

    ix++;
  }

  return sum;
}

int64_t _2023_day3_part1(const char * input, int length)
{
  return solve(input, length, is_symbol_part1, accumulate_part1);
}

int64_t _2023_day3_part2(const char * input, int length)
{
  return solve(input, length, is_symbol_part2, accumulate_part2);
}
