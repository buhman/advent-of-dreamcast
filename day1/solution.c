#include <stdint.h>

#include "parse.h"
#include "heapsort.h"
#include "abs.h"

struct list {
  int left[1000];
  int right[1000];
};

static int parse_input(const char * input, int length, struct list * list)
{
  const char * end = input + length;

  int i = 0;
  while (input < end) {
    input = parse_base10(input, &list->left[i]);
    input = parse_skip(input, ' ');
    input = parse_base10(input, &list->right[i]);
    input = parse_skip(input, '\n');
    i++;
  }

  return i;
}

int64_t day1_part1(const char * input, int length)
{
  struct list list;
  int list_length = parse_input(input, length, &list);

  heapsort(list.left, list_length);
  heapsort(list.right, list_length);

  int sum = 0;
  for (int i = 0; i < list_length; i++) {
    int distance = abs(list.left[i] - list.right[i]);
    sum += distance;
  }

  return sum;
}

int64_t day1_part2(const char * input, int length)
{
  struct list list;
  int list_length = parse_input(input, length, &list);

  heapsort(list.left, list_length);
  heapsort(list.right, list_length);

  int i = 0;
  int j = 0;

  int sum = 0;

  while (i < list_length) {
    int n = list.left[i];
    int mul_l = 1;
    while (list.left[i + mul_l] == n) {
      mul_l += 1;
    }
    i += mul_l;

    while (list.right[j] < n) {
      j++;
    }
    int mul_r = 0;
    while (list.right[j + mul_r] == n) {
      mul_r += 1;
    }
    j += mul_r;

    sum += n * mul_l * mul_r;
  }

  return sum;
}
